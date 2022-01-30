
class Golf {

private:
	static const int Len = 40;
	char fullname[Len];
	int handicap;

public:
	Golf(const char* name, int hc);
	int setgolf();
	void setHandicap(int hc);
	void showgolf() const;
};