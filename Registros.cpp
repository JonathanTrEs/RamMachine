/*
 * Registros.cpp
 *
 *  Created on: 15/02/2014
 *      Author: oliver
 */

#include "Registros.h"

Registros::Registros() {
  tamano = 12;
  for(int i = 0; i < tamano; i++)
    v_registros.push_back(0);
}

Registros::~Registros() {
  v_registros.clear();
}

int Registros::consultar(int posicion) {
  return v_registros[posicion];
}

void Registros::escribirRegistro(int posicion, int dato) {
  v_registros[posicion] = dato;
}

vector<int> Registros::getRegistros() {
  return v_registros;
}

void Registros::setRegistros(vector<int> registros) {
  v_registros = registros;
}

void Registros::mostrarRegistros() {
  for (int i = 0; i < v_registros.size(); i++)
    cout << "r[" << i << "] = " << v_registros[i] << endl;
}
