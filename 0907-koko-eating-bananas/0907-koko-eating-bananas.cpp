class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        while(low<high){
            int mid = (low+high)/2;
            int TotalH =0;
            for(auto i : piles){
                TotalH += ceil((double)i/mid);
            }
            if(TotalH > h){
                low = mid +1;
            }
            else high = mid;
        }
        return low;
    }
};