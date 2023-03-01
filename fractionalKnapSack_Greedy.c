#include <stdio.h>

int main() {
    int n, i, j, temp, W;
	float P=0.0;
    
    // take input of the number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    // take input of the profits of the items
    int profits[n];
    printf("Enter the profits of the items:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &profits[i]);
    }
    
    // take input of the weights of the items
    int weights[n];
    printf("Enter the weights of the items:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }
    
    // take input of the Knapsack Capacity
    printf("Enter knapsack capacity:\n");
    scanf("%d",&W);
    
    // calculate the profit by weight ratio array
    float ratios[n];
    for (i = 0; i < n; i++) {
        ratios[i] = (float)profits[i] / weights[i];
    }
    
    // display each item's profit, weight, and profit by weight ratio
    printf("\nItem\tProfit\tWeight\tRatio\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%.2f\n", i+1, profits[i], weights[i], ratios[i]);
    }
    
    // bubble sort all three arrays in terms of the profit by weight ratio
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (ratios[j] < ratios[j+1]) {
                // swap ratios
                float temp_ratio = ratios[j];
                ratios[j] = ratios[j+1];
                ratios[j+1] = temp_ratio;
                
                // swap profits
                temp = profits[j];
                profits[j] = profits[j+1];
                profits[j+1] = temp;
                
                // swap weights
                temp = weights[j];
                weights[j] = weights[j+1];
                weights[j+1] = temp;
            }
        }
    }
    
    // display the sorted arrays
    printf("\nHence the items sorted  with respect their profit and weight ratio are:\n");

  printf("\nItem\tProfit\tWeight\tRatio\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%.2f\n", i+1, profits[i], weights[i], ratios[i]);
    }
    
    
    // now compute maximum profit
    for(i=0;i<n;i++){
    	if(W>0 && weights[i]<=W)
    	{
    		W=W-weights[i];
    		P=P+profits[i];
		}
		else break;
	}
	if(W>0){
		P=P+(float)profits[i]*W/weights[i];
	}
	printf("\n And the maximum profit is: %.2f",P);
    
    return 0;
}

