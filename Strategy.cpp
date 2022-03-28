//
// Created by sagi on 28/03/2022.
//

#include <iostream>

using namespace std;

// creating the interface for Navigation. contain the buildRoute function.
class Navigation {
public:
    virtual void buildRoute() = 0;
};

// Concrete 1
class CarNavigation : public Navigation {
public:
    void buildRoute() override {
        cout << "Algorithm for CarNavigation" << endl;
    }
};

// Concrete 2
class PublicTransportNavigation : public Navigation {
public:
    virtual void buildRoute() override {
        cout << "Algorithm for PublicTransportNavigation" << endl;
    }
};

// Route class.
class Route {
    Navigation *navigation;
public:
    Route(): navigation(nullptr){};
    Route(Navigation *n) : navigation(n) {};

    // The createRoute function will call a different function in runtime depending on the navigation value.
    virtual void createRoute() {
        if (navigation != nullptr) {
            this->navigation->buildRoute();
        } else {
            cout << "Navigation need to be initialized" << endl;
        }

    }

    void setRoute(Navigation* n) {
        delete this->navigation;
        this->navigation = n;
    }

    ~Route(){
        delete this->navigation;
    };
};

int main() {
    Route* r = new Route();
    r->createRoute();
    r->setRoute(new CarNavigation);
    r->createRoute();
    r->setRoute(new PublicTransportNavigation);
    r->createRoute();
    delete r;
}