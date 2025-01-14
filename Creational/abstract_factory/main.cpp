#include <iostream>
#include "DrinkFactory.h"
#include "HotDrink.h"

int main()
{
    DrinkFactory f;
    unique_ptr<HotDrink> d1 = f.make_drink("tea");
    std::cout << "Enjoy my tea! add:"
              << d1 << std::endl;

    DrinkWithVolumeFactory vf;
    unique_ptr<HotDrink> d2 = vf.make_drink("coffee");
    std::cout << "Enjoy my coffee! add:"
              << d2 << std::endl;

    return 0;
}