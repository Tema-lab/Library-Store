#include "person.h"

void Person::setName(const std::string& new_name){
    name = new_name;
}

void Person::setAddress(const std::string& new_address){
    address = new_address;
}

void Person::setEmail(const std::string& new_email){
    email = new_email;
}

std::string Person::getName() const {
    return name;
}

std::string Person::getAddress() const {
    return address;
}

std::string Person::getEmail() const {
    return email;
}

