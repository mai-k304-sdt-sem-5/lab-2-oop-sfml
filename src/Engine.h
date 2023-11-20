#include <SFML/Graphics.hpp>
#include "Player.h"
#define PLAYERS_COUNT 1 // Кол-во вариантов игрока
 
using namespace sf;

class Engine { // Класс движка
    private:
        RenderWindow m_Window;
        // Объявляем спрайт и текстуру для фона
        Sprite m_BackgroundSprite;
        Texture m_BackgroundTexture;   
        Player* player; // Объект игрока
        void input(); // Обработка ввода
        void update(float dtAsSeconds); // Функция обновления
        void draw(); // Функция отрисовки
    public:
        Engine(); // Конструктор движка
        void start(); // Функция старт вызовет все приватные функции
};