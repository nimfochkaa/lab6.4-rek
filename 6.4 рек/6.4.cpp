#include <iostream>
#include <ctime>
using namespace std;

void Create(float* a, const int size, const int Low, const int High) {
    for (int i = 0; i < size; i++) {
        a[i] = Low + rand() % (High - Low + 1);
    }
}

float FindMin(const float* a, int size) {
    if (size == 1) {
        return a[0];
    }
    float minOfRest = FindMin(a, size - 1);
    return (a[size - 1] < minOfRest) ? a[size - 1] : minOfRest;
}

float SumBetweenPositives(const float* a, int size, int& firstPos, int& lastPos) {
    if (size == 0) {
        return 0;
    }

    if (a[size - 1] > 0) {
        lastPos = size - 1;
        if (firstPos == -1) {
            firstPos = size - 1;
        }
    }

    return a[size - 1] + SumBetweenPositives(a, size - 1, firstPos, lastPos);
}

float SumBetweenPositives(const float* a, const int size) {
    int firstPos = -1;
    int lastPos = -1;

    SumBetweenPositives(a, size, firstPos, lastPos);

    if (firstPos != -1 && lastPos != -1 && firstPos < lastPos) {
        float sum = 0;
        for (int i = firstPos + 1; i < lastPos; i++) {
            sum += a[i];
        }
        return sum;
    }
    return 0; 
}

void RearrangeArray(float* a, const int size) {
    int zeroCount = 0;
    float* temp = new float[size];

    for (int i = 0; i < size; i++) {
        if (a[i] == 0) {
            temp[zeroCount++] = 0;
        }
    }

    for (int i = 0; i < size; i++) {
        if (a[i] != 0) {
            temp[zeroCount++] = a[i];
        }
    }

    for (int i = 0; i < size; i++) {
        a[i] = temp[i];
    }

    delete[] temp;
}

int main() {
    srand(static_cast<unsigned>(time(NULL)));
    int n;

    cout << "Enter the number of array elements: ";
    cin >> n;

    float* a = new float[n];
    int Low = -10;
    int High = 10;

    Create(a, n, Low, High);

    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    float minElement = FindMin(a, n);
    cout << "Minimal element: " << minElement << endl;

    float sum = SumBetweenPositives(a, n);
    if (sum == 0) {
        cout << "There are not enough positive elements to calculate the sum." << endl;
    }
    else {
        cout << "The sum of the elements between the first and last positive ones: " << sum << endl;
    }

    RearrangeArray(a, n);

    cout << "Rearranged Array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    delete[] a;

    return 0;
}
