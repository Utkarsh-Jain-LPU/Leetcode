class Solution {
public:
    void collect(vector<vector<int>>& adj, vector<bool>& visited, vector<vector<char>>& col) {
        for (int i=0; i<26; i++) {
            if (!visited[i] && adj[i][i] == 1) {
                queue<int> q;
                q.push(i);
                vector<char> v;
                while (!q.empty()) {
                    int x = q.front();
                    q.pop();
                    visited[x] = true;
                    v.push_back((char)(x+'a'));
                    for (int j=0; j<26; j++) {
                        if (!visited[j] && adj[x][j] == 1) q.push(j);
                    }
                }
                col.push_back(v);
            }
        }
    }
    void mapString(vector<vector<char>>& col, map<char, char>& mp) {
        for (int i=0; i<col.size(); i++) {
            for (int j=0; j<col[i].size(); j++) {
                mp[col[i][j]] = col[i][0];
            }
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
        int m = baseStr.length();
        vector<vector<int>> adj(26, vector<int>(26, 0));
        for (int i=0; i<n; i++) {
            int a = s1[i]-'a', b = s2[i]-'a';
            adj[a][a] = 1, adj[b][b] = 1;
            adj[a][b] = 1, adj[b][a] = 1;
        }
        vector<bool> visited(26, false);
        vector<vector<char>> col;
        collect(adj, visited, col);
        map<char, char> mp;
        mapString(col, mp);
        string res = "";
        for (int i=0; i<m; i++) res += mp[baseStr[i]] == NULL ? baseStr[i] : mp[baseStr[i]];
        return res;
    }
};
