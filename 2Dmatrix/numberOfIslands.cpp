int numIslands(vector<vector<char>>& grid) {
    int row=grid.size();
    int col=grid[0].size();

     vector<vector<bool>> visited(row, vector<bool>(col, false));
     queue<pair<int,int>>q;

     int rowDirections[]={-1,1,0,0};
     int colDirections[]={0,0,1,-1};
     int count=0;
     for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(!visited[i][j] && grid[i][j]=='1'){
                count++;
                visited[i][j]=true;
                q.push({i,j});
                
            }

            while(!q.empty()){
                auto[r,c]=q.front();
                q.pop();
                int newRow=r+rowDirections[i];
                int newCol=c+colDirections[i];
                for(int x=0;x<4;x++){
                    int newRow=r+rowDirections[x];
                int newCol=c+colDirections[x];
                if(newRow<row && newRow>=0 && newCol<col && newCol>=0){
                    if(!visited[newRow][newCol] && grid[newRow][newCol]=='1'){
                        visited[newRow][newCol]=true;
                        q.push({newRow,newCol});
                    }
                }
                }
            }
        }
     }

     return count;
}

