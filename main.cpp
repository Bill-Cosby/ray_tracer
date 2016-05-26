#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>

float magnitude(sf::Vector3f p)
{
    return sqrt(pow(p.x,2)+pow(p.y,2)+pow(p.z,2));
}

float distance(sf::Vector3f p, sf::Vector3f p2)
{
    return sqrt(pow(p.x - p2.x,2) + pow(p.y - p2.y,2) + pow(p.z - p2.z,2));
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600), "ray tracing");

    sf::Event event;

    sf::Vector3f ray;

    sf::Vector3f sphere(300,400,50);
    float radius(50);

    sf::Image img;

    img.create(800,600,sf::Color::Black);

        for (int y = 0; y < 600; y++){
            for (int x = 0; x < 800; x++){
                ray = sf::Vector3f (x,y,50);
                while (magnitude(ray)<1000){
                    ray.x*=1.1;
                    ray.y*=1.1;
                    ray.z*=1.1;
                    if (abs(distance(ray, sphere) - 50) < 5){
                        img.setPixel(x,y,sf::Color::Red);
                    }
                }
            }
        }

        img.saveToFile("picture.png");

//    while (window.isOpen()){
//        while (window.pollEvent(event)){
//            if (event.type == sf::Event::Closed){
//                window.close();
//            }
//        }
//    }
}
