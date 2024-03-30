#pragma once
#include "header.h"

int isCentralPosition(int vertex) {

	Vector<int> CentralVertex = { 6,7,8,11,12,15,16,17 };
	bool CenVer = false;

	int low = 0;
	int high = CentralVertex.size() - 1;

	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (CentralVertex[mid] == vertex) {
			CenVer = true; // Ёлемент найден, возвращаем индекс
			CentralVertex.clear();
			return true;
		}
		else if (CentralVertex[mid] < vertex) {
			low = mid + 1; // »скомый элемент находитс€ во второй половине
		}
		else {
			high = mid - 1; // »скомый элемент находитс€ в первой половине
		}
	}
	CentralVertex.clear();
	return false;
}

int isMiddlePosition(int vertex) {

	Vector<int> ver = { 3,4,5,10,13,18,19,20 };
	bool CenVer = false;

	int low = 0;
	int high = ver.size() - 1;

	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (ver[mid] == vertex) {
			CenVer = true; // Ёлемент найден, возвращаем индекс
			ver.clear();
			return true;
		}
		else if (ver[mid] < vertex) {
			low = mid + 1; // »скомый элемент находитс€ во второй половине
		}
		else {
			high = mid - 1; // »скомый элемент находитс€ в первой половине
		}
	}
	ver.clear();
	return false;
	return false;
}

int countPotentialMills(const Vector<sf::CircleShape>& tableCircleShape, sf::Color color) {
	// —писок всех возможных мельниц
	Vector<Vector<int>> possibleMills = {
		{0,1,2}, {3,4,5}, {6,7,8}, {9,10,11}, {12,13,14}, {15,16,17}, {18,19,20}, {21,22,23},
		{0,9,21}, {3,10,18}, {6,11,15}, {1,4,7}, {16,19,22}, {8,12,17}, {5,13,20},{2,14,23},
		{0,3,6}, {2,5,8},{21,18,15},{17,20,23}
	};
	int potentialMills = 0;

	for (const auto& mill : possibleMills) {
		if (
			((tableCircleShape[mill[0]].getFillColor() == sf::Color::Black && tableCircleShape[mill[1]].getFillColor() == color && tableCircleShape[mill[2]].getFillColor() == color) ||
				(tableCircleShape[mill[0]].getFillColor() == color && tableCircleShape[mill[1]].getFillColor() == sf::Color::Black && tableCircleShape[mill[2]].getFillColor() == color) ||
				(tableCircleShape[mill[0]].getFillColor() == color && tableCircleShape[mill[1]].getFillColor() == color && tableCircleShape[mill[2]].getFillColor() == sf::Color::Black)
				) && !(tableCircleShape[mill[0]].getFillColor() == color && tableCircleShape[mill[1]].getFillColor() == color && tableCircleShape[mill[2]].getFillColor() == color)) {
			potentialMills++;
		}
	}
	return potentialMills;
}

int countMills(const Vector<sf::CircleShape>& tableCircleShape, sf::Color color) {
	Vector<Vector<int>> possibleMills = {
		{0,1,2}, {3,4,5}, {6,7,8}, {9,10,11}, {12,13,14}, {15,16,17}, {18,19,20}, {21,22,23},
		{0,9,21}, {3,10,18}, {6,11,15}, {1,4,7}, {16,19,22}, {8,12,17}, {5,13,20},{2,14,23},
		{0,3,6}, {2,5,8},{21,18,15},{17,20,23}
	};
	int Mills = 0;

	for (const auto& mill : possibleMills) {
		if (
			(tableCircleShape[mill[0]].getFillColor() == color && tableCircleShape[mill[1]].getFillColor() == color && tableCircleShape[mill[2]].getFillColor() == color)) {
			Mills++;
		}
	}
	return Mills;
}