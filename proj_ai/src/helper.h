#pragma once
#include "general_settings.h"

using namespace std;

void init_rules();

void init_cards(card_vec&, card_vec& ,card_vec&,
                card_vec&, card_vec&, card_vec&);

void deal_cards(card_vec&, card_vec& ,card_vec&,
                card_vec&, card_vec&, card_vec&);

void move(card_vec&, card_vec&, int);

void random_move(card_vec&, card_vec&, int);

void random_move(card_vec&, card_vec&);

void random_move_except(card_vec&, card_vec&, int, month_vec&);

int random_choose(card_vec&);

void set_zero(card_vec&, int);

void set_one(card_vec&, int);

void set_two(card_vec&, int);

void set_zero(card_vec&);

void set_one(card_vec&);

void set_two(card_vec&);

int card_amount(card_vec&);

void koi_koi(card_vec&);

int get_month(int);

bool is_same_month(int, int);

card_vec find_same_month(int, card_vec&);

card_vec get_yama_enemy_te(card_vec &, card_vec &, card_vec &, card_vec &);

void guess_enemy_te(card_vec, card_vec&, card_vec&, card_vec&, int);





