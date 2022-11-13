#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

vector<pair<ll, ll>> maximum_period(const vector<pair<ll, ll>> &vect);

int main() {
    ifstream in ("input.txt");
    ofstream  out ("output.txt");
    ll size;
    vector<pair<ll, ll>> interval_list;

    in >> size;
    for (int i = 0; i < size; ++i) {
        ll val_1;
        ll val_2;

        in >> val_1 >> val_2;

        interval_list.push_back({val_1, val_2});
    }

    sort(interval_list.begin(), interval_list.end());
    vector<pair<ll, ll>> res = maximum_period(interval_list);
    if (res.size() > 0) {
        out << res[0].first << " " << res[0].second;
    } else {
        out << 0;
    }

    out << endl;
    in.close();
    out.close();
    return 0;
}

vector<pair<ll, ll>> maximum_period(const vector<pair<ll, ll>> &vect) {
    vector<pair<ll, ll>> periods;
    ll max_so_far = -1;
    ll max_interval_top = -1;

    if (vect.size() > 0) {
        max_interval_top = vect[0].first;
    }

    for (ll i = 0; i < vect.size()-1; ++i) {
        if (vect[i].second > max_interval_top) {
            max_interval_top = vect[i].second;
        }

        if (vect[i+1].first > max_interval_top) {
            periods.push_back({max_interval_top, vect[i+1].first});
        }

        if (vect[i].second < vect[i+1].first && vect[i].second >= max_interval_top) {

            ll local_sum = vect[i+1].first-1 - vect[i].second;
            if(local_sum > max_so_far) {
                periods.clear();
                max_so_far = local_sum;
            }

            periods.push_back({vect[i].second, vect[i+1].first});
        }
    }

    sort(periods.begin(), periods.end());

    return periods;
}
