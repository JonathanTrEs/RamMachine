/*
 * Instrucciones.h
 *
 *  Created on: 15/02/2014
 *      Author: oliver
 */

#ifndef INSTRUCCIONES_H_
#define INSTRUCCIONES_H_

#include "Cinta.h"
#include <map>


typedef enum { INMEDIATO, DIRECTO, INDIRECTO } MODO;

class Instrucciones {
  private:
    vector<int> v_registros;
    vector<int> cintaEntrada;
    vector<int> cintaSalida;
    map<string, int> etiquetas;
    int pc;
  public:
    Instrucciones();
    virtual ~Instrucciones();
    virtual void ejecutar(MODO, int, string) = 0;
    vector<int> getRegistros() {return v_registros;}
    void setRegistros(vector<int> registros) {v_registros = registros;}
    void escribirRegistro(int posicion, int dato) {v_registros[posicion] = dato;}
    vector<int> getCintaEntrada() {return cintaEntrada;}
    void setCintaEntrada(vector<int> cinta) {cintaEntrada = cinta;}
    vector<int> getCintaSalida() {return cintaSalida;}
    void setCintaSalida(vector<int> cinta) {cintaSalida = cinta;}
    void escribirCinta(int dato) {cintaSalida.push_back(dato);}
    int getPc() {return pc;}
    void setPc(int num) {pc = num;}
    void setEtiquetas(map<string, int> etiquet) {etiquetas = etiquet;}
    map<string, int> getEtiquetas() {return etiquetas;}
};


#endif /* INSTRUCCIONES_H_ */
