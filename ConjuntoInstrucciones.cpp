/*
 * ConjuntoInstrucciones.cpp
 *
 *  Created on: 15/02/2014
 *      Author: oliver
 */

#define MAX_INT 2147483647

#include "ConjuntoInstrucciones.h"

void Load_i::ejecutar(MODO modo, int dato, string etiqueta) {
  if (modo == 0)
    escribirRegistro(0, dato);
  else if (modo == 1)
    escribirRegistro(0, getRegistros()[dato]);
  else if (modo == 2)
    escribirRegistro(0, getRegistros()[getRegistros()[dato]]);
  setPc(getPc() + 1);
}

void Store_i::ejecutar(MODO modo, int dato, string etiqueta) {
  if (modo == 1)
    escribirRegistro(dato, getRegistros()[0]);
  else if (modo == 2)
    escribirRegistro(getRegistros()[dato], getRegistros()[0]);
  setPc(getPc() + 1);
}

void Add_i::ejecutar(MODO modo, int dato, string etiqueta) {
  if (modo == 0)
    if (((getRegistros()[0] > 0) && (dato > 0) && ((getRegistros()[0] + dato) < 0)) || 
         ((getRegistros()[0] < 0) && (dato < 0) && ((getRegistros()[0] + dato) > 0))) {
      cout << "Error, desbordamiento en la linea " << getPc() + 1 << endl;
      setPc(-1);
    }
    else {
      escribirRegistro(0, getRegistros()[0] + dato);
      setPc(getPc() + 1);
    }
  else if (modo == 1)
    if (((getRegistros()[0] > 0) && (getRegistros()[dato] > 0) && ((getRegistros()[0] + getRegistros()[dato]) < 0)) || 
         ((getRegistros()[0] < 0) && (getRegistros()[dato] < 0) && ((getRegistros()[0] + getRegistros()[dato]) > 0))) {
      cout << "Error, desbordamiento en la linea " << getPc() + 1 << endl;
      setPc(-1);
    }
    else {
      escribirRegistro(0, getRegistros()[0] + getRegistros()[dato]);
      setPc(getPc() + 1);
    }
  else if (modo == 2)
    if (((getRegistros()[0] > 0) && (getRegistros()[getRegistros()[dato]] > 0) && ((getRegistros()[0] + getRegistros()[getRegistros()[dato]]) < 0)) || 
         ((getRegistros()[0] < 0) && (getRegistros()[getRegistros()[dato]] < 0) && ((getRegistros()[0] + getRegistros()[getRegistros()[dato]]) > 0))) {
      cout << "Error, desbordamiento en la linea " << getPc() + 1 << endl;
      setPc(-1);
    }
    else {
      escribirRegistro(0, getRegistros()[0] + getRegistros()[getRegistros()[dato]]);
      setPc(getPc() + 1);
    }
}

void Sub_i::ejecutar(MODO modo, int dato, string etiqueta) {
  if (modo == 0)
    if (((getRegistros()[0] > 0) && (dato < 0) && ((getRegistros()[0] - dato) < 0)) || 
       ((getRegistros()[0] < 0) && (dato > 0) && ((getRegistros()[0] - dato) > 0))) {
      cout << "Error, desbordamiento en la linea " << getPc() + 1 << endl;
      setPc(-1);
    }
    else {
      escribirRegistro(0, getRegistros()[0] - dato);
      setPc(getPc() + 1);
    }
  else if (modo == 1)
    if (((getRegistros()[0] > 0) && (getRegistros()[dato] < 0) && ((getRegistros()[0] - getRegistros()[dato]) < 0)) || 
       ((getRegistros()[0] < 0) && (getRegistros()[dato] > 0) && ((getRegistros()[0] - getRegistros()[dato]) > 0))) {
      cout << "Error, desbordamiento en la linea " << getPc() + 1 << endl;
      setPc(-1);
    }
    else {
      escribirRegistro(0, getRegistros()[0] - getRegistros()[dato]);
      setPc(getPc() + 1);
    }
  else if (modo == 2)
    if (((getRegistros()[0] > 0) && (getRegistros()[getRegistros()[dato]] < 0) && ((getRegistros()[0] - getRegistros()[getRegistros()[dato]]) < 0)) || 
       ((getRegistros()[0] < 0) && (getRegistros()[getRegistros()[dato]] > 0) && ((getRegistros()[0] - getRegistros()[getRegistros()[dato]]) > 0))) {
      cout << "Error, desbordamiento en la linea " << getPc() + 1 << endl;
      setPc(-1);
    }
    else {
      escribirRegistro(0, getRegistros()[0] - getRegistros()[getRegistros()[dato]]);
      setPc(getPc() + 1);
    }
}

void Mult_i::ejecutar(MODO modo, int dato, string etiqueta) {
  if (modo == 0)
    if (((getRegistros()[0] > 0) && (dato > 0) && ((getRegistros()[0] * dato) < 0)) || 
       ((getRegistros()[0] < 0) && (dato < 0) && ((getRegistros()[0] * dato) < 0))) {
      cout << "Error, desbordamiento en la linea " << getPc() + 1 << endl;
      setPc(-1);
    }
    else {
      escribirRegistro(0, getRegistros()[0] * dato);
      setPc(getPc() + 1);
    }
  else if (modo == 1)
    if (((getRegistros()[0] > 0) && (getRegistros()[dato] > 0) && ((getRegistros()[0] * getRegistros()[dato]) < 0)) || 
       ((getRegistros()[0] < 0) && (getRegistros()[dato] < 0) && ((getRegistros()[0] * getRegistros()[dato]) < 0))) {
      cout << "Error, desbordamiento en la linea " << getPc() + 1 << endl;
      setPc(-1);
    }
    else {
      escribirRegistro(0, getRegistros()[0] * getRegistros()[dato]);
      setPc(getPc() + 1);
    }
  else if (modo == 2)
    if (((getRegistros()[0] > 0) && (getRegistros()[getRegistros()[dato]] > 0) && ((getRegistros()[0] * getRegistros()[getRegistros()[dato]]) < 0)) || 
       ((getRegistros()[0] < 0) && (getRegistros()[getRegistros()[dato]] < 0) && ((getRegistros()[0] * getRegistros()[getRegistros()[dato]]) < 0))) {
      cout << "Error, desbordamiento en la linea " << getPc() + 1 << endl;
      setPc(-1);
    }
    else {
      escribirRegistro(0, getRegistros()[0] * getRegistros()[getRegistros()[dato]]);
      setPc(getPc() + 1);
    }
}

void Div_i::ejecutar(MODO modo, int dato, string etiqueta) {
  if (modo == 0) {
    if (dato == 0) {
      cout << "Error división entre 0 en la línea " << getPc() + 1;
      setPc(-1);
    }
    else {
      escribirRegistro(0, getRegistros()[0] / dato);
      setPc(getPc() + 1);
    }
  }
  else if (modo == 1) {
    if (getRegistros()[dato] == 0) {
      cout << "Error división entre 0 en la línea " << getPc() + 1;
      setPc(-1);
    }
    else {
      escribirRegistro(0, getRegistros()[0] / getRegistros()[dato]);
      setPc(getPc() + 1);
    }
  }
  else if (modo == 2) {
    if (getRegistros()[getRegistros()[dato]] == 0) {
      cout << "Error división entre 0 en la línea " << getPc() + 1;
      setPc(-1);
    }
    else {
      escribirRegistro(0, getRegistros()[0] / getRegistros()[getRegistros()[dato]]);
      setPc(getPc() + 1);
    }
  }
}

void Read_i::ejecutar(MODO modo, int dato, string etiqueta) {
  int num = getCintaEntrada()[0];
  vector<int> aux;
  for (int i = 1; i < getCintaEntrada().size(); i++)
    aux.push_back(getCintaEntrada()[i]);
  setCintaEntrada(aux);
  if (modo == 1)
    escribirRegistro(dato, num);
  else if (modo == 2)
    escribirRegistro(getRegistros()[dato], num);
  setPc(getPc() + 1);
}

void Write_i::ejecutar(MODO modo, int dato, string etiqueta) {
  if (modo == 0)
    escribirCinta(dato);
  if (modo == 1)
    escribirCinta(getRegistros()[dato]);
  if (modo == 2)
    escribirCinta(getRegistros()[getRegistros()[dato]]);
  setPc(getPc() + 1);
}

void Jump_i::ejecutar(MODO modo, int dato, string etiqueta) {
  setPc(getEtiquetas().find(etiqueta)->second);
}

void Jgtz_i::ejecutar(MODO modo, int dato, string etiqueta) {
  if (getRegistros()[0] > 0)
    setPc(getEtiquetas().find(etiqueta)->second);
  else
    setPc(getPc() + 1);
}

void Jzero_i::ejecutar(MODO modo, int dato, string etiqueta) {
  if (getRegistros()[0] == 0)
    setPc(getEtiquetas().find(etiqueta)->second);
  else
    setPc(getPc() + 1);
}

void Halt_i::ejecutar(MODO modo, int dato, string etiqueta) {
  setPc(-1);
  ofstream fs("cintaSalida.txt");
  for (int i = 0; i < getCintaSalida().size(); i++)
    fs << getCintaSalida()[i] << " ";
}
