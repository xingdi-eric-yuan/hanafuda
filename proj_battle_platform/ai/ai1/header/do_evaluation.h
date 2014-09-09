#pragma once
#include "general_settings.h"

using namespace std;



double do_evaluation(vector<int>&);

// 五光. 光札5枚
double goko(vector<int>&);

// 四光. 光札のうち柳に小野道風を除く4枚
double shiko(vector<int>&);

// 雨入り四光. 光札のうち柳に小野道風を含む4枚
double ame_shiko(vector<int>&);

// 三光. 光札のうち柳に小野道風を除く3枚
double sanko(vector<int>&);

// 猪鹿蝶. 萩に猪 + 紅葉に鹿 + 牡丹に蝶の3枚
double ino_shika_cho(vector<int>&);

// たね. 種9枚のうち任意の5枚
double tane(vector<int>&);

// たん. 短冊10枚のうち任意の5枚
double tanzaku(vector<int>&);

// かす. 任意のカス10枚
double kasu(vector<int>&);

// 青短. 牡丹 + 菊 + 紅葉の短冊3枚
double aotan(vector<int>&);

// 赤短. 松 + 梅 + 桜の短冊3枚
double akatan(vector<int>&);

// 花見で一杯. 桜に幕 + 菊に盃の2枚
double hanami_de_ippai(vector<int>&);

// 月見で一杯. 芒に月 + 菊に盃の2枚	
double tsukimi_de_ippai(vector<int>&);

