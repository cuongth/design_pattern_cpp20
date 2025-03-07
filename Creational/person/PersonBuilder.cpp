#include "PersonBuilder.h"
#include "PersonAddressBuilder.h"
#include "PersonJobBuilder.h"

PersonBuilderBase::PersonBuilderBase(Person &person)
    : person{person}
{}

PersonBuilderBase::operator Person() const
{
    return std::move(person);
}

PersonAddressBuilder PersonBuilderBase::lives() const
{
    return PersonAddressBuilder{person};
}

PersonJobBuilder PersonBuilderBase::works() const
{
    return PersonJobBuilder{person};
}

PersonBuilder::PersonBuilder()
    : PersonBuilderBase{person_}
{}

