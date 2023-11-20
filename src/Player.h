#include "Object.h"

class Player : public Object {
private:
    float m_Speed; // Скорость игрока
    // Логические переменные для отслеживания направления движения
    bool m_LeftPressed;
    bool m_RightPressed;
    bool m_UpPressed;
    bool m_DownPressed;
public:
    Player(sf::Vector2f init_m_Position, const std::string& init_Texture, float init_m_Speed);
    void set_m_Speed(float init_m_Speed); // Установить скорость
    float get_m_Speed(); // Вернуть скорость

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
