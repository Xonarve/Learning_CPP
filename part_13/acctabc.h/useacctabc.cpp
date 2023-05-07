// acctabc.h.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "acctabc.h"

const int Clients = 1;

int _tmain(int argc, _TCHAR* argv[])
{

	using std::cout;
	using std::cin;
	using std::endl;

	AcctABC* pclients[Clients];
	std::string temp;
	long tempnum;
	double tempbal;
	char kind;
	
	for (int i = 0; i < Clients; ++i) {
		cout << "Name: ";
		getline(cin, temp);
		cout << "Account number: ";
		cin >> tempnum;
		cout << "Opening balance: ";
		cin >> tempbal;
		cout << "1 for Brass, 2 to BrassPlus: ";
		while (cin >> kind && (kind != '1' && kind != '2'))
			cout << "Enter either 1 or 2: ";
		if (kind == '1')
			pclients[i] = new Brass(temp, tempnum, tempbal);
		else {
			double tmax, trate;
			cout << "Overdraft limit: $";
			cin >> tmax;
			cout << "Rate: as a decimal fraction: ";
			cin >> trate;
			pclients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
		}
		while (cin.get() != '\n')
			continue;
	}
	cout << endl;
	for (int i = 0; i < Clients; ++i) {
		pclients[i]->ViewAcct();
		cout << endl;
	}
	for (int i = 0; i < Clients; ++i)
		delete pclients[i];
	cout << "Done.\n";
	cin.get();
	return 0;
}

