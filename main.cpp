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

void rayCast(sf::Image& img)
{

    sf::Vector3f ray;

    sf::Vector3f eye(300,400,0);

    sf::Vector3f sphere(-100,-100,150);
    sf::Vector3f sphere2(010,010,100);

    sf::Vector3f refractionRay;

    bool hitSphere = false;

    for (int y = 0; y < 600; y++){
            for (int x = 0; x < 800; x++){
                ray = sf::Vector3f (x-eye.x,y-eye.y, 50-eye.z);
                while (magnitude(ray)<1000){

                    ray.x*=1.01;
                    ray.y*=1.01;
                    ray.z*=1.01;

                    if (distance(ray, sphere2) <= 100){
                        img.setPixel(x,y,sf::Color::Blue);
                        hitSphere = true;
                    }

                    if (distance(ray, sphere) <= 50){

                        if (hitSphere){
                            sf::Color temp = sf::Color::Blue;
                            //std::cout << (int)temp.r << "," << (int)temp.g << "," << (int)temp.b << std::endl;
                            temp.r += sf::Color::Red.r;
                            temp.g += sf::Color::Red.g;
                            temp.b += sf::Color::Red.b;
                            //std::cout << (int)temp.r << "," << (int)temp.g << "," << (int)temp.b << std::endl;
                            img.setPixel(x,y,temp);
                        }
                        else{
                            img.setPixel(x,y,sf::Color::Red);
                        }
                    }
                    //refractionRay =
                }
            }
        }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600), "ray tracing");

    sf::Event event;

    sf::Image img;

    img.create(800,600,sf::Color::White);

    rayCast(img);

    while (window.isOpen()){
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        window.clear(sf::Color::White);
        sf::Texture tex;
        tex.loadFromImage(img);
        sf::Sprite sprite;
        sprite.setTexture(tex);
        window.draw(sprite);
        window.display();
    }
}
