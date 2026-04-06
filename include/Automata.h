// Copyright 2022 UNN-IASR
#ifndef AUTOMATA_H_
#define AUTOMATA_H_
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
#endif // INCLUDE_AUTOMATA_H_
