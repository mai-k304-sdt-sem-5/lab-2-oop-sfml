#ifndef ENTITY_H
#define ENIUTY_H
#include "Object.h"

class Item : public Object { // Класс сущности
    public:
        Item(const std::string& _texture, int _coins, int _id); // Конструктор
        ~Item();  // Диструктор
};

class NullItem : public Item {
    public:
        NullItem(); // Конструктор
        ~NullItem();
};

class Coin : public Item {
    public:
        Coin(); // Конструктор
        ~Coin();
};

class Armor : public Item {
    public:
        Armor(); // Конструктор
        ~Armor();
};

class HealthPoint : public Item {
    public:
        HealthPoint(); // Конструктор
        ~HealthPoint();
};

#endif