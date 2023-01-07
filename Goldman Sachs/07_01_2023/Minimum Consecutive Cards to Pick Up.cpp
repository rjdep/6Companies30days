class Solution {
public:

    bool check(int mid, vector<int> &cards){
        map<int,int> mp;
        for(int i=0; i<mid; i++){
            mp[cards[i]]++;
            if(mp[cards[i]]>1) return true;
        }
        int n = cards.size();
        for(int i=mid; i<n; i++){
            mp[cards[i-mid]]--;
            mp[cards[i]]++;
            if(mp[cards[i]]>1) return true;
        }
        return false;
    }

    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size();
        int lo=1, hi=n;
        int ans = 1e9;
        // while(lo<=hi){
        //     int mid = (lo+hi)/2;
        //     if(check(mid,cards)){
        //         ans = mid;
        //         hi=mid-1;
        //     }else{
        //         lo=mid+1;
        //     }
        // }
        lo=0,hi=-1;
        map<int,int> mp;
        bool f = true;
        while(lo<n){
            while(f && hi+1<n && (mp.find(cards[hi+1]) == mp.end() || mp[cards[hi+1]]<=1)){
                hi++;
                mp[cards[hi]]++;
                if(mp[cards[hi]]==2){
                    f = false;
                }
            }
            if(!f) ans = min(ans,hi-lo+1);
            if(lo<=hi){
                mp[cards[lo]]--;
                lo++;
                if(mp[cards[hi]]<=1){
                    f = true;
                }
            }else{
                lo++;
                hi=lo-1;
                f = true;
            }
        }
        if(ans==1e9) return -1;
        return ans;
    }
};
