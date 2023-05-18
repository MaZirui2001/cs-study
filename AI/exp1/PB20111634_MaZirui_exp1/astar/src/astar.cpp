#include "bits/stdc++.h"

//#define DIJKSTRA
#define DEBUG

enum Direction {
    UP_RIGHT = 1, UP_LEFT, DOWN_LEFT, DOWN_RIGHT
};
// the record of the path
struct path_node {
    int x, y;
    Direction direction;
};

// nodes of a star
struct node {
    int f{0}, g{0}, h{0};
    bool mat[12][12]{};
    std::vector<path_node> path;
};
auto compare = [](node *a, node *b) { return a->f < b->f; };

// update location
struct update_location {
    int x0, y0, x1, y1, x2, y2;
};

// size of the mat
int size = 12;

/* h_function of a star */
int h_func(const node *n) {
#ifdef DIJKSTRA
    return 0;
#endif
    int h = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            h += n->mat[i][j];
        }
    }
    return h;
}

// check finish
bool check_finish(const node *n) {
#ifdef DIJKSTRA
    for (int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(n->mat[i][j] == 1){
                return false;
            }
        }
    }
    return true;
#endif
    return n->h == 0;
}

update_location get_loc(int i, int j, Direction s) {
    switch (s) {
        case UP_RIGHT:
            return {i + 1, j, i, j, i + 1, j + 1};
        case UP_LEFT:
            return {i + 1, j + 1, i + 1, j, i, j + 1};
        case DOWN_LEFT:
            return {i, j + 1, i, j, i + 1, j + 1};
        case DOWN_RIGHT:
            return {i, j, i, j + 1, i + 1, j};
    }
}

// data structure for a star search
std::multiset<node *, decltype(compare)> node_list(compare);

// input and output file
#define INPUT_FILE "../input/input9.txt"
#define OUTPUT_FILE "../output/output9.txt"
#define MAX_LENGTH 100000
#define STRIP_LENGTH 1000

int main() {
    std::ifstream fin(INPUT_FILE);
    std::ofstream fout(OUTPUT_FILE);
    fin >> size;
    node *root = new node;
    // input
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            fin >> root->mat[i][j];
        }
    }
    root->h = h_func(root);
    root->f = root->g + root->h;
    node_list.insert(root);
#ifdef DEBUG
    auto temp = root;
    root = new node;
    *root = *temp;
#endif
    while (!check_finish(*node_list.begin())) {
        node *n = *node_list.begin();
        node_list.erase(node_list.begin());
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - 1; j++) {
                for (int k = 1; k <= 4; k++) {
                    auto loc = get_loc(i, j, (Direction) k);
                    if (n->mat[loc.x0][loc.y0] == 0 && n->mat[loc.x1][loc.y1] == 0 && n->mat[loc.x2][loc.y2] == 0)
                        continue;
                    node *new_node = new node;
                    memcpy(new_node->mat, n->mat, sizeof(n->mat));
                    new_node->mat[loc.x0][loc.y0] = !new_node->mat[loc.x0][loc.y0];
                    new_node->mat[loc.x1][loc.y1] = !new_node->mat[loc.x1][loc.y1];
                    new_node->mat[loc.x2][loc.y2] = !new_node->mat[loc.x2][loc.y2];
                    new_node->h = h_func(new_node);
                    new_node->g = n->g + 3;
                    new_node->f = new_node->g + new_node->h;
                    new_node->path = n->path;
                    new_node->path.push_back({loc.x0, loc.y0, (Direction) k});
                    node_list.insert(new_node);
                }
                if (node_list.size() > MAX_LENGTH) {
                    auto it = node_list.end();
                    for (int u = 0; u < STRIP_LENGTH; u++)
                        delete *--it;
                    node_list.erase(it, node_list.end());
                }
            }
        }
        delete n;
    }
    // output
    if (node_list.empty()) {
        fout << "No valid solution" << std::endl;
        return 0;
    }
    node *n = *node_list.begin();
    fout << n->path.size() << std::endl;
    for (auto &i: n->path) {
        fout << i.x << " " << i.y << " " << i.direction << std::endl;
    }
    for(auto &i : node_list){
        delete i;
    }
    fin.close();
    fout.close();
#ifdef DEBUG
    fin.open(OUTPUT_FILE);
    int M;
    fin >> M;
    for (int k = 0; k < M; k++) {
        int i, j, s;
        fin >> i >> j >> s;
        switch (Direction(s)) {
            case DOWN_RIGHT:
                root->mat[i][j] = !root->mat[i][j];
                root->mat[i + 1][j] = !root->mat[i + 1][j];
                root->mat[i][j + 1] = !root->mat[i][j + 1];
                break;
            case DOWN_LEFT:
                root->mat[i][j] = !root->mat[i][j];
                root->mat[i][j - 1] = !root->mat[i][j - 1];
                root->mat[i + 1][j] = !root->mat[i + 1][j];
                break;
            case UP_RIGHT:
                root->mat[i][j] = !root->mat[i][j];
                root->mat[i][j + 1] = !root->mat[i][j + 1];
                root->mat[i - 1][j] = !root->mat[i - 1][j];
                break;
            case UP_LEFT:
                root->mat[i][j] = !root->mat[i][j];
                root->mat[i - 1][j] = !root->mat[i - 1][j];
                root->mat[i][j - 1] = !root->mat[i][j - 1];
                break;
        }
    }
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            std::cout << root->mat[i][j] << " \n"[j == size - 1];
    fin.close();
#endif
    return 0;
}
