#include <iostream>

int main(void)
{
  int unos;
  
  while(true){
    std::cout << "Unesite pozitivan cijeli broj: ";
    std::cin>>unos;
    if(unos>0)
      break;
    else
      std::cout << "\nNevalidan unos" << '\n';
  }

  for(int i=1;i<=unos;++i){
    for(int k=0; k<i; ++k)
      std::cout << "* ";
    std::cout << '\n';
  }

  return 0;
}
