#include <iostream>
#include <vector>
using namespace std;

int paths(const int m, const int n, vector<vector<int>>);

int m, n, p;
int main() {
	//cout << "enter m" << endl;
	cin >> m;
	//cout << "enter n" << endl;
	cin >> n;
	//cout << "enter p" << endl;
	cin >> p;

	vector<vector<int>> ps(p, vector<int>(2));
	for (int i = 0; i < p; i++) {
		//cout << "enter x" << endl;
		cin >> ps[i][0];
		//cout << "enter y" << endl;
		cin >> ps[i][1];
	}

	cout << paths(m, n, ps);

	system("pause");
}

 int paths(const int m, const int n, vector<vector<int>> ps) {
	std::vector<std::vector<int>> table(m, vector<int>(n));
	//table[m][n];
	for (int i = 0; i<m; i++) {
		table.at(i).at(0) = 1;
	}

	for (int i = 0; i<n; i++) {
		table[0][i] = 1;
	}

	for (int i = 1; i<m; i++) {
		for (int j = 1; j<n; j++) {

			bool hasp=false;
			for (int f = 0; f < p; f++) {
				if (ps[f][0]-1 == i && ps[f][1]-1 == j)
					hasp = true;
				};
			if (hasp)
				table[i][j] = 0;
			else
				table[i][j] = table[i - 1][j] + table[i][j - 1];
			if (table[i][j] > 1000000007) table[i][j] %= 1000000007;
				
			}
			//cout << table[i][j] << endl;
		}
	return table[m-1][n-1];
};
