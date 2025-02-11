#include <iostream>
#include <string>
using namespace std;

class Item
{
protected:
    int weight; //Или флоат сделать? Просто хз не возникнет ли проблем со сравнениием, а в интах все держать явно проще
    int quality;
    int type;//Я хотела сделать стринг, но получается хуйня, так что надо будет сделать таблицу с номерами и тем, какой тип им соотвествует
public:
    int getWeight()
    {
        return this->weight;
    }
    int getType()
    {
        return this->type;
    }
    int getQuality()
    {
        return this->quality;
    }

};


class Food: public Item
{
protected:
    int food_value;
    int water_value;
public:
    Food(int w, int q, int t, int fv, int wv)
    {
        this->weight = w;
        this->quality = q;
        this->type = t;
        this->food_value = fv;
        this->water_value = wv;
    }
    ~Food(){}

    int getFood_val()
    {
        return this->food_value;
    }
    int getWater_val()
    {
        return this->water_value;
    }
};

class Canned_foods: protected Food
{
    bool canOpen(); //Функция, проверяющая игрока на наличие нужного инструмента чтобы открыть. Сейчас не могу написать, т к нет класса игрока
};
/*
class Carcass: protected Item
{
protected:
    int freeze; // величина от 0 до 1 - процент заморозки
    int meat;
    int gut;
    int skin;
public:


};*/

int main()
{
    Canned_foods f(10, 1, 11, 30, 15);
    cout << f.getType() << endl;
    cout << f.getWeight() << endl;
    return 0;
}
