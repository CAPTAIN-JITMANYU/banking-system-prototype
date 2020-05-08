/*
* @Author: jitmanyu
* @Date:   2020-05-06 02:44:48
* @Last Modified by:   jitmanyu
* @Last Modified time: 2020-05-08 22:05:28
*/
#include "jana_bank.h"

#include "jana_accounting.h"


int main()
{

	char c;

	do
	{
		cout << "**********   WELCOME TO JANA BANK SERVICES!   **********" << endl;

		int a;

		cout << "\n\n********************************************************" << endl;

		cout << "                         MENU                           " << endl;

		cout << "********************************************************" << endl;

		cout << "* 1 * ADD A NEW ACCOUNT  *      Press 1 to Select       *" << endl;
		cout << "*********************************************************" << endl;

		cout << "* 2 * WITHDRAW AMOUNT    *      Press 2 to Select       *" << endl;
		cout << "*********************************************************" << endl;

		cout << "* 3 * DEPOSIT AMOUNT     *      Press 3 to Select       *" << endl;
		cout << "*********************************************************" << endl;

		cout << "* 4 * TRANSFER AMOUNT    *      Press 4 to Select       *" << endl;
		cout << "*********************************************************" << endl;

		cout << "* 5 * DEACTIVATE ACCOUNT *      Press 5 to Select       *" << endl;
		cout << "*********************************************************" << endl;

		cout << "* 6 * SHOW DETAILS       *      Press 6 to Select       *" << endl;
		cout << "*********************************************************" << endl;

		cout << "* 7 * MODIFY DETAILS     *      Press 7 to Select       *" << endl;
		cout << "*********************************************************" << endl;



		cout << "YOUR RESPONSE:";
		cin >> a;

		switch (a)
		{
		case 1: new_account();
			break;

		case 2: withrawal();
			break;

		case 3: deposit();
			break;

		case 4: transfer();
			break;

		case 5: deactivate_account();
			break;

		case 6: show();
			break;

		case 7: modify_account();
			break;

		}

	} while (1);

	return 0;
}
