#include <vector>

#include "Episode.h"

class Serie{
  private:
    vector<Episode> episodes;
    int ID;
    int runningTime;
    string name;
    string genre;
    double score;
    
  public:
    Serie();
    Serie(int ID, string name, string genre);


    //SETTERS
    void setName(string);

    //GETTERS
    string getName();
    vector<Episode> getEpisodes();
    int getNEpisodes();
    double getScore();
    int getRunningTime();
    
    void addEpisode(Episode ep);
    void showEpisodes();
};

Serie::Serie(){
  ID = 0;
  runningTime = 0;
  genre = "";
  name = "";
  score = 0;
  episodes = {};
};

Serie::Serie(int ID, string name, string genre){
  this->ID = ID;
  this->runningTime = 0;
  this->genre = genre;
  this->name = name;
  this->score = getScore();
  this->episodes = {};
}


void Serie::setName(string name){
  this->name = name;
}

string Serie::getName(){
  return name;
}


vector<Episode> Serie::getEpisodes(){
  return episodes;
}


void Serie::addEpisode(Episode ep){
  episodes.push_back(ep);
}

void Serie::showEpisodes(){
  cout << getName() << ":" << endl;
  for (int i = 0; i < getNEpisodes(); i++){
    cout << i+1 << ": ";
    cout << episodes[i].getName() << endl;
  }
}

int Serie::getNEpisodes(){
  return episodes.size();
}

double Serie::getScore(){
  double cont = 0;

  // Si la serie no tiene capítulos
  if (episodes.empty())
    return 0;

  
  for (int i = 0; i < episodes.size(); i++){
    cont += episodes[i].getScore();
  }

  return cont/episodes.size();
  
}

int Serie::getRunningTime(){

  int rt = 0;

  for (int i = 0; i < episodes.size(); i++){
    rt += episodes[i].getRunningTime();
  }

  return rt;
}







