#pragma once
#include "general_settings.h"

using namespace std;

int yaku_calculate(vector<int>&);

// 五光. 光札5枚
int is_goko(vector<int>&, bool&);

// 四光. 光札のうち柳に小野道風を除く4枚
int is_shiko(vector<int>&, bool&);

// 雨入り四光. 光札のうち柳に小野道風を含む4枚
int is_ame_shiko(vector<int>&, bool&);

// 三光. 光札のうち柳に小野道風を除く3枚
int is_sanko(vector<int>&, bool&);

// 猪鹿蝶. 萩に猪 + 紅葉に鹿 + 牡丹に蝶の3枚
int is_ino_shika_cho(vector<int>&, bool&);

// たね. 種9枚のうち任意の5枚
int is_tane(vector<int>&, bool&);

// たん. 短冊10枚のうち任意の5枚
int is_tanzaku(vector<int>&, bool&);

// かす. 任意のカス10枚
int is_kasu(vector<int>&, bool&);

// 青短. 牡丹 + 菊 + 紅葉の短冊3枚
int is_aotan(vector<int>&, bool&);

// 赤短. 松 + 梅 + 桜の短冊3枚
int is_akatan(vector<int>&, bool&);

// 花見で一杯. 桜に幕 + 菊に盃の2枚
int is_hanami_de_ippai(vector<int>&, bool&);

// 月見で一杯. 芒に月 + 菊に盃の2枚	
int is_tsukimi_de_ippai(vector<int>&, bool&);

