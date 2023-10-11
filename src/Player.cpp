#include "Player.h"

Player::Player() {
    // Связываем текстуру и спрайт
    m_Texture.loadFromFile("bob.png");
    m_Sprite.setTexture(m_Texture); 
    // Вписываем в переменную скорость Боба
    m_Speed = 400;
    m_Position.x = 300;
    m_Position.y = 300;
}