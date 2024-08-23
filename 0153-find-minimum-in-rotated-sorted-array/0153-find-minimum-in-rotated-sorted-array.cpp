class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int low = 0;
        int high = n-1;
        int min = INT_MAX;
        while(low<=high){
            if(arr[low]<=arr[high]){
                if(arr[low]<min){
                    min = arr[low];
                }
                low++;
            }
            else{
                if(arr[high] < min){
                    min = arr[high];
                }
                high--;
            }
        }
        return min;
    }
};