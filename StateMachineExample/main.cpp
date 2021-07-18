#include <iostream>

using namespace std;

//============================================================================

class Machine
{
    class State *current;
public:
    Machine();
    void setCurrent(State *s) { current = s; }
    void on();
    void off();
};

//============================================================================

class State {
public:
    virtual void on(Machine *m) { cout << "ON not changed\n"; }
    virtual void off(Machine *m) { cout << "OFF not changed\n"; }
    virtual ~State(){}
};

//============================================================================

void Machine::on() {
    current->on(this);
}

void Machine::off() {
    current->off(this);
}

//============================================================================
class ON: public State {
public:
    ON() { cout << "constructor ON "; }
    ~ON() { cout << "destructor ON\n"; }
    void off(Machine *m);
};
//============================================================================
class OFF: public State {
public:
    OFF() { cout << "constructor OFF "; }
    ~OFF() { cout << "destructor OFF\n"; }
    void on(Machine *m);
};
//============================================================================

void ON::off(Machine *m) {
    cout << " going from ON to ";
    m->setCurrent(new OFF());
    delete this;
}

void OFF::on(Machine *m) {
   cout << " going from OFF to ";
   m->setCurrent(new ON());
   delete this;
}

//============================================================================

Machine::Machine()
{
    current = new OFF();
    cout << '\n';
}

//============================================================================

int main()
{
    void(Machine:: *ptrs[])() = { &Machine::off, &Machine::on };

    Machine fsm;
    int num;
    while (1)
    {
        cout << "Enter 0/1: ";
        cin >> num;
        (fsm.*ptrs[num])();
    }
}
