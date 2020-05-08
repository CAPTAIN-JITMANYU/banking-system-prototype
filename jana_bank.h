/* this file includes generation of the class "jana_bank
   and the modules for accessing the datamembers only*/

#include<iostream>
#include<fstream>
#include <bits/stdc++.h>
#include<stdlib.h>

using namespace std;

class jana_bank {
	// the personal credentials are kept as private members
	// to prevent any external access

	long int uidai_no;

	char first_name[20];

	char last_name[20];

	char mobile_no[15];

	long int balance;

	int age;

	// this is your unique banking id
	long int customer_id;

	// this is the password to access your account
	long int pin;

public:
	// the member functions are used by the functions in
	// jana_accounting.h to access the datamembers

	// funciton to add a new account in the banking databse
	// basically works as a constructor
	void add_data(long int );

	// function to display the balnce in an account
	void display_data();

	// function to display all the details of an account
	void display_details();

	// function to modify NAME or MOBILE NUMBER
	void modify();

	long int return_customer_id()
	{return customer_id;}

	long int return_balance()
	{return balance;}

	long int return_pin()
	{return pin;}

	long int return_uidai()
	{return uidai_no;}

	// function to add money to your balance
	void deposit_money(int);

	// function to withdraw money from your balance
	void withdraw_money(int);

};

void jana_bank::add_data(long int r)
{
	this->uidai_no = r;

	cout << "FIRST NAME : ";
	cin >> this->first_name;

	cout << "LAST NAME : ";
	cin >> this->last_name;

	int a;
	cout << "YEAR OF BIRTH :";
	cin >> a;
	// calculating the age from the year of birth
	this->age = 2020 - a;

	cout << "MOBILE NUMBER : ";
	cin >> this->mobile_no;

	this->customer_id = uidai_no;

	srand(time(0));
	this->pin = rand() % 9000 + 1000;		//this statement generates a pin from (1000 - 9999)

	this->balance = 10000;

}


void jana_bank::display_data()
{
	cout << this->uidai_no << "\t\t" << this->first_name << " " << this->last_name << "\t  " << this->balance << "\n";
}

void jana_bank::display_details()
{
	cout << endl;
	cout << "\tUIDAI NUMBER : " << this->uidai_no << endl;

	cout << "\tNAME : " << this->first_name << " " << this->last_name << endl;

	cout << "\tMOBILE NUMBER : " << this->mobile_no << endl;

	cout << "\tAGE : " << this->age << " years" << endl;

	cout << "\tCUSTOMER ID : " << this->customer_id << endl;

	cout << "\tPIN : " << this->pin << endl;

	cout << "\tBALANCE: " << this->balance << endl;

}


void jana_bank::modify()

{	cout << "FIRST NAME : ";
	cin >> this->first_name;

	cout << "LAST NAME : ";
	cin >> this->last_name;

	cout << "MOBILE NUMBER : ";
	cin >> this->mobile_no;

}


void jana_bank::deposit_money(int a)
{
	this->balance = this->balance + a;

	cout << "UPDATED BALANCE : " << this->balance;
}


void jana_bank::withdraw_money(int a)
{
	this->balance = this->balance - a;

	cout << "UPDATED BALANCE : " << this->balance;
}

