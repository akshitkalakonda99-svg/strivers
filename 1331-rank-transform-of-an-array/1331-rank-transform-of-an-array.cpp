class Solution {
public:
    int bs(vector<int>& temp,int target,int low,int high){
        // long long int n=temp.size();
        if(low>high) return -1;
        int mid=low+(high-low)/2;
        if(target==temp[mid]) return mid;
        if(temp[mid]>target){
            high=mid-1;
            return bs(temp,target,low,high);
        }
        // if(temp[mid]<target){
        //     return bs(temp,target,mid+1,high);
        // }
        return bs(temp,target,mid+1,high);
    }

    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;

sort(temp.begin(), temp.end());

temp.erase(unique(temp.begin(), temp.end()), temp.end());

for(int i=0;i<arr.size();i++){
    arr[i] = bs(temp, arr[i], 0, temp.size()-1) + 1;
}
        return arr;
        
    }
};