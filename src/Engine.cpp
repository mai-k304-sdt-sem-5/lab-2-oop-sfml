#include "Engine.h"
#include "Block.h"
 
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

    Block blockList[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            blockList[i][j].setM_Poition(i*32, j*32);
        }
    }
 
}
 
void Engine::start() {
    // Расчет времени
    Clock clock;
 
    while (m_Window.isOpen()) {
        // Перезапускаем таймер и записываем отмеренное время в dt
        Time dt = clock.restart();
 
        float dtAsSeconds = dt.asSeconds();
 
        input();
        update(dtAsSeconds);
        draw();
    }
}

void Engine::input() {
    // Обрабатываем нажатие Escape
    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        m_Window.close();
    }
 
    // Обрабатываем нажатие клавиш движения
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        player.moveLeft();
    } else {
        player.stopLeft();
    }
 
    if (Keyboard::isKeyPressed(Keyboard::D)) {
        player.moveRight();
    } else {
        player.stopRight();
    }   

    if (Keyboard::isKeyPressed(Keyboard::W)) {
        player.moveUp();
    } else {
        player.stopUp();
    }
 
    if (Keyboard::isKeyPressed(Keyboard::S)) {
        player.moveDown();
    } else {
        player.stopDown();
    }                     
 
}

using namespace sf;

void Engine::update(float dtAsSeconds) {
    player.update(dtAsSeconds);
}

void Engine::draw() {
    // Стираем предыдущий кадр
    m_Window.clear(Color::White);
 
    // Отрисовываем фон
    m_Window.draw(m_BackgroundSprite);
    // И Боба
    m_Window.draw(player.getSprite());
 
    // Отображаем все, что нарисовали
    m_Window.display();
}