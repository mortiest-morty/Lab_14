# include "Header.h"

int main() {
	using namespace std;
	setlocale(LC_ALL, "Rus");
	int num;

	cout << "~ Yo, hiii ~ " << endl;
	cout << " ==== Выбор номера желаемой задачи (0 - выход) === \n";
	num = getNumber();
	while (num != 0 && (num < 1 || num>3)) {
		cout << "Нужна цифра 1-3!\n";
		num = getNumber();
	}

	while (num != 0) {
		switch (num) {
		case 1:
			system("cls"); // очистка экрана
			cout << endl << "(^-^) ============  Задание 1  ============ (^-^)";
			cout << "\n";
			task_1();
			cout << endl;
			break;
		case 2:
			system("cls"); // очистка экрана
			cout << endl << "(^-^) ============  Задание 2  ============ (^-^)" << endl;
			cout << "\n";
			task_2();
			cout << endl;
			break;
		case 3:
			system("cls"); // очистка экрана
			cout << endl << "(^-^) ============  Задание 3  ============ (^-^)" << endl;
			cout << "\n";
			task_3();
			cout << endl;
			break;
		}
		cout << "\n ==== Выбор номера желаемой задачи (0 - выход) ==== \n";
		num = getNumber();
		while (num != 0 && (num < 1 || num>3)) {
			cout << "Нужна цифра 1-3!\n";
			num = getNumber();
		}
	}

	system("cls"); // очистка экрана
	cout << endl << "(x-x) ============ конец проги ============ (x-x)" << endl;
	cout << endl << "byeee ~" << endl;
}
