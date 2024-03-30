#pragma once
#include "header.h"


//Функция для поиска лучшей вершины для удаления
int RemoveHighestPriorityChecker(Vector<sf::CircleShape>& TabelCircleShape, Vector<int>& AIChekers, Vector<int>& PlayerChekers, Vector<int>& FreeFields,bool move) {
	if (!move) {
		int delVertex = PlayerChekers[0];
		int score = INT_MAX;
		for (int i = 1; i < PlayerChekers.size(); i++) {
			int tempVertex = PlayerChekers[i];
			TabelCircleShape[tempVertex].setFillColor(sf::Color::Black);
			FreeFields.push_back(tempVertex);
			FreeFields.quickSort();
			PlayerChekers.erase(i);
			if (Evalution(TabelCircleShape, AIChekers, PlayerChekers) < score) {
				delVertex = tempVertex;
			}
			TabelCircleShape[tempVertex].setFillColor(sf::Color::Red);
			FreeFields.erase(binarySearch(FreeFields, tempVertex));
			PlayerChekers.push_back(tempVertex);
			PlayerChekers.quickSort();
		}
		return delVertex;
	}
	else {
		int delVertex = AIChekers[0];
		int score = INT_MIN;
		for (int i = 1; i < AIChekers.size(); i++) {
			int tempVertex = AIChekers[i];
			TabelCircleShape[tempVertex].setFillColor(sf::Color::Black);
			FreeFields.push_back(tempVertex);
			FreeFields.quickSort();
			AIChekers.erase(i);
			if (Evalution(TabelCircleShape, AIChekers, PlayerChekers) > score) {
				delVertex = tempVertex;
			}
			TabelCircleShape[tempVertex].setFillColor(sf::Color::Blue);
			FreeFields.erase(binarySearch(FreeFields, tempVertex));
			AIChekers.push_back(tempVertex);
			AIChekers.quickSort();
		}
		return delVertex;
	}	
}


void MakeMove_EarlyGame(Vector<sf::CircleShape>& TabelCircleShape, Vector<int>& Chekers, Vector<int>& FreeFields, int vertex, sf::Color color) {
	TabelCircleShape[vertex].setFillColor(color);
	Chekers.push_back(vertex);
	Chekers.quickSort();
	FreeFields.erase(binarySearch(FreeFields, vertex));
}

void UndoMove_EarlyGame(Vector<sf::CircleShape>& TabelCircleShape, Vector<int>& Chekers, Vector<int>& FreeFields, int vertex) {
	TabelCircleShape[vertex].setFillColor(sf::Color::Black);
	FreeFields.push_back(vertex);
	FreeFields.quickSort();
	Chekers.erase(binarySearch(Chekers, vertex));
}

void MakeMove_LateGame(Vector<sf::CircleShape>& TabelCircleShape, Vector<int>& Chekers, Vector<int>& FreeFields, int vertex, int move, sf::Color color) {
	TabelCircleShape[vertex].setFillColor(sf::Color::Black);
	TabelCircleShape[move].setFillColor(color);

	FreeFields.push_back(vertex);
	Chekers.push_back(move);
	FreeFields.quickSort();
	Chekers.quickSort();
	FreeFields.erase(binarySearch(FreeFields, move));
	Chekers.erase(binarySearch(Chekers, vertex));
	
}

void UndoMove_LateGame(Vector<sf::CircleShape>& TabelCircleShape, Vector<int>& Chekers, Vector<int>& FreeFields, int vertex, int move, sf::Color color) {
	TabelCircleShape[move].setFillColor(sf::Color::Black);
	TabelCircleShape[vertex].setFillColor(color);

	FreeFields.push_back(move);
	Chekers.push_back(vertex);
	FreeFields.quickSort();
	Chekers.quickSort();
	FreeFields.erase(binarySearch(FreeFields, vertex));
	Chekers.erase(binarySearch(Chekers, move));
}


//Функция для герации ходов для каждой фигуры.
void pushVer(int vertex, Vector<sf::CircleShape>& TabelCircleShape, Vector<int>& FieldsForMove) {
	FieldsForMove.push_back(vertex);
}
void generateMoves_helper(int vertex, Vector<sf::CircleShape>& TabelCircleShape, Vector<int>& FieldsForMove) {

	sf::Color Black = sf::Color::Black;
	switch (vertex)
	{
	case(0): {

		if (getColor(1, TabelCircleShape) == Black) {
			pushVer(1, TabelCircleShape, FieldsForMove);
		}
		else {
			if (getColor(2, TabelCircleShape) == Black) {
				pushVer(2, TabelCircleShape, FieldsForMove);
			}
		}

		if (getColor(3, TabelCircleShape) == Black) {
			pushVer(3, TabelCircleShape, FieldsForMove);
		}
		else {
			if (getColor(6, TabelCircleShape) == Black) {
				pushVer(6, TabelCircleShape, FieldsForMove);
			}
		}

		if (getColor(9, TabelCircleShape) == Black) {
			pushVer(9, TabelCircleShape, FieldsForMove);
		}
		else {
			if (getColor(21, TabelCircleShape) == Black) {
				pushVer(21, TabelCircleShape, FieldsForMove);
			}
		}
		break;
	}
	case(1): {
		if (getColor(0, TabelCircleShape) == Black) {
			pushVer(0, TabelCircleShape, FieldsForMove);
		}
		if (getColor(2, TabelCircleShape) == Black) {
			pushVer(2, TabelCircleShape, FieldsForMove);
		}
		if (getColor(4, TabelCircleShape) == Black) {
			pushVer(4, TabelCircleShape, FieldsForMove);
		}
		else if (getColor(7, TabelCircleShape) == Black) {
			pushVer(7, TabelCircleShape, FieldsForMove);
		}break;
	}
	case(2): {
		if (getColor(1, TabelCircleShape) == Black) {
			pushVer(1, TabelCircleShape, FieldsForMove);
		}
		else if (getColor(0, TabelCircleShape) == Black) {
			pushVer(0, TabelCircleShape, FieldsForMove);
		}
		if (getColor(5, TabelCircleShape) == Black) {
			pushVer(5, TabelCircleShape, FieldsForMove);
		}
		else if (getColor(8, TabelCircleShape) == Black) {
			pushVer(8, TabelCircleShape, FieldsForMove);
		}
		if (getColor(14, TabelCircleShape) == Black) {
			pushVer(14, TabelCircleShape, FieldsForMove);
		}
		else if (getColor(23, TabelCircleShape) == Black) {
			pushVer(23, TabelCircleShape, FieldsForMove);
		}break;
	}
	case(3): {
		if (getColor(0, TabelCircleShape) == Black) {
			pushVer(0, TabelCircleShape, FieldsForMove);
		}
		if (getColor(6, TabelCircleShape) == Black) {
			pushVer(6, TabelCircleShape, FieldsForMove);
		}
		if (getColor(4, TabelCircleShape) == Black) {
			pushVer(4, TabelCircleShape, FieldsForMove);
		}
		else if (getColor(5, TabelCircleShape) == Black) {
			pushVer(5, TabelCircleShape, FieldsForMove);
		}
		if (getColor(10, TabelCircleShape) == Black) {
			pushVer(10, TabelCircleShape, FieldsForMove);
		}
		else if (getColor(18, TabelCircleShape) == Black) {
			pushVer(18, TabelCircleShape, FieldsForMove);
		}break;
	}
	case(4): {
		if (getColor(3, TabelCircleShape) == Black) {
			pushVer(3, TabelCircleShape, FieldsForMove);
		}
		if (getColor(5, TabelCircleShape) == Black) {
			pushVer(5, TabelCircleShape, FieldsForMove);
		}
		if (getColor(1, TabelCircleShape) == Black) {
			pushVer(1, TabelCircleShape, FieldsForMove);
		}
		if (getColor(7, TabelCircleShape) == Black) {
			pushVer(7, TabelCircleShape, FieldsForMove);
		}break;
	}
	case(5): {
		if (getColor(2, TabelCircleShape) == Black) {
			pushVer(2, TabelCircleShape, FieldsForMove);
		}
		if (getColor(8, TabelCircleShape) == Black) {
			pushVer(8, TabelCircleShape, FieldsForMove);
		}
		if (getColor(4, TabelCircleShape) == Black) {
			pushVer(4, TabelCircleShape, FieldsForMove);
		}
		else if (getColor(3, TabelCircleShape) == Black) {
			pushVer(3, TabelCircleShape, FieldsForMove);
		}
		if (getColor(13, TabelCircleShape) == Black) {
			pushVer(13, TabelCircleShape, FieldsForMove);
		}
		else if (getColor(20, TabelCircleShape) == Black) {
			pushVer(20, TabelCircleShape, FieldsForMove);
		}break;
	}
	case(6): {
		if (getColor(3, TabelCircleShape) == Black) {
			pushVer(3, TabelCircleShape, FieldsForMove);
		}
		else {
			if (getColor(0, TabelCircleShape) == Black) {
				pushVer(0, TabelCircleShape, FieldsForMove);
			}
		}

		if (getColor(7, TabelCircleShape) == Black) {
			pushVer(7, TabelCircleShape, FieldsForMove);
		}
		else {
			if (getColor(8, TabelCircleShape) == Black) {
				pushVer(8, TabelCircleShape, FieldsForMove);
			}
		}

		if (getColor(11, TabelCircleShape) == Black) {
			pushVer(11, TabelCircleShape, FieldsForMove);
		}
		else {
			if (getColor(15, TabelCircleShape) == Black) {
				pushVer(15, TabelCircleShape, FieldsForMove);
			}
		}break;
	}
	case(7): {
		if (getColor(6, TabelCircleShape) == Black) {
			pushVer(6, TabelCircleShape, FieldsForMove);
		}
		if (getColor(8, TabelCircleShape) == Black) {
			pushVer(8, TabelCircleShape, FieldsForMove);
		}
		if (getColor(4, TabelCircleShape) == Black) {
			pushVer(4, TabelCircleShape, FieldsForMove);
		}
		else {
			if (getColor(1, TabelCircleShape) == Black) {
				pushVer(1, TabelCircleShape, FieldsForMove);
			}
		}break;
	}
	case(8): {
		if (getColor(7, TabelCircleShape) == Black) {
			pushVer(7, TabelCircleShape, FieldsForMove);
		}
		else {
			if (getColor(6, TabelCircleShape) == Black) {
				pushVer(6, TabelCircleShape, FieldsForMove);
			}
		}

		if (getColor(5, TabelCircleShape) == Black) {
			pushVer(5, TabelCircleShape, FieldsForMove);
		}
		else {
			if (getColor(2, TabelCircleShape) == Black) {
				pushVer(2, TabelCircleShape, FieldsForMove);
			}
		}

		if (getColor(12, TabelCircleShape) == Black) {
			pushVer(12, TabelCircleShape, FieldsForMove);
		}
		else {
			if (getColor(17, TabelCircleShape) == Black) {
				pushVer(17, TabelCircleShape, FieldsForMove);
			}
		}break;
	}
	case(9): {
		if (getColor(0, TabelCircleShape) == Black) {
			pushVer(0, TabelCircleShape, FieldsForMove);
		}
		if (getColor(21, TabelCircleShape) == Black) {
			pushVer(21, TabelCircleShape, FieldsForMove);
		}
		if (getColor(10, TabelCircleShape) == Black) {
			pushVer(10, TabelCircleShape, FieldsForMove);
		}
		else if (getColor(11, TabelCircleShape) == Black) {
			pushVer(11, TabelCircleShape, FieldsForMove);
		}break;
	}
	case(10): {
		if (getColor(3, TabelCircleShape) == Black) {
			pushVer(3, TabelCircleShape, FieldsForMove);
		}
		if (getColor(18, TabelCircleShape) == Black) {
			pushVer(18, TabelCircleShape, FieldsForMove);
		}
		if (getColor(9, TabelCircleShape) == Black) {
			pushVer(9, TabelCircleShape, FieldsForMove);
		}
		if (getColor(11, TabelCircleShape) == Black) {
			pushVer(11, TabelCircleShape, FieldsForMove);
		}break;
	}
	case(11): {
		if (getColor(10, TabelCircleShape) == Black) {
			pushVer(10, TabelCircleShape, FieldsForMove);
		}
		else if (getColor(9, TabelCircleShape) == Black) {
			pushVer(9, TabelCircleShape, FieldsForMove);
		}
		if (getColor(6, TabelCircleShape) == Black) {
			pushVer(6, TabelCircleShape, FieldsForMove);
		}
		if (getColor(15, TabelCircleShape) == Black) {
			pushVer(15, TabelCircleShape, FieldsForMove);
		}break;
	}
	case(12): {
		if (getColor(8, TabelCircleShape) == Black) {
			pushVer(8, TabelCircleShape, FieldsForMove);
		}
		if (getColor(17, TabelCircleShape) == Black) {
			pushVer(17, TabelCircleShape, FieldsForMove);
		}
		if (getColor(13, TabelCircleShape) == Black) {
			pushVer(13, TabelCircleShape, FieldsForMove);
		}
		else if (getColor(14, TabelCircleShape) == Black) {
			pushVer(14, TabelCircleShape, FieldsForMove);
		}break;
	}
	case(13): {
		if (getColor(12, TabelCircleShape) == Black) {
			pushVer(12, TabelCircleShape, FieldsForMove);
		}
		if (getColor(14, TabelCircleShape) == Black) {
			pushVer(14, TabelCircleShape, FieldsForMove);
		}
		if (getColor(5, TabelCircleShape) == Black) {
			pushVer(5, TabelCircleShape, FieldsForMove);
		}
		if (getColor(20, TabelCircleShape) == Black) {
			pushVer(20, TabelCircleShape, FieldsForMove);
		}break;
	}
	case(14): {
		if (getColor(2, TabelCircleShape) == Black) {
			pushVer(2, TabelCircleShape, FieldsForMove);
		}
		if (getColor(23, TabelCircleShape) == Black) {
			pushVer(23, TabelCircleShape, FieldsForMove);
		}
		if (getColor(13, TabelCircleShape) == Black) {
			pushVer(13, TabelCircleShape, FieldsForMove);
		}
		else if (getColor(12, TabelCircleShape) == Black) {
			pushVer(12, TabelCircleShape, FieldsForMove);
		}break;
	}
	case(15): {
		if (getColor(18, TabelCircleShape) == Black) {
			pushVer(18, TabelCircleShape, FieldsForMove);
		}
		else if (getColor(21, TabelCircleShape) == Black) {
			pushVer(21, TabelCircleShape, FieldsForMove);
		}
		if (getColor(11, TabelCircleShape) == Black) {
			pushVer(11, TabelCircleShape, FieldsForMove);
		}
		else if (getColor(6, TabelCircleShape) == Black) {
			pushVer(6, TabelCircleShape, FieldsForMove);
		}
		if (getColor(16, TabelCircleShape) == Black) {
			pushVer(16, TabelCircleShape, FieldsForMove);
		}
		else if (getColor(17, TabelCircleShape) == Black) {
			pushVer(17, TabelCircleShape, FieldsForMove);
		}break;
	}
	case(16): {
		if (getColor(15, TabelCircleShape) == Black) {
			pushVer(15, TabelCircleShape, FieldsForMove);
		}
		if (getColor(17, TabelCircleShape) == Black) {
			pushVer(17, TabelCircleShape, FieldsForMove);
		}
		if (getColor(19, TabelCircleShape) == Black) {
			pushVer(19, TabelCircleShape, FieldsForMove);
		}
		else if (getColor(22, TabelCircleShape) == Black) {
			pushVer(22, TabelCircleShape, FieldsForMove);
		}break;
	}
	case(17): {
		if (getColor(16, TabelCircleShape) == Black) {
			pushVer(16, TabelCircleShape, FieldsForMove);
		}
		else if (getColor(15, TabelCircleShape) == Black) {
			pushVer(15, TabelCircleShape, FieldsForMove);
		}
		if (getColor(12, TabelCircleShape) == Black) {
			pushVer(12, TabelCircleShape, FieldsForMove);
		}
		else if (getColor(8, TabelCircleShape) == Black) {
			pushVer(8, TabelCircleShape, FieldsForMove);
		}
		if (getColor(20, TabelCircleShape) == Black) {
			pushVer(20, TabelCircleShape, FieldsForMove);
		}
		else if (getColor(23, TabelCircleShape) == Black) {
			pushVer(23, TabelCircleShape, FieldsForMove);
		}break;
	}
	case(18): {
		if (getColor(21, TabelCircleShape) == Black) {
			pushVer(21, TabelCircleShape, FieldsForMove);
		}
		if (getColor(15, TabelCircleShape) == Black) {
			pushVer(15, TabelCircleShape, FieldsForMove);
		}
		if (getColor(19, TabelCircleShape) == Black) {
			pushVer(19, TabelCircleShape, FieldsForMove);
		}
		else if (getColor(20, TabelCircleShape) == Black) {
			pushVer(20, TabelCircleShape, FieldsForMove);
		}
		if (getColor(10, TabelCircleShape) == Black) {
			pushVer(10, TabelCircleShape, FieldsForMove);
		}
		else if (getColor(3, TabelCircleShape) == Black) {
			pushVer(3, TabelCircleShape, FieldsForMove);
		}break;
	}
	case(19): {
		if (getColor(18, TabelCircleShape) == Black) {
			pushVer(18, TabelCircleShape, FieldsForMove);
		}
		if (getColor(20, TabelCircleShape) == Black) {
			pushVer(20, TabelCircleShape, FieldsForMove);
		}
		if (getColor(16, TabelCircleShape) == Black) {
			pushVer(16, TabelCircleShape, FieldsForMove);
		}
		if (getColor(22, TabelCircleShape) == Black) {
			pushVer(22, TabelCircleShape, FieldsForMove);
		}break;
	}
	case(20): {
		if (getColor(17, TabelCircleShape) == Black) {
			pushVer(17, TabelCircleShape, FieldsForMove);
		}
		if (getColor(23, TabelCircleShape) == Black) {
			pushVer(23, TabelCircleShape, FieldsForMove);
		}
		if (getColor(19, TabelCircleShape) == Black) {
			pushVer(19, TabelCircleShape, FieldsForMove);
		}
		else if (getColor(18, TabelCircleShape) == Black) {
			pushVer(18, TabelCircleShape, FieldsForMove);
		}break;
	}
	case(21): {
		if (getColor(22, TabelCircleShape) == Black) {
			pushVer(22, TabelCircleShape, FieldsForMove);
		}
		else {
			if (getColor(23, TabelCircleShape) == Black) {
				pushVer(23, TabelCircleShape, FieldsForMove);
			}
		}

		if (getColor(9, TabelCircleShape) == Black) {
			pushVer(9, TabelCircleShape, FieldsForMove);
		}
		else {
			if (getColor(0, TabelCircleShape) == Black) {
				pushVer(0, TabelCircleShape, FieldsForMove);
			}
		}

		if (getColor(18, TabelCircleShape) == Black) {
			pushVer(18, TabelCircleShape, FieldsForMove);
		}
		else {
			if (getColor(15, TabelCircleShape) == Black) {
				pushVer(15, TabelCircleShape, FieldsForMove);
			}
		}break;
	}
	case(22): {
		if (getColor(21, TabelCircleShape) == Black) {
			pushVer(21, TabelCircleShape, FieldsForMove);
		}
		if (getColor(23, TabelCircleShape) == Black) {
			pushVer(23, TabelCircleShape, FieldsForMove);
		}
		if (getColor(19, TabelCircleShape) == Black) {
			pushVer(19, TabelCircleShape, FieldsForMove);
		}
		else if (getColor(16, TabelCircleShape) == Black) {
			pushVer(16, TabelCircleShape, FieldsForMove);
		}break;
	}
	case(23): {
		if (getColor(22, TabelCircleShape) == Black) {
			pushVer(22, TabelCircleShape, FieldsForMove);
		}
		else {
			if (getColor(21, TabelCircleShape) == Black) {
				pushVer(21, TabelCircleShape, FieldsForMove);
			}
		}

		if (getColor(14, TabelCircleShape) == Black) {
			pushVer(14, TabelCircleShape, FieldsForMove);
		}
		else {
			if (getColor(2, TabelCircleShape) == Black) {
				pushVer(2, TabelCircleShape, FieldsForMove);
			}
		}

		if (getColor(20, TabelCircleShape) == Black) {
			pushVer(20, TabelCircleShape, FieldsForMove);
		}
		else {
			if (getColor(17, TabelCircleShape) == Black) {
				pushVer(17, TabelCircleShape, FieldsForMove);
			}
		}break;
	}
	default:
		throw std::out_of_range("Нет такой вершины");
		break;
	}
}
Vector<int> generateMoves(Vector<sf::CircleShape>& TabelCircleShape, int vertex) {
	Vector<int> moves;
	generateMoves_helper(vertex, TabelCircleShape, moves);
	return moves;
}
