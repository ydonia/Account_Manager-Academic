//
//  main.cpp
//  hw7
//
//  Created by Youssef Donia on 3/27/20.
//  Copyright © 2020 Youssef Donia. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
#include "Account.h"

void displayMenu();
void displayAccounts();
//define a global array of pointers to Account
   const int MAX_NUM_ACCOUNTS = 4;
   Account * accountArray[MAX_NUM_ACCOUNTS];

int main()
{
   
    for (int i = 0; i < MAX_NUM_ACCOUNTS; i++)
    {
        accountArray[i] = nullptr; //is this the correct way??
    }
    
    bool finished = false;
    int userChoice;
    bool available;
    int numberOwners;
    double amount;
    int accountNumber;
    bool exists;
    int newindex;
    Person newOwner;
    Person deleteOwner;
    int returnValue;
    while (! finished)
       {
           newindex = 0;
           available = false;
           exists = false;
           displayMenu();
           cin >> userChoice;
           //EVALUATE USER CHOICES
           if (userChoice == 1) //create account
           {
               //check if there is an available element in the account array
               for (int a = 0; a < MAX_NUM_ACCOUNTS; a++)
               {
                   if (accountArray[a] == nullptr)
                   {
                       available = true;
                   }
               }
               if (!available)
               {
                   cout << "Max number of accounts reached, cannot add a new account" << endl;
               }else
               {
                   //Prompt user for number of owners and amount of money to put in the account
                   cout << "Enter number of owners: ";
                   cin.ignore();
                   cin >> numberOwners;
                   cout << "Enter amount: ";
                   cin.ignore();
                   cin >> amount;
                   
                   //store object into the first available element in the array of accounts
                   int newAccountIndex = 0;
                   bool found = false;
                   Account *newAccount = new Account(numberOwners, amount);
                   for (int j = 0; j < MAX_NUM_ACCOUNTS; j++)
                   {
                       if (accountArray[j] == nullptr && !found)
                       {
                           newAccountIndex = j;
                           found = true;
                       }
                   }
                   accountArray[newAccountIndex] = newAccount;
                   cout << "Account #" << accountArray[newAccountIndex]->getAccountNumber() << " created" << endl;
               }
               
           } else if (userChoice == 2) //deposit
           {
               //prompt user for account number
               cout << "Enter account number: ";
               cin.ignore();
               cin >> accountNumber;
               //check to see if the account number exists
               int k = 0;
               while (k < MAX_NUM_ACCOUNTS && accountArray[k] != nullptr && !exists)
               {
                   if (accountNumber == accountArray[k]->getAccountNumber())
                   {
                       exists = true;
                       newindex = k;
                   }
                   k++;
               }
               if (!exists)
               {
                   cout << "No such account" << endl;
               }else
               {
                   //prompt user for amount
                   cout << "Enter amount: ";
                   cin.ignore();
                   cin >> amount;
                   int depositValue = accountArray[newindex]->deposit(amount);
                   if (depositValue == 1)
                   {
                       cout << "Amount cannot be negative, deposit not executed" << endl;
                   }else if (depositValue == 0)
                   {
                       cout << "New balance is $" << fixed << setprecision(2) << accountArray[newindex]->getBalance() << endl;
                   }
               }
           } else if (userChoice == 3) //withdraw
           {
              //prompt user for account number
              cout << "Enter account number: ";
              cin.ignore();
              cin >> accountNumber;
              int k = 0;
              while (k < MAX_NUM_ACCOUNTS && accountArray[k] != nullptr && !exists)
              {
                  if (accountNumber == accountArray[k]->getAccountNumber())
                  {
                      exists = true;
                      newindex = k;
                  }
                  k++;
              }
               if (!exists)
               {
                   cout << "No such account" << endl;
               }else
               {
                   //prompt user for amount
                   cout << "Enter amount: ";
                   cin.ignore();
                   cin >> amount;
                   int withdrawValue = accountArray[newindex]->withdraw(amount);
                   if (withdrawValue == 1)
                   {
                       cout << "Insufficient balance, withdrawal not executed" << endl;
                   }else if (withdrawValue == 2)
                   {
                       cout << "Amount cannot be negative, withdrawal not executed" << endl;
                   } else if (withdrawValue == 0)
                   {
                       cout << "New balance is $" << fixed << setprecision(2) << accountArray[newindex]->getBalance() << endl;
                   }
               }
           } else if (userChoice == 4)
           {
               displayAccounts();
           } else if (userChoice == 5)
           {
               //prompt user for account number
               cout << "Enter account number: ";
               cin.ignore();
               cin >> accountNumber;
               int u = 0;
               while (u < MAX_NUM_ACCOUNTS && accountArray[u] != nullptr && !exists)
               {
                   if (accountNumber == accountArray[u]->getAccountNumber())
                   {
                       exists = true;
                       newindex = u;
                   }
                   u++;
               }
                if (!exists)
                {
                    cout << "No such account" << endl;
                }else
                {
                    //prompt user for Person to delete
                    cout << "Enter owner's name: ";
                    cin.ignore();
                    getline(cin, deleteOwner.name);
                    
                    //call member function to delete owner
                    returnValue = accountArray[newindex]->delOwner(deleteOwner);
                    
                    if (returnValue == 1)
                    {
                        cout << "Person not found among the owners" << endl;
                    } else if (returnValue == 2)
                    {
                        cout << "delete cannot be performed because there is only one owner left" << endl;
                    }
                }
           } else if (userChoice == 6)
           {
               //prompt user for account number
               cout << "Enter account number: ";
               cin.ignore();
               cin >> accountNumber;
               int f = 0;
               while (f < MAX_NUM_ACCOUNTS && accountArray[f] != nullptr && !exists)
               {
                   if (accountNumber == accountArray[f]->getAccountNumber())
                   {
                       exists = true;
                       newindex = f;
                   }
                   f++;
               }
                if (!exists)
                {
                    cout << "No such account" << endl;
                }else
                {
                    //prompt user for new owner info
                    cout << "Enter owner's name: ";
                    cin.ignore();
                    getline(cin, newOwner.name);
                    
                    cout << "Enter owner's DOB, month, day then year: ";
                    cin >> newOwner.DOB.month >> newOwner.DOB.day >> newOwner.DOB.year;
                    
                    cout << "Enter owner's address: ";
                    cin.ignore();
                    getline(cin, newOwner.address);
                    
                    //call member function to add owner
                    accountArray[newindex]->addOwner(newOwner);
                }
           } else if (userChoice == 7) // quit
           {
               int del = 0;
               while (del < MAX_NUM_ACCOUNTS && accountArray[del] != nullptr)
               {
                   delete accountArray[del];
                   del++;
               }
               finished = true;
           }
       } return 0;
}


void displayMenu()
{
    cout << "Menu" << endl;
    cout << "----" << endl;
    
    cout << "1->Create account 2->Deposit   3->Withdraw 4->Display " << endl;
    cout << "5->Delete owner   6->Add owner 7->Quit " << endl;
}

void displayAccounts()
{
    int i = 0;
    while(i < MAX_NUM_ACCOUNTS && accountArray[i] != nullptr)
    {
        
        cout << "Account Number: " << accountArray[i]->getAccountNumber() << endl;
        cout << "--------------" << endl;
        for (int j = 0; j < accountArray[i]->getNumOwners(); j++)
        {
        cout << "*Name: " << accountArray[i]->getOwner(j).name << ", DOB: " << accountArray[i]->getOwner(j).DOB.month << "/" << accountArray[i]->getOwner(j).DOB.day << "/" << accountArray[i]->getOwner(j).DOB.year<< endl;
        cout << "Address: " << accountArray[i]->getOwner(j).address << endl;
        }
        cout << "*Balance: $" << accountArray[i]->getBalance() << " " << endl;
        i++;
    }
}





