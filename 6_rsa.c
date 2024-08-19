#include<stdio.h>
long long int power(long long int base,long long int expo, long long int modulus ){
    long long int result=1;
    while(expo>0){
        if(expo%2==1){
            result=(base *result)% modulus;
        }
        base =(base*base)%modulus;
        expo/=2;
    }
    return result;
}
long long int encrypt(long long int plaintext,long long int e,long long int n){
    return power(plaintext,e,n);
}
long long int decrypt(long long int ciphertext,long long int d,long long int n){
    return power(ciphertext,d,n);
}
int main(){
    long long int p,q,n,phi,e,plaintext,ciphertext,decryptedtext;
    printf("Enter prime number p:");
    scanf("%lld",&p);
    printf("Enter prime number q:");
    scanf("%lld",&q);
    printf("Enter the public exponent e:");
    scanf("%lld",&e);
    n= p*q;
    phi=(p-1)*(q-1);
    long long int d=1;
    while(((d*e)%phi)!=1){
        d++;
    }
    printf("Enter the plaintext:");
    scanf("%lld",&plaintext);
    ciphertext=encrypt(plaintext,e,n);
    printf("Ciphertext:%lld\n",ciphertext);
    decryptedtext=decrypt(ciphertext,d,n);
    printf("decryptedtext:%lld",decryptedtext);
    return 0;
}
