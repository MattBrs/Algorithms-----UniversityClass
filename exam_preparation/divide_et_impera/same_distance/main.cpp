#include <algorithm>
#include <iostream>
#include <fstream>
#include <iterator>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

const int INF = 100000;

int same_distance(const vector<vector<short> > &adj_list, const short &src_node_1, const short &src_node_2);
vector<int> bfs(const vector<vector<short> > &adj_list, const short &src_node_1);
bool isConnected(const vector<vector<short> > &adj_list);
void dfs(const vector<vector<short> > &adj_list, const short &curr_node, int count, vector<int> &id);

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

	cout << "node 1: " << src_node_1 << endl;
	cout << "node 2: " << src_node_2 << endl;

	cout << "The two nodes have " << 
		same_distance(adj_list, src_node_1, src_node_2) << 
		" nodes reachable with the same distance" 
	<< endl;

	cout << "The graph is " << (isConnected(adj_list) ? "connected" : "not connected") << endl;

	in.close();
	out.close();
	return 0;
}

int same_distance(const vector<vector<short> > &adj_list, const short &src_node_1, const short &src_node_2) {
	int node_count = 0;

	vector<int> node_1_d_v = bfs(adj_list, src_node_1);
	vector<int> node_2_d_v = bfs(adj_list, src_node_2);


	for (int i = 0; i < adj_list.size(); i++) {
		if (node_1_d_v[i] == node_2_d_v[i] && node_1_d_v[i] != INF) {
			++node_count;
		}
	}

	return node_count;
}

vector<int> bfs(const vector<vector<short> > &adj_list, const short &src_node) {
	vector<bool> visited_nodes (adj_list.size(), false);
	queue<short> local_queue;
	vector<int> distance_vector (adj_list.size(), INF);

	visited_nodes[src_node] = true;
	local_queue.push(src_node);
	distance_vector[src_node] = 0;

	while (!local_queue.empty()) {
		short curr_node = local_queue.front();
		local_queue.pop();

		for (auto node: adj_list[curr_node]) {
			if (!visited_nodes[node]) {
				visited_nodes[node] = true;
				local_queue.push(node);
				distance_vector[node] = distance_vector[curr_node] + 1;
			}
		}
	}

	return distance_vector;
}

bool isConnected(const vector<vector<short> > &adj_list) {
	// questa funzione trova solamente se le componenti sono connesse
	// per risolvere il problema dato dal prof (dato un array di interi che specifica le capacità di ogni nodo, trova la capacità totale)
	// basterebbe, dopo aver eseguito il calcolo degli id delle componenti connesse, creare un vettore con le capacità delle componenti connesse
	// e sommare ad ogni posizione i (con i l'id della componente connessa) la capacità dei singoli nodi appartenenti alla componente.
	// si ritorna il massimo perchè viene chiesto la massima capacità.

	vector<int> id (adj_list.size(), 0);
	int count = 0;

	for (int i = 0; i < adj_list.size(); i++) {
		if (id[i] == 0) {
			count++;
			dfs(adj_list, i, count, id);
		}
	}


	int connected_components_number = *max_element(begin(id), end(id));
	vector<int> connection_count (connected_components_number, 0);

	for (auto item: id) {
		connection_count[item-1]++;
	}


	int min_connection_count = *min_element(begin(connection_count), end(connection_count));
	if (min_connection_count <= 1) {
		return false;
	}

	return true;
}

void dfs(const vector<vector<short> > &adj_list, const short &curr_node, int count, vector<int> &id) {
	id[curr_node] = count;

	for (auto node: adj_list[curr_node]) {
		if (id[node] == 0) {
			dfs(adj_list, node, count, id);
		}
	}
}