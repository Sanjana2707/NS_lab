#include<stdio.h>
#include<string.h>
void encryption(char plaintext[],char key[]){
    int i;
    char ciphertext[strlen(plaintext)+1];
    for(i=0;plaintext[i]!='\0';i++){
        if(plaintext[i]>='A'&&plaintext[i]<='Z'){
            ciphertext[i]=key[plaintext[i]-'A'];
        }
        else if(plaintext[i]>='a'&&plaintext[i]<='a'){
            ciphertext[i]=key[plaintext[i]-'a'];
        }
        else{
        ciphertext[i]=plaintext[i];
        }
    }
    ciphertext[i]='\0';
    printf("Ciphertext:%s\n",ciphertext);
}
void decryption(char ciphertext[],char key[]){
    int i,j;
    char plaintext[strlen(ciphertext)+1];
    for(i=0;ciphertext[i]!='\0';i++){
        if(ciphertext[i]>='A'&&ciphertext[i]<='Z'){
            for(j=0;key[j]!='\0';j++){
                if(ciphertext[i]==key[j])
                plaintext[i]='A'+j;
            }
            
        }
       else if(ciphertext[i]>='a'&&ciphertext[i]<='a'){
            for(j=0;key[j]!='\0';j++){
                if(ciphertext[i]==key[j]-'a'+'A')
                plaintext[i]='a'+j;
            }
            
        }
        else
        plaintext[i]=ciphertext[i];
    }
    plaintext[i]='\0';
     printf("Decrypted plaintext:%s\n",plaintext);
}
int main(){
    char plaintext[1000];
    char key[100];
    printf("Enter the plaintext:");
    fgets(plaintext,sizeof(plaintext),stdin);
      printf("Enter the key:");
    fgets(key,sizeof(key),stdin);
    printf("Original plaintext:%s\n",plaintext);
    encryption(plaintext,key);
    int i;
    char ciphertext[strlen(plaintext)+1];
    for(i=0;plaintext[i]!='\0';i++){
        if(plaintext[i]>='A'&&plaintext[i]<='Z'){
            ciphertext[i]=key[plaintext[i]-'A'];
        }
        else if(plaintext[i]>='a'&&plaintext[i]<='a'){
            ciphertext[i]=key[plaintext[i]-'a'];
        }
        else
        ciphertext[i]=plaintext[i];
    }
    decryption(ciphertext,key);
    return 0;
}
























