#include <chrono>
#include <thread>
#include <iostream>

void pauziraj(unsigned int msec) {
  std::flush(std::cout);
  std::this_thread::sleep_for(std::chrono::milliseconds{msec});
}

void shtDwn(){
  std::cout << "Operations with register ended, shutting down";
  for(int i=0;i<5;++i){
    for(int x=0; x<8; ++x){
      std::cout << '.';
      pauziraj(250);
    }
    std::cout << "\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b";
  }
  std::cout << "........\n";
}
