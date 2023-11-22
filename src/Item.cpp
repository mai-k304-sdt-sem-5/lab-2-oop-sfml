#include "Item.h"

Item::Item(const std::string& _texture, int _coins, int _id): // Конструктор
    Object(Vector2f(rand() % MAX_X, rand() % MAX_Y), _texture, _coins, _id) {
        sprite.setPosition(position); 
    }

Item::~Item(void) {}

NullItem::NullItem(): Item::Item("", 0, 0) {}

NullItem::~NullItem(void) {}

Coin::Coin(): Item::Item("textures/coin.png", rand() % 10, 0) {}

Coin::~Coin(void) {}

Armor::Armor(): Item::Item("textures/armor.png", rand() % 10, 1) {}

Armor::~Armor(void) {}

HealthPoint::HealthPoint(): Item::Item("textures/health_point.png", rand() % 10, 2) {}

HealthPoint::~HealthPoint(void) {}