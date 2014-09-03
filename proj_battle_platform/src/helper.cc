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

void init_cards(vector<int>& yama, vector<int>& te_1 ,vector<int>& te_2,
                vector<int>& yaku_table_1, vector<int>& yaku_table_2, vector<int>& ba){

    for(int i = 0; i < yama.size(); i++){
        yama[i] = 1;
        te_1[i] = 0;
        te_2[i] = 0;
        yaku_table_1[i] = 0;
        yaku_table_2[i] = 0;
        ba[i] = 0;
    }   
}

void deal_cards(vector<int>& yama, vector<int>& te_1 ,vector<int>& te_2,
                vector<int>& yaku_table_1, vector<int>& yaku_table_2, vector<int>& ba){

	random_move(yama, te_1, 8);
	random_move(yama, te_2, 8);
	random_move(yama, ba, 8);
}

void move(vector<int>& _from, vector<int>& _to, int which){
	if(_from[which] exists){
		_to[which] = 1;
		_from[which] = 0;
	}
}

void random_move(vector<int>& _from, vector<int>& _to, int amount){
	if(card_amount(_from) < amount) return;
	for(int i = 0; i < amount; i++){
        int randomNum = ((long)rand() + (long)rand()) % _from.size();
        if(_from[randomNum != 0]){
        	_from[randomNum] = 0;
        	_to[randomNum] = 1;
        }else --i;
	}
}

void random_move(vector<int>& _from, vector<int>& _to){
	if(card_amount(_from) < 1) return;
	while(1){
        int randomNum = ((long)rand() + (long)rand()) % _from.size();
        if(_from[randomNum != 0]){
        	_from[randomNum] = 0;
        	_to[randomNum] = 1;
        	break;
        }
	}
}

int random_choose(vector<int>& _from){
	int res = -1;
	if(card_amount(_from) < 1) return res;
	while(1){
        int randomNum = ((long)rand() + (long)rand()) % _from.size();
        if(_from[randomNum != 0]){
        	res = randomNum;
        	break;
        }
	}
}

void set_zero(vector<int>& vec, int which){
	vec[which] = 0;
}

void set_one(vector<int>& vec, int which){
	vec[which] = 1;
}

void set_two(vector<int>& vec, int which){
	vec[which] = 2;
}

int card_amount(vector<int>& vec){
	int res = 0;
	for(int i = 0; i < vec.size(); i++){
		if(vec[i] != 0) ++res;
	}
	return res;
}

void koi_koi(vector<int>& vec){
	for(int i = 0; i < vec.size(); i++){
		if(vec[i] != 0) vec[i] = 1;
	}
}

bool is_same_month(int a, int b){
	if(a / 4 == b / 4) return true;
	else return false;
}

vector<int> find_same_month(int a, vector<int>& vec){
	vector<int> res;
	for(int i = 0; i < vec.size(); i++){
		if(is_same_month(a, vec[i])){
			res.push_back(vec[i]);
		}
	}
	return res;
}


























