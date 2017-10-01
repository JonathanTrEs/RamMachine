/*
 * Cinta.cpp
 *
 *  Created on: 14/02/2014
 *      Author: oliver
 */

#include "Cinta.h"

Cinta::Cinta() {}

Cinta::Cinta(const char nombreFichero[]) {
  cargarCinta(nombreFichero);
}

Cinta::~Cinta() {
  cinta.clear();
}

void Cinta::cargarCinta(const char nombreFichero[]) {
  ifstream fichero(nombreFichero, ifstream::in);
  int dato;
  fichero >> dato;
  while(!fichero.eof()) {
    cinta.push_back(dato);
    fichero >> dato;
  }
}

void Cinta::mostrarCinta() {
  for (int i = 0; i < cinta.size(); i++)
    cout << cinta[i] << " ";
  cout << endl;
}

vector<int> Cinta::getCinta() {
  return cinta;
}

void Cinta::setCinta(vector<int> v_cinta) {
  cinta = v_cinta;
}
