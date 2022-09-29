class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if(arr.size() == 1) return arr;
        
        int index = min(int(arr.size()-1), int(lower_bound(arr.begin(), arr.end(), x) - arr.begin()));
        int before = index-1;
        int after = index;
        
        multiset<int> tmp;
        vector<int> ans;
        while(arr[index] == x && k > 0){
            --k;
            tmp.insert(arr[index]);
            ++after;
            ++index;
        }
        
        bool toggle = true;
        while(k--){
            if(before < 0){
                tmp.insert(arr[after]);
                ++after;
            }else if(after >= arr.size()){
                tmp.insert(arr[before]);
                --before;
            }else if(arr[after] - x < x - arr[before]){
                tmp.insert(arr[after]);
                ++after;
            }else{
                tmp.insert(arr[before]);
                --before;
            }
        }
        
        for(auto i = tmp.begin(); i != tmp.end(); i++){
            ans.push_back(*i);
        }
        
        return ans;
    }
};