#pragma once
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;

class String {
private:
	char* str;
	size_t size;

	void copy(const char* str);
	void clear() const;
public:
	String(const char* str = "");
	String(const String& other);
	String& operator=(const String& other);
	~String();
	String(String&& other);
	String& operator=(String&& other);

	char* getString() const;
	size_t getSize()const;

	friend ostream& operator<<(ostream& out, const String& str);
	friend istream& operator>>(istream& in, String& str);

	bool isInteger();
	bool isDouble();
};