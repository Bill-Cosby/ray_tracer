#include "rayTracer.hpp"

void rayTracer::render()
{
    for (int y = -300; y < 300; y++){
        for (int x = -400; x < 400; x++){
            sf::Vector3f dir = sf::Vector3f(x,y,0) - cameraPos;
            dir = normalize(dir);

            Ray ray(cameraPos, dir);

            img->setPixel(x+400,y+300,traceRay(ray,0));
        }
    }
}

sf::Color rayTracer::traceRay(Ray& ray, int depth)
{
    if (depth == 3)return sf::Color(0,0,0);

    sf::Color litColor, reflectedColor;
    float distanceToIntersect = 1000;

    sf::Vector3f intersection;
    sphere* nearestSphere = NULL;

    nearestSphere = getNearestSphere(ray, distanceToIntersect);

    if (nearestSphere!= NULL)return nearestSphere->color;
}

sphere* rayTracer::getNearestSphere(Ray& ray, float& distanceToIntersect)
{
    sphere* nearestSphere = NULL;

    float dist = 1000;

    for (sphere &tSphere : spheres){
        if (tSphere.intersect(ray,dist)){
            if (dist < distanceToIntersect and dist > 0){
                distanceToIntersect = dist;
                nearestSphere = &tSphere;
            }
        }
    }

    return nearestSphere;
}

rayTracer::rayTracer(sf::Image* image, sf::Vector3f cam)
{
    img = image;
    cameraPos = cam;
}
