
#include "class.hpp"
long Account::next_id = 0;
Account::Account(string fn,string ln,long bal)
{
    next_id++;
    id = next_id;
    first_name = fn;
    last_name = ln;
    balance = bal;
}

ofstream & operator<<(ofstream &ofs,Account &acc)
{
    ofs<<acc.id<<endl;
    ofs<<acc.first_name<<endl;
    ofs<<acc.last_name<<endl;
    ofs<<acc.balance<<endl;
    return ofs;
}
ifstream & operator>>(ifstream &ifs,Account &acc)
{
    ifs>>acc.id;
    ifs>>acc.first_name;
    ifs>>acc.last_name;
    ifs>>acc.balance;
    return ifs;
}
ostream & operator<<(ostream &os, Account &acc)
{
    os<<"Account ID:"<<acc.get_ID()<<endl;
    os<<"First Name:"<<acc.get_FirstName()<<endl;
    os<<"Last Name:"<<acc.get_LastName()<<endl;
    os<<"Balance:"<<acc.get_balance()<<endl;
    return os;
}

Bank::Bank()
{
    Account account;
    ifstream file;
    file.open("Bank.data");
    if(!file)
    {
        cout<<"Error!! File Not Found!!"<<endl;
        return ;
    }
    while(file>>account)
    {
        accounts.insert(pair<long,Account>(account.get_ID(),account));
        cout<<"Hello";

    }
    if(accounts.empty())
    {
        Account::set_last_accountNo(0);
    }
    else
    {
        Account::set_last_accountNo(account.get_ID());

    }
    file.close();

}
Account Bank::openAccount(string first,string last,long bal)
{
    ofstream outfile;
    Account account(first,last,bal);
    accounts.insert(pair<long,Account>(account.get_ID(),account));
    outfile.open("Bank.data",ios::trunc);
    map<long,Account>::iterator itr;
    for(itr =accounts.begin();itr!=accounts.end();itr++)
    {
        outfile<<itr->second;
    }
    outfile.close();
    return account;
}
Account Bank::BalanceEnquiry(long id)
{
    map<long,Account>::iterator itr;
    itr = accounts.find(id);
    return itr->second;
}
Account Bank::Deposit(long id, long bal)
{
    map<long,Account>::iterator itr;
    itr = accounts.find(id);
    itr->second.deposit(bal);
    return (itr->second);
}
Account Bank::Withdraw(long id, long bal)
{
    map<long,Account>::iterator itr;
    itr = accounts.find(id);
    itr->second.deposit(bal);
    return (itr->second);
}
void Bank::CloseAccount(long id)
{
        map<long,Account>::iterator itr;
        itr = accounts.find(id);
        cout<<"Your account has been deleted"<<itr->second;
        accounts.erase(id);
}
void Bank::showAllAccounts()
{
    map<long,Account>::iterator itr;
    for(itr= accounts.begin();itr!=accounts.end();itr++)
    {
        cout<<"Account "<<itr->first<<endl<<itr->second<<endl;
    }
}
Bank::~Bank()
{
    ofstream outfile;
    outfile.open("Bank.data",ios::trunc);

    map<long,Account>::iterator itr;
    for(itr=accounts.begin();itr!=accounts.end();itr++)
    {
        outfile<<itr->second<<endl;
    }
    outfile.close();
}

bool Bank::find(long id)
{
    map<long,Account>::iterator itr;
    itr = accounts.find(id);
    if(itr == accounts.end())
    {
        return false;
    }
    return true;
}