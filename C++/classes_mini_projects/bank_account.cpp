#include <iostream>
using namespace std;

class AccountHolder {
    int account;
    int balance = 0;
    static int no_of_account_holders;

    public: 
        string account_holder_name;
        void createAccount(string account_holder_name, int account_number, int intial_deposit);
        void deposit(int amount_to_deposit);
        void withdraw(int amount_to_withdraw);
        void displayDetails();
        void displayBalance();
        static void displayNoOfAccountHolders();
};

int AccountHolder::no_of_account_holders; // by default 0

void AccountHolder::createAccount(string account_holder_name, int account_number, int initial_deposit) {
    account_holder_name = account_holder_name;
    account = account_number;
    balance += initial_deposit; 
    no_of_account_holders++;
}

void AccountHolder::deposit(int amount_to_deposit){
    balance += amount_to_deposit;
}

void AccountHolder::withdraw(int amount_to_withdraw){
    balance -= amount_to_withdraw;
}

void AccountHolder::displayDetails(){
    cout << "Name of Account Holder: " << account_holder_name << endl;
    cout << "Account Number: " << account << endl;
    cout << "Balance: " << balance << endl;
}

void AccountHolder::displayBalance(){
    cout << "Net balance of Acoount Number - " << account << " : " << balance << endl;
}

void AccountHolder::displayNoOfAccountHolders(){
    cout << "Total no of account holders: " << no_of_account_holders << endl;
}

int main() {
    
    AccountHolder A1, A2, A3;

    A1.createAccount("Suraj Shukla", 1000, 100 );
    A1.displayBalance();
    A1.deposit(400);
    A1.displayBalance();
    A1.withdraw(200);
    A1.displayBalance();

    A2.createAccount("Shubham Shukla", 1001, 1400 );
    A2.displayBalance();
    A2.deposit(400);
    A2.displayBalance();
    A2.withdraw(200);
    A2.displayBalance();

    A3.createAccount("Manish", 1003, 1400 );

    AccountHolder::displayNoOfAccountHolders();
    return 0;
}