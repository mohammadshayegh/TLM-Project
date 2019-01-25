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

    gram.cyk("baaba");


    //    gram.parser("abcg","S",t);
    //    cout << gram.is_sGrammar() << endl;

//    string  q="";
//    gram.parser("abcg","S",q);





   /* int input;



    while (1)
    {
        cout << "1. Enter grammar" << endl
             << "2. S_grammar checking " << endl
             << "3. Parse as s_grammar" << endl
             << "4. Parse with tree" << endl
             << "5. Exit" << endl;
        cin >> input;

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
            gram.sGrammarParse("S",inp);
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

            if(input == 5)
                break;

        }
    }*/

    return 0;
}





//        return 0;

/*




    S => aSb"
    A => ab | AbS | bba
    B =>  BaB | bCb| bba | abS| bba | abS
    C => aCb | ba | ab | AbS | bba | abSab | AbS | bba | abS
    null





    for(auto i=grammars.begin(); i!= grammars.end();i++){
        cout << (*i)->name[0] << " => ";
        for(int j=0; j<(*i)->size;j++)
        {
            for(int k=0; k<(*i)->gr[j]->size;k++)
                cout << (*i)->gr[j][k].name  ;
            cout << "|" ;
        }
        cout << endl;
    }
*/
