#include "Person.h"
#include "PersonBuilder.h"

PersonBuilder Person::create()
{
    return {};
}

std::ostream& operator<<(std::ostream& os, const Person& person)
{
    os << "Address: " << person.street_address << ", "
       << person.city << ", " << person.post_code << '\n'
       << "Work as " << person.company_name << " as a "
       << person.position << " and earns "
       << person.annual_income << std::endl;

    return os;
}
