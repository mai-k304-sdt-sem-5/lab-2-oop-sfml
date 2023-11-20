#include <SFML/Graphics.hpp>

using namespace sf;

class Object { // Класс Объекта
protected:
    Vector2f m_Position; // Позиция объекта
    //Sprite m_Sprite; // Объект Sprite
    Texture m_Texture; // Текстура
public:
    Sprite m_Sprite; // Объект Sprite
    Object(Vector2f init_m_Position, const std::string& init_Texture); // Конструктор
    Sprite getSprite(); // Возвращение спрайта
    void set_m_Poition(Vector2f init_m_Poition); // Установить позицию
    Vector2f get_m_Poition(); // Вернуть позицию
};