#include "Movie.h"
#include "Serie.h"

#include <fstream>
#include <unordered_set>
#include <iostream>

using namespace std;

vector<Serie> seriesVector(100);
vector<Movie> moviesVector(100);
vector<Episode> episodesVector(100);
vector<Video*> videoPointers(200);
unordered_set<string> totalGenres;

int totalVideos = 0;
int totalMovies = 0;
int totalSeries = 0;
int totalEpisodes = 0;

bool changedScore = false;

void loadMovies(){
  string askOption;
  int ID;
  string name;
  string genre;
  int runningTime;
  double score;

  ifstream moviesTxt;
  moviesTxt.open("movies.txt");

  while(moviesTxt >> name >> genre >> runningTime >> score){

    totalGenres.insert(genre);
    
    ID = totalSeries + totalVideos + 1;    
    
    Movie tempMovie(ID, name, genre, runningTime, score);
    moviesVector[totalMovies] = tempMovie;
    videoPointers.push_back(&moviesVector[totalMovies]);

    totalVideos++;
    totalMovies++;
  }  
}
void loadSeries(){
  int ID;
  string name;
  string genre;

  ifstream seriesTxt;
  seriesTxt.open("series.txt");

  while(seriesTxt >> name >> genre){
    ID = totalSeries + totalVideos + 1;      
    Serie tempSerie(ID, name, genre);
    seriesVector[totalSeries] = tempSerie;
    totalSeries++;
  }
  
}
void loadEpisodes(){
  int ID;
  string belongingSerie;
  string name;
  string genre;
  int runningTime;
  string season;
  double score;

  ifstream episodesTxt;
  episodesTxt.open("episodes.txt");
  
  while(episodesTxt >> name >> genre >> runningTime >> score >> belongingSerie >> season){

    totalGenres.insert(genre);
    
    ID = totalSeries + totalVideos + 1;
    
    Episode tempEpisode(ID, runningTime, genre, name, score, belongingSerie, season);
    episodesVector[totalEpisodes] = tempEpisode;
    videoPointers.push_back(&episodesVector[totalEpisodes]);
    
    totalVideos++;
    totalEpisodes++; 
  } 
}
void setEpsWithSeries(){
  for (int i = 0; i < totalEpisodes; i++){
    
    string serieName = episodesVector[i].getBelongingSerie();

    for (int j = 0; j < totalSeries; j++){

      if (seriesVector[j].getName() == serieName){
        seriesVector[j].addEpisode(episodesVector[i]);
      }
    }
  }
}
void reWriteVideoFiles(){
  
  ofstream movies;
  movies.open("movies.txt");
  for (int i = 0; i < totalMovies; i++){
    Movie movie = moviesVector[i];
    movies << movie.getName() << "\t" 
      << movie.getGenre() << "\t"
      << movie.getRunningTime() << "\t"
      << movie.getScore() << "\n";
  }
  movies.close();

  ofstream episodes;
  episodes.open("episodes.txt");
  for (int i = 0; i < totalEpisodes; i++){
    Episode episode = episodesVector[i];
    episodes << episode.getName() << "\t"
      << episode.getGenre() << "\t"
      << episode.getRunningTime() << "\t" 
      << episode.getScore() << "\t"
      << episode.getBelongingSerie() << "\t"
      << episode.getSeason() << "\n";
  }
  episodes.close();
  
}

void printSet(unordered_set<string> const &s){

  int cont = 1;
  
  for (auto const &i:s){
    cout << cont << " " << i << endl;
    cont++;
  }
  
}

vector<double> askScoreInterval(){
  double interL, interR;
  cout << "Ingrese el rango de calificaciones separado por espacios: " << endl;
  cin >> interL >> interR;

  while(interL > interR || interL < 0 || interR > 5 ){
    cout << "FORMATO INCORRECTO -- Inténtelo de nuevo" << endl;
    cout << "Ingrese el rango de calificaciones separado por espacios: " << endl;
    cin >> interL >> interR;
  }

  return {interL, interR};  
}

string askOption(){
  string option;
  
  cout << "¿Qué desea hacer?" << endl;
  cout << "1 -> Mostrar videos por calificaciones" << endl;
  cout << "2 -> Mostrar videos por género" << endl;
  cout << "3 -> Mostrar episodios de las series por calificaciones" << endl;
  cout << "4 -> Mostrar películas por calificaciones" << endl;
  cout << "5 -> Calificar un video" << endl;
  cout << "0 -> Salir" << endl;

  cin >> option;

  return option;
}



// Opción 1
void showVideosByScore(){

  vector<double> interval = askScoreInterval();
  double interL = interval[0];
  double interR = interval[1];

  cout << endl;
  cout << "--------------- RESULTADO ---------------" << endl << endl;
  
  for(int i = 0; i < totalVideos; i++){
    
    double score = videoPointers[i]->getScore();
    
    if(score >= interL && score <= interR){
      videoPointers[i]->showData();
      cout << endl;
    }
    
  } 
  
  cout << "-----------------------------------------" << endl;
  
}
// Opción 2
void showVideosByGenre(){

  int cnt = 0;
  
  cout << endl;
  printSet(totalGenres);
  cout << endl;

  cout << "¿Por cuál género desea filtrar? (Número)" << endl;
  int genreNum;
  cin >> genreNum;

  unordered_set<string>::iterator it = totalGenres.begin();
  advance(it, genreNum-1);
  string genreToFilter = *it;

  cout << endl;
  cout << "--------------- RESULTADO ---------------" << endl << endl;
  
  for(int i = 0; i < totalVideos; i++){
    
    string genre = videoPointers[i]->getGenre();
    
    if(genre == genreToFilter){
      videoPointers[i]->showData();
      cout << endl;
      cnt++;
    }
    
  }

  if (cnt == 0){
    cout << "No existe ningún video con esa calificación" << endl << endl;
  }
  
  cout << "-----------------------------------------" << endl;  
}
// Opción 3
void showEpisodesByScore(){

  int cnt = 0;
  vector<double> interval;
  double interL, interR;
  int indexSerie;

  cout << endl;
  for(int i = 0; i < totalSeries; i++){
    cout << i+1 << ": " << seriesVector[i].getName() << endl;
  }
  cout << endl;
  
  cout << "Escoja la serie de la que le gustaría filtrar los episodios (Número): " << endl;
  cin >> indexSerie;

  cout << endl;
  interval = askScoreInterval();
  interL = interval[0];
  interR = interval[1];
  
  vector<Episode> episodes = seriesVector[indexSerie-1].getEpisodes();

  cout << endl;
  cout << "--------------- RESULTADO ---------------" << endl << endl;
  
  for (int i = 0; i < episodes.size(); i++){
    
    double episodeScore = episodes[i].getScore();
    
    if (episodeScore >= interL && episodeScore <= interR){
      
      cout << "Nombre: " << episodes[i].getName() << endl;
      cout << "Temporada: " << episodes[i].getSeason() << endl;
      cout << "Duración: " << episodes[i].getRunningTime() << endl;
      cout << "Calificación: " << episodes[i].getScore() << endl;
      cout << endl;
      cnt++;
      
    }
  }

  if (cnt == 0){
    cout << "No existe ningún capítulo con esa calificación" << endl << endl;
  }

  cout << "-----------------------------------------" << endl;
}
// Opción 4
void showMoviesByScore(){

  int cnt = 0;
  vector<double> interval = askScoreInterval();
  double interL = interval[0];
  double interR = interval[1];
  
  cout << endl;
  cout << "--------------- RESULTADO ---------------" << endl << endl;
  
  for(int i = 0; i < totalMovies; i++){
    double score = moviesVector[i].getScore();
    if(score >= interL && score <= interR){
      moviesVector[i].showData();
      cout << endl;
      cnt++;
    }
  }

  if (cnt == 0){
    cout << "No existe ninguna película con esa calificación" << endl << endl;
  }

  cout << "-----------------------------------------" << endl;
  
}
// Opción 5
void scoreVideo(){

  int index;
  double newScore;
  
  for (int i = 0; i < totalVideos; i++){
    cout << i+1 << " " << videoPointers[i]->getName() << endl;
  }

  cout << endl;
  cout << "Ingrese la serie que desea calificar (Número)" << endl;
  cin >> index;

  while (index > totalVideos || index < 0){
    cout << endl;
    cout << "Número incorrecto, inténtelo de nuevo" << endl;
    cout << "Ingrese la serie que desea calificar (Número)" << endl;
    cin >> index;
  }
  
  cout << endl;
  cout << "Ingrese la calificación que desea asignar" << endl;
  cin >> newScore;

  while(newScore < 0 || newScore > 5){
    cout << endl;
    cout << "La calificación debe de estar entre un rango de 1 y 5" << endl;
    cout << "Ingrese la calificación que desea asignar" << endl;
    cin >> newScore;
  }

  videoPointers[index-1]->setScore(newScore);
  changedScore = true;
}



int main() {

  videoPointers.clear();

  loadMovies(); loadSeries(); loadEpisodes(); 
  setEpsWithSeries();

  while(true){

    string selectedOption = askOption();

    // Se pudo haber hecho un switch pero por algún motivo
    // nos marcaba error
    
    if (selectedOption == "1"){
      showVideosByScore();
      cout << endl;
    }
  
    else if (selectedOption == "2"){
      showVideosByGenre();
      cout << endl;
    }
  
    else if (selectedOption == "3"){
      showEpisodesByScore();
      cout << endl;
    }

    else if (selectedOption == "4"){
      showMoviesByScore();
      cout << endl;
    }

    else if (selectedOption == "5"){
      scoreVideo();
      cout << endl;
    }
      

    else if (selectedOption == "0"){
      cout << "Gracias por usar nuestros servicios" << endl;
      if (changedScore){
        reWriteVideoFiles();  
      }
      break;
    }

    else{
      cout << "Esa opción no es válida, inténtalo de nuevo" << endl << endl;
    }

  }
    
  
  return 0;
}