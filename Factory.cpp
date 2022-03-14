/*
 * Created by Sagi Wilentzik on 15/02/2022.
 */

#include <iostream>
#include <iterator>
#include <map>

class Ball {
protected:
    double price;

    Ball(double price1) {
        this->price = price1;
    }

public:
    virtual double getPrice() {
        return this->price;
    }
};

class SoccerBall : public Ball {
public:
    SoccerBall(double price1) : Ball(price1) {
        std::cout << "creating a soccer ball" << std::endl;
    };
};

class BasketBall : public Ball {
public:
    BasketBall(double price1) : Ball(price1) {
        std::cout << "creating a basket ball" << std::endl;
    };
};


class BallFactory {
private:
    std::map<std::string, Ball *> map;
public:
    BallFactory() {
        this->map.insert({"soccerball", new SoccerBall(10.0)});
        this->map.insert({"basketball", new BasketBall(20.0)});
    }

    Ball *create(const std::string &key) {
        if (map.find(key) != map.end()) {
            return map.at(key);
        }
        return nullptr;
    }
};

int main() {
    BallFactory *ballFactory = new BallFactory();
    Ball *b1 = ballFactory->create("basketball");
    if (b1) {
        std::cout << "ball price is: " << b1->getPrice() << std::endl;
        delete b1;
    }
    b1 = ballFactory->create("soccerball");
    {
        if (b1) {
            std::cout << "ball price is: " << b1->getPrice() << std::endl;
            delete b1;
        }
    }
    delete ballFactory;
    return 1;
}
