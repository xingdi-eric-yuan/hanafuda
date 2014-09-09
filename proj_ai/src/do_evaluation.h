#pragma once
#include "general_settings.h"

using namespace std;



double do_evaluation(card_vec&);

// 五光. 光札5枚
double goko(card_vec&);

// 四光. 光札のうち柳に小野道風を除く4枚
double shiko(card_vec&);

// 雨入り四光. 光札のうち柳に小野道風を含む4枚
double ame_shiko(card_vec&);

// 三光. 光札のうち柳に小野道風を除く3枚
double sanko(card_vec&);

// 猪鹿蝶. 萩に猪 + 紅葉に鹿 + 牡丹に蝶の3枚
double ino_shika_cho(card_vec&);

// たね. 種9枚のうち任意の5枚
double tane(card_vec&);

// たん. 短冊10枚のうち任意の5枚
double tanzaku(card_vec&);

// かす. 任意のカス10枚
double kasu(card_vec&);

// 青短. 牡丹 + 菊 + 紅葉の短冊3枚
double aotan(card_vec&);

// 赤短. 松 + 梅 + 桜の短冊3枚
double akatan(card_vec&);

// 花見で一杯. 桜に幕 + 菊に盃の2枚
double hanami_de_ippai(card_vec&);

// 月見で一杯. 芒に月 + 菊に盃の2枚	
double tsukimi_de_ippai(card_vec&);

