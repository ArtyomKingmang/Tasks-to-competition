#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream fout("OUTPUT.txt");
    for (int i = 1000; i <= 9999; i++) { 
        if (i % 7 == 0) {
            int sum = 0;
            int num = i;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            if (sum % 7 == 0) {
                fout << i << endl;
            }
        }
    }
    fout.close();
    return 0;
}