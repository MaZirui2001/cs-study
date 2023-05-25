#include "bits/stdc++.h"
using namespace std;
#define INPUT_FILE "../input/input9.txt"
#define OUTPUT_FILE "../output/output9.txt"
// record fit:
// input0: 20/21
// input1: 58/60
// input2: 32/33
// input3: 114/114
// input4: 68/69
// input5: 575/576
// input6: 1008/1008
// input7: 377/378
// input8: 2159/2160
// input9: 720/720

#define DEBUG
struct worker{
    int alloc_work_num{0};
};
struct work{
    vector<int> av_worker;
    vector<int> req_worker;
    int alloc_worker{0};
};
int N, D, S;
int min_per_work_time;
bool * request;
bool alloc_work(work * works, worker * workers){
    // MRV: get the work with the least request_num
    int work_id = -1;
    int min_req_num = N + 1;
    int min_av_num = N + 1;
    vector<int> req_equal_0;
    vector<int> req_ge_1;
    for(int i = 0; i < D * S; i++){
        if(works[i].alloc_worker == -1){
            if(works[i].req_worker.empty()){
                req_equal_0.push_back(i);
            }
            else{
                req_ge_1.push_back(i);
            }
        }
    }
    if(!req_ge_1.empty()){
        for(int i : req_ge_1){
            if(works[i].req_worker.size() < min_req_num){
                work_id = i;
                min_req_num = (int)works[work_id].req_worker.size();
            }
        }
    }
    else if(!req_equal_0.empty()){
        for(int i : req_equal_0){
            if(works[i].av_worker.size() < min_av_num){
                work_id = i;
                min_av_num = (int)works[work_id].av_worker.size();
            }
        }
    }
    // if all works are allocated, return true
    if(work_id == -1){
        for(int i = 0; i < N; i++){
            if(workers[i].alloc_work_num < min_per_work_time){
                return false;
            }
        }
        return true;
    }
    // sort the available workers of this work by their request_num
    sort(works[work_id].av_worker.begin(), works[work_id].av_worker.end(), [&](int a, int b){
        return request[a * D * S + work_id] != request[b * D * S + work_id] ? request[a * D * S + work_id] > request[b * D * S + work_id]
                                                                                : workers[a].alloc_work_num < workers[b].alloc_work_num;
    });
    for(int i = 0; i < works[work_id].av_worker.size(); i++){
        int worker_id = works[work_id].av_worker[i];
        // if all workers take enough works, then we can allocate this work to any worker
        bool full = true;
        for(int j = 0; j < N; j++){
            if(workers[j].alloc_work_num < min_per_work_time){
                full = false;
                break;
            }
        }
        // if this worker can do this work
        if(full || workers[worker_id].alloc_work_num < min_per_work_time){
            // allocate this work to this worker
            works[work_id].alloc_worker = worker_id;
            workers[worker_id].alloc_work_num++;
            // update its neighbors' available workers
            int left = work_id - 1;
            bool left_exist = false;
            if(left >= 0 && works[left].alloc_worker == -1){
                auto iter = find(works[left].av_worker.begin(), works[left].av_worker.end(), worker_id);
                if(iter != works[left].av_worker.end()){
                    left_exist = true;
                    works[left].av_worker.erase(iter);
                }
            }
            int right = work_id + 1;
            bool right_exist = false;
            if(right < D * S && works[right].alloc_worker == -1) {
                auto iter = find(works[right].av_worker.begin(), works[right].av_worker.end(), worker_id);
                if (iter != works[right].av_worker.end()) {
                    right_exist = true;
                    works[right].av_worker.erase(iter);
                }
            }
            // recursion
            if(alloc_work(works, workers)){
                return true;
            }
            // fail, recover
            works[work_id].alloc_worker = -1;
            workers[worker_id].alloc_work_num--;
            if(left_exist){
                works[left].av_worker.push_back(worker_id);
            }
            if(right_exist){
                works[right].av_worker.push_back(worker_id);
            }
        }
    }
    return false;
}
int main(){

    ifstream fin = ifstream(INPUT_FILE);
    ofstream fout = ofstream(OUTPUT_FILE);
    // input
    char comma = ',';
    fin >> N >> comma >> D >> comma >> S;

    auto workers = new worker[N];
    auto works = new work[D * S];
    request = new bool[N * D * S];
    // init
    for(int i = 0; i < N; i++){
        workers[i].alloc_work_num = 0;
    }
    for(int i = 0; i < D * S; i++){
        for(int j = 0; j < N; j++){
            works[i].av_worker.push_back(j);
        }
        works[i].alloc_worker = -1;
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < D; j++){
            for(int k = 0; k < S; k++) {
                int temp;
                fin >> temp;
                request[i * D * S + j * S + k] = temp;
                if(temp == 1){
//                    workers[i].request_work.push_back(j * S + k);
//                    works[j * S + k].request_num++;
                    works[j * S + k].req_worker.push_back(i);
                }
                if(k != S - 1)
                    fin.ignore();
            }
        }
    }

    // calculate the min_per_work_time
    min_per_work_time = D * S / N;
    // solve the CSP problem
    alloc_work(works, workers);
#ifdef DEBUG
    // 打印每个工人的工作分配情况
//    for(int i = 0; i < N; i++){
//        cout << "worker " << i << " : ";
//        for(int j = 0; j < D * S; j++){
//            if(works[j].alloc_worker == i){
//                cout << j << " ";
//            }
//        }
//        cout << endl;
//    }
    auto answer = new int[N];
    for(int i = 0; i < N; i++){
        answer[i] = false;
    }
    for(int i = 0; i < D * S; i++){
        if(works[i].alloc_worker != -1){
            answer[works[i].alloc_worker]++;
        }
        if(i > 0){
            if(works[i].alloc_worker == works[i - 1].alloc_worker){
                cout << "error: works that are near are done by the same worker!" << endl;
            }
        }
    }
    for(int i = 0; i < N; i++){
        if(answer[i] < min_per_work_time){
            cout << "error: not all the worker does the average work!" << endl;
        }
    }

#endif
    // output
    int count = 0;
    for (int j = 0; j < D * S; j++) {
        fout << works[j].alloc_worker + 1 << ",\n"[j % S == S - 1];
        if (request[works[j].alloc_worker * D * S + j]) {
            count++;
        }
    }
    fout << count << endl;
#ifdef DEBUG
    cout << count << endl;
#endif
    fin.close();
    fout.close();
}