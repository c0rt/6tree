#include <iostream>

using namespace std;


struct TREE {
	double val;
	size_t count;
	TREE *field;
};

TREE * init(double val, size_t count);
TREE * addItem(TREE * ph, double val, size_t count);
void menu(TREE * ph);

int main() {
	TREE * ph = NULL;
	double temp;
	size_t count;
	cin >> temp >> count;
	ph = addItem(ph, temp, count);
	//menu(ph);
	return 0;
}

void menu(TREE * ph) {

	short int m;

	system("cls");
	for (int i = 0; i < 70; i++) {
		cout << "-";
	}

	cout << endl << "\t\tМеню действий над списком:" << endl;
	cout << "\t1. Вставка элемента в конец списка." << endl;
	cout << "\t2. Удалить все элементы, которые больше зачения." << endl;
	cout << "\t3. Поиск элемента." << endl;
	cout << "\t4. Сортировка списка по убыванию." << endl;
	cout << "\t5. Вывод списка на экран." << endl;
	cout << "\t6. Выйти из программы." << endl;
	cin >> m;

	/*switch (m) {
	
	}*/
	menu(ph);
}

TREE * init(double val, size_t count) {
	TREE * pnew = new TREE;
	pnew->val = val;
	pnew->count = count;
	pnew->field = new TREE[pnew->count + 1];
	memset(pnew->field, NULL, count * sizeof(TREE*));
	return pnew;
}

TREE * addItem(TREE * ph, double val, size_t count) {
	if (ph == NULL) {
		ph = init(val, count);
		return ph;
	}
	
	return ph;
}