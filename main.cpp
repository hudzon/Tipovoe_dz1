// Copyright 2015 <Sergey Gudz>

#include "./main.h"

int main()  {
  try  {
    Street str[3];

    for (int i = 0; i < 2; ++i) {
      str[i] = Street(i + 1, true);
      str[i].add(House(1, 9, 106, true));
      str[i].add(House(2, 8, 91, true));
      str[i].add(House(3, 2, 33, true));
      str[i].add(House(4, 3, 42, true));
    }

    str[2] =  Street(str[1]);
    str[2].set_number(3);
    for (int i = 0; i < 3; ++i)
      std::cout << str[i] << std::endl;
    std::cout << "Number of voters " << str[0].get_number()
          << " Street: " << str[0].get_num_inhabitants();

    std::cout << std::endl << "After" << std::endl;

    str[0].change_all_street(10, false);
    str[0].search_house(4).change_all_house(4, 123, false);

    str[1].del_in_order(1);
    str[1].del(House(3, 2, 33, true));
    str[2].del(House(2, 8, 91, true));
    str[2].del(House(3, 2, 33, true));

    for (int i = 0; i < 3; ++i)
      std::cout << str[i] << std::endl;

    std::cout << "Number of voters " << str[0].get_number()
          << " Street: " << str[0].get_num_inhabitants();

    return 0;
  }
  catch (const std::exception& ex) {
    std::cout << "\n" << ex.what() << "\n";
  }
}
