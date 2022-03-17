#include <iostream>
#include "TComplex.h"
int main()
{
  TComplex com1(3, 5);
  TComplex com2;
  TComplex com3 = com2;
  com1.SetRe(10);
  std::cout << com1.GetRe() << "+" << com1.GetIm() << std::endl;
  com2.SetRe(3);
  com2.SetIm(4);
  com3 = com2 + com1;
  std::cout << com3 << std::endl;
  com2 = com3 - com1;
  std::cout << com2;
  if (com1 == com2)
  {
    std::cout << "com1 = com2" << std::endl;
  }
  com3 = com1 * com2;
  std::cout << com3 << std::endl;
  com3 = com1 / com2;
  std::cout << com3 << std::endl;
  std::cin >> com2;
  return 0;

}
