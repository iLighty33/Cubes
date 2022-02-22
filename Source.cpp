// Персональный шаблон проекта C++
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
int scorePlayer = 0, scoreComputer = 0;

bool yesOrNo() {
	return rand() % 2;
}
void roll(bool comp = false) {
	int points = rand() % 6 + 1;
	if (points == 6) {
		if (!comp) {
			scorePlayer += points;
			cout << "Вам выпало 6. Хотите ли кинуть кубик ещё раз?\n";
			cout << "Ответ -> ";
			bool choise;
			cin >> choise;
			if (choise) {
				points = rand() % 6 + 1;
				if (points % 2) {
					scorePlayer += points;
					cout << "Вам выпало " << points << ".\n";
					cout << "Игрок: " << scorePlayer << ".\n";
				}
				else {
					scorePlayer -= points;
					cout << "Вам выпало " << points << ".\n";
					cout << "Игрок: " << scorePlayer << ".\n";
				}
			}


		}

		else {
			scoreComputer += points;
			if (yesOrNo) {
				cout << "Компьютеру выпало 6. Он решил кинуть повторно.\n";
				points = rand() % 6 + 1;
				if (points % 2)
					scoreComputer += points;
				else
					scoreComputer -= points;
				cout << "Выпало " << points << ".\n";
				cout << "Компьютер: " << scoreComputer << ".\n";
			}
			else {
				cout << "Компьютеру выпало 6. Он решил не кидать повторно.\n";
			}
		}


	}
	else
	if (comp) {
		scoreComputer += points;
		cout << "Компьютеру выпало " << points << ".\n";
		cout << "Компьютер: " << scoreComputer << ".\n";
	}
	else {
		scorePlayer += points;
		cout << "Вам выпало: " << points << ".\n";
		cout << "Игрок: " << scorePlayer << ".\n";
	}
}



int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	
	cout << "Давай сыграем в кубики!\n";
	if (yesOrNo()) {
		cout << "Начинает игрок.\nИгрок бросает кубик -> ";
		roll();
	}
	else
		cout << "Начинает компьютер.\nКомпьютер бросает кубик ->";

	do {
		if (scorePlayer < 50)
			roll(true);
		if (scoreComputer < 50)
			roll();
	} while (scorePlayer < 50 && scoreComputer < 50);
	if (scorePlayer >= 50)
		cout << "Вы победили!\n";
	else
		cout << "Победил компьютер!\n";

	// Задача

	return 0;
}