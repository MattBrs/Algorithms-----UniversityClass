#include <iostream>
#include <fstream>
#include <ostream>
#include <utility>
#include <vector>

using namespace std;

void print_list(const vector<pair<int, int>> &list);
void visit_node(const int original_node, int current_node, vector<pair<int, int>> arches_list, int &visit_count, vector<bool> &visitArray);
vector<pair<int, int>> filter_pair_list(const vector<pair<int , int>> &list, int filter);

int main (int argc, char *argv[]) {
  int nodes_number;
  int arches_number;
  int starting_node;
  int visit_count = 0;
  vector<pair<int, int>> arch_list;

  ifstream in ("input.txt");
  ofstream out ("output.txt");

  in >> nodes_number >> arches_number >> starting_node;

  for (size_t i = 0; i < arches_number; i++) {
    int first_node;
    int second_node;

    in >> first_node;
    in >> second_node;

    arch_list.push_back({first_node, second_node});
  }
  vector<bool> visit_array (nodes_number);

  visit_node(starting_node, starting_node, arch_list, visit_count, visit_array);
  // print_list(arch_list);
  out << visit_count << endl;
  in.close();
  out.close();
  return 0;
}

void print_list(const vector<pair<int, int>> &list) {
  for(auto item : list) {
    cout << item.first << " " << item.second << endl;
  }
}

void visit_node(const int original_node, int current_node, vector<pair<int, int>> arches_list, int &visit_count, vector<bool> &visit_array) {
  cout << current_node << endl;
  if (visit_array[current_node]) {
    return;
  }

  visit_array[current_node] = true;
  visit_count++;
  vector<pair<int, int>> reachable_nodes = filter_pair_list(arches_list, current_node);
  for(auto item : reachable_nodes) {
    visit_node(original_node, item.second, arches_list, visit_count, visit_array);
  }
}

vector<pair<int, int>> filter_pair_list(const vector<pair<int , int>> &list, int filter) {
  vector<pair<int, int>> to_return;
  for(auto var : list) {
    if (var.first == filter) {
      to_return.push_back(var);
    }
  } 

  return to_return;
  }

