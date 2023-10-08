#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    ifstream fin("KARTA.IN");
    fin >> n >> m;
    vector<vector<int>> map(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fin >> map[i][j];
        }
    }
    fin.close();

    int count = 0;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (map[i][j] == 1) {
                bool isSquare = true;
                int size = 1;
                while (isSquare && i + size < n && j + size < m) {
                    for (int k = i; k <= i + size; k++) {
                        if (map[k][j + size] == 0) {
                            isSquare = false;
                            break;
                        }
                    }
                    for (int k = j; k <= j + size; k++) {
                        if (map[i + size][k] == 0) {
                            isSquare = false;
                            break;
                        }
                    }
                    if (isSquare) {
                        size++;
                    }
                }
                if (size > 1) {
                    count++;
                }
            }
        }
    }

    ofstream fout("KARTA.OUT");
    fout << count << endl;
    fout.close();

    return 0;
}