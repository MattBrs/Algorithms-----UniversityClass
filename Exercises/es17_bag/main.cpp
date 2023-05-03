#include <fstream>
#include <iostream>
#include <utility>

using namespace std;

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");

  int bag_size;
  int item_count;
  vector<pair<int, int>> item_list;

  in >> bag_size >> item_count;

  for (int i = 0; i < bag_size; ++i) {
    int item_weigth;
    int item_value;
  }

  in.close();
  out.close();
  return 0;
}
