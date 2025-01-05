#ifndef PERSONBUILDER_H
#define PERSONBUILDER_H

#include "Person.h"

class PersonAddressBuilder;
class PersonJobBuilder;

class PersonBuilderBase
{
protected:
    Person &person;
public:
    explicit PersonBuilderBase(Person &person);
    operator Person() const;
    [[nodiscard]] PersonAddressBuilder lives() const;
    [[nodiscard]] PersonJobBuilder works() const;
};

class PersonBuilder : public PersonBuilderBase
{
    Person person_; // object being build
public:
    PersonBuilder();
};

#endif //PERSONBUILDER_H
