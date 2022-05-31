#include <stdio.h>
#include "CMP3_MCI.h" ///記得要下載，同目錄中
CMP3_MCI mp3;
int main(){
    mp3.Load("07042111.mp3");
    mp3.Play();

    printf("Input:");
    int N;
    scanf("%d", &N);
}
