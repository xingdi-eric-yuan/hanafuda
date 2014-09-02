#include "helper.h"

using namespace std;

void move_top(vector<SingleCard*> &_from, vector<SingleCard*> &_to, int amount = 1){
	if(amount == 0) return;
	if(_from.size() < amount){
		cout<<"error: there is no enough cards to move..."<<endl;
	}else{
		for(int i = 0; i < amount; i++){
			_to.push_back(_from[0]);
			_from.erase(_from.begin());
		}
	}
}

void move(vector<SingleCard*> &_from, vector<SingleCard*> &_to, int loc, int amount = 1){
	if(amount == 0) return;
	if(loc == 0){
		move_top(_from, _to, amount);
	}else{
		if(loc >= _from.size()){
			cout<<"error: wrong move location..."<<endl;
		}elif(_from.size() + loc < amount){
			cout<<"error: there is no enough cards to move..."<<endl;
		}else{
			for(int i = 0; i < amount; i++){
				_to.push_back(_from[loc]);
				_from.erase(_from.begin() + loc);
			}
		}
	}
}

void reshuffle(	vector<SingleCard*> &te_1,
				vector<SingleCard*> &te_2, 
				vector<SingleCard*> &yaku_table_1, 
				vector<SingleCard*> &yaku_table_2, 
				vector<SingleCard*> &ba, 
				vector<SingleCard*> &yama){
	move_top(te_1, yama, te_1.size());
	move_top(te_2, yama, te_2.size());
	move_top(yaku_table_1, yama, yaku_table_1.size());
	move_top(yaku_table_2, yama, yaku_table_2.size());
	move_top(ba, yama, ba.size());
	random_shuffle(yama.begin(), yama.end());
}


