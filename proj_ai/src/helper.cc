#include "helper.h"

using namespace std;

void init_rules(){

	points.resize(48, 1);

	// five 20-point cards
	points[MATSU_NI_TSURU] = 20;
	points[SAKURA_NI_MAKU] = 20;
	points[SUSUKI_NI_TSUKI] = 20;
	points[YANAGI_NI_ONO_NO_MICHIKAZE] = 20;
	points[KIRI_NI_HOUOU] = 20;

	// nine 10-point cards
	points[UME_NI_UGUISU] = 10;
	points[FUJI_NI_YATSUHASHI] = 10;
	points[AYAME_NI_YATSUHASHI] = 10;
	points[BOTAN_NI_CHO] = 10;
	points[HAGI_NI_INOSHISHI] = 10;
	points[SUSUKI_NI_KALI] = 10;
	points[KIKU_NI_SAKAZUKI] = 10;
	points[MOMIJI_NI_SHIKA] = 10;
	points[YANAGI_NI_TSUBAA] = 10;

	// ten 5-point cards
	points[MATSU_NI_AKATAN] = 5;
	points[UME_NI_AKATAN] = 5;
	points[SAKURA_NI_AKATAN] = 5;
	points[FUJI_NI_TANZAKU] = 5;
	points[AYAME_NI_TANZAKU] = 5;
	points[HAGI_NI_TANZAKU] = 5;
	points[YANAGI_NI_TANZAKU] = 5;
	points[BOTAN_NI_AOTAN] = 5;
	points[KIKU_NI_AOTAN] = 5;
	points[MOMIJI_NI_AOTAN] = 5;

}

void init_cards(card_vec& yama, card_vec& te_1 ,card_vec& te_2,
                card_vec& yaku_table_1, card_vec& yaku_table_2, card_vec& ba){

    for(int i = 0; i < yama.size(); i++){
        yama[i] = 1;
        te_1[i] = 0;
        te_2[i] = 0;
        yaku_table_1[i] = 0;
        yaku_table_2[i] = 0;
        ba[i] = 0;
    }   
}

void deal_cards(card_vec& yama, card_vec& te_1 ,card_vec& te_2,
                card_vec& yaku_table_1, card_vec& yaku_table_2, card_vec& ba){

	random_move(yama, te_1, 8);
	random_move(yama, te_2, 8);
	random_move(yama, ba, 8);
}

void move(card_vec& _from, card_vec& _to, int which){
	if(_from[which] exists){
		_to[which] = 1;
		_from[which] = 0;
	}
}

void random_move(card_vec& _from, card_vec& _to, int amount){
	if(card_amount(_from) < amount) return;
	int i = 0;
	while(1){
		if(i >= 8) break;
        int randomNum = rand() % _from.size();
        //cout<<"random number is "<<randomNum<<endl;
        if(_from[randomNum] exists){
        	_from[randomNum] = 0;
        	_to[randomNum] = 1;
        	++ i;
        }
	}
}

void random_move(card_vec& _from, card_vec& _to){
	if(card_amount(_from) < 1) return;
	while(1){
        int randomNum = rand() % _from.size();
        if(_from[randomNum] exists){
        	_from[randomNum] = 0;
        	_to[randomNum] = 1;
        	break;
        }
	}
}

void random_move_except(card_vec& _from, card_vec& _to, int amount, month_vec except){
	if(card_amount(_from) < amount) return;
	int i = 0;
	while(1){
		if(i >= 8) break;
        int randomNum = rand() % _from.size();
        //cout<<"random number is "<<randomNum<<endl;
        if(except[get_month(randomNum)] == 0 && _from[randomNum] exists){
        	_from[randomNum] = 0;
        	_to[randomNum] = 1;
        	++ i;
        }
	}
}

int random_choose(card_vec& _from){
	int res = -1;
	if(card_amount(_from) < 1) return res;
	while(1){
        int randomNum = rand() % _from.size();
        if(_from[randomNum] exists){
        	res = randomNum;
        	break;
        }
	}
	return res;
}

void set_zero(card_vec& vec, int which){
	vec[which] = 0;
}

void set_one(card_vec& vec, int which){
	vec[which] = 1;
}

void set_two(card_vec& vec, int which){
	vec[which] = 2;
}

void set_zero(card_vec& vec){
	for(int i = 0; i < vec.size(); i++) vec[i] = 0;
}

void set_one(card_vec& vec){
	for(int i = 0; i < vec.size(); i++) vec[i] = 1;
}

void set_two(card_vec& vec){
	for(int i = 0; i < vec.size(); i++) vec[i] = 2;
}

int card_amount(card_vec& vec){
	int res = 0;
	for(int i = 0; i < vec.size(); i++){
		if(vec[i] != 0) ++res;
	}
	return res;
}

void koi_koi(card_vec& vec){
	for(int i = 0; i < vec.size(); i++){
		if(vec[i] != 0) vec[i] = 1;
	}
}

bool is_same_month(int a, int b){
	if(a / 4 == b / 4) return true;
	else return false;
}

card_vec find_same_month(int a, card_vec& vec){
	card_vec res;
	for(int i = 0; i < vec.size(); i++){
		if(vec[i] exists && is_same_month(a, i)){
			res.push_back(i);
		}
	}
	return res;
}

card_vec get_yama_enemy_te(card_vec &te, card_vec &yaku_table_mine, card_vec &yaku_table_enemy, card_vec &ba){

	card_vec res(48, 1);
	for(int i = 0; i < 48; i++){
		if(te[i] == 1) res[i] = 0;
		if(yaku_table_mine[i] == 1) res[i] = 0;
		if(yaku_table_enemy[i] == 1) res[i] = 0;
		if(ba[i] == 1) res[i] = 0;
	}
	return res;
}

int get_month(int card){
	return card / 4;
}

void guess_enemy_te(card_vec yama_te, card_vec &yama, card_vec& te, card_vec& yaku_table_enemy, int te_amount){

	month_vec except(12, 0);
	for(int i = 0; i < yaku_table_enemy.size(); i++){
		if(yaku_table_enemy[i] exists) except[get_month(i)] = 1;
	}
	random_move_except(yama_te, te, te_amount, except);
	yama = yama_te;
}




















