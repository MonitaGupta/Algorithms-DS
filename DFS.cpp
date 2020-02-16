/**
Depth Search First : Print all paths from source to destination
**/

#include <vector>
#include <iostream>
#include <utility>
#include <stack>
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


void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, pair<int,int> source, pair<int,int> dest, vector<int> &path) {
    vector<pair<int,int>> traverse = {{0,1}, {-1,0}, {0,-1}, {1,0}};
    path.push_back(grid[source.first][source.second]);
    
    if(source == dest){
        print_path(path);
        path.pop_back();
        return;
    }

    visited[source.first][source.second] = true;
    
    int m = grid.size();
    int n = grid[0].size();
    
    for(int i=0; i<4; i++) {
        int newx = traverse[i].first + source.first;
        int newy = traverse[i].second + source.second;
            
        if(is_valid(newx, newy, m, n) && !visited[newx][newy]) {
            pair<int,int> value = make_pair(newx,newy);
            dfs(grid, visited, value, dest, path);
        }
        else
            continue;
       
    }
    visited[source.first][source.second] = false;
    path.pop_back();
}

int main() {
    int xs,ys,xd,yd;
    vector<vector<int>> grid =  {{1,2,3,4},
                                 {5,6,7,8},
                                 {9,10,11,12},
                                 {13,14,15,16}};
                              
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    vector<int> path;
     
    pair<int, int> source;
    pair<int, int> dest;
    
    cout << "Enter source" << endl;
    cin >> xs >> ys;
    
    cout << "Enter destination" << endl;
    cin >> xd >> yd;
    
    source = make_pair(xs,ys);
    dest = make_pair(xd,yd);
     
    dfs(grid,visited,source,dest,path);                     
}
