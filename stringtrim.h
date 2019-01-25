#ifndef STRINGTRIM_H
#define STRINGTRIM_H

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class stringTrim
{
public:
    stringTrim();
    static string& ltrim(string&);
    static string& rtrim(string&);
    static string& trim(string&);
    static int charCounter(string ,char);
    static terminalCounter();
};

#endif // STRINGTRIM_H
