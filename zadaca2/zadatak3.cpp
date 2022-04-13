#include <sys/ioctl.h>
#include <chrono>
#include <iostream>
#include <thread>
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

void napred(const char a){
  std::cout << a;
  pauziraj(35);
  std::cout << "\b \b ";
}

void nazad(const char a){
  std::cout << "\b \b" << a;
  pauziraj(35);
  std:: cout << "\b \b";
}

int main() {
  while(true){

  for (int i = 0; i<broj_kolona()-1;++i){
    switch (i%4) {
      case 0:
        napred('-');
        break;
      case 1:
        napred('\\');
        break;
      case 2:
        napred('|');
        break;
      case 3:
        napred('/');
        break;
    }
  }

  for (int i = 0; i<broj_kolona()-1;++i){
    switch (i%4) {
      case 0:
        nazad('-');
        break;
      case 1:
        nazad('/');
        break;
      case 2:
        nazad('|');
        break;
      case 3:
        nazad('\\');
        break;
    }
  }
  }

  return 0;
}

