#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>

#include "stringtrim.h"

using namespace std;

struct grammar_left
{
    string name;
    vector<string>* addr;
    int size;
};

class grammar
{
public:
    grammar();
    bool push(string g);
    void print();
    bool is_sGrammar();
    void parser(string inpString, string parsed, string ans);
    void sGrammarParse(string start,string remain);
    void cyk(string inp);

private:
    vector<vector<string>*> rules;
    list<grammar_left*> variables;

    vector<string>* grammarSlices(string s);
    vector<string>* ruleAddr(string ide);
    bool sGrammar_check(vector<string>* rule);
    void variablesOrganizer();
    string findCharInRule(string ide, vector<string> *rules);
    string finRule(string ide);

};

#endif // GRAMMAR_H
