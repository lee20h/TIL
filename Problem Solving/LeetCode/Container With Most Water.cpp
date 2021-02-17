class Solution {
public:
    int maxArea(vector<int>& height) {
        int answer = 0;
        int left = 0;
        int right = height.size()-1;
        
        while(left < right) {
            int width = min(height[left], height[right]);
            int temp = width * (right - left);
            height[left] < height[right] ? left++ : right--;
            answer = max(answer, temp);
        }
        return answer;
    }
};
