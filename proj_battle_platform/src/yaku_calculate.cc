#include "yaku_calculate.h"

using namespace std;

int yaku_calculate(vector<int>& vec){

	int res = 0;
	bool flag = false;

	if(is_goko(vec, flag) exists) res += 10;
	elif(is_shiko(vec, flag) exists) res += 8;
	elif(is_ame_shiko(vec, flag) exists) res += 7;
	elif(is_sanko(vec, flag) exists) res += 5;
	else res += 0;
	res += is_ino_shika_cho(vec, flag);
	res += is_tane(vec, flag);
	res += is_tanzaku(vec, flag);
	res += is_kasu(vec, flag);
	res += is_aotan(vec, flag);
	res += is_akatan(vec, flag);
	res += is_hanami_de_ippai(vec, flag);
	res += is_tsukimi_de_ippai(vec, flag);

	if(!flag) return 0;
	else return res;
}

// 五光. 光札5枚
int is_goko(vector<int>& vec, bool &flag){
	if(	vec[MATSU_NI_TSURU] exists &&
		vec[SAKURA_NI_MAKU] exists &&
		vec[SUSUKI_NI_TSUKI] exists &&
		vec[YANAGI_NI_ONO_NO_MICHIKAZE] exists &&
		vec[KIRI_NI_HOUOU] exists){

		if( vec[MATSU_NI_TSURU] is_new ||
			vec[SAKURA_NI_MAKU] is_new ||
			vec[SUSUKI_NI_TSUKI] is_new ||
			vec[YANAGI_NI_ONO_NO_MICHIKAZE] is_new ||
			vec[KIRI_NI_HOUOU] is_new) flag = true;
		return 10;
	}
	else return 0;
}

// 四光. 光札のうち柳に小野道風を除く4枚
int is_shiko(vector<int>& vec, bool &flag){
	if(	vec[MATSU_NI_TSURU] exists &&
		vec[SAKURA_NI_MAKU] exists &&
		vec[SUSUKI_NI_TSUKI] exists &&
		vec[KIRI_NI_HOUOU] exists){
			
		if( vec[MATSU_NI_TSURU] is_new ||
			vec[SAKURA_NI_MAKU] is_new ||
			vec[SUSUKI_NI_TSUKI] is_new ||
			vec[KIRI_NI_HOUOU] is_new) flag = true;
		return 8;
	}
	else return 0;
}

// 雨入り四光. 光札のうち柳に小野道風を含む4枚
int is_ame_shiko(vector<int>& vec, bool &flag){
	if(vec[YANAGI_NI_ONO_NO_MICHIKAZE] exists){
		int i = 0;
		if(vec[MATSU_NI_TSURU] exists) ++i;
		if(vec[SAKURA_NI_MAKU] exists) ++i;
		if(vec[SUSUKI_NI_TSUKI] exists) ++i;
		if(vec[KIRI_NI_HOUOU] exists) ++i;
		if(i >= 3){
			if( vec[MATSU_NI_TSURU] is_new ||
				vec[SAKURA_NI_MAKU] is_new ||
				vec[SUSUKI_NI_TSUKI] is_new ||
				vec[KIRI_NI_HOUOU] is_new) flag = true;
			return 7;
		}
		else return 0;
	}
	else return 0;
}

// 三光. 光札のうち柳に小野道風を除く3枚
int is_sanko(vector<int>& vec, bool &flag){
	if(vec[YANAGI_NI_ONO_NO_MICHIKAZE] exists) return 0;
	else{
		int i = 0;
		if(vec[MATSU_NI_TSURU] exists) ++i;
		if(vec[SAKURA_NI_MAKU] exists) ++i;
		if(vec[SUSUKI_NI_TSUKI] exists) ++i;
		if(vec[KIRI_NI_HOUOU] exists) ++i;
		if(i >= 3){
			if( vec[MATSU_NI_TSURU] is_new ||
				vec[SAKURA_NI_MAKU] is_new ||
				vec[SUSUKI_NI_TSUKI] is_new ||
				vec[KIRI_NI_HOUOU] is_new) flag = true;
			return 5;
		}
		else return 0;
	}
}

// 猪鹿蝶. 萩に猪 + 紅葉に鹿 + 牡丹に蝶の3枚
int is_ino_shika_cho(vector<int>& vec, bool &flag){
	if( vec[BOTAN_NI_CHO] exists &&
		vec[HAGI_NI_INOSHISHI] exists &&
		vec[MOMIJI_NI_SHIKA] exists){

		if( vec[BOTAN_NI_CHO] is_new ||
			vec[HAGI_NI_INOSHISHI] is_new ||
			vec[MOMIJI_NI_SHIKA] is_new) flag = true;
		return 5;
	}
	else return 0;
}

// たね. 種9枚のうち任意の5枚
int is_tane(vector<int>& vec, bool &flag){
	int count = 0;
	for(int i = 0; i < vec.size(); i++){
		if(vec[i] exists && points[i] == 10) ++ count;
	}
	if(count < 5) return 0;
	else{
		for(int i = 0; i < vec.size(); i++){
			if(vec[i] is_new && points[i] == 10) flag = true;
		}
		return count - 5 + 1;	
	}
}

// たん. 短冊10枚のうち任意の5枚
int is_tanzaku(vector<int>& vec, bool &flag){
	int count = 0;
	for(int i = 0; i < vec.size(); i++){
		if(vec[i] exists && points[i] == 5) ++ count;
	}
	if(count < 5) return 0;
	else{
		for(int i = 0; i < vec.size(); i++){
			if(vec[i] is_new && points[i] == 5) flag = true;
		}
		return count - 5 + 1;	
	}
}

// かす. 任意のカス10枚
int is_kasu(vector<int>& vec, bool &flag){
	int count = 0;
	for(int i = 0; i < vec.size(); i++){
		if(vec[i] exists && points[i] == 1) ++ count;
	}
	if(count < 10) return 0;
	else{
		for(int i = 0; i < vec.size(); i++){
			if(vec[i] is_new && points[i] == 1) flag = true;
		}
		return count - 10 + 1;	
	}
}

// 青短. 牡丹 + 菊 + 紅葉の短冊3枚
int is_aotan(vector<int>& vec, bool &flag){
	if( vec[BOTAN_NI_AOTAN] exists &&
		vec[KIKU_NI_AOTAN] exists &&
		vec[MOMIJI_NI_AOTAN] exists){
		if( vec[BOTAN_NI_AOTAN] is_new ||
			vec[KIKU_NI_AOTAN] is_new ||
			vec[MOMIJI_NI_AOTAN] is_new) flag = true;
		return 5;
	}
	else return 0;
}

// 赤短. 松 + 梅 + 桜の短冊3枚
int is_akatan(vector<int>& vec, bool &flag){
	if( vec[MATSU_NI_AKATAN] exists &&
		vec[UME_NI_AKATAN] exists &&
		vec[SAKURA_NI_AKATAN] exists){
		if( vec[MATSU_NI_AKATAN] is_new ||
			vec[UME_NI_AKATAN] is_new ||
			vec[SAKURA_NI_AKATAN] is_new) flag = true;
		return 5;
	}
	else return 0;
}

// 花見で一杯. 桜に幕 + 菊に盃の2枚
int is_hanami_de_ippai(vector<int>& vec, bool &flag){
	if( vec[SAKURA_NI_MAKU] exists &&
		vec[KIKU_NI_SAKAZUKI] exists){
		if( vec[SAKURA_NI_MAKU] is_new ||
			vec[KIKU_NI_SAKAZUKI] is_new) flag = true;
		return 5;
	}
	else return 0;
}

// 月見で一杯. 芒に月 + 菊に盃の2枚	
int is_tsukimi_de_ippai(vector<int>& vec, bool &flag){
	if( vec[SUSUKI_NI_TSUKI] exists &&
		vec[KIKU_NI_SAKAZUKI] exists){
		if( vec[SUSUKI_NI_TSUKI] is_new ||
			vec[KIKU_NI_SAKAZUKI] is_new) flag = true;
		return 5;
	}
	else return 0;
}
