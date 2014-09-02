#include "init_cards.h"

using namespace std;

void init_cards(){
    int count = 0;

    SingleCard *cd;
    // Jan
    cd = new SingleCard(Matsu, 20, count++, "Matsu ni Tsuru"); // 松に鶴
    yama.push_back(cd);
    cd = new SingleCard(Matsu, 5, count++, "Matsu ni Akatan");
    yama.push_back(cd);
    cd = new SingleCard(Matsu, 1, count++, "Matsu no Kasu");
    yama.push_back(cd);
    cd = new SingleCard(Matsu, 1, count++, "Matsu no Kasu");
    yama.push_back(cd);
    // Feb
    cd = new SingleCard(Ume, 10, count++, "Ume ni Uguisu"); // 梅に鴬
    yama.push_back(cd);
    cd = new SingleCard(Ume, 5, count++, "Ume ni Akatan");
    yama.push_back(cd);
    cd = new SingleCard(Ume, 1, count++, "Ume no Kasu");
    yama.push_back(cd);
    cd = new SingleCard(Ume, 1, count++, "Ume no Kasu");
    yama.push_back(cd);
    // Mar
    cd = new SingleCard(Sakura, 20, count++, "Sakura ni Maku"); // 桜に幕
    yama.push_back(cd);
    cd = new SingleCard(Sakura, 5, count++, "Sakura ni Akatan");
    yama.push_back(cd);
    cd = new SingleCard(Sakura, 1, count++, "Sakura no Kasu");
    yama.push_back(cd);
    cd = new SingleCard(Sakura, 1, count++, "Sakura no Kasu");
    yama.push_back(cd);
    // Apr
    cd = new SingleCard(Fuji, 10, count++, "Fuji ni Hototogisu"); // 藤に不如帰
    yama.push_back(cd);
    cd = new SingleCard(Fuji, 5, count++, "Fuji ni Tanzaku");
    yama.push_back(cd);
    cd = new SingleCard(Fuji, 1, count++, "Fuji no Kasu");
    yama.push_back(cd);
    cd = new SingleCard(Fuji, 1, count++, "Fuji no Kasu");
    yama.push_back(cd);
    // May
    cd = new SingleCard(Ayame, 10, count++, "Ayame ni Yatsuhashi"); // 菖蒲に八橋
    yama.push_back(cd);
    cd = new SingleCard(Ayame, 5, count++, "Ayame ni Tanzaku");
    yama.push_back(cd);
    cd = new SingleCard(Ayame, 1, count++, "Ayame no Kasu");
    yama.push_back(cd);
    cd = new SingleCard(Ayame, 1, count++, "Ayame no Kasu");
    yama.push_back(cd);
    // Jun
    cd = new SingleCard(Botan, 10, count++, "Botan ni Chiyou"); // 牡丹に蝶
    yama.push_back(cd);
    cd = new SingleCard(Botan, 5, count++, "Botan ni Aotan");
    yama.push_back(cd);
    cd = new SingleCard(Botan, 1, count++, "Botan no Kasu");
    yama.push_back(cd);
    cd = new SingleCard(Botan, 1, count++, "Botan no Kasu");
    yama.push_back(cd);
    // Jul
    cd = new SingleCard(Hagi, 10, count++, "Hagi ni Inoshishi"); // 萩に猪
    yama.push_back(cd);
    cd = new SingleCard(Hagi, 5, count++, "Hagi ni Tanzaku");
    yama.push_back(cd);
    cd = new SingleCard(Hagi, 1, count++, "Hagi no Kasu");
    yama.push_back(cd);
    cd = new SingleCard(Hagi, 1, count++, "Hagi no Kasu");
    yama.push_back(cd);
    // Aug
    cd = new SingleCard(Susuki, 20, count++, "Susuki ni Tsuki"); // 芒に月
    yama.push_back(cd);
    cd = new SingleCard(Susuki, 10, count++, "SUsuki ni Kali"); // 芒に雁
    yama.push_back(cd);
    cd = new SingleCard(Susuki, 1, count++, "Susuki no Kasu");
    yama.push_back(cd);
    cd = new SingleCard(Susuki, 1, count++, "Susuki no Kasu");
    yama.push_back(cd);
    // Sep
    cd = new SingleCard(Kiku, 10, count++, "Kiku ni Sakazuki"); // 菊に盃
    yama.push_back(cd);
    cd = new SingleCard(Kiku, 5, count++, "Kiku ni Aotan");
    yama.push_back(cd);
    cd = new SingleCard(Kiku, 1, count++, "Kiku no Kasu");
    yama.push_back(cd);
    cd = new SingleCard(Kiku, 1, count++, "Kiku no Kasu");
    yama.push_back(cd);
    // Oct
    cd = new SingleCard(Momiji, 10, count++, "Momiji ni Shika"); // 紅葉に鹿
    yama.push_back(cd);
    cd = new SingleCard(Momiji, 5, count++, "Momiji ni Aotan");
    yama.push_back(cd);
    cd = new SingleCard(Momiji, 1, count++, "Momiji no Kasu");
    yama.push_back(cd);
    cd = new SingleCard(Momiji, 1, count++, "Momiji no Kasu");
    yama.push_back(cd);
    // Nov
    cd = new SingleCard(Yanagi, 20, count++, "Yanagi ni Ono no Michikaze"); // 柳に小野道風
    yama.push_back(cd);
    cd = new SingleCard(Yanagi, 10, count++, "Yanagi ni Tsubaa"); // 柳に燕
    yama.push_back(cd);
    cd = new SingleCard(Yanagi, 5, count++, "Yanagi ni Tanzaku");
    yama.push_back(cd);
    cd = new SingleCard(Yanagi, 1, count++, "Yanagi no Kasu");
    yama.push_back(cd);
    // Dec
    cd = new SingleCard(Kiri, 20, count++, "Kiri ni Houou"); // 桐に鳳凰
    yama.push_back(cd);
    cd = new SingleCard(Kiri, 1, count++, "Kiri no Kasu");
    yama.push_back(cd);
    cd = new SingleCard(Kiri, 1, count++, "Kiri no Kasu");
    yama.push_back(cd);
    cd = new SingleCard(Kiri, 1, count++, "Kiri no Kasu");
    yama.push_back(cd);

}


