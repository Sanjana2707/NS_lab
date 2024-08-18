#include <stdio.h>
#include<string.h>
void ceaser(char text[],int shift){
    int i;
    for(i=0;text[i]!='\0';i++){
        if(text[i]>='a'&&text[i]<='z'){
            text[i]='a'+(text[i]-'a'+shift)%26;
        }
          else if(text[i]>='A'&&text[i]<='Z'){
            text[i]='A'+(text[i]-'A'+shift)%26;
        }
    }
}

int main() {
    char message[100];
    int key;
    printf("Enter the message:");
    fgets(message,sizeof(message),stdin);
    printf("Enter the key:");
    scanf("%d",&key);
    printf("The original message:%s\n",message);
    ceaser(message,key);
    printf("The encrypted message:%s\n",message);
      ceaser(message,-key);
    printf("The decrypted message:%s\n",message);
    

    return 0;
}
