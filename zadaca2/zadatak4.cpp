#include <sys/ioctl.h>
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>
#include <string>

size_t broj_kolona() {
  winsize sz;
  ioctl(0, TIOCGWINSZ, &sz);
  return sz.ws_col;
}

void pauziraj(unsigned int msec) {
  std::flush(std::cout);
  std::this_thread::sleep_for(std::chrono::milliseconds{msec});
}

void bar(const char q, const char w, const std::vector<double> e){

  std::string u(broj_kolona()-1, q);
  std::cout << u << ']' << '\r' << '[';
  for(const double& b : e){
    if(b==0)
      continue;
    std::string s( broj_kolona() * (b/100), w);
    pauziraj(850);
    std::cout << s;
  }
  std::cout << '\r';

}

int main() {

  std::vector<double> a;
  std::cout << "Please enter 4 values (0-100): ";

  do{
    for(int input;a.size()<4 && std::cin>>input;){
      a.push_back(input);
    }
    if(a.size()<4){
      std::cout << "\nYou have to enter at least 4 values.\nEnter a new set of values: ";
      std::cin.clear(); // ocisti buffer
      a.clear();
    }
    else if(a.at(0)+a.at(1)+a.at(2)+a.at(3)!=100){
      std::cout << "\nBoundaries must have a sum equal to 100.\nEnter a new set of values: ";
      a.clear();
    }
    else
      break;
  }while(true);

  while(true){
    bar(' ', '=', a);
    bar('=', ' ', a);
  }

  return 0;
}
