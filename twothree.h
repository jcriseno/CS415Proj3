// Description: Prototypes for 2-3 tree class.

#ifndef TWOTHREE_H
#define TWOTHREE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class TwoThree
{
    public:
	TwoThree();
        void contains() const;
        bool isEmpty();
        //bool isLeaf();
        void printTree(ostream & out = cout) const;
        void buildTree(ifstream & input);
    private:
    	struct node
    	{
            node(const string &x, const string &y, node *l, node *m, node *r)
            :LKey(x), RKey(y), left(l), middle(m), right(r){
                lines.resize(0);
        }
            string LKey;
            string RKey;
            node * left;
            node * middle;
            node * right;
            vector<int> lines;
    	};
    	node * root;
    	void insertHelper(const string &x, int line, node *&t, int &distWord);
    	bool containsHelper(const string &x, node *t, node* &result) const;
    	void printTreeHelper(node *t, ostream & out) const;
    	int findHeight(node *t);
};

#endif



