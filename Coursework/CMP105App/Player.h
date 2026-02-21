#pragma once
#include "Framework/GameObject.h"
class Player : public GameObject
{
public:
    Player();

    void handleInput(float dt) override;
    void update(float dt) override;
    void collisionResponse(GameObject& collider) override;
    void setFlag(GameObject* flag) { m_pFlag = flag; };
    void setSwitch(GameObject* pSwitch) { m_pSwitch = pSwitch; };
private:
    sf::Texture m_texture;
    sf::Vector2f m_acceleration;
    bool m_isOnGround = false;

    const float GRAVITY = 10.f;
    const float SPEED = 5.f;
    const float JUMP_FORCE = 6.0f;
    const float COEFF_RESTITUTION = 0.9f;

    sf::Vector2f m_oldPosition;
    GameObject* m_pFlag;
    GameObject* m_pSwitch;
    
};

