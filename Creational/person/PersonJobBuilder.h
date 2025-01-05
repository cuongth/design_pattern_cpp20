#ifndef PERSONJOBBUILDER_H
#define PERSONJOBBUILDER_H
#include "PersonBuilder.h"

class PersonJobBuilder: public PersonBuilderBase
{
    typedef PersonJobBuilder self;
public:
    explicit PersonJobBuilder(Person& person)
        : PersonBuilderBase{person}
    {}
    self& at(const std::string& company_name)
    {
        person.company_name = company_name;
        return *this;
    }
    self& as_a(const std::string& position)
    {
        person.position = position;
        return *this;
    }
    self& earning(int annual_income)
    {
        person.annual_income = annual_income;
        return *this;
    }
};
#endif //PERSONJOBBUILDER_H
