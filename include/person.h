#ifndef LIBRARY_STORE_PERSON_H
#define LIBRARY_STORE_PERSON_H

#include <string>

class Person{
private:
    std::string name;
    std::string address;
    std::string email;
public:
    std::string getName() const;
    std::string getAddress() const;
    std::string getEmail() const;

    void setName(const std::string&);
    void setAddress(const std::string&);
    void setEmail(const std::string&);
};


#endif //LIBRARY_STORE_PERSON_H
