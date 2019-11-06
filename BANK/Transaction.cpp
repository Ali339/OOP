//TRANSACTION CLASS IMPLEMENTATION
//ALI ZAIB

#include <iostream>
#include <string>
#include <fstream>
#include "Transaction.h"
using namespace std;
void Transaction:: setTransType (string _trans_type)
{
    _trans_type = trans_type;
}
void Transaction::setTransAmount (double _trans_amount)
{
    trans_amount = _trans_amount ;
}
string Transaction::getTransType () const
{
    return trans_type ;
}
double Transaction::getTransAmount() const
{
    return trans_amount;
}

