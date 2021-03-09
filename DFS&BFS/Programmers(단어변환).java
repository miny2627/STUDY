import java.util.*;

class Solution {
    static class Node {
        String curr;
        int cost;
        
        public Node(String curr, int cost) {
            this.curr = curr;
            this.cost = cost;
        }
    }
    
    public int solution(String begin, String target, String[] words) {
        return bfs(begin, target, words);
    }
    
    int bfs(String begin, String target, String[] words) {
        boolean[] visited = new boolean[words.length];
        Queue<Node> q = new LinkedList<>();
        q.add(new Node(begin, 0));
        
        while(!q.isEmpty()) {
            Node tmp = q.poll();
            System.out.println(tmp.cost);
            if(tmp.curr.equals(target)) {
                return tmp.cost;
            }
            
            for(int i = 0; i < words.length; i++) {
                if(!visited[i] && check(tmp.curr, words[i])) {
                    visited[i] = true;
                    q.add(new Node(words[i], tmp.cost + 1));
                }
            }
        }
        return 0;
    }
    
    boolean check(String prev, String next) {
        int cnt = 0;
        for(int i = 0; i < prev.length(); i++) {
            if(prev.charAt(i) != next.charAt(i)) cnt++;
        }
        return cnt == 1 ? true : false;
    }
}
