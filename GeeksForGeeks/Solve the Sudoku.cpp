class Solution 
{
    public:
    bool isSafe(int row,int col,int grid[N][N],int val){
        for(int i=0;i<9;i++){
            // check same row
            if(grid[row][i]==val)return false;
            
            // check same column
            if(grid[i][col]==val)return false;
            
            // check small boxes
            if(grid[3*(row/3)+i/3][3*(col/3)+i%3]==val)return false;
        }
        return true;
    }
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        for(int row=0;row<N;row++){
            for(int col=0;col<N;col++){
                if(grid[row][col]==0){
                    for(int tryy=1;tryy<=9;tryy++){
                        if(isSafe(row,col,grid,tryy)){
                            grid[row][col]=tryy;
                            bool aageSolutionPossible=SolveSudoku(grid);
                            if(aageSolutionPossible)
                                return true;
                            else 
                                grid[row][col]=0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<grid[i][j]<<" ";
            }
        }
    }
};