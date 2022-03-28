//
// Created by sagi on 28/03/2022.
//

#include <iostream>

using namespace std;

// creating the state interface.
class State {
public:
    virtual void action()=0;
};

// Concrete state 1 - Employee is working
class InWork : public State {
public:
    virtual void action() {
        cout << "working!" << endl;
    }

    ~InWork();
};

// Concrete state 2 - Employee finish work and ready to go home.
class FinishWork : public State {
public:
    virtual void action() {
        cout << "go home!" << endl;
    }

    ~FinishWork();
};

// Employee class - contain a member of state.
class Employee {
    string name;
    State *s;

public:
     Employee(string name, State *s) : name(name), s(s) {};

    ~Employee(){
        delete this->s;
    };

    // Setter for the state.
    void setState(State *state) {
        delete this->s;
        this->s = state;
    }

    // The action function in Employee will call a different function in runtime depending on the state value.
    void action() {
        s->action();
    }
};

int main() {
    Employee *e = new Employee("Sagi", new InWork);
    e->action();
    e->setState(new FinishWork);
    e->action();
    delete e;


}

