#include <windows.h>
#include <stdio.h>
int main(){
    printf("PlaySound()before\n");
        //檔案不存在,會有很小聲的錯誤聲音
    PlaySound("badbad.wav", NULL, SND_SYNC);
    printf("PlaySound()after\n");
}
