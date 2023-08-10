#include <iostream>
#include "cat.h"

int main(int argc, char* argv[]) {
    Cat a("Garfield");
    
    std::cout << a.get_name() << " has "
              << a.get_lives() << " lives." << std::endl;
              
    Cat b("Mog" , 10);
    std::cout << b.get_name() << " has "
              << b.get_lives() << " lives." << std::endl;
    
    //(a)
    unsigned int new_lives_a = 42;
    b.set_lives(new_lives_a);
    std::cout << b.get_name() << " has "
              << b.get_lives() << " lives." << std::endl;

    //(b)
    std::string new_name_b = "Prince";
    b.set_name(new_name_b);
    std::cout << b.get_name() << " has "
              << b.get_lives() << " lives." << std::endl;

    //(c)
    unsigned int new_lives_c = 8;
    b.set_lives(new_lives_c);
    std::cout << b.get_name() << " has "
              << b.get_lives() << " lives." << std::endl;

    //(d)
    unsigned int new_lives_d = 0;
    b.set_lives(new_lives_d);
    std::cout << b.get_name() << " has "
              << b.get_lives() << " lives." << std::endl;

    //(e)
    unsigned int new_lives_e = 0;
    b.set_lives(new_lives_e);
    std::cout << b.get_name() << " has "
              << b.get_lives() << " lives." << std::endl;

              
    return 0;
}