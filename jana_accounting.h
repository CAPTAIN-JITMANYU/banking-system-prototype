/* this file contains the modules used to
   make modifications in the banking databse,
   which is a binary file.
*/



// THESE FUNCTIONS ARE FOR CREATION AND DELETION OF ACCOUNTS




// this function provides the fucntionality of PRESS ANY KEY TO CONTINUE
void paktc() {
	cout << "\n`````````````````````````````````````````````````````````````````" << endl;
	cout << "\n\nPRESS ENTER KEY TO CONTINUE" << endl;
	cout << "to exit press < CTRL + C > " << endl;
	cin.get();
	cin.get();
	system("clear");
}




// function to check duplicacy
int check_duplicate(long int r)
{
	jana_bank j;

	ifstream if1("jana.ball", ios::binary | ios::in);

	while (if1.read((char*)&j, sizeof(j)))
	{
		if (r == j.return_uidai())
		{
			cout << "DUPLICACY ALERT!!!!\n Try Again";

			if1.close();

			return 1;
		}
	}
	if1.close();
	return 0;
}




// function to create a new account in the database
void new_account()
{
	jana_bank j;
	int nrec = -1;

	ifstream if1;

	ofstream of1;

	of1.open("jana.ball", ios::binary | ios::out | ios::app);

	of1.seekp(0, ios::end);

	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

	long int n = of1.tellp();

	of1.close();

	long int r;
	cout << "\nENTER THE UIDAI NO. (the 6 digit code): \n";
	cin >> r;

	if (n == 0)
	{
		cout << "CONGRATULATIONS!! You are our First customer\n :) :) ;)\n";

		of1.open("jana.ball", ios::binary | ios::out | ios::app);

		j.add_data(r);

		of1.write((char*)&j, sizeof(j));

		of1.close();
		cout << "________________________________________________________________________";
		cout << "\n CONGRATS! Now you are a Member of 'Jana Family'\n";
		cout << "________________________________________________________________________";


		cout << "\nYOUR DETAILS ARE AS FOLLOWS:\n";

		j.display_details();

		cout << "\n****You are required to maintain a minimum balance of rs.1000****\n";
		cout << "\n\nNOTE: ";
		cout << " you are requested to remember your 4 digit pin at all times" << endl;
		cout << "\t   donot share the pin with anyone " << endl;
	}
	else
	{
		int x = check_duplicate(r);

		if (x == 0)
		{

			of1.open("jana.ball", ios::binary | ios::out | ios::app);

			of1.seekp(0, ios::end);

			j.add_data(r);

			of1.write((char*)&j, sizeof(j));

			of1.close();

			cout << "\n CONGRATS! now you are a member of 'Jana Family'\n";
			cout << "________________________________________________________________________";
			cout << "\nyour details are as follows:\n";

			j.display_details();

			cout << "\n\nNOTE: ";
			cout << "\t\tyou are requested to remember your 4 digit pin at all times" << endl;
			cout << "\t\tdonot share the pin with anyone " << endl;
		}

	}

	paktc();
}






// function to delete an account from the database
void deactivate_account()
{
	jana_bank j;

	long int a;

	int b;

	cout << "\nenter your customer id\n";
	cin >> a;


	ifstream if1;
	if1.open("jana.ball", ios::binary | ios::in);

	ofstream of2;
	of2.open("temp.ball", ios::binary | ios::out);

	int flag = 0;


	while (if1.read((char*)&j, sizeof(j)))
	{
		if (j.return_customer_id() == a)
		{
			cout << "\nenter your pin\n";
			cin >> b;

			if (j.return_pin() == b) {

				flag = 1 ;
				break;
			} else {
				cout << "\nWRONG PIN\n" << endl;
				of2.write((char*)&j, sizeof(j));
				flag = 2;
				break;
			}
		}
		else {
			of2.write((char*)&j, sizeof(j));
		}
	}

	if (flag == 1) {
		cout << "\nyour Jana account has been successfully deactivated\n";
	}

	else if (flag == 0) {
		cout << "\n Account Not Found !!!";
	}


	if1.close();

	of2.close();

	remove("jana.ball");

	rename("temp.ball", "jana.ball");

	paktc();

}






void show()
{
	ifstream if1;

	if1.open("jana.ball", ios::binary | ios::in);

	if1.seekg(0, ios::beg);

	jana_bank j ;

	cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout << "=======================================\n";
	cout << "UIDAI NO.        NAME            BALANCE \n";
	cout << "=======================================\n";

	while (if1.read((char*)&j, sizeof(j)))
	{
		j.display_data();
	}

	paktc();

}






// function to remove money from your account and update in the database
void withrawal()
{
	long int n ;
	int amt, p;
	cout << "Customer id  : ";
	cin >> n;

	cout << "Enter amount to be withdrawn  : ";
	cin >> amt;

	cout << "Enter PIN  : ";
	cin >> p;

	fstream f1;

	f1.open("jana.ball", ios::binary | ios::in | ios::ate | ios::out);

	f1.seekg(0, ios::beg);

	int c = 1;
	jana_bank j;

	bool flag = false;

	while (f1.read((char*)&j, sizeof(j)))
	{
		c++;
		if (n == j.return_customer_id())
		{
			cout << "Account found! Transaction initiated\n";

			if (amt <= j.return_balance() - 1000)
			{

				if (p == j.return_pin())
				{
					cout << "Transaction successful\n";

					j.withdraw_money(amt);

					f1.seekp((c - 2)*sizeof(j), ios::beg);
					f1.write((char*)&j, sizeof(j));

					flag = true;
					break;
				}
				else
				{
					cout << "INCORRECT PIN. TRY AGAIN!";
					break;
				}
			}
			else
			{	cout << " transaction FAILED" << endl;
				cout << "Not enough balance";
				break;
			}
		}
		if (!flag) {
			cout << "Account not found! Transaction terminated";
		}

	}

	f1.close();

	paktc();
}







// function to add money to your account and update in the database
void deposit()
{
	long int amt, p, n;

	cout << "Customer id  : ";
	cin >> n;

	cout << "Enter amount to be deposited  : ";
	cin >> amt;

	cout << "Enter PIN  : ";
	cin >> p;

	fstream f1;

	f1.open("jana.ball", ios::binary | ios::in | ios::ate | ios::out);

	f1.seekg(0, ios::beg);

	jana_bank j;

	bool flag = false;

	while (f1.read((char*)&j, sizeof(j)))
	{
		if (n == j.return_customer_id())
		{
			cout << "\naccount found! process initiated";

			if (p == j.return_pin())
			{
				cout << "\ndeposit successful" << endl;

				j.deposit_money(amt);

				int x = f1.tellg();

				f1.seekp(x - sizeof(j), ios::beg);

				f1.write((char*)&j, sizeof(j));

				flag = true;
				break;
			}
			else
			{
				cout << "incorrect pin!";

				break;
			}
		}

	}
	if (!flag) {
		cout << "\naccount not found";
	}

	f1.close();

	paktc();

}






// function to transfer money between two accounts
// and update the same in the database
void transfer()
{
	jana_bank a, b;

	long int m, n = 0, amt, Q, X;

	int c;

	int flag = 0, flag2 = 0;

	cout << "Your customer id 	: ";
	cin >> m;

	cout << "PIN 	: ";
	cin >> c;

	fstream f1;

	f1.open("jana.ball", ios::binary | ios::in | ios::out | ios::ate);

	f1.seekg(0, ios::beg);

	while (f1.read((char*)&a, sizeof(a)))
	{
		if ((a.return_customer_id() == m) && (a.return_pin() == c))
		{
			cout << "Amount : ";
			cin >> amt;

			if (a.return_balance() - 1000 < amt)
			{
				flag = 2;

				break;
			}
			else
			{
				Q = f1.tellg();

				flag = 1;

				break;
			}
		}
	}

	if (flag == 0)
	{
		cout << "\n Account not Found !!";
		cout << "\n Try again with a valid account...";
	}


	else if (flag == 2)
	{
		cout << "\n Insufficient Balance !!!";
		cout << "\n Try Again !!";
	}


	else if (flag == 1)
	{
		cout << "ACC FOUND ! PROCESS INITIATED" << endl;

		cout << "third party customer id : ";
		cin >> n;

		f1.seekg(0, ios::beg);

		while (f1.read((char*)&b, sizeof(b)))
		{

			if (b.return_customer_id() == n)
			{
				X = f1.tellg();
				cout << "\n second acc found and transaction comp" << endl;

				cout << " YOUR ";
				a.withdraw_money(amt);
				cout << endl;

				f1.seekp(Q - sizeof(a));

				f1.write((char*)&a, sizeof(a));

				cout << " THEIR ";
				b.deposit_money(amt);

				f1.seekp(X - sizeof(b));

				f1.write((char*)&b, sizeof(b));

				flag2 = 1;

				break;
			}
		}

		if (flag2 == 0)
		{
			cout << "\n Incorrect Recipient Account number..." << endl;
			cout << "\n Try Again..." << endl;
		}
	}

	f1.close();

	paktc();

}






// function to modify the details of account in the database
void modify_account()
{
	int flag = 0;

	long int n;

	cout << "\n Enter your customer id 	: ";
	cin >> n;

	jana_bank A;

	fstream f1;

	f1.open("jana.ball", ios::binary | ios::in | ios::out);

	while (f1.read((char *) &A, sizeof(A)) && (flag == 0))

	{
		if (A.return_customer_id() == n)
		{
			cout << "\n Your curent details are as follows" << endl;

			A.display_data();

			cout << "\n\nEnter The New Details of account" << endl;

			A.modify();

			int pos = (-1) * sizeof(A);

			f1.seekp(pos, ios::cur);

			f1.write((char *) &A, sizeof(A));

			cout << "\n\t Record Updated !" << endl;

			flag = 1;
		}
	}

	f1.close();

	if (flag == 0) {
		cout << "\n\n Record Not Found !" << endl;
	}

	paktc();

}
