class Solution {
public:
#define fr(i, n) for (int i = 0; i < (n); i++)
    int T[4*100100];

int merge(int a, int b){
    return a+b;
}
int n;
void build(int id, int l, int r){
    if(l==r){
        T[id]=0;
        return;
    }
    int mid = (l+r)/2;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    T[id]=merge(T[id<<1],T[id<<1|1]);
}

void update(int id, int l, int r, int idx){
    if(l>idx || r<idx) return;
    if(l==r){
        T[id]=1;
        return;
    }
    int mid = (l+r)/2;
    update(id<<1,l,mid,idx);
    update(id<<1|1,mid+1,r,idx);
    T[id]=merge(T[id<<1],T[id<<1|1]);
}

int query(int id, int l, int r, int lq, int rq){
    if(lq<0 || rq>=n) return 0;
    if(l>rq || r<lq) return 0;
    if(l>=lq && r<=rq) return T[id];
    int mid = (l+r)/2;
    return query(id<<1,l,mid,lq,rq)+query(id<<1|1,mid+1,r,lq,rq);
}

    long long goodTriplets(vector<int>& arr, vector<int>& brr) {
         map<int,int> mp;
         n = arr.size();
    fr(i,n){
        mp[brr[i]]=i;
    }
    long long cnt = 0;
    build(1,0,n-1);
    fr(i,n){
        if(i==0){
            update(1,0,n-1,mp[arr[i]]);
        }else{
            int idx = mp[arr[i]];
            if(idx==0){
                update(1,0,n-1,mp[arr[i]]);
            }else{
                int a = query(1,0,n-1,0,idx-1); 
                int b = query(1,0,n-1,idx+1,n-1);

                int c = n-idx-1;
                c-=b;
                cnt += (1LL*a*c);
                update(1,0,n-1,mp[arr[i]]);
            }
        }
    }
    return cnt;
    }
};
