class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> p1, p2;
        int result = 0;

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (img1[r][c] == 1) p1.push_back({r, c});
                if (img2[r][c] == 1) p2.push_back({r, c});
            }
        }
        
        map<pair<int, int>, int> count;
        for (auto& a : p1) {
            for (auto& b : p2) {
                int shiftR = b.first - a.first;
                int shiftC = b.second - a.second;
                count[{shiftR, shiftC}]++;
                result = max(result, count[{shiftR, shiftC}]);
            }
        }
        
        return result;
    }
};