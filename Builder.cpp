/*
 * Created by Sagi Wilentzik on 15/02/2022.
 */

#include <iostream>

using namespace std;

class Pizza {
    friend class PizzaBuilder;
    const bool extraCheese;
    const bool tomatoes;
    const bool olives;
    const bool pineapple;
    Pizza(bool extra_cheese, bool tomatoes1, bool olives1, bool pineapple1): extraCheese(extra_cheese), olives(olives1), pineapple(pineapple1), tomatoes(tomatoes1) {}

public:
    void print() const {
        cout << "Pizza states:" << endl;
        cout << "\tExtra Cheese: " << (extraCheese ? "+" : "-") << endl;
        cout << "\tTomatoes: " << (tomatoes ? "+" : "-") << endl;
        cout << "\tOlives: " << (olives ? "+" : "-") << endl;
        cout << "\tPineapple: " << (pineapple ? "+" : "-") << endl;
    }
};

class PizzaBuilder {
    bool extraCheese;
    bool tomatoes;
    bool olives;
    bool pineapple;
public:
    PizzaBuilder(){
        extraCheese = false;
        tomatoes = false;
        olives = false;
        pineapple = false;
    }
    PizzaBuilder AddCheese() {
        extraCheese = true;
        return *this;
    }
    PizzaBuilder AddTomatoes() {
        tomatoes = true;
        return *this;
    }
    PizzaBuilder AddOlives() {
        olives = true;
        return *this;
    }
    PizzaBuilder AddPineapple() {
        pineapple = true;
        return *this;
    }

    Pizza* build() const {
        return new Pizza(extraCheese, tomatoes, olives, pineapple);
    }
};


int main() {
    PizzaBuilder pizzaBuilder;
    Pizza p = *(pizzaBuilder.AddCheese().AddOlives().AddPineapple().build());
    p.print();
    Pizza* p2 = pizzaBuilder.AddCheese().AddOlives().AddPineapple().build();
    p2->print();
    return 0;
}