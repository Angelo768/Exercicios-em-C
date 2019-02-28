#include <iostream>
#include <iomanip>

using namespace std;

class Conta{
public:
  Conta(float saldo);
  float getSaldo();
  float Credito();
  float Debito(float debitar);
  void print();

private:
  float saldoinicial;
};

Conta::Conta(float saldo){
  (saldo >= 0) ? saldoinicial = saldo : saldoinicial = 0;
}

float Conta::getSaldo(){
  return saldoinicial;
}

float Conta::Credito(){
  float cred = saldoinicial*1.15;
  return cred;
}

void Conta::print(){
  cout << "Você possui R$" << getSaldo()
  << " de Saldo" << endl;
}

float Conta::Debito(float debitar){
  saldoinicial = saldoinicial - debitar;
  if(saldoinicial < 0) {
  cout << "Você não possui saldo suficiente para efetuar a operação" << endl;
  }
}
