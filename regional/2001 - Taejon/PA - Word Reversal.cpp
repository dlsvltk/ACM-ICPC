//each string divided by newline
//each words (j~i-1) reversal print and white space
#include<stdio.h>
int main(){
    int t;
    for(scanf("%d ", &t);t--;){
        char a[1001];
        gets(a);
        int i,j;
        for(j=i=0;a[i];i++){
            if(a[i] == ' '){   //each word (j ~ i-1)
                int k;
                for(k=i-1;k>=j;k--)putchar(a[k]);
                putchar(' ');
                j = i+1;
            }
        }
        int k;
        for(k = i-1; k>=j;k--)putchar(a[k]);    //remain last
        puts("");                               //newline
    }
}
//BOJ 9093
