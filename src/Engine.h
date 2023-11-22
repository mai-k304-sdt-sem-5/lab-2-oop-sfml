#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Item.h"
#define PLAYERS_COUNT 3 // Кол-во вариантов игрока
#define ENTITY_COUNT 9 // Кол-во противников на первом уровне
#define ITEMS_COUNT 10 // Кол-во монет на уровне
 
using namespace sf;

class Engine { // Класс движка
    private:
        RenderWindow m_Window;
        // Объявляем спрайт и текстуру для фона
        Sprite m_BackgroundSprite;
        Texture m_BackgroundTexture;
        RectangleShape rectangle;
        Font font; // Основной шрифт
        Text textCoins; // Текст монет
        Text textHealth; // Текст здоровья
        Text textForce; // Текст силы
        Player* player; // Объект игрока
        Entity_0 nullEntity;
        NullItem nullItem;
        void input(); // Обработка ввода
        void update(float dtAsSeconds); // Функция обновления
        void draw(); // Функция отрисовки
    public:
        Engine(); // Конструктор движка
        void start(); // Функция старт вызовет все приватные функции
};