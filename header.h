#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Vector.h"
#include "Func.h"
#include <chrono>

struct gameStats {
	bool isPlaced = false;
	bool move = true; //означает что игру начинает игрок
	bool mill = false;
	short AIC = 9; //Количество стартовых фишек бота
	short PC = AIC; //Количество стартовых фишек игрока
	bool Final = false;
	bool nowMove = false; 
	int devFreeVerIndex = -1; //чтобы мы понимали какую вершину удалять из fieldformove
	int nowVer = -1; //вершина с которой идет работа 
	int depth = 5;//глубина рекурсии

	friend std::ostream& operator<<(std::ostream& os, const gameStats& stats) {
		os << "isPlaced: " << stats.isPlaced << std::endl;
		os << "move: " << stats.move << std::endl;
		os << "mill: " << stats.mill << std::endl;
		os << "AIC: " << stats.AIC << std::endl;
		os << "PC: " << stats.PC << std::endl;
		os << "Final: " << stats.Final << std::endl;
		os << "nowMove: " << stats.nowMove << std::endl;
		os << "devFreeVer: " << stats.devFreeVerIndex << std::endl;
		os << "nowVer: " << stats.nowVer << std::endl;
		return os;
	}
};
struct MoveBeforeMinimax {
	int vertex;
	int move;
	int evaluation;
	bool isMill;
	int delver;
	MoveBeforeMinimax& operator=(const MoveBeforeMinimax& other) {
		if (this != &other) {
			vertex = other.vertex;
			move = other.move;
			evaluation = other.evaluation;
			isMill = other.isMill;
			delver = other.delver;
		}
		return *this;
	}
	MoveBeforeMinimax(): vertex(-1), move(-1), evaluation(0), isMill(false), delver(-1) {}
};