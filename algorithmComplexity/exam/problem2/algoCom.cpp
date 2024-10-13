#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono> 

using namespace std;
using namespace std::chrono;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int generate_random_minutes() {
    return rand() % 241; 
}

int main() {

    const int SAZ = 500;
    const int MAZ = 5000;
    const int LAZ = 15000;

    vector<int> deliveryTimes(SAZ); 
    vector<int> deliveryTimes1(MAZ);
    vector<int> deliveryTimes2(LAZ);

    // Fill the arrays with random delivery times
    for (int i = 0; i < SAZ; ++i) deliveryTimes[i] = generate_random_minutes();
    for (int i = 0; i < MAZ; ++i) deliveryTimes1[i] = generate_random_minutes();
    for (int i = 0; i < LAZ; ++i) deliveryTimes2[i] = generate_random_minutes();

    vector<vector<int>> allDeliveryTimes = {deliveryTimes, deliveryTimes1, deliveryTimes2};
    vector<string> labels = {"small", "medium", "large"};



    // Measure and print time for Bubble Sort
    cout << "Bubble Sort Timing:" << endl;
    for (size_t i = 0; i < allDeliveryTimes.size(); ++i) {
        vector<int> cont = allDeliveryTimes[i];  

        auto start = high_resolution_clock::now(); 
        bubbleSort(cont); 
        auto stop = high_resolution_clock::now();  

        auto duration = duration_cast<milliseconds>(stop - start);
        cout << "Bubble sort time for " << labels[i] << " array: " << duration.count() << " ms" << endl;
    }

    // Measure and print time for Merge Sort
    cout << "\nMerge Sort Timing:" << endl;
    for (size_t i = 0; i < allDeliveryTimes.size(); ++i) {
        vector<int> cont = allDeliveryTimes[i]; 

        auto start = high_resolution_clock::now(); 
        mergeSort(cont, 0, cont.size() - 1); 
        auto stop = high_resolution_clock::now();  

        auto duration = duration_cast<milliseconds>(stop - start);
        cout << "Merge sort time for " << labels[i] << " array: " << duration.count() << " ms" << endl; 
    }

    return 0;
}





// int printSorted(vector<int>& arr){
//     for (const int& t : arr) {
//         cout << t << " ";
//     }
//     cout << std::endl;

//     return 0;
    
// }


// to print 
        // cout << "Sorted delivery times (" << labels[i] << "):" << endl;
        // printSorted(allDeliveryTimes[i]);
        // cout << " " << endl;
