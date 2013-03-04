#pragma once
#include <iostream>

enum BodyPart
{
	Top,
	Bottom
};

std::ostream& operator<< (std::ostream& os, BodyPart bp);

enum Color
{
	Brown,
	Green,
	Purple,
	Blue
};

std::ostream& operator<< (std::ostream& os, Color color);