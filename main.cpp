#include <iostream>
#include "grammar.h"
#include "stringtrim.h"
#include <windows.h>

using namespace std;

int main()
{
    string g;
    string t;
    grammar gram;

    gram.push("S => AB | BC");
    gram.push("A => BA | a");
    gram.push("B => CC | b");
    gram.push("C => AB | a");
    gram.push("null");

    int input;



    while (1)
    {
        cout << "1. Enter grammar" << endl
             << "2. S_grammar checking " << endl
             << "3. Parse as s_grammar" << endl
             << "4. Parse with tree" << endl
             << "5. CYK" << endl
             << "6. Exit" << endl;
        cin >> input;

        if(input == 6)
            break;

        switch (input) {
        case 1:
        {
            cout << "enter rules : ";
            cin.ignore();
            while(1)
            {
                getline(cin,g);
                if(!gram.push(g))
                    break;
            }
        }
            break;

        case 2 :
        {
            int sch = gram.is_sGrammar();

            if(sch == 0)
                cout << "this grammar is not a s grammar! " << endl;
            else
                cout << "this grammar is a s grammar! " << endl;

        }
            break;

        case 3:
        {
            string inp;
            cout << "enter a string : ";
            cin >> inp ;
            gram.sGrammarParser("S",inp);
            cout << endl << " _____________________ " << endl;
        }
            break;

        case 4:
        {
            string inp;
            cout << "enter a string : ";
            cin >> inp ;
            gram.parser(inp,"S","");
            cout << endl << " _____________________ " << endl;
        }
            break;

        case 5:
        {
            string inp;
            cout << "enter a string : ";
            cin >> inp ;
            gram.cyk(inp);
            cout << endl << " _____________________ " << endl;
        }
            break;


        }
    }

    return 0;
}


