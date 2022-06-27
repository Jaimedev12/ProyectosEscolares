#include "Video.h"

class Episode : public Video{
protected:
  string belongingSerie;
  string season;

public:
  // Constructores 
  Episode();
  Episode(int ID, int runningTime, string genre, string name, 
double score, string belongingSerie, string season);

  void showData();

  // Setters
  void setSeason(string);

  // Getters
  string getSeason();
  int getNEpisodes();
  string getBelongingSerie();
};

Episode::Episode() : Video(){
  belongingSerie = "";
  season = "";
}

Episode::Episode(int ID, int runningTime, string genre, string name, 
double score, string belongingSerie, string season) 
: Video(ID, runningTime, genre, name, score){
  this->belongingSerie = belongingSerie;
  this->season = season;
}

void Episode::showData(){
  cout << "De la serie: " << belongingSerie << endl;
  cout << "Temporada: " << season << endl;
  Video::showData();
}

string Episode::getSeason(){
  return season;
}
string Episode::getBelongingSerie(){
  return belongingSerie;
}

void Episode::setSeason(string season){
  this->season = season;
}
