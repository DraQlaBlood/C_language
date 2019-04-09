
#include <stdio.h>
#include <string.h>

int stringCmpi(char *s1,char *s2);
int stringCmp (char *s1,char *s2);

int main()
{
    // Variables for userinfos input
    double item_price;
    int age;
    char buyer_club_member[30], 
            discount_code[30],
            ship_name[20], ship_country[20],ship_province[20]
            ,ship_city[20],ship_address[20],ship_postal_code[20];
    //Variables for calculation
    double discount_price, discount_code_amount,member_discount,
            age_discount,total_saved,discounted_price
            ,tax,price_w_tax,shipping_price,amount_due;
    
    printf("Enter the price of the item purchased: ");
    scanf("%lf", &item_price);
    printf("Enter your age: ");
    scanf("%d",&age);
    getchar();
    printf("Are you a member of our Buyer's Club?: ");
    scanf("%[^\n]s", buyer_club_member);
    getchar();
    printf("Enter your discount code or <Enter> if you do not have one: ");
    scanf("%[^\n]s",discount_code);
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
    
    
     if(age<18){
        age_discount  = item_price*15/100;  
        
    }else if(age>65){
         age_discount  = item_price*10/100;
       
    }else{
        age_discount  = item_price*0;
       
    }
    //calculation needed for Output
        if(stringCmpi(buyer_club_member,"yes") == 0){
            member_discount =(float) 5/100;
            discount_price = item_price * member_discount;
        }
        
        if(stringCmp(discount_code,"SAVE_WIN_19")==0){
            discount_code_amount = (double)item_price *5/100;
        }else if(stringCmp(discount_code,"BDAY_SPECIAL")==0){
            discount_code_amount = (double)item_price *7/100;
        }else{
            discount_code_amount = (double)item_price *0;
        }

     if((0 == stringCmpi(ship_province,"Toronto"))
            &&(0 == stringCmpi(ship_province,"Ontario"))
            &&(0 == stringCmpi(ship_country,"Canada"))){
                
            // discounted amount calculation
        discounted_price = item_price-age_discount-discount_price-discount_code_amount;
        total_saved = item_price - discounted_price;
        tax = discounted_price*13/100;
        price_w_tax = discounted_price+tax;
            shipping_price = 5 + price_w_tax*5/100;
            
        }else if((0 != stringCmpi(ship_province,"Toronto"))
            &&(0 == stringCmpi(ship_province,"Ontario"))
            &&(0 == stringCmpi(ship_country,"Canada"))){
                
            // discounted amount calculation
        discounted_price = item_price-age_discount-discount_price-discount_code_amount;
        total_saved = item_price - discounted_price;
        tax = discounted_price*13/100;
        price_w_tax = discounted_price+tax;
            shipping_price = 7 + price_w_tax*5/100;
            
        }else if((0 != stringCmpi(ship_province,"Toronto"))
            &&(0 != stringCmpi(ship_province,"Ontario"))
            &&(0 == stringCmpi(ship_country,"Canada"))){
            
            // discounted amount calculation
        discounted_price = item_price-age_discount-discount_price-discount_code_amount;
        total_saved = item_price - discounted_price;
        tax = discounted_price*13/100;
        price_w_tax = discounted_price+tax;
            shipping_price = 10 + price_w_tax*10/100;
            
        }else{
            // discounted amount calculation
        discounted_price = item_price-age_discount-discount_price-discount_code_amount;
        total_saved = item_price - discounted_price;
        tax = discounted_price*13/100;
        price_w_tax = discounted_price+tax;
            shipping_price = 15 + price_w_tax*15/100;
        }
   
        amount_due = price_w_tax+shipping_price;
    
    //Output results
    printf("------------------ Seneca Sales ------------------\n");
    printf("Ship to:\n");
    printf("%10s%-30s\n","",ship_name);
    printf("%10s%-30s\n","",ship_address);
    printf("%10s%-30s\n","",ship_city);
    printf("%10s%-30s\n","",ship_province);
    printf("%10s%-30s\n","",ship_country);
    printf("%10s%-30s\n\n","",ship_postal_code);
    printf("%-25s%25.2lf\n","Cost of Goods",item_price);
    printf("%-25s%25.2lf\n","Club Discount",discount_price);
    printf("%-25s%25.2lf\n","Discount Code",discount_code_amount);
    printf("%-25s%25.2lf\n","Age Discount",age_discount);
    printf("%-25s%25.2lf\n","Total Saved",total_saved);
    printf("%-25s%25.2lf\n","Discounted Price",discounted_price);
    printf("%-25s%25.2lf\n","Tax",tax);
    printf("%-25s%25.2lf\n","Price with Tax",price_w_tax);
    printf("%-25s%25.2lf\n","Shipping",shipping_price);
    printf("%-25s%25.2lf\n","Amount Due",amount_due);
    
    
    return 0;
}
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