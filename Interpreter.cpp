//
// Created by sagi on 30/03/2022.
//

#include <iostream>

using namespace std;

class Expression {
public:
    virtual string print() = 0;

    virtual double evaluate() = 0;

};

class NonTerminatedExpression : public Expression {
protected:
    Expression *first;
    Expression *second;

    NonTerminatedExpression(Expression *e1, Expression *e2) : first(e1), second(e2) {};
};

class Num : public Expression {
    double num;
public:
    Num(double n) : num(n) {};

    string print() override {
        return to_string(num);
    }

    double evaluate() override {
        return num;
    }
};

class Plus : public NonTerminatedExpression {
public:
    Plus(Expression *e1, Expression *e2) : NonTerminatedExpression(e1, e2) {};

    string print() override {
        return "(" + first->print() + " + " + second->print() + ")";
    }

    double evaluate() {
        return first->evaluate() + second->evaluate();
    }

};

class Minus : public NonTerminatedExpression {
public:
    Minus(Expression *e1, Expression *e2) : NonTerminatedExpression(e1, e2) {};

    string print() override {
        return "(" + first->print() + " - " + second->print() + ")";
    }

    double evaluate() {
        return first->evaluate() - second->evaluate();
    }

};

class Multiplication : public NonTerminatedExpression {
public:
    Multiplication(Expression *e1, Expression *e2) : NonTerminatedExpression(e1, e2) {};

    string print() override {
        return "(" + first->print() + " * " + second->print() + ")";
    }

    double evaluate() {
        return first->evaluate() * second->evaluate();
    }

};

int main() {
    Expression *expression = new Plus((new Minus(new Num(1.5), new Num(5))), new Num(5.5));
    cout << expression->print() << " = " << expression->evaluate() << endl;

    Expression *expression1 = new Multiplication(new Plus((new Minus(new Num(10), new Num(6))), new Num(4)), new Num(2));
    cout << expression1->print() << " = " << expression1->evaluate() << endl;
}


