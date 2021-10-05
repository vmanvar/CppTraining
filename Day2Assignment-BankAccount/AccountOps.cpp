#include "AccountClass.h"

static int gAccountNum = 0;

int Account::GetNewAccountNumber() {
    return ++gAccountNum;
}

void Account::ShowAccount() {
    cout << "Name        : " << this->Name << std::endl
         << "AccNo       : " << this->AccNo << std::endl
         << "Balance     : " << this->Balance << std::endl
         << "InterestRate: " << this->InterestRate << std::endl;
}

int Account::Deposit(double amount) {
    if(amount <= 0) {
        return ERR_INVALID_AMOUNT;
    } else if ((this->Balance + amount) < this->Balance) {
        return ERR_DEPOSIT_LIMIT;
    } else {
        this->Balance += amount;
        return SUCCESS;
    }
}

int Account::Withdraw(double amount, char* Pass) {
    if(strncmp(this->Password, Pass, sizeof(this->Password))) {
        return ERR_INVALID_PASSWORD;
    } else if(amount <= 0) {
        return ERR_INVALID_AMOUNT;
    } else if((this->Balance - amount) < 0) {
        return ERR_WITHDRAW_LIMIT;
    } else {
        this->Balance -= amount;
        return SUCCESS;
    }
}

int Account::ChangeName(char* NewName) {
    char* OldFirstName;
    char* OldLastName;
    char* NewFirstName;
    char* NewLastName;
    
    if(strnlen(NewName, sizeof(this->Name)) == sizeof(this->Name)) {
        return ERR_INVALID_NAME;
    }
    OldFirstName = strtok(this->Name, " ");
    OldLastName = strtok(NULL, " ");

    NewFirstName = strtok(NewName, " ");
    NewLastName = strtok(NULL, " ");

    if((OldLastName == NULL) || 
        (!strcmp(OldLastName, NewLastName))) {
        strncpy(this->Name, NewName, sizeof(this->Name)-1);
        this->Name[sizeof(this->Name)-1] = '\0';
        return SUCCESS;
    } else {
        return ERR_LAST_NAME_MISMATCH;
    }
}

int Account::ChangePass(char* OldPass, char* NewPass) {
    if(strnlen(OldPass, sizeof(this->Password)) == sizeof(this->Password)) {
        return ERR_INVALID_PASSWORD;
    } else if (strcmp(this->Password, OldPass)) {
        return ERR_INVALID_PASSWORD;
    } else if (strnlen(NewPass, sizeof(this->Password)) == sizeof(this->Password)) {
        return ERR_PASSWORD_TOO_LONG;
    } else {
        strcpy(this->Password, NewPass);
        return SUCCESS;
    }
}

int Account::ChangeInterestRate(double NewRate) {
    if(NewRate <= 0) {
        return ERR_INVALID_RATE;
    } else if(this->InterestRate > NewRate) {
        if((this->InterestRate - NewRate) > (this->InterestRate/10)) {
            return ERR_RATE_CHANGE_NOT_ALLOWED;
        } else {
            this->InterestRate = NewRate;
            return SUCCESS;
        }
    } else if(this->InterestRate < NewRate) {
        if((NewRate - this->InterestRate) > (this->InterestRate/10)) {
            return ERR_RATE_CHANGE_NOT_ALLOWED;
        } else {
            this->InterestRate = NewRate;
            return SUCCESS;
        }
    } else {
        return SUCCESS;
    }
}

void Account::CreditInterest() {
    this->Balance += (this->Balance * this->InterestRate/1200);
}