//
// Person has address and employment information.
// We want to have separate builders for each.
//

#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <ostream>

class PersonBuilder;

class Person {
    friend class PersonAddressBuilder;
    friend class PersonJobBuilder;

    std::string street_address, post_code, city;
    std::string company_name, position;
    int annual_income = 0;

    friend std::ostream& operator<<(std::ostream& os, const Person& person);
public:
    static PersonBuilder create();
};

#endif //PERSON_H
