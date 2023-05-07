#ifndef CD_H_
#define CD_H_
#include <iostream>

class Cd {
private:
	char* performers;
	char* label;
	int selections;
	double playtime;
public:
	Cd(char* s1, char* s2, int n, double x);
	Cd();
	Cd(const Cd& d);
	virtual ~Cd();
	virtual void Report() const;
	Cd& operator=(const Cd& d);
};

class Classic : public Cd {
private:
	char* main;
public:
	Classic(char* s1, char* s2, char* s3, int n, double x);
	Classic();
	Classic(const Classic& c);
	Classic(const Cd& d, char* s3);
	Classic& operator=(const Classic& c);
	virtual void Report() const;
	~Classic();
};
#endif