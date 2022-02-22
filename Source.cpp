// ������������ ������ ������� C++
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
			cout << "��� ������ 6. ������ �� ������ ����� ��� ���?\n";
			cout << "����� -> ";
			bool choise;
			cin >> choise;
			if (choise) {
				points = rand() % 6 + 1;
				if (points % 2) {
					scorePlayer += points;
					cout << "��� ������ " << points << ".\n";
					cout << "�����: " << scorePlayer << ".\n";
				}
				else {
					scorePlayer -= points;
					cout << "��� ������ " << points << ".\n";
					cout << "�����: " << scorePlayer << ".\n";
				}
			}


		}

		else {
			scoreComputer += points;
			if (yesOrNo) {
				cout << "���������� ������ 6. �� ����� ������ ��������.\n";
				points = rand() % 6 + 1;
				if (points % 2)
					scoreComputer += points;
				else
					scoreComputer -= points;
				cout << "������ " << points << ".\n";
				cout << "���������: " << scoreComputer << ".\n";
			}
			else {
				cout << "���������� ������ 6. �� ����� �� ������ ��������.\n";
			}
		}


	}
	else
	if (comp) {
		scoreComputer += points;
		cout << "���������� ������ " << points << ".\n";
		cout << "���������: " << scoreComputer << ".\n";
	}
	else {
		scorePlayer += points;
		cout << "��� ������: " << points << ".\n";
		cout << "�����: " << scorePlayer << ".\n";
	}
}



int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	
	cout << "����� ������� � ������!\n";
	if (yesOrNo()) {
		cout << "�������� �����.\n����� ������� ����� -> ";
		roll();
	}
	else
		cout << "�������� ���������.\n��������� ������� ����� ->";

	do {
		if (scorePlayer < 50)
			roll(true);
		if (scoreComputer < 50)
			roll();
	} while (scorePlayer < 50 && scoreComputer < 50);
	if (scorePlayer >= 50)
		cout << "�� ��������!\n";
	else
		cout << "������� ���������!\n";

	// ������

	return 0;
}