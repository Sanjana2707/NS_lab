#include<stdio.h>
#include<math.h>
long long int power(long long int a,long long int b,long long int p){
    if(b==1)
    return a;
    else return (((long long int )pow(a,b))%p);
}
int main(){
    long long int a,b,x,y,ka,kb,P,G;
    printf("Enter the prime number:");
    scanf("%lld",&P);
     printf("Enter the primitive root of P:");
    scanf("%lld",&G);
     printf("Enter the private key for alice:");
    scanf("%lld",&a);
     printf("Enter the private key for bob:");
    scanf("%lld",&b);
    printf("The prime number is:%lld\n",P);
     printf("The primitive root of P is:%lld\n",G);
      printf("The private key for alice is:%lld\n",a);
       printf("The private key for bob is:%lld\n",b);
       x=power(G,a,P);
       y=power(G,b,P);
       ka=power(y,a,P);
       kb=power(x,b,P);
        printf("The secret key for alice is:%lld\n",ka);
        printf("The secret key for bob is:%lld\n",kb);
    return 0;
    
}
