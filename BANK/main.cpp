//HW_5 BANK ACCOUNTS
//Extra Credits
//ALI ZAIB

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <windows.h>
#include "Bank.h"
#include "TransactionInputForm.h"
using namespace std;

//Function Prototypes
void readBank (Bank & bank);
void printBank (const Bank & bank, ofstream & out);
void printHistory (const Bank & bank, ofstream & out);
void balance (const Bank &bank,  ofstream & out,ifstream & in);
void close (Bank &bank,  ofstream & out,ifstream & in);
void account_info (const Bank & bank ,ofstream & out,ifstream & in);
void account_info_H (const Bank & bank ,ofstream & out, ifstream & in);
void reopen (Bank &bank,  ofstream & out,ifstream & in);
void deposit (Bank & bank, ofstream & out,ifstream & in );
void withdrawal (Bank & bank, ofstream & out,ifstream & in );
void new_acct (Bank & bank, ofstream & out,ifstream & in);
void delete_acct (Bank & bank, ofstream & out,ifstream & in);
void menu ();
void placeCursor (HANDLE screen, int row, int col);
int main()
{
    //Declaring variables
    bool not_done = true;
    char choice;
    Bank bank ;

    //Declaration and opening of input file
    ifstream infile
        ("C:\\Users\\PCR\\Desktop\\C++ Practice\\BANK1\\operations.txt");
    //ifstream infile("con");
    //Declaration and opening of output file
    ofstream outfile
        ("C:\\Users\\PCR\\Desktop\\C++ Practice\\BANK1\\output.txt");

    //Setting precision up to 2 decimal places
    outfile.setf(ios::fixed,ios::floatfield);
    outfile.precision(2);
    outfile << "ALI ZAIB" << endl<< endl;
    //Calling the function readBank() to read initial data
    readBank (bank);
    outfile << "INITIAL CUSTOMER INFORMATION"<< endl;
    //Calling the function printBank() to read initial data
    printBank (bank,outfile);

   do
    {
       //Call to the function to display menu
       menu();
       infile >> choice ;

       //Compound switch statement
       switch (choice)
       {
       case 'Q':
           not_done = false ;
           outfile << endl << endl << "CLOSING CUSTOMER INFORMATION"<< endl;
           //Calling the function to print the data at the end of operations
           printBank (bank,outfile);

           outfile << endl << endl <<
                "TRANSACTION HISTORY FOR ALL THE ACCOUNTS IN DATABASE"<< endl;
           outfile << "**Upon the creation of the account, Transaction Amount"
                "is equal to initial balance" << endl <<endl;
           //Calling the function to print the transactions history
           printHistory(bank,outfile);
           break;

       case 'I':
            //Calling the function to get account information
           account_info(bank,outfile,infile );
           break;
       case 'H':
           account_info_H(bank,outfile,infile );
           break;

       case 'B':
           //Call to the function to inquire balance of an account
           balance(bank,outfile,infile);
           break;
       case 'C':
           //Call to the function to close an account
           close(bank,outfile,infile);
           break;

        case 'R':
           //Call to the function to close an account
           reopen (bank,outfile,infile);
           break;

       case 'D':
           //Call to the function to make deposits in an account
           deposit(bank,outfile,infile);
        break;

       case 'W':
           //Call to the function to make withdrawals from an account
           withdrawal(bank,outfile,infile);
           break;

       case 'N':
           //Call to the function to make a new account in system
           new_acct(bank,outfile,infile);
           break;

       case 'X':
           //Call to the function to delete an account from the system
           delete_acct(bank,outfile,infile);
           break;

        default:
            //Validation of the choice
            cout << "Operation requested is invalid. Please try again."<<endl;
            outfile << endl ;
            outfile << "Operation Requested  = " << choice << endl ;
            outfile << "ERROR: No such choice in menu."
                "Please try again with a valid selection." << endl<<endl;
            outfile << "\t***--------------------------***" <<endl;
            break;
       }
    }

    while (not_done);
    //Closing output and input files

    outfile.close();
    infile.close();

    return 0 ;
}

/*
 *menu():
 *Input:
 *Noting
 *Process:
 * Displays menu
 *Output:
 * Prints options on screen for user to choose one from those
 */

void menu ()
{
    cout << "Enter B for balance inquiry"<<endl;
    cout << "Enter D for deposit" <<endl;
    cout << "Enter W for withdrawal"<<endl;
    cout << "Enter Q to quit" << endl;
    cout << "Enter N to add new account" << endl;
    cout << "Enter X to delete account" << endl;
return ;
}

/*
 *readBank():
 *Input:
 * bank - a reference to the Bank object
 *Process:
 * Declare and open input file
 * Reads in the initial Bank database
 * Calls various (Name(), Depositor(), Account()) constructors to set values
 * Uses method setAccount() to set an account's data members until the EOF
 * Close the input file
 *Output:
 * Fills in the initial Bank database
 */

void readBank (Bank & bank)
{
    //Declaring local variables
    string last, first, socsecnum, type, acct_status;
    int acct_num ;
    double balance ;
    Name name ;
    Depositor depositor ;
    Transaction transaction ;

    Account account ;


    //Declaring and opening of input file for reading data
    ifstream infile
        ("C:\\Users\\PCR\\Desktop\\C++ Practice\\BANK1\\input.txt");

    //Reading until EOF
    while (infile >> last)
    {
        infile >> first ;
        infile >> socsecnum;
        infile >> acct_num;
        infile >> type ;
        infile >> balance ;
        infile >> acct_status ;
        //Calling various constructors to initialize data
        name = Name (first,last) ;
        depositor = Depositor (name, socsecnum);
        transaction = Transaction ("Opening of the account", balance);
        account = Account
            (depositor, acct_num, type, balance, acct_status,0,transaction);
        //Calling the member function setAccount() to set accounts
        bank.setAccount(account);
    }

    //Closing input file
    infile.close();
    return;
}

/*
 *printBank():
 *Input:
 * ofstream & out-A reference to the ofstream
 * bank - a reference to the Bank object
 *Process:
 * It is a constant function which prints the headers for the information
 * Prints all the information in bank database
 *Output:
 * Prints bank database whenever it is called.
 */

void printHistory (const Bank & bank, ofstream & out)
{
    Transaction transaction ;
    Account * accct ;
    for (int i = 0 ; i < bank.getNum_acct() ; i++)
    {

        accct = bank.getAccount(i);
        out << "ACCOUNT# = "  << accct->getAcct_num() << endl ;
        out <<"TOTAL TRANSACTIONS = "  << accct->getNumtrans() <<endl <<endl ;
        for (int j = 0 ; j < accct->getNumtrans(); j++)
        {
            transaction = accct->getTrans(j);

            out <<"TRANSACTION # "<< j+1 << ":" << endl ;
            out<<  "Transaction Type = " <<  transaction.getTransType() <<endl;
            if (transaction.getTransAmount()> 0)
            out << "Trans Amount = " <<transaction.getTransAmount() << endl ;
            else
            out << "Trans Amount = N/A"  << endl ;
        }
        out <<endl <<endl ;
    }
}

void printBank (const Bank & bank, ofstream & out)
{
    //Declaring local variables
    Account* account ;
    Depositor depositor ;
    Name name ;
    out << endl;
    out << "Total Number of Accounts = "<< bank.getNum_acct() <<endl;
    out << "***-----------------------***" << endl ;

    //Table headers
    out<<"F_Name\t\tL_Name\t\tSSN\t\t\tACCT#\t\tStatus\t\tACCT_Type\t\tBalance"
        << endl;
    out << "****---------------------------------------------------------"
        "----------------------------------------------------------****" <<endl;
    out << endl ;

    for (int count = 0 ; count < bank.getNum_acct(); count++)
    {
       account = bank.getAccount(count) ;
       depositor = account->getDepositor();
       name = depositor.getName();
       out << name.getFirst() ;
       out << "\t\t" <<  name.getLast();
       out <<  "\t\t" <<  depositor.getSocsecnum();
       out <<  "\t\t" <<  account->getAcct_num();
       out <<  "\t\t" <<  account->getStatus() ;
       out << "\t\t"  << account->getAcct_type() ;
       out.width (9);
       out <<  "\t\t" <<  account->getBalance() ;
       out << endl ;

    }
    out << "****---------------------------------------------------------"
       "-----------------------------------------------------------****"<<endl;
    return ;
}

/*
 *balance():
 *Input:
 * ifstream & in-A reference to the input file
 * ofstream & out-A reference to the ofstream
 * bank - a reference to the Bank object
 *Process:
 * Reads account number entered by user
 * Calls the method findAccount() to validate the account entered
 *Output:
 * Prints the balance if account entered is valid
 * Otherwise prints an error message
 */

void balance (const Bank &bank,  ofstream & out,ifstream & in)
{
    //Declaration of local variables
    int acct;
    int index;
    Transaction transaction ;
    TransactionInputForm * input ;
    input = new TransactionInputForm ;
    Account* account ;
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);

    placeCursor(screen,14,65);
    cout << "*DATA ENTRY For Balance Inquiry*"<<endl;
    placeCursor(screen, 16,65);
    cout << "Acct# :" ;
    placeCursor(screen, 16,74);
    in >> acct ;
    placeCursor(screen, 17,65);
    cout << "**************************" <<endl;
    *input = TransactionInputForm(acct);

    out<<endl<<endl;
    out << "Operation requested is Balance Inquiry."<< endl;
    out << "Account Number = " <<  acct << endl;
    index = bank.findAccount(acct);

    if (index == -1)
    {
        out << "ERROR: Account Number does not exist."
            "Try with a valid account number, please." <<endl<<endl;
        out<< "\t***--------------------------***" <<endl;
    }

    else

    {
        account = bank.getAccount(index);
        if (account->getStatus()!= "Active")
        {
            out << "ERROR: No transaction can be done, Account is closed "
                << endl << endl;
            out<< "\t***--------------------------***" <<endl;
        }
        else
        {
            out << "Current Balance = $" << account->getBalance() <<endl<<endl;
            out<< "\t***--------------------------***" <<endl;
            transaction = Transaction ("Balance inquiry", 0.0);
            account->addTrans(transaction);
        }

    }
    delete input ;
    return;
}
void close (Bank &bank,  ofstream & out,ifstream & in)
{
    //Declaration of local variables
    int acct;
    int index;
    Transaction transaction;
    TransactionInputForm * input ;
    input = new TransactionInputForm ;
    Account* account ;
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);

    placeCursor(screen,19,65);
    cout << "*DATA ENTRY For Closing Acct*"<<endl;
    placeCursor(screen, 21,65);
    cout << "Acct# :" ;
    placeCursor(screen, 21,74);
    in >> acct ;
    placeCursor(screen, 22,65);
    cout << "**************************" <<endl;
    *input = TransactionInputForm(acct);
    out<<endl<<endl;
    out << "Operation requested is Closing the Account."<< endl;
    out << "Account Number = " << acct << endl;
    index = bank.findAccount(acct);

    if (index == -1)
    {
        out << "ERROR: Account Number does not exist."
            "Try with a valid account number, please." <<endl<<endl;
        out<< "\t***--------------------------***" <<endl;
    }

    else

    {
        account = bank.getAccount(index);
        if (account->getStatus() == "Closed")
        {
            out << "ERROR: Account is already Closed" << endl ;

            out<< "\t***--------------------------***" <<endl;
        }
        else
        {
            account->setStatus("Closed");
            out << "Account has been closed successfully " << endl ;

            out<< "\t***--------------------------***" <<endl;
            transaction = Transaction ("Closing the account", 0.0);
            account->addTrans(transaction);

        }

    }
    delete input;
    return;
}
void reopen (Bank &bank,  ofstream & out,ifstream & in)
{
    //Declaration of local variables
    int acct;
    int index;
    Transaction transaction;
    TransactionInputForm * input ;
    input = new TransactionInputForm ;
    Account* account ;
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);

    placeCursor(screen,24,65);
    cout << "*DATA ENTRY For Re-opening Acct*"<<endl;
    placeCursor(screen, 26,65);
    cout << "Acct# :" ;
    placeCursor(screen, 26,74);
    in >> acct ;
    placeCursor(screen, 27,65);
    cout << "**************************" <<endl;
    *input = TransactionInputForm(acct);
    out<<endl<<endl;
    out << "Operation requested is Re-opening the closed Account."<< endl;
    out << "Account Number = " << acct << endl;
    index = bank.findAccount(acct);

    if (index == -1 )
    {
        out << "ERROR: Account Number does not exist."
            "Try with a valid account number, please." <<endl<<endl;
        out<< "\t***--------------------------***" <<endl;
    }
    else
    {
        account = bank.getAccount(index);
        if (account->getStatus() == "Active")
        {
            out << "ERROR: Account is already Active" << endl ;
            out<< "\t***--------------------------***" <<endl;
        }
        else
        {
            account->setStatus("Active");
            out << "Account has been Re-opened" << endl ;

            out<< "\t***--------------------------***" <<endl;
            transaction = Transaction ("Re-opening the account", 0.0);
            account->addTrans(transaction);
        }

    }

    delete input;
    return;
}

/*
 *account_info()
 *Input:
 * ifstream & in-A reference to the input file
 * ofstream & out-A reference to the ofstream
 * bank - a reference to the bank database
 *Process:
 * Reads SSN number entered by user
 * Calls the method findSSN() to validate the SSN entered
 *Output:
 * Prints the all relevant information if SSN entered is valid
 * Otherwise prints an error message
 */

void account_info (const Bank & bank ,ofstream & out, ifstream & in)
{
    //Declaration of local variables
    string customerSSN ;
    int index  ;
    Account* account ;
    TransactionInputForm * input ;
    input = new TransactionInputForm ;
    Depositor depositor ;
    Transaction transaction ;
    Name name ;
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);

    placeCursor(screen,29,65);
    cout << "*DATA ENTRY For Acct_Info*"<<endl;
    placeCursor(screen, 31,65);
    cout << "SSN# :" ;
    placeCursor(screen, 31,74);
    in >> customerSSN ;
    placeCursor(screen, 32,65);
    cout << "**************************" <<endl;
    *input = TransactionInputForm(customerSSN);
    out<<endl<<endl;
    out << "Operation requested is Account_Info ."<< endl;
    out << "Entered SSN =  " << customerSSN << endl ;
    index = bank.findSSN(customerSSN);
    if (index == -1)
    {
        out << "ERROR: Entered SSN does not exist."
            "Try with a valid SSN, please." <<endl<<endl;
        out<< "\t***--------------------------***" <<endl;
    }
    else
    {
        account = bank.getAccount(index);
        if (account->getStatus()!= "Active")
        {
            out << "ERROR: No transaction can be done, Account is closed "
                << endl << endl;
            out<< "\t***--------------------------***" <<endl;
        }
        else
        {
            depositor = account->getDepositor();
            name = depositor.getName();
            out << "The information related to the entered SSN is as follow: "
                << endl ;
            out << "First name: " << name.getFirst() << endl ;
            out << "Last name: " << name.getLast()<< endl ;
            out << "Account type: " << account->getAcct_type() << endl ;
            out << "Account#: " << account->getAcct_num() << endl ;
            out << "Account balance: " << account->getBalance() << endl<< endl;

             out << "\t***--------------------------***" <<endl  ;
            transaction = Transaction ("Acct_Info W/O Trans history", 0.0);
            account->addTrans(transaction);

        }
    }
    delete input ;
    return;

}
void account_info_H (const Bank & bank ,ofstream & out, ifstream & in)
{
    //Declaration of local variables
    string customerSSN ;
    int index  ;
    Account* account ;
    TransactionInputForm* input ;
    input = new TransactionInputForm;
    Depositor depositor ;
    Transaction transaction ;
    Name name ;
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
    placeCursor(screen,34,65);
    cout << "*DATA ENTRY For Acct_Info with Transactions*"<<endl;
    placeCursor(screen, 36,65);
    cout << "SSN# :" ;
    placeCursor(screen, 36,74);
    in >> customerSSN ;
    placeCursor(screen, 37,65);
    cout << "**************************" <<endl;
    *input = TransactionInputForm(customerSSN);
    out<<endl<<endl;
    out << "Operation requested is Account_Info with Transaction history ."
        << endl;
    out << "Entered SSN =  " << customerSSN << endl ;
    index = bank.findSSN(customerSSN);
    if (index == -1)
    {
        out << "ERROR: Entered SSN does not exist."
            "Try with a valid SSN, please." <<endl<<endl;
        out<< "\t***--------------------------***" <<endl;
    }
    else
    {
        account = bank.getAccount(index);
        if (account->getStatus()!= "Active")
        {
            out << "ERROR: No transaction can be done, Account is closed "
                << endl << endl;
            out<< "\t***--------------------------***" <<endl;
        }
        else
        {


            depositor = account->getDepositor();
            name = depositor.getName();
            out << "The information related to the entered SSN is as follow: "
                << endl ;
            out << "First name: " << name.getFirst() << endl ;
            out << "Last name: " << name.getLast()<< endl ;
            out << "Account type: " << account->getAcct_type() << endl ;
            out << "Account#: " << account->getAcct_num() << endl ;
            out << "Account balance: " << account->getBalance() << endl<< endl;

            out << "TRANSACTION HISTORY FOR THE ACCOUNT " << endl << endl;
            out << "Total Transactions = " << account->getNumtrans() << endl;
            for (int i = 0 ; i <account->getNumtrans() ; i++)
            {
                transaction = account->getTrans(i) ;
                out << "Transaction # " << i+1 << ":" << endl ;
                out << "Transaction type = " << transaction.getTransType()
                    << endl ;
                if (transaction.getTransAmount()> 0)
                out << "Transaction amount = " << transaction.getTransAmount()
                    << endl ;
                else
                out << "Transaction amount = N/A"  <<endl ;
                out << endl ;
            }
             out << "\t***--------------------------***" <<endl  ;
            transaction = Transaction ("Acct_Info W Trans history", 0.0);
            account->addTrans(transaction);

        }
    }
    delete input ;
    return;

}


/*
 *deposit():
 *Input:
 * ifstream & in-A reference to the input file (in_operations)
 * ofstream & out-A reference to the ofstream (outfile)
 * bank - a reference to the bank database
 *Process:
 * Reads an account number
 * Validate the account number by calling findAccount, a member function
 * Reads the amount to deposit
 * Validates the amount to be deposited
 * Creates a new account with updated balance
 * Deletes the old account by using methods, Accountfliping() and
 *  setNum_acct()
 *Output:
 * Prints error message if account number is not valid
 * Prints the error message if amount to deposit is not valid
 * Prints the new balance after addition of deposited amount to old balance
 */

void deposit (Bank & bank, ofstream & out,ifstream & in )
{
    //Declaration of local variables
    int acct;
    int index;
    double depositing_amount;
    TransactionInputForm* input ;
    input = new TransactionInputForm;
    Transaction transaction ;
    Account* account ;
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
    placeCursor(screen,39,65);
    cout << "*DATA ENTRY For Deposit*"<<endl;
    placeCursor(screen, 41,65);
    cout << "Acct# :" ;
    placeCursor(screen, 41,74);
    in >> acct ;
    placeCursor(screen, 42,65);
    cout << "Deposit $:";
    placeCursor(screen, 42,74);
    in >> depositing_amount;
    placeCursor(screen, 43,65);
    cout << "**************************" <<endl;

    *input = TransactionInputForm(acct, depositing_amount);
    out<<endl<<endl;
    out << "Operation requested is Deposit."<< endl;
    out << "Account Number = " << acct << endl;

    index = bank.findAccount(acct);
    //Calling member function to find account
    if (index == -1)
    {
        out << "ERROR: Account Number does not exist."
            "Try with a valid account number, please." <<endl<<endl;
        out<< "\t***--------------------------***" <<endl;
    }

    else
    {
        //Calling member function to get the account
        account = bank.getAccount(index);
        if (account->getStatus()!= "Active")
        {

            out << "ERROR: No transaction can be done, Account is closed "
                << endl << endl;
            out<< "\t***--------------------------***" <<endl;


        }
        else
        {



            if (depositing_amount <= 0.00)

            {
                out << "Amount to deposit = $" << depositing_amount <<endl ;
                out << "ERROR:Invalid amount."
                    "Try with a valid depositing amount, please."
                    <<endl<<endl;
                out<< "\t***--------------------------***" <<endl;
            }





            else
            {
                out << "Transaction has been processed successfully."
                    << endl;


                out <<"Old balance = $"<< account->getBalance() <<endl;
                account->makeDeposit(depositing_amount);

                out << "Depositing amount = $" << depositing_amount
                    << endl;
                out << "New balance = $"
                    << account->getBalance() << endl<<endl;
                out<< "\t***--------------------------***" <<endl;
                transaction = Transaction ("Deposit", depositing_amount);
                account->addTrans(transaction);

            }
        }
    }
    delete input ;
    return;
}


/*
 *withdrawal():
 *Input:
 * ifstream & in-A reference to the input file (in_operations)
 * ofstream & out-A reference to the ofstream (outfile)
 * bank - a reference to the bank database
 *Process:
 * Reads an account number
 * Validate the account number by calling findAccount, a member function
 * Reads the amount to withdraw
 * Validates the amount to be deposited
 * Creates a new account with updated balance
 * Deletes the old account by using methods, Accountfliping() and
 *  setNum_acct()
 *Output:
 * Prints error message if account number is not valid
 * Prints the error message if amount to deposit is not valid
 * Prints the new balance after withdrawing amount from old balance
 */

void withdrawal (Bank & bank, ofstream & out,ifstream & in )
{
    //Declaring local variables
    int acct;
    int index;
    int withdraw_limit = 1000;
    double withdraw_amount;
    TransactionInputForm* input ;
    input = new TransactionInputForm ;
    Transaction transaction ;
    Account* account ;
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
    placeCursor(screen,45,65);
    cout << "*DATA ENTRY For Withdrawing*"<<endl;
    placeCursor(screen, 47,65);
    cout << "Acct# :" ;
    placeCursor(screen, 47,74);
    in >> acct ;
    placeCursor(screen, 48,65);
    cout << "Withdraw $:";
    placeCursor(screen, 48,74);
    in >> withdraw_amount;
    placeCursor(screen, 49,65);
    cout << "**************************" <<endl;

    *input = TransactionInputForm(acct, withdraw_amount);
    out <<endl<<endl;
    out << "Operation requested is Withdrawal"<< endl;
    out << "Account Number = " << acct << endl;
    index = bank.findAccount(acct);
    if (index == -1)

    {
        out << "ERROR: Account Number does not exist."
            "Try with a valid account number, please." <<endl<<endl;
        out<< "\t***--------------------------***" <<endl;
    }
    else
    {
        account = bank.getAccount(index);
        if (account->getStatus()!= "Active")
        {

            out << "ERROR: No transaction can be done, Account is closed "
                << endl << endl;
            out<< "\t***--------------------------***" <<endl;


        }
        else
        {

            if ((double)account->getBalance() <  withdraw_amount)
            {
                out << "Current Balance = " << account->getBalance()
                    <<endl;
                out << "Withdrawal amount = $" << withdraw_amount <<endl;
                out << "ERROR: Insufficient available funds."
                    "Try with a valid withdrawal amount, please."
                    << endl<<endl;
                out<< "\t***--------------------------***" <<endl;

            }

            else if (withdraw_amount <= 0.00 )
            {
                out << "Current Balance = " << account->getBalance()<<endl;
                out << "Withdrawal amount = $" << withdraw_amount << endl;
                out << "ERROR: Invalid withdrawal amount."
                    "Try with a valid withdrawal amount, please."
                    <<endl<<endl;
                out<< "\t***--------------------------***" <<endl;

            }
            else if (withdraw_amount > withdraw_limit)

            {

                out<< "Current Balance = " << account->getBalance()
                    <<endl;
                out<< "Withdrawal limit per day = $" << withdraw_limit
                    << endl ;
                out<< "Withdrawal amount = $" << withdraw_amount << endl;
                out<<"ERROR: Withdrawal amount is exceeding withdrawing limit."
                    "Try with a valid withdrawal amount, please."
                    << endl<<endl;
                out << "\t***--------------------------***" <<endl;

            }
            else if  (account->getStatus()!= "Active")
            {

                out << "ERROR: No transaction can be done, Account is closed "
                    << endl << endl;
                out<< "\t***--------------------------***" <<endl;


            }
            else
            {
                out << "Transaction has been processed successfully." << endl;
                out << "Old balance = $" << account->getBalance() <<endl;
                account->makeWithdrawal(withdraw_amount);

                out << "Withdrawal amount = $" << withdraw_amount << endl;
                out << "New balance = $" << account->getBalance() << endl
                    <<endl;
                out << "\t***--------------------------***" <<endl;
                transaction = Transaction ("Withdrawal", withdraw_amount);
                account->addTrans(transaction);
            }


        }
    }

    return ;
}


/*
 *new_acct()
 *Input:
 * ifstream & in-A reference to the input file
 * ofstream & out-A reference to the ofstream
 * bank - a reference to the bank database
 *Process:
 * Reads the account number to add in the data
 * Checks the account number entered does not exit already
 * Uses screen input form to reads in all needed variables
 * Calls various (Name(), Depositor(), Account()) constructors to set values
 * Uses method setAccount() to set new account's data members
 *Output:
 * Prints error message if the account number entered already in database
 *  Otherwise adds the account number
 */

void new_acct (Bank & bank, ofstream & out,ifstream & in)
{
//Declaring local variables
    int acct;
    string newfirst, newlast, newssn , newacct_type, newstatus, trans_type ;
    double newbalance ;
    Account newaccount  ;
    Name name ;
    TransactionInputForm * input ;
    input = new TransactionInputForm ;
    Depositor depositor ;
    Transaction transaction   ;

    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);

    placeCursor(screen,2,65);

    cout << "*DATA ENTRY FORM For Creating An ACCOUNT*"<<endl;
    placeCursor(screen, 4,65);
    cout << "Acct#:" ;
    placeCursor(screen, 4,74);
    in >> acct;
    placeCursor(screen, 5,65);

    cout << "F Name :" << endl ;
    placeCursor(screen, 5,74);
    in >> newfirst ;
    placeCursor(screen, 6,65);
    cout << "L Name :" << endl ;
    placeCursor(screen, 6,70);
    in >> newlast ;
    placeCursor(screen, 7,65);
    cout << "SSN:"<< endl;
    placeCursor(screen, 7,70);
    in >> newssn ;
    placeCursor(screen, 8,65);
    cout << "Type:"<< endl;
    placeCursor(screen, 8,74);
    in >> newacct_type;
    placeCursor(screen, 9,65);
    cout << "Balance:" << endl ;
    placeCursor(screen, 9,74);
    in >> newbalance ;
    placeCursor(screen, 10,65);
    cout << "Status" << endl ;
    placeCursor(screen, 10,74);
    in >> newstatus ;
    placeCursor(screen, 11,65);
    cout << "**************************" <<endl;
    *input = TransactionInputForm
        (acct, newlast,newfirst,newssn,newacct_type,newbalance,newstatus);
    out <<endl<<endl;
    out << "Operation requested is Creating new Account."<< endl;
    out << "Account Number = " << acct << endl;

    if (!bank.openAccount(acct))
    {
        out << "ERROR: Account already exist."
            "Try with another account number, please."
            << endl<<endl;

        out << "\t***--------------------------***" <<endl;
    }

    else
    {


        name = Name (newfirst,newlast) ;
        depositor = Depositor (name, newssn);


        transaction = Transaction ("New Acct opening" , newbalance);
        newaccount = Account
            (depositor,acct,newacct_type,newbalance,newstatus,0,transaction);
        bank.setAccount(newaccount);
        out << "Congrats new account has been set up for MR. "
             << name.getLast()<<endl<<endl;

        out << "\t***--------------------------***" <<endl;
    }
    delete input ;

    return ;
}

/*
 *placeCursor():
 *Input:
 * screen - a handle to the standard output screen
 * row - an integer to define row number
 * col - an integer to define column number
 *Process:
 * Defines cursor position
 *Output:
 * Defines cursor position
 */
void placeCursor (HANDLE screen, int row, int col)
{
    COORD position ;
    position.Y = row ;
    position.X = col ;
    SetConsoleCursorPosition(screen, position) ;
    return ;
}

/*
 *delete_acct():
 *Input:
 * ifstream & in-A reference to the input file (in_operations)
 * ofstream & out-A reference to the ofstream (outfile)
 * bank - A reference to the bank database
 *Process:
 * Reads the account number to delete from the data
 * Checks the account number entered exits or not by using method findAccount()
 * Deletes the account number by using method Accountfliping()
 * Updates the number of accounts by calling method setNum_acct()
 *Output:
 * Prints error message if the account number does not exit
 * Otherwise  deletes the account number and updates num_acct
 */
void delete_acct (Bank & bank, ofstream & out,ifstream & in)
{
    //Declaring local variables
    int acct;
    int index ;
    Transaction transaction ;
    TransactionInputForm * input ;
    input = new TransactionInputForm ;
    Account* account ;
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);

    placeCursor(screen,51,65);
    cout << "*DATA ENTRY For deleting Acct*"<<endl;
    placeCursor(screen, 53,65);
    cout << "Acct# :" ;
    placeCursor(screen, 53,74);
    in >> acct ;
    placeCursor(screen, 54,65);
    cout << "**************************" <<endl;
    *input = TransactionInputForm(acct);
    out <<endl<<endl;
    out << "Operation requested is deleting an Account."<< endl;
    out << "Account Number = " << acct << endl;
    index = bank.findAccount(acct);
    if (index == -1)

    {
        out << "ERROR: Account Number does not exist."
            "Try with a valid account number, please." <<endl<<endl;
        out<< "\t***--------------------------***" <<endl;
    }
    else
    {
        account = bank.getAccount(index);
        if (account->getStatus()== "Active")
        {
            account ->setStatus("Closed");
            bank.deleteAccount(index);
            out << acct << "  Account has been deleted successfully."
            << endl<<endl;

            out << "\t***--------------------------***" <<endl;


        }
        else
        {
            bank.deleteAccount(index);
            out << acct << "  Account has been deleted successfully."
            << endl<<endl;

            out << "\t***--------------------------***" <<endl;


        }

    }

    return;
}
