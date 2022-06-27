#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>

using namespace std;

class Video{
  protected:
    int ID, runningTime;
    string genre, name;
    double score;
  
  public:
    Video();
    Video(int ID, int runningTime, string genre, string name, double score);
    //virtual void showScore() = 0;
    virtual void showData() = 0;

    //setters
    void setID(int);
    void setRunningTime(int);
    void setGenre(string);
    void setName(string);
    void setScore(double);

    //getters
    int getID();
    int getRunningTime();
    string getGenre();
    string getName();
    double getScore();
};

Video::Video(){
  ID = 0;
  runningTime = 0;
  genre = "";
  name = "";
  score = 0;
}

Video::Video(int ID, int runningTime, string genre, string name, double score){
  this->ID = ID;
  this->runningTime = runningTime;
  this->genre = genre;
  this->name = name;
  this->score = score;
}

void Video::showData(){
  cout << "Nombre: " << name << endl;
  cout << "ID: " << ID << endl;
  cout << "Género: " << genre << endl;
  cout << "Duración: " << runningTime << endl;
  cout << "Calificación: " << score << endl;
}

// --------------- SETTERS ---------------------------------
void Video::setID(int ID){this->ID = ID;}
void Video::setRunningTime(int runningTime){this->runningTime = runningTime;}
void Video::setGenre(string genre){this->genre = genre;}
void Video::setName(string name){this->name = name;}
void Video::setScore(double score){this->score = score;}
//----------------------------------------------------------

// --------------- GETTERS ---------------------------------
int Video::getID(){return ID;}
int Video::getRunningTime(){return runningTime;}
string Video::getGenre(){return genre;}
string Video::getName(){return name;}
double Video::getScore(){return score;}
//----------------------------------------------------------

#endif
