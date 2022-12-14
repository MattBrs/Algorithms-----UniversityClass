#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

void visit_node(
  short current_node, 
  const short &target_node, 
  const vector<vector<short>> &adj_list, 
  vector<bool> visit_array, 
  map<string, int> &path_map,
  int local_count
);

int main (int argc, char *argv[]) {
  short node_count;
  int arch_count;
  short starting_node;
  short target_node; 
  
  ifstream in ("input.txt");
  ofstream out ("output.txt");

  in >> node_count >> arch_count >> starting_node >> target_node;
  vector<vector<short>> adj_list(node_count);

  for (size_t i = 0; i < arch_count; i++) {
    short input1;
    short input2;

    in >> input1 >> input2;
    adj_list[input1].push_back(input2);
    adj_list[input2].push_back(input1);
  }


  vector<bool> visit_array (node_count, false);
  map<string, int> distance_map;
  visit_node(starting_node, target_node, adj_list, visit_array, distance_map, 0);

  out << distance_map.begin()->first << " " << distance_map.begin()->second << endl;

  in.close();
  out.close();
  return 0;
}

void visit_node(
  short current_node, 
  const short &target_node, 
  const vector<vector<short>> &adj_list, 
  vector<bool> visit_array, 
  map<string, int> &path_map,
  int local_count
) {
  if (visit_array[current_node]) {
    return;
  }
  
  if (current_node == target_node) {
    path_map[to_string(local_count)]++;
    return;
  }

  if (!path_map.empty() && local_count > stoi(path_map.begin()->first)) {
    return;
  }

  visit_array[current_node] = true;
  local_count++;

  for(auto item: adj_list[current_node]) {
      visit_node(item, target_node, adj_list, visit_array, path_map, local_count);
    }
  }
