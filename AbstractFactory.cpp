/*
 * Created by Sagi Wilentzik on 15/02/2022.
 */

#include <iostream>

using namespace std;

class Shirt {
public:
    float price;
};

class ShortShirt : public Shirt {
public:
    ShortShirt() {
        price = 20.0;
    }
};

class LongShirt : public Shirt {
public:
    LongShirt() {
        price = 30.0;
    }
};

class Pants {
public:
    float price;
};

class ShortPans : public Pants {
public:
    ShortPans() {
        price = 25.5;
    }
};

class LongPants : public Pants {
public:
    LongPants() {
        price = 35.0;
    }
};


class AbstractFactory {
public:
    virtual Shirt *createShirt() = 0;

    virtual Pants *createPants() = 0;
};

class ShortFactory : public AbstractFactory {
    Shirt *createShirt() override {
        return new ShortShirt;
    };

    Pants *createPants() override {
        return new ShortPans;
    };
};

class LongFactory : public AbstractFactory {
    Shirt *createShirt() override {
        return new LongShirt;
    };

    Pants *createPants() override {
        return new LongPants;
    };
};

int main() {
    char length;
    AbstractFactory *factory;
    bool x;
    do {
        cout << "Enter long or short ('s' or 'l'): ";
        cin >> length;
        switch (length) {
            case 's':
                cout << "Create short clothes" << endl;
                factory = new ShortFactory();
                x = false;
                break;
            case 'l':
                cout << "Create long clothes" << endl;
                factory = new LongFactory();
                x = false;
                break;
            default:
                x = true;
        }
    } while (x);
    Shirt *shirt = factory->createShirt();
    Pants *pants = factory->createPants();
    cout << "Shirt price: " << shirt->price << endl;
    cout << "Pants price: " << pants->price << endl;
    return 0;
}
