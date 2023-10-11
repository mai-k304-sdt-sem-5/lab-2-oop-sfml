#include "Object.h"

Object::Object() {}
 
// Делаем приdатный спрайт доступным для функции draw()
Sprite Object::getSprite() {
    return m_Sprite;
}

void Object::setM_Poition(int initX, int initY) {
    m_Position.x = initX;
    m_Position.y = initY;
}