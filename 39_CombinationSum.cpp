class Solution {
    public:
        set<vector<int>> s;
        //To avoid multiple (same) saving we use set.
    
        void getAllCombinations(vector<int>& arr, int i, int tar, vector<vector<int>> &ans, vector<int> &combin){
    
            if(tar == 0) {
                if(s.find(combin) == s.end()) {
                    ans.push_back(combin);
                    s.insert(combin);
                }
    
                return;
            }
    
            if(i == arr.size() || tar < 0) {
                return;
            }
    
    
            combin.push_back(arr[i]);
    
            //Single
            getAllCombinations(arr, i+1, tar-arr[i], ans, combin);
    
            //Multiple
            getAllCombinations(arr, i, tar-arr[i], ans, combin);
    
            //Exclusion
            combin.pop_back(); //Backtracking
            getAllCombinations(arr, i+1, tar, ans, combin);
        }
    
        vector<vector<int>> combinationSum(vector<int>& arr , int tar) {
            vector<vector<int>> ans;
            vector<int> combin;
    
            getAllCombinations(arr, 0, tar, ans, combin);
    
            return ans;
        }
    };