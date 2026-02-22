#pragma once
#include "Framework/GameObject.h"
class Switch :
    public GameObject
{
public:
    Switch();
    ~Switch();
    void toggle();
    bool getState() { return m_isOn; };

private:

    bool m_isOn;
    sf::IntRect m_off = { {4 * 19,3 * 19}, {18,18} };
    sf::IntRect m_on = { {6 * 19,3 * 19},{18,18} };

};

