#include <iostream>
#include "AccountClass.h"
using namespace std;

void ShowHelp() {
    cout<<"Press 1 to Add Account"<<endl
        <<"Press 2 to Show Account"<<endl
        <<"Press 3 to Change Name"<<endl
        <<"Press 4 to Change Password"<<endl
        <<"Press 5 to Deposit amount"<<endl
        <<"Press 6 to Withdraw amount"<<endl
        <<"Press 7 to Credit monthly interest"<<endl
        <<"Press 8 to Change interest rate"<<endl
        <<"Press 9 to Exit"<<endl<<endl
        <<"Choice: ";
}

void ShowError(int ret) {
    cout << "Error : ";
    switch(ret) {
        case ERR_INVALID_AMOUNT:
            cout << "Invalid amount.\n";
            break;
        case ERR_DEPOSIT_LIMIT:
            cout << "Deposit limit reached.\n";
            break;
        case ERR_INVALID_PASSWORD:
            cout << "Invalid Password.\n";
            break;
        case ERR_WITHDRAW_LIMIT:
            cout << "Withdraw limit reached.\n";
            break;
        case ERR_INVALID_NAME:
            cout << "Invalid Name.\n";
            break;
        case ERR_LAST_NAME_MISMATCH:
            cout << "Last name must match when changing name.\n";
            break;
        case ERR_PASSWORD_TOO_LONG:
            cout << "Password too long.\n";
            break;
        case ERR_INVALID_RATE:
            cout << "Invalid rate of interest.\n";
            break;
        case ERR_RATE_CHANGE_NOT_ALLOWED:
            cout << "Rate change not allowed with specified rate. Should be within +/- 10%\n";
            break;
        default:
            cout << "Unknown error.\n";
            break;
    }
}

int main() {
    bool exit = false;
    int choice;
    int ret;
    char Name[MAX_NAME_LEN];
    char OldPass[MAX_PASS_LEN];
    char NewPass[MAX_PASS_LEN];
    Account *acc = NULL;
    double amount;
    double rate;

    while(exit == false) {
        ShowHelp();
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Name : ";
                cin.getline(Name, sizeof(Name));        // Virat: Hack
                cin.getline(Name, sizeof(Name));
                cout << "Password : ";
                cin.getline(NewPass, sizeof(NewPass));
                acc = new Account(Name, NewPass);
                if(!acc->IsNameAssigned() || 
                    !acc->IsPassAssigned()) {
                    delete acc;
                    acc = NULL;
                }
                break;
            case 2:
                if(acc == NULL) {
                    cout << "Please add accout.\n\n";
                } else {
                    acc->ShowAccount();
                }
                break;
            case 3:
                if(acc == NULL) {
                    cout << "Please add accout.\n\n";
                } else {
                    cout << "New Name : ";
                    cin.getline(Name, sizeof(Name));        // Virat: Hack
                    cin.getline(Name, sizeof(Name));
                    ret = acc->ChangeName(Name);
                    if(ret) { ShowError(ret); }
                }
                break;
            case 4:
                if(acc == NULL) {
                    cout << "Please add accout.\n\n";
                } else {
                    cout << "Old Password : ";
                    cin.getline(OldPass, sizeof(OldPass));        // Virat: Hack
                    cin.getline(OldPass, sizeof(OldPass));
                    cout << "New Password : ";
                    cin.getline(NewPass, sizeof(NewPass));
                    ret = acc->ChangePass(OldPass, NewPass);
                    if(ret) { ShowError(ret); }
                }
                break;
            case 5:
                if(acc == NULL) {
                    cout << "Please add accout.\n\n";
                } else {
                    cout << "Amount to deposit : ";
                    cin >> amount;
                    ret = acc->Deposit(amount);
                    if(ret) { ShowError(ret); }
                }
                break;
            case 6:
                if(acc == NULL) {
                    cout << "Please add accout.\n\n";
                } else {
                    cout << "Amount to withdraw : ";
                    cin >> amount;
                    cout << "Password : ";
                    cin.getline(OldPass, sizeof(OldPass));      // Virat: Hack
                    cin.getline(OldPass, sizeof(OldPass));
                    ret = acc->Withdraw(amount, OldPass);
                    if(ret) { ShowError(ret); }
                }
                break;
            case 7:
                if(acc == NULL) {
                    cout << "Please add accout.\n\n";
                } else {
                    acc->CreditInterest();
                }
                break;
            case 8:
                if(acc == NULL) {
                    cout << "Please add accout.\n\n";
                } else {
                    cout << "New interest rate : ";
                    cin >> rate;
                    ret = acc->ChangeInterestRate(rate);
                    if(ret) { ShowError(ret); }
                }
                break;
            case 9:
                exit = true;
                break;
            default:
                break;
        }
    }

    delete acc;
    return SUCCESS;
}