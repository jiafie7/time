#include <iostream>

#include "utility/time.h"

using namespace melon::utility;

int main()
{
  Time t1;
  std::cout << "t1: " << t1.format("%Y-%m-%d %H-%M-%S") << '\n';

  Time::setSleep(2000);

  Time t2;
  std::cout << "t2: " << t2.format("%Y-%m-%d %H-%M-%S") << '\n';
  
  std::cout << "Time interval between t1 and t2 is " << t2 - t1 << " microseconds" << '\n';

  return 0;
}
