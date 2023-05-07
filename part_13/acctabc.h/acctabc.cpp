#include "stdafx.h"
#include "acctabc.h"
using std::cout;
using std::endl;
using std::ios_base;
using std::string;

AcctABC::AcctABC(const std::string& s, long an, double bal) : fullName(s),
acctNum(an), balance(bal) {}

void AcctABC::Deposit(double amt) {
	if (amt < 0)
		cout << "Negative deposit not allowed; "
		<< "deposit is cancelled.\n";
	else
		balance += amt;
}

void AcctABC::Withdraw(double amt) {
	balance -= amt;
}

AcctABC::Formatting AcctABC::SetFormat() const {
	Formatting f;
	f.flag = cout.setf(ios_base::fixed, ios_base::floatfield);
	f.pr = cout.precision(2);
	return f;
}

void AcctABC::restore(Formatting& f) const {
	cout.setf(f.flag, ios_base::floatfield);
	cout.precision(f.pr);
}

void Brass::Withdraw(double amt) {
	if (amt > Balance())
		cout << "Withdraw amount of $" << amt
		<< " exeeds your balance.\n"
		<< "Withdraw cancelled.\n";
	else
		AcctABC::Withdraw(amt);
}

void Brass::ViewAcct() const {
	Formatting f = SetFormat();
	cout << "Brass Client: " << FullName() << endl
		<< "Account number: " << AcctNum() << endl
		<< "Balance: $" << Balance() << endl;
	restore(f);
}

BrassPlus::BrassPlus(const std::string& s, long an, double bal,
	double ml, double r) : AcctABC(s, an, bal), maxLoan(ml), rate(r), owesBank(0.0) {}

BrassPlus::BrassPlus(const Brass& ba, double ml, double r) : 
AcctABC(ba), maxLoan(ml), rate(r), owesBank(0.0) {}

void BrassPlus::ViewAcct() const {
	Formatting f = SetFormat();
	cout << "BrassPlus Client: " << FullName() << endl
		<< "Account number: " << AcctNum() << endl
		<< "Balance: $" << Balance() << endl
		<< "Maximum loan: $" << maxLoan << endl
		<< "Owed to bank: $" << owesBank << endl;
		cout.precision(3);
		cout << "Loan Rate: " << 100 * rate << "%\n";
	restore(f);
}

void BrassPlus::Withdraw(double amt) {
	Formatting f = SetFormat();
	double bal = Balance();
	if (amt < bal)
		AcctABC::Withdraw(amt);
	else if (amt <= bal + maxLoan - owesBank) {
		double advance = amt - bal;
		owesBank += advance * (1.0 + rate);
		cout << "Bank advance: $" << advance << endl;
		cout << "Finance charge: $" << advance * rate << endl;
		Deposit(advance);
		AcctABC::Withdraw(amt);
	}
	else
		cout << "Credit limit exceeded. Transaction cancelled.\n";
	restore(f);
}