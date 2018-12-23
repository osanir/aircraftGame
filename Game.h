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

    sf::RenderWindow mWindow;
    sf::CircleShape mPlayer;
};