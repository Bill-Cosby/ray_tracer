#include "sphere.hpp"

bool sphere::intersect(Ray& ray, float& dist)
{
    bool result = false;

    sf::Vector3f e = pos - ray.GetOrigin();
    float        a = dotProduct(ray.GetDirection(),e);

    float f = pow(radius,2) - dotProduct(e,e) + (a * a);

    if (f < 0.0f)return result;
    else{
        float t = a - sqrtf(f);

        if (t > 0.1f and t < 1000){
            dist = t;
            result = true;
        }
    }
    return result;
}
