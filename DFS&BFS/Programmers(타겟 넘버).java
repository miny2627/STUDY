class Solution {
    public int solution(int[] numbers, int target) {
        int answer = 0;
        answer += dfs(numbers[0], 1, numbers, target);
        answer += dfs(-numbers[0], 1, numbers, target);
        
        return answer;
    }
    int dfs(int prev, int idx, int[] numbers, int target) {
        if(idx >= numbers.length) {
            if(prev == target) return 1;
            return 0;
        }
        
        int sum = 0;
        int tmp1 = prev + numbers[idx];
        int tmp2 = prev - numbers[idx];
        
        sum += dfs(tmp1, idx + 1, numbers, target);
        sum += dfs(tmp2, idx + 1, numbers, target);
        
        return sum;
    }
}
