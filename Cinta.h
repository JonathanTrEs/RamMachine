/*
 * Cinta.h
 *
 *  Created on: 14/02/2014
 *      Author: oliver
 */

#ifndef CINTA_H_
#define CINTA_H_

#include <vector>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

class Cinta {
  private:
    vector<int> cinta;

  public:
    Cinta();
    Cinta(const char nombreFichero[]);
    ~Cinta();
    void cargarCinta(const char nombreFichero[]);
    vector<int> getCinta();
    void setCinta(vector<int> cinta);
    void mostrarCinta();
};


#endif /* CINTA_H_ */
