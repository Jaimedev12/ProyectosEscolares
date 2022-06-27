#include "Video.h"


class Movie : public Video{
  protected:

  public:
    Movie();
    Movie(int ID, string name, string genre, int runningTime, double score);

    void showData();
};


//constructor default pelicula
Movie::Movie() : Video(){}

//constructor con parámetros de pelicula
Movie::Movie(int ID, string name, string genre, int runningTime, double score)
: Video(ID, runningTime, genre, name, score){}

void Movie::showData(){
   Video::showData(); 
}

