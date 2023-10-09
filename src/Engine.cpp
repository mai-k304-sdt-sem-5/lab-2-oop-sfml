#include "Engine.h"
 
Engine::Engine()
{
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
 
void Engine::start()
{
    // Расчет времени
    Clock clock;
 
    while (m_Window.isOpen())
    {
        // Перезапускаем таймер и записываем отмеренное время в dt
        Time dt = clock.restart();
 
        float dtAsSeconds = dt.asSeconds();
 
        input();
        update(dtAsSeconds);
        draw();
    }
}

void Engine::input()
{
    // Обрабатываем нажатие Escape
    if (Keyboard::isKeyPressed(Keyboard::Escape))
    {
        m_Window.close();
    }
 
    // Обрабатываем нажатие клавиш движения
    if (Keyboard::isKeyPressed(Keyboard::A))
    {
        m_Bob.moveLeft();
    }
    else
    {
        m_Bob.stopLeft();
    }
 
    if (Keyboard::isKeyPressed(Keyboard::D))
    {
        m_Bob.moveRight();
    }
    else
    {
        m_Bob.stopRight();
    }   
    if (Keyboard::isKeyPressed(Keyboard::W))
    {
        m_Bob.moveUp();
    }
    else
    {
        m_Bob.stopUp();
    }
 
    if (Keyboard::isKeyPressed(Keyboard::S))
    {
        m_Bob.moveDown();
    }
    else
    {
        m_Bob.stopDown();
    }                     
 
}

using namespace sf;

void Engine::update(float dtAsSeconds)
{
    m_Bob.update(dtAsSeconds);
}

void Engine::draw()
{
    // Стираем предыдущий кадр
    m_Window.clear(Color::White);
 
    // Отрисовываем фон
    m_Window.draw(m_BackgroundSprite);
    // И Боба
    m_Window.draw(m_Bob.getSprite());
 
    // Отображаем все, что нарисовали
    m_Window.display();
}