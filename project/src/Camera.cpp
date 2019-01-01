#include "Camera.h"

Camera::Camera(Vector2f pos, float scale)
{
    m_transform.Translate(pos);
    Vector2f scaleVec(scale, scale);
    m_transform.Scale(scaleVec);
}

Camera::~Camera()
{
    //dtor
}
