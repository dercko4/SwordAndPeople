#include "ClassPeople1.h"
#include "Sword1.h"
#pragma once

bool throw_sword(Sword& a)
{
    string agree;
    cout << "������� ��� ������ ��������� ��� " << a.get_name_sword();
    cout << "? ���� ��, �� �������� yes. ���� ���, �� �������� ���-�� ������" << endl;
    getline(cin, agree);
    if (agree == "yes") return true;
    return false;
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
void info_sword(Sword& a)
{
    cout << a.get_name_sword() << " ���������� � ��������:" << a.get_hp_sword() << "���������� � ������:" << a.get_protect_sword();
    cout << " ������� ����:" << a.get_damage_sword() << " ���� ��������� � �����:" << a.get_miss_sword();
    cout << " ����:" << a.get_crit_sword() << " ���� �����:" << a.get_chance_crit_sword();
    cout << endl;
}
bool take_sword(Sword& a)
{
    string agree;
    cout << "������� ��� ������ ����� ��� " << a.get_name_sword();
    cout << "? ���� ��, �� �������� yes. ���� ���, �� �������� ���-�� ������" << endl;
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
void print_crit(People& a, People& b)
{
    cout << "� " << b.get_name() << " ������� ���� �� " << a.get_name() << endl;
}
void print_hit(People& a, People& b)
{
    cout << b.get_name() << " ���� ���� �� ";
    cout << a.get_name() << ". �������� �� � " << a.get_name() << " :" << a.get_hp() << endl;
}
void print_miss(People& a, People& b)
{
    cout << b.get_name() << " ����������� �� " << a.get_name() << endl;
}
void print_protected(People& a, People& b)
{
    cout << b.get_name() << " �� ������ " << a.get_name() << endl;
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
        cout << b.get_name() << " ���� " << a.get_name() << endl;
    }
    if (b.get_hp() == 0)
    {
        cout << a.get_name() << " ���� " << b.get_name() << endl;
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
    cout << "���������� " << a.get_name() << " ��������:" << a.get_hp() << " ������:" << a.get_protect();
    cout << " ������� ����:" << a.get_damage() << " ���� ���������:" << a.get_miss();
    cout << " ����:" << a.get_crit() << " ���� �����:" << a.get_chance_crit();
    cout << endl;
}