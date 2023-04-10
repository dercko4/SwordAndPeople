#include "ClassPeople1.h"
#include "Sword1.h"
#include "Show.h"
int main()
{
    setlocale(LC_ALL, "Rus");
    srand((unsigned int)time(0));
    Enemy enemy(100, 15, 7, 25, "Alexia", 1.9, 29);
    Hero hero(100, 23, 4, 15, "Dercko", 1.7, 23);
    Sword rapire(50, 15, 5, 7, "Divine Rapire", 1, 15);
    info(enemy);
    info(hero);
    char choise;
    cout << "Выберите меч для боя:\n1- ";
    info_sword(rapire);
    cin >> choise;
    if (choise == '1')
    {
        take_sword(rapire);
        if (take_sword(rapire) == true)
        {
            get_sword(rapire, hero);
        }
    }
    info(enemy);
    info(hero);
    for (int i = 1;; i++)
    {
        cout << endl;
        cout << i << " раунд" << endl;
        attack(enemy, hero);
        if (enemy.get_hp() == 0) break;
        attack(hero, enemy);
        if (hero.get_hp() == 0) break;
        cout << i << " раунд завершился" << endl;
    }
    throw_sword(rapire);
    delete_sword(rapire, hero);
    info(hero);
}