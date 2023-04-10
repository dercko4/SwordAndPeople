#include "needincludes.h"
#pragma once
class People
{
    float hp;
    float damage;
    int protect;
    int miss;
    string name;
    float crit;
    int chance_crit;
public:
    People(float hp, float damage, int protect, int miss, string name, float crit, int chance_crit);
    void set_hp(float a);
    void set_damage(int a);
    void set_miss(int a);
    void set_protect(int a);
    void set_name(string a);
    void set_crit(float a);
    void set_chance_crit(int a);
    float get_hp();
    float get_damage();
    int get_protect();
    int get_miss();
    string get_name();
    float get_crit();
    int get_chance_crit();
    int help(People& b);
    bool Save(int h, int d, int p, int m);
    bool accuracy();
    bool accuracy_crit();
    float critical();
};
class Hero : public People
{
public:
    Hero(float hp, int damage, int protect, int miss, string name, float crit, int chance_crit) : People(hp, damage, protect, miss, name, crit, chance_crit) {};
};
class Enemy : public People
{
public:
    Enemy(float hp, int damage, int protect, int miss, string name, float crit, int chance_crit) : People(hp, damage, protect, miss, name, crit, chance_crit) {};
};