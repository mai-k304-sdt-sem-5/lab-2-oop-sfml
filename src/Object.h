#ifndef OBJECT_H
#define OBJECT_H
#define MAX_X 1024
#define MAX_Y 768
#include <SFML/Graphics.hpp>
#include <ctime>

using namespace sf;

class Object { // Класс Объекта
    protected:
        Vector2f position; // Позиция объекта
        Sprite sprite; // Объект Sprite
        Texture texture; // Текстура
        int coins; // Монеты
        int id;
    public:
        Object(Vector2f _position, const std::string& _texture, int _coins, int _id); // Конструктор
        ~Object(); // Диструктор
        Sprite getSprite(); // Возвращение спрайта
        void setPosition(Vector2f _position); // Установить позицию
        Vector2f getPosition(); // Вернуть позицию
        int getCoins(); // Вернуть монеты
        void setCoins(int _coins); // Установить монеты
        bool collision(Object* enterObject); // Проверка коллизии
        int getId();
};

#endif