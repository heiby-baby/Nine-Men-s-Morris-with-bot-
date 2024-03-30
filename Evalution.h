#pragma once
#include "header.h"
#include "FuncForEvalution.h"
int Evalution(Vector<sf::CircleShape>& TabelCircleShape, Vector<int>& AIChekers, Vector<int>& PlayerChekers)
{
	//score - оценка поля
	int score = 0;

	int aiPotentialMills = countPotentialMills(TabelCircleShape, sf::Color::Blue);
	int playerPotentialMills = countPotentialMills(TabelCircleShape, sf::Color::Red);

	score += (playerPotentialMills - aiPotentialMills) * 15;

	int aiMills = countMills(TabelCircleShape, sf::Color::Blue);
	int playerMills = countMills(TabelCircleShape, sf::Color::Red);

	score += (playerMills - aiMills) * 30;

	for (const auto& checker : AIChekers) {
		if (isCentralPosition(checker)) {
			score -= 3;
		}
		else if (isMiddlePosition(checker)) {
			score -= 2;
		}
		else {
			score--;
		}
	}
	for (const auto& checker : PlayerChekers) {
		if (isCentralPosition(checker)) {
			score += 3;
		}
		else if (isMiddlePosition(checker)) {
			score += 2;
		}
		else {
			score++;
		}
	}

	return score;
}