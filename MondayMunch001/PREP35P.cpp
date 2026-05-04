void dfs(vector<string> &matrix, int m, int n, int i, int j) {
    if(i<0 || j<0 || i==m || j==n || matrix[i][j] != 'O') {
        return;
    }
    matrix[i][j] = 'S';
    dfs(matrix, m,n,i+1,j);
    dfs(matrix, m,n,i-1,j);
    dfs(matrix, m,n,i,j+1);
    dfs(matrix, m,n,i,j-1);
}
void solveTerritories(vector<string> &matrix, int N) {
    // write your code here 
    for(int i=0;i<N;i++) {
        dfs(matrix, N, N, i, N-1);
        dfs(matrix, N, N, i, 0);
        dfs(matrix, N, N, N-1, i);
        dfs(matrix, N, N, 0, i);
    }
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(matrix[i][j] == 'S') matrix[i][j] = 'O';
            else matrix[i][j] = 'X';
        }
    }
}