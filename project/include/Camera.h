#ifndef CAMERA_H
#define CAMERA_H

class Camera
{
    public:
        Camera(float x, float y, float scale);
        virtual ~Camera();

    protected:

    private:

    float m_x, m_y, m_scale;
    float m_origin_x, m_origin_y;
};



#endif // CAMERA_H
