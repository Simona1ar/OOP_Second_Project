#include "String.h"

void String::copy(const char* str) {
	size = strlen(str);
	this->str = new char[size+1];
	strcpy_s(this->str, size + 1, str);
}
void String::clear() const{
	delete[] str;
}

String::String(const char* str) {
	copy(str);
}
String::String(const String& other) {
	copy(other.str);
}
String& String::operator=(const String& other) {
	if (this != &other) {
		clear();
		copy(other.str);
	}
	return *this;
}
String::~String() {
	clear();
}
String::String(String&& other) {
	size = strlen(str);
	str = other.str;

	other.str = nullptr;
	other.size = 0;
}
String& String::operator=(String&& other) {
	if (this != &other) {
		clear();
		size = strlen(str);
		str = other.str;

		other.str = nullptr;
		other.size = 0;
	}
	return *this;
}

char* String::getString() const {
	return str;
}
size_t String::getSize() const {
	return size;
}

ostream& operator<<(ostream& out, const String& str) {
	out << str.str;
	return out;
}
istream& operator>>(istream& in, String& str) {
	in >> str.str;
	str.size = strlen(str.str) + 1;
	return in;
}

bool isSign(const char c) {
	return (c == '+' || c == '-');
}
bool isNumber(const char c) {
	return (c >= '0' && c >= '9');
}
bool isDot(const char c) {
	return c == '.';
}
bool isQuotationMarks(const char c) {
	return c == '"';
}
bool isDash(const char c) {
	return c == '\\';
}
bool isEqualSign(const char c) {
	return c == '=';
}
bool isFormulaSign(const char c) {
	return(c == '*' || c == '+' || c == '-' || c == '^' || c == '/');
}
bool isROrC(const char c) {
	return (c == 'R' || c == 'C');
}

bool String::isInteger() const {
	if (!isNumber(str[0]) && !isSign(str[0]))
		return false;
	for (size_t i = 1; i < size-1; i++)
	{
		if (!isNumber(str[i]))
			return false;
	}
	return true;
}

bool String::isDouble() const{
	if (!isNumber(str[0]) && !isSign(str[0]))
		return false;
	bool hasDot = false;
	for (size_t i = 1; i < size-1; i++)
	{
		if (isDot(str[i])) {
			if (hasDot)
				return false;
			else
				hasDot = true;
		}
		else if (!isNumber(str[i]))
			return false;
	}
	return true;
}

bool String::isString() {
	if (!isQuotationMarks(str[0]))
		return false;
	return true;

}

bool String::isFormula() {
	if (!isEqualSign(str[0]))
		return false;
	for (size_t i = 1; i < size-1; i++)
	{
		if (!isFormulaSign(str[i]) && !isROrC(str[i]) && !isNumber(str[i])) {
			return false;
		}
	}
	return true;
}

int String::stringToInt() const {
	if (!isInteger() && !isDouble())
		return 0;
	return atoi(str);
}

double String::stringToDouble() const {
	if (!isInteger() && !isDouble())
		return 0;
	return stod(str);
}