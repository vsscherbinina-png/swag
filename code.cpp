#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

// Демонстрация работы
int main() {
    vector<int> data = {64, 25, 12, 22, 11};
    selectionSort(data);
    cout << "Результат сортировки выбором: ";
    for (int value : data) {
        cout << value << " ";
    }
    cout << endl;
    return 0;
}





#include <iostream>
#include <vector>
using namespace std;

void shellSort(vector<int>& arr) {
    int n = arr.size();
    
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// Демонстрация работы
int main() {
    vector<int> data = {12, 34, 54, 2, 3};
    shellSort(data);
    cout << "Результат сортировки Шелла: ";
    for (int value : data) {
        cout << value << " ";
    }
    cout << endl;
    return 0;
}






#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Демонстрация работы
int main() {
    vector<int> data = {12, 11, 13, 5, 6, 7};
    heapSort(data);
    cout << "Результат пирамидальной сортировки: ";
    for (int value : data) {
        cout << value << " ";
    }
    cout << endl;
    return 0;
}




#include <iostream>
#include <vector>
using namespace std;

int linearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// Демонстрация работы
int main() {
    vector<int> data = {2, 3, 4, 10, 40};
    int target = 10;
    int result = linearSearch(data, target);
    
    if (result != -1) {
        cout << "Элемент " << target << " найден на позиции " << result << endl;
    } else {
        cout << "Элемент не найден" << endl;
    }
    return 0;
}





#include <iostream>
#include <vector>
using namespace std;

int fibonacciSearch(const vector<int>& arr, int target) {
    int n = arr.size();
    
    int fibMM2 = 0;
    int fibMM1 = 1;
    int fibM = fibMM1 + fibMM2;
    
    while (fibM < n) {
        fibMM2 = fibMM1;
        fibMM1 = fibM;
        fibM = fibMM1 + fibMM2;
    }
    
    int offset = -1;
    
    while (fibM > 1) {
        int i = min(offset + fibMM2, n - 1);
        
        if (arr[i] < target) {
            fibM = fibMM1;
            fibMM1 = fibMM2;
            fibMM2 = fibM - fibMM1;
            offset = i;
        }
        else if (arr[i] > target) {
            fibM = fibMM2;
            fibMM1 = fibMM1 - fibMM2;
            fibMM2 = fibM - fibMM1;
        }
        else {
            return i;
        }
    }
    
    if (fibMM1 && offset + 1 < n && arr[offset + 1] == target) {
        return offset + 1;
    }
    
    return -1;
}

// Демонстрация работы
int main() {
    vector<int> data = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100};
    int target = 85;
    int result = fibonacciSearch(data, target);
    
    if (result != -1) {
        cout << "Элемент " << target << " найден на позиции " << result << endl;
    } else {
        cout << "Элемент не найден" << endl;
    }
    return 0;
}
