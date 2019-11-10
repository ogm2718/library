void dijkstra(vector<vector<pair<ll,ll>>> &G, ll n, vector<ll> &dist, ll start) {
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    dist[start] = 0;
    vector<ll> used(n+1,0);
    pq.push({0, start});
    while(!pq.empty()) {
        ll d = pq.top().first, v = pq.top().second;
        pq.pop();
        if(used[v])continue;
        used[v] = 1;
        if(dist[v]<d){
            continue;
        }
        for(pi e : G[v]) {
            ll to = e.first, cost = e.second;
            if(dist[v] + e.second < dist[to]) {
                dist[to] = dist[v] + cost;
                pq.push({dist[to], to});
            }
        }
    }
}
