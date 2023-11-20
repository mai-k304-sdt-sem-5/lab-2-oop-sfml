#include "Engine.h"

Player* players[PLAYERS_COUNT]; // Массив игроков
 
Engine::Engine() {
    // Получаем разрешение экрана, создаем окно SFML и View
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
 
    m_Window.create(VideoMode(resolution.x, resolution.y),
        "Simple Game Engine",
        Style::Fullscreen);
 
    // Загружаем фон в текстуру
    // Подготовьте изображение под ваш размер экрана в редакторе
    m_BackgroundTexture.loadFromFile("background.jpg");
 
    // Связываем спрайт и текстуру
    m_BackgroundSprite.setTexture(m_BackgroundTexture);
}
 
void Engine::start() {
    Clock clock; // Расчет времени

    Player player1(Vector2f(0, 0), "bob.png", 400);
    players[0] = &player1;
    player = players[0];
 
    while (m_Window.isOpen()) {
        Time dt = clock.restart(); // Перезапускаем таймер и записываем отмеренное время в dt
 
        float dtAsSeconds = dt.asSeconds();
 
        input();
        update(dtAsSeconds);
        draw();
    }
}

void Engine::input() { // Обработка ввода
    if (Keyboard::isKeyPressed(Keyboard::Escape)) { m_Window.close(); } // Обрабатываем нажатие Escape
    // Обрабатываем нажатие клавиш движения
    if (Keyboard::isKeyPressed(Keyboard::A)) { player->moveLeft(); }
    else { player->stopLeft(); } // Движение влево 
    if (Keyboard::isKeyPressed(Keyboard::D)) { player->moveRight(); }
    else { player->stopRight(); } // Движение вправо
    if (Keyboard::isKeyPressed(Keyboard::W)) { player->moveUp(); }
    else { player->stopUp(); } // Движение вверх
    if (Keyboard::isKeyPressed(Keyboard::S)) { player->moveDown(); }
    else { player->stopDown(); } // Движение вниз                 
}

void Engine::update(float dtAsSeconds) { // Функция обновления
    player->update(dtAsSeconds); // Обновление игрока
}

void Engine::draw() { // Функция отрисовки
    m_Window.clear(Color::White); // Стираем предыдущий кадр
    m_Window.draw(m_BackgroundSprite); // Отрисовываем фон
    m_Window.draw(player->getSprite()); // Отрисовываем игрока
    m_Window.display(); // Отображаем все, что нарисовали
}