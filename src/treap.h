#pragma once
#include <string>

using namespace std;

class TreapNode {
public:
    string key;
    int priority;
    TreapNode* left;
    TreapNode* right;
    TreapNode(string key, int priority) : key(key), priority(priority), left(nullptr), right(nullptr) {}
};

class Treap {
private:
public:
    Treap();
    TreapNode* root;
    TreapNode* rotate_right(TreapNode* node);
    TreapNode* rotate_left(TreapNode* node);
    void insert(string key, int priority);
private:
    TreapNode* insert_helper(TreapNode* node, string key, int priority);
    TreapNode* search_helper(TreapNode* node, string key);
    TreapNode* delete_helper(TreapNode* node, string key);
};
