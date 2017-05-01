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

	cout << endl << "\t\t���� �������� ��� �������:" << endl;
	cout << "\t1. ������� �������� � ����� ������." << endl;
	cout << "\t2. ������� ��� ��������, ������� ������ �������." << endl;
	cout << "\t3. ����� ��������." << endl;
	cout << "\t4. ���������� ������ �� ��������." << endl;
	cout << "\t5. ����� ������ �� �����." << endl;
	cout << "\t6. ����� �� ���������." << endl;
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