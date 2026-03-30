# include "Header.h"

// ======================== ПРОВЕРКА ВВОДА ========================
int getNumber() {
	using namespace std;
	int value;

	while (true) {
		cout << "Введите число: ";
		cin >> value;

		if (cin.fail()) {
			cout << "Ошибка! Введите ЧИСЛО, а не буквы!" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return value;
		}
	}
}

std::string getText() {
	using namespace std;
	string input;
	bool hasDigit;

	while (true) {
		hasDigit = false;
		cout << "Введите имя файла: ";
		getline(cin, input);

		if (input.empty()) {
			cout << "Ошибка! Строка не может быть пустой!" << endl;
			continue;
		}

		for (int i = 0; i < input.length(); i++) {
			if (isdigit(input[i])) {
				hasDigit = true;
				break;
			}
		}

		if (hasDigit) {
			cout << "Ошибка! В тексте не должно быть цифр!" << endl;
		}
		else {
			return input;
		}
	}
}

// ================== ВВОД И ВЫВОД КОНТЕЙНЕРА "VECTOR" ==================
std::vector<int> inputVector() {
	using namespace std;

	vector<int> V;
	int input, n, num;
	srand((time(nullptr)));

	cout << "\n===== Заполнение вектора =====\n 1 - c консоли\n 2 - рандомно\n 3 - из файла\n";
	input = getNumber();
	while (input < 1 || input>3) {
		cout << "Ошибка!\nНужна цифра от 1 до 3!\n ";
		input = getNumber();
	}
	switch (input) {
	case 1:
	{
		cout << "\n\n===== Введите числа (завершите ввод не-числом) =====\n";
		istream_iterator<int> in_it(cin), in_end;
		V.assign(in_it, in_end);
		cin.clear();
		break;
	}
	case 2:
	{
		cout << "\n===== Количество чисел =====\n";
		n = getNumber();
		while (n < 1) {
			cout << "Ошибка!\nВведите натуральное число!\n ";
			n = getNumber();
		}

		int* a = new int[n];

		for (int i = 0; i < n; i++) {
			a[i] = rand() % 120 - 60 + 1;
		}

		V.assign(a, a + n);

		cout << "Вектор: ";
		for (auto it = V.begin(); it != V.end(); ++it) {
			cout << *it << " ";
		}
		cout << endl;

		delete a;
		break;
	}
	case 3:
	{
		string filename;
		filename = getText();

		ifstream file(filename);

		if (file.is_open()) {
			istream_iterator<int> file_it(file), file_end;
			V.assign(file_it, file_end);
			file.close();
		}
		else {
			cout << "\nОшибка открытия файла!\n";
		}

		cout << "Вектор: ";
		for (auto it = V.begin(); it != V.end(); ++it) {
			cout << *it << " ";
		}
		cout << endl;
		break;
	}
	}
	return V;
}

// Создание вектора со строками
void randomStringVector(std::vector<std::string>& v) {
	using namespace std;

	int input, n, num;
	srand((time(nullptr)));

	cout << "===== Заполнение вектора =====\n 1 - c консоли\n 2 - рандомно\n 3 - из файла\n";
	input = getNumber();
	while (input < 1 || input>3) {
		cout << "Ошибка!\nНужна цифра от 1 до 3!\n ";
		input = getNumber();
	}
	switch (input) {
	case 1:
	{
		cout << "\n\n===== Введите слова (пустая строка для завершения) =====\n";
		string word;
		while (getline(cin, word) && !word.empty()) {
			stringstream ss(word);
			string single;
			while (ss >> single) {
				v.push_back(single);
			}
		}
		cin.clear();
		break;
	}
	case 2:{
		int length, cnt = 1;
		string word;
		srand(time(nullptr));

		cout << "\n===== Количество слов =====\n";
		n = getNumber();
		while (n < 1) {
			cout << "Ошибка!\nВведите натуральное число!\n ";
			n = getNumber();
		}

		while(n!=0){
			word = "";
			while (true) {
				cout << "Введите длину " << cnt << " слова: ";
				cin >> length;

				if (cin.fail() || length < 0) {
					cout << "Ошибка! Введите НАТУРАЛЬНОЕ ЧИСЛО!" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				else {
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					break;
				}
			}
			for (int j = 0; j < length; j++) {
				word += 'A' + (rand() % 26);
			}
			v.push_back(word);
			n--;
			cnt++;
		}

		cout << "Вектор: ";
		for (auto it = v.begin(); it != v.end(); ++it) {
			cout << *it << " ";
		}
		cout << endl;

		break;
	}
	case 3:
	{
		string filename;
		filename = getText();

		ifstream file(filename);

		if (file.is_open()) {
			istream_iterator<string> file_it(file), file_end;
			v.assign(file_it, file_end);
			file.close();
		}
		else {
			cout << "\nОшибка открытия файла!\n";
		}

		cout << "Вектор: ";
		for (auto it = v.begin(); it != v.end(); ++it) {
			cout << *it << " ";
		}
		cout << endl;
		break;
	}
	}

}

void outputVector(std::vector<int>& V) {
	using namespace std;

	int output;

	cout << "\n\n===== Вывод вектора =====\n 1 - в консоль\n 2 - в файл\n";
	output = getNumber();
	while (output < 1 || output>2) {
		cout << "Ошибка!\nНужна цифра от 1 до 2!\n ";
		output = getNumber();
	}
	switch (output) {
	case 1:
		cout << "\nВектор: ";
		for (auto it = V.begin(); it != V.end(); ++it) {
			cout << *it << " ";
		}
		break;
	case 2:
	{
		string filename;
		filename = getText();

		ofstream file(filename);

		if (file.is_open()) {
			file << "Вектор: ";
			for (auto it = V.begin(); it != V.end(); ++it) {
				file << *it << " ";
			}
		}
		else {
			cout << "\nОшибка открытия файла!\n";
		}

		file.close();
		break;
	}
	}
}

void printVector(std::vector<int> v) {
	using namespace std;

	for (auto it = v.begin(); it != v.end(); ++it) {
		cout << *it << " ";
	}
}

// ==================== ЗАПОЛНЕНИЕ МНОЖЕСТВА ====================
void inputSet(std::set<std::vector<int>>& sett, int n) {
	using namespace std;

	cout << "\n===== Заполнение множества =====\n";
	for (int i = 1; i < n + 1; i++) {
		vector < int> v = inputVector();
		sort(v.begin(), v.end());
		sett.insert(v);
	}

	for (auto i : sett) {
		cout << "\nВектор: ";
		printVector(i);
	}
}


// ==================== ВЫВОД СЛОВАРЯ ====================
void outputMap(std::map<char, int>& m) {
	using namespace std;

	int output;

	cout << "\n\n===== Вывод словаря =====\n 1 - в консоль\n 2 - в файл\n";
	output = getNumber();
	while (output < 1 || output>2) {
		cout << "Ошибка!\nНужна цифра от 1 до 2!\n ";
		output = getNumber();
	}
	switch (output) {
	case 1:
		cout << "\nСловарь:\n";
		for (auto it : m) {
			cout << it.first << " = " << it.second << endl;
		}
		break;
	case 2:
	{
		string filename;
		filename = getText();

		ofstream file(filename);

		if (file.is_open()) {
			file << "Словарь:\n";
			for (auto it : m) {
				file << it.first << " = " << it.second << endl;
			}
		}
		else {
			cout << "\nОшибка открытия файла!\n";
		}

		file.close();
		break;
	}
	}
}


// ==================== ВЫВОД MULTIMAP ====================
void outputMultiMap(std::multimap<int, int>& m) {
	using namespace std;

	int output;

	cout << "\n\n===== Вывод мульти-словаря =====\n 1 - в консоль\n 2 - в файл\n";
	output = getNumber();
	while (output < 1 || output>2) {
		cout << "Ошибка!\nНужна цифра от 1 до 2!\n ";
		output = getNumber();
	}
	switch (output) {
	case 1:
		cout << "\nМульти-словарь:\n";
		for (auto it : m) {
			cout << " " << it.first << " = " << it.second << endl;
		}
		break;
	case 2:
	{
		string filename;
		filename = getText();

		ofstream file(filename);

		if (file.is_open()) {
			file << "Мульти-словарь:\n";
			for (auto it : m) {
				file << " " << it.first << " = " << it.second << endl;
			}
		}
		else {
			cout << "\nОшибка открытия файла!\n";
		}

		file.close();
		break;
	}
	}
}
