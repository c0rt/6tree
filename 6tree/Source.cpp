/*
	������������ ������ 6. �������
	������� 4.
	������ ���� �. ������������ �����.
*/

#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

struct TREE {
	double val;
	size_t count;
	TREE **field;
};

TREE * init(double val, size_t count);
TREE * addItem(TREE * ph, double val, size_t count);
TREE * findNullItem(TREE * temp);
int findNumberItem(TREE * temp);
void printTree(TREE * ph);
void cont();
void menu(TREE * ph);

int main() {
	setlocale(0, "");
	TREE * ph = NULL;
	ph = addItem(ph, 0, 5);		//�������� ������, ����� �������
	ph = addItem(ph, 1, 1);		//�������� ������, ����� �������
	ph = addItem(ph, 2, 2);		//�������� ������, ����� �������
	ph = addItem(ph, 3, 3);		//�������� ������, ����� �������
	ph = addItem(ph, 4, 5);		//�������� ������, ����� �������
	ph = addItem(ph, 5, 1);		//�������� ������, ����� �������
	ph = addItem(ph, 6, 1);		//�������� ������, ����� �������
	ph = addItem(ph, 7, 1);		//�������� ������, ����� �������
	ph = addItem(ph, 8, 1);		//�������� ������, ����� �������
	ph = addItem(ph, 9, 3);		//�������� ������, ����� �������
	ph = addItem(ph, 10, 1);	//�������� ������, ����� �������
	ph = addItem(ph, 11, 1);	//�������� ������, ����� �������
	ph = addItem(ph, 12, 2);	//�������� ������, ����� �������
	ph = addItem(ph, 13, 2);	//�������� ������, ����� �������
	menu(ph);
	return 0;
}

//����
void menu(TREE * ph) {
	short int m;
	string s;
	size_t countTemp;
	double valueTemp;

	system("cls");
	for (int i = 0; i < 70; i++) {
		cout << "-";
	}

	cout << endl << "\t\t���� �������� ��� �������:" << endl;
	cout << "\t1. ���������� �������� � ������ (����������)." << endl;
	cout << "\t2. ����� ������ �� �����." << endl;
	cout << "\t3. ����� �� ���������." << endl;
	cin >> m;

	switch (m) {
	case(1):
		cout << "������� ������� �������� � ��� ����������� (������� 1): ";
		cin >> valueTemp >> countTemp;
		while (countTemp < 1) {
			cout << "�� ����� ������������ ����������� ��������.\n��������� �������: ";
			cin >> valueTemp;
		}
		ph = addItem(ph, valueTemp, countTemp);
		break;
	case(2):
		cout << "������: " << endl;
		printTree(ph);
		//cout << endl;
		break;
	case(3):
		cout << "�� ������������� ������ ����� �� ���������? (y/n)" << endl;
		cin >> s;
		if (s == "y")
			return;
		break;
	default:
		cout << "������� ������������ �������, ��������� �������." << endl;
		break;
	}
	cont();
	menu(ph);
}

//������������� ������� ������
TREE * init(double val, size_t count) {
	TREE * pnew = new TREE;
	pnew->val = val;
	pnew->count = count;
	pnew->field = new TREE*[pnew->count];
	memset(pnew->field, NULL, count * sizeof(TREE*));
	return pnew;
}

//���������� �������
TREE * addItem(TREE * ph, double val, size_t count) {
	if (ph == NULL) {
		ph = init(val, count);
		return ph;
	}
	TREE * temp;
	temp = findNullItem(ph);
	if (temp == NULL) {
		delete temp;
		cout << "������ ���������!" << endl;
		return ph;
	}
	TREE * cur = new TREE;
	cur->count = count;
	cur->val = val;
	cur->field = new TREE*[cur->count];
	memset(cur->field, NULL, count * sizeof(TREE*));
	cur->field[0] = temp;

	int p = findNumberItem(temp);
	temp->field[p] = cur;
	return ph;
}

//������� �����, �� �������� ����� "�������" �������
TREE * findNullItem(TREE * ph) {
	if (ph->count != 1) {
		for (size_t i = 1; i < ph->count; ++i) {
			if (ph->field[i] == NULL) {
				return ph;
			}
		}
		int i = 1;
		while (ph == findNullItem(ph->field[i])) {
			i++;
			if (i == ph->count)
				return ph->field[0];
		}
		ph = findNullItem(ph->field[i]);
	}
	else
		return ph->field[0];
}

//������� ������ ������� ��������� �� �������
int findNumberItem(TREE * temp) {
	for (size_t i = 1; i < temp->count; ++i) {
		if (temp->field[i] == NULL) {
			return i;
		}
	}
}

//���������� ������
void printTree(TREE * ph) {
	if (ph == NULL)
		return;
	cout << ph->val << " ";
	for (size_t i = 1; i < ph->count; ++i) {
		printTree(ph->field[i]);
	}
	cout << " ";
}

//"��� ����������� ������ ����� ������� . . ."
void cont() {
	cout << "��� ����������� ������ ����� ������� . . . ";
	_getch();
}