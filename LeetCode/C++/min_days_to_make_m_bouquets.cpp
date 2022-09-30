class Solution {
public:
    
    bool isValid(int res, vector<int>& bloomDay, int m, int k){
        int curr = 0, adj =0;
        for(int i=0;i<bloomDay.size(); i++){
            if(bloomDay[i]<=res){
                adj++;
                if(adj == k){
                    curr++;
                    adj = 0;
                }     
            }
            else
                adj = 0; 
            if(curr >= m) break;
        }
        if(curr < m)
            return false;
        else
            return true;
                          
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(m*k>bloomDay.size())
            return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            if(isValid(mid,bloomDay,m,k)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
            
        }
        
        return ans;
        
    }
};
