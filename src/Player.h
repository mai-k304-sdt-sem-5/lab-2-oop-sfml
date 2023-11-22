#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"

class Player : public Entity {
private:
    // Логические переменные для отслеживания направления движения
    bool m_LeftPressed;
    bool m_RightPressed;
    bool m_UpPressed;
    bool m_DownPressed;

    int health; // Здоровье игрока
    int regeneration; // Скорость регенирации
    int maxForce = 30;
public:
    Player(const std::string& _texture, float _speed, int _regeneration, int _id);
    //~Player();

    // Функции движения
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
 
    // Функция прекращения движения
    void stopLeft();
    void stopRight();
    void stopUp();
    void stopDown();

    int getHealth(); // Вернуть здоровье
    void setHealth(int _health); // Установить здоровье

    int getRegeneration(); // Вернуть регенирацию
    void setRegeneration(int _regeneration); // Установить регенирацию

    virtual void update(float elapsedTime); // Эта функция будет вызываться на каждый кадр
};

class Player_1 : public Player { public: Player_1(); };

class Player_2 : public Player { public: Player_2(); };

class Player_3 : public Player { public: Player_3(); };

#endif