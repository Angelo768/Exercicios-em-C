#include "Conta.h"
#include <iomanip>

// using namespace std;

int main(){

  Conta banco(1000);
  banco.print();
  banco.Credito();
  banco.Debito(10);

}
