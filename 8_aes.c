// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<openssl/aes.h>
unsigned char aes_key[]="0123456789abcdef";
void aes_encrypt(unsigned char *plaintext,unsigned char *ciphertext){
    AES_KEY key;
    AES_set_encrypt_key(aes_key,128,&key);
    AES_encrypt(plaintext,ciphertext,&key);
}
void aes_decrypt(unsigned char *ciphertext,unsigned char *decryptedtext){
    AES_KEY key;
    AES_set_decrypt_key(aes_key,128,&key);
    AES_decrypt(ciphertext,decryptedtext,&key);
}

int main() {
 unsigned char plaintext[100];
 printf("Enter the plaintext:");
 fgets(plaintext,100,stdin);
 plaintext[strcspn(plaintext,"\n")]='\0';
 unsigned char ciphertext[AES_BLOCK_SIZE];
  unsigned char decryptedtext[AES_BLOCK_SIZE];
  aes_encrypt(plaintext,ciphertext);
  aes_decrypt(ciphertext,decryptedtext);
  printf("Original message:%s\n",plaintext);
  printf("Encrypted message:");
  for(int i=0;i<AES_BLOCK_SIZE;i++){
      printf("%02x",ciphertext[i]);
  }
  printf("\n");
printf("decrypted message:%s\n",decryptedtext);

    return 0;
}
/* sudo apt update
sudo apt install libssl -dev
gedit aes.c
gcc aes.c -lssl -lcrypto
  ./a.out
  */
