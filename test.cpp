#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Tuple {
public:
	int _x;
	int _y;
	Tuple(int x, int y) {
		_x = x;
		_y = y;
	}
};

class OrderedSet {
public:
	std::vector<Tuple> positions;
	bool notValid;
	void add(Tuple &t) {
		positions.push_back(t);
	}

	bool has(Tuple t) {
		for (int i = 0; i < positions.size(); i++) {
			if (positions[i]._x == t._x && positions[i]._y == t._y) return true;
		}
		return false;
	}

	OrderedSet(int x, int y) {
		add(Tuple(x, y));
	}

};


int m; int n; int p;
vector<Tuple> ps;
vector<OrderedSet> mainSet;

void find(int x, int y, OrderedSet *path) {
	(*path).add(Tuple(x, y));
	if (x == m && y == n) {
		mainSet.push_back(*path);
		(*path).positions.clear();
	}

	if (x < m) find(x + 1, y, path);

	if (y < n) find(x, y + 1, path);
}

int main()
{
	int count = 0;
	cin >> m >> n >> p;

	for (int i = 0; i < p; i++) {
		int p1, p2;
		cin >> p1 >> p2;
		ps.push_back(Tuple(p1, p2));
	}

	find(1, 1, &OrderedSet(0, 0));//find m n's paths

	if (ps.size() > 0) {
		for (int i = 0; i < ps.size(); i++) {
			for (int e = 0; e < mainSet.size(); e++) {
				if (mainSet[e].has(ps.at(i))) continue;
				else count++;
			}
		}
	}
	else count = mainSet.size();

	cout << count << endl;
	system("pause");
	return 0;
}