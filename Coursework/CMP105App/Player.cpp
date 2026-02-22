#include "Player.h"
#include <iostream>

Player::Player()
{
	if (!m_texture.loadFromFile("gfx/dino1.png"))
		std::cerr << "No dino texture. sad";

	setTexture(&m_texture);
	setSize({ 36,36 });
	setCollisionBox({ {6,6}, { 24,25 } });
	setPosition({ 50,0 });
	m_isOnGround = false;
	setTextureRect({ { 0,0 }, { 24,24 } });
}

void Player::handleInput(float dt)
{
	m_acceleration = { 0,0 };

	if (m_input->isKeyDown(sf::Keyboard::Scancode::A))
		m_acceleration.x -= SPEED;
	if (m_input->isKeyDown(sf::Keyboard::Scancode::D))
		m_acceleration.x += SPEED;
	if (m_isOnGround && m_input->isKeyDown(sf::Keyboard::Scancode::W))
	{
		m_velocity.y -= JUMP_FORCE;
		m_isOnGround = false;
	}
	if (m_input->isKeyDown(sf::Keyboard::Scancode::R))	// Reset (for debugging)
	{
		setPosition({ 50,0 });
		m_velocity = { 0,0 };
	}

	if (m_input->isPressed(sf::Keyboard::Scancode::F))
	{
		if ((m_pFlag->getPosition() - getPosition()).length() < INTERACTION_RANGE)
		{
			std::cout << "flag interaction\n";
		}
		if ((m_pSwitch->getPosition() - getPosition()).length() < INTERACTION_RANGE)
		{
			std::cout << "switch interaction\n";
			m_pSwitch->toggle();
		}
	}
}

void Player::update(float dt)
{
	// newtonian model
	m_acceleration.y += GRAVITY;
	m_velocity += dt * m_acceleration;
	m_oldPosition = getPosition();
	move(m_velocity);
}

void Player::collisionResponse(GameObject& collider)
{
	
	sf::FloatRect playerController = getCollisionBox();
	sf::FloatRect wallBounds = collider.getCollisionBox();
	auto overlap = playerController.findIntersection(wallBounds);
	if (!overlap) return;
	

	float oldBottom = m_oldPosition.y + playerController.size.y;
	float tileTop = wallBounds.position.y;


	if( oldBottom <= tileTop)
	{ 
		if (m_velocity.y > 0)
		{
			m_velocity.y = 0;
			setPosition({ getPosition().x, collider.getPosition().y - getCollisionBox().size.y });
			m_isOnGround = true;
		}
	}
	else
	{
		m_velocity.x *= -COEFF_RESTITUTION;
		// getting stuck in wall prevention
		if (playerController.position.x < wallBounds.position.x)
		{
			setPosition({ getPosition().x - overlap->size.x, getPosition().y });
		}
		else
		{
			setPosition({ getPosition().x + overlap->size.x, getPosition().y });
		}
	}
	
}
