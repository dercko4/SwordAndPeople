#include "needincludes.h"
#include "Game.h"
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
void info_sword(Sword& a)
{
    cout << a.get_name_sword() << " Пополнение к здоровью:" << a.get_hp_sword() << "Пополнение к защите:" << a.get_protect_sword();
    cout << " Обычный урон:" << a.get_damage_sword() << " Шанс уклонения с мечом:" << a.get_miss_sword();
    cout << " Крит:" << a.get_crit_sword() << " Шанс крита:" << a.get_chance_crit_sword();
    cout << endl;
}
bool take_sword(Sword& a)
{
    string agree;
    cout << "Уверены что хотите взять меч " << a.get_name_sword();
    cout << "? Если да, то напишите yes. Если нет, то напишите что-то другое" << endl;
    getline(cin, agree);
    if (agree == "yes") return true;
    return false;
}
bool throw_sword(Sword& a)
{
    string agree;
    cout << "Уверены что хотите выбросить меч " << a.get_name_sword();
    cout << "? Если да, то напишите yes. Если нет, то напишите что-то другое" << endl;
    getline(cin, agree);
    if (agree == "yes") return true;
    return false;
}
void get_sword(Sword& a, People& a1)
{
    if (take_sword(a) == true)
    {
        a1.set_hp(a1.get_hp() + a.get_hp_sword());
        a1.set_damage(a1.get_damage() + a.get_damage_sword());
        a1.set_protect(a1.get_protect() + a.get_protect_sword());
        a1.set_miss(a1.get_miss() + a.get_miss_sword());
        a1.set_crit(a1.get_crit() + a.get_crit_sword());
        a1.set_chance_crit(a1.get_chance_crit() + a.get_chance_crit_sword());
    }
}
void delete_sword(Sword& a, People& a1)
{
    if (throw_sword(a) == true)
    {
        a1.set_hp(a1.get_hp() - a.get_hp_sword());
        a1.set_damage(a1.get_damage() - a.get_damage_sword());
        a1.set_protect(a1.get_protect() - a.get_protect_sword());
        a1.set_miss(a1.get_miss() - a.get_miss_sword());
        a1.set_crit(a1.get_crit() - a.get_crit_sword());
        a1.set_chance_crit(a1.get_chance_crit() - a.get_chance_crit_sword());
    }
}