#include "Object.h"

Object::Object(Vector2f init_m_Position, const std::string& init_Texture) { // Конструктор
    m_Position = init_m_Position;
    m_Texture.loadFromFile(init_Texture);
    m_Texture.setSmooth(true);
    m_Sprite.setTexture(m_Texture); 
}

Sprite Object::getSprite() { // Возвращение спрайта
    return m_Sprite;
}

void Object::set_m_Poition(Vector2f init_m_Poition) { // Установить новую позицию
    m_Position = init_m_Poition;
}

Vector2f Object::get_m_Poition() { // Вернуть позицию
    return m_Position;
}