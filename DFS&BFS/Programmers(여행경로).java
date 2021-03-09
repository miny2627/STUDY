import java.util.*;

class Solution {
    boolean[] visited;
    ArrayList<String> ans;
    
    public String[] solution(String[][] tickets) {
        visited = new boolean[tickets.length];
        ans = new ArrayList<String>();
        
        dfs(tickets, "ICN", "ICN", 0);
        System.out.println(ans);
        Collections.sort(ans); // alphabet sorting
        String[] answer = ans.get(0).split(" ");
            
        return answer;
    }
    void dfs(String[][] tickets, String dep, String arr, int cnt) {
        if(cnt == tickets.length) {
            ans.add(arr);
            return;
        }
        
        for(int i = 0; i < tickets.length; i++) {
            if(!visited[i] && tickets[i][0].equals(dep)) {
                visited[i] = true;
                dfs(tickets, tickets[i][1], arr + " " + tickets[i][1], cnt+1);
                visited[i] = false;
            }
        }
        
    } 
}
