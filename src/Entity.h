#include "Object.h"

class Entity : public Object {
protected:
    // Логические переменные для отслеживания направления движения
    bool m_LeftPressed;
    bool m_RightPressed;
    bool m_UpPressed;
    bool m_DownPressed;
 
    float m_Speed; // Скорость в пикселях в секунду
public:
    Entity();
    Entity(FileInputStream stream);
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

    // Эта функция будет вызываться на каждый кадр
    void update(float elapsedTime);
};