
#include <stdio.h>

int approvaljob(char* Has_job);
int approvalhouse(char*own_house);
int approvalrating(char*credit_rating);

int main()
{
    int age, n_age;
    char Has_job[30], own_house[30],credit_rating[30];
    printf("---=== Credit Card Application ===---\n");
    printf("Enter your age: ");
    scanf("%d",&age);
    getchar();
    printf("Do you have a job? ");
    scanf("%[^\n]s",Has_job);
    getchar();
    printf("Do you do you own a house? ");
    scanf("%[^\n]s",own_house);
    getchar();
    printf("Enter the credit rating: ");
    scanf("%[^\n]s",credit_rating);
    
    if(age>=18 && age<=35){
        n_age = 0;
    }else if(age>=36 && age<=55){
        n_age = 1;
    }else if(age>55){
        n_age=2;
    }else{
       n_age =3;
    }
     switch(n_age)
    {
        case 0:
            if(approvaljob(&Has_job[0])==1 && approvalhouse(&own_house[0])==1
            && approvalrating(&credit_rating[0])==1){
                printf("not approved");
            }else if(approvaljob(&Has_job[0])==1 && approvalhouse(&own_house[0])==1
            && approvalrating(&credit_rating[0])==2){
                printf("not approved");
            }else if(approvaljob(&Has_job[0])==0 && approvalhouse(&own_house[0])==1
            && approvalrating(&credit_rating[0])==2){
                printf("approved");
            } else if(approvaljob(&Has_job[0])==0 && approvalhouse(&own_house[0])==0
            && approvalrating(&credit_rating[0])==1){
                printf("approved");
            }else{
                printf("not approved");
            }
            break;

        case 1:
           if(approvaljob(&Has_job[0])==1 && approvalhouse(&own_house[0])==1
            && approvalrating(&credit_rating[0])==1){
                printf("not approved");
            }else if(approvaljob(&Has_job[0])==1 && approvalhouse(&own_house[0])==1
            && approvalrating(&credit_rating[0])==2){
                printf("not approved");
            }else if(approvaljob(&Has_job[0])==0 && approvalhouse(&own_house[0])==0
            && approvalrating(&credit_rating[0])==2){
                printf("approved");
            } else if(approvaljob(&Has_job[0])==1 && approvalhouse(&own_house[0])==0
            && approvalrating(&credit_rating[0])==3){
                printf("approved");
            }else{
                printf("not approved");
            }
            break;

        case 2:
            if(approvaljob(&Has_job[0])==1 && approvalhouse(&own_house[0])==0
            && approvalrating(&credit_rating[0])==3){
                printf("approved");
            }else if(approvaljob(&Has_job[0])==1 && approvalhouse(&own_house[0])==0
            && approvalrating(&credit_rating[0])==2){
                printf("approved");
            }else if(approvaljob(&Has_job[0])==0 && approvalhouse(&own_house[0])==1
            && approvalrating(&credit_rating[0])==2){
                printf("approved");
            } else if(approvaljob(&Has_job[0])==0 && approvalhouse(&own_house[0])==1
            && approvalrating(&credit_rating[0])==3){
                printf("approved");
            }else if(approvaljob(&Has_job[0])==1 && approvalhouse(&own_house[0])==1
            && approvalrating(&credit_rating[0])==1){
                printf("not approved");
            }else{
                printf("not approved");
            }
            break;
			
        default:
            printf("Error! Not eligible for credit card application");
    }
    
    return 0;
}
// functions
int approvaljob(char* Has_job){
   if(stringCmpi(Has_job,"y")==0){
       return 0;
   }
   return 1; 
}
int approvalhouse(char* own_house){
   if(stringCmpi(own_house,"y")==0){
       return 0;
   }
   return 1; 
}
int approvalrating(char* credit_rating){
   if(stringCmpi(credit_rating,"Fair")==0){
       return 1;
   }else if(stringCmpi(credit_rating,"Good")==0){
       return 2;
   }else if(stringCmpi(credit_rating,"Excellent")==0){
       return 3;
   }
   return 0; 
}

/// comparison functions
int stringCmpi (char *s1,char *s2)
{
    int i=0,diff=0;
    for(i=0; s1[i]!='\0'; i++)
    {
        if( toupper(s1[i])!=toupper(s2[i]) )
            return 1;           
    }
    return 0;
}
