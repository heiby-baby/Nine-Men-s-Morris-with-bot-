#pragma once
#include "header.h"
#include "Evalution.h"
using namespace std;
template<typename T>
int binarySearch(const Vector<T>& vector, const T& key) {
	int low = 0;
	int high = vector.size() - 1;

	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (vector[mid] == key) {
			return mid; // Ёлемент найден, возвращаем индекс
		}
		else if (vector[mid] < key) {
			low = mid + 1; // »скомый элемент находитс€ во второй половине
		}
		else {
			high = mid - 1; // »скомый элемент находитс€ в первой половине
		}
	}

	return -1; // Ёлемент не найден
}


bool isMill(const Vector<sf::CircleShape>& TabelCircleShape, int vertex)
{
	Vector<Vector<int>> Mills = {
		{0,1,2}, {3,4,5}, {6,7,8}, {9,10,11}, {12,13,14}, {15,16,17}, {18,19,20}, {21,22,23},
		{0,9,21}, {3,10,18}, {6,11,15}, {1,4,7}, {16,19,22}, {8,12,17}, {5,13,20},{2,14,23},
		{0,3,6}, {2,5,8},{21,18,15},{17,20,23}
	};

	Vector<Vector<int>> PossibleMills;

	for (const auto& mill : Mills) {
		bool found = false;
		for (int element : mill) {
			if (element == vertex) {
				found = true;
				break;
			}
		}
		if (found) {
			PossibleMills.push_back(mill);
		}
	}

	for (const auto& mill : PossibleMills) {
		if (TabelCircleShape[mill[0]].getFillColor() == TabelCircleShape[mill[1]].getFillColor()
			&& TabelCircleShape[mill[0]].getFillColor() == TabelCircleShape[mill[2]].getFillColor())
		{
			return true;
		}
	}

	return false;
}



//‘ункции дл€ отладки
void PrintColor(Vector<sf::CircleShape>& TabelCircleShape) {
	int j = 0;
	for (auto i : TabelCircleShape) {
		if (i.getFillColor() == sf::Color::Black) cout << "Black: " << j << endl;
		if (i.getFillColor() == sf::Color::Blue) cout << "Blue: " << j << endl;
		if (i.getFillColor() == sf::Color::Red) cout << "Red: " << j << endl;
		j++;
	}
}

inline void print_without_eval(Vector<int>& AIChekers, Vector<int>& PlayerChekers, Vector<int>& FreeFields) {
	std::cout << "FreeFields:    " << FreeFields.size() << " - " << FreeFields << std::endl;
	std::cout << "PlayerChekers: " << PlayerChekers.size() << " - " << PlayerChekers << std::endl;
	std::cout << "AIChekers:     " << AIChekers.size() << " - " << AIChekers << std::endl;
}

void print(Vector<sf::CircleShape>& TabelCircleShape, Vector<int>& AIChekers, Vector<int>& PlayerChekers, Vector<int>& FreeFields) {
	std::cout << "FreeFields:    " << FreeFields.size() << " - " << FreeFields << std::endl;
	std::cout << "PlayerChekers: " << PlayerChekers.size() << " - " << PlayerChekers << std::endl;
	std::cout << "AIChekers:     " << AIChekers.size() << " - " << AIChekers << std::endl;
	std::cout << "Evalution:     " << Evalution(TabelCircleShape, AIChekers, PlayerChekers) << std::endl;
}
