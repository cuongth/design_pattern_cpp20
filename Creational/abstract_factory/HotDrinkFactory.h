#ifndef HOTDRINKFACTORY_H
#define HOTDRINKFACTORY_H
#include <memory>
#include "HotDrink.h"

// Abstract factory class
class HotDrinkFactory
{
public:
    virtual ~HotDrinkFactory() = default;
    virtual std::unique_ptr<HotDrink> make() const = 0;
};

#endif //HOTDRINKFACTORY_H
