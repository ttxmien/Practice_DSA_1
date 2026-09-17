class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        vector<int> minLen(arr.size(), INT_MAX);
        int sum = 0, left = 0;
        int result = INT_MAX, shortest = INT_MAX;
        
        for (int right = 0; right < arr.size(); ++right) {
            sum += arr[right];
            while (sum > target) sum -= arr[left++];
            if (sum == target) {
                int len = right - left + 1;
                if (left > 0 && minLen[left - 1] != INT_MAX) {
                    result = min(result, len + minLen[left - 1]);
                }
                shortest = min(shortest, len);
            }
            minLen[right] = shortest;
        }
        
        return result == INT_MAX ? -1 : result;
    }
};