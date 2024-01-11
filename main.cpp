#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "person.h"
#include "book.h"
#include "librarian.h"
#include "member.h"


bool askToContinue() {
    char userInput;

    while (true) {
        std::cout << "Welcome to library management system." << std::endl;
        std::cout << "Press Y to continue or N to stop the program (Y/N): ";
        std::cin >> userInput;

        // Ignore any remaining characters in the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (userInput == 'Y' || userInput == 'y') {

            return true;
        } else if (userInput == 'N' || userInput == 'n') {
            return false;
        } else {
            std::cout << "Invalid input. Please enter 'Y' to continue or 'N' to stop." << std::endl;
        }
    }
}


void manage_getting_books_info() {
    bool is_data_book_file_found = false;
    std::string filename;
    std::ifstream input_file;

    std::cout << "Please enter the file that contains book data: " << std::endl;
    std::getline(std::cin, filename);

    while (std::cin.fail()) {
        std::cout << "Error! File " << filename << " was not found and can be read. " << std::endl;
        std::cin.clear();
        is_data_book_file_found = true;
        return;
    }

    std::string book_line = ""; // each line of books data file
    input_file.open(filename);

    std::getline(input_file, book_line); // access to the first line of the books data file that contains id, book author, page count, etc.
    book_line = ""; // reset line to start reading all lines except from the first line that contains headers

    while (std::getline(input_file, book_line)) {
        int book_id;
        std::string book_name;
        std::string page_count;
        std::string author_first_name;
        std::string author_last_name;
        std::string book_type;
        std::time_t due_date;
        std::string tmp_line;// temporary string to help divide headers in book data file

        std::stringstream input_str(book_line);

        std::getline(input_str,tmp_line,','); // setting first header to tmp string
        book_id = stoi(tmp_line); // convert first header to an integer (book_id)
        std::getline(input_str, book_name, ',');
        std::getline(input_str, page_count, ',');
        std::getline(input_str, author_first_name, ',');
        std::getline(input_str, author_last_name, ',');
        std::getline(input_str, book_type, ',');

        book_line = "";
        Book new_book(book_id,book_name,author_first_name,author_last_name);
        Book::get_list_of_books().push_back(new_book);

    }
    std::cout << "\nBooks added successfully!" << std::endl;
}
int main() {
    if(askToContinue()){
        manage_getting_books_info();
        char choice;

        while(true){
            std::cout << "Please choose one of the available options below: " << std::endl;
            std::cout << "Add Member (1) " << std::endl;
            std::cout << "Manage Book (2)" << std::endl;
            std::cout << "Display All Books (3)" << std::endl;
            std::cout << "End Session (4)" << std::endl;
            std::cin >> choice;
            std::cin.ignore();

            switch (choice) {
                case '1':
                    librarian.add_member();
                    break;
                case '2':
                    librarian.manageBook();
                    break;
                case '4':
                    std::cout << "System Exiting" << std::endl;
                    exit(0);
                    break;
                default:
                    std::cout << "Invalid choice. Please choose a valid option." << std::endl;
                    break;
            }
        }

    }else {
        std::cout << "Program stopped. " << std::endl;
    }
    return 0;
}

