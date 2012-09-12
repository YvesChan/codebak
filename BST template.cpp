#include<iostream>
#include<queue>
using namespace std;

//Binary tree node class
template <class Elem>
class BinNode {
private:
	Elem it;       //the node's value
	BinNode* lc;   //left child
	BinNode* rc;   //right child
public:
	BinNode(){lc = rc = NULL;}
	BinNode(Elem e,BinNode* l = NULL,BinNode* r = NULL){
		it = e; lc = l; rc = r;
	}
	~BinNode(){}
	Elem& val(){return it;}
	void setVal(const Elem& e){it = e;}
	inline BinNode<Elem>* left() const {return lc;}    //use inline function to improve performance
	inline BinNode<Elem>* right() const {return rc;}
	void setLeft(BinNode<Elem>* l){lc = l;}
	void setRight(BinNode<Elem>* r){rc = r;}
	bool isLeaf(){return lc == NULL && rc == NULL;}
};


//BST 
template <class Elem>
class BST{
private:
	BinNode<Elem>* root;
	int num;      //number of node in BST
	void clearhelp(BinNode<Elem>*);
	BinNode<Elem>* inserthelp(BinNode<Elem>*, const Elem&);
	BinNode<Elem>* deletemin(BinNode<Elem>*, BinNode<Elem>*&);
	BinNode<Elem>* removehelp(BinNode<Elem>*, const Elem&, BinNode<Elem>*&);
	bool findhelp(BinNode<Elem>*,const Elem&,BinNode<Elem>*&) const;
	void printhelp(BinNode<Elem>*,int) const;      //print by graph
	int heighthelp(BinNode<Elem>* subroot) const {    //calculate the BST'height
		if(subroot == NULL)return 0;
		int l = heighthelp(subroot->left());
		int r = heighthelp(subroot->right());
		else return 1 + (l > r ? l : r);
	}

public:
	BST(){root = NULL; num = 0;}
	~BST(){clearhelp(root);}
	void clear(){
		clearhelp(root);
		root = NULL;
		num = 0;
	}
	bool insert(const Elem& e){
		root = inserthelp(root,e);
		num ++;
		return true;
	}
	bool remove(const Elem& k, Elem& e){
		BinNode<Elem>* t = NULL;
		root = removehelp(root,k,t);
		if(t == NULL)return false;    //NOT found
		e = t->val();
		num --;
		delete t;
		return true;
	}
	bool find(const Elem& k) const {return findhelp(root,k);}
	int size(){return num;}
	void print() const {
		if(root == NULL) cout<<"empty tree\n";
		else printhelp(root,0);
	}

	//additional function
	void BFSprinthelp() const {
		queue<BinNode<Elem>*> q;
		BinNode<Elem>* tmp;
		q.push(root);
		while(!q.empty()){
			tmp = q.front();
			q.pop();
			cout<<tmp->val()<<"  ";
			if(tmp->left() != NULL) q.push(tmp->left());
			if(tmp->right() != NULL) q.push(tmp->right());
		}
		cout<<endl;
	}

	int height() const {return heighthelp(root);}
};
template <class Elem>
bool BST<Elem>::findhelp(BinNode<Elem>* subroot,const Elem& k,BinNode<Elem>*& t) const {
	if(subroot == NULL)return false;     //empty tree;
	if(subroot->val() < k)return findhelp(subroot->left(),k);
	if(subroot->val() > k)return findhelp(subroot->right(),k);
	else {t = subroot;return true;}
}

template <class Elem>
void BST<Elem>::clearhelp(BinNode<Elem>* subroot){
	if(subroot == NULL)return;    //empty tree
	clearhelp(subroot->left());
	clearhelp(subroot->right());
	delete subroot;
}

template <class Elem>
BinNode<Elem>* BST<Elem>::inserthelp(BinNode<Elem>* subroot,const Elem& val){
	if(subroot == NULL)return new BinNode<Elem>(val);
	if(val < subroot->val())subroot->setLeft(inserthelp(subroot->left(),val));    //insert on left
	else subroot->setRight(inserthelp(subroot->right(),val));     //insert on right
	return subroot;      //return subtree with node inserted
}

template <class Elem>
BinNode<Elem>* BST<Elem>::deletemin(BinNode<Elem>* subroot,BinNode<Elem>*& min){
	if(subroot->left() == NULL){      //find minimun elem
		min = subroot;
		return subroot->right();
	}
	else {
		subroot->setLeft(deletemin(subroot->left(),min));
		return subroot;            //done
	}
}

//cosider reusing code as findhelp() & deletemin(),but it's difficlut to delete the leaf node
template <class Elem>
BinNode<Elem>* BST<Elem>::removehelp(BinNode<Elem>* subroot,const Elem& k,BinNode<Elem>*& t){
	if(subroot == NULL)return NULL;    //not found
	else if(subroot->val() > k) subroot->setLeft(removehelp(subroot->left(),k,t));
	else if(subroot->val() < k) subroot->setRight(removehelp(subroot->right(),k,t));
	else {            //find it
		t = subroot;
		if(subroot->left() == NULL)return subroot->right();     //only rihgt subtree(or leaf)
		else if(subroot->right() == NULL)return subroot->left();  //only left subtree(or leaf)
		else {
			BinNode<Elem>* rmin;
			subroot->setRight(deletemin(subroot->right(),rmin));   //find/delete the minimum elem in right subtree
			rmin->val() ^= t->val();
			t->val() ^= rmin->val();
			rmin->val() ^= t->val();     //swap(t,rmin)
			t = rmin;
		}
	}
	return subroot;
}

template <class Elem>
void BST<Elem>::printhelp(BinNode<Elem>* subroot,int level) const {
		if(subroot == NULL)return;
		printhelp(subroot->right(),level + 1);
		for(int i = 0;i < level;i ++)cout << "   ";
		cout << subroot->val() << "\n";
		printhelp(subroot->left(),level + 1);
	}

int main(){
	int n,t;
	BST<int> b;
	cout<<"0.exit\n"
		<<"1.insert\n"
		<<"2.remove\n"
		<<"3.print\n"
		<<"4.BFS\n"
		<<"5.height\n";
	
	while(cin>>n && n != 0){
		switch(n){
			case 1:	
				cout<<"input:";
				while(cin>>n && n >= 0) b.insert(n);
				break;
			case 2:
				cout<<"input:";
				cin>>n;
				b.remove(n,t);
				break;
			case 3:
				b.print();
				break;
			case 4:
				b.BFSprinthelp();
				break;
			case 5:
				b.height();
		}
	}
	return 0;
}