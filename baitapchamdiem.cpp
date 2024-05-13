#include <iostream>
#include <vector> 
using namespace std;
template<typename T>
class BSTree{
	public:
		BSTree(){
			root=NULL;
		}
		~BSTree(){
			makeEmpty();
			cout<<"Da goi destructer";
		}
		void makeEmpty(){
			makeEmpty(root);
		}
		bool isEmpty(){
			return root==NULL;
		}
		T findMin(){
			Bnode* v=findMin(root);
			if(v!=NULL) return v->elem;
		}
		T findMax(){
			Bnode* v=findMax(root);
			if(v!=NULL) return v->elem;
		}
		void insert(T x){
			insert(x,root);
		}
		void print(){
			duyetgiua(root);
			cout<<endl;
		} 
		void remove(T x){
			remove(x,root);
		}
	private:
		struct Bnode{
			T elem;
			Bnode* left;
			Bnode* right;
			Bnode(T x,Bnode* l,Bnode* r){
				elem=x;
				left=l;
				right=r;
			}
		};
		Bnode* root;
		void makeEmpty(Bnode* &t){
			if(t==NULL) return;
			makeEmpty(t->left);
			makeEmpty(t->right);
			delete t;
			t=NULL;
		}
		Bnode* findMin(Bnode* t){
			while(t->left!=NULL){
				t=t->left;
			}
			return t;
		}
		Bnode* findMax(Bnode* t){
			while(t->right!=NULL){
				t=t->right;
			}
			return t;	
		}
		void insert(T x,Bnode* &t){
			if(t==NULL){
				t=new Bnode(x,NULL,NULL);
			}else if(x>t->elem) 
					insert(x,t->right);
			else if(x<t->elem)
					insert(x,t->left);
			else;
		}
		void duyetgiua(Bnode* t){
			if(t==NULL) return;
			duyetgiua(t->left);
			cout<<t->elem<<" ";
			duyetgiua(t->right);
		}
		void remove(T x,Bnode* &t){
			if(t==NULL) return;
			if(x<t->elem)
				return remove(x,t->left);
			if(x>t->elem)
				return remove(x,t->right);
			else if(t->left!=NULL && t->right!=NULL){
				t->elem=findMin(t->right)->elem;
				remove(t->elem,t->right);
			}else{
				Bnode* old=t;
				t=(t->left!=NULL)?t->left:t->right;
				delete old;
			}
			
		}
		
};
template<typename T>
void between(BSTree<T> &tree,T a,T b){
	vector<T> ds;
	T temp;
	//copy tu cay sang vector theo thu tu tang dan
	while(!tree.isEmpty()){
		temp=tree.findMin();
		tree.remove(temp);
		ds.push_back(temp);
	}
	cout<<"Cac gia tri cua cay trong khoang "<<a<<"->"<<b<<" la: "; 
	for(int i=0;ds[i]<=b;i++){
		if(ds[i]>=a) cout<<" "<<ds[i];
	//	cout<<"This is i: "<<i<<endl;
	//	cout<<"This is ds[i]: "<<ds[i]<<endl;
	}
	cout<<endl;
	return;
}
int main(){
	BSTree<int> bstree;
	bstree.insert(9);
	bstree.insert(5);
	bstree.insert(6);
	bstree.insert(9);
	bstree.insert(2);
	bstree.insert(8);
	cout<<"In cay: ";
	bstree.print();
	cout<<"Da xoa: 9"<<endl;
	bstree.remove(9);
	cout<<"In cay: ";
	bstree.print();
	bstree.remove(6);
	bstree.insert(34);
	bstree.insert(-8);
	cout<<"Da them: 34 -8"<<endl;
	cout<<"In cay: ";
	bstree.print();
	cout<<"Min: "<<bstree.findMin()<<endl;
	cout<<"Max: "<<bstree.findMax()<<endl;
	int a,b;
	cout<<"Nhap khoang: "; cin>>a>>b;
	between<int>(bstree,a,b);
	return 0;
}

