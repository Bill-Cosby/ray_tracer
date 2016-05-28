#ifndef RAYTRACER_HPP_INCLUDED
#define RAYTRACER_HPP_INCLUDED
#include "light.hpp"

class rayTracer
{
public:
    rayTracer(sf::Image* Timg, sf::Vector3f camera);

    std::vector<sphere> spheres;
    std::vector<Light> lights;

    sf::Image returnImage(){return *img;}

    sf::Color traceRay(Ray& ray, int depth);
    void render();

    sf::Vector3f cameraPos;
private:

    int ViewPlaneX1 = -8,ViewPlaneX2 = 8, ViewPlaneY1 = 5, ViewPlaneY2 = -5;
    int nextLine = 0;
    int bufferIndex = 0;

    float DeltaX = (ViewPlaneX2 - ViewPlaneX1) / 800;
    float DeltaY = (ViewPlaneY2 - ViewPlaneY1) / 600;

    int currentX = 0;
    int currentY = 5;


    sphere* getNearestSphere(Ray& ray, float& distanceToIntersect);
    sf::Color calculateLight(sphere Sphere, sf::Vector3f& intersection, sf::Vector3f rayDirection);

    sf::Image* img;

};

#endif // RAYTRACER_HPP_INCLUDED
