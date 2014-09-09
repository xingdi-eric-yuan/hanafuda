#include "general_settings.h"
#include "../ai/ai1/header/ai.h"
using namespace std;

vector<int> points;

void new_match(bool oya, int &Point_1, int &Point_2){
	vector<int> yama(48, 0); // 山札
	vector<int> te_1(48, 0); // 手札_1
	vector<int> te_2(48, 0); // 手札_2
	vector<int> yaku_table_1(48, 0); // 役札_1 
	vector<int> yaku_table_2(48, 0); // 役札_2
	vector<int> ba(48, 0); // 場札

    init_cards(yama, te_1 ,te_2, yaku_table_1, yaku_table_2, ba);
    deal_cards(yama, te_1 ,te_2, yaku_table_1, yaku_table_2, ba);

	int step = 0;
	bool order = oya;
	bool end_game = false;
	int p1 = 0;
	int p2 = 0;
	int cache = 0;
	int enemy_te_amount = 0;
	// use two AIs in turn.
//	int test = ai1::dosomething(yama);
//	cout<<test<<endl;
	
	while(1){
		if(card_amount(te_1) == 0 || card_amount(te_2) == 0){ // Oya-Ken
			if(oya) Point_1 += 6;
			else Point_2 += 6;
			break;
		}
		if(order == PLAYER_1){
			enemy_te_amount = card_amount(te_2);
			ai1 ai;
			ai.enemy_te_amount = enemy_te_amount;
			int which = ai.move_1(te_1, yaku_table_1, yaku_table_2, ba);
			set_zero(te_1, which);
			vector<int> same = find_same_month(which, ba);
			if(same.empty()){
				set_one(ba, which);
			}elif(same.size() == 1){
				set_two(yaku_table_1, which);
				set_zero(ba, same[0]);
				set_two(yaku_table_1, same[0]);
			}else{
				int which2 = ai.move_2(te_1, yaku_table_1, yaku_table_2, ba, which, same);
				set_two(yaku_table_1, which);
				set_zero(ba, which2);
				set_two(yaku_table_1, which2);
			}
			same.clear();
			cache = random_choose(yama);
			same = find_same_month(cache, ba);
			set_zero(yama, cache);
			if(same.empty()){
				set_one(ba, cache);
			}elif(same.size() == 1){
				set_two(yaku_table_1, cache);
				set_zero(ba, same[0]);
				set_two(yaku_table_1, same[0]);
			}else{
				int which2 = ai.move_2(te_1, yaku_table_1, yaku_table_2, ba, cache, same);
				set_two(yaku_table_1, cache);
				set_zero(ba, which2);
				set_two(yaku_table_1, which2);
			}
			int tmp = yaku_calculate(yaku_table_1);
			/*
			cout<<"step = "<<step<<", yaku_1 = "<<tmp<<endl;
			if(tmp exists){
				for(int j = 0; j < yaku_table_1.size(); j++){
					if(yaku_table_1[j] exists) cout<<"    yaku: "<<j<<endl;
				}
			}
			*/
			if(tmp exists){
				end_game = ai.move_3(te_1, yaku_table_1, yaku_table_2, ba);	
				if(end_game){
					Point_1 += tmp;
					oya = PLAYER_1;
					break;
				}else{
					koi_koi(yaku_table_1);
				}
			}
		}else{
			enemy_te_amount = card_amount(te_1);
			ai1 ai;
			ai.enemy_te_amount = enemy_te_amount;
			int which = ai.move_1(te_2, yaku_table_2, yaku_table_1, ba);
			set_zero(te_2, which);
			vector<int> same = find_same_month(which, ba);
			if(same.empty()){
				set_one(ba, which);
			}elif(same.size() == 1){
				set_two(yaku_table_2, which);
				set_zero(ba, same[0]);
				set_two(yaku_table_2, same[0]);
			}else{
				int which2 = ai.move_2(te_2, yaku_table_2, yaku_table_1, ba, which, same);
				set_two(yaku_table_2, which);
				set_zero(ba, which2);
				set_two(yaku_table_2, which2);
			}
			same.clear();
			cache = random_choose(yama);
			same = find_same_month(cache, ba);
			set_zero(yama, cache);
			if(same.empty()){
				set_one(ba, cache);
			}elif(same.size() == 1){
				set_two(yaku_table_2, cache);
				set_zero(ba, same[0]);
				set_two(yaku_table_2, same[0]);
			}else{
				int which2 = ai.move_2(te_2, yaku_table_2, yaku_table_1, ba, cache, same);
				set_two(yaku_table_2, cache);
				set_zero(ba, which2);
				set_two(yaku_table_2, which2);
			}
			int tmp = yaku_calculate(yaku_table_2);
			/*
			cout<<"step = "<<step<<", yaku_2 = "<<tmp<<endl;
			if(tmp exists){
				for(int j = 0; j < yaku_table_2.size(); j++){
					if(yaku_table_2[j] exists) cout<<"    yaku: "<<j<<endl;
				}
			}
			*/
			if(tmp exists){
				end_game = ai.move_3(te_2, yaku_table_2, yaku_table_1, ba);	
				if(end_game){
					Point_2 += tmp;
					oya = PLAYER_2;
					break;
				}else{
					koi_koi(yaku_table_2);
				}
			}
		}

		order = !order;
		++step;
	}
}

void game(){

	init_rules();
	bool oya = PLAYER_1; // 親
	int Point_1 = 10;
	int Point_2 = 10;
	new_match(oya, Point_1, Point_2);

	cout<<"end game, p1 = "<<Point_1<<", p2 = "<<Point_2<<endl;

}


int main(int argc, char** argv){

	game();

    return 0;
}

