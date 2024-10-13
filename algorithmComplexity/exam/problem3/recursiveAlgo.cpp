#include <iostream>
using namespace std;

int towerOfHanoi(int n, string source, string auxiliary, string target) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << target << endl;
        return 0;
    }

    towerOfHanoi(n - 1, source, target, auxiliary);

    cout << "Move disk " << n << " from " << source << " to " << target << endl;

    towerOfHanoi(n - 1, auxiliary, source, target);

    return (1 << n) - 1; // 2^n - 1
}

int main() {
    int n;

    cout << "Enter number: ";
    cin >> n;

    int output = towerOfHanoi(n, "A", "B", "C");
    cout << "\nN: " << n << endl;
    cout << "Total number of moves: " << output << endl;
    

    return 0;
}
