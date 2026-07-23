#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
struct node{
    int x;
    int y;
    int n;
};
struct tree{
    node head;
    tree* l;
    tree* r;
};

bool compare(node a,node b){
    if(a.y == b.y){
        return a.x < b.x;
    }else{
        return a.y > b.y;
    }
}

void add_tree(tree*t, tree*tmp){
    if(t->head.x > tmp->head.x){
        if(t->l == NULL){
            t->l = tmp;
        }else{
            add_tree(t->l,tmp);
        }
    }else{
        if(t->r == NULL){
            t->r = tmp;
        }else{
            add_tree(t->r,tmp);
        }
    }
}

vector <int> pre_arr;
vector <int> post_arr;

void preSearch(tree* t){
    if(t == NULL) return;
    
    pre_arr.push_back(t->head.n);
    preSearch(t->l);
    preSearch(t->r);
}

void postSearch(tree* t){
    if(t == NULL) return;
    
    postSearch(t->l);
    postSearch(t->r);
    post_arr.push_back(t->head.n);
}


vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<node> n;
    
    for(int i = 0; i < nodeinfo.size(); i ++){
        node tmp;
        tmp.x = nodeinfo[i][0];
        tmp.y = nodeinfo[i][1];
        tmp.n = i+1;
        n.push_back(tmp);
    }
    stable_sort(n.begin(),n.end(),compare);
    
    tree* t = new tree;
    t->head = n[0];
    t->l = NULL;
    t->r = NULL;
    
    for(int i = 1 ; i < n.size(); i ++){
        tree* tmp = new tree;
        tmp->head = n[i];
        tmp->l = NULL;
        tmp->r = NULL;
        add_tree(t,tmp);
    }
    preSearch(t);
    postSearch(t);
    answer.push_back(pre_arr);
    answer.push_back(post_arr);
    return answer;
}