#include "Entity.h"

Entity::Entity(Vector2f _position, const std::string& _texture, int _coins, int _force, float _speed, int _id): // Конструктор
    Object(_position, _texture, _coins, _id) { // Подключение конструктора объекта
        speed = _speed; // Установка скорости
        force = _force;
    }

//Entity::~Entity(void) { } // Диструктор

void Entity::setSpeed(float _speed) { // Установить скорость
    speed = _speed;
}

float Entity::getSpeed() { // Вернуть скорость
    return speed;
}

int Entity::getForce() { // Вернуть силу
    return force;
}

void Entity::setForce(int _force) { // Установить силу
    force = _force;
}

Entity_0::Entity_0(): Entity::Entity(Vector2f(0, 0), "", 0, 0, 0, 0) { }

void Entity_0::update(float elapsedTime) { }

Entity_1::Entity_1(Vector2f _position):
    Entity::Entity(_position, "textures/zombie/zombie_1.png", rand() % 10, rand() % 10, 200, 0) {}

void Entity_1::update(float elapsedTime) {
    if (position.x > 0) position.x += (rand() % 2 - 1) * speed * elapsedTime;
    if (position.x < MAX_X - texture.getSize().x) position.x += (rand() % 2) * speed * elapsedTime;
    if (position.y > 0) position.y += (rand() % 2 - 1) * speed * elapsedTime;;
    if (position.y < MAX_Y - texture.getSize().y) position.y += (rand() % 2) * speed * elapsedTime;
    // Теперь сдвигаем спрайт на новую позицию
    sprite.setPosition(position); 
}

Entity_2::Entity_2(Vector2f _position):
    Entity::Entity(_position, "textures/zombie/zombie_2.png", rand() % 10, rand() % 10, 100, 1) {
        point = Vector2f(rand() % MAX_X - texture.getSize().x, rand() % MAX_Y - texture.getSize().y);
    }

void Entity_2::update(float elapsedTime) {
    position.x += (point.x - position.x) / 500 * speed * elapsedTime;
    position.y += (point.y - position.y) / 500 * speed * elapsedTime;
    if ((point.x - position.x < 1) && (point.y - position.y < 1)) point = Vector2f(rand() % MAX_X - texture.getSize().x, rand() % MAX_Y - texture.getSize().y);
    // Теперь сдвигаем спрайт на новую позицию
    sprite.setPosition(position); 
}

Entity_3::Entity_3(Vector2f _position, Object* _player):
    Entity::Entity(_position, "textures/zombie/zombie_3.png", rand() % 10, rand() % 10, 50, 2) {
        player = _player;
    }

void Entity_3::update(float elapsedTime) {
    position.x += (player->getPosition().x - position.x) / 500 * speed * elapsedTime;
    position.y += (player->getPosition().y - position.y) / 500 * speed * elapsedTime;
    // Теперь сдвигаем спрайт на новую позицию
    sprite.setPosition(position); 
}