#include <vector>
#include <iostream>
#include <utility>
#include <queue>
using namespace std;

bool is_valid(int x, int y, int m, int n){
    if(x<0 || x>=m || y<0 || y>=n)
        return false;
    return true;
}

void print_path(vector<int> path){
    for(unsigned int i=0; i<path.size(); i++)
        cout<<path[i]<<"\t";
    cout<<endl;    
}

void bfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, pair<int,int> &source, pair<int,int> dest, vector<int> &path) {
    queue<pair<int,int>> q;
    vector<pair<int,int>> traverse = {{0,1}, {-1,0}, {0,-1}, {1,0}};
    
    q.push(make_pair(source.first, source.second));
    visited[source.first][source.second] = true;
    
    while(!q.empty()) {
        path.push_back(grid[q.front().first][q.front().second]);
        
        //cout << grid[q.front().first][q.front().second] << " ";
        source = make_pair(q.front().first, q.front().second);
        //cout<<source.first<<" "<<source.second<<"\t";
        if(source == dest) {
            print_path(path);
            return;
        }
        q.pop();
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0; i<4; i++) {
            int newx = traverse[i].first + source.first;
            int newy = traverse[i].second + source.second;
            
            if(is_valid(newx, newy, m, n) && !visited[newx][newy]) {
                pair<int,int> newxy = make_pair(newx,newy);
                q.push(newxy); 
                visited[newx][newy] = true;
            }
        }        
    }
}

int main() {
    int xs,ys,xd,yd;

    vector<vector<int>> grid =  {{1,2,3,4},
                                 {5,6,7,8},
                                 {9,10,11,12},
                                 {13,14,15,16}};
                             
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
     
    pair<int, int> source;
    pair<int, int> dest;
    
    cout << "Enter source" << endl;
    cin >> xs >> ys;
    
    cout << "Enter destination" << endl;
    cin >> xd >> yd;
    
    source = make_pair(xs,ys);
    dest = make_pair(xd,yd);
    
    vector<int> path;
     
    bfs(grid,visited,source,dest,path);                     
}
