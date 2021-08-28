
#define print_debug true

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

const long long MOD = 1000000007;

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_set;

typedef long long ll;

void fileIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

template <class T>
void debug(const T& n) {
    if (print_debug) cerr << n << "\n\n";
}

template <class T>
void debug(const vector<T>& k) {
    if (print_debug) {
        for (int i = 0; i < k.size(); ++i) {
            cerr << k[i] << " ";
        }
        cerr << "\n\n";
    }
}

template <class T>
void debug(const vector<vector<T>>& k) {
    if (print_debug) {
        for (int i = 0; i < k.size(); ++i) {
            for (int j = 0; j < k[i].size(); ++j) {
                cerr << k[i][j] << " ";
            }
            cerr << "\n";
        }
        cerr << "\n";
    }
}

template <class T>
int bin_upper(const vector<T>& k, const T& value) {
    return distance(k.begin(), upper_bound(k.begin(), k.end(), value));
}

template <class T>
int bin_lower(const vector<T>& k, const T& value) {
    return distance(k.begin(), lower_bound(k.begin(), k.end(), value));
}

class Max_Sparse {
   public:
    ll arr[200005][25];
    int logs[200005];
    Max_Sparse(vector<ll> vect) {
        for (int i = 0; i < 25; ++i) {
            for (int j = 0; j < (int)vect.size(); ++j) {
                if (i == 0) {
                    arr[j][i] = vect[j];
                } else {
                    if (j + (1 << i) <= (int)vect.size()) {
                        cerr << (j + (1 << (i - 1))) << "\n";
                        arr[j][i] =
                            max(arr[j][i - 1], arr[j + (1 << (i - 1))][i - 1]);
                    } else {
                        arr[j][i] = INT_MIN;
                    }
                }
            }
        }

        for (int i = 1; i <= (int)vect.size(); ++i) {
            if (i == 1) {
                logs[i] = 0;
            } else {
                logs[i] = logs[i / 2] + 1;
            }
        }

        for (int i = 0; i < (int)vect.size(); ++i) {
            for (int j = 0; j < 25; ++j) {
                cerr << arr[i][j] << " ";
            }
            cerr << "\n";
        }
    }

    ll query(int l, int r) {
        int len = r - l + 1;

        assert(0 <= r - (1 << logs[len]) + 1);

        // assert(r - (1 << logs[len]) + 1 < (int)vect.size());

        return max(arr[l][logs[len]], arr[r - (1 << logs[len]) + 1][logs[len]]);
    }
};

class Max_Segtree {
   public:
    int round_size;
    vector<ll> segs;
    Max_Segtree(vector<ll> vect) {
        round_size = 1;
        while (round_size < (int)vect.size()) round_size *= 2;
        segs.resize(2 * round_size - 1);
        fill(segs.begin(), segs.end(), INT_MIN);
        for (int i = 0; i < (int)vect.size(); ++i) {
            segs[i + round_size - 1] = vect[i];
        }

        for (int i = round_size - 2; i > -1; --i) {
            segs[i] = max(segs[2 * i + 1], segs[2 * i + 2]);
        }
    }
    void update(int index, ll val) {
        int node = index + round_size - 1;
        segs[node] = val;
        while (node != 0) {
            node = (node - 1) / 2;
            segs[node] = max(segs[2 * node + 1], segs[2 * node + 2]);
        }
    }

    ll query(int l, int r) { return query(l, r, 0, 0, round_size - 1); }

    ll query(int l, int r, int node, int l_node, int r_node) {
        if (l_node > r || l > r_node) return INT_MIN;
        if (l <= l_node && r_node <= r) return segs[node];
        return max(
            query(l, r, 2 * node + 1, l_node, (l_node + r_node) / 2),
            query(l, r, 2 * node + 2, (l_node + r_node) / 2 + 1, r_node));
    }
};

class Min_Segtree {
   public:
    int round_size;
    vector<ll> segs;
    Min_Segtree(vector<ll> vect) {
        round_size = 1;
        while (round_size < (int)vect.size()) round_size *= 2;
        segs.resize(2 * round_size - 1);
        fill(segs.begin(), segs.end(), INT_MAX);
        for (int i = 0; i < (int)vect.size(); ++i) {
            segs[i + round_size - 1] = vect[i];
        }

        for (int i = round_size - 2; i > -1; --i) {
            segs[i] = min(segs[2 * i + 1], segs[2 * i + 2]);
        }
    }
    void update(int index, ll val) {
        int node = index + round_size - 1;
        segs[node] = val;
        while (node != 0) {
            node = (node - 1) / 2;
            segs[node] = min(segs[2 * node + 1], segs[2 * node + 2]);
        }
    }

    ll query(int l, int r) { return query(l, r, 0, 0, round_size - 1); }

    ll query(int l, int r, int node, int l_node, int r_node) {
        if (l_node > r || l > r_node) return INT_MAX;
        if (l <= l_node && r_node <= r) return segs[node];
        return min(
            query(l, r, 2 * node + 1, l_node, (l_node + r_node) / 2),
            query(l, r, 2 * node + 2, (l_node + r_node) / 2 + 1, r_node));
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    Max_Sparse as(a);
    /*

            Min_Segtree bs(b);

            ll ans = 0;

                for (int i = 0; i < n; ++i) {
                    // find when max <= min

                    int high = n - 1;
                    int low = i - 1;
                    while (low < high) {
                        int mid = low + (high - low + 1) / 2;

                        // cerr << low << " " << mid << " " << high << "\n";
                        // cerr << as.query(i, mid) << " " << bs.query(i, mid)
       <<
           "\n"; if (as.query(i, mid) <= bs.query(i, mid)) { low = mid; } else {
                            high = mid - 1;
                        }
                    }

                    if (low == i - 1) continue;

                    int last_leq = low;

                    // find when max < min

                    high = n - 1;
                    low = i - 1;
                    while (low < high) {
                        int mid = low + (high - low + 1) / 2;
                        if (as.query(i, mid) < bs.query(i, mid)) {
                            low = mid;
                        } else {
                            high = mid - 1;
                        }
                    }

                    int last_le = low;

                    ans += (ll)last_leq - (ll)last_le;
                    // cerr << last_leq << " " << (ll)last_le << "\n";
                }

                // cerr << bs.query(0, 3) << "\n";

                cout << ans << "\n";
                */
}
