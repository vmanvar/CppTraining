#pragma once
#include <iostream>
#include <string.h>
using namespace std;

#define MAX_NAME_LEN 100
#define MAX_PASS_LEN 100
#define DEFAULT_INTEREST_RATE 10

#define SUCCESS                 0
#define ERR_INVALID_AMOUNT      -1
#define ERR_DEPOSIT_LIMIT       -2
#define ERR_INVALID_PASSWORD    -3
#define ERR_WITHDRAW_LIMIT      -4
#define ERR_INVALID_NAME        -5
#define ERR_LAST_NAME_MISMATCH  -6
#define ERR_PASSWORD_TOO_LONG   -7
#define ERR_INVALID_RATE        -8
#define ERR_RATE_CHANGE_NOT_ALLOWED -9

class Account {
    private:
        char Name[MAX_NAME_LEN];
        char Password[MAX_PASS_LEN];
        int  AccNo;
        double Balance;
        double InterestRate;

        int GetNewAccountNumber();
        bool IsValidName(char* Name) {
            if(Name == NULL) {
                cout << "Enter valid Name.\n";
                return false;
            } else {
                return true;
            }
        }
        bool IsValidPassword(char* Pass) {
            if(Pass == NULL) {
                cout << "Enter valid Password.\n";
                return false;
            } else if (!strncmp(Name, Pass, sizeof(Name))) {
                cout << "Name and Password can't be same.\n";
                return false;
            } else {
                return true;
            }
        }
    public:
        void ShowAccount();
        bool IsNameAssigned() {
            return (Name[0] != '\0');
        }
        bool IsPassAssigned() {
            return (Password[0] != '\0');
        }

        int ChangeName(char* NewName);
        int ChangePass(char* OldPass, char* NewPass);
        int Deposit(double amount);
        int Withdraw(double amount, char* Pass);
        int ChangeInterestRate(double NewRate);
        void CreditInterest();

        Account(char* Name, char* Password) {
            if(IsValidName(Name)) {
                strncpy(this->Name, Name, sizeof(this->Name)-1);
                this->Name[sizeof(this->Name)-1] = '\0';
            } else {
                this->Name[0] = '\0';
                return;
            }

            if(IsValidPassword(Password)) {
                strncpy(this->Password, Password, sizeof(this->Password)-1);
                this->Password[sizeof(this->Password)-1] = '\0';
            } else {
                this->Password[0] = '\0';
                return;
            }

            this->AccNo = GetNewAccountNumber();
            this->Balance = 0;
            this->InterestRate = DEFAULT_INTEREST_RATE;
        }
};