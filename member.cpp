#include "member.h"
#include "book.h"


 Member::Member(int member_id, std::string name, std::string address, std::string email) {
    this->member_id = member_id;
    this->setName(name);
    this->setAddress(address);
    this->setEmail(email);
};

int Member::get_member_id() const{
    return member_id;
};

std::vector<Book> Member::get_books_borrowed(){
    return books_loaned;
}

void Member::set_books_borrowed(const std::vector<Book>& books) {
    books_loaned = books;
}
//function which returns a reference to the vector of member objects
std::vector<Member>& Member::get_list_of_members(){
    //create vector that holds all member objects
    static std::vector<Member> member_list;
    return member_list;
}


