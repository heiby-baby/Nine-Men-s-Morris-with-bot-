#include "graficFunc.h"
#include "Evalution.h"
#include "Func.h"
#include "Minimax.h"
#include "alphabeta.h"	
using namespace std;
//на будущее
//заменить алгоритм быстрой сортировки на сортировку вставками


int main() {

	setlocale(0, "rus");
	//Графические и интерфейсные параметры
	const int Width = 1500;					// Параметры экрана
	const int Height = 1000;
	float circleRadius = 20;				// Параметры круга

	gameStats gamestats;

	//Вектор в котором хранятся графические объекты наших кругов;
	Vector<sf::CircleShape> TabelCircleShape;
	//Вектор в котором хранятся линии между кругами
	//Чисто графическая часть программы не влияющая на програмную
	Vector<sf::VertexArray> Lines;
	//Вектор в котором хранятся индексы кругов бота
	Vector<int> AIChekers;
	//Вектор в котором хранятся индексы кругов игрока
	Vector<int> PlayerChekers;
	//Вектор в которм хранятся индексы свободных кругов
	Vector<int> FreeFields = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23 };
	Vector<int> FieldsForMove;

	MoveBeforeMinimax AiMove;

	createGameTable(Lines, TabelCircleShape, circleRadius);
	//Основное окно

	sf::RenderWindow window(sf::VideoMode(Width, Height, 10000000000), "The best kursach ever"); //Создаем окно
	while (window.isOpen() && !gamestats.Final) {
		sf::Event event;
		//игрок
		if (gamestats.move == true || gamestats.mill) {
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
					sf::Vector2i mousePos = {sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y};
					//Проверка на мельницу
					if (gamestats.mill) {
						for (int i = 0; i < AIChekers.size(); i++) {
							if (TabelCircleShape[AIChekers[i]].getGlobalBounds().contains(mousePos.x, mousePos.y)) {
								TabelCircleShape[AIChekers[i]].setFillColor(sf::Color::Black);
								FreeFields.push_back(AIChekers[i]);
								FreeFields.quickSort();
								AIChekers.erase(i);
								gamestats.mill = false;
								if (AIChekers.size() + gamestats.AIC <= 2) {
									gamestats.Final = true;
								}
								break;
							}
						}
					}
					// Расставляем фигуры
					else if (!gamestats.isPlaced) {
						for (int i = 0; i < TabelCircleShape.size(); ++i) {
							if (TabelCircleShape[i].getGlobalBounds().contains(mousePos.x, mousePos.y) && TabelCircleShape[i].getFillColor() == sf::Color::Black) {
								// Изменяем цвет кружка на красный
								TabelCircleShape[i].setFillColor(sf::Color::Red);
								PlayerChekers.push_back(i);
								PlayerChekers.quickSort();
								FreeFields.erase(binarySearch(FreeFields, i));
								gamestats.move = false;
								gamestats.mill = isMill(TabelCircleShape, i);
								gamestats.PC--;
								break;
							}
						}
					}
					//choosing a chekers to move
					else if (!gamestats.nowMove) {
						//игрок
						if (gamestats.move) {
							for (int i = 0; i < PlayerChekers.size(); i++) {
								if (TabelCircleShape[PlayerChekers[i]].getGlobalBounds().contains(mousePos.x, mousePos.y)) {
									gamestats.nowMove = true;
									gamestats.nowVer = PlayerChekers[i];
									ShapeRepainting(PlayerChekers[i], TabelCircleShape, FieldsForMove);
									break;
								}
							}
						}
						if (FieldsForMove.size() == 0) {
							gamestats.nowMove = false;
						}
					}
					//ход
					else {
						//игрок
						for (int i = 0; i < FieldsForMove.size(); i++) {
							if (TabelCircleShape[FieldsForMove[i]].getGlobalBounds().contains(mousePos.x, mousePos.y)) {
								TabelCircleShape[gamestats.nowVer].setFillColor(sf::Color::Black);
								FreeFields.erase(binarySearch(FreeFields, FieldsForMove[i]));
								FreeFields.push_back(gamestats.nowVer);
								FreeFields.quickSort();
								TabelCircleShape[FieldsForMove[i]].setFillColor(sf::Color::Red);

								gamestats.devFreeVerIndex = i;
								gamestats.move = false;
								gamestats.nowMove = false;

								PlayerChekers.push_back(FieldsForMove[i]);
								PlayerChekers.quickSort();
								PlayerChekers.erase(binarySearch(PlayerChekers, gamestats.nowVer));
								if (isMill(TabelCircleShape, FieldsForMove[i])) {
									gamestats.mill = true;
									if (AIChekers.size() <= 2) gamestats.Final = true;
								}
								break;
							}
						}
						if (!gamestats.nowMove) {
							FieldsForMove.erase(gamestats.devFreeVerIndex);
							gamestats.devFreeVerIndex = -1;
							for (auto i : FieldsForMove) {
								TabelCircleShape[i].setFillColor(sf::Color::Black);
							}
							FieldsForMove.clear();
						}
					}
				}
				else if (event.type == sf::Event::Closed) window.close();
			}
		}
		//бот
		else {
			gamestats.depth = 3;
			auto start = std::chrono::high_resolution_clock::now(); // Запуск таймера
			//AiMove = minimax(TabelCircleShape, AIChekers, PlayerChekers, FreeFields, gamestats, gamestats.depth, false);
			AiMove = alphabeta(TabelCircleShape, AIChekers, PlayerChekers, FreeFields, gamestats, gamestats.depth, INT16_MIN, INT16_MAX , false);
			auto end = std::chrono::high_resolution_clock::now(); // Остановка таймера
			auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(end - start); // Преобразование продолжительности в секунды
			std::cout << "alphabeta выполнялась " << duration.count() << " секунд" << std::endl;

			std::cout << AiMove.vertex << " " << AiMove.move << endl;

			if (gamestats.isPlaced == false) {
				gamestats.AIC--;
				MakeMove_EarlyGame(TabelCircleShape, AIChekers, FreeFields, AiMove.vertex, sf::Color::Blue);
				if (gamestats.AIC == 0 && gamestats.PC == 0) gamestats.isPlaced = true;
			}
			else {
				MakeMove_LateGame(TabelCircleShape, AIChekers, FreeFields, AiMove.vertex, AiMove.move, sf::Color::Blue);
			}
			
			gamestats.move = true;
			if (AiMove.isMill) {
				TabelCircleShape[AiMove.delver].setFillColor(sf::Color::Black);
				PlayerChekers.erase(binarySearch(PlayerChekers, AiMove.delver));
				FreeFields.push_back(AiMove.delver);
				FreeFields.quickSort();
				if (PlayerChekers.size() + gamestats.PC <= 2) gamestats.Final = true;
			}
		}
		Rendering(Lines, TabelCircleShape, window);
	}
	std::cout << "Конец игры!" << std::endl;
	std::cout << "Выйграл: " << (gamestats.move ? "Компьютер" : "Игрок") << std::endl;

}


