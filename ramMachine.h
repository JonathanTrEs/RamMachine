#ifndef RAMMACHINE_H_
#define RAMMACHINE_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <map>

#include "Cinta.h"
#include "Registros.h"
#include "ConjuntoInstrucciones.h"
//#include "Instrucciones.h"

using namespace std;

/** 
 * @brief Códigos de instrucción 
 */
typedef enum { LOAD, STORE, ADD, SUB, MULT, DIV, READ, WRITE, JUMP, JGTZ, JZERO, HALT } CODIGO;

/**
 * @brief Modos de operación 
 */
//typedef enum { INMEDIATO, DIRECTO, INDIRECTO } MODO;

/**
 * @brief Componntes de una instrucción
 */
typedef struct  {
  CODIGO cod;
  MODO mod;
  int operando;
  string etiqueta;
} instruccion;

class programa {
  private:
    vector<instruccion> v_programa;
    map<string ,int> etiquetas;

  public:
    programa();
    programa(const char nombreFichero[]);
    ~programa();

    void cargarPrograma(const char nombreFichero[]);
    void setPrograma (instruccion inst, string op);
    vector<instruccion> getPrograma();
    void mostrarPrograma();
    void mostrarEtiquetas();
    int getTamanoPrograma();
    map<string, int> getEtiquetas();
    void setEtiquetas(map<string, int> etiquet);
    void desensamblar();
};

class ramMachine {
  private:
    programa program;
    Cinta cintaEntrada;
    Cinta cintaSalida;
    Registros registros;
    Instrucciones** v_instrucciones;
    int pc;

  public:
    /// Contstructor y destructor
    ramMachine(const char nombrefichero[], const char nombreCinta[]);
    ~ramMachine();
    void menu();
    void ejecutar();
};

#endif /* RAMMACHINE_H_ */
