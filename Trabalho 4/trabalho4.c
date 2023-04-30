/*Lucas Lopes Silva
 * Note: O vetor de retorno deve ser alocado internamente, assuma que quem chamou vai dar free
 *nele
 */

#include <stdio.h>
#include <stdlib.h>

int cmp(void *a, void *b);
int* maxSubsequence(int* nums, int numsSize, int k, int* returnSize);

int main() {
    int *nums, k, numsSize = 4, *returnSize; //numsSize = 4 para fazer os testes do pdf

    nums = (int *) malloc (sizeof(int) * numsSize);
    returnSize = (int *) malloc (sizeof(int));
    
    for (int i = 0; i < numsSize; i++){
        printf("Digite o valor do %d numero do vetor: ", i + 1);
        scanf("%d", &nums[i]);
    }

    printf("Digite o tamanho de k: ");
    scanf("%d", &k);

    int *ans = maxSubsequence( nums, numsSize, k, returnSize);
    for(int i = 0; i < k; i++){
        printf("%d \n", ans[i]);     
    }

    free(nums);
    free(returnSize);
    free(ans);

    return 0;
}

int cmp(void *a, void *b){
    return *(int *)a < *(int *)b;
}

int* maxSubsequence(int* nums, int numsSize, int k, int* returnSize){
    int lenght = numsSize, count = 0, i, j;
    int *sorted = (int *) malloc(sizeof(int) * lenght);//vetor para ordenar
    int *ans = (int *) malloc (sizeof(int) * k);//vetor que sera retornado
    *returnSize = k;

    memcpy(sorted, nums, lenght * sizeof(int));
    qsort(sorted, lenght, sizeof(int), cmp);
    int kMax = sorted[k - 1];

    for(i = k - 1; i >= 0; i--){
        if(sorted[i] == kMax){
            count++;
        } else {
            break;
        }
    }

    for(i = 0, j = 0; i < lenght; i++){
        if(nums[i] > kMax){
            ans[j++] = nums[i];
        } else if(nums[i] == kMax){
            if(count > 0){
                ans[j++] = nums[i];
                count--;
            }
        }
    }
    return ans;
}