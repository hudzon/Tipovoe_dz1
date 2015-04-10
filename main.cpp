// Copyright 2015 <Sergey Gudz>

#include "./main.h"

int main()  {
  try  {
    Street *str[3];

    for (int i = 0; i < 3; ++i) {
      str[i] = new Street(i + 1, true);
      str[i]->add(House(1, 9, 106, true));
      str[i]->add(House(2, 8, 91, true));
      str[i]->add(House(3, 2, 33, true));
      str[i]->add(House(4, 3, 42, true));
    }
    for (int i = 0; i < 3; ++i)
      std::cout << str[i] << std::endl;
    std::cout << "Number of voters " << str[0]->getnumber()
          << " Street: " << str[0]->getnuminhabitants();

    std::cout << std::endl << "After" << std::endl;

    str[0]->changeallstreet(10, false);
    str[0]->searchhouse(4)->changeallhouse(4, 123, false);

    str[1]->del(House(3, 2, 33, true));
    str[2]->del(House(2, 8, 91, true));
    str[2]->del(House(3, 2, 33, true));
    for (int i = 0; i < 3; ++i)
      std::cout << str[i] << std::endl;
    std::cout << "Number of voters " << str[0]->getnumber()
          << " Street: " << str[0]->getnuminhabitants();
  }
  catch (const char* msg) {
    std::cout << "\n" << msg << "\n";
  }

  return 0;
}
