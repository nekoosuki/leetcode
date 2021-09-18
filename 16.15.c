#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* masterMind(char* solution, char* guess, int* returnSize){
    // *returnSize = 2;
    int* answer =(int*)malloc(sizeof(int) * 2);
    int gusd = 0, fgusd = 0;
    int solu[4] = {0,0,0,0};
    int gues[4] = {0,0,0,0};
    for (int i = 0; i < 4; i++){
        if(solution[i] == guess[i]){
            gusd++;
        }
        switch (solution[i]){
            case 'R':
                solu[0]++;
                break;
            case 'G':
                solu[1]++;
                break;
            case 'B':
                solu[2]++;
                break;
            case 'Y':
                solu[3]++;
                break;
        }
        switch (guess[i]){
            case 'R':
                gues[0]++;
                break;
            case 'G':
                gues[1]++;
                break;
            case 'B':
                gues[2]++;
                break;
            case 'Y':
                gues[3]++;
                break;
        }
    }
    for(int i = 0; i < 4; i++){
        fgusd += (gues[i] > solu[i] ? solu[i] : gues[i]);
    }
    answer[0] = gusd;
    answer[1] = fgusd - gusd;
    return answer;
}
int main() {
    char* solu = "RGBY";
    char* gues = "GGRY";
    int* p = masterMind(solu, gues, NULL);
    for (int i = 0; i < 2; i++) {
        printf("%d\t", p[i]);
    }
}