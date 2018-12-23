#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#define SCREEN_WIDTH    1024
#define SCREEN_HEIGHT   768

class Game{
public:
    Game();
    void run();
private:
    void processEvents();
    void update();
    void render();

    void handlePlayerInput(sf::Keyboard::Key, bool);

    sf::RenderWindow mWindow;
    sf::CircleShape mPlayer;

    bool mIsMovingUp = false;
    bool mIsMovingDown = false;
    bool mIsMovingLeft = false;
    bool mIsMovingRight = false;
};