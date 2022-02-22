// Knapsack Problem Solution in C

#include<stdio.h>

int max(int a,int b);
void calculateMethod(char items[],int arr[],int arr1[],int n,int r,int index,int data[],int i, int data1[],char nesne[]);
void printKnapsack(char items[],int arr[],int arr1[], int n, int r);

void knapSackSolution(int W, int weights[], int values[], int n,char items[]) {
   int i, w;
   int K[n + 1][W + 1];
   
   for (i = 0; i <= n; i++) {
      for (w = 0; w <= W; w++) {
         if (i == 0 || w == 0)
            K[i][w] = 0;
         else if (weights[i - 1] <= w)
            K[i][w] = max(values[i - 1] +
            K[i - 1][w - weights[i - 1]], K[i - 1][w]);
         else
            K[i][w] = K[i - 1][w];
      }
   }
   
   int maxValue = K[n][W];
   int sumofItemsWeights=0;
           	
   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
   printf("Girilen nesnelerin kiymet ve agirlik degerlerine gore Knapsack Problemi icin elde edilebilecek \nmaximum kiymet degeri = %d \n",maxValue);
   printf("\n---------------------------------------------------------------------------\n");
   printf("Cantanin kapasitesi icin belirtilen %d agirligini asmayacak sekilde elde edilebilecek \nmaximum kiymet degeri icin secilebilecek nesneler asagida siralanmistir:\n\n",W);
   w = W;
   for (i = n; i > 0 && maxValue > 0; i--) {
      if (maxValue == K[i - 1][w])
         continue;
      else {
         printf("-> %d kiymet degerine ve %d agirligina sahip '%c' nesnesi\n", values[i - 1],weights[i-1],items[i-1]);
         maxValue = maxValue - values[i - 1];
         w = w - weights[i - 1];
         sumofItemsWeights+=weights[i-1];
      }
   }
   printf("\nSecilecek bu nesnelerin agirliklari toplami = %d\n",sumofItemsWeights);
}


// nesnelerin deger ve araliklarinin toplamini gosteren method
void printKnapsack(char items[],int arr[],int arr1[], int n, int r)
{
    char nesne[r];
    int data[r];
    int data1[r];
    
 	calculateMethod(items,arr,arr1, n, r, 0, data, 0, data1,nesne);
 
    
}


int max(int a, int b)
 { 
// a b den buyukse a yi, degilse b yi dondur
return (a > b) ? a : b; 

}

void calculateMethod(char items[],int arr[],int arr1[], int n, int r, int index, int data[], int i,int data1[],char nesne[])
{
    int sumW=0;
    int sumV=0;
    int j;
   
  
    if (index == r)
    {
        for (j=0; j<r; j++)
        {
            printf("%c nesnesinin kiymet degeri= %d || ",nesne[j], data1[j]);
    
            printf("%c nesnesinin agirligi= %d ",nesne[j], data[j]);
        	printf("\n");
        	 sumW+=data[j];
            sumV+=data1[j];
		}
		        	
			
			printf("\n=> Bu nesne/nesneler icin hesaplanan kiymet degerleri toplami= %d",sumV);
			
			printf("\n=> Bu nesne/nesneler icin hesaplanan agirlik degerleri toplami= %d\n",sumW);
        
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        return;
    }
 
    
    if (i >= n)
        return;
 
    
     data1[index] = arr1[i];
       data[index] = arr[i];
       nesne[index]=items[i];
   
    calculateMethod(items,arr,arr1, n, r, index+1, data, i+1,data1,nesne);
 
    calculateMethod(items,arr,arr1, n, r, index, data, i+1,data1,nesne);
}

// ana method
int main()
{
	/*c: kapasite 
    w[]: agirlik kumesi
    v[]: deger kumesi 
    n: nesne sayisi
    
    Knapsack problemi icin soruda belirtilen sartlar:
    5<=c<=25
    1<=w<=c
    1<=v<=n^2 */
    
    int i, n, v[5], w[5], c;
  
    n=5;
	char items [5]={'A','B','C','D','E'};
    printf("Knapsack Problemi icin kullanilacak cantanin kapasitesini giriniz:");
    scanf("%d", &c);
   
    printf("\nKnapsack Probleminde optimal nesne secimi icin nesnelerin degerlerini ve agirliklarini giriniz:\n\n");
   for (i = 0; i < n; ++i) {
        printf("%c nesnesinin degeri =>  ",items [i]);
        scanf("%d", &v[i]);
        if(v[i]<1 || v[i]>n*n)
        {
        	printf("--------------------------------------------------------------------------------------------------------");
        	printf("Nesnenin kiymet degeri icin girilen sayi 1 den kucuk veya nesne sayisindan buyuk oldugu icin program sonlanmistir.");
        	return 0;
		}
            
        printf("%c nesnesinin agirligi => ",items [i]);
        scanf("%d", &w[i]);
        if(w[i]<1 || w[i]>c)
        {
        	printf("--------------------------------------------------------------------------------------------------------");
        	printf("Nesnenin agirligi icin girilen sayi 1 den kucuk veya kapasiteden buyuk oldugu icin program sonlanmistir.");
        	return 0;
		}
        printf("\n");
    }
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  
             	for(i=1;i<=5;i++)
             	{
             		// Nesnelerin degerleri toplamini bastiran method
             		printKnapsack(items,w,v, 5, i);
             	
				 }
                 
                 knapSackSolution(c, w, v, n,items);
                 return 0;
            
}
