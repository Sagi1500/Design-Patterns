/*
 * Created by Sagi Wilentzik on 15/02/2022.
 */

#ifndef PROXYEXAMPLE_PROXY_H
#define PROXYEXAMPLE_PROXY_H


#include <iostream>

using namespace std;
class Account {
public:
    string name;
    int id;
    Account(string name1, int id1): name(name1), id(id1){};
    virtual void showAccountHolderName()=0;
    virtual void showAccountHolderPassword()=0;
    virtual void showAccountHolderId()=0;
    virtual ~Account() {
        delete name;
        delete id;
    }

};

class UserAccount: public Account {
    string password;
public:
    UserAccount(string name1, int id1, string passwords1): Account(name1,id1), password(passwords1){};
    void showAccountHolderName() override {
        std::cout << "Your name is: " << this->name << endl;
    }
    void showAccountHolderPassword() override{
        std::cout << "Your password is: " << this->password << endl;
    }
    void showAccountHolderId() override{
        std::cout << "Your id is: " << this->id << endl;
    }

};

class AccountProxy: public Account {
private:
    Account* account;
public:
    AccountProxy(Account* account1): Account(account1->name, account1->id), account(account1){};
    void showAccountHolderName() override {
        std::cout << "Name of account holder is: " << account->name << endl;
    }
    void showAccountHolderId() override{
        std::cout << "Id of account holder is: " << account->id << endl;
    }
    void showAccountHolderPassword() override{
        std::cout << "You cant see other users password! "<< endl;
    }
};

int main() {
    Account* Sagi = new UserAccount("Sagi",1234, "1206");
    Sagi->showAccountHolderName();
    Sagi->showAccountHolderId();
    Sagi->showAccountHolderPassword();

    Account* account = new AccountProxy(Sagi);
    account->showAccountHolderName();
    account->showAccountHolderId();
    account->showAccountHolderPassword();

    delete Sagi;
    delete account;
}