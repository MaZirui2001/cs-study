int f(int*g){
    return g(g);
}
int main(){
    f(f);
}