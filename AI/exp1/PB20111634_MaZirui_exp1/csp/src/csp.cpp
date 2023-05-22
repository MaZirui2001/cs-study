#include "bits/stdc++.h"
using namespace std;
#define INPUT_FILE "../input/input9.txt"
#define OUTPUT_FILE "../output/output9.txt"
// record fit:
// input0: 20/21
// input1: 57/60
// input2: 33/33
// input3: 111/114
// input4: 69/69
// input5: 571/576
// input6: 1005/1008
// input7: 377/378
// input8: 2156/2160
// input9: 716/720
#define DEBUG
struct worker{
    int alloc_work_num{0};
    vector<int> request_work;
};
struct work{
    vector<int> av_worker;
    int alloc_worker{0};
    int request_num{0};
};
int N, D, S;
int min_per_work_time;
bool alloc_work(work * works, worker * workers){
    // recursion solve the CSP problem
    // if all works are allocated, return true
    // else return false
    // find a work which is not allocated
    // MRV: get the work with the least available workers
    int work_id = -1;
    int min_req_num = N + 1;
    for(int i = 0; i < D * S; i++){
        if(works[i].alloc_worker == -1 && works[i].request_num < min_req_num){
            work_id = i;
            min_req_num = works[i].request_num;
        }
    }

    // if all works are allocated, return true
    if(work_id == -1){
        return true;
    }
    // find a worker who can do this work
    for(int i = 0; i < works[work_id].av_worker.size(); i++){
        int worker_id = works[work_id].av_worker[i];
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
            int right = work_id + 1;
            bool right_exist = false;
            if(left >= 0 && works[left].alloc_worker == -1){
                auto iter = find(works[left].av_worker.begin(), works[left].av_worker.end(), worker_id);
                if(iter != works[left].av_worker.end()){
                    left_exist = true;
                    works[left].av_worker.erase(iter);
                }
            }
            if(right < D * S && works[right].alloc_worker == -1){
                auto iter = find(works[right].av_worker.begin(), works[right].av_worker.end(), worker_id);
                if(iter != works[right].av_worker.end()){
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
    auto request = new bool[N * D * S];
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
                    workers[i].request_work.push_back(j * S + k);
                    works[j * S + k].request_num++;
                }
                if(k != S - 1)
                    fin.ignore();
            }
        }
    }
    // 按照每个工人是否有意向选择这个工作以及这个工人的剩余意向数对工作表中的工人排序
    for(int i = 0; i < D * S; i++){
        sort(works[i].av_worker.begin(), works[i].av_worker.end(), [&](int a, int b){
            return request[a * D * S + i] != request[b * D * S + i] ? request[a * D * S + i] > request[b * D * S + i] : workers[a].request_work.size() < workers[b].request_work.size();
        });
    }

    // split the work time:
    min_per_work_time = D * S / N;
    // solve the CSP problem
    alloc_work(works, workers);
    // 分配剩余的工作，使得每个人的意向尽可能被满足，相邻的工作不能被同一个人做
   // alloc_remained_work(works, workers);
#ifdef DEBUG
    auto answer = new bool[N];
    for(int i = 0; i < N; i++){
        answer[i] = false;
    }
    for(int i = 0; i < D * S; i++){
        if(works[i].alloc_worker != -1){
            answer[works[i].alloc_worker] = true;
        }
        if(i > 0){
            if(works[i].alloc_worker == works[i - 1].alloc_worker){
                cout << "error" << endl;
            }
        }
    }
    for(int i = 0; i < N; i++){
        if(!answer[i]){
            cout << "error1" << endl;
        }
    }
    // 输出每一个工人的意向工作
//    cout << "request: " << endl;
//    for(int i = 0; i < N; i++){
//        cout << "worker " << i + 1<< " : ";
//        for(int j : workers[i].request_work){
//            cout << j << " ";
//        }
//        cout << endl;
//    }
    // 输出每一个工人的分配情况
//    cout << "alloc: " << endl;
//    for(int i = 0; i < N; i++){
//        cout << "worker " << i + 1<< " : ";
//        for(int j = 0; j < D * S; j++){
//            if(works[j].alloc_worker == i){
//                cout << j << " ";
//            }
//        }
//        cout << endl;
//    }

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
    fin.close();
    fout.close();
}