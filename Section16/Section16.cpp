// Section 16 
// Challenge 
#include <iostream>
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std; 

int main() {
    cout.precision(2);
    cout << fixed;
       
    // Savings 

    vector<Account *> sav_accounts;

    
    Account* savings_1 = new Savings_Account{};
    Account* savings_2 = new Savings_Account{ "Superman" };
    Account* savings_3 = new Savings_Account{ "Batman", 2000 };
    Account* savings_4 = new Savings_Account{ "Wonderwoman", 5000, 5.0 };


    sav_accounts.push_back(savings_1);
    sav_accounts.push_back(savings_2);
    sav_accounts.push_back(savings_3);
    sav_accounts.push_back(savings_4);


    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts,2000);
   
   // Checking
   
    vector<Account*> check_accounts;

    Account* checking_1 = new Checking_Account{} ;
    Account* checking_2 = new Checking_Account{ "Kirk" };
    Account* checking_3 = new Checking_Account{ "Spock", 2000 };
    Account* checking_4 = new Checking_Account{ "Bones", 5000 };

    check_accounts.push_back(checking_1);
    check_accounts.push_back(checking_2);
    check_accounts.push_back(checking_3);
    check_accounts.push_back(checking_4);

    display(check_accounts);
    deposit(check_accounts, 1000);
    withdraw(check_accounts, 2000);

    // Trust
  
    vector<Account*> trust_accounts;

    Account* trust_1 = new Trust_Account{};
    Account* trust_2 = new Trust_Account{ "Kirk" };
    Account* trust_3 = new Trust_Account{ "Spock", 2000 };
    Account* trust_4 = new Trust_Account{ "Bones", 5000 };

    trust_accounts.push_back(trust_1);
    trust_accounts.push_back(trust_2);
    trust_accounts.push_back(trust_3);
    trust_accounts.push_back(trust_4);

    display(trust_accounts);
    deposit(trust_accounts, 1000);
    withdraw(trust_accounts, 3000);
    
    // Withdraw 5 times from each trust account
    // All withdrawals should fail if there are too many withdrawals or if the withdrawl is > 20% of the balance
    for (int i=1; i<=5; i++)
        withdraw(trust_accounts, 1000);
    

    
    return 0;
}

