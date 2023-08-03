#include "menufesto.h"

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {

    // Create a test menu Menu object.
    Menu the_main_menu("TEST MENU");

    // // Test the get_int method.
    // int age = the_main_menu.get_int("Please enter your age: ");
    // cout << "Your age is: " << age << endl;

    // Test the get_float method.
    float dec_value = the_main_menu.get_float("Please enter a decimal point value: ");
    cout << "Your decimal point value is: " << dec_value << endl;

    // Test the get_string method.
    string fav_food = the_main_menu.get_string("Please enter your favorite food: ");

    return 0;
}