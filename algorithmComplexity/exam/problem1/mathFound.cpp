#include <iostream>
using namespace std;
#include <map>
#include <vector>
#include <cmath> 

int pythagoras(vector<int> x, vector<int> y){
    int sum;

    sum = 0;
    for (size_t i = 0; i < x.size(); ++i) {
        sum += pow(x[i+1] - x[i], 2) + pow(y[i+1] - y[i], 2);
    }
    return sqrt(sum);
}


int natNum(int n){
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }
    return sum;
}


int main() {
    // Define the map with string keys and vector<int> values
    map<string, vector<int>> arr;

    int n = 0;

    cout << "Enter N: ";
    cin >> n;

    // Resize the vectors based on the input n
    arr["x"].resize(n);
    arr["y"].resize(n);

    // Input values for 'x' and 'y'
    cout << "Enter values for x: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr["x"][i];
    }

    cout << "Enter values for y: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr["y"][i];
    }

    int naturalSum = natNum(n);
    cout << "Sum of first " << n << " natural numbers: " << naturalSum << endl;

    int distance = pythagoras(arr["x"], arr["y"]);
    cout << "Pythagorean distance: " << distance << endl;

    return 0;
}

    // Iterate and print the map
    // for (const auto& pair : arr) {
    //     cout << pair.first << ": ";
    //     for (int val : pair.second) {
    //         cout << val << " ";
    //     }
    //     cout << endl;
    // }