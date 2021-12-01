#include <iostream>
#include <vector>

using namespace std;

class FindVertex {
private:

    vector<vector<int>> graph;
    vector<int> paths;
    bool check_visited(int vertex, vector<int> visited) {
        if (visited.size() == 0)
            return true;
        else
        {
            for (int edge = 0; edge < visited.size(); edge++)
                if (vertex == visited[edge])
                    return false;
            return true;
        }
    }

public:

    void set_matrix(vector<vector<int>> matrix) {
        this->graph = matrix;
    }

    void search(int begin, int end, vector<int> visited) {
        visited.push_back(begin);
        if (begin == end)
        {
            paths.push_back(visited.size() - 1);
            return;
        }
        else
        {
            for (int vertex = 0; vertex < graph[begin].size(); vertex++) {
                if (graph[begin][vertex] != 0 && check_visited(vertex, visited))
                    search(vertex, end, visited);
            }
        }
    }

    void output() {
        for (int picked = paths.size() - 1; picked > 0; picked--)
            for (int compared = picked - 1; compared >= 0; compared--)
                if (paths[picked] > paths[compared])
                    swap(paths[picked], paths[compared]);
        cout << paths[0];
    }

};


int main() {
    vector<vector<int>> Matrix;
    vector<int>end_way;
    int begin;
    int end;
    cout << "First point: ";
    cin >> begin;
    cout << "End point: ";
    cin >> end;
    vector<vector<int>> matrix = {
            {0, 1, 1, 0, 0, 0, 0, 0},
            {1, 0, 1, 1, 0, 0, 0, 0},
            {1, 1, 0, 0, 1, 0, 0, 0},
            {0, 1, 0, 0, 0, 1, 1, 0},
            {0, 0, 1, 0, 0, 1, 0, 1},
            {0, 0, 0, 1, 1, 0, 1, 1},
            {0, 0, 0, 1, 0, 1, 0, 0},
            {0, 0, 0, 0, 1, 1, 0, 0,}
    };
    FindVertex pop;
    pop.set_matrix(matrix);
    vector<int> visited;
    pop.search(begin, end, visited);
    pop.output();
}