#include <vector>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <stack>
#include <ctime>
#define INF 0x7fffffff
int n = 0;
using namespace std;
int             min_dis[1024][1024];
int             pre[1024][1024];
struct enode{
    int vnum;
    int weight;
    int w;
    enode(){}
    enode(int _vnum, int _weight){
        vnum = _vnum;
        weight = _weight;
        w = weight;
    }
};
struct vnode{
    int vnum;
    int h;
    int dis;
    int p;
    vector<enode> *elist;
};
class Graph{
    private:
    int  heapsize;
    void build_heap();
    void dfs_cut_minus_circle(bool visited[], int i, int w[]);
    public:
    vector<vnode>   vlist;
    vector<vnode>   vheap;
    vector<int>     map;
    Graph(int num);
    ~Graph();
    int     relax(int i, int j, int w);
    bool    BellmanFord(int s, bool do_cut);
    void    min_heapify(int i);
    void    decreace_key(int i, int key);
    int     extract_min();
    void    cut_minus_circle();
    void    Dijkstra(int s);
    void    Johnson();
    void    print_path(int s, int i, ofstream &fout);
};
Graph::Graph(int num){
    vector<vnode>list(num);
    vlist = move(list);
    heapsize = num;
    for(int i = 0; i < num; i++){
        vlist[i].vnum = i;
        vlist[i].elist = new vector<enode>;
    }
}
Graph::~Graph(){
    int n = vlist.size();
    for(int i = 0; i < n; i++) delete vlist[i].elist;
}
void Graph::print_path(int s, int i, ofstream &fout){
    string path = "";
    while(i != s){
        path = to_string(i) + ", " + path;
        i = pre[s][i];
    }
    path = to_string(s) + ", " + path;
    path.pop_back();
    path.pop_back();
    // cout << path << "  ";
    fout << path << "  ";
}
void Graph::min_heapify(int i){
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    int min;
    if(l < heapsize && vheap[l].dis < vheap[i].dis) min = l;
    else min = i;
    if(r < heapsize && vheap[r].dis < vheap[i].dis) min = r;
    while(min != i){
        swap(vheap[i], vheap[min]);
        map[vheap[i].vnum] = i;
        map[vheap[min].vnum] = min;
        i = min;
        l = i * 2 + 1;
        r = i * 2 + 2;
        if(l < heapsize && vheap[l].dis < vheap[i].dis) min = l;
        else min = i;
        if(r < heapsize && vheap[r].dis < vheap[i].dis) min = r;
    }
}
void Graph::decreace_key(int i, int key){
    if(vheap[i].dis < key) 
        while(1);
    vheap[i].dis = key;
    while(i > 0 && vheap[(i - 1) / 2].dis > vheap[i].dis){
        swap(vheap[(i - 1) / 2], vheap[i]);
        map[vheap[(i - 1) / 2].vnum] = (i - 1) /  2;
        map[vheap[i].vnum] = i;
        i = (i - 1) / 2;
    }
}
void Graph::build_heap(){
    vheap = vlist;
    int n = vlist.size() - 1;
    vector<int> m(n);
    map = move(m);
    for(int i = 0; i < n; i++){
        map[i] = i;
    }
    heapsize = vheap.size() - 1;
    for(int i = (heapsize - 1) / 2; i >= 0; i--){
        min_heapify(i);
    }
}

int Graph::extract_min(){
    int min = vheap[0].vnum;
    swap(vheap[0], vheap[heapsize-1]);
    map[vheap[0].vnum] = 0;
    map[vheap[heapsize-1].vnum] = heapsize - 1;

    heapsize--;
    return min;
}
int Graph::relax(int i, int j, int w){
    int dis = (vlist[i].dis == INF) ? INF : vlist[i].dis + w;
    if(vlist[j].dis > dis){
        vlist[j].dis = dis;
        vlist[j].p = i;
    }
    return vlist[j].dis;
}
bool Graph::BellmanFord(int s, bool do_cut){
    int n = vlist.size();
    // initialize
    for(int i = 0; i < n; i++) {
        vlist[i].dis = INF;
        vlist[i].p = -1;
    }
    vlist[s].dis = 0;
    // relax every edge
    for(int k = 0; k < n - 1; k++){
        for(int i = 0; i < n; i++){
            for(auto j = vlist[i].elist->begin(); j != vlist[i].elist->end(); j++){
                relax(i, j->vnum, j->weight);
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(auto j = vlist[i].elist->begin(); j != vlist[i].elist->end(); j++){
            int dis = (vlist[i].dis == INF) ? INF : vlist[i].dis + j->weight;
            if(vlist[j->vnum].dis > dis) {
                if(!do_cut) return false;
                // cout << "cut: " << i << " " << j->vnum << endl;
                // vlist[i].elist->erase(j--);  
            }
        }
    }
    return true;
}

void Graph::Dijkstra(int s){
    int n = vlist.size() - 1;
    for(int i = 0; i < n; i++) {
        vlist[i].dis = INF;
    }
    vlist[s].dis = 0;
    build_heap();
    while(heapsize > 0){
        int u = extract_min();
        for(auto i = vlist[u].elist->begin(); i != vlist[u].elist->end(); i++){
            decreace_key(map[i->vnum], relax(u, i->vnum, i->w));
        } 
    }
    for(int i = 0; i < n; i++){
        pre[s][i] = vlist[i].p;
    }
    return;
}
void Graph::Johnson(){
    int n = vlist.size();
    for(int i = 0; i < n - 1; i++){
        vlist[n-1].elist->push_back(enode(i, 0));
    }
    if(!BellmanFord(n-1, false)){
        cout << "error! minus circle!" << endl;
        exit(-1);
    }
    for(int i = 0; i < n; i++){
        vlist[i].h = vlist[i].dis;
    }
    for(int i = 0; i < n; i++){
        for(auto j = vlist[i].elist->begin(); j != vlist[i].elist->end(); j++){
            if(j->weight == INF) j->w = INF;
            else j->w = j->weight + vlist[i].h - vlist[j->vnum].h;
        }
    }
    for(int i = 0; i < n - 1; i++){
        Dijkstra(i);
        for(int j = 0; j < n - 1; j++){
            if(vlist[j].dis == INF) min_dis[i][j] = INF;
            else min_dis[i][j] = vlist[j].dis + vlist[j].h - vlist[i].h;
        }
    }
    vlist[n-1].elist->clear();
}

void Graph::cut_minus_circle(){
    int n = vlist.size() - 1;
    bool *visited = new bool[n];
    int  *w = new int[n];

    for(int i = 0; i < vlist.size()-1; i++){
        memset(visited, false, n * sizeof(bool));
        memset(w, 0, n * sizeof(int));
        dfs_cut_minus_circle(visited, i, w);
    }
    delete[] visited;
    delete[] w;
}

void Graph::dfs_cut_minus_circle(bool visited[], int i, int w[]){
    if(visited[i]) return;
    visited[i] = true;
    for(auto j = vlist[i].elist->begin(); j != vlist[i].elist->end(); j++){
        if(visited[j->vnum]){
            if(w[i] - w[j->vnum] + j->weight < 0){
                // cout << "cut: " << i << " " << j->vnum << endl;
                vlist[i].elist->erase(j--);
                n++;
            }
        }
        else {
            w[j->vnum] = w[i] + j->weight;
            dfs_cut_minus_circle(visited, j->vnum, w);
            w[j->vnum] = 0;
        }
    }

}

int main(){
    ofstream fout, ftime;
    ifstream fin;
    int vnum = 27;
    ftime.open("../output/time.txt");
    for(int i = 1; i <= 4; i++){
        for(int j = 1; j <= 2; j++){
            fin.open("../input/input" + to_string(i) + to_string(j) + ".txt");
            fout.open("../output/result" + to_string(i) + to_string(j) + ".txt");
            Graph G(vnum+1);
            int e = 0;
            while(!fin.eof()){
                int u, v, w;
                fin >> u >> v >> w;
                G.vlist[u].elist->push_back(enode(v, w));
                e++;
            }
            fin.close();
            // cut minus circle
            n = 0;
            G.cut_minus_circle();
            int start = (int)clock();
            G.Johnson();
            int end = (int)clock();
            ftime << "scale: vex num = " << vnum << ", edge num = " << e - n << ": " << endl;
            ftime << end - start << "us" << endl << endl;
            for(int m = 0; m < vnum; m++){
                for(int k = 0; k < vnum; k++){
                    //cout << setiosflags(ios::left) << setw(3) << m << " " << setiosflags(ios::left) << setw(3) << k << ": ";
                    fout << setiosflags(ios::left) << setw(3) << m << " " << setiosflags(ios::left) << setw(3) << k << ": ";
                    int dis = min_dis[m][k];
                    if(dis == INF){
                        //cout << "unreachable" << endl;
                        fout << "unreachable" << endl;
                    }
                    else {
                        G.print_path(m, k, fout);
                        //cout << dis << endl;
                        fout << dis << endl;
                    }
                }
            }
            fout.close();
        }
        vnum *= 3;
    }
    return 0;
}