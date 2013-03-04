#include "stdafx.h"
#include "Solver.h"
#include <algorithm>
#include <ppl.h>
#include <concurrent_vector.h>
#include <thread>

Solver::Solver(std::vector<Checker>& checkers)
	:m_checkers(checkers)
{
}


Solver::~Solver(void)
{
}

std::vector<std::vector<Checker>> Solver::Solve()
{
	auto allSolutions = concurrency::concurrent_vector<std::vector<Checker>>();
	concurrency::parallel_for_each(begin(m_checkers),end(m_checkers), [&](Checker& checker) {
		std::vector<Checker> checkers;

		for(auto c : m_checkers)
			checkers.push_back(c);

		std::vector<std::vector<Checker>> solutions;
		auto board = std::vector<Checker*>(16);
		
		for (int i = 0; i < 4; i++)
		{
			board[0] = &checker;

			BuildSolutionsRecursively(board, 0, checkers, solutions);

			board[0]->TurnRight();
		}

		for(auto& solution : solutions)
		{
			allSolutions.push_back(std::move(solution));
		}
	});

	std::vector<std::vector<Checker>> finalSolution;

	for (auto& v : allSolutions)
	{
		finalSolution.push_back(std::move(v));
	}

	return std::move(finalSolution);
}

void Solver::BuildSolutionsRecursively(std::vector<Checker*>& board, int solutionIndex, std::vector<Checker>& checkers, std::vector<std::vector<Checker>>& solutions)
{
	auto nextIndex = solutionIndex + 1;
	auto matchingCheckers = FindMatchingCheckers(board, solutionIndex, checkers);
	for (auto nextChecker : matchingCheckers)
	{
		board[nextIndex] = &nextChecker;

		if (nextIndex == 15)
		{
			std::vector<Checker> solution;

			for(auto c : board)
				solution.push_back(*c);

			solutions.push_back(std::move(solution));
		}

		if (nextIndex < 15)
		{
			BuildSolutionsRecursively(board, nextIndex, checkers, solutions);
		}

		board[nextIndex] = nullptr;
	}
}

std::vector<Checker> Solver::FindMatchingCheckers(std::vector<Checker*> board, int solutionIndex, std::vector<Checker>& checkers)
{
	std::vector<Checker> matches;
	std::vector<Checker*> unusedCheckers;

	for(auto& c : checkers) {

		auto exist = std::any_of(begin(board), end(board), [&c] (Checker* c2) { 
			return c2 && c == (*c2); 
		});

		if(!exist) {
			unusedCheckers.push_back(&c);
		}
	}

	auto thisIndex = solutionIndex + 1;

	for (auto unusedChecker : unusedCheckers)
	{
		for (int i = 0; i < 4; i++)
		{
			if (thisIndex < 4) //first row
			{
				auto leftChecker = board[solutionIndex];

				if (leftChecker->GetRight().GetColor() == unusedChecker->GetLeft().GetColor() &&
					leftChecker->GetRight().GetBodyPart() != unusedChecker->GetLeft().GetBodyPart())
				{
					matches.push_back(*unusedChecker);
				}
			}

			else if (thisIndex % 4 == 0) //first column, in any other row
			{
				auto topChecker = board[thisIndex - 4];

				if (topChecker->GetBottom().GetColor() == unusedChecker->GetTop().GetColor()
					&& topChecker->GetBottom().GetBodyPart() != unusedChecker->GetTop().GetBodyPart())
				{
					matches.push_back(*unusedChecker);
				}
			}

			else //2nd-4th column in 2nd-4th row
			{
				auto leftChecker = board[thisIndex - 1];
				auto topChecker = board[thisIndex - 4];

				if (leftChecker->GetRight().GetColor() == unusedChecker->GetLeft().GetColor() &&
					leftChecker->GetRight().GetBodyPart() != unusedChecker->GetLeft().GetBodyPart() &&
					topChecker->GetBottom().GetColor() == unusedChecker->GetTop().GetColor() &&
					topChecker->GetBottom().GetBodyPart() != unusedChecker->GetTop().GetBodyPart())
				{
					matches.push_back(*unusedChecker);
				}
			}

			unusedChecker->TurnRight();
		}
	}

	return std::move(matches);
}

bool Solver::IsValidSolution( std::vector<Checker>& solution )
{
	for (int i = 1; i < solution.size(); i++)
	{
		auto currentChecker = solution[i];

		if (i < 4) //first row
		{
			auto leftChecker = solution[i - 1];

			if (leftChecker.GetRight().GetColor() != currentChecker.GetLeft().GetColor() ||
				leftChecker.GetRight().GetBodyPart() == currentChecker.GetLeft().GetBodyPart())
			{
				return false;
			}
		}

		else if (i % 4 == 0) //first column, in any other row
		{
			auto topChecker = solution[i - 4];

			if (topChecker.GetBottom().GetColor() != currentChecker.GetTop().GetColor() ||
				topChecker.GetBottom().GetBodyPart() == currentChecker.GetTop().GetBodyPart())
			{
				return false;
			}
		}

		else //2nd-4th column in 2nd-4th row
		{
			auto leftChecker = solution[i - 1];
			auto topChecker = solution[i - 4];

			if (leftChecker.GetRight().GetColor() != currentChecker.GetLeft().GetColor() ||
				leftChecker.GetRight().GetBodyPart() == currentChecker.GetLeft().GetBodyPart() ||
				topChecker.GetBottom().GetColor() != currentChecker.GetTop().GetColor() ||
				topChecker.GetBottom().GetBodyPart() == currentChecker.GetTop().GetBodyPart())
			{
				return false;
			}
		}
	}

	return true;
}
