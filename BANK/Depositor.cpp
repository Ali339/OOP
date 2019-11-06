//DEPOSITOR CLASS IMPLEMETATION
//ALI ZAIB

#include <iostream>
#include <string>
#include <fstream>
#include "Depositor.h"
using namespace std;

//SETTERS

/* Depositor member function setName():
 * Input:
 *  d_name - object's name
 * Process:
 *  sets the value member variable name
 * Output:
 *  none
 */

void Depositor::setName (Name d_name)
{
    name = d_name ;
    return ;
}

/* Depositor member function setSocsecnum():
 * Input:
 *  d_socsecnum - object's SSN
 * Process:
 *  sets the value member variable socsecnum
 * Output:
 *  none
 */

void Depositor::setSocsecnum (string d_socsecnum)
{
    socsecnum = d_socsecnum ;
    return;
}

//GETTERS

/* Depositor member function getName():
 * Input:
 *  none
 * Process:
 *  retrieves the value of member variable name
 * Output:
 *  returns the object's name
 */

Name Depositor::getName () const
{
    return name ;
}

/* Depositor member function getSocsecnum():
 * Input:
 *  none
 * Process:
 *  retrieves the value of member variable socsecnum
 * Output:
 *  returns the object's socsecnum
 */
string Depositor::getSocsecnum () const
{
    return socsecnum ;
}
