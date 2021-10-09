#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
class I_Printable {
public:
    void printInterface(double tenge , double dollar , double euro, string name , double balance){
        cout<<"Owner :"<<name<<endl<<"Balance :"<<balance<<endl<<"Tenge :"<<tenge<<endl<<"Dollar :"<<dollar<<endl<<"Euro :"<<euro<<endl;
    }
};
class Account : public I_Printable{
protected:
    string name;
    double balance;
    double dollar;
    double tenge;
    double euro;
public:
    void PrintInterface(){
        I_Printable :: printInterface(tenge , dollar ,  euro, name , balance);
    }
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



class SavingAccount: public Account{
public:
    int interestRateT= 1;
    int interestRateE= 3;
    int interestRateD= 2;
    SavingAccount() : Account(){

    }
    SavingAccount(string name , double tenge, double euro, double dollar, double balance , int interestRateT ,int interestRateE , int interestRateD) : Account(name , tenge, euro , dollar , balance){
        this->interestRateT = interestRateT;
        this->interestRateE = interestRateE;
        this->interestRateD = interestRateD;
    }

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
    CheckingAccount(string name , double tenge, double euro, double dollar, double balance) : Account(name , tenge, euro , dollar , balance){

    }
};

class TrustAccount : public SavingAccount{
public:
    TrustAccount(): SavingAccount(){}
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
//class Redistribution{
//public:
//    vector <Account> accounts;
//    Redistribution(vector <Account> account){
//        this->accounts = accounts;
//    }
//    void redistribute(double tenge){
//        for(int i =0 ;i < accounts.size() ; i++){
//            accounts[i].depositT(tenge);
//        }
//    }
//};


int main() {

//    Account acc;
//    TrustAccount tru =TrustAccount();
//    Redistribution redistribution =  Redistribution({acc , tru});
//    redistribution.redistribute(150);
//    tru.PrintInterface();
//    acc.PrintInterface();
    return 0;
}
