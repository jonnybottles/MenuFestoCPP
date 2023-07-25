#include "menu.h"
#include <algorithm>
#include <cctype>
#include <csignal>
#include <cstdlib>
#include <fstream>
#include <iostream>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

// Menu constructor implementation.
// Prints the menu name at construction.
Menu::Menu(const string &menu_name) : menu_name(menu_name) {
    print_menu_name(menu_name);
}

// Function to clear the screen, works on Windows and Linux.
void Menu::clear_screen(void) {
#ifdef _WIN32
    // For Windows
    system("cls");
#else
    // ANSI escape code to clear the screen for non-Windows systems
    cout << "\033[2J\033[1;1H";
#endif
}

// Prints a given menu name.
void Menu::print_menu_name(const string &menu_name) {
    cout << "***** " << menu_name << " *****\n";
}

// Obtains a string from the user.
string Menu::get_string(const string &prompt) {
    // Register signal handler for SIGINT (Ctrl+C)
    signal(SIGINT, quit_program);

    string response;
    while (true) {
        cout << prompt;
        // Check to see if the input stream is still good.
        if (!getline(cin, response)) {
            // If we have reached EOF (e.g., Ctrl+D / Ctrl+C).
            if (cin.eof()) {
                quit_program(EOF);
            } else {
                // If there are any other input stream errors, quit the program.
                quit_program(1);
            }
        } else {
            // Input stream is good, break the loop.
            break;
        }
    }
    return response;
}

// Helper function to validate if a string can be converted to an int
pair<bool, int> Menu::is_valid_int(const string &response) {
    try {
        // Try to convert the string to an integer.
        // If successful, return true and the integer.
        return {true, stoi(response)};
    } catch (invalid_argument &e) {
        // If a std::invalid_argument exception is caught, return false and 0.
        return {false, 0};
    }
}

// Function to get an integer input from the user.
int Menu::get_int(const string &prompt) {
    // Register signal handler for SIGINT (Ctrl+C)
    signal(SIGINT, quit_program);

    string response;
    while (true) {
        cout << prompt;
        // Check to see if the input stream is still good.
        if (!getline(cin, response)) {
            // If we have reached EOF (e.g., Ctrl+D / Ctrl+C)
            if (cin.eof()) {
                quit_program(EOF);
            } else {
                // If there are any other input stream errors, quit the program.
                quit_program(1);
            }
        } else {
            pair<bool, int> parsed = is_valid_int(response);
            if (parsed.first) {
                // If the string can be parsed to an integer, return the integer
                return parsed.second;
            } else {
                // If the string can't be parsed to an integer, print an error message
                cout << "Please enter a valid number: \n";
            }
        }
    }
}

// Function to handle program termination
void Menu::quit_program(int signal) {
    if (signal == SIGINT || signal == EOF) {
        // If the program is terminated by SIGINT (Ctrl+C) or EOF (Ctrl+D), print a message
        cout << "\nExiting program.\n";
    } else {
        // If the program is terminated due to an error, print an error message
        cerr << "Input error. Exiting program." << std::endl;
    }

    // Terminate the program with the provided signal code
    exit(signal);
}