#ifndef AUTOMATA_H
#define AUTOMATA_H
#include <string>
enum STATES {OFF, WAIT, ACCEPT, CHECK, COOK};
class Automata {
private:
    double cash;
    std::string menu[4];
    double prices[4];
    STATES state;
public:
    Automata();
    void on();
    void off();
    void coin();
    void getMenu();
    STATES getState();
    void choice();
    bool check(int index);
    void cancel();
    void cook(int index);
    void finish();
};
#endif
