import java.util.*;

class Solution {
    public long solution(int n, int[] times) {
        Arrays.sort(times);
        return binarySearch(n, times);
    }
    
    long binarySearch(int n, int[] times) {
        long min = 1, max = (long)times[times.length - 1] * n;
        long ans = max, mid = 0, sum;
        
        while(min <= max) {
            sum = 0;
            mid = (min + max) / 2;
            
            for(int i : times) {
                sum += mid / i;
            }
            
            if(sum >= n) {
                ans = ans > mid ? mid : ans;
                max = mid - 1;
            } else {
                min = mid + 1;
            }
        }
        
        return ans;
    }
}
