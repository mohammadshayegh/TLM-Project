#include "grammar.h"

grammar::grammar()
{

}

vector<string>* grammar::grammarSlices(string s)
{
    vector<string>* subStrings = new vector<string>;
    size_t pos = s.find("=>");

    string leftstr = s.substr(0,pos);
    subStrings->push_back(stringTrim::trim(leftstr));

    string rightStr = s.substr(pos+2,s.size());

    for(int i=0;(pos = rightStr.find("|")) != string::npos;i++)
    {
        string subStr = rightStr.substr(0,pos);
        subStrings->push_back(stringTrim::trim(subStr));
        rightStr.erase(0,pos+1);
    }

    subStrings->push_back(stringTrim::trim(rightStr));

    return subStrings;
}

vector<string> *grammar::ruleAddr(string ide)
{
    for (auto n : variables)
    {
        if(n->name == ide)
            return n->addr ;
    }

    return nullptr;
}

void grammar::variablesOrganizer()
{
    for (auto i = rules.begin(); i != rules.end(); ++i)
    {
        vector<string>* t = *i;
        auto j = t->begin();

        grammar_left *lg = new grammar_left;
        lg->addr = t;
        lg->name = *j;

        variables.push_back(lg);
    }
}

void grammar::parser(string inpString, string parsed,string ans)
{
    if(inpString == parsed)
    {
        cout << ans << "ok" << endl;
        return;
    }

    if(inpString.size() < parsed.size())
    {
        ans.clear();
        return;
    }

    string q = "";

    for( unsigned int i=0; i<parsed.size() ; i++ )
    {
        if( parsed[i] >= 'A' && parsed[i] <= 'Z' )
        {
            auto addr = ruleAddr( string( 1 , parsed[i] ) );

            for( unsigned int j=1 ; j<addr->size() ; j++ )
            {
                string cur = q + addr->at(j) + parsed.substr( i+1,parsed.size() );
                parser( inpString , cur , ans+cur+" => ");

            }

            break;
        }
        q += parsed[i];
    }
}

void grammar::sGrammarParser(string start, string remain)
{
    if(!is_sGrammar())
    {
        cout << " this grammar is not simple grammar " << endl;
        return;
    }

    sGrammarParse(start,remain);
}

void grammar::sGrammarParse(string firstRule, string remain)
{


    if(remain.size() == 0)
    {
        cout << "done" << endl;
        return;
    }

     cout << firstRule << "(" << remain[0] << ") -> ";

    auto addr = ruleAddr(string(1,firstRule[0]));
    string nextRule = findCharInRule(string(1,remain[0]),addr);

    sGrammarParse(nextRule,remain.substr(1,remain.size()));
}

string grammar::findCharInRule(string ide, vector<string> *rules)
{
    for (auto j = rules->begin()+1; j != rules->end(); ++j)
    {
        string rule_str = *j;
        if(string(1,rule_str[0]) == ide)
        {
            return rule_str.substr(1,rule_str.size()-1) ;
        }
    }

    return "";
}

bool grammar::push(string g)
{
    g = stringTrim::trim(g);

    if(g == "null")
    {
        variablesOrganizer();
        //        cout << is_sGrammar() << endl;
        return 0;
    }
    else
    {
        vector<string>* t = grammarSlices(g);
        rules.push_back(t);

        return 1;
    }

}

void grammar::print()
{
    for (auto i = rules.begin(); i != rules.end(); ++i)
    {
        vector<string>* t = *i;

        for (auto j = t->begin(); j != t->end(); ++j)
        {
            cout << *j << " ";
        }
        cout << endl;
    }
}

bool grammar::is_sGrammar()
{
    for (auto i = rules.begin(); i != rules.end(); ++i)
    {
        if(sGrammar_check(*i) == 0)
            return 0;
    }

    return 1;
}

bool grammar::sGrammar_check(vector<string> *rule)
{
    for (auto j = rule->begin()+1; j != rule->end(); ++j)
    {
        auto &sub_rule = *j;

        if(sub_rule[0] >= 'A' && sub_rule[0] <= 'Z' )
            return 0;
        else
        {
            for(unsigned int i=1 ; i<sub_rule.size() ; ++i)
                if(sub_rule[i] >= 'a' && sub_rule[i]<='z' )
                    return 0;
        }

    }


    for (auto j = rule->begin()+1; j != rule->end(); ++j)
    {
        auto &sub_rule = *j;

        for (auto k = j+1; k != rule->end(); ++k)
        {
//            cout << sub_rule[0] << " - " << (*k)[0] << endl;
            if(sub_rule[0] == (*k)[0])
                return 0;
        }

    }


    return 1;
}
