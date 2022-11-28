#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void visit_node(
  short current_node, 
  const short &target_node, 
  const vector<vector<short>> &arches_list, 
  int &visit_count, 
  vector<bool> visitArray, 
  int local_count,
  int &path_count
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
  int path_count = 0;
  int visit_count = 100000;
  visit_node(starting_node, target_node, adj_list, visit_count, visit_array, 0, path_count);
  // cout << visit_count << " " << path_count << endl;
  out << visit_count << " " << path_count << endl;
  in.close();
  out.close();
  return 0;
}

void visit_node(
  short current_node, 
  const short &target_node, 
  const vector<vector<short>> &adj_list, 
  int &visit_count, 
  vector<bool> visit_array, 
  int local_count,
  int &path_count
) {

  if (visit_array[current_node]) {
    return;
  }
  
  if (current_node == target_node) {
    if (local_count == visit_count) {
      path_count++;
      return;
    }

    if (local_count < visit_count) {
      visit_count = local_count;
      path_count = 1;
      return;
    }

    return;
  }

  visit_array[current_node] = true;
  local_count++;

  for(auto item: adj_list[current_node]) {
      visit_node(item, target_node, adj_list, visit_count, visit_array, local_count, path_count);
    }
  }
