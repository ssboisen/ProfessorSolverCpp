#include "stdafx.h"
#include "Checker.h"
#include "CheckerSide.h"
#include "Domain.h"

int Checker::id_counter = 1;

Checker::Checker( CheckerSide top, CheckerSide right, CheckerSide bottom, CheckerSide left ) :topIndex(0) {
	m_checkerSides.push_back(top);
	m_checkerSides.push_back(right);
	m_checkerSides.push_back(bottom);
	m_checkerSides.push_back(left);
	id = id_counter++;
}

void Checker::TurnRight()
{
	topIndex = (topIndex + 1) % 4;
}

const CheckerSide& Checker::GetTop() const
{
	return m_checkerSides[topIndex];
}

const CheckerSide& Checker::GetRight() const
{
	return m_checkerSides[(topIndex + 1) % 4];
}

const CheckerSide& Checker::GetBottom() const
{
	return m_checkerSides[(topIndex + 2) % 4];
}

const CheckerSide& Checker::GetLeft() const
{
	return m_checkerSides[(topIndex + 3) % 4];
}

bool Checker::operator==( const Checker& other )
{
	return id == other.id;
}

std::ostream& operator<<( std::ostream& o, const Checker& c)
{
	return o << "Top: " << c.GetTop() << ";Right: " << c.GetRight() << ";Bottom: " << c.GetBottom() << ";Left: " << c.GetLeft() << std::endl;
}