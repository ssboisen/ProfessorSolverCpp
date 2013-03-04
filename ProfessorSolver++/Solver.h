#pragma once
#include <vector>
#include "Checker.h"

class Solver
{
public:
	Solver(const std::vector<Checker*>& checkers);
	std::vector<std::vector<Checker>> Solve();
	~Solver(void);
private:
	void BuildSolutionsRecursively(std::vector<Checker*>& board, int solutionIndex, std::vector<Checker>& checkers, std::vector<std::vector<Checker>>& solutions);
	std::vector<Checker> FindMatchingChecker(std::vector<Checker*> board, int solutionIndex, std::vector<Checker>& checkers);
	bool IsValidSolution(std::vector<Checker>& solution);
	const std::vector<Checker*>& m_checkers;
};

