/*
 * ConjuntoInstrucciones.h
 *
 *  Created on: 15/02/2014
 *      Author: oliver
 */

#ifndef CONJUNTOINSTRUCCIONES_H_
#define CONJUNTOINSTRUCCIONES_H_

#include "Instrucciones.h"

class Load_i: public Instrucciones {
  public:
    Load_i() {}
    ~Load_i() {}
    void ejecutar(MODO, int, string);
};

class Store_i: public Instrucciones {
  public:
    Store_i() {}
    ~Store_i() {}
    void ejecutar(MODO, int, string);
};


class Add_i: public Instrucciones {
  public:
    Add_i() {}
    ~Add_i() {}
    void ejecutar(MODO, int, string);
};

class Sub_i: public Instrucciones {
  public:
    Sub_i() {}
    ~Sub_i() {}
    void ejecutar(MODO, int, string);
};

class Mult_i: public Instrucciones {
  public:
    Mult_i() {}
    ~Mult_i() {}
    void ejecutar(MODO, int, string);
};

class Div_i: public Instrucciones {
  public:
    Div_i() {}
    ~Div_i() {}
    void ejecutar(MODO, int, string);
};

class Read_i: public Instrucciones {
  public:
    Read_i() {}
    ~Read_i() {}
    void ejecutar(MODO, int, string);
};

class Write_i: public Instrucciones {
  public:
    Write_i() {}
    ~Write_i() {}
    void ejecutar(MODO, int, string);
};

class Jump_i: public Instrucciones {
  public:
    Jump_i() {}
    ~Jump_i() {}
    void ejecutar(MODO, int, string);
};

class Jgtz_i: public Instrucciones {
  public:
    Jgtz_i() {}
    ~Jgtz_i() {}
    void ejecutar(MODO, int, string);
};

class Jzero_i: public Instrucciones {
  public:
    Jzero_i() {}
    ~Jzero_i() {}
    void ejecutar(MODO, int, string);
};

class Halt_i: public Instrucciones {
  public:
    Halt_i() {}
    ~Halt_i() {}
    void ejecutar(MODO, int, string);
};

#endif /* CONJUNTOINSTRUCCIONES_H_ */
