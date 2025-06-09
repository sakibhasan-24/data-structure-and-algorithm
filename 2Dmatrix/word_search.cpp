#include<iostream>
#include<vector>
#include<stack>


struct State
{
    int row;
    int col;
    int idx;
    vector<vector<bool>>visited;
};

using namespace std;

  bool exist(vector<vector<char>>& board, string word) {

    int row=board.size();
    int col=board[0].size();
    vector<vector<bool>>visited(row,vector<bool>(col,false));
    stack<State>st;
    int rowDirections[]={-1,1,0,0};
    int colDirections[]={0,0,-1,1};
    int wordSize=word.size();
    for(int r=0;r<row;r++){
        for(int c=0;c<col;c++){
            if(board[r][c]==word[0]){
                visited[r][c]=true;
                st.push({r,c,0,visited});
            }

            while(!st.empty()){
                int currRow=st.top().row;
                int currCol=st.top().col;
                int currIdx=st.top().idx;
                auto vis=st.top().visited;
                st.pop();
                if(idx==wordSize-1){
                    return true;

                }
                for(int x=0;x<4;x++){
                    int newRow=currRow+rowDirections[x];
                    int newCol=currCol+colDirections[x];
                    if(newRow>=0 && newRow<row && newCol>=0 && newCol<col){
                        if(!visited[newRow][newCol] && board[newRow][newCol]==word[idx+1]){
                            visited[newRow][newCol]=true;
                            st,push({newRow,newCol,idx+1,visited});

                        }
                    }
                }
            }
        }
    }

    return false;

    

    }
int main()


{

}