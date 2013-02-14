#include <vector>
#include <algorithm>
#include <iostream>
enum BodyPart
{
	Top,
	Bottom
};

std::ostream& operator<< (std::ostream& os, BodyPart bp) {

	switch (bp) {
	case Top:
		return os << "Top";
	case Bottom:
		return os << "Bottom";
	}
	return os;
}

enum Color
{
	Brown,
	Green,
	Purple,
	Blue
};

std::ostream& operator<< (std::ostream& os, Color color) {

	switch (color) {
	case Brown:
		return os << "Brown";
	case Green:
		return os << "Green";
	case Purple:
		return os << "Purple";
	case Blue:
		return os << "Blue";
	}
	return os;
}

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

class Checker
{
public:
	Checker(CheckerSide top, CheckerSide right, CheckerSide bottom, CheckerSide left);
	void TurnRight();
	const CheckerSide& GetTop() const;
	const CheckerSide& GetRight() const;
	const CheckerSide& GetBottom() const;
	const CheckerSide& GetLeft() const;
	bool operator== (const Checker& other);

private:
	std::vector<CheckerSide> m_checkerSides;
	int topIndex;

};

Checker::Checker( CheckerSide top, CheckerSide right, CheckerSide bottom, CheckerSide left ) :topIndex(0) {
	m_checkerSides.push_back(top);
	m_checkerSides.push_back(right);
	m_checkerSides.push_back(bottom);
	m_checkerSides.push_back(left);
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
	return m_checkerSides[topIndex + 1];
}

const CheckerSide& Checker::GetBottom() const
{
	return m_checkerSides[topIndex + 2];
}

const CheckerSide& Checker::GetLeft() const
{
	return m_checkerSides[topIndex + 3];
}

bool Checker::operator==( const Checker& other )
{
	return std::equal(begin(m_checkerSides),end(m_checkerSides),begin(other.m_checkerSides));
}

std::ostream& operator<<( std::ostream& o, const Checker& c)
{
	return o << "Top: " << c.GetTop() << ";Right: " << c.GetRight() << ";Bottom: " << c.GetBottom() << ";Left: " << c.GetLeft() << std::endl;
}