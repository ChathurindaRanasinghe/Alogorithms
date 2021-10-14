int no_edges;
int no_nodes;

struct Edge {
    int u, v, weight;
    bool operator < (Edge const& other) {
        return weight < other.weight;
    }
    friend istream& operator >> (istream& is, Edge& e) {
        is >> e.u >> e.v >> e.weight;
        return is;
    }
};



void kruskals() {


    int cost = 0;
    vector<Edge> result;

    cin >> no_nodes;
    cin >> no_edges;

    vector<int> tree_id;
    vector<Edge> edges;

    edges.reserve(no_edges);
    tree_id.reserve(no_nodes + 1);

    for (int i = 0; i < no_edges; i++) {
        Edge e; cin >> e;
        edges.emplace_back(e);
    }


    tree_id.emplace_back(0);
    for (int i = 0; i < no_nodes; i++) {
        tree_id.emplace_back(i + 1);
    }

    sort(edges.begin(), edges.end());

    for (Edge& e : edges) {
        if (tree_id[e.u] != tree_id[e.v]) {
            cost += e.weight;
            result.push_back(e);

            int old_id = tree_id[e.u], new_id = tree_id[e.v];
            for (int i = 1; i <= no_nodes; i++) {
                if (tree_id[i] == old_id)
                    tree_id[i] = new_id;
            }
        }
    }

    cout << cost << "\n";

}
