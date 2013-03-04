#pragma once
#include "Domain.h"

class CheckerSide
{
public:
	CheckerSide(BodyPart bodyPart, Color color);
	bool operator== (const CheckerSide& other);
	BodyPart GetBodyPart() const;
	Color GetColor() const;
private:
	BodyPart m_bodyPart;
	Color m_color;
};
std::ostream& operator<<( std::ostream& o, const CheckerSide& cs );