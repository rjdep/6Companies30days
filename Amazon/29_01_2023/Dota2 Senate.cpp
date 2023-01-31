class Solution {
public:
    string predictPartyVictory(string s) {
        int n = s.size(), cntR = 0, cntD=0;
        queue<int> R,D;
        for(int i=0; i<n; i++){
            if(s[i]=='R') R.push(i);
            else D.push(i);
        }

        while(!R.empty() && !D.empty()){
            auto it1 = R.front();
            auto it2 = D.front();
            R.pop();
            D.pop();
            if(it1<it2){
                R.push(it1+n);
            }else{
                D.push(it2+n);
            }
        }
        if(R.empty()) return "Dire";
        else return "Radiant";

        

    }
};
