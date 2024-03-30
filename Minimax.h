
#pragma once
#include "header.h"
#include "FuncForMinimax.h"
//move == false   ai move else player move
MoveBeforeMinimax minimax(
	Vector<sf::CircleShape>& TabelCircleShape, 
	Vector<int>& AIChekers, 
	Vector<int>& PlayerChekers,
	Vector<int>& FreeFields,
	gameStats& gms, 
	int depth, bool
	move) {
	Vector<MoveBeforeMinimax> moveEvaluations;
	MoveBeforeMinimax evol{};
	if (depth == 0 || ((AIChekers.size() + gms.AIC) <= 2) || ((PlayerChekers.size() + gms.PC) <= 2)) {
		// ¬ернуть оценку текущего состо€ни€ доски
		evol.evaluation = Evalution(TabelCircleShape, AIChekers, PlayerChekers); // «амените это на вашу функцию оценки
		return evol;
	}
	//ранн€€ стади€ игры
	if (!gms.isPlaced) {
		if (!move) {
			for (int i = 0; i < FreeFields.size(); i++) {
				evol.vertex = FreeFields[i];
				gms.AIC--;
				MakeMove_EarlyGame(TabelCircleShape, AIChekers, FreeFields, evol.vertex, sf::Color::Blue);
				///проверка на окончание первой фазы игры
				if (gms.AIC == 0) gms.isPlaced = true;

				//провер€ем нет ли мельницы после нашего хода
				if (isMill(TabelCircleShape, evol.vertex)) {
					int delVerIsMill;
					evol.isMill = true;
					delVerIsMill = RemoveHighestPriorityChecker(TabelCircleShape, AIChekers, PlayerChekers,FreeFields,move);
					evol.delver = delVerIsMill;
					TabelCircleShape[delVerIsMill].setFillColor(sf::Color::Black);
					PlayerChekers.erase(binarySearch(PlayerChekers, delVerIsMill));
					FreeFields.push_back(delVerIsMill);
					FreeFields.quickSort();
					evol.evaluation = minimax(TabelCircleShape, AIChekers, PlayerChekers, FreeFields, gms, depth - 1, true).evaluation;
					FreeFields.erase(binarySearch(FreeFields, delVerIsMill));
					PlayerChekers.push_back(delVerIsMill);
					PlayerChekers.quickSort();
					TabelCircleShape[delVerIsMill].setFillColor(sf::Color::Red);

				}
				else evol.evaluation = minimax(TabelCircleShape, AIChekers, PlayerChekers, FreeFields, gms, depth - 1, true).evaluation;
				
				UndoMove_EarlyGame(TabelCircleShape, AIChekers, FreeFields, evol.vertex);
				gms.AIC++;
				gms.isPlaced = false;
				moveEvaluations.push_back(evol);
			}
		}
		else {
			for (int i = 0; i < FreeFields.size(); i++) {
				evol.vertex = FreeFields[i];
				gms.PC--;
				MakeMove_EarlyGame(TabelCircleShape, PlayerChekers, FreeFields, evol.vertex, sf::Color::Red);
				//провер€ем нет ли мельницы после нашего хода
				int delVerIsMill;
				if (isMill(TabelCircleShape, evol.vertex)) {
					delVerIsMill = RemoveHighestPriorityChecker(TabelCircleShape, AIChekers, PlayerChekers, FreeFields, move);
					TabelCircleShape[delVerIsMill].setFillColor(sf::Color::Black);
					AIChekers.erase(binarySearch(AIChekers, delVerIsMill));
					FreeFields.push_back(delVerIsMill);
					FreeFields.quickSort();
					evol.evaluation = minimax(TabelCircleShape, AIChekers, PlayerChekers, FreeFields, gms, depth - 1, false).evaluation;
					FreeFields.erase(binarySearch(FreeFields, delVerIsMill));
					AIChekers.push_back(delVerIsMill);
					AIChekers.quickSort();
					TabelCircleShape[delVerIsMill].setFillColor(sf::Color::Blue);
				}
				else {
					evol.evaluation = minimax(TabelCircleShape, AIChekers, PlayerChekers, FreeFields, gms, depth - 1, false).evaluation;
				}

				UndoMove_EarlyGame(TabelCircleShape, PlayerChekers, FreeFields, evol.vertex);
				gms.PC++;

				moveEvaluations.push_back(evol);
			}
		}
	}
	//поздн€€ игра
	else {
		if (!move) {
			for (int i = 0; i < AIChekers.size(); i++) {
				Vector<int> moves = generateMoves(TabelCircleShape, AIChekers[i]);
				evol.vertex = AIChekers[i];
				for (int i = 0; i < moves.size(); i++) {
					evol.move = moves[i];
					MakeMove_LateGame(TabelCircleShape, AIChekers, FreeFields, evol.vertex, evol.move, sf::Color::Blue);
					//обработка мельницы
					int delVerIsMill;
					if (isMill(TabelCircleShape, evol.move)) {
						delVerIsMill = RemoveHighestPriorityChecker(TabelCircleShape, AIChekers, PlayerChekers, FreeFields, move);
						evol.isMill = true;
						evol.delver = delVerIsMill;
						TabelCircleShape[delVerIsMill].setFillColor(sf::Color::Black);
						PlayerChekers.erase(binarySearch(PlayerChekers, delVerIsMill));
						FreeFields.push_back(delVerIsMill);
						FreeFields.quickSort();
						evol.evaluation = minimax(TabelCircleShape, AIChekers, PlayerChekers, FreeFields, gms, depth - 1, true).evaluation;
						PlayerChekers.push_back(delVerIsMill);
						PlayerChekers.quickSort();
						FreeFields.erase(binarySearch(FreeFields, delVerIsMill));
						TabelCircleShape[delVerIsMill].setFillColor(sf::Color::Red);

					}
					else {
						evol.evaluation = minimax(TabelCircleShape, AIChekers, PlayerChekers, FreeFields, gms, depth - 1, true).evaluation;
					}
					//---
					UndoMove_LateGame(TabelCircleShape, AIChekers, FreeFields, evol.vertex, evol.move, sf::Color::Blue);
					moveEvaluations.push_back(evol);
				}
			}
		}
		else {
			for (int i = 0; i < PlayerChekers.size(); i++) {
				Vector<int> moves = generateMoves(TabelCircleShape, PlayerChekers[i]);
				evol.vertex = PlayerChekers[i];
				for (int i = 0; i < moves.size(); i++) {
					evol.move = moves[i];
					MakeMove_LateGame(TabelCircleShape, PlayerChekers, FreeFields, evol.vertex, evol.move, sf::Color::Red);
					//обработка мельницы
					int delVerIsMill;
					if (isMill(TabelCircleShape, evol.move)) {
						delVerIsMill = RemoveHighestPriorityChecker(TabelCircleShape, AIChekers, PlayerChekers, FreeFields, move);
						TabelCircleShape[delVerIsMill].setFillColor(sf::Color::Black);
						AIChekers.erase(binarySearch(AIChekers, delVerIsMill));
						FreeFields.push_back(delVerIsMill);
						FreeFields.quickSort();
						evol.evaluation = minimax(TabelCircleShape, AIChekers, PlayerChekers, FreeFields, gms, depth - 1, false).evaluation;
						AIChekers.push_back(delVerIsMill);
						AIChekers.quickSort();
						FreeFields.erase(binarySearch(FreeFields, delVerIsMill));
						TabelCircleShape[delVerIsMill].setFillColor(sf::Color::Blue);
					}
					else {
						evol.evaluation = minimax(TabelCircleShape, AIChekers, PlayerChekers, FreeFields, gms, depth - 1, false).evaluation;
					}
					//---
					UndoMove_LateGame(TabelCircleShape, PlayerChekers, FreeFields, evol.vertex, evol.move, sf::Color::Red);
					moveEvaluations.push_back(evol);
				}
			}
		}
	}

	int bestMoveIndex = 0;
	for (int i = 1; i < moveEvaluations.size(); ++i) {
		if (!move && (moveEvaluations[i].evaluation < moveEvaluations[bestMoveIndex].evaluation)) {
			bestMoveIndex = i;
		}
		else if (move && (moveEvaluations[i].evaluation > moveEvaluations[bestMoveIndex].evaluation)) {
			bestMoveIndex = i;
		}
	}

	return moveEvaluations[bestMoveIndex];
}
