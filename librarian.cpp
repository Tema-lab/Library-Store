#include "librarian.h"
#include "member.h"

Librarian::Librarian(int staff_id, std::string name, std::string address, std::string email, int salary) {
    this->staff_id = staff_id;
    this->setName(name);
    this->setAddress(address);
    this->setEmail(email);
    this->salary = salary;
};
// adding member to a vector that holds all members
void Librarian::add_member(Member &new_member) {
    new_member.get_list_of_members().push_back(new_member);
};



void Librarian::issue_book(int member_id, int book_id) {};

void Librarian::return_book(int member_id, int book_id) {};

void Librarian::display_borrowed_books(int member_id) {};

void Librarian::calc_fine(int member_id) {};


int Librarian::get_staff_id() {
    return staff_id;
};

int Librarian::get_salary() {
    return salary;
};

void Librarian::set_staff_id(int staff_id) {
    this->staff_id = staff_id;
};

void Librarian::set_salary(int salary) {
    this->salary = salary;
}
