#include "do_evaluation.h"

using namespace std;

double do_evaluation(card_vec& vec){

	double res = 0.0;
	res += goko(vec);
	res += shiko(vec);
	res += ame_shiko(vec);
	res += sanko(vec);
	res += ino_shika_cho(vec);
	res += tane(vec);
	res += tanzaku(vec);
	res += kasu(vec);
	res += aotan(vec);
	res += akatan(vec);
	res += hanami_de_ippai(vec);
	res += tsukimi_de_ippai(vec);

	return res;
}

// 五光. 光札5枚
double goko(card_vec& vec){
	double res = 0.0;
	if(vec[MATSU_NI_TSURU] exists) res += 1.0;
	if(vec[SAKURA_NI_MAKU] exists) res += 1.0;
	if(vec[SUSUKI_NI_TSUKI] exists) res += 1.0;
	if(vec[YANAGI_NI_ONO_NO_MICHIKAZE] exists) res += 1.0;
	if(vec[KIRI_NI_HOUOU] exists) res += 1.0;
	return res / 5.0 * 10;
}

// 四光. 光札のうち柳に小野道風を除く4枚
double shiko(card_vec& vec){

	double res = 0.0;
	if(vec[MATSU_NI_TSURU] exists) res += 1.0;
	if(vec[SAKURA_NI_MAKU] exists) res += 1.0;
	if(vec[SUSUKI_NI_TSUKI] exists) res += 1.0;
	if(vec[KIRI_NI_HOUOU] exists) res += 1.0;
	return res / 4.0 * 8;
}

// 雨入り四光. 光札のうち柳に小野道風を含む4枚
double ame_shiko(card_vec& vec){

	double res = 0.0;
	if(vec[MATSU_NI_TSURU] exists) res += 1.0;
	if(vec[SAKURA_NI_MAKU] exists) res += 1.0;
	if(vec[SUSUKI_NI_TSUKI] exists) res += 1.0;
	if(vec[YANAGI_NI_ONO_NO_MICHIKAZE] exists) res += 1.0;
	if(vec[KIRI_NI_HOUOU] exists) res += 1.0;
	return res / 4.0 * 7;
}

// 三光. 光札のうち柳に小野道風を除く3枚
double sanko(card_vec& vec){
	double res = 0.0;
	if(vec[MATSU_NI_TSURU] exists) res += 1.0;
	if(vec[SAKURA_NI_MAKU] exists) res += 1.0;
	if(vec[SUSUKI_NI_TSUKI] exists) res += 1.0;
	if(vec[KIRI_NI_HOUOU] exists) res += 1.0;
	return res / 4.0 * 5;
}

// 猪鹿蝶. 萩に猪 + 紅葉に鹿 + 牡丹に蝶の3枚
double ino_shika_cho(card_vec& vec){
	double res = 0.0;
	if(vec[BOTAN_NI_CHO] exists) res += 1.0;
	if(vec[HAGI_NI_INOSHISHI] exists) res += 1.0;
	if(vec[MOMIJI_NI_SHIKA] exists) res += 1.0;
	return res / 3.0 * 5;
}

// たね. 種9枚のうち任意の5枚
double tane(card_vec& vec){
	int count = 0;
	for(int i = 0; i < vec.size(); i++){
		if(vec[i] exists && points[i] == 10) ++ count;
	}
	return (double)count * 0.2;
}

// たん. 短冊10枚のうち任意の5枚
double tanzaku(card_vec& vec){
	int count = 0;
	for(int i = 0; i < vec.size(); i++){
		if(vec[i] exists && points[i] == 5) ++ count;
	}
	return (double)count * 0.2;
}

// かす. 任意のカス10枚
double kasu(card_vec& vec){
	int count = 0;
	for(int i = 0; i < vec.size(); i++){
		if(vec[i] exists && points[i] == 1) ++ count;
	}
	return (double)count * 0.1;
}

// 青短. 牡丹 + 菊 + 紅葉の短冊3枚
double aotan(card_vec& vec){
	double res = 0.0;
	if(vec[BOTAN_NI_AOTAN] exists) res += 1.0;
	if(vec[KIKU_NI_AOTAN] exists) res += 1.0;
	if(vec[MOMIJI_NI_AOTAN] exists) res += 1.0;

	return res / 3.0 * 5;
}

// 赤短. 松 + 梅 + 桜の短冊3枚
double akatan(card_vec& vec){
	double res = 0.0;
	if(vec[MATSU_NI_AKATAN] exists) res += 1.0;
	if(vec[UME_NI_AKATAN] exists) res += 1.0;
	if(vec[SAKURA_NI_AKATAN] exists) res += 1.0;

	return res / 3.0 * 5;
}

// 花見で一杯. 桜に幕 + 菊に盃の2枚
double hanami_de_ippai(card_vec& vec){
	double res = 0.0;
	if(vec[SAKURA_NI_MAKU] exists) res += 1.0;
	if(vec[KIKU_NI_SAKAZUKI] exists) res += 1.0;
	return res / 2.0 * 5;
}

// 月見で一杯. 芒に月 + 菊に盃の2枚	
double tsukimi_de_ippai(card_vec& vec){
	double res = 0.0;
	if(vec[SUSUKI_NI_TSUKI] exists) res += 1.0;
	if(vec[KIKU_NI_SAKAZUKI] exists) res += 1.0;
	return res / 2.0 * 5;
}
