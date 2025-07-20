#include "treap.h"

using namespace std;

Treap::Treap() : root(nullptr) {

}

TreapNode* Treap::rotate_right(TreapNode* node) {
    TreapNode* new_root = node->left;
    node->left = new_root->right;
    new_root->right = node;
    return new_root;
}

TreapNode* Treap::rotate_left(TreapNode* node) {
    TreapNode* new_root = node->right;
    node->right = new_root->left;
    new_root->left = node;
    return new_root;
}

TreapNode* Treap::insert_helper(TreapNode* node, string key, int priority) {
    if (node == nullptr)
        return new TreapNode(key, priority);
    if (key < node->key) {
        node->left = insert_helper(node->left, key, priority);
        if (node->left->priority > node->priority)
            node = rotate_right(node);
    } else {
        node->right = insert_helper(node->right, key, priority);
        if (node->right->priority > node->priority)
            node = rotate_left(node);
    }
    return node;
}

void Treap::insert(string key, int priority){
    this->root = insert_helper(this->root, key, priority);
}

TreapNode* Treap::search_helper(TreapNode* node, string key) {
    if (node == nullptr || node->key == key)
        return node;
    if (key < node->key)
        return search_helper(node->left, key);
    else
        return search_helper(node->right, key);
}

TreapNode* Treap::delete_helper(TreapNode* node, string key) {
    if (node == nullptr)
        return node;
    if (key < node->key)
        node->left = delete_helper(node->left, key);
    else if (key > node->key)
        node->right = delete_helper(node->right, key);
    else {
        if (node->left == nullptr) {
            TreapNode* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            TreapNode* temp = node->left;
            delete node;
            return temp;
        }

        if (node->left->priority < node->right->priority) {
            node = rotate_left(node);
            node->left = delete_helper(node->left, key);
        } else {
            node = rotate_right(node);
            node->right = delete_helper(node->right, key);
        }
    }
    return node;
}

