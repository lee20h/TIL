class Solution {
    static int[] px = {0,0,1,-1};
    static int[] py = {1,-1,0,0};
    static boolean[][] pa;
    static boolean[][] at;
    static int n, m;
    private void paDfs(int[][] matrix, int y, int x) {
        pa[y][x] = true;
        
        for(int t=0; t<4; t++) {
            int dy = y + py[t];
            int dx = x + px[t];
            
            if(dy < 0 || dx < 0 || dy >= n || dx >= m)
                continue;
            if(pa[dy][dx])
                continue;
            if(matrix[dy][dx] >= matrix[y][x])
                paDfs(matrix, dy, dx);
        }
    }
    private void atDfs(int[][] matrix, int y, int x) {
        at[y][x] = true;
        
        for(int t=0; t<4; t++) {
            int dy = y + py[t];
            int dx = x + px[t];
            
            if(dy < 0 || dx < 0 || dy >= n || dx >= m)
                continue;
            if(at[dy][dx])
                continue;
            if(matrix[dy][dx] >= matrix[y][x])
                atDfs(matrix, dy, dx);
        }
    }
    
    public List<List<Integer>> pacificAtlantic(int[][] matrix) {
        List<List<Integer>> res = new ArrayList<>();
        if(matrix.length == 0 || matrix[0].length == 0)
            return res;
        n = matrix.length;
        m = matrix[0].length;
        
        pa = new boolean[n][m];
        at = new boolean[n][m];
        
        for(int i=0; i<n; i++) {
            pa[i][0] = true;
            at[i][m-1] = true;
        }
        for(int i=0; i<m; i++) {
            pa[0][i] = true;
            at[n-1][i] = true;
        }
        
        for(int i=0; i<n; i++) {
            paDfs(matrix, i, 0);
            atDfs(matrix, i, m-1);
        }
        for(int i=0; i<m; i++) {
            paDfs(matrix, 0, i);
            atDfs(matrix, n-1, i);
        }
        
        
        for(int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if(pa[i][j] && at[i][j]) {
                    List<Integer> pos = new ArrayList<>();
                    pos.add(i);
                    pos.add(j);
                    res.add(pos);
                }
            }
        }
        
        return res;
        
    }
}