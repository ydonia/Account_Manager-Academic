//
//  Account.h
//  hw7
//
//  Created by Youssef Donia on 3/27/20.
//  Copyright © 2020 Youssef Donia. All rights reserved.
//

#ifndef Account_h
#define Account_h

using namespace std;

struct Date
{
   int month;
   int day;
   int year;
};

struct Person // stores account owner’s info
{
   string name;
   Date DOB;
   string address;
};
class Account
   {
   private:
       int accountNumber;
       int numOwners;
       Person *ownerPtr;
       double balance;
       static int accountCounter; //where do i define this
   public:
       Account(int numberOwners, double amount);
       
       ~Account();
       
       int withdraw(double amount);
       
       int deposit(double amount);
       
       void setOwner(int ind, Person p);
       
       Person getOwner(int ind) const;
       
       int getAccountNumber() const;
       
       double getBalance() const;
       
       int getNumOwners() const;
       
       void addOwner(Person p);
       
       int delOwner(Person p);
   
   };

#endif /* Account_h */

