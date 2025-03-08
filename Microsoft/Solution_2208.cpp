class Solution {
public:
    int halveArray(vector<int>& nums) {
        double initSum = 0;
        double curSum = 0;
        int count = 0;
         priority_queue<double> pq;
        for(int i = 0; i < nums.size(); i++) {
            initSum += nums[i];
            pq.push(nums[i]);
        }
        curSum = initSum;
        while(curSum * 2 > initSum) {
            count++;
            double top = pq.top();
            pq.pop();
            curSum = curSum - top + top/2;
            pq.push(top/2);
        }
        return count;
    }
};