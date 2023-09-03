#include "class.hpp"

int main()
{
    Bank b;
    Account acc;
    int choice;
    string fname,lsname;
    long balance,account_no;
    long money;
    cout<<"******BANKING SYSTEM*******"<<endl;
    do
    {
        cout<<"Please Select one option below"<<endl;
        cout<<"\t1 Open an Account"<<endl;
        cout<<"\t2 Balance Enquiry"<<endl;
        cout<<"\t3 Deposit"<<endl;
        cout<<"\t4 Withdraw"<<endl;
        cout<<"\t5 Close an Account"<<endl;
        cout<<"\t6 Show All Accounts"<<endl;
        cout<<"\t7 Quit"<<endl;
        cout<<"Please Enter your Choice: ";
        cin>>choice;
        switch (choice)
        {
            case 1:
                cout<<"Please Enter Your First Name:";
                cin>>fname;
                cout<<"Please Enter Your Last Name:";
                cin>>lsname;
                cout<<"Please Enter your balance:";
                cin>>balance;
                acc = b.openAccount(fname,lsname,balance);
                cout<<acc;
                break;
            case 2:
                cout<<"Enter Account Number:";
                cin>>account_no;
                if (b.find(account_no))
                {
                    acc = b.BalanceEnquiry(account_no);
                    cout<<"Your Account Details"<<endl;
                    cout<<acc;
                }
                else
                {
                    cout<<"###############################"<<endl;
                    cout<<"###########ID IS WRONG#########"<<endl;
                    cout<<"###############################"<<endl;
            
                }
                
                break;
            case 3:
                cout<<"Enter Account Number:";
                cin>>account_no;
                if (!b.find(account_no))
                {
                    cout<<"###############################"<<endl;
                    cout<<"###########ID IS WRONG#########"<<endl;
                    cout<<"###############################"<<endl;
                }
                else
                {
                    cout<<"Enter the Amount of money you want to deposit:";
                    cin>>money;
                    acc=b.Deposit(account_no,money);
                    cout<<"Process has been completed successfully"<<endl;
                    cout<<acc;
                }
                break;
            case 4:
                cout<<"Enter Account Number:";
                cin>>account_no;
                if (!b.find(account_no))
                {
                    cout<<"###############################"<<endl;
                    cout<<"###########ID IS WRONG#########"<<endl;
                    cout<<"###############################"<<endl;
                }
                else
                {
                    cout<<"Enter the Amount of money you want to withdraw:";
                    cin>>money;
                    acc=b.Withdraw(account_no,money);
                    cout<<acc;

                }
                break;

            case 5:
                cout<<"Enter Account Number:";
                cin>>account_no;
                if (!b.find(account_no))
                {
                    cout<<"###############################"<<endl;
                    cout<<"###########ID IS WRONG#########"<<endl;
                    cout<<"###############################"<<endl;
                }
                else
                {

                b.CloseAccount(account_no);
                cout<<"Your Account is closed"<<endl;

                }
                break;
            case 6:
                b.showAllAccounts();
                break;
            case 7:
                break;
            default:
                cout<<"\n Wrong Input please Enter correct Choice";
                exit(0);
        }
    } while (choice !=7); 
    return 0;
}
