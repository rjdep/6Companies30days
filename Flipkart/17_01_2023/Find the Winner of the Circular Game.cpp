class Solution {
public:

    int rec(int n, int k){
        if(n==1) return 0;
        return (rec(n-1,k)+k)%n;
    }

    int findTheWinner(int n, int k) {
        /*
        vector<int> arr(n);
        for(int i=0; i<n; i++) arr[i]=i+1;
        int cnt = 1, idx = 0;
        while(1){
            while(cnt<k){
                if(arr[idx] != -1){
                    cnt++;idx++;
                }
                while(idx<n && arr[idx]==-1) idx++;
                if(idx==n) idx = 0;
                while(idx<n && arr[idx]==-1) idx++;
            }
            int temp = 0;
            for(int i=0; i<n; i++){
                if(arr[i]==-1){
                    temp++;
                }
            }
            if(temp==n-1) break;
            // cout<<arr[idx]<<endl;
            arr[idx]=-1;
            idx++;
            if(idx==n) idx = 0;
            cnt = 1;
        }
        int ans = -1;
        for(int i=0; i<n; i++){
            if(arr[i] != -1) ans = i+1;
        }
        return ans;

        */

        return rec(n,k)+1;
    }
};
