#include <iostream>
using namespace std;
class Item
{
protected:
    int weight; //��� �������� ���������� ���, ��� ��� � ���� ��� �������� ������ ������ ������������ �����
    int quality;// �������� � ��������� [0;100]
    int type;//1 - ���������� ������, 2 - �����������, 3 - ���, 4 - ������, 5 - �����������, 6 - �������� ��� ������
    bool in;// ������� ������� � ��������� - 1, ���������� - 0
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
    int temperature; // ����� �����
    int wind; // ����� �����������������
    int protection; // ����� ������ �� ��������� �����
    bool on; // ������ �� ��������� - 1, �� ������ - 0
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

    virtual Item* destroy() = 0; // ������� "���������", ����������� � ��������� ����� �������� ����� ��������(�����,���������� ����/�����/�����)
    virtual void repair() = 0; // ������� �������??? ��� ���������� ������ ������� ���������� �������������� � ����� ������� - ���������
    //��� ������� ������������ �������� (�����,���������� ����/�����/�����), ������� ���������� ������������� �������������� ����� ���� � �������
};