#include "interval_tree.h"
#include <iostream>
#include <vector>

using namespace std;

IntNode::IntNode(std::pair<int, int> data){
    this->data = data;
    this->maxValue = 0;
    this->left = nullptr;
    this->right = nullptr;
}

IntTree::IntTree(){
    this->root = nullptr;
}

IntNode* IntTree::insert(std::pair<int, int> data, IntNode* root){
    if(!root){
        return new IntNode(data);
    }

    if(root->left && data.first < root->left->data.first){
        root->left = insert(data, root->left);
    }
    else{
        root->right = insert(data, root->right);
    }

    if(root->maxValue < data.second){
        root->maxValue = data.second;
    }

    return root;
}

void IntTree::overlap(int data, IntNode* root, vector<std::pair<int, int> >& intervalList){
    if(!root){
        return;
    }
    if(root->data.first <= data && root->data.second >= data){
        intervalList.push_back(std::make_pair(root->data.first, root->data.second));
    }
    if(root->left && data <= root->data.first){
        overlap(data, root->left, intervalList);
    }
    if(root->right && data >= root->data.second){
        overlap(data, root->right, intervalList);
    }
}

void IntTree::insert(std::pair<int, int> data){
    this->root = insert(data, this->root);
}

void IntTree::overlap(int data, vector<std::pair<int, int> >& intervalList){
    overlap(data, this->root, intervalList);
}
