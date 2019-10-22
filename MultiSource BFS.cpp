struct cell{
    int x,y;
};
bool isSafe(int i,int j,int n){
    return (i>=0 && i<n && j>=0 && j<n);
}
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int res[n][n];
        queue<cell> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    cell temp;
                    temp.x = i;
                    temp.y = j;
                    q.push(temp);
                    res[i][j] = 0;
                }
                else res[i][j]=INT_MAX;
            }
        }
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        int ans=-1;
        while(!q.empty()){
            cell curr = q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int r=curr.x+dx[k];
                int c=curr.y+dy[k];
                if(isSafe(r,c,n) && res[r][c]>res[curr.x][curr.y]+1){
                    res[r][c]=res[curr.x][curr.y]+1;
                    ans=max(ans,res[r][c]);
                    cell temp;
                    temp.x=r;
                    temp.y=c;
                    q.push(temp);
                }
            }
        }
        return ans;
    }
};