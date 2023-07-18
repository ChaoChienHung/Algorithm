#include <bits/stdc++.h>
#define Infinity 9999999
#define MaxFireStation 100 + 1
#define MaxIntersection 500 + 1

using namespace std;

int Fire_station[MaxFireStation], Distance[MaxIntersection][MaxIntersection];

void Initial(const int &intersection)
{
    for (int i = 1; i <= intersection; ++i) {
        for (int j = 1; j <= intersection; ++j)
            Distance[i][j] = Infinity;
        Distance[i][i] = 0;
    }
}
void Floyd(const int &intersection)
{
    for (int k = 1; k <= intersection; ++k)
        for (int i = 1; i <= intersection; ++i)
            for (int j = 1; j <= intersection; ++j)
                Distance[i][j] = min(Distance[i][j], Distance[i][k] + Distance[k][j]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int Cases, Fire_station_number, Intersection;
    cin >> Cases;
    while (Cases--)
    {
        cin >> Fire_station_number >> Intersection;
        for (int i = 0; i < Fire_station_number; ++i)
            cin >> Fire_station[i];

        Initial(Intersection);

        string input;
        getline(cin, input);
        while (getline(cin, input) && !input.empty()) {
            stringstream ss(input);
            int head, tail, weight;
            ss >> head >> tail >> weight;
            Distance[head][tail] = Distance[tail][head] = weight;
        }

        Floyd(Intersection);

        int shortest_length[MaxIntersection];  // shortest length
        int max_shortest_length = 0;  // max shortest length
        for (int i = 1; i <= Intersection; ++i) {
            shortest_length[i] = Infinity;
            for (int j = 0; j < Fire_station_number; ++j)
                shortest_length[i] = min(shortest_length[i], Distance[i][Fire_station[j]]);
            max_shortest_length = max(max_shortest_length, shortest_length[i]);
        }

        int answer = 1;
        for (int i = 1; i <= Intersection; ++i) {
            int new_length = 0;
            for (int j = 1; j <= Intersection; ++j) {
                int shorter = min(Distance[i][j], shortest_length[j]);
                new_length = max(new_length, shorter);
            }
            if (new_length < max_shortest_length) {
                max_shortest_length = new_length;
                answer = i;
            }
        }
        cout << answer << endl;
        if (Cases) cout << endl;
    }
}

// 題目 : https://onlinejudge.org/external/102/10278.pdf

// Reference : http://programming-study-notes.blogspot.com/2014/04/10278-fire-station.html