#pragma once
#include "header.h"
using namespace sf;

void createGameTable(Vector<sf::VertexArray>& lines, Vector<sf::CircleShape>& TabelCircleShape, float circleRadius) {
	for (int i = 0; i < 24; i++) {
		sf::CircleShape shape(circleRadius);
		shape.setFillColor(sf::Color::Black);
		TabelCircleShape.push_back(shape);
	}

	//Первая строчка позиций для шашек 
	TabelCircleShape[0].setPosition(100 - circleRadius, 100 - circleRadius);
	TabelCircleShape[1].setPosition(500 - circleRadius, 100 - circleRadius);
	TabelCircleShape[2].setPosition(900 - circleRadius, 100 - circleRadius);

	//Вторая строчка позиций для шашек
	TabelCircleShape[3].setPosition(200 - circleRadius, 200 - circleRadius);
	TabelCircleShape[4].setPosition(500 - circleRadius, 200 - circleRadius);
	TabelCircleShape[5].setPosition(800 - circleRadius, 200 - circleRadius);

	//Третья строчка позиций для шашек
	TabelCircleShape[6].setPosition(300 - circleRadius, 300 - circleRadius);
	TabelCircleShape[7].setPosition(500 - circleRadius, 300 - circleRadius);
	TabelCircleShape[8].setPosition(700 - circleRadius, 300 - circleRadius);

	//Чётвертая строчка позиций для шашек
	TabelCircleShape[9].setPosition(100 - circleRadius, 500 - circleRadius);
	TabelCircleShape[10].setPosition(200 - circleRadius, 500 - circleRadius);
	TabelCircleShape[11].setPosition(300 - circleRadius, 500 - circleRadius);
	TabelCircleShape[12].setPosition(700 - circleRadius, 500 - circleRadius);
	TabelCircleShape[13].setPosition(800 - circleRadius, 500 - circleRadius);
	TabelCircleShape[14].setPosition(900 - circleRadius, 500 - circleRadius);

	//Пятая строчка позиций для шашек
	TabelCircleShape[15].setPosition(300 - circleRadius, 700 - circleRadius);
	TabelCircleShape[16].setPosition(500 - circleRadius, 700 - circleRadius);
	TabelCircleShape[17].setPosition(700 - circleRadius, 700 - circleRadius);

	//Шестая строчка позиций для шашек
	TabelCircleShape[18].setPosition(200 - circleRadius, 800 - circleRadius);
	TabelCircleShape[19].setPosition(500 - circleRadius, 800 - circleRadius);
	TabelCircleShape[20].setPosition(800 - circleRadius, 800 - circleRadius);

	//Седьмая строчка позиций для шашек
	TabelCircleShape[21].setPosition(100 - circleRadius, 900 - circleRadius);
	TabelCircleShape[22].setPosition(500 - circleRadius, 900 - circleRadius);
	TabelCircleShape[23].setPosition(900 - circleRadius, 900 - circleRadius);

	//Создание линий между позиции для шашек

	//Большой квадрат
	sf::VertexArray line(sf::Lines, 2);
	line[0].position = sf::Vector2f(100, 100);
	line[1].position = sf::Vector2f(900, 100);
	line[0].color = sf::Color::Black;
	line[1].color = sf::Color::Black;
	lines.push_back(line);
	line[0].position = sf::Vector2f(100, 900);
	line[1].position = sf::Vector2f(900, 900);
	line[0].color = sf::Color::Black;
	line[1].color = sf::Color::Black;
	lines.push_back(line);
	line[0].position = sf::Vector2f(900, 100);
	line[1].position = sf::Vector2f(900, 900);
	line[0].color = sf::Color::Black;
	line[1].color = sf::Color::Black;
	lines.push_back(line);
	line[0].position = sf::Vector2f(100, 100);
	line[1].position = sf::Vector2f(100, 900);
	line[0].color = sf::Color::Black;
	line[1].color = sf::Color::Black;
	lines.push_back(line);
	//Малый квадрат
	line[0].position = sf::Vector2f(300, 700);
	line[1].position = sf::Vector2f(700, 700);
	line[0].color = sf::Color::Black;
	line[1].color = sf::Color::Black;
	lines.push_back(line);
	line[0].position = sf::Vector2f(300, 300);
	line[1].position = sf::Vector2f(700, 300);
	line[0].color = sf::Color::Black;
	line[1].color = sf::Color::Black;
	lines.push_back(line);
	line[0].position = sf::Vector2f(300, 300);
	line[1].position = sf::Vector2f(300, 700);
	line[0].color = sf::Color::Black;
	line[1].color = sf::Color::Black;
	lines.push_back(line);
	line[0].position = sf::Vector2f(700, 300);
	line[1].position = sf::Vector2f(700, 700);
	line[0].color = sf::Color::Black;
	line[1].color = sf::Color::Black;
	lines.push_back(line);
	//Средний квадрат
	line[0].position = sf::Vector2f(200, 800);
	line[1].position = sf::Vector2f(800, 800);
	line[0].color = sf::Color::Black;
	line[1].color = sf::Color::Black;
	lines.push_back(line);
	line[0].position = sf::Vector2f(200, 200);
	line[1].position = sf::Vector2f(800, 200);
	line[0].color = sf::Color::Black;
	line[1].color = sf::Color::Black;
	lines.push_back(line);
	line[0].position = sf::Vector2f(200, 200);
	line[1].position = sf::Vector2f(200, 800);
	line[0].color = sf::Color::Black;
	line[1].color = sf::Color::Black;
	lines.push_back(line);
	line[0].position = sf::Vector2f(800, 200);
	line[1].position = sf::Vector2f(800, 800);
	line[0].color = sf::Color::Black;
	line[1].color = sf::Color::Black;
	lines.push_back(line);
	//Диагонали
	line[0].position = sf::Vector2f(100, 100);
	line[1].position = sf::Vector2f(300, 300);
	line[0].color = sf::Color::Black;
	line[1].color = sf::Color::Black;
	lines.push_back(line);
	line[0].position = sf::Vector2f(900, 100);
	line[1].position = sf::Vector2f(700, 300);
	line[0].color = sf::Color::Black;
	line[1].color = sf::Color::Black;
	lines.push_back(line);
	line[0].position = sf::Vector2f(100, 900);
	line[1].position = sf::Vector2f(300, 700);
	line[0].color = sf::Color::Black;
	line[1].color = sf::Color::Black;
	lines.push_back(line);
	line[0].position = sf::Vector2f(700, 700);
	line[1].position = sf::Vector2f(900, 900);
	line[0].color = sf::Color::Black;
	line[1].color = sf::Color::Black;
	lines.push_back(line);

	//горизонтали
	line[0].position = sf::Vector2f(500, 100);
	line[1].position = sf::Vector2f(500, 300);
	line[0].color = sf::Color::Black;
	line[1].color = sf::Color::Black;
	lines.push_back(line);
	line[0].position = sf::Vector2f(100, 500);
	line[1].position = sf::Vector2f(300, 500);
	line[0].color = sf::Color::Black;
	line[1].color = sf::Color::Black;
	lines.push_back(line);
	line[0].position = sf::Vector2f(500, 700);
	line[1].position = sf::Vector2f(500, 900);
	line[0].color = sf::Color::Black;
	line[1].color = sf::Color::Black;
	lines.push_back(line);
	line[0].position = sf::Vector2f(700, 500);
	line[1].position = sf::Vector2f(900, 500);
	line[0].color = sf::Color::Black;
	line[1].color = sf::Color::Black;
	lines.push_back(line);
}

void Rendering(Vector<sf::VertexArray>& Lines, Vector<sf::CircleShape>& TabelCircleShape, sf::RenderWindow& window) {
	window.clear(sf::Color::White);
	//Старт отрисовки объектов
	for (auto& line : Lines) window.draw(line);
	for (auto& shape : TabelCircleShape) window.draw(shape);
	//Обновление окна
	window.display();
}

void setColor(int vertex, Vector<sf::CircleShape>& TabelCircleShape, Vector<int>& FieldsForMove) {
	TabelCircleShape[vertex].setFillColor(sf::Color::Green);
	FieldsForMove.push_back(vertex);
}

sf::Color getColor(int vertex, Vector<sf::CircleShape>& TabelCircleShape) {
	return TabelCircleShape[vertex].getFillColor();
}

void ShapeRepainting(int vertex, Vector<sf::CircleShape>& TabelCircleShape, Vector<int>& FieldsForMove) {

	sf::Color Black = sf::Color::Black;
	sf::Color Green = sf::Color::Green;

	if (vertex == 0) {

		if (getColor(1, TabelCircleShape) == Black) {
			setColor(1, TabelCircleShape, FieldsForMove);
		}
		else {
			if (getColor(2, TabelCircleShape) == Black) {
				setColor(2, TabelCircleShape, FieldsForMove);
			}
		}

		if (getColor(3, TabelCircleShape) == Black) {
			setColor(3, TabelCircleShape, FieldsForMove);
		}
		else {
			if (getColor(6, TabelCircleShape) == Black) {
				setColor(6, TabelCircleShape, FieldsForMove);
			}
		}

		if (getColor(9, TabelCircleShape) == Black) {
			setColor(9, TabelCircleShape, FieldsForMove);
		}
		else {
			if (getColor(21, TabelCircleShape) == Black) {
				setColor(21, TabelCircleShape, FieldsForMove);
			}
		}

	}
	if (vertex == 1) {
		if (getColor(0, TabelCircleShape) == Black) {
			setColor(0, TabelCircleShape, FieldsForMove);
		}
		if (getColor(2, TabelCircleShape) == Black) {
			setColor(2, TabelCircleShape, FieldsForMove);
		}
		if (getColor(4, TabelCircleShape) == Black) {
			setColor(4, TabelCircleShape, FieldsForMove);
		}
		else if (getColor(7, TabelCircleShape) == Black) {
			setColor(7, TabelCircleShape, FieldsForMove);
		}
	}
	if (vertex == 2) {
		if (getColor(1, TabelCircleShape) == Black) {
			setColor(1, TabelCircleShape, FieldsForMove);
		}
		else if (getColor(0, TabelCircleShape) == Black) {
			setColor(0, TabelCircleShape, FieldsForMove);
		}
		if (getColor(5, TabelCircleShape) == Black) {
			setColor(5, TabelCircleShape, FieldsForMove);
		}
		else if (getColor(8, TabelCircleShape) == Black) {
			setColor(8, TabelCircleShape, FieldsForMove);
		}
		if (getColor(14, TabelCircleShape) == Black) {
			setColor(14, TabelCircleShape, FieldsForMove);
		}
		else if (getColor(23, TabelCircleShape) == Black) {
			setColor(23, TabelCircleShape, FieldsForMove);
		}
	}
	if (vertex == 3) {
		if (getColor(0, TabelCircleShape) == Black) {
			setColor(0, TabelCircleShape, FieldsForMove);
		}
		if (getColor(6, TabelCircleShape) == Black) {
			setColor(6, TabelCircleShape, FieldsForMove);
		}
		if (getColor(4, TabelCircleShape) == Black) {
			setColor(4, TabelCircleShape, FieldsForMove);
		}
		else if (getColor(5, TabelCircleShape) == Black) {
			setColor(5, TabelCircleShape, FieldsForMove);
		}
		if (getColor(10, TabelCircleShape) == Black) {
			setColor(10, TabelCircleShape, FieldsForMove);
		}
		else if (getColor(18, TabelCircleShape) == Black) {
			setColor(18, TabelCircleShape, FieldsForMove);
		}
	}
	if (vertex == 4) {
		if (getColor(3, TabelCircleShape) == Black) {
			setColor(3, TabelCircleShape, FieldsForMove);
		}
		if (getColor(5, TabelCircleShape) == Black) {
			setColor(5, TabelCircleShape, FieldsForMove);
		}
		if (getColor(1, TabelCircleShape) == Black) {
			setColor(1, TabelCircleShape, FieldsForMove);
		}
		if (getColor(7, TabelCircleShape) == Black) {
			setColor(7, TabelCircleShape, FieldsForMove);
		}
	}
	if (vertex == 5) {
		if (getColor(2, TabelCircleShape) == Black) {
			setColor(2, TabelCircleShape, FieldsForMove);
		}
		if (getColor(8, TabelCircleShape) == Black) {
			setColor(8, TabelCircleShape, FieldsForMove);
		}
		if (getColor(4, TabelCircleShape) == Black) {
			setColor(4, TabelCircleShape, FieldsForMove);
		}
		else if (getColor(3, TabelCircleShape) == Black) {
			setColor(3, TabelCircleShape, FieldsForMove);
		}
		if (getColor(13, TabelCircleShape) == Black) {
			setColor(13, TabelCircleShape, FieldsForMove);
		}
		else if (getColor(20, TabelCircleShape) == Black) {
			setColor(20, TabelCircleShape, FieldsForMove);
		}
	}
	if (vertex == 6) {
		if (getColor(3, TabelCircleShape) == Black) {
			setColor(3, TabelCircleShape, FieldsForMove);
		}
		else {
			if (getColor(0, TabelCircleShape) == Black) {
				setColor(0, TabelCircleShape, FieldsForMove);
			}
		}

		if (getColor(7, TabelCircleShape) == Black) {
			setColor(7, TabelCircleShape, FieldsForMove);
		}
		else {
			if (getColor(8, TabelCircleShape) == Black) {
				setColor(8, TabelCircleShape, FieldsForMove);
			}
		}

		if (getColor(11, TabelCircleShape) == Black) {
			setColor(11, TabelCircleShape, FieldsForMove);
		}
		else {
			if (getColor(15, TabelCircleShape) == Black) {
				setColor(15, TabelCircleShape, FieldsForMove);
			}
		}
	}
	if (vertex == 7) {
		if (getColor(6, TabelCircleShape) == Black) {
			setColor(6, TabelCircleShape, FieldsForMove);
		}
		if (getColor(8, TabelCircleShape) == Black) {
			setColor(8, TabelCircleShape, FieldsForMove);
		}
		if (getColor(4, TabelCircleShape) == Black) {
			setColor(4, TabelCircleShape, FieldsForMove);
		}
		else {
			if (getColor(1, TabelCircleShape) == Black) {
				setColor(1, TabelCircleShape, FieldsForMove);
			}
		}
	}
	if (vertex == 8) {
		if (getColor(7, TabelCircleShape) == Black) {
			setColor(7, TabelCircleShape, FieldsForMove);
		}
		else {
			if (getColor(6, TabelCircleShape) == Black) {
				setColor(6, TabelCircleShape, FieldsForMove);
			}
		}

		if (getColor(5, TabelCircleShape) == Black) {
			setColor(5, TabelCircleShape, FieldsForMove);
		}
		else {
			if (getColor(2, TabelCircleShape) == Black) {
				setColor(2, TabelCircleShape, FieldsForMove);
			}
		}

		if (getColor(12, TabelCircleShape) == Black) {
			setColor(12, TabelCircleShape, FieldsForMove);
		}
		else {
			if (getColor(17, TabelCircleShape) == Black) {
				setColor(17, TabelCircleShape, FieldsForMove);
			}
		}
	}
	if (vertex == 9) {
		if (getColor(0, TabelCircleShape) == Black) {
			setColor(0, TabelCircleShape, FieldsForMove);
		}
		if (getColor(21, TabelCircleShape) == Black) {
			setColor(21, TabelCircleShape, FieldsForMove);
		}
		if (getColor(10, TabelCircleShape) == Black) {
			setColor(10, TabelCircleShape, FieldsForMove);
		}
		else if (getColor(11, TabelCircleShape) == Black) {
			setColor(11, TabelCircleShape, FieldsForMove);
		}
	}
	if (vertex == 10) {
		if (getColor(3, TabelCircleShape) == Black) {
			setColor(3, TabelCircleShape, FieldsForMove);
		}
		if (getColor(18, TabelCircleShape) == Black) {
			setColor(18, TabelCircleShape, FieldsForMove);
		}
		if (getColor(9, TabelCircleShape) == Black) {
			setColor(9, TabelCircleShape, FieldsForMove);
		}
		if (getColor(11, TabelCircleShape) == Black) {
			setColor(11, TabelCircleShape, FieldsForMove);
		}
	}
	if (vertex == 11) {
		if (getColor(10, TabelCircleShape) == Black) {
			setColor(10, TabelCircleShape, FieldsForMove);
		}
		else if (getColor(9, TabelCircleShape) == Black) {
			setColor(9, TabelCircleShape, FieldsForMove);
		}
		if (getColor(6, TabelCircleShape) == Black) {
			setColor(6, TabelCircleShape, FieldsForMove);
		}
		if (getColor(15, TabelCircleShape) == Black) {
			setColor(15, TabelCircleShape, FieldsForMove);
		}
	}
	if (vertex == 12) {
		if (getColor(8, TabelCircleShape) == Black) {
			setColor(8, TabelCircleShape, FieldsForMove);
		}
		if (getColor(17, TabelCircleShape) == Black) {
			setColor(17, TabelCircleShape, FieldsForMove);
		}
		if (getColor(13, TabelCircleShape) == Black) {
			setColor(13, TabelCircleShape, FieldsForMove);
		}
		else if (getColor(14, TabelCircleShape) == Black) {
			setColor(14, TabelCircleShape, FieldsForMove);
		}
	}
	if (vertex == 13) {
		if (getColor(12, TabelCircleShape) == Black) {
			setColor(12, TabelCircleShape, FieldsForMove);
		}
		if (getColor(14, TabelCircleShape) == Black) {
			setColor(14, TabelCircleShape, FieldsForMove);
		}
		if (getColor(5, TabelCircleShape) == Black) {
			setColor(5, TabelCircleShape, FieldsForMove);
		}
		if (getColor(20, TabelCircleShape) == Black) {
			setColor(20, TabelCircleShape, FieldsForMove);
		}
	}
	if (vertex == 14) {
		if (getColor(2, TabelCircleShape) == Black) {
			setColor(2, TabelCircleShape, FieldsForMove);
		}
		if (getColor(23, TabelCircleShape) == Black) {
			setColor(23, TabelCircleShape, FieldsForMove);
		}
		if (getColor(13, TabelCircleShape) == Black) {
			setColor(13, TabelCircleShape, FieldsForMove);
		} 
		else if (getColor(12, TabelCircleShape) == Black) {
			setColor(12, TabelCircleShape, FieldsForMove);
		}
	}
	if (vertex == 15) {
		if (getColor(18, TabelCircleShape) == Black) {
			setColor(18, TabelCircleShape, FieldsForMove);
		}
		else if (getColor(21, TabelCircleShape) == Black) {
			setColor(21, TabelCircleShape, FieldsForMove);
		}
		if (getColor(11, TabelCircleShape) == Black) {
			setColor(11, TabelCircleShape, FieldsForMove);
		} 
		else if (getColor(6, TabelCircleShape) == Black) {
			setColor(6, TabelCircleShape, FieldsForMove);
		}
		if (getColor(16, TabelCircleShape) == Black) {
			setColor(16, TabelCircleShape, FieldsForMove);
		}
		else if (getColor(17, TabelCircleShape) == Black) {
			setColor(17, TabelCircleShape, FieldsForMove);
		}
	}
	if (vertex == 16) {
		if (getColor(15, TabelCircleShape) == Black) {
			setColor(15, TabelCircleShape, FieldsForMove);
		}
		if (getColor(17, TabelCircleShape) == Black) {
			setColor(17, TabelCircleShape, FieldsForMove);
		}
		if (getColor(19, TabelCircleShape) == Black) {
			setColor(19, TabelCircleShape, FieldsForMove);
		}
		else if (getColor(22, TabelCircleShape) == Black) {
			setColor(22, TabelCircleShape, FieldsForMove);
		}
	}
	if (vertex == 17) {
		if (getColor(16, TabelCircleShape) == Black) {
			setColor(16, TabelCircleShape, FieldsForMove);
		}
		else if (getColor(15, TabelCircleShape) == Black) {
			setColor(15, TabelCircleShape, FieldsForMove);
		}
		if (getColor(12, TabelCircleShape) == Black) {
			setColor(12, TabelCircleShape, FieldsForMove);
		}
		else if (getColor(8, TabelCircleShape) == Black) {
			setColor(8, TabelCircleShape, FieldsForMove);
		}
		if (getColor(20, TabelCircleShape) == Black) {
			setColor(20, TabelCircleShape, FieldsForMove);
		}
		else if (getColor(23, TabelCircleShape) == Black) {
			setColor(23, TabelCircleShape, FieldsForMove);
		}
	}
	if (vertex == 18) {
		if (getColor(21, TabelCircleShape) == Black) {
			setColor(21, TabelCircleShape, FieldsForMove);
		}
		if (getColor(15, TabelCircleShape) == Black) {
			setColor(15, TabelCircleShape, FieldsForMove);
		}
		if (getColor(19, TabelCircleShape) == Black) {
			setColor(19, TabelCircleShape, FieldsForMove);
		}
		else if (getColor(20, TabelCircleShape) == Black) {
			setColor(20, TabelCircleShape, FieldsForMove);
		}
		if (getColor(10, TabelCircleShape) == Black) {
			setColor(10, TabelCircleShape, FieldsForMove);
		}
		else if (getColor(3, TabelCircleShape) == Black) {
			setColor(3, TabelCircleShape, FieldsForMove);
		}
	}
	if (vertex == 19) {
		if (getColor(18, TabelCircleShape) == Black) {
			setColor(18, TabelCircleShape, FieldsForMove);
		}
		if (getColor(20, TabelCircleShape) == Black) {
			setColor(20, TabelCircleShape, FieldsForMove);
		}
		if (getColor(16, TabelCircleShape) == Black) {
			setColor(16, TabelCircleShape, FieldsForMove);
		}
		if (getColor(22, TabelCircleShape) == Black) {
			setColor(22, TabelCircleShape, FieldsForMove);
		}
	}
	if (vertex == 20) {
		if (getColor(17, TabelCircleShape) == Black) {
			setColor(17, TabelCircleShape, FieldsForMove);
		}
		if (getColor(23, TabelCircleShape) == Black) {
			setColor(23, TabelCircleShape, FieldsForMove);
		}
		if (getColor(19, TabelCircleShape) == Black) {
			setColor(19, TabelCircleShape, FieldsForMove);
		}
		else if (getColor(18, TabelCircleShape) == Black) {
			setColor(18, TabelCircleShape, FieldsForMove);
		}
	}
	if (vertex == 21) {
		if (getColor(22, TabelCircleShape) == Black) {
			setColor(22, TabelCircleShape, FieldsForMove);
		}
		else {
			if (getColor(23, TabelCircleShape) == Black) {
				setColor(23, TabelCircleShape, FieldsForMove);
			}
		}

		if (getColor(9, TabelCircleShape) == Black) {
			setColor(9, TabelCircleShape, FieldsForMove);
		}
		else {
			if (getColor(0, TabelCircleShape) == Black) {
				setColor(0, TabelCircleShape, FieldsForMove);
			}
		}

		if (getColor(18, TabelCircleShape) == Black) {
			setColor(18, TabelCircleShape, FieldsForMove);
		}
		else {
			if (getColor(15, TabelCircleShape) == Black) {
				setColor(15, TabelCircleShape, FieldsForMove);
			}
		}
	}
	if (vertex == 22) {
		if (getColor(21, TabelCircleShape) == Black) {
			setColor(21, TabelCircleShape, FieldsForMove);
		}
		if (getColor(23, TabelCircleShape) == Black) {
			setColor(23, TabelCircleShape, FieldsForMove);
		}
		if (getColor(19, TabelCircleShape) == Black) {
			setColor(19, TabelCircleShape, FieldsForMove);
		}
		else if (getColor(16, TabelCircleShape) == Black) {
			setColor(16, TabelCircleShape, FieldsForMove);
		}
	}
	if (vertex == 23) {
		if (getColor(22, TabelCircleShape) == Black) {
			setColor(22, TabelCircleShape, FieldsForMove);
		}
		else {
			if (getColor(21, TabelCircleShape) == Black) {
				setColor(21, TabelCircleShape, FieldsForMove);
			}
		}

		if (getColor(14, TabelCircleShape) == Black) {
			setColor(14, TabelCircleShape, FieldsForMove);
		}
		else {
			if (getColor(2, TabelCircleShape) == Black) {
				setColor(2, TabelCircleShape, FieldsForMove);
			}
		}

		if (getColor(20, TabelCircleShape) == Black) {
			setColor(20, TabelCircleShape, FieldsForMove);
		}
		else {
			if (getColor(17, TabelCircleShape) == Black) {
				setColor(17, TabelCircleShape, FieldsForMove);
			}
		}
	}
}

