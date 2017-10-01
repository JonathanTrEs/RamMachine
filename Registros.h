/*
 * Registros.h
 *
 *  Created on: 15/02/2014
 *      Author: oliver
 */

#ifndef REGISTROS_H_
#define REGISTROS_H_

#include "Cinta.h"

class Registros {
  private:
    vector<int> v_registros;
    int tamano;

  public:
    Registros();
    ~Registros();
    int consultar(int posicion);
    void escribirRegistro(int posicion, int dato);
    vector<int> getRegistros();
    void setRegistros(vector<int> registros);
    void mostrarRegistros();
};

#endif /* REGISTROS_H_ */
