#include "stringtrim.h"

stringTrim::stringTrim()
{

}
string& stringTrim::ltrim(string& str )
{
    const string& chars = "\t\n\v\f\r ";
    str.erase(0, str.find_first_not_of(chars));
    return str;
}
string& stringTrim::rtrim(string& str)
{
    const string& chars = "\t\n\v\f\r ";
    str.erase(str.find_last_not_of(chars) + 1);
    return str;
}
string& stringTrim::trim(string& str)
{
    return ltrim(rtrim(str));
}
int stringTrim::charCounter(string s,char target)
{
    const char* c = s.c_str();
    int cnt=0;
    for(unsigned int i=0;i<s.size();i++)
    {
        if(c[i] == target)
            cnt++;
    }

    return cnt;
}
