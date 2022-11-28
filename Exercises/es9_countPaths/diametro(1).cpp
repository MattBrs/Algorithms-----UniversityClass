#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
void visit_node(const short &original_node, short current_node, const short &target_node, const vector<pair<short, short>> &arches_list, int &visit_count, vector<bool> visitArray, int local_count);
void print_matrix(vector<vector<int>> matrix);


int main (int argc, char *argv[]) {
  short node_count;
  int arch_count;
  vector<pair<short, short>> arch_list;

  ifstream in ("input.txt");
  ofstream out ("output.txt");

  in >> node_count >> arch_count;
  for (size_t i = 0; i < arch_count; i++) {
    short input1;
    short input2;

    in >> input1 >> input2;
    arch_list.push_back({input1, input2});
  }

  // vector<vector<int>> distance_matrix (node_count, vector<int>(node_count));
  vector<bool> visit_array (node_count);
  int max_distance = 0;

  for (size_t i = 0; i < node_count; i++) {
    for (size_t j = i; j < node_count; j++) {
      int visit_count = 100000;
      visit_node(0, i, j, arch_list, visit_count, visit_array, 0);
      // distance_matrix[i][j] = visit_count;
      max_distance = max(visit_count, max_distance);
    }
  }

  // print_matrix(distance_matrix); 
  out << max_distance << endl;
  in.close();
  out.close();
  return 0;
}


void visit_node(const short &original_node, short current_node, const short &target_node, const vector<pair<short, short>> &arches_list, int &visit_count, vector<bool> visit_array, int local_count) {
  if (visit_array[current_node]) {
    return;
  }
  // cout << "current node -> " << current_node << endl;
  
  if (current_node == target_node) {
    // cout << "target reached  " << local_count << endl;
    visit_count = min(local_count, visit_count); 
    return;
  }

  visit_array[current_node] = true;
  local_count++;

  for(auto item: arches_list) {
    if (item.first == current_node) {
      visit_node(original_node, item.second, target_node, arches_list, visit_count, visit_array, local_count);
    } else if (item.second == current_node) {
      visit_node(original_node, item.first, target_node, arches_list, visit_count, visit_array, local_count);
    }
  }
}

void print_matrix(vector<vector<int>> matrix) {
  for(auto x: matrix) {
    for(auto y: x) {
      cout << y << " ";
    }
    cout << endl;
  }
}
