#include "bits/stdc++.h"
using namespace std;

#define DIJKSTRA
//#define H_CNT
//#define PART
//#define PART_4
//#define H_CNT_FIX

#define DEBUG
#define LIMIT_SPACE

// input and output file
#define INPUT_FILE "../input/input8.txt"
#define OUTPUT_FILE "../output/output8.txt"
#define MAX_LENGTH 10000
#define STRIP_LENGTH 400
// unlimited space time step pop_time
// input0: 2 5 107
// input1: 0 4 53
// input2: 0 5 51
// input3: 3 7 174
// input4: 0 7 40
// input5: 2 7 130
// input6: 102 11 3237
// input7: 36 14 931
// input8: 49 16 1208
// input9: 1298 23 32131
enum Direction {
    UP_RIGHT = 1, UP_LEFT, DOWN_LEFT, DOWN_RIGHT, NONE
};

// the record of the path
struct path_node {
    int x, y;
    Direction direction;
};

// nodes of a star
struct node {
    int f{0}, g{0}, h{0}, cnt{0};
    std::bitset<144>mat;
    std::vector<path_node> path;
};
auto compare = [](node *a, node *b) {
    return a->f < b->f;
};

// update location
struct update_location {
    int x0, y0, x1, y1, x2, y2;
    Direction dir;
};
// size of the mat
int size = 12;

// count 1 numbers
int count_1(const node *n) {
    int cnt = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; ++j) {
            cnt += n->mat[i * 12 + j];
        }
    }
    return cnt;
}

#ifdef PART
int get_part_h(const bool mat[14][14], int i, int j, bool flag[14][14]) {
    if (flag[i][j] || mat[i][j] == 0) return 0;
    flag[i][j] = true;
    int cnt = 1;
    // search up
    cnt += get_part_h(mat, i - 1, j, flag);
    // search up left
    cnt += get_part_h(mat, i - 1, j - 1, flag);
    // search up right
    cnt += get_part_h(mat, i - 1, j + 1, flag);
    // search down
    cnt += get_part_h(mat, i + 1, j, flag);
    // search down left
    cnt += get_part_h(mat, i + 1, j - 1, flag);
    // search down right
    cnt += get_part_h(mat, i + 1, j + 1, flag);
    // search left
    cnt += get_part_h(mat, i, j - 1, flag);
    // search right
    cnt += get_part_h(mat, i, j + 1, flag);
    return cnt;
}
#endif
#ifdef PART_4
int get_part_h4(const bool mat[14][14], int i, int j, bool flag[14][14], int round[14][14], bool round_flag[14][14]) {

    if (flag[i][j] || mat[i][j] == 0) return 0;
    flag[i][j] = true;
    // update how many 1s rounds a 0
    if(round_flag[i-1][j] && round[i-1][j] == 0){
        round[i-1][j]++;
        round_flag[i-1][j] = false;
    }
    if(round_flag[i+1][j] && round[i+1][j] == 0){
        round[i+1][j]++;
        round_flag[i+1][j] = false;
    }
    if(round_flag[i][j-1] && round[i][j-1] == 0){
        round[i][j-1]++;
        round_flag[i][j-1] = false;
    }
    if(round_flag[i][j+1] && round[i][j+1] == 0){
        round[i][j+1]++;
        round_flag[i][j+1] = false;
    }
    int cnt = 1;
    // search up
    cnt += get_part_h4(mat, i - 1, j, flag, round, round_flag);
    // search down
    cnt += get_part_h4(mat, i + 1, j, flag, round, round_flag);
    // search left
    cnt += get_part_h4(mat, i, j - 1, flag, round, round_flag);
    // search right
    cnt += get_part_h4(mat, i, j + 1, flag, round, round_flag);
    return cnt;
}
#endif

/* h_function of a star */
int h_func(const node *n) {
#ifdef PART
    bool flag[14][14] = {false};
    bool mat[14][14] = {false};
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            mat[i + 1][j + 1] = n->mat[i * 12 + j];
        }
    }
    int h = 0;
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            h += (get_part_h(mat, i, j, flag) + 2) / 3;
        }
    }
    return h;
#endif
#ifdef PART_4
    bool flag[14][14] = {false};
    bool mat[14][14] = {false};
    int round[14][14] = {0};
    bool round_flag[14][14] = {false};
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            mat[i + 1][j + 1] = n->mat[i * 12 + j];
        }
    }
    // get the h value: the sum of the ceil of the number of 1s div 3 in each four-connected domains
    int h = 0;
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            memset(round_flag, true, sizeof(round_flag));
            h += (get_part_h4(mat, i, j, flag, round, round_flag) + 2) / 3;
        }
    }
    // fix h: if a 0 is in a 3-connected domain, h -= 1; if a 0 is in a 4-connected domain, h -= 2
    for(int i = 1; i <= size; i++){
        for(int j = 1; j <= size; j++){
            if(round[i][j] == 3) h -= 1;
            else if(round[i][j] == 4) h -= 2;
        }
    }
    return h;
#endif
#ifdef DIJKSTRA
    return 0;
#endif
#ifdef H_CNT
    return (n->cnt + 2) / 3;
#endif
#ifdef H_CNT_FIX
    if(n->cnt == 1) return 3;
    return (n->cnt + 2) / 3 + (n->cnt % 3 == 2);
#endif
}

// check finish
bool check_finish(const node *n) {
#ifdef DIJKSTRA
    for (int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(n->mat[i * 12 + j] == 1){
                return false;
            }
        }
    }
    return true;
#endif
    return n->h == 0;
}

update_location get_loc(int i, int j, int k) {
    switch (k) {
        case 0:
            return {i, j, i - 1, j - 1, i, j - 1, i > 0 && j > 0 ? UP_LEFT : NONE};
        case 1:
            return {i, j - 1, i - 1, j - 1, i, j, i > 0 && j > 0 ? UP_RIGHT : NONE};
        case 2:
            return {i - 1, j, i - 1, j - 1, i, j, i > 0 && j > 0 ? DOWN_LEFT : NONE};
        case 3:
            return {i, j, i - 1, j, i, j + 1, i > 0 && j < size - 1 ? UP_RIGHT : NONE};
        case 4:
            return {i - 1, j, i - 1, j + 1, i, j, i > 0 && j < size - 1 ? DOWN_RIGHT : NONE};
        case 5:
            return {i, j + 1, i - 1, j + 1, i, j, i > 0 && j < size - 1 ? UP_LEFT : NONE};
        case 6:
            return {i, j, i, j + 1, i + 1, j, i < size - 1 && j < size - 1 ? DOWN_RIGHT : NONE};
        case 7:
            return {i, j + 1, i, j, i + 1, j + 1, i < size - 1 && j < size - 1 ? DOWN_LEFT : NONE};
        case 8:
            return {i + 1, j, i, j, i + 1, j + 1, i < size - 1 && j < size - 1 ? UP_RIGHT : NONE};
        case 9:
            return {i, j, i, j - 1, i + 1, j, i < size - 1 && j > 0 ? DOWN_LEFT : NONE};
        case 10:
            return {i, j - 1, i, j, i + 1, j - 1, i < size - 1 && j > 0 ? DOWN_RIGHT : NONE};
        case 11:
            return {i + 1, j, i + 1, j - 1, i, j, i < size - 1 && j > 0 ? UP_LEFT : NONE};
        default:
            return {0, 0, 0, 0, 0, 0, NONE};
    }
}

// data structure for a star search
std::multiset<node *, decltype(compare)> node_list(compare);
unordered_map<bitset<144>, node *> node_map;

int main() {
    std::ifstream fin(INPUT_FILE);
    std::ofstream fout(OUTPUT_FILE);
    fin >> size;
    node *root = new node;
    // input
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            bool temp;
            fin >> temp;
            root->mat[i * 12 + j] = temp;
        }
    }
    root->cnt = count_1(root);
    root->h = h_func(root);
    root->f = root->g + root->h;
    node_list.insert(root);
    node_map[root->mat] = root;
#ifdef DEBUG
    auto temp = root;
    root = new node;
    *root = *temp;
#endif
    // a counter to record time
    int pop_time = 0;
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    while (!check_finish(*node_list.begin())) {
        pop_time++;
        node *n = *node_list.begin();
        node_list.erase(node_list.begin());
        node_map.erase(n->mat);
        int i = 0, j = 0, u = 0;
        // find a 1 in the matrix
        for (u = 0; u < 144; u++) {
            if (n->mat[u] == 1) break;
        }
        i = u / 12;
        j = u % 12;
        // generate new nodes in 12 directions
        for (int k = 0; k < 12; k++) {
            auto loc = get_loc(i, j, k);
            if (loc.dir == NONE) continue; // out of bound
            node *new_node = new node;
            new_node->cnt = n->cnt;
            new_node->mat = n->mat;
            // update matrix
            new_node->mat[loc.x0 * 12 + loc.y0] = !new_node->mat[loc.x0 * 12 + loc.y0];
            new_node->mat[loc.x1 * 12 + loc.y1] = !new_node->mat[loc.x1 * 12 + loc.y1];
            new_node->mat[loc.x2 * 12 + loc.y2] = !new_node->mat[loc.x2 * 12 + loc.y2];
            // update how many 1 in the matrix
            new_node->cnt += new_node->mat[loc.x0 * 12 + loc.y0] ? 1 : -1;
            new_node->cnt += new_node->mat[loc.x1 * 12 + loc.y1] ? 1 : -1;
            new_node->cnt += new_node->mat[loc.x2 * 12 + loc.y2] ? 1 : -1;
            // update g, h, f
            new_node->h = h_func(new_node);
            new_node->g = n->g + 1;
            new_node->f = new_node->g + new_node->h;
            // update path
            new_node->path = n->path;
            new_node->path.push_back({loc.x0, loc.y0, loc.dir});
            // delete same node in the list
            auto iter = node_map.find(new_node->mat);
            if(iter != node_map.end()){
                if(iter->second->f > new_node->f){
                    delete iter->second;
                    node_list.erase(iter->second);
                    node_list.insert(new_node);
                    node_map[new_node->mat] = new_node;
                }
                else
                    delete new_node;
                continue;
            }
            node_map[new_node->mat] = new_node;
            node_list.insert(new_node);
        }
#ifdef LIMIT_SPACE
        if (node_list.size() > MAX_LENGTH) {
            auto it = node_list.end();
            it--;
            for (int v = 0; v < STRIP_LENGTH; v++){
                node_map.erase((*it)->mat);
                auto tmp = it;
                it--;
                delete *(tmp);
                node_list.erase(tmp);
            }
        }
#endif
        delete n;
    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
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
                root->mat[i * 12 + j] = !root->mat[i * 12 + j];
                root->mat[(i + 1) * 12 + j] = !root->mat[(i + 1) * 12 + j];
                root->mat[i * 12 + j + 1] = !root->mat[i * 12 + j + 1];
                break;
            case DOWN_LEFT:
                root->mat[i * 12 + j] = !root->mat[i * 12 + j];
                root->mat[i * 12 + j - 1] = !root->mat[i * 12 + j - 1];
                root->mat[(i + 1) * 12 + j] = !root->mat[(i + 1) * 12 + j];
                break;
            case UP_RIGHT:
                root->mat[i * 12 + j] = !root->mat[i * 12 + j];
                root->mat[i * 12 + j + 1] = !root->mat[i * 12 + j + 1];
                root->mat[(i - 1) * 12 + j] = !root->mat[(i - 1) * 12 + j];
                break;
            case UP_LEFT:
                root->mat[i * 12 + j] = !root->mat[i * 12 + j];
                root->mat[(i - 1) * 12 + j] = !root->mat[(i - 1) * 12 + j];
                root->mat[i * 12 + j - 1] = !root->mat[i * 12 + j - 1];
                break;
            default:
                break;
        }
    }
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            std::cout << root->mat[i * 12 + j] << " \n"[j == size - 1];
    fin.close();
#endif
    std::cout << "Time cost = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count()
              << std::endl;
    std::cout << "Total step = " << n->path.size() << std::endl;
    std::cout << "Total pop time = " << pop_time << std::endl;
    for (auto &i: node_list) {
        delete i;
    }
    return 0;
}
