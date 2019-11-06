//NAME CLASS SPECIFICATION
//ALI ZAIB

#ifndef NAME_H
#define NAME_H
#include <string>
using namespace std;

class Name
{
    string last ;
    string first ;

    public:

    //SETTERS

    void setLast (string lastname) ;
    void setFirst (string firstname);

    //GETTERS

    string getLast () const ;
    string getFirst ()const ;

    //CONSTRUCTORS

    /* Name default constructor:
     * Input:
     *  none
     * Process:
     *  sets object's data members to default values
     * Output:
     *  object's data members are set
     */

    Name ()
    {
        last = "";
        first = "";
    }


    /* Name constructor 2 - accepts 2 arguments:
     * Input:
     *  ini_first - Account holder's first name
     *  ini_last - Account holder's last name
     * Process:
     *  sets the member variable first = ini_first
     *  sets the member variable last = ini_last
     * Output:
     *  object's data members are set
     */
    Name (string ini_first, string ini_last)
    {
        first = ini_first ;
        last = ini_last ;
    }
};
#endif
