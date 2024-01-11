#include "person.h"


// Setter function to update the name of the person
void Person::setName(const std::string& new_name){
    name = new_name;
}
// Setter function to update the address of the person
void Person::setAddress(const std::string& new_address){
    address = new_address;
}
// Setter function to update the email of the person
void Person::setEmail(const std::string& new_email){
    email = new_email;
}

// Getter function to retrieve the name of the person
std::string Person::getName() const {
    return name;
}
// Getter function to retrieve the address of the person
std::string Person::getAddress() const {
    return address;
}
// Getter function to retrieve the email of the person
std::string Person::getEmail() const {
    return email;
}

