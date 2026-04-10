// still getting TLE 
// caz it's work on O(n²) that's obvious 

class Solution {
public:
   vector<long long > rotateArr(vector<int>& nums, int d) {
    vector<long long> arr(nums.begin(), nums.end());
    int n = arr.size();
    d %= n;
    reverse(arr.begin(), arr.end());
    reverse(arr.begin() , arr.begin()+d);
    reverse(arr.begin()+d, arr.end());

    return arr;
}
    int maxRotateFunction(vector<int>& nums) {
        int n =nums.size();
        if(n==1){return 0;}
        vector<long long>dp;
        //vector<int>tmp;
        int best=-9999999999;
        for(int i=0;i<n;i++){
             dp=rotateArr(nums,i);
             /*for(auto i:tmp){
             cout <<i<<" ";
              }
              cout <<"\n";*/
             int sum=0;
             for(int j=0;j<n;j++){
                sum += (dp[j]*j);
                //cout << "sum:"<<i<<" "<<sum;
             }
            // cout << "sum:"<<sum<<endl;
             best = max(sum,best);
        }
        
        return best;
    }
   
};
