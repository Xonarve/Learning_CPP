#include "stdafx.h"
#include "dma.h"

dmaABC::dmaABC(const char* l, int r) {
	label = new char[strlen(l) + 1];
	strcpy_s(label, strlen(l) + 1, l);
	rating = r;
}

dmaABC::dmaABC(const dmaABC& rs) {
	label = new char[strlen(rs.label) + 1];
	strcpy_s(label, strlen(rs.label) + 1, rs.label);
	rating = rs.rating;
}

dmaABC::~dmaABC() {
	delete[] label;
}

dmaABC& dmaABC::operator=(const dmaABC& rs) {
	if (this == &rs)
		return *this;
	delete[] label;
	label = new char[strlen(rs.label) + 1];
	strcpy_s(label, strlen(rs.label) + 1, rs.label);
	rating = rs.rating;
	return *this;
}

void dmaABC::View() const {
	std::cout << "Label: " << label << std::endl
		<< "Rating: " << rating << std::endl;
}

std::ostream& operator<<(std::ostream& os, const dmaABC& rs) {
	os << "Label: " << rs.label << std::endl;
	os << "Rating: " << rs.rating << std::endl;
	return os;
}

baseDma::baseDma(const char* l, int r) : dmaABC(l, r) {}

baseDma::baseDma(const baseDma& rs) : dmaABC(rs) {}

baseDma& baseDma::operator=(const baseDma& rs) {
	dmaABC::operator=(rs);
	return *this;
}

void baseDma::View() const {
	dmaABC::View();
}

std::ostream& operator<<(std::ostream& os, const baseDma& rs) {
	os << (const dmaABC&)rs;
	return os;
}

lacksDma::lacksDma(const char* c, const char* l,
	int r) : dmaABC(l, r) {
	strcpy_s(color, COL_LEN, c);
}

lacksDma::lacksDma(const dmaABC& rs, const char* c) : dmaABC(rs) {
	strcpy_s(color, COL_LEN, c);
}

void lacksDma::View() const {
	dmaABC::View();
	std::cout << "Color: " << color << std::endl;
}

std::ostream& operator<<(std::ostream& os, const lacksDma& ls) {
	os << (const dmaABC&)ls;
	os << "Color: " << ls.color << std::endl;
	return os;
}

hasDma::hasDma(const char* s, const char* l,
	int r) : dmaABC(l, r) {
	style = new char[strlen(s) + 1];
	strcpy_s(style, strlen(s) + 1, s);
}

hasDma::hasDma(const dmaABC& rs, const char* s) : dmaABC(rs) {
	style = new char[strlen(s) + 1];
	strcpy_s(style, strlen(s) + 1, s);
}

hasDma::hasDma(const hasDma& hs) : dmaABC(hs) {
	style = new char[strlen(hs.style) + 1];
	strcpy_s(style, strlen(hs.style) + 1, hs.style);
}

hasDma::~hasDma() {
	delete[] style;
}

hasDma& hasDma::operator=(const hasDma& hs) {
	if (this == &hs)
		return *this;
	dmaABC::operator=(hs);
	delete[] style;
	style = new char[strlen(hs.style) + 1];
	strcpy_s(style, strlen(hs.style) + 1, hs.style);
	return *this;
}

void hasDma::View() const {
	dmaABC::View();
	std::cout << "Style: " << style << std::endl;
}

std::ostream& operator<<(std::ostream& os, const hasDma& hs) {
	os << (const dmaABC&)hs;
	os << "Style: " << hs.style << std::endl;
	return os;
}