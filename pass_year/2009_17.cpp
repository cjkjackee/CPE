#include <iostream>
using namespace std;

// A utility function to search x in arr[] of size n
int search(char arr[], char x, int n)
{
    for (int i = 0; i < n; i++)
      if (arr[i] == x)
         return i;
    return -1;
}

// Prints postorder traversal from given inorder and preorder traversals
void printPostOrder(char in[], char pre[], int n,int nn)
{
   // The first element in pre[] is always root, search it
   // in in[] to find left and right subtrees
   int root = search(in, pre[0], n);

   // If left subtree is not empty, print left subtree
   if (root != 0)
      printPostOrder(in, pre+1, root,nn);

   // If right subtree is not empty, print right subtree
   if (root != n-1)
      printPostOrder(in+root+1, pre+root+1, n-root-1,nn);

   // Print root
   cout << pre[0] <<((n==nn)?"":" ");
}

int main()
{
   int x,y;
   char in[100]={0};
   char pre[100]={0};
   int n,i,j,k;
   while(cin>>x){
        for(i=0;i<x;i++){
            cin>>y;
            for(j=0;j<y;j++){
                cin>>pre[j];
            }
            for(k=0;k<y;k++){
                cin>>in[k];
            }
            printPostOrder(in,pre,y,y);
            cout<<endl;
        }
   }
   return 0;
}
