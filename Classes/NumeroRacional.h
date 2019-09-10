#include <iostream>

using namespace std;

class NumeroRacional{

public:
  NumeroRacional(int numerator, int denominator);
  int num1;
  int num2;
};

NumeroRacional::NumeroRacional(int numerator, int denominator){
  num1 = numerator;
  if(denominator <= 0){ cout << "Denominador inválido!"
  " por isso será inicializado com 1" << endl;
  num2 = 1;
  }else{num2 = denominator;}
}
