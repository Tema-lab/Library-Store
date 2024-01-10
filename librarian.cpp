#include <iostream>
#include <string>
#include <limits>
#include "librarian.h"
#include "member.h"
#include <vector>
int MEMBER_ID = 1000;

Librarian::Librarian(int staff_id, std::string name, std::string address, std::string email, int salary) {
    this->staff_id = staff_id;
    this->setName(name);
    this->setAddress(address);
    this->setEmail(email);
    this->salary = salary;
};

Librarian librarian(113,"temoid","portnall road","nowayamgs78@gmail.com",85000);

// adding member to a vector that holds all members
void Librarian::add_member() {
    std::string name;
    std::string address;
    std::string email;

    std::cout << "Add member option was chosen." << std::endl;
    std::cout << "Please enter member's name: ";
    std::getline(std::cin, name);
    std::cout << "Please enter member's address: ";
    std::getline(std::cin, address);
    std::cout << "Please enter member's email: ";
    std::getline(std::cin, email);

    Member member(MEMBER_ID,name,address,email);

    std::cout << "New member was added: " << std::endl;

    Member::get_list_of_members().push_back(member);
    print_member_details(MEMBER_ID);

    MEMBER_ID += 1;

    const std::vector<Member> &member_list = Member::get_list_of_members();
    std::cout << "Return to main menu..."<< std::endl;
    std::cout << "All Members: " << std::endl;

    for (const Member &m : member_list) {
        std::cout << "Member ID: " << m.get_member_id() << ", Name: " << m.getName() << std::endl;
    }
};

void Librarian::print_member_details(int member_id) {
    const std::vector<Member> &member_list = Member::get_list_of_members();
    for (const Member& member : member_list){
        if(member.get_member_id() == member_id){
                std::cout << "Member ID: " << member.get_member_id() << std::endl;
                std::cout << "Name: " << member.getName() << std::endl;
                std::cout << "Address: " << member.getAddress() << std::endl;
                std::cout << "Email: " << member.getEmail() << std::endl;


                return;
        }
    }
    std::cout << "Member with id " << member_id << " was not found." << std::endl;
}


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
