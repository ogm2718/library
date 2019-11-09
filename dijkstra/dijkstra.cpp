vector<ll> dist;
int start,goal;

void dijkstra(){
  priority_queue<pi,vector<pi>,greater<pi> > pq;
  dist.resize(n+1,INF);
  dist[start]=0;
  pq.push(pi(0,start));
  while(!que.empty()){
    int d = pq.top().first, v = pq.top().second;
    pq.pop();
    if(dist[v] < d)continue;

    for(auto e:G[v]){
      ll to = e.first,cost = e.second;
      if(d + e.first < dist[e.to]){
        dist[to] = d + cost;
        pq.push(pi(dist[to],to));
      }
    }
  }
}
