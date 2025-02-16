#include <iostream>
using namespace std;
class Item
{
protected:
    int weight; //дл€ простоты используем инт, так как в игре вес предмеов всегда кратен определЄнному числу
    int quality;// значени€ в процентах [0;100]
    int type;//1 - разведение костра, 2 - медикаменты, 3 - еда, 4 - одежда, 5 - инструменты, 6 - предметы дл€ крафта
    bool in;// наличие прдмета в инвентаре - 1, отсутсвтие - 0
public:
    void Take(){
        this->in = 1;
    }

    void Drop(){
        this->in = 0;
    }

    int getWeight(){
        return this->weight;
    }

    int getType(){
        return this->type;
    }

    int getQuality(){
        return this->quality;
    }
};

class cloth : public Item
{
protected:
    int temperature; // бонус тепла
    int wind; // бонус ветроустойчивости
    int protection; // бонус защиты от нанесени€ урона
    bool on; // надето на персонажа - 1, не надето - 0
public:
    cloth(int temp, int wind, int p, int w, int q){
        this->weight = w;
        this->quality = q;
        this->type = 4;
        this->in = 0;
        this->on = 0;
        this->temperature = temp;
        this->wind = wind;
        this->protection = p;
    }

    void wear(){
        this->on = 1;
    }

    void take_off() {
        this->on = 0;
    }

    virtual Item* destroy() = 0; // функци€ "разобрать", добавл€юща€ в инвентарь после действи€ новые предметы(ткань,высушенную кожу/шкуру/кишки)
    virtual void repair() = 0; // функци€ починки??? ƒл€ реализации данной функции необходимо взаимодействие с новым классом - инвентарь
    //при починке используютс€ предметы (ткань,высушенна€ кожа/шкура/кишки), поэтому необходимо реализовавыть взаимодействие между ними и одеждой
};