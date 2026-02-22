#pragma once
#include "Framework/GameObject.h"
#include "Switch.h"
class Player : public GameObject
{
public:
    Player();

    void handleInput(float dt) override;
    void update(float dt) override;
    void collisionResponse(GameObject& collider) override;
    void setFlag(GameObject* flag) { m_pFlag = flag; };
    void setSwitch(Switch* pSwitch) { m_pSwitch = pSwitch; };
    bool getWantGameOver() { return m_wantsGameToEnd; };
    void setWantGameOver(bool isOver) { m_wantsGameToEnd = isOver; };
private:
    sf::Texture m_texture;
    sf::Vector2f m_acceleration;
    bool m_isOnGround = false;

    const float GRAVITY = 10.f;
    const float SPEED = 5.f;
    const float JUMP_FORCE = 6.0f;
    const float COEFF_RESTITUTION = 0.9f;
    const float INTERACTION_RANGE = 50.f;

    sf::Vector2f m_oldPosition;
    GameObject* m_pFlag;
    Switch* m_pSwitch;
    bool m_wantsGameToEnd = false;
   
};

