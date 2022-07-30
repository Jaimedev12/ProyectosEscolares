/** 
*
* Autores:
*    Luis Barajas - A01235589
*    María Fernanda Vela Calderón  -  A01377958
*    Jaime Eduardo López Castro - A00833173  
* Fecha: 13/07/2022
*
* Compilacion para debug:  
*    g++ -std=c++17 -g -o main *.cpp 
* Ejecucion con valgrind:
*    nix-env -iA nixpkgs.valgrind
*    valgrind --leak-check=full ./main
*
* Compilacion para ejecucion:  
*    g++ -std=c++17 -O3 -o main *.cpp 
* Ejecucion:
*    ./main
**/

#include <iostream>
#include "DoubleLinkedList.h"

int main() {
  std::cout << "Ejemplo de listas ligadas\n";
  
  DoubleLinkedList<int> miLista;
  std::cout << "numElements: " << miLista.getNumElements() << std::endl;
  // addFirst
  std::cout << "Agregando 5 elementos al frente..." << std::endl;
  for (int i = 1; i < 6; i++) {
    miLista.addFirst(i);
  }
  std::cout << "numElements: " << miLista.getNumElements() << std::endl;
  miLista.printList();
  std::cout << std::endl;

  // addLast
  std::cout << "Agregando 5 elementos al final..." << std::endl;
  for (int i = 10; i < 15; i++) {
    miLista.addLast(i);
  }
  std::cout << "numElements: " << miLista.getNumElements() << std::endl;
  miLista.printList();
  std::cout << std::endl;

// find Data
  std::cout << "findData(13): " << std::endl;
  try {
    std::cout << miLista.findData(13) << std::endl;
  }
  catch (std::out_of_range e) {
    std::cout << "Ocurrio un error: " << e.what() << std::endl << "No se encontró el elemento." << std::endl;
  }
  miLista.printList();
  std::cout << std::endl;
  
  // deleteData
  std::cout << "Delete 5: " << std::endl;
  miLista.deleteData(5);
  miLista.printList();
  std::cout << std::endl;
  std::cout << "Delete 14: " << std::endl;
  miLista.deleteData(14);
  miLista.printList();
  std::cout << std::endl;
  std::cout << "Delete 10: " << std::endl;
  miLista.deleteData(10);
  miLista.printList();
  std::cout << std::endl;

  // deleteAt puede lanzar una excepcion 
  std::cout << "Delete at 0: " << std::endl;
  try {
    miLista.deleteAt(0);
  }
  catch (std::out_of_range e) {
    std::cout << "Ocurrio un error: " << e.what() << std::endl << "No se modifico la lista" << std::endl;
  }
  miLista.printList();
  std::cout << std::endl;
  std::cout << "Delete at 3: " << std::endl;
  try {
    miLista.deleteAt(3);
  }
  catch (std::out_of_range e) {
    std::cout << "Ocurrio un error: " << e.what() << std::endl << "No se modifico la lista" << std::endl;
  }  
  miLista.printList();
  std::cout << std::endl;
  std::cout << "Delete at 4: " << std::endl;
  try {
    miLista.deleteAt(4);
  }
  catch (std::out_of_range e) {
    std::cout << "Ocurrio un error: " << e.what() << std::endl << "No se modifico la lista" << std::endl;
  }
  miLista.printList();
  std::cout << std::endl;

  // getData puede lanzar una excepcion 
  std::cout << "getData at 0: " << std::endl;
  try {
    std::cout << miLista.getData(0) << std::endl;
  }
  catch (std::out_of_range e) {
    std::cout << "Ocurrio un error: " << e.what() << std::endl << "No se modifico la lista" << std::endl;
  }
  std::cout << "getData at 3: " << std::endl;
  try {
    std::cout << miLista.getData(3) << std::endl;
  }
  catch (std::out_of_range e) {
    std::cout << "Ocurrio un error: " << e.what() << std::endl << "No se modifico la lista" << std::endl;
  }  
  std::cout << "getData at 1: " << std::endl;
  try {
    std::cout << miLista.getData(1) << std::endl;
  }
  catch (std::out_of_range e) {
    std::cout << "Ocurrio un error: " << e.what() << std::endl << "No se modifico la lista" << std::endl;
  }
  miLista.printList();
  std::cout << std::endl;

   // updateData puede lanzar una excepcion 
  std::cout << "updateData(3, 33): " << std::endl;
  try {
    miLista.updateData(3, 33);
  }
  catch (std::out_of_range e) {
    std::cout << "Ocurrio un error: " << e.what() << std::endl << "No se modifico la lista" << std::endl;
  }
  miLista.printList();
  std::cout << std::endl;
  std::cout << "updateData(12, 1212): " << std::endl;
  try {
    miLista.updateData(12, 1212);
  }
  catch (std::out_of_range e) {
    std::cout << "Ocurrio un error: " << e.what() << std::endl << "No se modifico la lista" << std::endl;
  }
  miLista.printList();
  std::cout << std::endl;
  std::cout << "updateData(2, 22): " << std::endl;
  try {
    miLista.updateData(2, 22);
  }
  catch (std::out_of_range e) {
    std::cout << "Ocurrio un error: " << e.what() << std::endl << "No se modifico la lista" << std::endl;
  }  
  miLista.printList();
  std::cout << std::endl; 
  //--------------------------------------------------------------------------------------------------------------------------------------------------
  
// updateAt
  std::cout << "updateAt(-1, 50): " << std::endl;
  try {
    miLista.updateAt(-1, 50);
  }
  catch (std::out_of_range e) {
    std::cout << "Ocurrio un error: " << e.what() << std::endl << "No se modifico la lista" << std::endl;
  }
  miLista.printList();
  std::cout << std::endl;

  std::cout << "updateAt(0, 0): " << std::endl;
  try {
    miLista.updateAt(0, 0);
  }
  catch (std::out_of_range e) {
    std::cout << "Ocurrio un error: " << e.what() << std::endl << "No se modifico la lista" << std::endl;
  }
  miLista.printList();
  std::cout << std::endl;

  std::cout << "updateAt(1, 1): " << std::endl;
  try {
    miLista.updateAt(1, 1);
  }
  catch (std::out_of_range e) {
    std::cout << "Ocurrio un error: " << e.what() << std::endl << "No se modifico la lista" << std::endl;
  }
  miLista.printList();
  std::cout << std::endl;

  std::cout << "updateAt(2, 2): " << std::endl;
  try {
    miLista.updateAt(2, 2);
  }
  catch (std::out_of_range e) {
    std::cout << "Ocurrio un error: " << e.what() << std::endl << "No se modifico la lista" << std::endl;
  }
  miLista.printList();
  std::cout << std::endl;

  std::cout << "updateAt(3, 3): " << std::endl;
  try {
    miLista.updateAt(3, 3);
  }
  catch (std::out_of_range e) {
    std::cout << "Ocurrio un error: " << e.what() << std::endl << "No se modifico la lista" << std::endl;
  }
  miLista.printList();
  std::cout << std::endl;

  std::cout << "updateAt(4, 4): " << std::endl;
  try {
    miLista.updateAt(4, 4);
  }
  catch (std::out_of_range e) {
    std::cout << "Ocurrio un error: " << e.what() << std::endl << "No se modifico la lista" << std::endl;
  }
  miLista.printList();
  std::cout << std::endl;

// find Data
  std::cout << "findData(49): " << std::endl;
  try {
    std::cout << miLista.findData(49) << std::endl;
  }
  catch (std::out_of_range e) {
    std::cout << "Ocurrio un error: " << e.what() << std::endl << "No se encontró el elemento." << std::endl;
  }
  miLista.printList();
  std::cout << std::endl;

  
  std::cout << "findData(2): " << std::endl;
  try {
    std::cout << miLista.findData(2) << std::endl;
  }
  catch (std::out_of_range e) {
    std::cout << "Ocurrio un error: " << e.what() << std::endl << "No se encontró el elemento." << std::endl;
  }
  miLista.printList();
  std::cout << std::endl;


// Sobrecarga  de operador =

  std::cout << "Ejemplo de sobrecarga del operador = con lista inicial vacia: \n";

  std::cout << "Lista 1: " <<  std::endl;
  DoubleLinkedList<int> lista1;
  std::cout << "numElements: " << lista1.getNumElements() << std::endl;
  lista1.printList();

  std::cout << "Lista 2: " <<  std::endl;
  DoubleLinkedList<int> lista2;
  std::cout << "numElements: " << lista2.getNumElements() << std::endl;
  // addFirst
  std::cout << "Agregando 5 elementos al frente..." << std::endl;
  for (int i = 7; i < 12; i++) {
    lista2.addFirst(i);
  }
  std::cout << "numElements: " << lista2.getNumElements() << std::endl;
  lista2.printList();
  std::cout << std::endl;

  std::cout << "Sobrecarga lista1 = lista2: " <<  std::endl;
  lista1 = lista2;
  std::cout << "Lista 1 modificada: " <<  std::endl;
  lista1.printList();  
  std::cout << "Lista 2 recibida: " <<  std::endl;
  lista2.printList();
  std::cout << std::endl;
  
  std::cout << "Ejemplo de sobrecarga del operador = con lista inicial con datos y NumElements de lista recibida > NumElements de lista inicial: " <<  std::endl;
  std::cout << "Agregando 5 elementos al final de lista2..." << std::endl;
  for (int i = 12; i < 17; i++) {
    lista2.addLast(i);
  }
  std::cout << "Lista 2: " <<  std::endl; 
  std::cout << "numElements: " << lista2.getNumElements() << std::endl;
  lista2.printList();
  std::cout << std::endl;


  lista1 = lista2;
  std::cout << "Lista 1 modificada : " <<  std::endl;
  lista1.printList();  
  std::cout << "Lista 2 recibida: " <<  std::endl;
  lista2.printList();
  std::cout << std::endl;


  std::cout << "Ejemplo de sobrecarga del operador = con lista inicial con datos y NumElements de lista recibida < NumElements de lista inicial: " <<  std::endl;
  std::cout << "Agregando 5 elementos al final de lista 1..." << std::endl;
  for (int i = 17; i < 22; i++) {
    lista1.addLast(i);
  }
  std::cout << "Lista 1: " <<  std::endl; 
  std::cout << "numElements: " << lista1.getNumElements() << std::endl;
  lista1.printList();
  std::cout << std::endl;

  std::cout << "Lista 2: " <<  std::endl; 
  std::cout << "numElements: " << lista2.getNumElements() << std::endl;
  lista2.printList();
  std::cout << std::endl;

  lista1 = lista2;
  std::cout << "Lista 1 modificada : " <<  std::endl;
  lista1.printList();  
  std::cout << "Lista 2 recibida: " <<  std::endl;
  lista2.printList();
  std::cout << std::endl;



// QuickSort
  std::cout << "Ejemplo de Sort \n Lista 1 original: " <<  std::endl; 
  lista1.printList();
  
  std::cout << "Lista 1 después de sort: " <<  std::endl; 
  lista1.sort();
  lista1.printList();
  std::cout << std::endl;

// invert
  std::cout << "Ejemplo de invert \n Lista 1 original: " <<  std::endl; 
  lista1.printList();
  
  std::cout << "Lista 1 después de invert: " <<  std::endl; 
  lista1.invert();
  lista1.printList();
  std::cout << std::endl;

// getReversedSublist
  std::cout << "Ejemplo de getReversedSublist \n Lista 1 original: " <<  std::endl; 
  lista1.printList();
  std::cout << std::endl;
  
  std::cout << "Sublista invertida getReversedSublist(3, 8): " <<  std::endl; 
  DoubleLinkedList<int> lista3=lista1.getReversedSublist(3, 8);
  lista3.printList();
  std::cout << std::endl;

/*
  std::cout << "Ejemplo de sobrecarga del operador = con lista inicial con datos y NumElements de lista recibida vacia: " <<  std::endl;
  std::cout << "Lista 1  original : " ;
  lista1.printList();  
  std::cout << "Lista 4: " <<  std::endl; 
  DoubleLinkedList<int> lista4;
  std::cout << "numElements: " << lista4.getNumElements() << std::endl;
  lista4.printList();
  std::cout << std::endl;

  
  lista1 = lista4;
  std::cout << "Lista 1  modificada : ";
  lista1.printList();  
  std::cout << "numElements: " << lista1.getNumElements() << std::endl;
  std::cout << std::endl;
  std::cout << "Lista 4  recibida: " ;
  lista4.printList();
  std::cout << "numElements: " << lista4.getNumElements() << std::endl;
  std::cout << std::endl;
*/

  return 0;
}