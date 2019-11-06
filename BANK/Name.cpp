//NAME CLASS IMPLEMENTATION
//ALI ZAIB
#include <iostream>
#include <string>
#include <fstream>
#include "Name.h"
using namespace std;


//SETTERS

/* Name member function setLast():
 * Input:
 *  lastname - object's last name
 * Process:
 * sets the value of member variable last
 * Output:
 *  none
 */

void Name:: setLast (string lastname)
{
    last = lastname;
    return;
}


/* Name member function setFirst():
 * Input:
 *  firstname - object's first name
 * Process:
 *  sets the value of member variable first
 * Output:
 *  none
 */
void Name:: setFirst (string firstname)
{
    first = firstname ;
    return ;
}

//GETTERS

/* Name member function getLast():
 * Input:
 *  none
 * Process:
 *  retrieves the value of member variable last
 * Output:
 *  returns the object's last name
 */
string Name:: getLast () const
{
    return last ;
}

/* Name member function getFirst():
 * Input:
 *  none
 * Process:
 *  retrieves the value of member variable first
 * Output:
 *  returns the object's first name
*/
string Name:: getFirst () const
{
    return first ;

}
