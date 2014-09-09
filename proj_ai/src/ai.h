#pragma once
#include "general_settings.h"
using namespace std;

class ai1{
public:
	ai1(void);
    ~ai1(void);
 	
 	int enemy_te_amount;

    static int dosomething(card_vec vec);
    static int move_1(card_vec te, card_vec yaku_table_mine, card_vec yaku_table_enemy, card_vec ba);
    static int move_2(card_vec te, card_vec yaku_table_mine, card_vec yaku_table_enemy, card_vec ba, int newcard, card_vec same);
    static bool move_3(card_vec te, card_vec yaku_table_mine, card_vec yaku_table_enemy, card_vec ba);

    static double evaluation(card_vec &te, card_vec &yaku_table_mine, card_vec &yaku_table_enemy, card_vec &ba);
};