#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int sum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

bool compare(int a, int b) {
    int sumA = sum(a);
    int sumB = sum(b);
    if (sumA == sumB) {
        return a < b;
    }
    return sumA < sumB;
}

int main() {
    ifstream fin("INPUT.TXT");
    ofstream fout("OUTPUT.TXT");

    int n;
    fin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        fin >> nums[i];
    }

    sort(nums.begin(), nums.end(), compare);

    for (int i = 0; i < n; i++) {
        fout << nums[i] << " ";
    }
    fout << endl;

    fin.close();
    fout.close();

    return 0;
}