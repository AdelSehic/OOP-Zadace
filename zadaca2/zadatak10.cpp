#include <iostream>
#include <chrono>
#include <random>

int main(void)
{
  std::random_device ran;
  std::mt19937 rng(ran());
  std::uniform_int_distribution<std::mt19937::result_type> dist6(1,100);

  int broj = dist6(rng), unos;
  bool pog = false;

  std::cout << "Unesite broj: " << std::endl;

  for(int i = 0; std::cin >> unos && i<4; ++i){
    if(broj == unos){
      pog = true;
      std::cout << "Cestitam, pogodili ste broj!" << '\n';
      break;
    }
    else if(unos < broj){
      std::cout << "Zamisljeni broj je veci." << '\n';
      std::cout << "Unesite broj : " << std::endl;
    }
    else if(unos > broj){
      std::cout << "Zamisljeni broj je manji." << '\n';
      std::cout << "Unesite broj : " << std::endl;
    }
  }

  if(pog==false)
    std::cout << "Nazalost, niste pogodili broj" << std::endl;

  return 0;
}
