/*
 * Created by Sagi Wilentzik on 15/02/2022.
 */

#include <iostream>

using namespace std;

class Pizza {

private:
    std::string description;
    double cost;

public:
    virtual double getCost() = 0;

    virtual std::string getDescription() = 0;

    Pizza() {
        this->description = "";
        this->cost = 0;
    }
};

class PlainPizza : public Pizza {
public:
    double getCost() {
        const double price = 4.00;
        std::cout << "Cost of Dough: " << price << std::endl;
        return price;
    };

    std::string getDescription() {
        return "Thin though";
    };
};

class ToppingDecorator : public Pizza {

protected:
    Pizza *tempPizza;
public:
    ToppingDecorator(Pizza *new_pizza) : tempPizza(new_pizza) {}

    virtual double getCost() {
        return this->tempPizza->getCost();
    }

    virtual std::string getDescription() {
        return this->tempPizza->getDescription();
    }
};

class TomatoSauce : public ToppingDecorator {
public:
    TomatoSauce(Pizza *new_pizza) : ToppingDecorator(new_pizza) {
        std::cout << "adding tomato sauce " << std::endl;
    }

    double getCost() override {
        const double price = 1.5;
        std::cout << "Cost of Tomato sauce: " << price << std::endl;
        return tempPizza->getCost() + price;
    }

    std::string getDescription() override {
        return tempPizza->getDescription() + ",Tomato sauce";
    }
};


class Mozzarella : public ToppingDecorator {
public:
    Mozzarella(Pizza *new_pizza) : ToppingDecorator(new_pizza) {
        std::cout << "adding Mozzarella " << std::endl;
    }

    double getCost() override {
        const double price = 0.75;
        std::cout << "Cost of Mozzarella: " << price << std::endl;
        return tempPizza->getCost() + price;
    }

    std::string getDescription() override {
        return tempPizza->getDescription() + ",Mozzarella";
    }
};


class Onions : public ToppingDecorator {

public:
    Onions(Pizza *new_pizza) : ToppingDecorator(new_pizza) {
        std::cout << "adding onions" << std::endl;
    }

    double getCost() {
        const double price = 0.5;
        std::cout << "Cost of Tomato sauce: " << price << std::endl;
        return tempPizza->getCost() + price;
    }

    std::string getDescription() {
        return tempPizza->getDescription() + ",Onions";
    };
};


int main() {
    std::cout << "Pizza 1 - Start" << std::endl;
    Pizza *p = new Mozzarella(new TomatoSauce(new PlainPizza()));
    std::cout << "Ingredients: " << p->getDescription() << std::endl;
    double total_cost = p->getCost();
    std::cout << "Total cost for pizza 1: " << total_cost << std::endl;
    std::cout << "Pizza 1 - End \n" << std::endl;


    std::cout << "Pizza 2 - Start" << std::endl;
    Pizza *p2 = new Onions(new Mozzarella(new TomatoSauce(new PlainPizza())));
    std::cout << "Ingredients: " << p2->getDescription() << std::endl;
    double total_cost2 = p2->getCost();
    std::cout << "Total cost for pizza 2: " << total_cost2 << std::endl;
    std::cout << "Pizza 2 - End " << std::endl;
    return 1;
}