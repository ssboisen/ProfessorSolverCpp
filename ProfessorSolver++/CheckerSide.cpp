#include "stdafx.h"
#include "CheckerSide.h"
#include <iostream>

CheckerSide::CheckerSide(BodyPart bodyPart, Color color) : m_bodyPart(bodyPart), m_color(color) { }

bool CheckerSide::operator==( const CheckerSide& other )
{
	return m_bodyPart == other.m_bodyPart && m_color == other.m_color;
}

BodyPart CheckerSide::GetBodyPart() const
{
	return m_bodyPart;
}

Color CheckerSide::GetColor() const
{
	return m_color;
}

std::ostream& operator<<( std::ostream& o, const CheckerSide& cs )
{
	return o << cs.GetColor() << " " << cs.GetBodyPart();
}