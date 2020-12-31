class Solution {
public:
    int kthFactor(int n, int k) {
        set<int> s;
        for (int d = 1; d * d <= n; ++d) {
            if (n % d == 0) {
                s.insert(d); 
                s.insert(n/d);
            }
        }
        if (s.size() < k) {
            return -1;
        }
        
        for (auto itr = s.begin(); itr != s.end(); ++itr) {
            if (--k == 0) return *itr;               
        }
        return -1;    
    }
};
