#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int N, F;
    int result;
    int rest;
    int output;
    cin >> N;
    cin >> F;
    result = N / 100;
    result *= 100;
    rest = result % F;
    if (rest == 0) {
        cout << "00" << endl;
    }else {
        output = (F-rest) % 100;
        cout << setw(2)<< setfill('0') << output<< endl;
    }

    return 0;
}