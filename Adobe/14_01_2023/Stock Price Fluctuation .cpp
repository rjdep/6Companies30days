class StockPrice {
public:

    map<int,int> mp;
    multiset<int> mt;
    StockPrice() {
        mp.clear();
        mt.clear();
    }
    
    void update(int timestamp, int price) {
        if(mp.find(timestamp)==mp.end()){
            mp[timestamp]=price;
            mt.insert(price);
            return;
        }
        int x = mp[timestamp];
        mt.erase(mt.find(x));
        mp[timestamp]=price;
        mt.insert(price);
        return;
    }
    
    int current() {
        auto it = *mp.rbegin();
        return it.second;
    }
    
    int maximum() {
        return *mt.rbegin();
    }
    
    int minimum() {
        return *mt.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
