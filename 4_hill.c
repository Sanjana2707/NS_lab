// Online C compiler to run C program online
#include <stdio.h>
#include<string.h>
#define MAX_SIZE 10
void encrypt(char *plaintext,char *ciphertext,int keyMatrix[MAX_SIZE][MAX_SIZE],int keySize){
    int len=strlen(plaintext);
    int blockSize=keySize;
    int numBlocks=len/blockSize;
    int i,j,k;
    int sumArr[MAX_SIZE];
    for(i=0;i<numBlocks;i++){
        for(j=0;j<keySize;j++){
            sumArr[j]=0;
        }
        for(j=0;j<keySize;j++){
            for(k=0;k<keySize;k++){
            
            sumArr[j]+= keyMatrix[j][k]*(plaintext[i*blockSize+k]-'a');
            }
            sumArr[j]%=26;
        }
         for(j=0;j<keySize;j++){
             ciphertext[i*blockSize+j]=(char)(sumArr[j]+'a');
         }
    }
    ciphertext[len]='\0';
}

int main() {
    int i,j,keySize;
    int keyMatrix[MAX_SIZE][MAX_SIZE];
    char plaintext[100],ciphertext[100];
    printf("Enter the key size:");
    scanf("%d",&keySize);
    printf("Enter the key matrix elements:");
    for(i=0;i<keySize;i++){
        for(j=0;j<keySize;j++){
            scanf("%d",&keyMatrix[i][j]);
        }
    }
    printf("Enter the plaintext:");
    scanf("%s",plaintext);
    if(strlen(plaintext)%2!=0){
        plaintext[strlen(plaintext)]='x';
        plaintext[strlen(plaintext)+1]='\0';
    }
    encrypt(plaintext,ciphertext,keyMatrix,keySize);
    printf("ciphertext:%s\n",ciphertext);

    return 0;
}
