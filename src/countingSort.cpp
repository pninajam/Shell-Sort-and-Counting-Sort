#include <vector>
#include <algorithm>
using namespace std;

void countingSort(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return;

    int minVal = *min_element(arr.begin(), arr.end());
    int maxVal = *max_element(arr.begin(), arr.end());
    int rango = maxVal - minVal + 1;

    vector<int> count(rango, 0);
    for (int i = 0; i < n; i++)
        count[arr[i] - minVal]++;

    int index = 0;
    for (int i = 0; i < rango; i++)
        while (count[i]-- > 0)
            arr[index++] = i + minVal;
}