#include <windows.h>
#include <stdio.h>
int main(){
    while(1){
        printf("Input The Number:");
        int N;
        scanf("%d", &N);
        if(N==1)PlaySound("do.wav",NULL,SND_ASYNC);
        if(N==2)PlaySound("re.wav",NULL,SND_ASYNC);
        if(N==3)PlaySound("mi.wav",NULL,SND_ASYNC);
    }
}
