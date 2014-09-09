#pragma once
#include "general_settings.h"

using namespace std;

void init_rules();

void init_cards(vector<int>&, vector<int>& ,vector<int>&,
                vector<int>&, vector<int>&, vector<int>&);

void deal_cards(vector<int>&, vector<int>& ,vector<int>&,
                vector<int>&, vector<int>&, vector<int>&);

void move(vector<int>&, vector<int>&, int);

void random_move(vector<int>&, vector<int>&, int);

void random_move(vector<int>&, vector<int>&);

int random_choose(vector<int>&);

void set_zero(vector<int>&, int);

void set_one(vector<int>&, int);

void set_two(vector<int>&, int);

void set_zero(vector<int>&);

void set_one(vector<int>&);

void set_two(vector<int>&);

int card_amount(vector<int>&);

void koi_koi(vector<int>&);

bool is_same_month(int, int);

vector<int> find_same_month(int, vector<int>&);

vector<int> get_yama_enemy_te(vector<int> &, vector<int> &, vector<int> &, vector<int> &);

void guess_enemy_te(vector<int>, vector<int>&, vector<int>&, int);





