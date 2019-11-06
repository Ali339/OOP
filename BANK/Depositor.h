//DEPOSITOR CLASS SPECIFICATION
//ALI ZAIB

#ifndef DEPOSITOR_H
#define DEPOSITOR_H
#include <string>
#include "Name.h"
using namespace std;

class Depositor
{
   Name name ;
   string socsecnum ;


   public:

   //SETTERS
   void setName (Name d_name) ;
   void setSocsecnum (string d_socsecnum) ;

   //GETTERS
   Name getName () const ;
   string getSocsecnum () const ;

   //CONSTRUCTORS

   /* Depositor default constructor:
    * Input:
    *  none
    * Process:
    *  sets object's data members to default values
    * Output:
    *  object's data members are set
    */
   Depositor ()
   {
       socsecnum = "" ;
   }


   /* Depositor constructor 2 - accepts 2 arguments:
    * Input:
    *  ini_name - Account holder's  name
    *  s - Account holder's social security number
    * Process:
    *  sets the member variable name = ini_name
    *  sets the member variable socsecnum = s
    * Output:
    *  object's data members are set
    */
   Depositor (Name ini_name , string s)
   {
        name = ini_name ;
        socsecnum = s ;
   }

};

#endif
