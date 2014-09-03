#include "general_settings.h"
#include "../ai/ai1/header/ai.h"
using namespace std;

vector<int> points;

void new_match(bool oya, int Point_1, int Point_2){
	vector<int> yama(48, false); // 山札
	vector<int> te_1(48, false); // 手札_1
	vector<int> te_2(48, false); // 手札_2
	vector<int> yaku_table_1(48, false); // 役札_1 
	vector<int> yaku_table_2(48, false); // 役札_2
	vector<int> ba(48, false); // 場札

    init_cards(yama, te_1 ,te_2, yaku_table_1, yaku_table_2, ba);
    deal_cards(yama, te_1 ,te_2, yaku_table_1, yaku_table_2, ba);

	int step = 0;
	bool order = oya;
	bool end_game = false;
	int p1 = 0;
	int p2 = 0;
	// use two AIs in turn.

//	int test = ai1::dosomething(yama);
//	cout<<test<<endl;
	
	while(1){
		if(te_1.empty() && te_2.empty()){ // Oya-Ken
			if(oya) Point_1 += 6;
			else Point_2 += 6;
			break;
		}
		if(order == PLAYER_1){

			end_game = player_1_AI();

			if(end_game){
				int tmp = yaku_calculate(yaku_table_1);
				if(tmp exists){
					Point_1 += tmp;
					oya = PLAYER_1;
				}else{
					// penalty
					Point_2 += 6;
					oya = PLAYER_2;
				}
				break;
			}else{
				koi_koi(yaku_table_1);
			}
		}else{
			end_game = player_2_AI();
			if(end_game){
				int tmp = yaku_calculate(yaku_table_2);
				if(tmp exists){
					Point_2 += tmp;
					oya = PLAYER_2;
				}else{
					// penalty
					Point_1 += 6;
					oya = PLAYER_1;
				}
				break;
			}else{
				koi_koi(yaku_table_2);
			}
		}
		order = !order;
	}
	
}

void game(){

	init_rules();
	bool oya = PLAYER_1; // 親
	int Point_1 = 10;
	int Point_2 = 10;
	new_match(oya, Point_1, Point_2);


}


int main(int argc, char** argv){

	game();

    return 0;
}

