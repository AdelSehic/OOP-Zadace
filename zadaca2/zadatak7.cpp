#include <iostream>
#include <vector>

int main(void)
{
  int broj, min=0, max=0, sum=0, pro=1;
  std::vector<int> v;
  
  std::cin>>broj;

  int temp = 0;
  do{
    temp = broj % 10;
    broj /= 10;
    
    if(temp<min)
      min = temp;
    if(temp>max)
      max = temp;

    sum += temp;
    pro*=temp;
    
    v.push_back(temp);
  }while(broj>0);

  for (const int& i : v)
    std::cout << i; 

  std::cout << '\n' << min << '\n' << max << '\n' << sum << '\n' << pro << '\n';

  return 0;
}
