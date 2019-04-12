#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define SIZE 10

int stringCmpi(char *s1,char *s2);
int stringCmp (char *s1,char *s2);
double agefunc(int age,double item_price);
double discountfunc(char discount_code[30],double item_price);
double discountpricefunc(char buyer_club_member[30],double item_price);

struct final{
    double discounted_price,total_saved,tax,price_w_tax,shipping_price,amount_due;
};

typedef struct final Struct;

Struct finalOutpout(char ship_country[20], char ship_province[20]
                    ,char ship_city[20], double item_price, double age_discount,
                    double discount_code_amount,double discount_price){
    Struct s;
    
    if((0 == stringCmpi(ship_city,"Toronto"))
       &&(0 == stringCmpi(ship_province,"Ontario"))
       &&(0 == stringCmpi(ship_country,"Canada"))){
        
        // discounted amount calculation
        s.discounted_price = item_price-age_discount-discount_price-discount_code_amount;
        s.total_saved = item_price - s.discounted_price;
        s.tax = s.discounted_price*13/100;
        s.price_w_tax = s.discounted_price+s.tax;
        s.shipping_price = 5 + s.price_w_tax*5/100;
        
    }else if((0 != stringCmpi(ship_city,"Toronto"))
             &&(0 == stringCmpi(ship_province,"Ontario"))
             &&(0 == stringCmpi(ship_country,"Canada"))){
        
        // discounted amount calculation
        s.discounted_price = item_price-age_discount-discount_price-discount_code_amount;
        s.total_saved = item_price - s.discounted_price;
        s.tax = s.discounted_price*13/100;
        s.price_w_tax = s.discounted_price+s.tax;
        s.shipping_price = 7 + s.price_w_tax*5/100;
        
    }else if((0 != stringCmpi(ship_city,"Toronto"))
             &&(0 != stringCmpi(ship_province,"Ontario"))
             &&(0 == stringCmpi(ship_country,"Canada"))){
        
        // discounted amount calculation
        s.discounted_price = item_price-age_discount-discount_price-discount_code_amount;
        s.total_saved = item_price - s.discounted_price;
        s.tax = s.discounted_price*13/100;
        s.price_w_tax = s.discounted_price+s.tax;
        s.shipping_price = 10 + s.price_w_tax*5/100;
        
    }else{
        // discounted amount calculation
        s.discounted_price = item_price-age_discount-discount_price-discount_code_amount;
        s.total_saved = item_price - s.discounted_price;
        s.tax = s.discounted_price*13/100;
        s.price_w_tax = s.discounted_price+s.tax;
        s.shipping_price = 15 + s.price_w_tax*5/100;
    }
    
    s.amount_due = s.price_w_tax+s.shipping_price;
    
    return s;
}


int main()
{
    //struct
    Struct result;
    
    // Variables for userinfos input
    double item_price = 0;
    int age,item_number;
    int k=0, i,j;
    
    char buyer_club_member[30],
    discount_code[30],
    ship_name[20], ship_country[20],ship_province[20]
    ,ship_city[20],ship_address[20],ship_postal_code[20];
    //Variables for calculation
    double discount_price = 0.0, discount_code_amount,sale_discount=0,
    age_discount;
    
    //arrays
    double items[SIZE*SIZE*SIZE];
    int sku[SIZE]={283,496,784,674,288,681,348,495,743,185};
    double price[SIZE]={3.45,7.89,6.50,22.98,16.47,33.25,12.35,15.00,14.99,71.60};
    char sale[SIZE][4]= {"No","No","No","No","No","Yes","No","No","Yes","No"};
    char desc[SIZE][28]= {"garden shears","work gloves","sun hat","watering hose","watering can",
        "hose nozzle","small rake","large rake","trowel","lawn mower"
    };
    int items_sku[SIZE*SIZE*SIZE];
    
    printf("Enter your age (0 to stop): ");
    scanf("%d",&age);
    
    while(age>0){
        getchar();
    printf("Are you a member of our Buyer's Club?: ");
    scanf("%[^\n]s", buyer_club_member);
    getchar();
    printf("Enter your discount code or <Enter> if you do not have one: ");
    scanf("%[^\n]s",discount_code);
    
        
        printf("Enter the item number (0 to stop): ");
        scanf("%d",&item_number);
        while(item_number!=0){
            for(i=0; i<SIZE; i++){
                if(sku[i]==item_number){
                    
                    items[k]=price[i];
                    items_sku[k] = sku[i];
                    //printf("items %.2lf name is %s and item\n", price[i],desc[i]);
                    k=k+1;
                    break;
                }else{
                    if(i>=9 && item_number!=sku[i]){
                        printf("Cannot find item %d\n", item_number);
                    }
                }
            }
            
            printf("Enter the item number (0 to stop): ");
            scanf("%d",&item_number);
        }
        /*for(int i=0;i<k;i++){
            printf("items %.2lf\n", items[i]);
        }*/
        getchar();
    printf("Enter the name of the person to ship to: ");
    scanf("%[^\n]s", ship_name);
    getchar();
    printf("Enter the country to which you want the item delivered: ");
    scanf("%[^\n]s", ship_country);
    getchar();
    printf("Enter the delivery province: ");
    scanf("%[^\n]s", ship_province);
    getchar();
    printf("Enter the delivery city: ");
    scanf("%[^\n]s", ship_city);
    getchar();
    printf("Enter the delivery street address: ");
    scanf("%[^\n]s", ship_address);
    getchar();
    printf("Enter the delivery postal code: ");
    scanf("%[^\n]s", ship_postal_code);
        for (i=0; i<k;i++){
            for (j=0; j<SIZE; j++) {
                if(items_sku[i] == sku[j]){
                    sale_discount += items[i];
                    if (0 == stringCmpi(sale[j],"Yes")) {
                        items[i]= items[i] - items[i]*10/100;
                    }
                }
                
            }
            item_price += items[i];
        }
        sale_discount = sale_discount-item_price;
//----------------------------------function age-----------------------------------
        age_discount = agefunc(age,item_price);
        
//----------------------------------function discount price----------------------------------
        discount_price = discountpricefunc(buyer_club_member,item_price);
    
//----------------------------------function discount code amount-----------------------------------
        discount_code_amount = discountfunc(discount_code,item_price);
    
        result=finalOutpout(ship_country, ship_province
                            ,ship_city, item_price,  age_discount,
                            discount_code_amount, discount_price);
    
    //Output results
    printf("--------------------------Sales ------------------\n");
    printf("Ship to:\n");
    printf("%10s%-30s\n","",ship_name);
    printf("%10s%-30s\n","",ship_address);
    printf("%10s%-30s\n","",ship_city);
    printf("%10s%-30s\n","",ship_province);
    printf("%10s%-30s\n","",ship_country);
    printf("%10s%-30s\n\n","",ship_postal_code);
        for (i=0; i<k;i++){
            for (j=0; j<SIZE; j++) {
                if(items_sku[i] == sku[j]){
                    if (0 == stringCmpi(sale[j],"Yes")) {
                        printf("%-24s%s%25.2lf\n",desc[j],"*",price[j]);
                    }else{
                        printf("%-25s%25.2lf\n",desc[j],price[j]);
                    }
                }
                
            }
        }
    printf("\n%-25s%25.2lf\n","Cost of Goods",item_price);
    printf("%-25s%25.2lf\n","Club Discount",discount_price);
    printf("%-25s%25.2lf\n","Discount Code",discount_code_amount);
    printf("%-25s%25.2lf\n","Age Discount",age_discount);
    printf("%-25s%25.2lf\n","On Sale Savings",sale_discount);
    printf("%-25s%25.2lf\n","Total Saved",result.total_saved);
    printf("%-25s%25.2lf\n","Discounted Price",result.discounted_price);
    printf("%-25s%25.2lf\n","Tax",result.tax);
    printf("%-25s%25.2lf\n","Price with Tax",result.price_w_tax);
    printf("%-25s%25.2lf\n","Shipping",result.shipping_price);
    printf("%-25s%25.2lf\n","Amount Due",result.amount_due);
        
        printf("Enter your age (0 to stop): ");
        scanf("%d",&age);
    
    }
    return 0;
}
int stringCmpi (char *s1,char *s2)
{
    int i=0;
    for(i=0; s1[i]!='\0'; i++)
    {
        if( toupper(s1[i])!=toupper(s2[i]) )
            return 1;
    }
    return 0;
}
int stringCmp (char *s1,char *s2)
{
    int i=0;
    for(i=0; s1[i]!='\0'; i++)
    {
        if(s1[i]!=s2[i])
            return 1;
    }
    return 0;
}

//// internal functions
double agefunc(int age,double item_price){
    double age_discount;
    if(age<18){
        age_discount  = item_price*15/100;
        
    }else if(age>65){
        age_discount  = item_price*10/100;
        
    }else{
        age_discount  = item_price*0;
        
    }
    return age_discount;
}
double discountfunc(char discount_code[30],double item_price){
    double discount;
    if(stringCmp(discount_code,"SAVE_WIN_19")==0){
        discount = (double)item_price *5/100;
    }else if(stringCmp(discount_code,"BDAY_SPECIAL")==0){
        discount = (double)item_price *7/100;
    }else{
        discount= (double)item_price *0;
    }
    
    
    return discount;
}
double discountpricefunc(char buyer_club_member[30],double item_price){
    double member_discount, discount=0;
    if(stringCmpi(buyer_club_member,"yes") == 0){
        member_discount =(float) 5/100;
        discount = item_price * member_discount;
    }
    return discount;
}