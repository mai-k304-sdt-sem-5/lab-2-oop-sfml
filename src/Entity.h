#ifndef ENTITY_H
#define ENIUTY_H
#include "Object.h"

class IEntity {
    protected:
        virtual void update(float elapsedTime) = 0; // Эта функция будет вызываться на каждый кадр
};

class Entity : public Object, IEntity { // Класс сущности
    protected:
        float speed; // Скорость сущности
        int force; // Сила сущности
    public:
        Entity(Vector2f _position, const std::string& _texture, int _coins, int _force, float _speed, int _id); // Конструктор
        //~Entity();  // Диструктор
        void setSpeed(float _speed); // Установить скорость
        float getSpeed(); // Вернуть скорость
        int getForce(); // Вернуть силу
        void setForce(int _force); // Установить силу
        virtual void update(float elapsedTime) = 0; // Эта функция будет вызываться на каждый кадр
};

class Entity_0 : public Entity {
    public:
        Entity_0(); // Конструктор
        virtual void update(float elapsedTime);
};

class Entity_1 : public Entity {
    public:
        Entity_1(Vector2f _position); // Конструктор
        virtual void update(float elapsedTime);
};

class Entity_2 : public Entity {
    private:
        Vector2f point;
    public:
        Entity_2(Vector2f _position); // Конструктор
        virtual void update(float elapsedTime);
};

class Entity_3 : public Entity {
    private:
        Object* player;
    public:
        Entity_3(Vector2f _position, Object* _player); // Конструктор
        virtual void update(float elapsedTime);
};

#endif