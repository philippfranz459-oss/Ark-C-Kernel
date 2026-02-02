#include  <stdio.h>

int main (){
    char text[100];
    int i=0;

    printf("原信是什么：");
    scanf("%s",text);

    while (text[i] !='\0'){
        if (text[i]=='z'){
            text[i]='a';
        } else {
            text[i]=text[i]+1;
                

                
            }
            

        
        i++;
    }
    printf("加密后的文件是:%s",text);
    return 0;
    
    
    
}