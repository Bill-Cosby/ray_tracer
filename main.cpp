#include <iostream>
#include "rayTracer.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600), "ray tracer");

    sf::Image img;

    img.create(800,600,sf::Color::Black);

    rayTracer world(&img, sf::Vector3f(0,0,-500));

    world.lights.push_back(Light(sf::Vector3f(9,150,0), sf::Color::Yellow));

    world.spheres.push_back(sphere(sf::Vector3f(100,100,100),50,1,sf::Color::Yellow));
    world.spheres.push_back(sphere(sf::Vector3f(100,00,100),10,1,sf::Color::Red));
    world.spheres.push_back(sphere(sf::Vector3f(-100,0,50),50,1,sf::Color::Blue));
    world.spheres.push_back(sphere(sf::Vector3f(-500,-100,900),500,.5,sf::Color::Green));


    sf::Event event;
    while (window.isOpen()){
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
    world.render();

    sf::Texture tex;
    tex.loadFromImage(world.returnImage());

    sf::Sprite sprite;
    sprite.setTexture(tex);

//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
//            world.cameraPos.x += 10;
//        }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
//            world.cameraPos.x -= 10;
//        }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
//            world.cameraPos.z -= 10;
//        }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
//            world.cameraPos.z += 10;
//        }

        window.clear();
        window.draw(sprite);
        window.display();
    }
}
