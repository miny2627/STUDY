import java.util.*;

class Solution {
    public int solution(int distance, int[] rocks, int n) {
        Arrays.sort(rocks);
        return binarySearch(distance, rocks, n);
    }
    int binarySearch(int distance, int[] rocks, int n) {
        int min = 1, max = distance;
        int ans = 0, mid = 0;
        
        while(min <= max) {
            int cnt = 0, prev = 0;
            mid = (min + max) / 2; // 거리의 최솟값
            
            for(int i = 0; i < rocks.length; i++) {
                // mid보다 작은 값이 존재할 경우 제거
                if(rocks[i] - prev < mid) {
                    cnt++;
                } else {
                    prev = rocks[i];
                }
            }
            
            // 마지막 지점
            if(distance - prev < mid) cnt++;
            
            if(cnt <= n) {
                ans = ans > mid ? ans : mid;
                min = mid + 1;
            } else {
                max = mid - 1;
            }
        }
        return ans;
    }
}
