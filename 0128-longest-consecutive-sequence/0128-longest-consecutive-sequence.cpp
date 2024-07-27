class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int last_smallest =INT_MIN;
        int longest =1;
        int cnt =0;
        int n = nums.size();
        if(n==0) return 0;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<n;i++){
            if(nums[i]-1==last_smallest){
                cnt+=1;
                last_smallest = nums[i];
            }
            else if(nums[i] != last_smallest){
                cnt=1;
                last_smallest = nums[i];
            }
            longest = max(longest,cnt);
        }
            return longest;

    }
};