#include <iostream>
#include <algorithm>
#include <vector>

int main(int argc, char *argv[])
{
  int unos = 0;
  std::cout << "\nUnesite pozitivan cijeli broj: ";
  for(; !(std::cin>>unos) || unos < 1;){
    std::cin.clear();
    std::cout << "\nUnesite pozitivan cijeli broj: ";
  }

  for(int i = 1; i <= unos; ++i){
    for(int j = i; j <= unos; ++j){
      for(int k = j; k <= unos; ++k){
        if( (i*i + j*j == k*k) && (j<k) )
          std::cout << '(' << i << ',' << j << ',' << k << ')' << std::endl;
      }
    }
  }

  /*
  std::vector<int> v;
  int unos, counter=0;
  std::cin >> unos;

  // punjenje vekora odgovarajucim vrijednostima :

  for (int i = 1; i <= unos; ++i) {
    for (int j = 1; j <= unos; ++j) {
      for (int k = 1; k <= unos; ++k) {
        if(i*i + j*j == k*k){
          v.push_back(i);
          v.push_back(j);
          v.push_back(k);
          std::sort(v.begin()+counter, v.end());
          counter += 3;
        }
      }
    }
  }

  // brisanje duplikata :

  for (int i = 0; i < v.size(); i+=3) {
    for (int k = i+3; k < v.size(); k+=3) {
      if( v.at(i) == v.at(k) && v.at(i+1) == v.at(k+1) && v.at(i+2) == v.at(k+2) ) {
        v.erase( v.begin() + k, v.begin() + k + 3 );
      }
    }
  }

  // sortiranje preostalih rezultata :
  
  for (int i = 0; i < v.size(); i+=3) {
    for (int k = i+3; k < v.size(); k+=3) {
      if( v.at(i)+v.at(i+1)+v.at(i+2) > v.at(k)+v.at(k+1)+v.at(k+2) ) {
        std::swap( v.at(i), v.at(k) );
        std::swap( v.at(i+1), v.at(k+1) );
        std::swap( v.at(i+2), v.at(k+2) );
      }
    }
  }

  // ispis konacnog vektora :

  std::cout << '\n';
  for(int i = 0; i<v.size();i+=3)
    std::cout << '(' << v.at(i) << ',' << v.at(i+1) << ',' << v.at(i+2) << ')' << '\n';
  */
  return 0;
}
