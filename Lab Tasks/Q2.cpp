#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    string AccountNumber;
    string AccountHolderName;
    double Balance;

public:
    Account(string AccNumber, string AccHolder) : AccountNumber(AccNumber), AccountHolderName(AccHolder), Balance(0.0) {}

    void Deposit(double Amount) {
        Balance += Amount;
        cout << "Deposited: $" << Amount << endl;
    }

    virtual void Withdraw(double Amount) {
        if (Amount <= Balance) {
            Balance -= Amount;
            cout << "Withdrew: $" << Amount << endl;
        } else {
            cout << "Insufficient Balance!!" << endl;
        }
    }

    void CheckBalance() const {
        cout << "Account Balance: $" << Balance << endl;
    }
};

class SavingsAccount : public Account {
    private:
        double InterestRate; 

    public:
        SavingsAccount(string AccNumber, string AccHolder, double intRate) : Account(AccNumber, AccHolder), InterestRate(intRate) {}

        void CalculateInterest() {
            double interest = Balance * (InterestRate / 100);
            cout << "Interest Earned: $" << interest << endl;
            Deposit(interest);  
        }
};

class CurrentAccount : public Account {
    private:
        double OverdraftLimit;  

    public:
        CurrentAccount(string AccNumber, string AccHolder, double overdraftLimit) : Account(AccNumber, AccHolder), OverdraftLimit(overdraftLimit) {}

        void Withdraw(double Amount) override {
            if (Amount <= Balance + OverdraftLimit) {
                Balance -= Amount;
                cout << "Withdrew: $" << Amount << endl;
            } else {
                cout << "Overdraft Limit Exceeded!!" << endl;
            }
        }
};

int main() {
    SavingsAccount savings("123456", "Fawad Khan", 5.0);

    CurrentAccount current("678974", "Emma Watson", 500.0);

    savings.Deposit(2000.0);
    savings.Withdraw(550.0);
    savings.CalculateInterest();  

    current.Deposit(600.0);
    current.Withdraw(50.0);
    current.Withdraw(300.0);  

    savings.CheckBalance();
    current.CheckBalance();

    return 0;
}