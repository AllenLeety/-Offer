/*
请实现两个函数，分别用来序列化和反序列化二叉树
*/
/*
对于序列化：使用前序遍历，递归的将二叉树的值转化为字符，并且在每次二叉树的结点不为空时，在转化val所得的字符
            之后添加一个','作为分割。对于空节点以'#'代替。
对于反序列化：按照前序顺序，递归的使用字符串中的字符创建一个二叉树（特别注意：在递归时，递归函数的参数一定要
            是char**，这样才能保证每次递归后指向字符串的指针会随着递归的进行而移动）。
*/
#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

void Serialize(TreeNode* root, string &str){
    if(root == NULL){
        str += '#';
        return ;
    }
    string s = to_string(root->val);
    str += s;
    str += ',';
    Serialize(root->left, str);
    Serialize(root->right, str);
}

char* Serialize(TreeNode *root) {    
    if(root == NULL){
        return NULL;
    }
    string str;
    Serialize(root, str);
    char *res = new char[str.length()+1];
    int i;
    for(i=0; i<str.length(); i++){
        res[i] = str[i];
    }    
    res[i] = '\0';
    return res;
}

TreeNode* Deserialize(char** str){//由于递归时，会不断的向后读取字符串
    if(**str == '#'){//所以一定要用**str，以保证得到递归后指针str指向未被读取的字符
        ++(*str);
        return NULL;
    }
    int num = 0;
    while(**str != '\0' && **str != ','){
        num = num * 10 + ((**str) - '0');
        ++(*str);
    }
    TreeNode* root = new TreeNode(num);
    if(**str == '\0'){
        return root;
    }else{
        (*str)++;
    }
    root->left = Deserialize(str);
    root->right = Deserialize(str);
    return root;
}

TreeNode* Deserialize(char *str) {
   if(str == NULL){
        return NULL;
    }
    TreeNode* res = Deserialize(&str);
    return res; 
}

int main()
{
    TreeNode tree[9];
    tree[0].val =8;
    tree[0].left = &tree[1];
    tree[0].right = &tree[2];
    tree[1].val =6;
    tree[1].left = &tree[3];
    tree[1].right = &tree[4];
    tree[2].val =10;
    tree[2].left = &tree[5];
    tree[2].right = &tree[6];
    tree[3].val =4;
    tree[3].left = &tree[7];
    tree[3].right = &tree[8];
    tree[4].val =7;
    tree[4].left = NULL;
    tree[4].right = NULL;
    tree[5].val =9;
    tree[5].left = NULL;
    tree[5].right = NULL;
    tree[6].val =11;
    tree[6].left = NULL;
    tree[6].right = NULL;
    tree[7].val =3;
    tree[7].left = NULL;
    tree[7].right = NULL;
    tree[8].val =5;
    tree[8].left = NULL;
    tree[8].right = NULL;
    char* ch = Serialize(tree);

    return 0;
}