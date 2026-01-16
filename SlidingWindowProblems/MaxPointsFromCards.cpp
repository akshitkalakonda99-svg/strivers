class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int l = 0, r = 0;
        long long int totalSum = 0;
        int n = cardPoints.size();
        for (int i = 0; i < n; i++) {
            totalSum += cardPoints[i];
        }
        if (k == n)
            return totalSum;
        r = n - k - 1;
        long long int sum = 0;
        for (int i = l; i <= r; i++) {
            sum += cardPoints[i];
        }
        // l++;
        // r++;
        long long int maxSum = 0;
        maxSum = max(totalSum - sum, maxSum);
        while (r < n - 1) {
            sum = sum - cardPoints[l] + cardPoints[r + 1];
            // long long int summ=totalSum-sum;
            maxSum = max(totalSum - sum, maxSum);
            l++;
            r++;
        }
        return maxSum;
    }
};
