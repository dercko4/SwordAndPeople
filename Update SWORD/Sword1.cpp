#include "needincludes.h"
#include "Sword1.h"
#include "ClassPeople1.h"
#pragma once
Sword::Sword(int hp_sword, int damage_sword, int protect_sword, int miss_sword, string name_sword, float critical_sword, int chance_crit_sword)
{
    this->hp_sword = hp_sword;
    this->damage_sword = damage_sword;
    this->protect_sword = protect_sword;
    this->miss_sword = miss_sword;
    this->name_sword = name_sword;
    this->crit_sword = critical_sword;
    this->chance_crit_sword = chance_crit_sword;
}
int Sword::get_hp_sword()
{
    return hp_sword;
}
int Sword::get_damage_sword()
{
    return damage_sword;
}
int Sword::get_protect_sword()
{
    return protect_sword;
}
int Sword::get_miss_sword()
{
    return miss_sword;
}
string Sword::get_name_sword()
{
    return name_sword;
}
float Sword::get_crit_sword()
{
    return crit_sword;
}
int Sword::get_chance_crit_sword()
{
    return chance_crit_sword;
}
void Sword::set_damage_sord(int a)
{
    damage_sword = a;
}
void Sword::set_protect_sword(int a)
{
    protect_sword = a;
}
void Sword::set_miss_sword(int a)
{
    miss_sword = a;
}
void Sword::set_critical_sword(float a)
{
    crit_sword = a;
}
void Sword::set_chance_crit_sword(int a)
{
    chance_crit_sword = a;
}