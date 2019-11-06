#ifndef TRANSACTIONINPUTFORM_H
#define TRANSACTIONINPUTFORM_H
#include <string>

class TransactionInputForm
{
    int Acct ;
    string ssn ;
    double depositing_withdrawing ;
    string first ;
    string last ;
    string type ;
    double bal ;
    string status ;
public:


    TransactionInputForm()
    {
        Acct = 0 ;
        ssn = "";
        depositing_withdrawing = 0.0 ;
        first = "";
        last = "";
        type = "";
        bal = 0.0 ;
        status = "";

    }
    TransactionInputForm(int _acct)
    {
        Acct = _acct;
    }
    TransactionInputForm(string _ssn)
    {
        ssn = _ssn ;
    }
    TransactionInputForm(int _acct, double adouble)
    {
        Acct = _acct ;
        depositing_withdrawing = adouble ;

    }

    TransactionInputForm(int _acct,string _last,string _first,string _ssn,
        string _type,double _bal,string _status)
    {
        Acct = _acct ;
        last = _last ;
        first = _first ;
        ssn = _ssn ;
        type = _type ;
        bal = _bal ;
        status = _status;
    }

};
#endif
