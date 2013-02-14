// ProfessorSolver++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Domain.h"

int main()
{
	using namespace std;

	vector<Checker> checkers;

#pragma region Checker Initialization

	checkers.push_back(Checker(
		CheckerSide(Bottom, Purple),
		CheckerSide(Top, Green),
		CheckerSide(Top, Blue),
		CheckerSide(Bottom, Brown)
		));

	checkers.push_back(Checker(
		CheckerSide(Bottom, Green),
		CheckerSide(Top, Brown),
		CheckerSide(Top, Purple),
		CheckerSide(Bottom, Blue)
		));

	checkers.push_back(Checker(
		CheckerSide(Bottom, Blue),
		CheckerSide(Top, Brown),
		CheckerSide(Top, Purple),
		CheckerSide(Bottom, Green)));

	checkers.push_back(Checker(
		CheckerSide(Bottom, Purple),
		CheckerSide(Top, Blue),
		CheckerSide(Top, Brown),
		CheckerSide(Bottom, Green)));


	checkers.push_back(Checker(
		CheckerSide(Bottom, Blue),
		CheckerSide(Top, Purple),
		CheckerSide(Top, Green),
		CheckerSide(Bottom, Brown)));

	checkers.push_back(Checker(
		CheckerSide(Bottom, Purple),
		CheckerSide(Top, Brown),
		CheckerSide(Top, Blue),
		CheckerSide(Bottom, Brown)));

	checkers.push_back(Checker(
		CheckerSide(Bottom, Blue),
		CheckerSide(Top, Green),
		CheckerSide(Top, Green),
		CheckerSide(Bottom, Brown)));

	checkers.push_back(Checker(
		CheckerSide(Bottom, Purple),
		CheckerSide(Top, Green),
		CheckerSide(Top, Blue),
		CheckerSide(Bottom, Brown)));


	checkers.push_back(Checker(
		CheckerSide(Bottom, Purple),
		CheckerSide(Top, Brown),
		CheckerSide(Top, Blue),
		CheckerSide(Bottom, Green)));

	checkers.push_back(Checker(
		CheckerSide(Bottom, Green),
		CheckerSide(Top, Blue),
		CheckerSide(Top, Purple),
		CheckerSide(Bottom, Brown)));

	checkers.push_back(Checker(
		CheckerSide(Bottom, Green),
		CheckerSide(Top, Green),
		CheckerSide(Top, Purple),
		CheckerSide(Bottom, Brown)));

	checkers.push_back(Checker(
		CheckerSide(Bottom, Brown),
		CheckerSide(Top, Brown),
		CheckerSide(Top, Blue),
		CheckerSide(Bottom, Blue)));


	checkers.push_back(Checker(
		CheckerSide(Bottom, Blue),
		CheckerSide(Top, Green),
		CheckerSide(Top, Purple),
		CheckerSide(Bottom, Green)));

	checkers.push_back(Checker(
		CheckerSide(Bottom, Brown),
		CheckerSide(Top, Purple),
		CheckerSide(Top, Blue),
		CheckerSide(Bottom, Green)));

	checkers.push_back(Checker(
		CheckerSide(Bottom, Green),
		CheckerSide(Top, Brown),
		CheckerSide(Top, Purple),
		CheckerSide(Bottom, Green)));

	checkers.push_back(Checker(
		CheckerSide(Bottom, Purple),
		CheckerSide(Top, Green),
		CheckerSide(Top, Brown),
		CheckerSide(Bottom, Brown)));
#pragma endregion Checker Initialization

	for(auto& c : checkers){
		cout << c << endl;
	}

	return 0;
}

