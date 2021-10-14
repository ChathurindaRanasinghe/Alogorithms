constexpr auto INF = 1000000000;

using namespace std;

unordered_map<int, vector<pair<int, int>>> adj;
int n;


vector<int> dijkstras(int x) {
    vector<int> distance(n + 1, INF);
    vector<bool> processed(n + 1, 0);
    distance[x] = 0;
    priority_queue<pair<int, int>> q;
    q.push({ 0,x });

    while (!q.empty()) {
        int a = q.top().second; q.pop();
        if (processed[a]) continue;
        processed[a] = 1;
        for (auto const& u : adj[a]) {
            int b = u.first, w = u.second;
            if (distance[a] + w < distance[b]) {
                distance[b] = distance[a] + w ;

                q.push({ -distance[b],b });
            }
        }
    }

    return distance;

}
