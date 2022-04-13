#include <iostream>

namespace T{
  const double cel2kel = 273.15;
  void foo(const double &a){
    std::cout << a << " degrees Celsius is " << a + cel2kel << " degrees Kelvin." << std::endl;
  }
}

namespace V{
  
}

int main(int argc, char *argv[])
{
  int odabir;

  std::cout << "Welcome to Unit converter. Please enter one of the following options\n\t1. Temperature\n\t2. Speed\n\t3. Length\n\t4. Weight\n\t5. Fuel economy\nYour choice: ";
  std::cin >> odabir;
  
  switch (odabir) {
    case 1:
      std::cout << "\nEnter your temperature in degrees Celsius: ";
      double k; std::cin >> k;
      T::foo(k);
      break;
    default:
      break;
  }

  return 0;
}
