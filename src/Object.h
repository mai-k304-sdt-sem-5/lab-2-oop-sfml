#include <SFML/Graphics.hpp>

using namespace sf;

class Object {
protected:
    Vector2f m_Position; // Позиция объекта

    // Объявляем объект Sprite
    Sprite m_Sprite;
 
    // Добавляем текстуру
    Texture m_Texture;
public:
    Object();
    Sprite getSprite(); // Возвращение спрайта

    void setM_Poition(int initX, int initY);
};