#include<stdio.h>
#include<cstring>

void dfs(char preorder[],char inorder[]){

    int n=strlen(preorder+1),m=strlen(inorder+1);

    if(n==1||m==1){
        printf("%c",preorder[1]);
        return;
    }

    int pos=0;
    for(int i=1;i<=m;++i){
        if(preorder[1]==inorder[i]){
            pos=i;
            break;
        }
    }

    char* preorder_left=new char[pos+1];
    char* preorder_right=new char[pos+1];
    char* inorder_left=new char[m-pos+2];
    char* inorder_right=new char[m-pos+2];  

    for(int i=2;i<=n;++i){
        if(i<=pos)
            preorder_left[i-1]=preorder[i];
        else
            preorder_right[i-pos]=preorder[i];
    }

    for(int i=1;i<=m;++i){
        if(i<pos)
            inorder_left[i]=inorder[i];
        if(i>pos)
            inorder_right[i-pos]=inorder[i];
    }
    
    preorder_left[pos+1]='\0';
    preorder_right[pos+1]='\0';
    inorder_left[m-pos+1]='\0';
    inorder_right[m-pos+1]='\0';

    dfs(preorder_left , inorder_left);
    dfs(preorder_right,inorder_right);
    
    printf("%c",preorder[1]);

    delete [] preorder_left;
    delete [] preorder_right;
    delete [] inorder_left;
    delete [] inorder_right;

    return;
}

int main(){

    char preorder[30],inorder[30];

    scanf("%s",preorder+1);
    scanf("%s", inorder+1);

    dfs(preorder,inorder);

    return 0;
}