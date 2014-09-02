#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "romaji.h"
#include "data_structure.h"
#include "init_cards.h"
#include "helper.h"
#include "yaku_calculate.h"
#include "PLAYER_1_AI.h"
#include "PLAYER_2_AI.h"

#define elif else if
#define PLAYER_1 true
#define PLAYER_2 false

using namespace std;

extern vector<SingleCard *> yama; // 山札
extern vector<SingleCard *> te_1; // 手札_1
extern vector<SingleCard *> te_2; // 手札_2
extern vector<SingleCard *> yaku_table_1;   // 役札_1 
extern vector<SingleCard *> yaku_table_2;   // 役札_2
extern vector<SingleCard *> ba;   // 場札
extern bool oya; // 親
extern int Point_1;
extern int Point_2;