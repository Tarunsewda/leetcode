class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n=plants.size();
        int left=0, right=n-1;
        int a= capacityA, b= capacityB;
        int cnt=0;
        while(left<right){
            if(plants[left]>a){
                cnt++;
                a= capacityA;
            }
            if(plants[right]>b){
                cnt++;
                b= capacityB;
            }
            a-=plants[left];
            b-=plants[right];
            left++;
            right--;
        }

        if(left==right && plants[left]>a && plants[right]>b)cnt++;
        return cnt;

    }
};