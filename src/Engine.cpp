#include "Engine.h"

Player* players[PLAYERS_COUNT]; // Массив игроков
Entity* entitys[ENTITY_COUNT]; // Массив противников
Item* items[ITEMS_COUNT]; // Массив монет

using namespace sf;
 
Engine::Engine() {
    nullEntity = Entity_0();
    nullItem = NullItem();

    m_Window.create(VideoMode(MAX_X, MAX_Y),
        "Knight Survivorse",
        Style::Default);
    m_Window.setPosition(Vector2i(0, 0));
    m_Window.setVerticalSyncEnabled(true);
 
    // Загружаем фон в текстуру
    // Подготовьте изображение под ваш размер экрана в редакторе
    m_BackgroundTexture.loadFromFile("textures/background.jpg");
 
    // Связываем спрайт и текстуру
    m_BackgroundSprite.setTexture(m_BackgroundTexture);
    rectangle = RectangleShape (sf::Vector2f(400, 40));
    rectangle.setFillColor(sf::Color::Black);

    font.loadFromFile("font.ttf");

    textCoins.setFont(font);
    textCoins.setCharacterSize(14);
    textCoins.setFillColor(sf::Color::Yellow);
    textCoins.move(10, 10);

    textHealth.setFont(font);
    textHealth.setCharacterSize(14);
    textHealth.setFillColor(sf::Color::Red);
    textHealth.move(100, 10);

    textForce.setFont(font);
    textForce.setCharacterSize(14);
    textForce.setFillColor(sf::Color::Blue);
    textForce.move(200, 10);
}
 
void Engine::start() {
    Clock clock; // Расчет времени
    Player_1 player1;
    players[0] = &player1;
    Player_2 player2;
    players[1] = &player2;
    Player_3 player3;
    players[2] = &player3;
    player = players[0];

    Entity_1 entity_1(Vector2f(rand() % MAX_X, rand() % MAX_Y));
    Entity_1 entity_2(Vector2f(rand() % MAX_X, rand() % MAX_Y));
    Entity_1 entity_3(Vector2f(rand() % MAX_X, rand() % MAX_Y));
    Entity_1 entity_4(Vector2f(rand() % MAX_X, rand() % MAX_Y));
    Entity_2 entity_5(Vector2f(rand() % MAX_X, rand() % MAX_Y));
    Entity_2 entity_6(Vector2f(rand() % MAX_X, rand() % MAX_Y));
    Entity_2 entity_7(Vector2f(rand() % MAX_X, rand() % MAX_Y));
    Entity_3 entity_8(Vector2f(rand() % MAX_X, rand() % MAX_Y), player);
    Entity_3 entity_9(Vector2f(rand() % MAX_X, rand() % MAX_Y), player);
    entitys[0] = &entity_1;
    entitys[1] = &entity_2;
    entitys[2] = &entity_3;
    entitys[3] = &entity_4;
    entitys[4] = &entity_5;
    entitys[5] = &entity_6;
    entitys[6] = &entity_7;
    entitys[7] = &entity_8;
    entitys[8] = &entity_9;

    Coin coin1;
    Coin coin2;
    Coin coin3;
    Coin coin4;
    Coin coin5;
    Armor arm1;
    Armor arm2;
    HealthPoint hp1;
    HealthPoint hp2;
    HealthPoint hp3;
    items[0] = &coin1;
    items[1] = &coin2;
    items[2] = &coin3;
    items[3] = &coin4;
    items[4] = &coin5;
    items[5] = &arm1;
    items[6] = &arm2;
    items[7] = &hp1;
    items[8] = &hp2;
    items[9] = &hp3;
 
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
    for (int i = 0; i < ENTITY_COUNT; i++) {
        if (player->collision(entitys[i])) {
            if (player->getForce() - entitys[i]->getForce() > 0) {
                player->setCoins(player->getCoins() + entitys[i]->getCoins());
                player->setForce(player->getForce() - entitys[i]->getForce());
            } else {
                player->setHealth(player->getHealth() - entitys[i]->getForce());
                player->setForce(0);
                if (player->getHealth() <= 0) m_Window.close();
            }
            entitys[i] = &nullEntity;
        }
        entitys[i]->update(dtAsSeconds); // Обновление противников
    }
    for (int i = 0; i < ITEMS_COUNT; i++) {
        if (player->collision(items[i])) {
            player->setCoins(player->getCoins() + items[i]->getCoins());
            if (items[i]->getId() == 1) {
                players[player->getId() + 1]->setPosition(player->getPosition());
                player = players[player->getId() + 1];
            }
            if (items[i]->getId() == 2) player->setHealth(player->getHealth() + rand() % 10);
            items[i] = &nullItem;
        }
    }
    textCoins.setString("Coins: " + std::to_string(player->getCoins()));
    textHealth.setString("Health: " + std::to_string(player->getHealth()));
    textForce.setString("Force: " + std::to_string(player->getForce()));
}

void Engine::draw() { // Функция отрисовки
    m_Window.clear(Color::White); // Стираем предыдущий кадр
    m_Window.draw(m_BackgroundSprite); // Отрисовываем фон
    m_Window.draw(player->getSprite()); // Отрисовываем игрока
    for (int i = 0; i < ENTITY_COUNT; i++) {
        m_Window.draw(entitys[i]->getSprite()); // Отрисовывка противников
    }
    for (int i = 0; i < ITEMS_COUNT; i++) {
        m_Window.draw(items[i]->getSprite()); // Отрисовывка противников
    }
    m_Window.draw(rectangle);
    m_Window.draw(textCoins);
    m_Window.draw(textHealth);
    m_Window.draw(textForce);
    m_Window.display(); // Отображаем все, что нарисовали
}