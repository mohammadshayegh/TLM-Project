#include <iostream>
#include "grammar.h"
#include "stringtrim.h"

using namespace std;

int main()
{
    string g;
    string t;
    grammar gram;




    gram.push("S => aS | aA ");
    gram.push("A => dA | cB ");
    gram.push("B => g ");
    gram.push("null");

//    gram.parser("abcg","S",t);
//    cout << gram.is_sGrammar() << endl;

    gram.sGrammarParser("S","abcg");

    return 0;
}
/*


    //    while(1)
    //    {
    //        getline(cin,g);
    //        if(!gram.push(g))break;
    //    }

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
