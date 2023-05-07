#include "stdafx.h"
#include "cd.h"

Cd::Cd(char* s1, char* s2, int n, double x) : selections(n), playtime(x) {
	strcpy_s(performers, strlen(s1) + 1, s1);
	strcpy_s(label, strlen(s2) + 1, s2);
}

Cd::Cd() : selections(0), playtime(0.0) {
	strcpy_s(performers, strlen("no-performers") + 1, "no-performers");
	strcpy_s(label, strlen("no-label") + 1, "no-label");
}

void Cd::Report() const {
	using std::cout;
	using std::endl;
	cout << "Performers: " << performers << endl
		<< "Label: " << label << endl
		<< "Selections: " << selections << endl
		<< "Playtime: " << playtime << endl;
}

Classic::Classic(char* s1, char* s2, char* s3, int n, double x) : Cd(s1, s2, n, x) {
	strcpy_s(main, strlen(s3) + 1, s3);
}

Classic::Classic() : Cd() {
	strcpy_s(main, strlen("no-main") + 1, "no-main");
}

Classic::Classic(const Cd& d, char* s3) : Cd(d) {
	strcpy_s(main, strlen(s3) + 1, s3);
}

void Classic::Report() const {
	Cd::Report();
	std::cout << "Main: " << main << std::endl << std::endl;
}