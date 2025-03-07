#pragma once
#include "Shape.h"
class Ellipse :
    public Shape
{
public:
    Ellipse(float maj, float minr);
    virtual void render();
    //父类有virtual，则子类可加可不加，为了可读性加上
protected:
    float major_axis, minor_axis;
};

