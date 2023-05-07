#ifndef DMA_H_
#define DMA_H_
#include <iostream>

class dmaABC {
private:
	char* label;
	int rating;
protected:
public:
	dmaABC(const char* l = "null", int r = 0);
	dmaABC(const dmaABC& rs);
	virtual ~dmaABC();
	dmaABC& operator=(const dmaABC& rs);
	virtual void View() const = 0;
	friend std::ostream& operator<<(std::ostream& os, const dmaABC& rs);
};

class baseDma : public dmaABC {
public:
	baseDma::baseDma(const char* l = "null", int r = 0);
	baseDma::baseDma(const baseDma& rs);
	baseDma& operator=(const baseDma& rs);

	virtual void View() const;
	friend std::ostream& operator<<(std::ostream& os, const baseDma& rs);
};

class lacksDma : public dmaABC {
	static const int COL_LEN = 40;
	char color[COL_LEN];
public:
	lacksDma(const char* c = "blank", const char* l = "null",
		int r = 0);
	//int getLen() const { return COL_LEN; }
	lacksDma(const dmaABC& rs, const char* c);
	virtual void View() const;
	friend std::ostream& operator<<(std::ostream& os, const lacksDma& ls);
};

class hasDma : public dmaABC {
private:
	char* style;
public:
	hasDma(const char* s = "none", const char* l = "null",
		int r = 0);
	hasDma(const dmaABC& rs, const char* s);
	hasDma(const hasDma& hs);
	~hasDma();
	hasDma& operator=(const hasDma& hs);
	virtual void View() const;
	friend std::ostream& operator<<(std::ostream& os, const hasDma& hs);
};

#endif