#ifndef HOTDRINK_H
#define HOTDRINK_H

#include <iostream>

// Abstract class
class HotDrink
{
public:
    virtual ~HotDrink() = default;
    virtual void prepare(int volume) = 0;
};

class Tea: public HotDrink
{
public:
    ~Tea() override
    {
        std::cout << "Destructor of Tea" << std::endl;
    }
    void prepare(int volume) override
    {
        std::cout << "Take a tea bag, boil water, pour "
                  << volume << "ml, add some lemon" << std::endl;
    }
};

class Coffee: public HotDrink
{
public:
    ~Coffee() override
    {
        std::cout << "Destructor of Coffee" << std::endl;
    }
    void prepare(int volume) override
    {
        std::cout << "Grind some beans, boil water, pour "
                  << volume << "ml, add some sugar" << std::endl;
    }
};

#endif //HOTDRINK_H
