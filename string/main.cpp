#include <iostream>
#include "string.h"

using std::cout;

int main() {
    String str1("Hellloo");
    String str2("lo");
    cout << str1.lastIndexOf(str2) << "\n";
    return 0;
}