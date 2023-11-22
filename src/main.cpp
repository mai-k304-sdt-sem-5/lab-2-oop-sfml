#include "Engine.h"
 
int main() {
    srand(time(0));
    Engine engine; // Объявляем экземпляр класса Engine
    engine.start(); // Вызываем функцию start
    return 0; // Останавливаем программу программу, когда движок остановлен
}