//BANK CLASS SPECIFICATION
//ALI ZAIB

#ifndef BANK_H
#define BANK_H
#include <iostream>
#include <string>
#include "Account.h"
//Declaring constant
const int MAX_NUM_ACCT = 50;

using namespace std;

class Bank
{

    Account* account [MAX_NUM_ACCT];
    int num_acct ;

    public:

    /* Bank default constructor:
     * Input:
     *  none
     * Process:
     *  sets object's data members to default values
     * Output:
     *  object's data members are set
     */
    Bank ()
    {
        num_acct = 0 ;
    }

    //Destructor
    ~Bank()
    {
        while (num_acct > 0)
        {
            num_acct--;
            delete account[num_acct] ;
            account [num_acct] = NULL ;

        }
    }
    //SETTERS

    void setAccount (Account baccount);
    void setNum_account (int num);

    //GETTERS

    Account* getAccount (int index) const ;
    int getNum_acct () const;

    //Other member functions

    int findAccount (int requested_account)const ;
    int findSSN (string requested_SSN)const ;
    bool openAccount (int acct);
    void deleteAccount (int acct);

};
#endif
