#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <limits>
#include <regex>
#include "librarian.h"
#include "member.h"
#include "book.h"

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
    std::regex emailRegex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");

    std::cout << "Add member option was chosen." << std::endl;
    std::cout << "Please enter member's name: ";
    std::getline(std::cin, name);
    std::cout << "Please enter member's address: ";
    std::getline(std::cin, address);
    do {
        std::cout << "Please enter member's email: ";
        std::getline(std::cin, email);

        if (!std::regex_match(email, emailRegex)) {
            std::cout << "Invalid email format. Please enter a valid email address." << std::endl;
        }
    } while (!std::regex_match(email, emailRegex));


    Member member(MEMBER_ID,name,address,email);

    std::cout << "New member was added: " << std::endl;

    Member::get_list_of_members().push_back(member);
    print_member_details(MEMBER_ID);

    MEMBER_ID += 1;
    std::cout << "Return to main menu..."<< std::endl;
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

void Librarian::manageBook() {
    int member_id;
    int book_id;

    std::cout << "If you would you like to issue a book to a member please enter 1. \n"
              << "If you would like to return a book please enter 2." << std::endl;
    char choice;
    std::cin >> choice;

    switch (choice) {
        case '1':
            // Get member_id and book_id from the user and pass them to issue_book
            std::cout << "Please enter a member id: " << std::endl;
            std::cin >> member_id;
            std::cout << "Please enter a book id: " << std::endl;
            std::cin >> book_id;
            issue_book(member_id, book_id);
            break;

        case '2':
            std::cout << "Return a book option was chosen." << std::endl;
            // Get member_id and book_id from the user and pass them to issue_book
            std::cout << "Please enter a member id: " << std::endl;
            std::cin >> member_id;
            std::cout << "Please enter a book id that you wish to return: " << std::endl;
            std::cin >> book_id;
            return_book(member_id, book_id);
            break;
        default:
            std::cout << "Invalid input! Please provide a valid one." << std::endl;
            break;
    }
}

void Librarian::issue_book(int member_id, int book_id) {
    Member* member = find_member(member_id);
    Book* book = find_book(book_id);
    std::time_t due_date = std::time(nullptr) + 3 * 24 * 60 * 60; // 3 days in seconds

    if (member != nullptr) {
        std::cout << "Member with id " << member_id << " was found." << std::endl;
    } else {
        std::cout << "Error! Member with id " << member_id << " was not found. Please provide a valid member id. " << std::endl;
        return;
    }

    if (book != nullptr) {
        std::cout << "Book with id " << book_id << " was found." << std::endl;
        std::cout << "Book name: " <<  book->get_book_name() << std::endl;
        std::cout << "Book ID: " << book_id << std::endl;

//        if (book->is_book_issued(*book) && book->borrower == member) {
//            std::cout << "Error! Book with ID " << book_id << " is already issued to Member with ID " << member_id << ". Cannot issue the same book again." << std::endl;
//            std::cout << "Returning to the main menu... " << std::endl;
//            return;
//        }

        //pass a vector of a single book
        member->set_books_borrowed(book);
        book->borrow_book(member,due_date);
    } else {
        std::cout << "Error! Book with id " << book_id << " was not found. Please provide a valid book id. " << std::endl;
        std::cout << "Returning to the main menu... " << std::endl;
        return;
    }

    // Displaying the date of issue
    std::time_t issue_date = std::time(nullptr);
    std::tm* local_time = std::localtime(&issue_date);

    // Formatting and displaying the date
    std::cout << "The date of issue is: ";
    std::cout << std::put_time(local_time, "%Y-%m-%d %H:%M:%S") << std::endl;

    //displaying the due date
    std::cout << "The due date is: ";
    std::cout << std::put_time(std::localtime(&due_date), "%Y-%m-%d %H:%M:%S") << std::endl;

    std::cout << "Issuing book with ID " << book_id << " to member with ID " << member_id << std::endl;
    std::cout << "Returning to the main menu... " << std::endl;
};

void Librarian::return_book(int member_id, int book_id) {
    Member* member = find_member(member_id);
    Book* book = find_book(book_id);
    const std::vector<Book *> &borrowed_books = member->get_books_borrowed();
    auto specified_book = std::find(borrowed_books.begin(), borrowed_books.end(), book);

    if (member != nullptr && book != nullptr) {
        std::cout << "Member with id " << member_id << " was found." << std::endl;
        if(member->get_books_borrowed().empty()){
            std::cout << "Member with id " << member_id << " doesnt have any books borrowed" << std::endl;
            return;
        }
        if (specified_book == borrowed_books.end()) {
            std::cout << "Error! Member with id " << member_id << " hasn't borrowed the book with id " << book_id << "." << std::endl;
            return;
        }
        std::cout << "Book with id " << book_id << " was found." << std::endl;

        member->remove_borrowed_book(book);
        std::cout << "Book with id: " << book_id << " was returned." << std::endl;

        // Calculate the difference in seconds between due date and current date
        std::time_t current_time = std::time(nullptr);
        std::time_t due_date = book->get_due_date();
        std::time_t time_difference = current_time - due_date;

        // Check if the book is returned late (more than 3 days)
        if (time_difference > 3 * 24 * 60 * 60) {
            std::cout << "Book is returned late. Calculating fine..." << std::endl;
            //calc_fine(member_id);
        } else {
            std::cout << "Book is returned on time. No fine is applied." << std::endl;
        }
    } else {
        std::cout << "Error! Member or book not found. Please provide valid IDs." << std::endl;
    }
};

Member* Librarian::find_member(int member_id){
    std::vector<Member>& members = Member::get_list_of_members();

    for(auto& member : members){
        if(member.get_member_id() == member_id){
            return &member; // we return a pointer to a found member
        }
    }
    return nullptr; // we could not find a member
}

Book* Librarian::find_book(int book_id) {
    std::vector<Book>& books = Book::get_list_of_books();
    for(auto& book : books){
        if(book.get_book_id() == std::to_string(book_id)){
            return &book;
        }
    }
    return nullptr; // we could not find a book with provided id
}

void Librarian::display_borrowed_books(int member_id) {
    Member* member = find_member(member_id);

    if (member != nullptr) {
        std::vector<Book *> borrowed_books = member->get_books_borrowed();
        if(borrowed_books.empty()){
            std::cout << "The member with ID: " << member_id << " doesnt have any borrowed books." << std::endl;
        }else{
            std::cout << "All books borrowed by:\n";
            print_member_details(member_id);
            for (const Book* book : borrowed_books) {
                std::cout << "Book ID: " << book->get_book_id() << "\n";
                std::cout << "Book Name: " << book->get_book_name() << "\n";
                std::cout << "Author: " << book->get_author_first_name() << " " << book->get_author_last_name() << std::endl;
                std::cout << "\n";
            }
        }
    } else {
        std::cout << "Error! Member with ID " << member_id << " was not found. Please provide a valid member ID. " << std::endl;
    }
}

void Librarian::calc_fine(int member_id) {

};


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
