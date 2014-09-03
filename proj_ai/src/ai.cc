#include "ai.h"

using namespace std;


vector<int> points;

ai1::ai1(){
	init_rules();
}

ai1::~ai1(){

}

int ai1::dosomething(vector<int> vec){
	return vec.size();
}

int ai1::move_1(vector<int> te, vector<int> yaku_table_mine, vector<int> yaku_table_enemy, vector<int> ba){
	//return 0;

	//init_rules();
	double _max_eval = -10000;
	int _which_max = 0;

	vector<int> _te;
	vector<int> _yaku_mine;
	vector<int> _ba;
	for(int i = 0; i < te.size(); i++){
		if(te[i] exists){
			_te = te;
			_yaku_mine = yaku_table_mine;
			_ba = ba;
			set_zero(_te, i);
			vector<int> same = find_same_month(i, _ba);
//			cout<<i<<", there are "<<same.size()<<" same months"<<endl;
//			for(int j = 0; j < same.size(); j++){
//				cout<<same[j]<<endl;
//			}
			if(same.empty()){
				set_one(_ba, i);
			}elif(same.size() == 1){
				set_two(_yaku_mine, i);
				set_zero(_ba, same[0]);
				set_two(_yaku_mine, same[0]);
			}else{
				int which = ai1::move_2(_te, _yaku_mine, yaku_table_enemy, _ba, i, same);
				set_two(_yaku_mine, i);
				set_zero(_ba, which);
				set_two(_yaku_mine, which);
			}
//			cout<<"check point 1"<<endl;
			double tmp = evaluation(_te, _yaku_mine, yaku_table_enemy, _ba);
			//cout<<"check point 2"<<endl;
			if(tmp > _max_eval){
				_max_eval = tmp;
				_which_max = i;
			}
			_te.clear();
			_yaku_mine.clear();
			_ba.clear();
			same.clear();
		}
	}
	return _which_max;
}
int ai1::move_2(vector<int> te, vector<int> yaku_table_mine, vector<int> yaku_table_enemy, vector<int> ba, int newcard, vector<int> same){
	//return 0;
	//init_rules();
	double _max_eval = -10000;
	int _which_max = 0;

	vector<int> _te;
	vector<int> _yaku_mine;
	vector<int> _ba;
	for(int i = 0; i < same.size(); i++){
		_te = te;
		_yaku_mine = yaku_table_mine;
		_ba = ba;

		set_zero(_ba, same[i]);
		set_two(_yaku_mine, same[i]);
		set_zero(_te, newcard);
		set_two(_yaku_mine, newcard);

		double tmp = evaluation(_te, _yaku_mine, yaku_table_enemy, _ba);
		if(tmp > _max_eval){
			_max_eval = tmp;
			_which_max = i;
		}
		_te.clear();
		_yaku_mine.clear();
		_ba.clear();
	}

	return _which_max;
}
bool ai1::move_3(vector<int> te, vector<int> yaku_table_mine, vector<int> yaku_table_enemy, vector<int> ba){
	//return true;

	return false;




}

double ai1::evaluation(vector<int> te, vector<int> yaku_table_mine, vector<int> yaku_table_enemy, vector<int> ba){

	return (double)yaku_calculate(yaku_table_mine);
}




