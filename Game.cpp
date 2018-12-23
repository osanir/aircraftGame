#include "Game.h"

Game::Game() 
    : mWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT) , "Rider", sf::Style::Default) 
    , mPlayer()
{
        mPlayer.setRadius(40.f);
        mPlayer.setPosition(100.f, 100.f);
        mPlayer.setFillColor(sf::Color::Red);
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
            case sf::Event::Closed:
                mWindow.close();
                break;
            default:
                break;
        }
    }
}

void Game::update(){

}

void Game::render(){
    mWindow.clear(sf::Color::Black);
    mWindow.draw(mPlayer);
    mWindow.display();
}