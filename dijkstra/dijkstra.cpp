struct edge { int to, cost};
typedef pair<int , int> pi;
typedef vector<edge> Graph;
vector<int> dist;
int start,goal;
Graph g[MAX_V];

void dijkstra(){
  priority_queue<pi,vector<pi>,greater<pi> > pq;
  fill(dist, dist+v,INF);
  dist[start]=0;
  pq.push(pi(0,start));

  while(!que.empty()){
    int d = pq.top().first, v = pq.top().second;
    pq.pop();

    if(v == goal)break;
    if(dist[v] < d)continue;

    for(int i=0; i < (int)g[v].size(); ++i){
      edge e = g[v][i];

      if(d + e.cost < dist[e.to]){
        dist[e.to] = d + e.cost;
        pq.push(pi(dist[e.to],e.to));
      }
    }
  }
}
