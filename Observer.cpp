/*
 * Created by Sagi Wilentzik on 15/02/2022.
 */

#include <iostream>
#include <list>

class Observer {
public:
    virtual void update(int num)=0;
};

class TripleDigitsNumber {
public:
    explicit TripleDigitsNumber(const int num) {
        std:: cout << "\nThe number " << num << " is triple digit number\n" << std::endl;
    }
};

class SingleDigitNumber {
public:
    explicit SingleDigitNumber(const int num) {
        std:: cout << "\nThe number " << num << " is single digit number\n" << std::endl;
    }
};

class DefineNumber : public Observer {
public:
    void update(const int num) override {
        if (0 < num && num < 10) {
            new SingleDigitNumber(num);
        } else if (num > 99 && num < 1000) {
            new TripleDigitsNumber(num);
        }
    }
};


class RandNumbers{
private:
    std::list<Observer*> observers;
public:
    void addObserver(Observer* observer1) {
        observers.push_back(observer1);
    }

    void notify(int num) {
        auto it = observers.begin();
        while(it != observers.end()){
            (*it)->update(num);
            it++;
        }
    }

    int randNumber() {
        int res = rand() % 10000;
        std:: cout << res << std::endl;
        this->notify(res);
        return res ;
    }
};

int main() {
    Observer* observer = new DefineNumber();
    RandNumbers* rand_numbers = new RandNumbers();
    rand_numbers->addObserver(observer);
    int temp;
    for(int i = 0 ; i < 50; i++) {
        rand_numbers->randNumber();
    }
}

