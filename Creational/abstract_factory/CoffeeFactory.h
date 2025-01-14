#ifndef COFFEEFACTORY_H
#define COFFEEFACTORY_H

#include "HotDrinkFactory.h"

class CoffeeFactory: public HotDrinkFactory
{
public:
    ~CoffeeFactory() override
    {
        std::cout << "CoffeeFactory destructor" << std::endl;
    }

    [[nodiscard]] std::unique_ptr<HotDrink> make() const override
    {
        return std::make_unique<Coffee>();
    }
};

#endif //COFFEEFACTORY_H
