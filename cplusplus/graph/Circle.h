#pragma once
#include "Ellipse.h"
class Circle :
    public Ellipse
{
public:
    Circle(float radius) :Ellipse(radius, radius) {}
    virtual void render();
    //virtual void resize();
    //virtual (float radius);
protected:
    //float area;
};

