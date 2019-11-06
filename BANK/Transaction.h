#ifndef TRANSACTION_H
#define TRANSACTION_H
#include<string>
using namespace std ;
class Transaction
{
    string trans_type ;
    double trans_amount ;
public:
    Transaction()
    {
        trans_type = "";
        trans_amount = 0.0 ;
    }
    Transaction(string _trans_type , double _trans_amount  )
    {
        trans_type = _trans_type  ;
        trans_amount = _trans_amount  ;
    }
    void setTransType (string _trans_type);
    void setTransAmount (double _trans_amount);
    string getTransType ()const;
    double getTransAmount()const;
};

#endif
