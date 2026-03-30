# include "Header.h"


void task_1() {
	using namespace std;

	int n, cnt = 0;
	vector<int> v0;
	v0 = inputVector();

	sort(v0.begin(), v0.end());
	cout << "Отсортированный вектор: ";
	for (int i : v0) {
		cout << i << " ";
	}

	cout << endl;
	while (true) {
		cout << "Введите число n: ";
		cin >> n;

		if (cin.fail() || n < 0) {
			cout << "Ошибка! Введите НАТУРАЛЬНОЕ ЧИСЛО!" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
	}

	set<vector<int>> vectors;
	inputSet(vectors, n);
	
	for (auto it : vectors) {
		if (includes(it.begin(), it.end(), v0.begin(), v0.end())) cnt++;
	}
	
	if (cnt > 0) cout << "\nКоличество векторов, в которых содержатся все элементы вектора v0 = " << cnt;
	else cout << "\nНууу...нет таких векторов...упс *-*\n";
}

void task_2() {
	using namespace std;

	vector<string> v;
	randomStringVector(v);
	map<char, int> m;

	for (auto i = v.begin(); i != v.end(); ++i) {
		string str = *i;
		
		if (m[str[0]]) {
			m[str[0]] += str.size();
		}
		else m[str[0]] = str.size();
	}

	outputMap(m);
}

void task_3() {
	using namespace std;

	int lastnum;
	vector<int> v = inputVector();
	multimap<int, int> m;
	
	for (auto it = v.begin(); it != v.end(); ++it) {
		lastnum = abs(*it % 10);
		m.insert({ lastnum, *it });
	}

	outputMultiMap(m);
}

