#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <ctime>
using namespace std;
enum Color{RED, BLACK};
struct intval{
    int low;
    int high;
    intval(){}
    intval(int _low, int _high){ low = _low; high = _high;}
};

struct RBnode{
    int key;
    Color color;
    RBnode *lson;
    RBnode *rson;
    RBnode *p;
    int max;
    intval intv;
    RBnode(int _key, int _max){
        key = _key; max = _max;
        lson = rson = p = nullptr;
        color = BLACK; intv = intval(key, max);
    }
};

class RBTree{
private:
    RBnode *nil;

    bool is_overlap(intval a, intval b);

    int get_max(RBnode *z);
    void left_rotate(RBnode *z); 
    void right_rotate(RBnode *z); 

    void RB_insert_fixup(RBnode *z); 

    RBnode* RB_tree_minimum(RBnode *z); 
    void RB_trasplant(RBnode *u, RBnode *v); 
    void RB_delete_fixup(RBnode *z);

public:
    RBnode *root;

    RBTree(){
        nil = new RBnode(-1, -1);
        root = nil;
        nil->lson = nil;
        nil->rson = nil;
    }

    void RB_insert(RBnode *z); 
    bool RB_delete(RBnode *z); 
    RBnode* RB_search(intval *intv, RBnode *r);
    intval *interval_search(intval i);

    void mid_trv(RBnode* r, ofstream &fout);
};
int RBTree::get_max(RBnode *z){
    return max(z->intv.high, max(z->lson->max, z->rson->max));
}

void RBTree::left_rotate(RBnode *z){
    // fix z->rson
    RBnode *y = z->rson;

    z->rson = y->lson;
    if(y->lson != nil) y->lson->p = z;

    // fix y->p
    y->p = z->p;

    // fix z->p
    if(z->p == nil) root = y; // z is root
    else if(z == z->p->lson) z->p->lson = y;
    else z->p->rson = y;

    // fix y->lson
    y->lson = z;
    z->p = y;
    
    y->max = get_max(y);
    z->max = get_max(z);
}

void RBTree::right_rotate(RBnode *z){
    // fix z->lson
    RBnode *y = z->lson;
    z->lson = y->rson;
    if(y->rson != nil) y->rson->p = z;

    // fix y->p
    y->p = z->p;

    // fix z->p
    if(z->p == nil) root = y; // z is root
    else if(z == z->p->lson) z->p->lson = y;
    else z->p->rson = y;

    // fix y->rson
    y->rson = z;
    z->p = y;

    y->max = get_max(y);
    z->max = get_max(z);
}

void RBTree::RB_insert(RBnode *z){
    RBnode *y = nil;
    RBnode *x = root;
    // find location
    while(x != nil){
        y = x;
        x->max = max(x->max, z->max);
        if(z->key < x->key) x = x->lson;
        else x = x->rson;
    }
    // link z with rbtree
    z->p = y;
    if(y == nil) root = z;
    else if(z->key < y->key) y->lson = z;
    else y->rson = z;
    z->lson = z->rson = nil;
    z->max = get_max(z);
    z->color = RED;
    RB_insert_fixup(z);
}

void RBTree::RB_insert_fixup(RBnode *z){
    // only when dad is red, go loop
    while(z->p->color == RED){
        RBnode *y; // y is uncle of z
        if(z->p == z->p->p->lson){
            y = z->p->p->rson;
            /* case 1: uncle is red, convert dad, uncle and grandpa , and iter grandpa to root*/
            if(y->color == RED){
                z->p->color = BLACK;    // father:  black
                y->color = BLACK;       // uncle:   black
                y->p->color = RED;      // grandpa: red
                z = z->p->p;
            }
            else {
                /* case 2: uncle is black, and z is the lson, left rotate based on dad convert to case 3*/
                if(z == z->p->rson){
                    z = z->p;
                    left_rotate(z);
                }
                /* case 3: uncle is black, and z is the rson, convert dad and grandpa, eft rotate based on grandpa*/
                z->p->color = BLACK;
                z->p->p->color = RED;
                right_rotate(z->p->p);
            }
        }
        else {
            y = z->p->p->lson;
            if(y->color == RED){
                z->p->color = BLACK;    
                y->color = BLACK;       
                y->p->color = RED;      
                z = z->p->p;
            }
            else {
                if(z == z->p->lson){
                    z = z->p;
                    right_rotate(z);
                }
                z->p->color = BLACK;
                z->p->p->color = RED;
                left_rotate(z->p->p);
            }
        }
    }
    root->color = BLACK;
}

RBnode* RBTree::RB_tree_minimum(RBnode *z){
    while(z->lson != nil) z = z->lson;
    return z;
}

void RBTree::RB_trasplant(RBnode *u, RBnode *v){
    if(u->p == nil) root = v;
    else if(u == u->p->lson) u->p->lson = v;
    else u->p->rson = v;
    v->p = u->p;
}

RBnode* RBTree::RB_search(intval* intv, RBnode *r){
    if(r == nil || r->intv.low == intv->low && r->intv.high == intv->high ) return r;
    if(intv->low < r->key) return RB_search(intv, r->lson);
    else if(intv->low > r->key) return RB_search(intv, r->rson);
    else {
        RBnode * temp = RB_search(intv, r->lson);
        return (temp == nil) ? RB_search(intv, r->rson) : temp;
    }
}

bool RBTree::RB_delete(RBnode *z){
    if(z == nil) return false;

    RBnode *x;
    RBnode *y = z;
    Color y_orig_color = y->color;

    /* case 1: no lson, link directly*/
    if(z->lson == nil){
        x = z->rson;
        RB_trasplant(z, z->rson);
        z->p->max = get_max(z->p);
        x->max = get_max(x);
    }
    /* case 2: no rson, link directly */
    else if(z->rson == nil){
        x = z->lson;
        RB_trasplant(z, z->lson);
        z->p->max = get_max(z->p);
        x->max = get_max(x);
    }
    /* case 3: both has lson and rson */
    else {
        y = RB_tree_minimum(z->rson);
        y_orig_color = y->color;
        x = y->rson;
        if(y->p == z) x->p = y;
        else {
            RB_trasplant(y, y->rson);
            y->rson = z->rson;
            y->rson->p = y;
            y->p->max = get_max(y->p);
        }
        RB_trasplant(z, y);
        y->lson = z->lson;
        y->lson->p = y;
        y->color = z->color;

        z->p->max = get_max(z->p);
        y->max = get_max(y);
    }
    if(y_orig_color == BLACK) RB_delete_fixup(x);
    delete z;
    return true;
}

void RBTree::RB_delete_fixup(RBnode *z){
    RBnode *w;
    while(z != root && z->color == BLACK){
        if(z == z->p->lson){
            w = z->p->rson;
            /* case 1 : brother is RED. convert to case 2,3,4*/
            if(w->color == RED){
                w->color = BLACK;
                z->p->color = RED;
                left_rotate(z->p);
                w = z->p->rson;
            }
            /* case 2 : brother is black and brother's two sons are black */
            if(w->lson->color == BLACK && w->rson->color == BLACK){
                w->color = RED;
                z = z->p;
            }
            else {
                /* case 3: brother is black , lson is red, rson is black*/
                if(w->rson->color == BLACK){
                    w->lson->color = BLACK;
                    w->color = RED;
                    right_rotate(w);
                    w = z->p->rson;
                }
                /* case 4: brother is black , rson is red */
                w->color = z->p->color;
                z->p->color = BLACK;
                w->rson->color = BLACK;
                left_rotate(z->p);
                z = root;
            }
        }
        else{
            w = z->p->lson;
            if(w->color == RED){
                w->color = BLACK;
                z->p->color = RED;
                right_rotate(z->p);
                w = z->p->lson;
            }
            if(w->lson->color == BLACK && w->rson->color == BLACK){
                w->color = RED;
                z = z->p;
            }
            else {
                if(w->lson->color == BLACK){
                    w->rson->color = BLACK;
                    w->color = RED;
                    left_rotate(w);
                    w = z->p->lson;
                }
                w->color = z->p->color;
                z->p->color = BLACK;
                w->lson->color = BLACK;
                right_rotate(z->p);
                z = root;
            }
        }
    }
    z->color = BLACK;
}

bool RBTree::is_overlap(intval a, intval b){
    if(a.low>b.high||a.high<b.low) return false;
    else return true;
}

intval* RBTree::interval_search(intval i){
    RBnode *x = root;
    while(x != nil && !is_overlap(i, x->intv)){
        if(x->lson != nil && x->lson->max >= i.low) x = x->lson;
        else x = x->rson;
    }
    if(x == nil) return nullptr;
    else return &(x->intv);
}

void RBTree::mid_trv(RBnode *r, ofstream &fout){
    if(r == nil) return;
    mid_trv(r->lson, fout);
    fout << r->intv.low << " " << r->intv.high << " " << r->max << endl;
    cout << r->intv.low << " " << r->intv.high << " " << r->max << endl;
    mid_trv(r->rson, fout);
}

int main(){
    ifstream fin;
    ofstream inorder_fout, delete_fout, search_fout;
    RBTree inv_tree;
    vector<intval> invs;
    srand(time(0));
    fin.open("../input/input.txt");
    inorder_fout.open("../output/inorder.txt");
    delete_fout.open("../output/delete_data.txt");
    search_fout.open("../output/search.txt");
    while(!fin.eof()){
        int low, high;
        fin >> low >> high;
        RBnode* node = new RBnode(low, high);
        inv_tree.RB_insert(node);
        invs.push_back(node->intv);
    }
    // inorder
    inv_tree.mid_trv(inv_tree.root, inorder_fout);

    // delete data 
    cout << "delete intvals:" << endl;
    delete_fout << "delete intvals:" << endl;
    for(int i = 0; i < 3; i++){
        int loc = rand() % (invs.size());
        cout << invs[loc].low << " " << invs[loc].high << endl;
        delete_fout << invs[loc].low << " " << invs[loc].high << endl;
        RBnode * p = inv_tree.RB_search(&(invs[loc]), inv_tree.root);
        inv_tree.RB_delete(p);
        invs.erase(invs.begin() + loc);
    }
    cout << "middle traverse result:" << endl;
    delete_fout << "middle traverse result:" << endl;
    inv_tree.mid_trv(inv_tree.root, delete_fout);

    // search
    intval *intv = new intval();
    for(int i = 0; i < 3; i++){
        
        cout << "search intval: ";
        search_fout << "search intval: ";
        if(i == 0){
            intv->low = 25;
            intv->high = 30;
        }
        else {
            intv->low = rand() % 50;
            intv->high = intv->low + rand() % (51 - intv->low);
        }
        cout << intv->low << " " << intv->high << endl << "result: ";
        search_fout << intv->low << " " << intv->high << endl << "result: ";
        intval *p = inv_tree.interval_search(*intv);
        if(p == nullptr) {
            cout << "NULL" << endl;
            search_fout << "NULL" << endl;
        }
        else {
            cout << p->low << " " << p->high << endl;
            search_fout << p->low << " " << p->high << endl;
        }
    }

    fin.close();
    inorder_fout.close();
    delete_fout.close();
    search_fout.close();
}