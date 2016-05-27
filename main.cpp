#include <iostream>
#include "rayTracer.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600), "ray tracer");

    sf::Image img;

    img.create(800,600,sf::Color::Black);

    rayTracer world(&img, sf::Vector3f(0,0,-500));

    world.spheres.push_back(sphere(sf::Vector3f(0,0,500),50,1,sf::Color::Red));
    world.spheres.push_back(sphere(sf::Vector3f(100,50,501),500,1,sf::Color::Blue));

    world.render();

    sf::Texture tex;
    tex.loadFromImage(world.returnImage());

    sf::Sprite sprite;
    sprite.setTexture(tex);

    sf::Event event;
    while (window.isOpen()){
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        window.clear();
        window.draw(sprite);
        window.display();
    }
}
