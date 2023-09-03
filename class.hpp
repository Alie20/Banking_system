#ifndef CLASS_H
#define CLASS_H

#include <string>
#include <string.h>
#include <map>
#include <fstream>
#include <iostream>

using namespace std;
class Account
{
        // set the private data
    private:
        long id;   
        string first_name;
        string last_name;
        long balance;
        static long next_id;
    public:
        Account(){}
        Account(string fn,string ln,long bal);
        string get_FirstName()
        {
            return first_name;
        }
        string get_LastName()
        {
            return last_name;
        }
        long get_balance()
        {
            return balance;
        }
         long get_ID()
         {
            return id;
         }
        void deposit(long bal)
        {
            balance += bal;
        }
        void withdraw (long bal)
        {
            balance -= bal;
        }
        static void set_last_accountNo(long accNo)
        {
            next_id = accNo;
        }
        static long get_last_accountNo()
        {
            return next_id;
        }
        friend ofstream & operator<<(ofstream &ofs,Account &acc);
        friend ifstream & operator>>(ifstream &ifs,Account &acc);
        friend ostream & operator<<(ostream &os, Account &acc);  
};


class Bank
{
    private:
        map<long,Account>accounts;
    public:
        Bank();
        Account openAccount(string first,string last,long bal);
        Account BalanceEnquiry(long id);
        Account Deposit(long id, long bal);
        Account Withdraw(long id, long bal);
        bool find(long id);
        void CloseAccount(long id);
        void showAllAccounts();
        ~Bank();
    
};
#endif