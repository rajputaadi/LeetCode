class Solution {
public:
    int IfPossile(vector<int> & bloomDay,int mid,int m,int k){
        int cnt =0;
        int noofbouque =0;
        int n = bloomDay.size();
        for(int i =0 ;i<n;i++){
            if(bloomDay[i]<=mid){
                cnt++;
            }
            else{
                noofbouque += (cnt/k);
                cnt =0;
            }
        }
        noofbouque += (cnt/k);
        return noofbouque>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long  val = m*1LL*k*1LL;
        int n =bloomDay.size();
        if(val>n) return -1;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int i =0;i<n;i++){
            mini = min(mini,bloomDay[i]);
            maxi = max(maxi,bloomDay[i]);
        }
        int low = mini;
        int high = maxi;
        while(low<=high){
            int mid =  (low+high)/2;
            if(IfPossile(bloomDay,mid,m,k) == true){
                high = mid -1;
            }
            else low = mid +1;
        }
        return low;
    }
};