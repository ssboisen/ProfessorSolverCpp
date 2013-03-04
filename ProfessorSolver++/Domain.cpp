#include "stdafx.h"
#include <iostream>
#include "Domain.h"

std::ostream& operator<< (std::ostream& os, BodyPart bp) {

	switch (bp) {
	case Top:
		return os << "Top";
	case Bottom:
		return os << "Bottom";
	}
	return os;
}

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