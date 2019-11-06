//ACCOUNT CLASS SPECIFICATION
//ALI ZAIB

#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include "Depositor.h"
#include "Transaction.h"
using namespace std;
const int MAX_NUM_TRANS = 100 ;

class Account
{
    Depositor depositor ;
    int acct_num ;
    string acct_type ;
    double balance ;
    string status ;
    Transaction transaction [MAX_NUM_TRANS] ;
    int num_trans   ;

    public:

    //SETTERS

    void setDepositor (Depositor d_depositor) ;
    void setAcct_num (int a_acct_num) ;
    void setAcct_type (string a_acct_type) ;
    void setBalance (double a_balance) ;
    void setStatus (string a_status);
    void addTrans (Transaction trans);
    void setNumTrans (int _num_trans);


    //GETTERS
    int getNumtrans () const;
    Transaction getTrans (int index) const ;
    Depositor getDepositor () const;
    int getAcct_num () const ;
    string getAcct_type () const ;
    double getBalance () const ;
    string getStatus () const ;

    void  makeDeposit (double depositing);
    void makeWithdrawal (double withdrawal);




    //CONSTRUCTORS

   /* Account default constructor:
    * Input:
    *  none
    * Process:
    *  sets object's data members to default values
    * Output:
    *  object's data members are set
    */
    Account ()
    {
        acct_num = 0;
        acct_type = "" ;
        balance = 0.0 ;
        status = "";




    }
   /* Account constructor 2 - accepts 4 arguments:
    * Input:
    *  ini_depositor - depositor's info  i.e name & SSN
    *  ini_acct_num - Account holder's account number
    *  ini_acct_type - Account holder's account type
    *  ini_acct_balance - Account holder's balance
    * Process:
    *  sets the member variable depositor = a_depositor
    *  sets the member variable acct_num = ini_acct_num
    *  sets the member variable acct_type = ini_acct_type
    *  sets the member variable balance = ini_balance
    * Output:
    *  object's data members are set
    */
    Account
    (Depositor ini_depositor,int ini_acct_num,string ini_acct_type,
        double ini_balance,string ini_status,int ini_numtrans,
        Transaction ini_trans)
    {
        depositor = ini_depositor ;
        acct_num = ini_acct_num ;
        acct_type = ini_acct_type ;
        balance = ini_balance ;
        status = ini_status ;
        num_trans = ini_numtrans ;
        transaction[num_trans] = ini_trans ;
        num_trans ++ ;

    }

};
#endif
