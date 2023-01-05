/*

____________________________________________________________________________________________

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define pbds tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

pbds mt; // declare variable
mt.insert(val);
auto it = mt.order_of_key(val); --------> gives number strictly less than val
int num = mt.size()-it ----> gives number greater than or equal to val


______________________________________________________________________________________________

ordered_set X;
X.insert(1);
X.insert(2);
X.insert(4);
X.insert(8);
X.insert(16);

cout<<*X.find_by_order(1)<<endl; // 2
cout<<*X.find_by_order(2)<<endl; // 4
cout<<*X.find_by_order(4)<<endl; // 16
cout<<(end(X)==X.find_by_order(6))<<endl; // true

cout<<X.order_of_key(-5)<<endl;  // 0
cout<<X.order_of_key(1)<<endl;   // 0
cout<<X.order_of_key(3)<<endl;   // 2
cout<<X.order_of_key(4)<<endl;   // 2
cout<<X.order_of_key(400)<<endl; // 5

If we want to get map but not the set, as the second argument type must be used mapped type. Apparently, the tree supports the same operations as the set (at least I haven't any problems with them before), but also there are two new features — it is find_by_order() and order_of_key(). The first returns an iterator to the k-th largest element (counting from zero), the second — the number of items in a set that are strictly smaller than our item. Example of use:

Number of items strictly smaller than k = X.order_of_key(-5)

In this case:-

nums1[i] - nums2[i] <= nums1[j]-nums2[j]+diff;
Insert: nums1[j]-nums2[j]+diff;

searching for (nums1[i] - nums2[i]) will give me number strictly less than this. but we want numbers from the set which are greater or equal to nums1[i] - nums2[i] so doing (n-order);

*/

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define pbds tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        pbds mt;
        long long cnt = 0;
        int n = nums1.size();
        for(int i=n-1; i>=0; i--){
            int temp = nums1[i]-nums2[i];
            auto it = mt.order_of_key(temp);
            cnt += (mt.size()-it);
            mt.insert(temp+diff);
        }
        return cnt;
    }
};
