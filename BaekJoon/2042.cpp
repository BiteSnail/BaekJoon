#include <iostream>

using namespace std;

int N, M, K;
typedef struct NODE{
	int left;
	int right;
	long long sum;
	struct NODE *lchild;
	struct NODE *rchild;
}NODE;

NODE arr[2100000];
int arrSize;

long long getSums(int left, int right, NODE* cur){
		int middle = (cur->left+cur->right)/2;
		if(left==cur->left && right==cur->right)
			return cur->sum;

		//left <= right
		if(right <= middle){ 
			return getSums(left, right, cur->lchild);
		}
		else if(left > middle){  
			return getSums(left, right, cur->rchild);
		}
		else{
			return getSums(left, middle, cur->lchild) + getSums(middle+1, right, cur->rchild);
		}
}

void update(const int index, const long long changed, NODE* cur){
	int middle = (cur->left+cur->right)/2;
	cur->sum += changed;
	if(cur->left == index && cur->right==index){
		return;
	}
	if(index <= middle){ 	
		update(index, changed, cur->lchild);
	}
	else{
		update(index, changed, cur->rchild);
	}
}

void initialize(int left, int right, NODE** cur){
	int middle = (left+right)/2;
    *cur = &arr[arrSize++];
	(*cur)->left=left;
	(*cur)->right=right;
	if(left==right){
		return;
	}
	initialize(left, middle, &((*cur)->lchild));
	initialize(middle+1, right, &((*cur)->rchild));
}

void init(int N, NODE** root){
    initialize(0, N-1, root);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long num, cmds;
    long long a, b, c;
    NODE* root = nullptr;
    cin >> N >> M >> K;
    initialize(0, N-1, &root);
    cmds = M+K;
    for(int i=0;i<N;i++){
        cin >> num;
        update(i, num, root);
    }

    for(int i=0;i<cmds;i++){
        cin >> a >> b >> c;
        switch(a){
            case 1:
              update(b-1, c-getSums(b-1, b-1, root), root);
            break;
            case 2:
              cout << getSums(b-1, c-1, root)<<'\n';
            break;
            default:
            break;
        }
    }
    return 0;
}