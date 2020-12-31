class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int top = -1, area = 0, maxarea = 0, i = 0;
        std::stack<int> st;
        heights.push_back(0);
        
        while (i<heights.size()) {
            if (st.empty() || heights[st.top()] <= heights[i]) {
                st.push(i++);
            } else {
                if (heights[st.top()] > heights[i]) {
                    int last_element = st.top();
                    st.pop();

                    if (st.empty()) {
                        area = heights[last_element] * i;
                    } else {
                        area = heights[last_element] * (i - st.top() -1);
                    }

                    maxarea = max(maxarea, area);
                }
            }
        }

        return maxarea;
    }
};
