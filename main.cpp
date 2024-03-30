#include "graficFunc.h"
#include "Evalution.h"
#include "Func.h"
#include "Minimax.h"
#include "alphabeta.h"	
using namespace std;
//�� �������
//�������� �������� ������� ���������� �� ���������� ���������


int main() {

	setlocale(0, "rus");
	//����������� � ������������ ���������
	const int Width = 1500;					// ��������� ������
	const int Height = 1000;
	float circleRadius = 20;				// ��������� �����

	gameStats gamestats;

	//������ � ������� �������� ����������� ������� ����� ������;
	Vector<sf::CircleShape> TabelCircleShape;
	//������ � ������� �������� ����� ����� �������
	//����� ����������� ����� ��������� �� �������� �� ����������
	Vector<sf::VertexArray> Lines;
	//������ � ������� �������� ������� ������ ����
	Vector<int> AIChekers;
	//������ � ������� �������� ������� ������ ������
	Vector<int> PlayerChekers;
	//������ � ������ �������� ������� ��������� ������
	Vector<int> FreeFields = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23 };
	Vector<int> FieldsForMove;

	MoveBeforeMinimax AiMove;

	createGameTable(Lines, TabelCircleShape, circleRadius);
	//�������� ����

	sf::RenderWindow window(sf::VideoMode(Width, Height, 10000000000), "The best kursach ever"); //������� ����
	while (window.isOpen() && !gamestats.Final) {
		sf::Event event;
		//�����
		if (gamestats.move == true || gamestats.mill) {
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
					sf::Vector2i mousePos = {sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y};
					//�������� �� ��������
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
					// ����������� ������
					else if (!gamestats.isPlaced) {
						for (int i = 0; i < TabelCircleShape.size(); ++i) {
							if (TabelCircleShape[i].getGlobalBounds().contains(mousePos.x, mousePos.y) && TabelCircleShape[i].getFillColor() == sf::Color::Black) {
								// �������� ���� ������ �� �������
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
						//�����
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
					//���
					else {
						//�����
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
		//���
		else {
			gamestats.depth = 3;
			auto start = std::chrono::high_resolution_clock::now(); // ������ �������
			//AiMove = minimax(TabelCircleShape, AIChekers, PlayerChekers, FreeFields, gamestats, gamestats.depth, false);
			AiMove = alphabeta(TabelCircleShape, AIChekers, PlayerChekers, FreeFields, gamestats, gamestats.depth, INT16_MIN, INT16_MAX , false);
			auto end = std::chrono::high_resolution_clock::now(); // ��������� �������
			auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(end - start); // �������������� ����������������� � �������
			std::cout << "alphabeta ����������� " << duration.count() << " ������" << std::endl;

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
	std::cout << "����� ����!" << std::endl;
	std::cout << "�������: " << (gamestats.move ? "���������" : "�����") << std::endl;

}


