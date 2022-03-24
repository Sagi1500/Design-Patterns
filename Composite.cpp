/*
 * Created by Sagi Wilentzik on 15/02/2022.
 */

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class Employee {

public:
    virtual void print() {
        cout << "Employee" << endl;
    }

    virtual ~Employee() {};
};

class Engineer : public Employee {
public:
    virtual void print() {
        cout << "Engineer" << endl;
    }
};

list<Employee *> hasAManager;

class Manager : public Employee {
    list<Employee *> employeesList;
public:
    virtual void print() {
        cout << "Manager" << endl;
        cout << "My team includes: " << endl;
        for_each(employeesList.begin(), employeesList.end(), [](Employee *e) {
            e->print();
        });
    }

    bool addEmployee(Employee *e) {
        if (find(e) || findMe(e)) {
            return false;
        }
        employeesList.push_back(e);
        hasAManager.push_back(e);
    }

    virtual ~Manager() {
        for_each(employeesList.begin(), employeesList.end(), [](Employee *e) { delete e; });
    }

private:
    // find if the employee has a manager.
    bool find(Employee *e) {
        list<Employee *>::iterator it = hasAManager.begin();
        while (it != hasAManager.end()) {
            if (e == *it) {
                return true;
            }
            it++;
        }
        return false;
    }

    // find if there is a collision in the tree.
    bool findMe(Employee *e) {
        // same person.
        if (this == e) {
            return true;
        }
        // if not the same person, check the other nodes in the tree.
        Manager *m = dynamic_cast<Manager *>(e);
        if (m) {
            auto it = m->employeesList.begin();
            while (it != m->employeesList.end()) {
                if (findMe(*it)) {
                    return true;
                }
                it++;
            }
        }
        return false;
    }
};

int main() {
    Manager *m0 = new Manager();
    Manager *m1 = new Manager();
    Manager *m2 = new Manager();
    Employee *e0 = new Engineer();
    Employee *e1 = new Engineer();
    Employee *e2 = new Engineer();
    Employee *e3 = new Engineer();
    m0->addEmployee(e0);
    m0->addEmployee(m1);
    m1->addEmployee(e1);
    m1->addEmployee(e2);
    m1->addEmployee(m2);
    m2->addEmployee(e3);
    m1->addEmployee(e0); // should return false
    m2->addEmployee(m0); // should return false
    m1->addEmployee(m1); // should return false
    m0->print();


    delete m0;
    return 0;
}