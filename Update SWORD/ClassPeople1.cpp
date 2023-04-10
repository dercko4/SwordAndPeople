#include "ClassPeople1.h"
#include "needincludes.h"
People::People(float hp, float damage, int protect, int miss, string name, float crit, int chance_crit)
{
    this->hp = hp;
    this->damage = damage;
    this->protect = protect;
    this->miss = miss;
    this->name = name;
    this->crit = crit;
    this->chance_crit = chance_crit;
}
bool People::Save(int h, int d, int p, int m)
{
    if (h == 100 && d == 100 && p == 100 && m == 100)
    {
        cout << "Ошибка, в данный момент программа не работает \nВ случае повторной ошибки, обратитесь в тех.поддежрку. \nОсновная тех.поддежрка: +7(960)-669-60-89 \nРезервная тех.поддержка: +7(999)-837-98-29" << endl;
        return true;
    }
    else return false;
}
float People::get_hp()
{
    return hp;
}
float People::get_damage()
{
    return damage;
}
int People::get_protect()
{
    return protect;
}
int People::get_miss()
{
    return miss;
}
string People::get_name()
{
    return name;
}

float People::get_crit()
{
    return crit;
}
int People::get_chance_crit()
{
    return chance_crit;
}
void People::set_hp(float a)
{
    hp = a;
}
void People::set_damage(int a)
{
    damage = a;
}
void People::set_protect(int a)
{
    protect = a;
}
void People::set_miss(int a)
{
    miss = a;
}
void People::set_name(string a)
{
    name = a;
}
void People::set_crit(float a)
{
    crit = a;
}
void People::set_chance_crit(int a)
{
    chance_crit = a;
}
bool People::accuracy()
{
    int accuracy1 = 1 + rand() % 99;
    if (accuracy1 <= miss) return true;
    else return false;
}
bool People::accuracy_crit()
{
    int accuracy_crit1 = 1 + rand() % 99;
    if (accuracy_crit1 <= chance_crit) return true;
    else return false;
}
int People::help(People& b)
{
    if (b.accuracy_crit() == true)
    {
        if (protect < b.get_damage() * b.get_crit())
        {
            cout << "У " << b.get_name() << " прокнул крит!" << endl;
            return (b.get_damage() * b.get_crit()) - protect;
        }
        if (protect >= b.get_damage() * b.get_crit()) return 0;
    }
    if (protect >= b.get_damage()) return 0;
    if (protect < b.get_damage()) return b.get_damage() - protect;
    return NULL;
}
float People::critical()
{
    if (accuracy_crit() == true) return damage * crit;
    else return damage;
}