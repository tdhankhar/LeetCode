struct node{
    int id,lvl,dist;
};
class compare 
{ 
public: 
    int operator() (const node& a, const node& b) 
    { 
        if(a.dist!=b.dist) return a.dist<b.dist;
        else if(a.lvl!=b.lvl) return a.lvl<b.lvl;
        return a.id<b.id;
    } 
}; 
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        priority_queue<node,vector<node>,compare> pq;
        int distance[n];
        for(int i=0;i<n;i++){
            distance[i] =INT_MAX;
        }
        distance[src] = 0;
        node curr;
        curr.id = src;
        curr.lvl = 0;
        curr.dist = 0;
        pq.push(curr);
        while(!pq.empty()){
            curr = pq.top();
            pq.pop();
            int u = curr.id;
            int l = curr.lvl;
            for(auto i = adj[u].begin();i!=adj[u].end();i++){
                int v = i->first;
                int wt = i->second;
                if(distance[v] > curr.dist+wt && l<=K){
                    cout<<l<<" ";
                    distance[v] = curr.dist+wt;
                    node temp;
                    temp.id = v;
                    temp.lvl = l+1;
                    temp.dist = distance[v];
                    pq.push(temp);
                }
            }
        }
        if(distance[dst]==INT_MAX) return -1;
        return distance[dst];
    }
};