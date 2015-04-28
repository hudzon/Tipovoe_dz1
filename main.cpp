// Copyright 2015 <Sergey Gudz>

#include "./main.h"

int main() {
  try  {
    Street str[3];

    for (int i = 0; i < 1; ++i) {
      str[i] = Street("Lenina", true);
      str[i].add(House(1, 9, 106, true));
      str[i].add(House(2, 8, 91, true));
      str[i].add(House(3, 2, 33, true));
      str[i].add(House(4, 3, 42, true));
    }
    str[1] = str[0];
    str[2] =  Street(str[1]);
    str[2].set_name("Tverskaya");

    for (int i = 0; i < 3; ++i)
      std::cout << str[i] << "\n";
    std::cout << "Number of voters " << str[0].get_name()
          << " Street: " << str[0].get_num_inhabitants();

    std::cout << "\n" << "After" << "\n";

    str[0].change_all_street("bkubkub", false);
    str[0].find(House(4, 3, 42, true)).change_all_house(4, 123, false);

    str[1].del_in_order(4);
    str[1].del(House(3, 2, 33, true));
    str[2].del(House(2, 8, 91, true));
    str[2].del(House(3, 2, 33, true));

    for (int i = 0; i < 3; ++i)
      std::cout << str[i] << "\n";

    std::cout << "Number of voters " << str[0].get_name()
          << " Street: " << str[0].get_num_inhabitants();

    return 0;
  }
  catch (const std::exception& ex) {
    std::cout << "\n" << ex.what() << "\n";

    return 0;
  }
}
