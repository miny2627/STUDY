#include <string>
#include <queue>
#include <vector>

using namespace std;

int bfs(string begin, string target, vector<string> words) {
    int len = words.size();
    bool* check = new bool[len + 1];
	fill(check, check + len + 1, false);
    
    queue<pair<string, int>> q;
    q.push(make_pair(begin, 0));   
    
    while(!q.empty()) {
        string curr = q.front().first;
        int cost = q.front().second;
        q.pop();
        
        if(curr.compare(target) == 0) return cost;
        
        for(int i = 0; i < words.size(); i++) {
            if(check[i]) continue;
            int cnt = 0;
            
            for(int j = 0; j < curr.size(); j++) {
                if(curr[j] != words[i][j]) cnt++;
            }
            
            if(cnt == 1) {
                check[i] = true;
                q.push(make_pair(words[i], cost + 1));
            }
        }
    }
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    return bfs(begin, target, words);
}
