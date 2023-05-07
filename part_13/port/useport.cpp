#include "stdafx.h"
#include "port.h"

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Start: " << endl;
	Port* ptrs[3];
	ptrs[0] = new Port("Massandra", "vintage", 3);
	ptrs[1] = new Port("Another_brand", "ruby", 4);
	ptrs[0]->Show();
	cout << endl;
	ptrs[1]->Show();
	cout << endl;
	ptrs[3] = new Port;
	ptrs[3]->Show();
	cout << endl;
	ptrs[3] = ptrs[1]; //используется операция присваивания по умолчанию
	ptrs[3]->Show();
	//delete[]ptrs;

	return 0;
}

