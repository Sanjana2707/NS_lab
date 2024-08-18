#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
char *encrypt(char *plaintext,char *key);
char *decrypt(char *ciphertext,char *key);
int main(){
  char plaintext[1000];
  char key[100];
  printf("Enter the plaintext:");
  fgets(plaintext,sizeof(plaintext),stdin);
  plaintext[strcspn(plaintext,"\n")]='\0';
  printf("Enter the key:");
  fgets(key,sizeof(key),stdin);
  key[strcspn(key,"\n")]='\0';
  printf("Original plaintext:%s\n",plaintext);
  char* encrypted_text=encrypt(plaintext,key);
  char* decrypted_text=decrypt(encrypted_text,key);
  printf(" Ciphertext:%s\n",encrypted_text);
  printf(" Plaintext:%s\n",decrypted_text);
  free(encrypted_text);
    free(decrypted_text);
return 0;
}
char *encrypt(char *plaintext,char *key){
    int keyLength=strlen(key);
    int textLength=strlen(plaintext);
    char *encrypted_text=(char*)malloc(textLength+1);
    strcpy(encrypted_text,plaintext);
    for(int i=0;i<textLength;i++){
        if(isalpha(plaintext[i])){
            char shift=key[i%keyLength]-'a';
            if(isupper(plaintext[i])){
                encrypted_text[i]='A'+(plaintext[i]-'A'+shift)%26;
            }
            else
            encrypted_text[i]='a'+(plaintext[i]-'a'+shift)%26;
        }
    }
    return encrypted_text;
}
char *decrypt(char *ciphertext,char *key){
    int keyLength=strlen(key);
    int textLength=strlen(ciphertext);
    char *decrypted_text=(char*)malloc(textLength+1);
    strcpy(decrypted_text,ciphertext);
    for(int i=0;i<textLength;i++){
        if(isalpha(ciphertext[i])){
            char shift=key[i%keyLength]-'a';
            if(isupper(ciphertext[i])){
                decrypted_text[i]='A'+(ciphertext[i]-'A'-shift+26)%26;
            }
            else
            decrypted_text[i]='a'+(ciphertext[i]-'a'-shift+26)%26;
        }
    }
    return decrypted_text;
}
