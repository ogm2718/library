template <typename T, typename U>
void dijkstra(const vector<vector<pair<T, U>>> &G, const int &n, vector<U> &dist, const T &start) {
    priority_queue<pair<U, T>, vector<pair<U, T>>, greater<pair<U, T>>> pq;
    dist[start] = 0;
    vector<bool> used(n + 1, 0);
    pq.push({0, start});
    while(!pq.empty()) {
        U d = pq.top().first;
        T v = pq.top().second;
        pq.pop();
        if(used[v]) continue;
        used[v] = 1;
        if(dist[v] < d) {
            continue;
        }
        for(auto &e : G[v]) {
            T to = e.first;
            U cost = e.second;
            if(dist[v] + e.second < dist[to]) {
                dist[to] = dist[v] + cost;
                pq.push({dist[to], to});
            }
        }
    }
}
