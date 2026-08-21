
#include <bits/stdc++.h>
using namespace std;

int searchTriplets(vector<int>& arr, int target) {
    sort(arr.begin(), arr.end());
    int count = 0;

    for (int i = 0; i < arr.size() - 2; i++) {
        int left = i + 1;
        int right = arr.size() - 1;

        while (left < right) {
            int sum = arr[i] + arr[left] + arr[right];

            if (sum < target) {
                count += right - left;
                left++;
            } else {
                right--;
            }
        }
    }

    return count;
}

int main() {
    vector<int> arr = {-1, 0, 2, 3};
    int target = 3;

    cout << searchTriplets(arr, target);
}
