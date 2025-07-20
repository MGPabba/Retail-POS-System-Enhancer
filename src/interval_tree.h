#include <iostream>
#include <vector>

using namespace std;

class IntNode{
private:
    std::pair<int, int> data;
    int maxValue;
    IntNode* left;
    IntNode* right;
public:
    IntNode(std::pair<int, int> data);
    ~IntNode();

    friend class IntTree;
};

class IntTree{
private:
    IntNode* insert(std::pair<int, int> data, IntNode* root);
    void overlap(int data, IntNode* root, vector<std::pair<int, int> >& intervalList);
public:
    IntNode* root;
    IntTree();
    void insert(std::pair<int, int> data);
    void clear();
    void overlap(int data, vector<std::pair<int, int> >& intervalList);
};
