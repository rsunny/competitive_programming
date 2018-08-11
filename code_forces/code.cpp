#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <stdio.h>

using namespace std;

int arr[100009];
vector<int> pst;

struct node {
     int data;
     struct node * left;
     struct node * right;
};

struct node * get_node (int data){
     struct node * new_node;
     if ((new_node = (struct node *)malloc (sizeof(struct node)))){
          new_node->data = data;
          new_node->left = new_node->right = NULL;
     }
     return new_node;
}

struct node * build_subtree (int *curindex, int minval, int maxval, int len){
     struct node * new_node;

     if (*curindex >= len)
          return NULL;

     if (arr[*curindex] > maxval || arr[*curindex] < minval)
          return NULL;

     if (!(new_node = get_node(arr[*curindex])))
          return NULL;

     *curindex = *curindex + 1;

     new_node->left = build_subtree (curindex, minval, new_node->data - 1, len);
     new_node->right = build_subtree (curindex, new_node->data, maxval, len);

     return new_node;
}

void postorder_traversal (struct node * node){
     if (!node)
          return;
     postorder_traversal (node->left);
     postorder_traversal (node->right);
     pst.push_back(node->data);
}

/*
 * Complete the function below.
 */

#include <cassert>
 
vector < int > change(vector < int > po) {
     int n=po.size();
     assert(n>0 and n<=100000);
     for(int i=0;i<n;i++){    
          assert(po[i]>=0 and po[i]<=1000000);
          arr[i]=po[i];
     }
     int startindex = 0;
     struct node * t = build_subtree (&startindex, -1, 1000000, n);
     postorder_traversal(t);
     return pst;
}


int main() {
    vector < int > res;
    
    int _po_size = 0;
    cin >> _po_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _po;
    int _po_item;
    for(int _po_i=0; _po_i<_po_size; _po_i++) {
        cin >> _po_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _po.push_back(_po_item);
    }
    
    res = change(_po);
    for(int res_i=0; res_i < res.size(); res_i++) {
     cout << res[res_i] << endl;;
    }
    
    return 0;
}

