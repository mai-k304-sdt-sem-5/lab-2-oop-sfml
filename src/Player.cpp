#include "Player.h"

Player::Player(const std::string& _texture, float _speed, int _regeneration, int _id):
    Entity(Vector2f(MAX_X / 2 - texture.getSize().x, MAX_Y / 2 - texture.getSize().y), _texture, 10, 10, _speed, _id) {
        health = 10;
        regeneration = _regeneration;
    }

//Player::~Player(void) { } // Диструктор

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

int Player::getHealth() { // Вернуть здоровье
    return health;
}

void Player::setHealth(int _health) { // Установить здоровье
    health = _health;
}

int Player::getRegeneration() { // Вернуть регенирацию
    return regeneration;
}

void Player::setRegeneration(int _regeneration) { // Установить регенирацию
    regeneration = _regeneration;
}


// Двигаем игрока на основании пользовательского ввода в этом кадре,
// прошедшего времени и скорости
void Player::update(float elapsedTime) {
    if (m_LeftPressed && (position.x > 0)) position.x -= speed * elapsedTime;
    if (m_RightPressed && (position.x < MAX_X - texture.getSize().x)) position.x += speed * elapsedTime;
    if (m_UpPressed && (position.y > 0)) position.y -= speed * elapsedTime;
    if (m_DownPressed && (position.y < MAX_Y - texture.getSize().y)) position.y += speed * elapsedTime;
 
    if (force <= maxForce) force += regeneration * elapsedTime;
    // Теперь сдвигаем спрайт на новую позицию
    sprite.setPosition(position);   
}

Player_1::Player_1(): Player::Player("textures/knights/knight_1.png", 200, 50, 0) {}

Player_2::Player_2(): Player::Player("textures/knights/knight_2.png", 250, 50, 1) {}

Player_3::Player_3(): Player::Player("textures/knights/knight_3.png", 300, 50, 2) {}