#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

vector<short> get_visitable_nodes(const vector<pair<short, short>> &adj_list, short current_node);
short bfs(const short &node_count, const vector<vector<short>> &adj_list); 

void print_list(const vector<pair<short, short>> &list) {
  for (auto item: list) {
    cout << item.first << "-" << item.second << "  ";
  }

  cout << endl;
}

int main (int argc, char *argv[]) {
  short node_count;
  int arch_count;

  ifstream in ("input.txt");
  ofstream out ("output.txt");

  in >> node_count >> arch_count;
  vector<vector<short>> adj_list(node_count);
  for (size_t i = 0; i < arch_count; i++) {
    short input1;
    short input2;

    in >> input1 >> input2;
    adj_list[input1].push_back(input2);
    adj_list[input2].push_back(input1);
  }

  short max_distance = bfs(node_count, adj_list);
  out << max_distance << endl; 
  in.close();
  out.close();
  return 0;
}

short bfs(const short &node_count, const vector<vector<short>> &adj_list) {
  short max_depth = 0;

  for (short i = 0; i < node_count; i++) {
    vector<pair<short, short>> traversed_nodes;  
    vector<bool> visited(node_count, false);
    if (!visited[i]) {
      queue<pair<short, short>> node_queue;
      visited[i] = true;
      node_queue.push({i , 0});

      while (!node_queue.empty()) {
        pair<short, short> current_node = node_queue.front();
        node_queue.pop();
        traversed_nodes.push_back(current_node);
        int curr_depth = current_node.second;
        curr_depth++;
        for (auto node: adj_list[current_node.first]) {
          if (!visited[node]) {
            visited[node] = true;
            node_queue.push({node, curr_depth});
          }
        }
      }
      max_depth = max(max_depth, traversed_nodes.back().second);
    }
  }
  
  return max_depth;
}

vector<short> get_visitable_nodes(const vector<pair<short, short>> &adj_list, short current_node) {
  vector<short> visitable_nodes;
   
  for (auto arch: adj_list) {
    if (arch.first == current_node) {
      visitable_nodes.push_back(arch.second);
    } else if (arch.second == current_node) {
      visitable_nodes.push_back(arch.first);
    }
  } 

  return visitable_nodes;
}
