/*
	Scrivere un algoritmo che prenda in input un grafo orientato G=(V,E) e due nodi s1,s2 e che restituisca il numero di nodi tali che:
		- siano raggiungibili sia da s1 che da s2, e
		- si trovino alla stessa distanza da s1 e da s2.
*/

#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int same_distance(const vector<vector<short> > &adj_list, const short &src_node_1, const short &src_node_2);
void bfs(const vector<vector<short> > &adj_list, const short &src_node_1);

int main() {
	int node_count;
	int arch_count;
	short src_node_1;
	short src_node_2;
	ifstream in ("input.txt");
	ofstream out ("output.txt");

	in >> node_count >> arch_count >> src_node_1 >> src_node_2;

	vector<vector<short> > adj_list (node_count);

	for (int i = 0; i < arch_count; i++) {
		int temp_source;
		int temp_dest;

		in >> temp_source >> temp_dest;
		adj_list[temp_source].push_back(temp_dest);
	}

	same_distance(adj_list, src_node_1, src_node_2);

	in.close();
	out.close();
	return 0;
}

int same_distance(const vector<vector<short> > &adj_list, const short &src_node_1, const short &src_node_2) {
	int node_count = 0;

	bfs(adj_list, src_node_1);

	// ora per risolvere l'esercizio, ritorna da bfs il distance vector.
	// fai bfs anche con il secondo nodo come src.
	// confronta le distanze nodo per nodo. Se la distanza è uguale vuol dire che il nodo è raggiungibile e ha la stessa distanza.

	return node_count;
}

void bfs(const vector<vector<short> > &adj_list, const short &src_node) {
	const int INF = 100000;
	vector<bool> visited_nodes (adj_list.size(), false);
	queue<short> local_queue;
	vector<int> distance_vector (adj_list.size(), INF);

	visited_nodes[src_node] = true;
	local_queue.push(src_node);
	distance_vector[src_node] = 0;

	while (!local_queue.empty()) {
		short curr_node = local_queue.front();
		local_queue.pop();


		cout << "curr node: " << curr_node << endl;

		for (auto node: adj_list[curr_node]) {
			if (!visited_nodes[node]) {
				visited_nodes[node] = true;
				local_queue.push(node);
				distance_vector[node] = distance_vector[curr_node] + 1;
			}
		}
	}

	for (auto item: distance_vector) {
		cout << item << " ";
	}

	cout << endl;\
}
