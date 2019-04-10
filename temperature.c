

#include <stdio.h>
#define NUMS 10
int highestTemp (double high[],int n);
int lowestTemp(double low[],int n);
double avgTemp(const double low[] , const double high[], int n );

int main() {
    double high[NUMS];
    double low[NUMS];
    int cnt;
    int numDays, exitnum;
    
    printf("---=== BTM Temperature Calculator V3.0 ===---\n");
    printf("Please enter the number of days, between 3 and 10, inclusive: ");
    scanf("%d", &numDays);
    
    while ((numDays > NUMS) || (numDays < 3)) {
        printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
        scanf("%d", &numDays);
    }
    
    for (cnt = 1; cnt <= numDays; cnt++) {
        printf("Day %d - High: ", cnt);
        scanf("%lf", &high[cnt]);
        
        printf("Day %d - Low: ", cnt);
        scanf("%lf", &low[cnt]);
    }
    
    printf("\nDay\tHi\tLow\n");
    for (cnt = 1; cnt <=numDays; cnt++) {
        printf("%d\t%d\t%d\n", cnt, (int)high[cnt],(int)low[cnt]);
    }
    
    for (cnt = 1; cnt <=numDays; cnt++) {
        if(cnt==highestTemp(high,numDays)){
            printf("The highest temperature was %d on day %d\n",(int)high[cnt],cnt);
        }
    }
    for (cnt = 1; cnt <=numDays; cnt++) {
        if(cnt==lowestTemp(low,numDays)){
            printf("The highest temperature was %d on day %d\n",(int)low[cnt],cnt);
        }
    }
    
    printf("Enter a number between 1 and %d to see the average temperature for the entered number of days,enter a negative number to exit: ",numDays);
    scanf("%d",&exitnum);
    while(exitnum>0){
        while (exitnum > numDays) {
            printf("Invalid entry, please enter a number between 1 and %d, inclusive: ",numDays);
            scanf("%d", &exitnum);
        }
		printf("The average temperature up to day %d is: %.2lf\n\n",exitnum,avgTemp(low,high,exitnum));
		printf("Enter a number between 1 and %d to see the average temperature for the entered number of days,enter a negative number to exit: ",numDays);
		scanf("%d",&exitnum);
    }
    printf("Goodbye!");
    return 0;
}

//functions
int highestTemp (double high[],int n){
    int index=1,max= -2147483648;
    
    for(int i =1; i<=n;i++){
        if(max<high[i]){
            max=high[i];
            index=i;
        }
    }
    
    return index;
}
int lowestTemp(double low[],int n){
    int index=1,min= 2147483647;
    
    for(int i =1; i<=n;i++){
        if(min>low[i]){
            min=low[i];
            index=i;
        }
    }
    
    return index;
}
double avgTemp(const double low[] , const double high[], int n ){
    double avg= 0;
    double allhigh=0, alllow=0;
    for(int i =1; i<=n;i++){
        allhigh +=high[i];
        alllow +=low[i];
    }
    avg =(allhigh + alllow)/(n*2);
    return avg;
}
