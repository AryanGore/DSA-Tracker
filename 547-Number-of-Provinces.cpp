//problem statement :

// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
// A province is a group of directly or indirectly connected cities and no other cities outside of the group.
// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
// Return the total number of provinces.

// Example 1:
// Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
// Output: 2

// Example 2:
// Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
// Output: 3
 

// Constraints:

// 1 <= n <= 200
// n == isConnected.length
// n == isConnected[i].length
// isConnected[i][j] is 1 or 0.
// isConnected[i][i] == 1
// isConnected[i][j] == isConnected[j][i]

// code solution:

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = 0;
        vector<bool>visited(isConnected.size(),false);
        for(int i = 0 ; i<isConnected.size() ; ++i){
                if(!visited[i]){
                    dfs(isConnected,i,visited);
                    provinces++;
                }
        }
        return provinces;
    }

    void dfs(vector<vector<int>>& isConnected,int i,vector<bool>&visited){
        visited[i] = true;
        for(int neighbor = 0 ; neighbor<isConnected.size() ; ++neighbor){
            if(isConnected[i][neighbor] == 1 && !visited[neighbor]){
                dfs(isConnected,neighbor,visited);
            }
        }
    }
};


//we are basically using recursion dfs to see what is connectivity of graph thats forming in dpth , basically we iterate over all the nodes from
//0th position to nth position , initially all are unvisited , now we call dfs for every node checking if its already marked visited or not, if yeas we call our dfs method , inside dfs,
//method we mark the current index as visited and run a for loop again for all nodes present , and we keep checking if theres conectivity , if there is we call dfs again, this happens
//recursively , once all nodes are visited we backtrack until we reach the first dfs call for this index , and increment the provinces .
