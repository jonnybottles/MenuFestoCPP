#ifndef MENU_H
#define MENU_H

#include <string>

using namespace std;

// The Menu class provides the functions and attributes required to
// create menus, accept, and validate user input.
class Menu {
  public:
    // Constructor that accepts a string for the menu name.
    Menu(const string &menu_name);

    // Member functions

    // Prints a given menu name.
    void print_menu_name(const string &menu_name);

    // clear the screen
    void clear_screen(void);

    // get a string from the user
    string get_string(const string &prompt);
    // get an integer from the user
    int get_int(const string &prompt);

    // Static function to handle program quit
    static void quit_program(int signal);

  private:
    // Private data member for the menu name
    string menu_name;

    // Helper function to validate integer input
    pair<bool, int> is_valid_int(const string &response);
};

#endif // MENU_H