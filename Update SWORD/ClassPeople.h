#include <needincludes.h>
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
void People::set_hp(float a)
{
    hp = a;
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
        if (protect < b.get_damage() * b.get_crit()) return (b.get_damage() * b.get_crit()) - protect;
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
void print_crit(People& a, People& b)
{
    cout << "У " << b.get_name() << " прокнул крит по " << a.get_name() << endl;
}
void print_hit(People& a, People& b)
{
    cout << b.get_name() << " нанёс урон по ";
    cout << a.get_name() << ". Осталось хп у " << a.get_name() << " :" << a.get_hp() << endl;
}
void print_miss(People& a, People& b)
{
    cout << b.get_name() << " промахнулся по " << a.get_name() << endl;
}
void print_protected(People& a, People& b)
{
    cout << b.get_name() << " не пробил " << a.get_name() << endl;
}
float hit(People& a, People& b)
{
    int l = a.help(b);
    if (a.accuracy() == true)
    {
        print_miss(a, b);
        return a.get_hp();
    }
    else
    {
        if (l > -1 && l < 1)
        {
            print_protected(a, b);
            return a.get_hp();
        }
        else
        {
            a.set_hp(a.get_hp() - l);
            print_hit(a, b);
            return a.get_hp();
        }
    }
    return 0;
}
void kill(People& a, People& b)
{
    if (a.get_hp() == 0)
    {
        cout << b.get_name() << " убил " << a.get_name() << endl;
    }
    if (b.get_hp() == 0)
    {
        cout << a.get_name() << " убил " << b.get_name() << endl;
    }
}
int death(People& a)
{
    if (a.get_hp() <= 0)
    {
        a.set_hp(0);
        return a.get_hp();
    }
    return a.get_hp();
}
void attack(People& a, People& b)
{
    hit(a, b);
    death(a);
    kill(a, b);
}
void info(People& a)
{
    cout << "Встречайте " << a.get_name() << " Здоровье:" << a.get_hp() << " Защита:" << a.get_protect();
    cout << " Обычный урон:" << a.get_damage() << " Шанс уклонения:" << a.get_miss();
    cout << " Крит:" << a.get_crit() << " Шанс крита:" << a.get_chance_crit();
    cout << endl;
}