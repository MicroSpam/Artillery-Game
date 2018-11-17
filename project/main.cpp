#include"Application.h"

int main(int argc, char** argv)
{
    Application m_app;
    m_app.Init();
    m_app.Update();
    m_app.Close();
    return 0;
}
