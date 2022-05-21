#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>




void moveInDirection(sf::Time &elapsed, const sf::Keyboard::Key &key, sf::Sprite &guy, sf::RenderWindow &window, std::vector<sf::Sprite> &walls)
{
    int speed_x = 100;
    int speed_y = 100;
    int right = 800;
    int bottom = 800;


    for(auto &wall : walls)
        {
            sf::FloatRect guybounds = guy.getGlobalBounds();
            sf::FloatRect wallbounds = wall.getGlobalBounds();
            if(guy.getGlobalBounds().intersects(wallbounds))
            {
              std::cout << "Collision!" << std::endl;
              if(guybounds.top > wallbounds.top + wallbounds.height - 5
                    && guybounds.left + guybounds.width > wallbounds.left
                        && guybounds.left < wallbounds.left + wallbounds.width)
                {
                   std::cout << "Top collision--";
                 guy.setPosition(guy.getPosition().x, wallbounds.top + wallbounds.height);
                    break;
                }
                else if(guybounds.top < wallbounds.top - guybounds.height + 5
                        && guybounds.left > wallbounds.left - guybounds.width
                        && guybounds.left < wallbounds.left + wallbounds.width)

                {
                    std::cout << "base collision--";
                    guy.setPosition(guy.getPosition().x, wallbounds.top - guybounds.height);
                    break;
                }
                else if(guybounds.left < wallbounds.left - guybounds.width + 5
                        && guybounds.top > wallbounds.top - guybounds.height
                        && guybounds.top < wallbounds.top + wallbounds.height)
                {
                    std::cout << "Right Collision!--";
          if(guybounds.left + guybounds.width - wallbounds.left > 4)
                        std::cout << guybounds.left + guybounds.width - wallbounds.left << "----";
                    guy.setPosition(wallbounds.left - guybounds.width, guy.getPosition().y);
                    break;
              }
                else if(guybounds.left > wallbounds.left + wallbounds.width - 5
                        && guybounds.top > wallbounds.top - guybounds.height
                        && guybounds.top < wallbounds.top + wallbounds.height)
                {
                    guy.setPosition(wallbounds.left + wallbounds.width, guy.getPosition().y);
                    break;
                }
            }
            else
            {
                if(key == sf::Keyboard::Up && !(guybounds.top <= 0.0))
                {
                    guy.move(0, -speed_y * elapsed.asSeconds());
                }
                else if(key == sf::Keyboard::Right && !(guybounds.left >= right - guybounds.width))
               {
                    guy.move(speed_x * elapsed.asSeconds(), 0);
                }
                else if(key == sf::Keyboard::Down && !(guybounds.top >= bottom - guybounds.height) && !(guybounds.top >= bottom - guybounds.height))
                {
                    guy.move(0, speed_y * elapsed.asSeconds());
                }
                else if(key == sf::Keyboard::Left && !(guybounds.left <= 0.0))
                {
                    guy.move(-speed_x * elapsed.asSeconds(), 0);
                }
            }
        }
}
int main()
{

    sf::RenderWindow window(sf::VideoMode(800, 800), "My window");

    sf::Texture texture_grass;
    if (!texture_grass.loadFromFile("grass.png")) {return 1;}

    sf::Texture texture_wall;
    if(!texture_wall.loadFromFile("wall.png")) {return 1;}

    sf::Texture texture_guy;
    if(!texture_guy.loadFromFile("guy.png")) {return 1;}

    texture_grass.setRepeated(true);
    sf::Sprite grass;
    grass.setTexture(texture_grass);
    grass.setTextureRect(sf::IntRect(0, 0, 800,800));

    texture_wall.setRepeated(true);
    sf::Sprite wall;
    wall.setTexture(texture_wall);

    std::vector<sf::Sprite> walls;


    wall.setTextureRect(sf::IntRect(0, 0, 50, window.getSize().y - 125));
    wall.setPosition(0.0, 125.0);
    walls.emplace_back(wall);

    wall.setTextureRect(sf::IntRect(0, 0, window.getSize().x, 50));
    wall.setPosition(0.0, 0.0);
    walls.emplace_back(wall);
    wall.setTextureRect(sf::IntRect(0, 0, 50, window.getSize().y - 125));
    wall.setPosition(window.getSize().x - 50, 0.0);
    walls.emplace_back(wall);
    wall.setTextureRect(sf::IntRect(0, 0, 675, 50));
    wall.setPosition(0, 125);
     walls.emplace_back(wall);
     wall.setTextureRect(sf::IntRect(0, 0, 675, 50));
     wall.setPosition(125, 250);
     walls.emplace_back(wall);
     wall.setTextureRect(sf::IntRect(0, 0, 500, 50));
     wall.setPosition(0, 375);
     walls.emplace_back(wall);
     wall.setTextureRect(sf::IntRect(0, 0, 50, 300));
     wall.setPosition(600, 375);
     walls.emplace_back(wall);
     wall.setTextureRect(sf::IntRect(0, 0, 50, 175));
     wall.setPosition(472, 375);
     walls.emplace_back(wall);
     wall.setTextureRect(sf::IntRect(0, 0, 50, 175));
     wall.setPosition(350, 500);
     walls.emplace_back(wall);
     wall.setTextureRect(sf::IntRect(0, 0, 50, 175));
     wall.setPosition(223, 375);
     walls.emplace_back(wall);
     wall.setTextureRect(sf::IntRect(0, 0, 50, 175));
     wall.setPosition(101, 500);
     walls.emplace_back(wall);
     wall.setTextureRect(sf::IntRect(0, 0, 675, 50));
     wall.setPosition(124, 625);
     walls.emplace_back(wall);
    wall.setTextureRect(sf::IntRect(0, 0, window.getSize().x, 50));
    wall.setPosition(0.0, window.getSize().y - 50);
    walls.emplace_back(wall);



    sf::Sprite guy;
    guy.setTexture(texture_guy);
    guy.setPosition(0.0, 50.0);
    sf::Clock clock;


    while (window.isOpen())
    {
        sf::Time elapsed = clock.restart();
        while (window.isOpen())
           { std::cout<<wall.getGlobalBounds().top<<std::endl<<guy.getGlobalBounds().top <<std::endl;
               sf::Time elapsed = clock.restart();

               if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&!(guy.getGlobalBounds().top==wall.getGlobalBounds().top) )
               {
                   moveInDirection(elapsed, sf::Keyboard::Up, guy, window, walls);
               }
               if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
               {
                   moveInDirection(elapsed, sf::Keyboard::Down, guy, window, walls);
               }
               if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
               {
                   moveInDirection(elapsed, sf::Keyboard::Left, guy, window, walls);
               }
               if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
               {
                   moveInDirection(elapsed, sf::Keyboard::Right, guy, window, walls);
               }



        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
        }

        window.draw(grass);
        for(auto &wall : walls)
        {
            window.draw(wall);
        }
        window.draw(guy);
        window.display();
    }

    return 0;
}
}
