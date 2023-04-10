#include "needincludes.h"
#include "ClassPeople1.h"
#pragma once
class Sword
{
    string name_sword;
    int damage_sword;
    int hp_sword;
    int parrying;
    int protect_sword;
    int miss_sword;
    float crit_sword;
    int chance_crit_sword;
public:
    Sword(int hp_sword, int damage_sword, int protect_sword, int miss_sword, string name_sword, float crit_sword, int chance_crit_cword);
    int get_hp_sword();
    int get_damage_sword();
    int get_protect_sword();
    int get_miss_sword();
    string get_name_sword();
    float get_crit_sword();
    int get_chance_crit_sword();
    void set_damage_sord(int a);
    void set_protect_sword(int a);
    void set_miss_sword(int a);
    void set_critical_sword(float a);
    void set_chance_crit_sword(int a);
    void set_name_sword(string a)
    {
        name_sword = a;
    }
    void set_hp_sword(int a)
    {
        name_sword = a;
    }
};