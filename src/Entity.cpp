#include "Entity.h"

Entity::Entity() {};

Entity::Entity(FileInputStream stream) {
    // Связываем текстуру и спрайт
    m_Texture.loadFromStream(stream);
    m_Sprite.setTexture(m_Texture); 
    // Вписываем в переменную скорость Боба
    m_Speed = 400;
}

void Entity::moveLeft() {
    m_LeftPressed = true;
}
 
void Entity::moveRight() {
    m_RightPressed = true;
}

void Entity::moveUp() {
    m_UpPressed = true;
}
 
void Entity::moveDown() {
    m_DownPressed = true;
}
 
void Entity::stopLeft() {
    m_LeftPressed = false;
}
 
void Entity::stopRight() {
    m_RightPressed = false;
}

void Entity::stopUp() {
    m_UpPressed = false;
}
 
void Entity::stopDown() {
    m_DownPressed = false;
}

// Двигаем Боба на основании пользовательского ввода в этом кадре,
// прошедшего времени и скорости
void Entity::update(float elapsedTime) {
    if (m_RightPressed) {
        m_Position.x += m_Speed * elapsedTime;
    }
 
    if (m_LeftPressed) {
        m_Position.x -= m_Speed * elapsedTime;
    }
    if (m_UpPressed) {
        m_Position.y -= m_Speed * elapsedTime;
    }
 
    if (m_DownPressed) {
        m_Position.y += m_Speed * elapsedTime;
    }
 
    // Теперь сдвигаем спрайт на новую позицию
    m_Sprite.setPosition(m_Position);   
 
}