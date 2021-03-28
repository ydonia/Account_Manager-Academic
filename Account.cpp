//
//  Account.cpp
//  hw7
//
//  Created by Youssef Donia on 3/27/20.
//
//

#include <stdio.h>
#include <iostream>
#include <string>
#include "Account.h"

int Account::accountCounter = 1000;
Account::Account(int numberOwners, double amount)
{
    accountNumber = accountCounter;
    numOwners = numberOwners;
    // Person array
    ownerPtr = new Person[numberOwners];
    string tempname;
    cin.ignore();
    for (int i = 0; i < numberOwners; i++)
    {
        cout << "Enter owner's name: ";
        getline(cin, tempname);
        ownerPtr[i].name = tempname;
        cout << "Enter owner's DOB, month, day then year: ";
        cin >> ownerPtr[i].DOB.month >> ownerPtr[i].DOB.day >> ownerPtr[i].DOB.year;
        
        cout << "Enter owner's address: ";
        cin.ignore();
        getline(cin, ownerPtr[i].address);
    }
    balance = amount;
    accountCounter++;
}
Account::~Account()
{
    /*for (int del = 0; del < numOwners; del++)
    {
        delete [] ownerPtr;
    }
     */
}
int Account::withdraw(double amount)
{
    if (amount > balance)
    {
        return 1;
    }else if (amount > 0)
    {
        balance = balance - amount;
        return 0;
    }else //(amount <= 0)
    {
        return 2;
    }
}
int Account::deposit(double amount)
{
    if (amount > 0)
    {
        balance = balance + amount;
        return 0;
    } else
    {
        return 1;
    }
    
}
void Account::setOwner(int ind, Person p)
{
        ownerPtr[ind] = p;
}

Person Account::getOwner(int ind) const
{
    return ownerPtr[ind];
}

int Account::getAccountNumber() const
{
    return accountNumber;
}

double Account::getBalance() const
{
    return balance;
}

int Account::getNumOwners() const
{
    return numOwners;
}

void Account::addOwner(Person newPerson)
{
    Person *tempOwnerPtr;
    //dynamically allocate new array with new size
    numOwners = numOwners + 1;
    tempOwnerPtr = new Person[numOwners];
    int lastElement =  numOwners - 1;
    
    //copy current array into new array
    for (int i = 0; i < numOwners - 1; i++)
    {
        tempOwnerPtr[i].name = ownerPtr[i].name ;
        tempOwnerPtr[i].DOB.month = ownerPtr[i].DOB.month;
        tempOwnerPtr[i].DOB.day = ownerPtr[i].DOB.day;
        tempOwnerPtr[i].DOB.year = ownerPtr[i].DOB.year;
        tempOwnerPtr[i].address = ownerPtr[i].address;
    }
    //release old array
    delete [] ownerPtr;
    
    //add the new person to the new array of owners
    tempOwnerPtr[lastElement] = newPerson;
    
    //get ownerPtr to point to the new array
    ownerPtr = tempOwnerPtr;
}

int Account::delOwner(Person deletePerson)
{
    Person *tempOwnerPtr;
    bool found = false;
    int indexToDelete = 0;
    int index= 0, index2 = 0;
    //check to see if the person exists in the array
    for (int i = 0; i < numOwners; i++)
    {
        if (deletePerson.name == ownerPtr[i].name)
        {
            indexToDelete = i;
            found = true;
        }
    }
        if (!found)
        {
            return 1;
        }else
        {
            if (numOwners == 1)
            {
                return 2;
            }else
            {
                //dynamically create a new array of owners
                tempOwnerPtr = new Person[numOwners - 1];
                
                //copy the contents of the current array to the temp one except for the one we deleted
                //ownerPtr[indexToDelete];
                while (index < numOwners)
                {
                    if (index != indexToDelete)
                    {
                        tempOwnerPtr[index].name = ownerPtr[index2].name;
                        tempOwnerPtr[index].DOB.month = ownerPtr[index2].DOB.month;
                        tempOwnerPtr[index].DOB.day = ownerPtr[index2].DOB.day;
                        tempOwnerPtr[index].DOB.year = ownerPtr[index2].DOB.year;
                        tempOwnerPtr[index].address = ownerPtr[index2].address;
                        index2++;
                    }
                    index++;
                }
                //release old array
                delete [] ownerPtr;
                
                //make ownerPtr point to the same array as tempOwnerPtr
                ownerPtr = tempOwnerPtr;
                return 0;
            }
        
        }
    
    
}
