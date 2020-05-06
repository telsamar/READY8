#include <iostream>
#include "header.h"
int main() {
std::string name;
std::cin >> name;
std::cin.ignore();
Context io;
My_client vasya(&io, name);
vasya.start_work();
    return 0;
}
