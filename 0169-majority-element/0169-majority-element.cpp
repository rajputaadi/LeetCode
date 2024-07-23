class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int n;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        n = nums.size()/2;
        for(auto x: mpp){
            if(x.second >n){
                return x.first;
            }
        }
        return 0;
    }
};