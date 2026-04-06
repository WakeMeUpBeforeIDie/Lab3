#ifndef AUTOMATA_H
#define AUTOMATA_H
#include <string>
enum STATES = {OFF, WAIT, ACCEPT, CHECK, COOK};
class Automata {
private:
double cash;
std::string[] menu = ["coffee", "black tea", "green tea", "cola"];
double[] prices = [35.75, 20.34, 20.22, 134.47];
STATES state;
public:
Automata();
void on();
void off();
void coin();
void getMenu();
STATES getState();
void choice();
bool check();
void cancel();
void cook();
void finish();
}
#endif
