#ifndef CAMERA_H
#define CAMERA_H

#include "Matrix.h"

class Camera
{
    public:
        Camera(Vector2f pos, float scale);
        virtual ~Camera();

        inline Matrix3x3f& GetTransform()
        { return m_transform; }

    protected:

    private:

    Matrix3x3f m_transform;
};



#endif // CAMERA_H
