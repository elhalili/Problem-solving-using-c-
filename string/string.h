#ifndef STRING_H
#define STRING_H
#include <iostream>

class String
{
private:
    int length;
    char* data;
public:
    static bool isAlpha(char);
    static bool isSpace(char);
    static char* strncpy(char* const, char* const, int);
    String();
    ~String();
    String(int);
    String(const char*);
    String(const String&);
    String(char);
    String& operator=(const String&);
    String operator +(const String&);
    char operator [](int) const;
    char& operator [](int);
    friend std::ostream& operator <<(std::ostream&, const String&);
    friend std::istream& operator >>(std::istream&, String&);
    String& concat(const String&);
    String& concat(const char*);
    String& concat(char);
    int getLength() const;
    char charAt(int) const;
    //return ascii code
    int charCodeAt(int) const;
    bool endsWith(const String&) const;
    bool endsWith(const char*) const;
    bool endsWith(char) const;
    bool includes(const String&) const;
    bool includes(const char*) const;
    bool includes(char) const;
    bool startsWith(const String&) const;
    bool startsWith(const char*) const;
    bool startsWith(char) const;
    String toLowerCase() const;
    String toUpperCase() const;
    String substr(int = 0, int = 0) const;
    String substring(int = 0, int = 0) const;
    String slice(int = 0, int = 0) const;
    int indexOf(const String&) const;
    int indexOf(const char*) const;
    int indexOf(char) const;
    int lastIndexOf(const String&) const;
    int lastIndexOf(const char*) const;
    int lastIndexOf(char) const;
    String repeat(int = 0) const;
    String trim() const;
};
#endif