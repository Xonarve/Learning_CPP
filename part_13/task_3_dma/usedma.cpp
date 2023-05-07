// acctabc.h.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "dma.h"
#include <string>

const int Clients = 4;

int _tmain(int argc, _TCHAR* argv[])
{
	using std::cout;
	using std::cin;
	using std::endl;

	dmaABC* pclients[Clients];
	char templabel[100];
	int tempr;

	for (int i = 0; i < Clients; ++i) {
		cout << "Label: ";
		//getline(cin, templabel);
		cin.getline(templabel, 100);
		cout << "Rating: ";
		cin >> tempr;
		char kind;
		cout << "1 for baseDma, 2 to lacksDma, 3 to hasDma: ";
		while (cin >> kind && (kind != '1' && kind != '2' && kind != '3'))
			cout << "Enter either 1 or 2 or 3: ";
		if (kind == '1')
			pclients[i] = new baseDma(templabel, tempr);
		else if (kind == '2') {
			char color_ptr[50];
			cout << "Color: ";
			cin >> color_ptr;
			pclients[i] = new lacksDma(color_ptr, templabel, tempr);
		}
		else {
			char style_ptr[50];
			cout << "Style: ";
			cin >> style_ptr;
			pclients[i] = new hasDma(style_ptr, templabel, tempr);
		}
		while (cin.get() != '\n')
			continue;
	}
	cout << endl;
	for (int i = 0; i < Clients; ++i) {
		pclients[i]->View();
		//cout << *pclients[i];
		cout << endl;
	}
	for (int i = 0; i < Clients; ++i)
		delete pclients[i];
	cout << "Done.\n";
	cin.get();
	return 0;
}

