/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        vector<int> dp(n,-1);
        int lo=0,hi=n-1;
        int idx = -1;
        while(lo<=hi){
            if(lo==hi){
                break;
            }
            int mid = (lo+hi)/2;
            if(mid==0){
                idx = mid;
                break;
            }else if(mid==lo){
                int x = mid+1;
                int a,b;
                if(dp[mid] != -1) a = dp[mid];
                else {
                    a = mountainArr.get(mid);
                    dp[mid]=a;
                }
                if(dp[x] != -1) b = dp[x];
                else{
                    b = mountainArr.get(x);
                    dp[x]=b;
                }
                if(a>b){
                    idx = mid;
                    hi=mid;
                }else{
                    idx = x;
                    lo=x;
                }
            }else{
                int x = mid-1;
                int a,b;
                if(dp[mid] != -1) a = dp[mid];
                else {
                    a = mountainArr.get(mid);
                    dp[mid]=a;
                }
                if(dp[x] != -1) b = dp[x];
                else{
                    b = mountainArr.get(x);
                    dp[x]=b;
                }

                if(a>b){
                    idx = mid;
                    lo=mid;
                }else{
                    idx = x;
                    hi=x;
                }

            }
        }

        int ans = -1;
        int lo1 = 0, hi1 = idx;
        while(lo1<=hi1){
            int mid = (lo1+hi1)/2;
            int a;
            if(dp[mid] != -1){
                a = dp[mid];
            }else{
                a = mountainArr.get(mid);
                dp[mid]=a;
            }
            if(a==target){
                return mid;
            }else if(a>target){
                hi1 = mid-1;
            }else{
                lo1 = mid+1;
            }
        } 

        lo1 = idx+1, hi1 = n-1;
        while(lo1<=hi1){
            int mid = (lo1+hi1)/2;
            int a;
            if(dp[mid] != -1){
                a = dp[mid];
            }else{
                a = mountainArr.get(mid);
                dp[mid]=a;
            }
            if(a==target){
                return mid;
            }else if(a>target){
                lo1 = mid+1;
            }else{
                hi1 = mid-1;
            }
        }   

        return ans; 
   







    }
};
