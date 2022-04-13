#include <iostream>
#include <string>
#include <cmath>

int errA = 0, errB = 0;

int string2int(const std::string& v, int b){
  int k = 0;
  try{
    k = stoi(v); 
  }catch(std::invalid_argument& q){
    if(b==1)
      ++errB;
    else
      ++errA;
  }

  return k;
}

int main(void)
{
  std::string s1, s2;
  char c;
  int a, b;

  for(;std::cin >> s1 >> c >> s2;){

  a = string2int(s1, 0);
  b = string2int(s2, 1);

  if( errA == 1 && errB == 1 ){
    errA = 0;
    errB = 0;
    std::cout << "Nevalidan unos. '" << s1 << "' i '"<< s2 << "' nisu brojevi." << std::endl;
    continue;
  }
  else if (errA == 1) {
    errA = 0;
    std::cout << "Nevalidan unos. '" << s1 <<"' nije broj." << std::endl;
    continue; 
  }
  else if (errB == 1) {
    errB = 0;
    std::cout << "Nevalidan unos. '" << s2 <<"' nije broj." << std::endl;
    continue;
  }

  if (c=='+') {
    std::cout << a+b << std::endl;
  }else if (c=='-') {
    std::cout << a-b << std::endl;
  }else if (c=='*') {
    std::cout << a*b << std::endl;
  }else if (c=='/') {
    if(b==0)
      std::cout << "Dijeljenje s nulom je nedefinisana operacija." << std::endl;
    else
      std::cout << (1.0 * a)/b << std::endl;
  }else if (c=='%') {
    std::cout << a%b << std::endl;
  }else if (c=='^') {
    std::cout << std::pow(a, b) << std::endl;
  }else if (c=='=') {
    if(a == b)
      std::cout << "true" << std::endl;
    else
      std::cout << "false" << std::endl;
  }

  }
  
  return 0;
} 
