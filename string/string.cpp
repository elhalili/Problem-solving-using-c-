#include "string.h"

bool String::isAlpha(char c) {
    return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122));
}

bool String::isSpace(char c)
{
    return ((c == ' ') || (c == '\n') || (c == '\t') || (c == '\r') || (c == '\v') || c =='\f');
}

char* String::strncpy(char* const dest, char* const src, int n)
{
    for (int i = 0; i < n; i++)
        *(dest + i) = *(src + i);

    *(dest + n) = 0;
    return dest;
}

String::String()
{
    length = 0;
    data = NULL;
}

String::String(int size) {
    length = size;
    data = new char[length];
    data[0] = 0;
}

String::String(const char* str) {
    int i;
    for (i = 0; *(str + i); i++);
    length = i;

    data = new char[length];
    for (i = 0; i < length; i++) {
        data[i] = str[i];
    }
}

String::String(const String& str) {
    length = str.length;
    data = new char[length];

    for (int i = 0; i < length; i++) {
        data[i] = str.data[i];
    }
}

String::String(char c)
{
    length = 0;
    data = new char[1];
    data[length++] = c;
}



String::~String() {
    delete[] data;
}

String& String::operator=(const String& str) {

    delete[] data;
    length = str.length;
    data = new char[length];

    for (int i = 0; i < length; i++) {
        data[i] = str.data[i];
    }
    return *this;
}

String String::operator+(const String& str) {
    String rs(*this);
    return String(rs.concat(str));
}

char String::operator [](int index) const {
    if (index >= length) return 0;
    return data[index];
}

char& String::operator [](int index) {
    if (index >= length) return *(data + length - 1);
    return data[index];
}

std::ostream& operator<<(std::ostream& out, const String& str) {
    for (int i = 0; i < str.length; i++) {
        out << str.data[i];
    }
    return out;
}

std::istream& operator>>(std::istream& in, String& str) {
    char tmp[200];
    in >> tmp;
    str = tmp;
    printf("%p ?? %p\n", tmp, str.data);
    return in;
}

String& String::concat(const String& str) {
    char* tmp = new char[length + str.length];
    int i;
    for (i = 0; i < length; i++) {
        tmp[i] = data[i];
    }

    for (i = 0; i < str.length; i++) {
        tmp[i + length] = str.data[i];
    }

    length += str.length;
    delete data;
    data = tmp;
    return *this;
}

String& String::concat(const char* str) {
    String rs(str);

    return this->concat(rs);
}

String& String::concat(char c) {
    data[length++] = c;
    return *this;
}

int String::getLength() const {
    return length;
}

char String::charAt(int index) const {
    return operator[](index);
}

int String::charCodeAt(int index) const {
    if (index >= length) return -1;
    return data[index];
}

bool String::endsWith(const String& str) const {
    //start comparaison from the end until the str data is finished
    //point to the end of this object's data
    char* psrc;
    //point to the end of the str object's data
    char* pstr = str.data + str.length - 1;
    for (psrc = (data + length - 1); psrc > (data + length - str.length); psrc--, pstr--) {
        if (*psrc != *pstr) return false;
    }
    return true;
}

bool String::endsWith(const char* str) const {
    return endsWith(String(str));
}
bool String::endsWith(char c) const
{
    return (data[length - 1] == c);
}
/*
bool String::includes(const String& str) const {
    //pointer to data
    const char* psrc, * pstr;
    bool isTrue;
    int strlen = str.length;
    //start from this object
    for (psrc = data, pstr = str.data; (psrc - data) <= (length - strlen); psrc++) {
        //start from str object
        if (*psrc == *pstr) {
            const char* p = psrc;
            isTrue = true;
            while (((pstr - str.data) < strlen) && isTrue) {
                if (*p != *pstr) isTrue = false;
                else p++, pstr++;
            }

            if (isTrue) return true;
            pstr = str.data;
        }
    }
    return false;
}

bool String::includes(const char* str) const {
    return includes(String(str));
}
*/

bool String::includes(const String& str) const {
    char* pthis = data;
    char* pstr = str.data;
    bool isTrue;

    while (pthis < (data + length)) {
        if (*pthis == *pstr) {
            //return if the length is less
            if ((data + length - pthis) < str.length) return false;
            isTrue = true;
            //keep tracking the last position before looping with str data
            char* p = pthis;
            while ((pstr < (str.data + str.length)) && isTrue) {
                if (*pstr != *p) isTrue = false;

                p++, pstr++;
            }

            if (isTrue) return true;
            else pstr = str.data;
        }
        pthis++;
    }
    return false;
}

bool String::includes(const char* str) const {
    return includes(String(str));
}

bool String::includes(char c) const
{
    for (int i = 0; i < length; i++)
        if (data[i] == c) return true;
    return false;
}

bool String::startsWith(const String &str) const
{
    for (int i = 0; i < str.length; i++) 
        if (str[i] != data[i]) return false;

    return true;
}

bool String::startsWith(const char* str) const
{
    return startsWith(String(str));
}

bool String::startsWith(char c) const
{
    return (data[0] == c);
}

String String::toLowerCase() const {
    String rs(length);

    for (int i = 0; i < length; i++)
    {
        if ((operator[](i) >= 'A') && (operator[](i) <= 'Z')) {
            rs[i] = (operator[](i) + ('a' - 'A'));
        }
        else rs[i] = operator[](i);
    }

    return rs;
}

String String::toUpperCase() const {
    String rs(length);

    for (int i = 0; i < length; i++)
    {
        if ((operator[](i) >= 'a') && (operator[](i) <= 'z')) {
            rs[i] = (operator[](i) - ('a' - 'A'));
        }
        else rs[i] = operator[](i);
    }

    return rs;
}

String String::substr(int start, int end) const
{
    //relative member are not allowed in default parameter 
    if (end == 0) end = length - 1;
    if (start == end) return operator[](start);
    if (end - start < 0) return String();

    String str(end - start + 1);
    for (int i = 0; i < str.length; i++) {
        str[i] = operator[](start + i);
    }
    return str;
}
String String::substring(int start, int end) const
{
    if (end == 0) end = length - 1;
    if (start == end) return operator[](start);

    return substr(start, end - 1);
}
String String::slice(int start, int end) const {
    if (end == 0) end = length - 1;
    if (start == 0) return String(*this);
    if (start < 0) return substr(length + start, end);
    return substr(start, end - 1);
}
//I can build this method start from others method but the time complexity will rise
int String::indexOf(const String &str) const {
    if ((str.length == 0) && (length == 0)) return -1;
    else if (str.length > length) return -1;

    bool isTrue;
    for (int i = 0; i < length; i++) {
        if (operator[](i) == str[0]) {
            isTrue = true;
            for (int j = 0, k = i; j < str.length; j++, k++)
                if (operator[](k) != str[j]) isTrue = false;

            if (isTrue) return i;
        }
    }

    return -1;
}

int String::indexOf(const char* str) const {
    return indexOf(String(str));
}

int String::indexOf(char c) const {
    for (int i = 0; i < length; i++)
        if (operator[](i) == c) return i;
    
    return -1;
}

int String::lastIndexOf(const String& str) const{
    if ((str.length == 0) && (length == 0)) return -1;
    else if (str.length > length) return -1;

    bool isTrue;
    for (int i = length - 1; i >= 0; i--) {
        if (operator[](i) == str[str.length - 1]) {
            isTrue = true;
            int k = i;
            for (int j = str.length - 1; j >= 0; j--, k--)
                if (operator[](k) != str[j]) isTrue = false;

            if (isTrue) return (k + 1);
        }
    }

    return -1;
}

int String::lastIndexOf(const char* str) const {
    return lastIndexOf(String(str));
}

int String::lastIndexOf(char c) const {
    for (int i = length; i >= 0; i--)
        if (operator[](i) == c) return i;

    return -1;
}

String String::repeat(int n) const
{
    String rs;
    while (n >= 1) {
        rs.concat(*this);
        n--;
    }
    return rs;
}

String String::trim() const
{
    bool isTrue = true;
    char* start = data;
    char* end = (data + length - 1);

    while (isSpace(*start) && isSpace(*end) && (end >= start)) {
        if (isSpace(*start)) start++;
        if (isSpace(*end)) end--;
    }

    int len = end - start + 1;
    char* tmp = new char[len + 1];

    String rs(strncpy(tmp, start, len));

    delete[] tmp;
    return rs;
}
