#include "ramMachine.h"

ramMachine::ramMachine(const char nombrefichero[], const char nombreCinta[]) {
  program = programa(nombrefichero);
  cintaEntrada = Cinta(nombreCinta);
  v_instrucciones = new Instrucciones* [12];
  v_instrucciones[0] = new Load_i();
  v_instrucciones[1] = new Store_i();
  v_instrucciones[2] = new Add_i();
  v_instrucciones[3] = new Sub_i();
  v_instrucciones[4] = new Mult_i();
  v_instrucciones[5] = new Div_i();
  v_instrucciones[6] = new Read_i();
  v_instrucciones[7] = new Write_i();
  v_instrucciones[8] = new Jump_i();
  v_instrucciones[9] = new Jgtz_i();
  v_instrucciones[10] = new Jzero_i();
  v_instrucciones[11] = new Halt_i();
  pc = 0;
}

ramMachine::~ramMachine() {

}

programa::programa() {

}

programa::programa(const char nombreFichero[]) {
  cargarPrograma(nombreFichero);
}

programa::~programa() {
  v_programa.clear();
}

void programa::cargarPrograma(const char nombreFichero[]) {
  ifstream fichero (nombreFichero, ifstream::in);
  instruccion instruc;
  string codigo;
  string operando;
  instruc.etiqueta = "null";
  while(getline(fichero, codigo, ' ')) {
    if (codigo != "") {
      if (codigo == ";")
        getline(fichero, codigo);
      else {
        if (codigo == "LOAD") {
          instruc.cod = LOAD;
          fichero >> operando;
          setPrograma(instruc, operando);
        }
        else if (codigo == "STORE") {
          instruc.cod = STORE;
          fichero >> operando;
          setPrograma (instruc, operando);
        }
        else if (codigo == "ADD") {
          instruc.cod = ADD;
          fichero >> operando;
          setPrograma (instruc, operando);
        }
        else if (codigo == "SUB") {
          instruc.cod = SUB;
          fichero >> operando;
          setPrograma (instruc, operando);
        }
        else if (codigo == "MULT") {
          instruc.cod = MULT;
          fichero >> operando;
          setPrograma (instruc, operando);
        }
        else if (codigo == "DIV") {
          instruc.cod = DIV;
          fichero >> operando;
          setPrograma (instruc, operando);
        }
        else if (codigo == "READ") {
          instruc.cod = READ;
          fichero >> operando;
          setPrograma (instruc, operando);
        }
        else if (codigo == "WRITE") {
          instruc.cod = WRITE;
          fichero >> operando;
          setPrograma (instruc, operando);
        }
        else if (codigo == "JUMP") {
          instruc.cod = JUMP;
          fichero >> operando;
          setPrograma (instruc, operando);
        }
        else if (codigo == "JGTZ") {
          instruc.cod = JGTZ;
          fichero >> operando;
          setPrograma (instruc, operando);
        }
        else if (codigo == "JZERO") {
          instruc.cod = JZERO;
          fichero >> operando;
          setPrograma (instruc, operando);
        }
        else if (codigo == "HALT") {
          instruc.cod = HALT;
          operando = "0";
          setPrograma (instruc, operando);
        }
        else if ((codigo != "\n") && (codigo.substr(0, codigo.size() - 1).size() > 1)) {
          if (codigo.substr(codigo.size() - 1, codigo.size()) == ":")
            etiquetas[codigo.substr(0, codigo.size() - 1)] = getTamanoPrograma();
          else
            etiquetas[codigo] = getTamanoPrograma();
        }
      }
    }
  }
}

void programa::setPrograma (instruccion inst, string op) {
  if (op.substr(0,1) == "*" || op.substr(0,1) == "=") {
    string m = op.substr(0,1);
    op = op.substr(1,op.size());
    inst.operando = atoi(op.c_str());
    inst.etiqueta = "null";
    if (m == "*")
      inst.mod = INDIRECTO;
    else
      inst.mod = INMEDIATO;
  }
  else if (op.size() <= 2) {
    inst.mod = DIRECTO;
    inst.operando = atoi(op.c_str());
    inst.etiqueta = "null";
  }
  else {
    inst.etiqueta = op;
    inst.operando = -1;
    inst.mod = DIRECTO;
  }
  /*if ((op.size() > 1) && (op.size() <= 2)) {
    string m = op.substr(0,1);
    op = op.substr(1,2);
    inst.operando = atoi(op.c_str());
    inst.etiqueta = "null";
    if (m == "*")
      inst.mod = INDIRECTO;
    else
      inst.mod = INMEDIATO;
  }
  else if (op.size() > 2) {
    inst.etiqueta = op;
    inst.operando = -1;
    inst.mod = DIRECTO;
  }
  else {
    inst.mod = DIRECTO;
    inst.operando = atoi(op.c_str());
    inst.etiqueta = "null";
  }*/
  v_programa.push_back(inst);
}

int programa::getTamanoPrograma() {
  return v_programa.size();
}

vector<instruccion> programa::getPrograma() {
  return v_programa;
}

void programa::mostrarPrograma() {
  cout << "Programa: " << endl;
  instruccion inst;
  for (int i = 0; i < getTamanoPrograma(); i++) {
    cout << v_programa[i].cod << " " << v_programa[i].mod << " " << v_programa[i].operando << " " << v_programa[i].etiqueta << endl;
  }
}

void programa::mostrarEtiquetas() {
  cout << "Etiquetas: " << endl;
  for (map<string, int>::iterator it = etiquetas.begin(); it != etiquetas.end(); it++) {
    cout << it->first << " " << it->second + 1 << endl;
  }
}

map<string, int> programa::getEtiquetas() {
  return etiquetas;
}

void programa::setEtiquetas(map<string, int> etiquet) {
  etiquetas = etiquet;
}

void programa::desensamblar() {
  for (int i = 0; i < v_programa.size(); i++) {
    cout << i + 1 << "  ";
    switch(v_programa[i].cod) {
      case 0: cout << "Load ";  break;
      case 1: cout << "Store "; break;
      case 2: cout << "Add "; break;
      case 3: cout << "Sub "; break;
      case 4: cout << "Mult "; break;
      case 5: cout << "Div "; break;
      case 6: cout << "Read "; break;
      case 7: cout << "Write "; break;
      case 8: cout << "Jump "; break;
      case 9: cout << "Jgtz "; break;
      case 10: cout << "Jzero "; break;
      case 11: cout << "Halt "; break;
    }
    if (v_programa[i].mod == 0)
      cout << "=";
    else if (v_programa[i].mod == 2)
      cout << "*";
    if (v_programa[i].etiqueta == "null")
      cout << v_programa[i].operando << endl;
    else
      cout << v_programa[i].etiqueta << endl;
  }
}

void ramMachine::ejecutar() {
  bool ejecucion = true;
  while(ejecucion) {
    cout << "contador: " << pc << endl;
    //Pasamos copia de las cintas de entrada y salida, registros, programa y contador de programa
    v_instrucciones[program.getPrograma()[pc].cod]->setCintaEntrada(cintaEntrada.getCinta());
    v_instrucciones[program.getPrograma()[pc].cod]->setCintaSalida(cintaSalida.getCinta());
    v_instrucciones[program.getPrograma()[pc].cod]->setEtiquetas(program.getEtiquetas());
    v_instrucciones[program.getPrograma()[pc].cod]->setRegistros(registros.getRegistros());
    v_instrucciones[program.getPrograma()[pc].cod]->setPc(pc);
    //Ejecutamos la instrucción
    v_instrucciones[program.getPrograma()[pc].cod]->ejecutar(program.getPrograma()[pc].mod, program.getPrograma()[pc].operando, program.getPrograma()[pc].etiqueta);
    //Actualizamos cintas de entrada y salida, registros y contador de programa
    cintaEntrada.setCinta(v_instrucciones[program.getPrograma()[pc].cod]->getCintaEntrada());
    cintaSalida.setCinta(v_instrucciones[program.getPrograma()[pc].cod]->getCintaSalida());
    program.setEtiquetas(v_instrucciones[program.getPrograma()[pc].cod]->getEtiquetas());
    registros.setRegistros(v_instrucciones[program.getPrograma()[pc].cod]->getRegistros());
    pc = v_instrucciones[program.getPrograma()[pc].cod]->getPc();
    //Mostramos registros actuales
    cout << endl;
    registros.mostrarRegistros();
    cout << endl;
    if(pc == -1)
      ejecucion = false;
  }
}

int opcion() {
  cout << endl;
  cout << "1. Mostrar programa" << endl;
  cout << "2. Desensamblador" << endl;
  cout << "3. Ver registros" << endl;
  cout << "4. Mostrar etiquetas" << endl;
  cout << "5. Ejecutar" << endl;
  cout << "6. Mostrar cinta de entrada" << endl;
  cout << "7. Mostrar cinta de salida" << endl;
  cout << "8. Salir" << endl;
  cout << ">";
  int opc;
  cin >> opc;
  cout << endl;
  return opc;
}

void ramMachine::menu() {
  int opc;
  int fin = 1;
  while (fin == 1) {
    opc = opcion();
    switch (opc) {
      case 1: program.mostrarPrograma();
              break;
      case 2: program.desensamblar();
              cout << endl;
              program.mostrarEtiquetas();
              break;
      case 3: registros.mostrarRegistros();
              break;
      case 4: program.mostrarEtiquetas();
              break;
      case 5: ejecutar();
              break;
      case 6: cout << "Cinta de entrada:" << endl;
              cintaEntrada.mostrarCinta();
              break;
      case 7: cout << "Cinta de salida:" << endl;
              cintaSalida.mostrarCinta();
              break;
      case 8: fin = 0;
              break;
    }
  }
}

