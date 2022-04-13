#include <bitset>
#include <iostream>
#include "anim.h"

// Poziv funkcije printBits rezultovace sa ispisom
// proslijedjenog broja u binarnoj formi.
//
// Primjer:
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// unsigned short s = 5;
// printBits(s);
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Ispis:
// 0000000000000101
// 
void printBits(unsigned short reg) {
  std::bitset<16> bits(reg);
  std::cout << bits << std::endl;
}


int main() {
  short int option, bit, bit1=0, bit2=0, bn=0, registar=1;
  
  std::cout << "Please choose register 1 or 2: " << '\n';

  for(;std::cin >> registar;){
    if(registar<1 || registar>2){
      std::cout << "Please choose either register 1 or 2!\n" << "Please choose register 1 or 2: " << '\n';
      continue;
    }
    if(registar == 1)
      bit = bit1;
    else
      bit = bit2;
   std::cout << "\n1. Print register\n2. Set bit in register\n3. Reset bit in register\n4. Exit\nEnter option: ";
   for (;std::cin >> option;) {
     if (option == 1) {
       printBits(bit);
     } 
     else if (option == 2) {
       std::cout << "Enter bit number: ";
       std::cin >> bn;
       bit |= (1UL << (bn-1) ) ;
       std::cout << "New register value: " << bit << '\n';
       printBits(bit);
     } 
     else if (option == 3) {
       std::cout << "Enter bit number: " << '\n'; 
       std::cin >> bn;
       bit &= ~( 1UL << (bn-1) );
       std::cout << "New register value: " << bit << '\n';
       printBits(bit);
     } 
     else if (option == 4) {
       break;
     }
   std::cout << "\n1. Print register\n2. Set bit in register\n3. Reset bit in register\n4. Exit\nEnter option: ";
   }
    bool ext=false;
    std::cout << "What do you wish to do next:\n\t1. Continue editing registers\n\t2. Swap register\n\t3. Exit\nEnter your option: " << '\n';
   for(; std::cin >> option;){
    if(option == 1)
      break;
    else if(option == 2){
      std::swap(bit1, bit2);
      std::cout << "Bits of both registers have been swapped, choose your next operation:\n\t1. Continue editing registers\n\t2. Swap register\n\t3. Exit\nEnter your option: " << '\n';
    }
    else if(option == 3){
      ext=true;
      break;
    }
    else{
      std::cout << "Please choose a valid input: " << '\n';
      continue;
    }
   }
   if(ext == true)
     break;
    std::cout << "Please choose register 1 or 2: " << '\n';
  }

  shtDwn();

  return 0;
}
