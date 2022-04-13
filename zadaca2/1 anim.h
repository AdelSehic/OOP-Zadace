#include <chrono>
#include <thread>
#include <sys/ioctl.h>
#include <iostream>





void pauziraj(unsigned int msec) {
  std::flush(std::cout);
  std::this_thread::sleep_for(std::chrono::milliseconds{msec});
}

void shtDwn(){
  std::cout << "Operations with register ended, shutting down";
  for(int i=0;i<7;++i){
    std::cout << '.';
    pauziraj(250);
  }
}
