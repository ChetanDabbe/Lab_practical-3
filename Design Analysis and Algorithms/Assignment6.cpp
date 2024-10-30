#include <bits/stdc++.h>
using namespace std;

class quicksort {
public:
    void deterministic(vector<int>& arr, int low, int high);
    void randomized(vector<int>& arr, int low, int high);

private:
    int get_D_Partition(vector<int>& arr, int low, int high);
    int get_r_Partition(vector<int>& arr, int low, int high);
};

int quicksort::get_D_Partition(vector<int>& arr, int low, int high) {
    int lowerIdx = low;
    int pivot = arr[high];
    for (int i = low; i < high; i++) {
        if (arr[i] <= pivot) {
            swap(arr[i], arr[lowerIdx]);
            lowerIdx++;
        }
    }
    swap(arr[lowerIdx], arr[high]);
    return lowerIdx;
}

int quicksort::get_r_Partition(vector<int>& arr, int low, int high) {
    srand(time(0));
    int pivotIdx = low + (rand() % (high - low + 1));
    swap(arr[pivotIdx], arr[high]);
    int pivot = arr[high];
    int lowerIdx = low;
    for (int i = low; i < high; i++) {
        if (arr[i] <= pivot) {
            swap(arr[i], arr[lowerIdx]);
            lowerIdx++;
        }
    }
    swap(arr[lowerIdx], arr[high]); 
    return lowerIdx;
}

void quicksort::randomized(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = get_r_Partition(arr, low, high);
        randomized(arr, low, pivot - 1);
        randomized(arr, pivot + 1, high);
    }
}

void quicksort::deterministic(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = get_D_Partition(arr, low, high);
        deterministic(arr, low, pivot - 1);
        deterministic(arr, pivot + 1, high);
    }
}

int main() {
    quicksort obj;
    int ch = 0;
    int n;
    cout << "\nEnter the size: ";
    cin >> n;
    
    vector<int> arr1(n); // Initialize the vector with size n
    for (int i = 0; i < n; i++) {
        cout << "\nEnter the number: ";
        cin >> arr1[i];
    }

    while (true) {
        cout << "\n**************QUICK SORT***************";
        cout << "\n1. Using Deterministic approach\n2. Randomized Approach\n3. Exit";
        cout << "\nEnter the choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                obj.deterministic(arr1, 0, n - 1);
                for (int num : arr1) {
                    cout << num << "  ";
                }
                cout << endl;
                break;
            case 2:
                obj.randomized(arr1, 0, n - 1);
                for (int num : arr1) {
                    cout << num << "  ";
                }
                cout << endl;
                break;
            case 3:
                return 0; // Exit the program
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
