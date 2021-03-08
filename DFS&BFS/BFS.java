package study;
import java.util.*;

public class BFS {
	public int solution(int n, int [][] edge) {
		int ans = 0;
		
		// graph
        ArrayList<ArrayList<Integer>> list = new ArrayList<ArrayList<Integer>>();
        for(int i = 0; i < edge.length; i++) {
            list.add(new ArrayList<Integer>());
        }
        // node
        int u, v;
        for(int[] node:edge) {
            u = node[0];
            v = node[1];
            list.get(u).add(v);
            list.get(v).add(u);
        }
        
        int[] count = new int[n + 1];
        boolean[] visited = new boolean[n+1];
        
        // bfs
        Queue<Integer> q = new LinkedList<>();
        q.add(1);
        visited[1] = true;
        
        while(!q.isEmpty()) {
            int curr = q.poll();
            for(int i:list.get(curr)) {
                if(!visited[i]) {
                    count[i] = count[curr] + 1;
                    visited[i] = true;
                    q.add(i);
                }
            }
        }
        
        int max = 0;
        for(int i: count) {
            if(max < i) {
                max = i;
                ans = 1;
            }
            else if(max == i) ans++;
        }
		
		return ans;
	}
}
