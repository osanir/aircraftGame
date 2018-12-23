#include "Game.h"

Game::Game() 
    : mWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT) , "Rider", sf::Style::Default) 
    , mPlayer()
{
        mWindow.setFramerateLimit(60);
        mPlayer.setRadius(40.f);
        mPlayer.setPosition(100.f, 100.f);
        mPlayer.setFillColor(sf::Color::Cyan);
}

void Game::run(){
    while(mWindow.isOpen() ){
        processEvents();
        update();
        render();
    }
}

void Game::processEvents(){
    sf::Event e;
    while( mWindow.pollEvent(e) ){
        switch (e.type){
            case sf::Event::KeyPressed:
                handlePlayerInput(e.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(e.key.code, false);
                break;
            case sf::Event::Closed:
                mWindow.close();
                break;
        }
    }
}

void Game::update(){
    sf::Vector2f movement(0.f, 0.f);
    float speed = 1.f;
    if( mIsMovingUp )
        movement.y -= speed;
    if( mIsMovingDown )
        movement.y += speed;
    if( mIsMovingRight )
        movement.x += speed;
    if( mIsMovingLeft )
        movement.x -= speed;

    mPlayer.move(movement);
}

void Game::render(){
    mWindow.clear(sf::Color::Black);
    mWindow.draw(mPlayer);
    mWindow.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed){
    if( key == sf::Keyboard::W )
        mIsMovingUp = isPressed;
    else if( key == sf::Keyboard::S )
        mIsMovingDown = isPressed;
    else if( key == sf::Keyboard::A )
        mIsMovingLeft = isPressed;
    else if( key == sf::Keyboard::D )
        mIsMovingRight = isPressed;
}
