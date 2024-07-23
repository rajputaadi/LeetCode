class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int sum2 =0;
        sum += n*(n+1)/2;

        for(int i=0;i<n;i++){
            sum2 += nums[i];

        }
        int number = sum-sum2;
        return number;
    }
};