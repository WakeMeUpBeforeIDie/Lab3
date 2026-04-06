#include "Automata.h"
#include <iostream>
#include <string>
Automata::Automata() : cash(0.0), state(OFF) {
    menu[0] = "coffee";
    menu[1] = "black tea";
    menu[2] = "green tea";
    menu[3] = "cola";
    prices[0] = 35.75;
    prices[1] = 20.34;
    prices[2] = 20.22;
    prices[3] = 134.47;
    std::cout << "Automata created" << std::endl;
}
void Automata::on() {
    if (state == OFF) {
        state = WAIT;
        std::cout << "Automata is on. Waiting for coins..." << std::endl;
    }
}
void Automata::off() {
    if (state != COOK) {
        state = OFF;
        cash = 0;
        std::cout << "Automata is off" << std::endl;
    }
}
void Automata::coin() {
    if (state == WAIT) {
        state = ACCEPT;
        cash += 10.5;
        std::cout << "Coin inserted. Balance: " << cash << std::endl;
    } else if (state == ACCEPT) {
        cash += 10.5;
        std::cout << "Coin inserted. Balance: " << cash << std::endl;
    } else {
        std::cout << "Cannot insert coin now" << std::endl;
    }
}
void Automata::getMenu() {
    std::cout << "Menu:" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << i + 1 << ". " << menu[i] << " costs " << prices[i] << std::endl;
    }
}
STATES Automata::getState() {
    return state;
}
void Automata::choice() {
    if (state == ACCEPT) {
        state = CHECK;
        std::cout << "Make your choice (enter number 1-4):" << std::endl;
        getMenu();
    } else {
        std::cout << "Cannot make choice now. Current state: " << state << std::endl;
    }
}
bool Automata::check(int index) {
    if (index < 0 || index >= 4) {
        std::cout << "Invalid index" << std::endl;
        return false;
    }
    bool sufficient = cash >= prices[index];
    if (sufficient) {
        std::cout << "Sufficient funds. Price: " << prices[index]<< ", Your balance: " << cash << std::endl;
    } else {
        std::cout << "Insufficient funds. Need: " << prices[index] - cash << " more" << std::endl;
    }
    return sufficient;
}
void Automata::cancel() {
    if (state == ACCEPT || state == CHECK) {
        state = WAIT;
        std::cout << "Operation cancelled. Returning " << cash << std::endl;
        cash = 0;
    } else {
        std::cout << "Cannot cancel now" << std::endl;
    }
}
void Automata::cook(int index) {
    if (state == CHECK && check(index)) {
        state = COOK;
        cash -= prices[index];
        std::cout << menu[index] << " is being cooked..." << std::endl;
        std::cout << "The drink is ready." << std::endl;
        finish();
    } else {
        std::cout << "Cannot cook." << std::endl;
    }
}
void Automata::finish() {
    if (state == COOK) {
        std::cout << "Automata has been brought back into waiting state." << std::endl;
        if (cash > 0) {
            std::cout << "Change returned: " << cash << " rub" << std::endl;
            cash = 0;
        }
        state = WAIT;
    }
}
