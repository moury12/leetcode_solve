#include <iostream>
#include <vector>
#include <string>
using namespace std;
void helper(vector<vector<int>>& maze,vector<string>& ans,int row, int col,string path){
    int n = maze.size();
    if(row<0 ||col<0|| row>=n|| col>=n|| maze[row][col]==0){
        return;
    }
    if(row==n-1 && col==n-1){
        ans.push_back(path);
        return;
    }
    maze[row][col]=0;
//down
helper(maze, ans, row+1, col,path+"D");
//left
helper(maze, ans, row, col-1,path+"L");
//right
helper(maze, ans, row, col+1,path+"R");
//up
helper(maze, ans, row-1, col,path+"U");
 maze[row][col]=1;
}
vector<string> ratInMaze(vector<vector<int>>& maze) {
      vector<string> ans;
      string path ="";
helper(maze, ans,0,0,path);
return ans;
        
    }
int main(){
    vector<vector<int>> maze = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<string> ans = ratInMaze(maze);
    for(auto i : ans){
        cout<<i<<endl;
    }
}