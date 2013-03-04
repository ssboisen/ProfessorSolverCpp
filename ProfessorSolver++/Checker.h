#pragma once
#include <vector>
#include "CheckerSide.h"
#include <iostream>
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
	static int id_counter;
	int id;
};



std::ostream& operator<<( std::ostream& o, const Checker& c);