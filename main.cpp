#include <iostream>
#include "rayTracer.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600), "ray tracer");

    sf::Image img;

    img.create(800,600,sf::Color::Black);

    rayTracer world(&img, sf::Vector3f(0,0,-10));

    world.lights.push_back(Light(sf::Vector3f(-5,0,5), sf::Color::Yellow));

    world.primitives.push_back(new sphere(sf::Vector3f(-7.5f,2.0f,5.0f),3.0f,1,sf::Color::Green));
    world.primitives.push_back(new sphere(sf::Vector3f(7.5f,2.0f,5.0f),3.0f,1,sf::Color::Blue));
    //world.primitives.push_back(new Box(sf::Vector3f(-7.5f,2.0f,5.0f),1.0f,.5,sf::Color::White));
    world.primitives.push_back(new Box(sf::Vector3f(0,-4,0),1.0f,1.5,sf::Color::Red));
    world.primitives.push_back(new Box(sf::Vector3f(1,-4,0),1.0f,1.5,sf::Color::Blue));
    world.primitives.push_back(new Box(sf::Vector3f(1,-3,0),1.0f,1.5,sf::Color::Green));
    world.primitives.push_back(new Box(sf::Vector3f(1,-2,0),1.0f,1.5,sf::Color::Blue));
    world.primitives.push_back(new Box(sf::Vector3f(0,-3,1),1.0f,1.5,sf::Color::Blue));
//    world.spheres.push_back(sphere(sf::Vector3f(7.5f,2.0f,1.0f),3,.7,sf::Color::Red));
//    world.spheres.push_back(sphere(sf::Vector3f(-100,0,50),50,.3,sf::Color::Yellow));
//    world.spheres.push_back(sphere(sf::Vector3f(-500,-100,900),500,.5,sf::Color::Green));

    sf::Vector3f movedist;



    sf::Event event;
    while (window.isOpen()){
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }

if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        movedist.z = .1;
    }if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        movedist.z = -.1;
    }if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        movedist.x = -.1;
    }if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        movedist.x = .1;
    }if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)){
        movedist.y = -.1;
    }if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
        movedist.y = .1;
    }

    world.moveCam(movedist);

    movedist = sf::Vector3f(0,0,0);

    world.render();

    sf::Texture tex;
    tex.loadFromImage(world.returnImage());

    sf::Sprite sprite;
    sprite.setTexture(tex);



        window.clear();
        window.draw(sprite);
        window.display();

    }
}
