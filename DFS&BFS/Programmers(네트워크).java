class Solution {
    boolean[] visited;
    public int solution(int n, int[][] computers) {
        int ans = 0;
        visited = new boolean[n];
        
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(i, computers);
                ans++;
            }
        }
        
        return ans;
    }
    
    void dfs(int start, int[][] computers) {
        visited[start] = true;
        for(int i = 0; i < computers.length; i++) {
            // start와 i 연결 확인
            if(!visited[i] && computers[start][i] == 1) {
                visited[i] = true;
                dfs(i, computers);
            }
        }
    }
}
