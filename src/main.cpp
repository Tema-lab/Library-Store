#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include "../include/person.h"
#include "../include/book.h"
#include "../include/librarian.h"
#include "../include/member.h"
#include "../include/enums.h"

// Function to prompt the user if they want to continue or stop the program
bool askToContinue() {
    std::string userInput;

    while (true) {
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Welcome to library management system." << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Press Y to continue or N to stop the program (Y/N): ";

        std::getline(std::cin, userInput);

        // Ignore any remaining characters in the input buffer
        if ((userInput.size() == 1) && (std::toupper(userInput[0]) == 'Y' || std::toupper(userInput[0]) == 'N')) {
            return std::toupper(userInput[0]) == 'Y';
        } else {
            std::cout << "Invalid input. Please enter 'Y' to continue or 'N' to stop." << std::endl;
        }
    }
}

// Function to manage getting books' information from a file
void manage_getting_books_info() {
    bool is_data_book_file_found = false;
    std::string filename;

    // Loop until a valid book data file is found
    while (!is_data_book_file_found) {
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Please enter the file that contains book data:\n"
                     "(e.g.) ../library_books.csv " << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        std::getline(std::cin, filename);

        if (filename == "../library_books.csv") {
            is_data_book_file_found = true;
        } else {
            std::cout << "Error! Incorrect filename. Please enter '../library_books.csv'." << std::endl;
        }
    }

    std::ifstream input_file(filename);

    if (!input_file.is_open()) {
        std::cout << "Error! File " << filename << " was not found or cannot be read. " << std::endl;
        return;
    }

    std::string book_line = ""; // each line of books data file
    std::getline(input_file, book_line); // access to the first line of the books data file that contains id, book author, page count, etc.
    book_line = ""; // reset line to start reading all lines except from the first line that contains headers

    // Loop through each line in the book data file
    while (std::getline(input_file, book_line)) {
        int book_id;
        std::string book_name;
        std::string page_count;
        std::string author_first_name;
        std::string author_last_name;
        std::string book_type;
        std::string tmp_line; // temporary string to help divide headers in book data file

        std::stringstream input_str(book_line);

        std::getline(input_str, tmp_line, ','); // setting first header to tmp string
        book_id = stoi(tmp_line); // convert first header to an integer (book_id)
        std::getline(input_str, book_name, ',');
        std::getline(input_str, page_count, ',');
        std::getline(input_str, author_first_name, ',');
        std::getline(input_str, author_last_name, ',');
        std::getline(input_str, book_type, ',');

        book_line = "";
        // Create a new Book object and add it to the list of books
        Book new_book(book_id, book_name, author_first_name, author_last_name);
        Book::get_list_of_books().push_back(new_book);
    }
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Books added successfully!" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << " " << std::endl;
}

int get_valid_member_id(){
    int memberID;
    bool is_found = false;
    std::string input;

    std::cout << "Please enter a member id: " << std::endl;

    while (!is_found) {
        bool invalid_input = false;
        std::cin >> input;

        try {
            size_t pos;
            memberID = std::stoi(input, &pos);

            // Check if no extra characters after the number exist
            if (pos == input.size()) {
                is_found = true; // Exit the loop if a valid integer is entered
            } else {
                invalid_input = true;
            }
        } catch (const std::invalid_argument& e) {
            invalid_input = true;
        } catch (const std::out_of_range& e) {
            invalid_input = true;
        }
        if (invalid_input) {
            std::cout << "Invalid input. Please enter a valid member ID (number):" << std::endl;

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return memberID;
}

int main() {
    if(askToContinue()){
        manage_getting_books_info();

        while(true){
            // Display menu and perform actions based on user input
            std::cout << "===============================" << std::endl;
            std::cout << "      Library Management      " << std::endl;
            std::cout << "===============================" << std::endl;
            std::cout << "Please choose one of the available options below: " << std::endl;
            std::cout << "Add Member (1) " << std::endl;
            std::cout << "Manage Book (2)" << std::endl;
            std::cout << "Display All Books Borrowed by a Member (3)" << std::endl;
            std::cout << "End Session (4)" << std::endl;

            int intChoice;
            std::cin >> intChoice;
            MenuOption choice = static_cast<MenuOption>(intChoice);

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "----------------------------------------" << std::endl;
                std::cout << "Invalid input. Please enter a valid numeric option." << std::endl;
                std::cout << "----------------------------------------" << std::endl;
                continue;
            }
            std::cin.ignore();

            switch (choice) {
                case MenuOption::ADD_MEMBER:{
                    librarian.add_member();
                    break;
                }
                case MenuOption::MANAGE_BOOK:
                {
                    std::cout << "----------------------------------------" << std::endl;
                    std::cout << "Manage book option was chosen." << std::endl;
                    std::cout << "----------------------------------------" << std::endl;
                    librarian.manageBook();
                    break;
                }
                case MenuOption::DISPLAY_BOOKS_BORROWED: {
                    std::cout << "----------------------------------------" << std::endl;
                    std::cout << "Display books borrowed by member option was chosen." << std::endl;
                    std::cout << "----------------------------------------" << std::endl;
                    int member_id = get_valid_member_id();
                    librarian.display_borrowed_books(member_id);
                    break;
                }
                case MenuOption::END_SESSION:{
                    std::cout << "----------------------------------------" << std::endl;
                    std::cout << "Thank you for using our system!\nSee you again!" << std::endl;
                    std::cout << "----------------------------------------" << std::endl;
                    exit(0);
                    break;
                }
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

