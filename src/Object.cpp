#include "Object.h"

Object::Object(Vector2f _position, const std::string& _texture, int _coins, int _id) { // Конструктор
    position = _position;
    texture.loadFromFile(_texture);
    texture.setSmooth(true);
    sprite.setTexture(texture); 
    coins = _coins;
    id = _id;
}

Object::~Object(void) { } // Диструктор

Sprite Object::getSprite() { // Возвращение спрайта
    return sprite;
}

void Object::setPosition(Vector2f _position) { // Установить новую позицию
    position = _position;
}

Vector2f Object::getPosition() { // Вернуть позицию
    return position;
}

int Object::getCoins() { // Вернуть монеты
    return coins;
}

void Object::setCoins(int _coins) { // Установить монеты
    coins = _coins;
}

bool Object::collision(Object* enterObject) { // Проверка коллизии
    if (sprite.getGlobalBounds().intersects(enterObject->getSprite().getGlobalBounds())) return true;
    else return false;
}

int Object::getId() {
    return id;
}