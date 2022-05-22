#include <vector>

#include "Jugador.h"
#include "Dado.h"
#include "Casilla.h"

class myGame{
private:
  vector<Casilla> tablero;
  Dado dado;
  Jugador jugador1;
  Jugador jugador2;
  int turno = 0;

public:
    void start();
    bool preguntarSiSeguir();
    void crearTablero(int nCasillas);
    void generarSerpientesyEscaleras();
    void imprimirInfo(Jugador &jugadorActual, Casilla &nuevaCasilla, int &nJugador);
    void actualizarInfoJugador(Jugador &jugadorActual, Casilla &nuevaCasilla, int &nJugador);
    
};

void myGame::start(){

  jugador1.setNombre("Andrea");
  jugador1.setPosicion(1);
  jugador2.setNombre("Jaime");
  jugador2.setPosicion(1);

  Jugador jugadorActual;
  dado.setNLados(6); // parámetro es el número de lados
  Casilla nuevaCasilla;
  
  //bool continuar;
  int nJugador;

  while(preguntarSiSeguir()){

    crearTablero(36); // Con casillas excedentes por si se pasa

    tablero[3].setTipo("L");
    tablero[5].setTipo("L");
    tablero[7].setTipo("L");
    
    tablero[9].setTipo("S");
    tablero[11].setTipo("S");
    tablero[29].setTipo("S");
    
    nJugador = (turno % 2) + 1;
    turno++;
    
    if(nJugador == 1){
      jugadorActual = jugador1;
    } else {
      jugadorActual = jugador2;
    }

    imprimirInfo(jugadorActual, nuevaCasilla, nJugador);
    actualizarInfoJugador(jugadorActual, nuevaCasilla, nJugador);  

    if (jugadorActual.getPosicion() >= 30){
      cout << "-- TERMINÓ EL JUEGO --" << endl;
      cout << "El Jugador número " << nJugador << "(" << jugadorActual.getNombre() << ") Ganó!!";
      break;
    }
    
  }
}


bool myGame::preguntarSiSeguir(){
  string temp;
  cout << "Presione 'C' para continuar, 'E' para terminar el juego:" << endl;
  cin >> temp;

  if (temp == "C"){
    return true;
  } else if (temp == "E"){
    cout << "Gracias por jugar" << endl;
    return false;
  } else{
    cout << "Ese input no es válido, inténtelo de nuevo\n";
    return preguntarSiSeguir();
  }
  
}

void myGame::crearTablero(int nCasillas){
  for (int i = 1; i < nCasillas+1; i++){
    Casilla casilla(i, "N");
    tablero.push_back(casilla);
  }
}

void myGame::imprimirInfo(Jugador &jugadorActual, Casilla &nuevaCasilla, int &nJugador){
  
  cout << "\nTurno número " << turno << endl;
    
  cout << "Jugador actual: " << nJugador << " (" << jugadorActual.getNombre() << ")" << endl;
  
  cout << "Casilla actual: " << jugadorActual.getPosicion() << endl;
  
  dado.lanzar();
  cout << "Resultado del dado: " << dado.getLadoArriba() << endl;
  
  int nNuevaCasilla = jugadorActual.getPosicion() + dado.getLadoArriba();
  nuevaCasilla = tablero[nNuevaCasilla-1];
  cout << "Deberá moverse a una casilla de tipo: " << nuevaCasilla.getTipo() << endl;

  if(nuevaCasilla.getTipo() == "S"){
    nuevaCasilla = tablero[nuevaCasilla.getNumero() - 3 - 1];
  } else if(nuevaCasilla.getTipo() == "L"){
    nuevaCasilla = tablero[nuevaCasilla.getNumero() + 3 - 1];
  }
  
  cout << "La casilla final del jugador es la número: " << nuevaCasilla.getNumero() << endl;

  cout << endl;
}

void myGame::actualizarInfoJugador(Jugador &jugadorActual, Casilla &nuevaCasilla, int &nJugador){
  
  jugadorActual.setPosicion(nuevaCasilla.getNumero());

  if(nJugador == 1){
    jugador1 = jugadorActual;
  } else {
    jugador2 = jugadorActual;
  }
}

