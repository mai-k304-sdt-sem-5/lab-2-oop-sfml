#include "Player.h"

Player::Player(Vector2f init_m_Position, const std::string& init_Texture, float init_m_Speed):
    Object(init_m_Position, init_Texture) {
        m_Speed = init_m_Speed;
    }

void Player::set_m_Speed(float init_m_Speed) { // Установить скорость
    m_Speed = init_m_Speed;
}

float Player::get_m_Speed() { // Вернуть скорость
    return m_Speed;
}

// Функции движения
void Player::moveLeft() { m_LeftPressed = true; }
void Player::moveRight() { m_RightPressed = true; }
void Player::moveUp() { m_UpPressed = true; }
void Player::moveDown() { m_DownPressed = true; }

// Функция прекращения движения
void Player::stopLeft() { m_LeftPressed = false; }
void Player::stopRight() { m_RightPressed = false; }
void Player::stopUp() { m_UpPressed = false; }
void Player::stopDown() { m_DownPressed = false; }

// Двигаем игрока на основании пользовательского ввода в этом кадре,
// прошедшего времени и скорости
void Player::update(float elapsedTime) {
    if (m_RightPressed) m_Position.x += m_Speed * elapsedTime;
    if (m_LeftPressed) m_Position.x -= m_Speed * elapsedTime;
    if (m_UpPressed) m_Position.y -= m_Speed * elapsedTime;
    if (m_DownPressed) m_Position.y += m_Speed * elapsedTime;
 
    // Теперь сдвигаем спрайт на новую позицию
    m_Sprite.setPosition(m_Position);   
 
}