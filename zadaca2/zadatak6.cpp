#include <iostream>
#include <string>

int main(void)
{
  std::string a, b;
  int count=0;

  while(true){
  getline(std::cin, a);
  getline(std::cin, b);
  if(a.size() != b.size())
    std::cout << "Stringovi moraju biti iste duzine!\nUnesite stringove: \n";
  else
    break;
  }

  for(int i = 0; i < a.size() ; ++i){
    if( a.at(i) != b.at(i) )
      ++count;
  }

  std::cout << "\nHamiltonova distanca: " << count << '\n';

  return 0;
} 
