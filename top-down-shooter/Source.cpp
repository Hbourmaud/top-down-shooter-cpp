#include <SFML/Graphics.hpp>
#include "player.h"
#include "gameManager.h"

using namespace std;
using namespace sf;

int main(){
    GameManager gameManager;

    sf::RenderWindow window(sf::VideoMode(gameManager.windowWidth, gameManager.windowHeight), "Top-down shooter");


    Player player{ gameManager.windowWidth / 2, gameManager.windowHeight - 50 };

    while (window.isOpen())
    {
        window.clear(Color::Black);

        if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) break;

        player.update(gameManager);

        window.draw(player.shape);

        window.display();
    }
    return 0;
}