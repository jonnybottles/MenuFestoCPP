#include "menu.h"

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {

    Menu the_main_menu("TEST MENU");

    the_main_menu.get_int("Please enter your age: ");

    return 0;
}