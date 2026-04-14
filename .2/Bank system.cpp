#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    BankAccount() {
        balance = 0;
    }

    
    void deposit(double amount) {
        balance += amount;
        cout << "Deposited successfully!\n";
    }


    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdraw successful!\n";
        } else {
            cout << "Error: Not enough balance!\n";
        }
    }

    
    void showBalance() {
        cout << "Current balance = " << balance << endl;
    }
};

int main() {

    BankAccount account;
    int choice;
    double amount;

    do {
        cout << "\n===== BANK MENU =====\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Show Balance\n";
        cout << "4. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                cout << "Enter amount: ";
                cin >> amount;
                account.deposit(amount);
                break;

            case 2:
                cout << "Enter amount: ";
                cin >> amount;
                account.withdraw(amount);
                break;

            case 3:
                account.showBalance();
                break;

            case 4:
                cout << "Goodbye!\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 4);

    return 0;
}