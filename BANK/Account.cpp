//ACCOUNT CLASS IMPLEMENTATION
//ALI ZAIB

#include <iostream>
#include <string>
#include <fstream>
#include "Account.h"
using namespace std;


//SETTERS

/* Account member function setDepositor():
 * Input:
 *  a_depositor - depositor's information containing name and SSN
 * Process:
 *  sets the value of member variable depositor
 * Output:
 *  none
 */

void Account::setDepositor (Depositor a_depositor)
{
    depositor = a_depositor ;
    return ;
}

/* Account member function setAcct_num():
 * Input:
 *  a_acct_num - object's account number
 * Process:
 *  sets the value of member variable acct_num
 * Output:
 *  none
 */

void Account::setAcct_num (int a_acct_num)
{
    acct_num = a_acct_num ;
    return ;
}
/* Account member function setAcct_type():
 * Input:
 *  a_acct_type - object's account type
 * Process:
 *  sets the value of member variable acct_type
 * Output:
 *  none
 */

void Account::setAcct_type (string a_acct_type)
{
    acct_type = a_acct_type ;
    return ;
}

/* Account member function setBalance():
 * Input:
 *  a_acct_num - object's account balance
 * Process:
 *  sets the value of member variable balance
 * Output:
 *  none
 */

void Account::setBalance (double a_balance)
{
    balance = a_balance ;
    return ;
}
void Account::setStatus (string a_status)
{
    status = a_status ;
    return ;
}

//GETTERS

/* Account member function getDepositor():
 * Input:
 *  none
 * Process:
 *  retrieves the value of member variable depositor
 * Output:
 *  returns the object's depositor (Account holders info i.e name & SSN)
 */

Depositor Account::getDepositor () const
{
    return depositor ;

}

/* Account member function getAcct_num():
 * Input:
 *  none
 * Process:
 *  retrieves the value of member variable acct_num
 * Output:
 *  returns the object's acct_num
 */

int Account::getAcct_num () const
{
    return acct_num ;
}

/* Account member function getAcct_type():
 * Input:
 *  none
 * Process:
 *  retrieves the value of member variable acct_type
 * Output:
 *  returns the object's acct_type
 */

string Account::getAcct_type () const
{
    return acct_type ;
}
/* Account member function getBalance():
 * Input:
 *  none
 * Process:
 *  retrieves the value of member variable balance
 * Output:
 *  returns the object's balance
 */

double Account::getBalance () const
{
    return balance ;
}
string Account::getStatus () const
{
    return status ;
}
int Account:: getNumtrans ()const
{
    return num_trans ;
}
Transaction Account:: getTrans (int index) const
{
    return transaction[index];
}
void Account:: makeDeposit ( double depositing)
{
    balance = balance + depositing ;
    return ;
}
void Account:: makeWithdrawal ( double withdrawal)
{
    balance = balance - withdrawal;
    return;
}
void Account :: setNumTrans (int _num_trans)
{
    num_trans = _num_trans;
}
void Account:: addTrans (Transaction trans)
{
    transaction[num_trans] = trans;
    num_trans++;
    return;
}
