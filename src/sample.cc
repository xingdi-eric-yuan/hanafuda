#include "general_settings.h"
using namespace std;

vector<SingleCard *> yama; // 山札
vector<SingleCard *> te_1; // 手札_1
vector<SingleCard *> te_2; // 手札_2
vector<SingleCard *> yaku_table_1;   // 役札_1 
vector<SingleCard *> yaku_table_2;   // 役札_2
vector<SingleCard *> ba;   // 場札
bool oya; // 親
int Point_1;
int Point_2;


void new_match(){

	reshuffle(te_1, te_2, yaku_table_1, yaku_table_2, ba, yama);
	move_top(yama, te_1, 8);
	move_top(yama, te_2, 8);
	move_top(yama, ba, 8);
	int step = 0;
	bool order = oya;
	bool end_game = false;
	int p1 = 0;
	int p2 = 0;
	// use two AIs in turn.
	while(1){
		if(te_1.empty() && te_2.empty()){ // Oya-Ken
			if(oya) Point_1 += 6;
			else Point_2 += 6;
			break;
		}
		if(order == PLAYER_1){
			end_game = player_1_AI();
			if(end_game){
				Point_1 += yaku_calculate();
				oya = PLAYER_1;
				break;
			}
		}else{
			end_game = player_2_AI();
			if(end_game){
				Point_2 += yaku_calculate();
				oya = PLAYER_2;
				break;
			}
		}
		order = !order;
	}
}


void game(){
	oya = PLAYER_1;
	Point_1 = 10;
	Point_2 = 10;
    init_cards();
	new_match();


}


int main(int argc, char** argv){

	game();

    return 0;
}

