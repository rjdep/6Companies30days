class Solution {
public:
    /*
    // Bubble sort
    vector<int> bubbleSort(vector<int> &arr){
        // compare every consecutive elements and do swap if arr[i]>arr[i+1]
        // can't be used for high value of n
        for(int i=0; i<n-1; i++){
            bool f = true;
            for(int j=0; j<n-i-1; j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                    f = false;
                }
            }
            if(f) break;
        }
        return arr;
        // TIME COMPLEXITY:
        // Best- O(n), Average:- O(n^2), Worst:- O(n^2)
        // SPACE COMPLEXITY:
        // O(1)
    }

    // Insertion sort
    vector<int> insertion(vector<int> &arr){
        int j;
        for(int i=1; i<n; i++){
            int x = arr[i];
            j = i-1;
            while(j>=0 && arr[j]>x){
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=x;
        }
        return arr;
        // TIME COMPLEXTIY:
        // Best- O(n), Average- o(n^2), Worst-O(n^2)
        // SPACE COMPLEXITY
        // O(1)
    }

    // Selection sort
    vector<int> selection(vector<int> &arr){
        int idx = -1;
        for(int i=0; i<n-1; i++){
            idx = i;
            for(int j=i+1; j<n; j++){
                if(arr[j]<arr[idx]){
                    idx=j;
                }
            }
            if(idx!=i){
                swap(arr[i],arr[idx]);
            }
        }
        return arr;
        // TIME COMPLEXITY:
        // Best- O(n^2), Average- O(n^2), Worst- O(n^2)
        // SPACE COMPLEXITY:
        // O(1)

    }

    // QUICK SORT

    */
    // Merge sort

    void Merge(vector<int> &arr, int l, int mid, int r){
        int n1 = mid-l+1;
        int n2 = r-mid;
        vector<int> br(n1),cr(n2);
        for(int i=0; i<n1; i++){
            br[i]=arr[i+l];
        }
        for(int i=0; i<n2; i++){
            cr[i]=arr[mid+1+i];
        }
        int i = 0, j=0, k=l;
        while(i<n1 && j<n2){
            if(br[i]>cr[j]){
                arr[k]=cr[j];
                j++;
            }else{
                arr[k]=br[i];
                i++;
            }
            k++;
        }
        while(i<n1){
            arr[k++]=br[i++];
        }
        while(j<n2){
            arr[k++]=cr[j++];
        }
    }

    void mergeSort(vector<int> &arr, int l, int r){
        if(l<r){
            int mid = (l+r)/2;
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,r);
            Merge(arr,l,mid,r);
        }
    }
    

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums,0,n-1);
        return nums;
    }
};
