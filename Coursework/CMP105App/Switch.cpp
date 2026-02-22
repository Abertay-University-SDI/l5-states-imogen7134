#include "Switch.h"

Switch::Switch()
{
	m_isOn = false;
}

Switch::~Switch()
{
}

void Switch::toggle()
{
	m_isOn = !m_isOn;
	if (m_isOn) setTextureRect(m_on);
	else setTextureRect(m_off);

}

void Switch::setState(bool state)
{
	m_isOn = state;
	if (state == true)
	{
		setTextureRect(m_on);
	}
	else
	{
		setTextureRect(m_off);
	}
}
