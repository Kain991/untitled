#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
class Account{
protected:
    string name;
    double balance;
    double dollar;
    double tenge;
    double euro;
public:
    Account(){
        name = "Unnamed Account";
        tenge = 0;
        balance = 0;
        dollar = 0;
        euro = 0;
    }
    string getName(){
        return name;
    };
    double getBalance(){
        return balance;
    }
    double getDollar(){
        return dollar;
    }
    double getEuro(){
        return euro;
    }
    double getTenge(){
        return tenge;
    }
    void setBalance(int valuebalance){
        balance = valuebalance;
    }
    void setDollar(int valdollar){
        dollar = valdollar;
    }
    void setEuro(int valeuro){
         euro = valeuro;
    }
    void setTenge(int valtenge){
        tenge = valtenge;
    }
    void setName(int valname){
        name = valname;
    }
// virtual int deposit(int ) = 0;
public: virtual double depositT(double amount){
        double newBalance = balance + amount;
        balance = newBalance;
    }
public: virtual double depositE(double amount){
        double newBalance = balance + (amount*491);
        balance = newBalance;
    }
public: virtual double depositD(double amount){
        double newBalance = balance + (amount*420);
        balance = newBalance;
    }
    //virtual void withdraw() = 0;
public:
    double withdraw(double amount)
    {
        double newBalance = balance - amount;
        balance = newBalance;
        return newBalance;
    }

    Account( string name1, double tenge1, double euro1, double dollars1, double balance1){
        name1 = name;
        tenge1 = tenge;
        euro1 = euro;
        dollars1= dollar;
        balance1 =balance;
    }

};

class I_Printable {
    void printInterface(){

    }
};

class SavingAccount: public Account{
public:
    int interestRateT= 1;
    int interestRateE= 3;
    int interestRateD= 2;

    double depositT (double amount ) override {

        balance= (1+(interestRateT/100));
        return balance;
    }
    double depositE (double amount ) override {

        balance= (1+(interestRateE/100));
        return balance;
    }
    double depositD (double amount ) override {

        balance= (1+(interestRateD/100));
        return balance;
    }
};

class CheckingAccount: public Account{
public:
    string name;
    double balance;
    double amount2;
    double fee = 0.015;
    void withdraw(){
        Account ::withdraw(amount2*fee);
    }
};

class TrustAccount : public SavingAccount{
public:
    double depositT (double amount ) override {
        if(amount >= 1000){
            amount += 10;
        }
        SavingAccount ::depositT(amount);
    }
    double depositE (double amount ) override {
        if(amount >= 1000){
            amount += 10;
        }
        SavingAccount ::depositE(amount);
    }
    double depositD (double amount ) override {
        if(amount >= 1000){
            amount += 10;
        }
        SavingAccount ::depositD(amount);
    }

    double withdraw(double amount){
        if(amount <= (0.2*balance)){
            SavingAccount ::withdraw(amount);
        }
        else {
            cout<<"You are not allowed to withdraw that amount of money\n";
        }
    }
};


int main() {

    return 0;
}
