#ifndef PERSONADDRESSBUILDER_H
#define PERSONADDRESSBUILDER_H
#include "PersonBuilder.h"

class PersonAddressBuilder: public PersonBuilderBase
{
    typedef PersonAddressBuilder self;
public:
    explicit PersonAddressBuilder(Person& person)
        : PersonBuilderBase{person}
    {}
    self& at(const std::string& address)
    {
        person.street_address = address;
        return *this;
    }
    self& with_postcode(const std::string& post_code)
    {
        person.post_code = post_code;
        return *this;
    }
    self& in(const std::string& city)
    {
        person.city = city;
        return *this;
    }
};

#endif //PERSONADDRESSBUILDER_H
