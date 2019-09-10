#include <iostream>
#include <string>

using namespace std;

class Data{

public:

  Data(int day, int monty, int year);
  void setMes(int m);
  int getMes();
  void setDia(int d);
  int getDia();
  void setAno(int a);
  int getAno();
  int quantDias(int month);
  void print();

private:
  int mes;
  int dia;
  int ano;
};

void Data::print(){
  cout << dia << "/" << mes << "/" << ano << endl;
}

int Data::quantDias(int month){
  int diastot;
  if(month%2 == 0) diastot =  mes*30;
  else diastot = mes*31;
  return diastot;
}
// Item D incompleto
int Data::quantDias(string month){
  int diastot;
  string meses[12] = {"Janeiro" , "Fevereiro",
  "Março", "Abril", "Maio", "Junho", "Julho",
  "Agosto", "Setembro", "Outubro", "Novembro",
  "Dezembro"};

  if(meses[month]%2 == 0) diastot =  mes*30;
  else diastot = mes*31;
  return diastot;
}

Data::Data(int day = 1, int month = 1, int year = 1500){

  if(0 < month <= 12) mes = month;
  else{
    cout << "Mês inválido" << endl;
    mes = 1;
  }

  if(month%2 == 0){
    if(0 < day <= 30) dia = day;
    else{
      cout << "Dia inválido" << endl;
      dia = 1;
    }
  }else{
    if(0 < day <= 31) dia = day;
    else{
      cout << "Dia inválido" << endl;
      dia = 1;
    }
  }

  if(year > 0) ano = year;
  else{
    cout << "Ano inválido" << endl;
    ano = 1;
  }
}



// void Data::setMes(int m){
// }
//
// void Data::setDia(int d){
// }
//
// void Data::setAno(int a){
// }
