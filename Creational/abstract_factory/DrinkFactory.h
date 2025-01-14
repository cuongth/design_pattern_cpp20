#ifndef DRINKFACTORY_H
#define DRINKFACTORY_H

#include <functional>
#include <map>
#include <string>
#include "TeaFactory.h"
#include "CoffeeFactory.h"

using namespace std;

class DrinkFactory
{
private:
    map<string, unique_ptr<HotDrinkFactory>> drinks;
public:
    DrinkFactory()
    {
        drinks["tea"] = make_unique<TeaFactory>();
        drinks["coffee"] = make_unique<CoffeeFactory>();
    }

    unique_ptr<HotDrink> make_drink(const string& name)
    {
        auto d = drinks[name]->make();
        d->prepare(200); // oops
        return d;
    }
};

// Functional factory
class DrinkWithVolumeFactory
{
private:
    map<string, function<unique_ptr<HotDrink>()>> factories;
public:
    DrinkWithVolumeFactory()
    {
        factories["tea"] = []
        {
            auto tea = make_unique<Tea>();
            tea->prepare(200);
            return tea;
        };
        factories["coffee"] = []
        {
            auto coffee = make_unique<Coffee>();
            coffee->prepare(50);
            return coffee;
        };
    }

    unique_ptr<HotDrink> make_drink(const string& name);
};

inline unique_ptr<HotDrink> DrinkWithVolumeFactory::make_drink(const string& name)
{
    return factories[name]();
}

#endif //DRINKFACTORY_H
