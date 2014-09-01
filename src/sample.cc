#include "general_settings.h"
using namespace std;

unordered_map<int, SingleCard*> cards;

int 
main(int argc, char** argv){

    init_cards();
    for(unordered_map<int, SingleCard*>::iterator _it = cards.begin(); _it != cards.end(); _it++){
        cout<<_it -> first<<", "<<_it -> second -> Name<<endl;
    }


    return 0;
}

