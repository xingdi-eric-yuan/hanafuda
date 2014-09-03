#pragma once
#include "general_settings.h"
using namespace std;

class ai1{
public:
        ai1(void);
        ~ai1(void);
 
        static int dosomething(vector<int> vec);
        static int move_1(vector<int> te, vector<int> yaku_table_mine, vector<int> yaku_table_enemy, vector<int> ba);
        static int move_2(vector<int> te, vector<int> yaku_table_mine, vector<int> yaku_table_enemy, vector<int> ba, int newcard, vector<int> same);
        static bool move_3(vector<int> te, vector<int> yaku_table_mine, vector<int> yaku_table_enemy, vector<int> ba);
};