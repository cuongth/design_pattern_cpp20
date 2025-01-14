#ifndef TEAFACTORY_H
#define TEAFACTORY_H

#include "HotDrinkFactory.h"

class TeaFactory : public HotDrinkFactory
{
public:
    ~TeaFactory() override
    {
        std::cout << "TeaFactory destructor" << std::endl;
    }

    [[nodiscard]] std::unique_ptr<HotDrink> make() const override
    {
        return std::make_unique<Tea>();
    }
};

#endif //TEAFACTORY_H
