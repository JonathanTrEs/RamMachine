#include "ramMachine.h"

int main() {
  char fichero[20];
  char ficheroCinta[20];
  cout << "Introduzca el nombre del fichero del programa RAM" << endl;
  cin >> fichero;
  cout << "Introduzca el nombre de la cinta de entrada" << endl;
  cin >> ficheroCinta;
  ramMachine a(fichero, ficheroCinta);
  a.menu();
}
