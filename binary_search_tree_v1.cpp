/*
Coderbyte coding challenge: Binary Search Tree

Using the C++ language, have the function BinarySearchTreeLCA(strArr) take the
array of strings stored in strArr, which will contain 3 elements: the first
element will be a binary search tree with all unique values in a preorder
traversal array, the second and third elements will be two different values, and
your goal is to find the lowest common ancestor of these two values.

For example: if strArr is ["[10, 5, 1, 7, 40, 50]", "1", "7"] then this tree
looks like the following:

     [10]
   [5]  [40]
 [1][7]   [50]


For the input above, your program should return 5 because that is the value of
the node that is the LCA of the two nodes with values 1 and 7. You can assume
the two nodes you are searching for in the tree will exist somewhere in the
tree.

Sample test cases:

Input:  "[10, 5, 1, 7, 40, 50]", "5", "10"
Output: 10

Input:  "[3, 2, 1, 12, 4, 5, 13]", "5", "13"
Output: 12
*/

#include <cctype>
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

typedef struct tree {
    int * intArray;
    int  size_array;
    int first_int_element;
    int second_int_element;
} parsed_tree;

typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int val) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode* constructBST(int* arr, int start, int end) {
    if (start > end)
        return NULL;

    TreeNode* root = createNode(arr[start]);

    int i;
    for (i = start + 1; i <= end; i++) {
        if (arr[i] > root->val)
            break;
    }

    root->left = constructBST(arr, start + 1, i - 1);
    root->right = constructBST(arr, i, end);

    return root;
}

TreeNode* findLCA(TreeNode* root, int val1, int val2) {
    if (root == NULL)
        return NULL;

    if (root->val > val1 && root->val > val2)
        return findLCA(root->left, val1, val2);

    if (root->val < val1 && root->val < val2)
        return findLCA(root->right, val1, val2);

    return root;
}

parsed_tree* parse_tree_intoArray(char * str_Tree , char * first , char *second){
        
    int len = strlen(str_Tree);
    if( len < 2)
        return NULL;
    //create the dyanmic integer array 
    int * intArray = (int*)calloc(len , sizeof(int));
    if(intArray == NULL)
        return NULL;
    
   // parse the string version 1
    int index = 0;
    char * pch = strtok(str_Tree ," [],.-");
    while(pch != NULL){
        intArray[index]=atoi(pch);
        index++;
        pch = strtok(NULL ," [],.-");
    }
    // // parse first element 
    pch = strtok(first ," [,.-");
    int frist_element =atoi(pch);

    // parse second element 
    pch = strtok(second ," [,.-");
    int second_element =atoi(pch);

    // create the pased_struct 
    parsed_tree * tree= (parsed_tree *) malloc(sizeof(parsed_tree));
    if (tree == NULL)
        return NULL;
    
    tree->first_int_element =frist_element;
    tree->second_int_element =second_element;
    tree->intArray= intArray;
    tree->size_array=index;
    return tree;
    return NULL;


}
int BinarySearchTreeLCA(char* strArr[]) {
    // Parse the input values
    int number_str = 3;
    int length = strlen(strArr[0]);
    char* temp_tree = (char *)malloc(sizeof(char)+1);
    if(temp_tree == NULL)
        return 0 ;
    strcpy(temp_tree , strArr[0]);

    char temp_first_element[3];
    strcpy(temp_first_element , strArr[1]);

    char temp_second_element[3];
    strcpy(temp_second_element , strArr[2]);

    parsed_tree * tree = parse_tree_intoArray(temp_tree , temp_first_element  , temp_second_element);
    
    // Construct the BST
    TreeNode* root = constructBST(tree->intArray, 0, tree->size_array - 1);

    // Find the LCA of the target values
    TreeNode* lcaNode = findLCA(root, tree->first_int_element, tree->second_int_element);
    int returnVal= lcaNode->val;
    
    free(tree->intArray);

    free(temp_tree);
    free(tree);

    return returnVal;
    
}

// int main() {
//     char* strArr1[] = { "[10, 5, 1, 7, 40, 50]", "1", "7" };
//     printf("LCA: %d\n", BinarySearchTreeLCA(strArr1));

//     char* strArr2[] = { "[3, 2, 1, 12, 4, 5, 13]", "5", "13" };
//     printf("LCA: %d\n", BinarySearchTreeLCA(strArr2));

//     return 0;
// }

int main() {
  // string A[] = gets(stdin);
  // cout << BinarySearchTreeLCA_v1(A, sizeof(A)/sizeof(*A));
  char* B[] = {"[10, 5, 1, 7, 40, 50]", "1", "7"};
  cout << BinarySearchTreeLCA(B)
       << '\n';  // expected output: 5
  char* C[] = {"[10, 5, 1, 7, 40, 50]", "5", "10"};
  cout << BinarySearchTreeLCA(C)
       << '\n';  // expected output: 10
  char* D[] = {"[3, 2, 1, 12, 4, 5, 13]", "5", "13"};
  cout << BinarySearchTreeLCA(D)
       << '\n'; // expected output: 12
  char* E[] = {"[3, 2, 1, 12, 4, 5, 13]", "2", "5"};  // 1 2 3 4 5 12 13
  cout << BinarySearchTreeLCA(E)
       << '\n';  // expected output: 3
  char* F[] = {"[5, 3, 1, 7, 6, 12, 45, 32]", "5", "32"};
  cout << BinarySearchTreeLCA(F)
       << '\n';  // expected output: 5
  return 0;
}