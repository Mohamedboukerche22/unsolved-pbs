//https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) 
{
    int n = mat.size();
    vector<vector<int>>ar = mat;
        for(int dd = 0 ; dd < 4 ;dd++){
           if(ar == target){return true;}
        vector<vector<int>> tmp(n,vector<int>(n));
        for(int i = 0 ;i < n;i++){for(int j = 0 ;j <n;j++){
            tmp[j][n-1-i] = ar[i][j];
        }
    ar = tmp;
} }
    
    
    return false;
}
};
