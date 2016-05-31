#ifndef RAYTRACER_HPP_INCLUDED
#define RAYTRACER_HPP_INCLUDED
#include "light.hpp"

class rayTracer
{
public:
    rayTracer(sf::Image* Timg, sf::Vector3f camera);

    std::vector<primitive*> primitives;
    std::vector<Light> lights;

    sf::Image returnImage(){return *img;}

    sf::Color traceRay(Ray& ray, int depth);
    void render();

    sf::Vector3f cameraPos;

    void moveCam(sf::Vector3f dist);

private:

    double ViewPlaneX1,ViewPlaneX2, ViewPlaneY1, ViewPlaneY2, ViewPlaneZ = 0;
    int nextLine = 0;
    int bufferIndex = 0;

    float DeltaX;
    float DeltaY;

    float currentX = 0;
    float currentY = 0;


    primitive* getNearestSphere(Ray& ray, float& distanceToIntersect);
    sf::Color calculateLight(primitive* Sphere, sf::Vector3f& intersection, sf::Vector3f rayDirection);

    rayTracer();

    sf::Image* img;
};

#endif // RAYTRACER_HPP_INCLUDED
