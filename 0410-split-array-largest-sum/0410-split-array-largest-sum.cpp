#include <vector>
#include <algorithm>
class Solution {

public:

int findStudent(std::vector<int>& arr, int pages) {
    int students = 1;
    int pagesPerStudent = 0;

    for (int i = 0; i < arr.size(); ++i) {
        if (pagesPerStudent + arr[i] <= pages) {
            pagesPerStudent += arr[i];
        } else {
            students++;
            pagesPerStudent = arr[i];
        }
    }
    return students;
}

int findPages(std::vector<int>& arr, int n, int m) {
    if (m > n) return -1;

    int low = *std::max_element(arr.begin(), arr.end());
    int high = std::accumulate(arr.begin(), arr.end(), 0);
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int noOfStudents = findStudent(arr, mid);

        if (noOfStudents <= m) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}
    int splitArray(vector<int>& nums, int k) {
        return findPages(nums,nums.size(),k);
    }
};