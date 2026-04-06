#include "Automata.h"
#include <iostream>
int main() {
    std::cout << "Demonstration scenario\n" << std::endl;
    Automata vending;
    vending.on();
    vending.getMenu();
    std::cout << "\nPutting coins in" << std::endl;
    for(int i = 0; i < 4; i++) {
        vending.coin();
    }
    vending.choice();
    std::cout << "\nBuying a green tea" << std::endl;
    vending.cook(2);
    std::cout << "Current state: " << vending.getState() << std::endl;
    std::cout << "\nTryna buy cola without enough money" << std::endl;
    vending.choice();
    vending.cook(3);
    std::cout << "\nAdding some money" << std::endl;
    for(int i = 0; i < 3; i++) {
        vending.coin();
    }
    vending.choice();
    vending.cook(3);
    std::cout << "\nTurning off" << std::endl;
    vending.off();
    return 0;
}
