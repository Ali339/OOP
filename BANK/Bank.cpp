//BANK CLASS IMPLEMENTATION
//ALI ZAIB

#include <iostream>
#include <string>
#include <fstream>
#include "Bank.h"


using namespace std;

//SETTERS

/* Bank member function setAccount():
 * Input:
 *  baccount - Account object to be set
 * Process:
 *  sets the member variable account[num_acct] = baccount
 * Output:
 *  account[num_acct] data members are set
 *  increments num_acct
 */

void Bank:: setAccount (Account baccount)
{
   account[num_acct] = new Account (baccount);
   num_acct++;
   return;
}

/* Bank member function setNum_acct():
 * Input:
 *  num - number of accounts
 * Process:
 *  sets the member variable num_acct
 * Output:
 *  Updates the number of accounts in database after transactions
 */

void Bank::setNum_account(int num)
{
    num_acct = num ;
    return;
}

//GETTERS

/* Bank member function getNum_acct():
 * Input:
 *  none
 * Process:
 *  retrieves data member num_acct
 * Output:
 *  returns value of data member num_acct
 */

int Bank::getNum_acct () const
{
    return num_acct ;
}

/* Bank member function getAccount():
 * Input:
 *  index - index of account to be retrieved
 * Process:
 *  retrieves data member account[index]
 * Output:
 *  returns data member account[index]
 */

Account* Bank::getAccount(int index) const

{
    return account [index];
}

//Other member functions
/*
 *findacct():
 *Input:
 * requested_account- Account number entered by the user
 *Process:
 * A linear search of the requested_account in the bank database
 *Output:
 * If account number exists, it finds that and returns its index in
 * otherwise returns -1
 */

int Bank::findAccount (int requested_account)const
{
    for (int count = 0 ; count < num_acct ; count++)
        if (account[count]->getAcct_num() == requested_account)
        {
            return count ;
        }
        return -1 ;
}

/*
 *findSSN():
 *Input:
  * customerSSN- SSN entered by the user
 *Process:
 * A linear search of the entered SSN in the bank database
 *Output:
 * If SSN exists, it finds that and returns its index
 * otherwise returns -1
 */
int Bank::findSSN (string requested_SSN)const
{
    Depositor depositor ;
    for (int count = 0 ; count < num_acct ; count++)
    {
        depositor = account[count]->getDepositor();
        if (depositor.getSocsecnum()== requested_SSN)
            return count ;

    }
    return -1 ;
}


bool Bank::openAccount (int acct)
{
    int index;
    index = findAccount(acct);
    if (index == -1)
    return true;
    return false;
}
void Bank::deleteAccount (int index)
{
    getAccount(index);
    account [index] = account[getNum_acct()-1];
    num_acct--;


    return;
}
