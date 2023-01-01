class Solution {
public:

    long long cal(long long a, long long b, int opt){
        if(opt==0){
            return a+b;
        }else if(opt==1){
            return a-b;
        }else if(opt==2){
            return a*b;
        }else{
            return a/b;
        }
    }

    int evalRPN(vector<string>& t) {
        int n = t.size();
        stack<int> st;
        for(int i=0; i<n; i++){
            if(t[i]=="+"){
                long long a = st.top();
                st.pop();
                long long b = st.top();
                st.pop();
                int ans = cal(b,a,0);
                st.push(ans);
            }else if(t[i]=="-"){
                long long a = st.top();
                st.pop();
                long long b = st.top();
                st.pop();
                int ans = cal(b,a,1);
                st.push(ans);
            }else if(t[i]=="*"){
                long long a = st.top();
                st.pop();
                long long b = st.top();
                st.pop();
                int ans = cal(b,a,2);
                st.push(ans);
            }else if(t[i]=="/"){
                long long a = st.top();
                st.pop();
                long long b = st.top();
                st.pop();
                int ans = cal(b,a,3);
                st.push(ans);
            }else{
                st.push(stol(t[i]));
            }
        }
        return st.top();

    }
};