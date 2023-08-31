#include<stdio.h>
#include<stdlib.h>
#include<string.h>
  struct user
{
    char name[30];
    char userType[8];
    char username[35];
    char password[8];
};
struct product
{
    char name[50];
    float price;
    char category[12];
    char description[200];
    int sold;
    int id;
};
//
int sizeOfProducts=4;
struct product *products;
int numPeople = 3;
int sizeOfCart=2;
struct product *cart;
int cartItems=0;
int productCounts=0;
struct user *people;
int counts = 0;

void main()
{
    products = (struct product*)malloc(sizeOfProducts*sizeof(struct product));
    cart = (struct cart*)calloc(sizeOfCart,sizeof(struct product));
    people = (struct user*)calloc(numPeople,sizeof(struct user));
// Adding accounts
struct user s={"amit singh","admin","amit123@gmail.com","123Amit4"};
people[counts]=s;
counts++;
struct user s1={"sunny","customer","sunny@gmail.com","12345678"};
people[counts]=s1;
counts++;
struct user s3 = {"bhavesh kumar","customer","bhavesh@gmail.com","bhavesh1"};
people[counts] = s3;
counts++;
// Adding initial products like amazon basics
struct product p1 = {"Suit and Pant",29.99,"fashion","Especially for officers",0,productCounts+1};
products[productCounts] = p1;
productCounts++;
struct product p2 = {"Dragon Toy",1.29,"plastic","Especially for toddlers",0,productCounts+1};
products[productCounts] = p2;
productCounts++;
struct product p3 = {"3 tshirts",39.69,"fashion","3 at the price of one.",0,productCounts+1};
products[productCounts] = p3;
productCounts++;
// Showing menu to vendor or customer
showMenu();
// Freeing dynamically created memory
free(products);
free(cart);
free(people);
}

void showMenu()
{
    system("cls");
// FOR ADDING VERTICAL SPACE
 for(int i=0;i<5;i++)
    printf("\n");
// FOR ADDING HORIZONTAL SPACE
 for(int k=0;k<40;k++)
    printf(" ");
//PRINTING STARTS
 printf("WELCOME TO ECOMMERCE PLATFORM\n\n\n");
 printf(" - ENTER 1 FOR CUSTOMER");
 for(int k=0;k<72;k++)
    printf(" ");
printf("- ENTER 2 FOR MERCHANT   \n");
int userInput;
   // FOR ADDING VERTICAL SPACE
 for(int i=0;i<5;i++)
    printf("\n");
// FOR ADDING HORIZONTAL SPACE
 for(int k=0;k<40;k++)
    printf(" ");
 printf("Valid Ids \n\n");
// FOR ADDING HORIZONTAL SPACE
 for(int k=0;k<20;k++)
    printf(" ");
printf("For Merchant");
printf("\n\n - email:amit123@gmail.com \n\n - password:123Amit4 \n\n");
 for(int k=0;k<20;k++)
    printf(" ");
printf("For Customer");
printf("\n\n - email:sunny@gmail.com \n\n - password:12345678 \n\n");

printf("   ENTER : ");
scanf("%d",&userInput);
int status=-1;
  while(status!=1)
   {
    status = showForm(userInput);
   }

}
int showForm(int input)
{
    char inputUsername[30];
    system("cls");
    for(int i=0;i<5;i++)
    printf("\n");
    for(int i=0;i<50;i++)
    printf(" ");
    printf("LOGIN FORM\n\n");
    printf("   Enter you email address : ");
    scanf("%s",&inputUsername[0]);
     int i;
     for(i=0;i<counts;i++)
     {
        struct user u=people[i];
       if(strcmp(u.username,inputUsername)==0)
       {
           char password[8];
            printf("\n   Enter you password : ");
            fflush(stdin);
            scanf("%s",&password[0]);
            char pass[8];
            printf("%s",pass);
            if(strcmp(password,u.password)==0)
             {
                if(strcmp(strlwr(u.userType),"admin")==0)
                     showMerchantMenu(u);
                else
                     showCustomerMenu(u,products,productCounts);
                return 1;
             } else
                {
                    printf("\n  ENTERED PASSWORD IS WRONG \n   Press Any Key");
                    getch();
                    return 0;
                }
       }
    }
    if(i==counts)
    {
        printf(" - NO ACCOUNT WAS FOUND \n   press any key");
        getch();
        return 0;
    }
}
void showCustomerMenu(struct user u,struct product *arr,int len)
{
    system("cls");
 // FOR ADDING VERTICAL SPACE
 for(int i=0;i<5;i++)
    printf("\n");

    printf("       Welcome Back %s ",strupr(u.name));
    for(int i=0;i<5;i++)
        printf("\n");
   for(int i=0;i<25;i++)
        printf("  ");
    printf("CUSTOMER ACCOUNT");
    printf("\n\n\n - ENTER 1 FOR SORTING PRODUCT BY CATEGORY ");
    for(int k=0;k<40;k++)
    printf(" ");
    printf("- ENTER 2 FOR ADDING ITEM TO CART   \n");
    printf("\n - ENTER 3 FOR SIGN OUT");
    for(int k=0;k<60;k++)
    printf(" ");
    printf("- ENTER 4 FOR CHECKING KART ITEMS");
    printf("\n\n - ENTER 5  TO CHECKOUT");
    for(int k=0;k<60;k++)
    printf(" ");
    printf("- ENTER 6 TO CLEAR CART   \n");
    printf("\n\n\n - Quantity : %d",cartItems);
    showProducts(arr,productCounts);
    printf("\n\n   ENTER : ");
    int input;
    scanf("%d",&input);
    if(input==1)
    {
        char category[20];
        printf("\n\n - Enter Your Preferred Category : ");
        scanf("%s",&category);
        sortProductsByCategory(category,u);

    }
    if(input==2)
        addToCart(u,arr,len);
    if(input==3)
    {
        free(cart);
        cart = (struct product*)calloc(sizeOfCart,sizeof(struct product));
        showMenu();
    }
    if(input==4)
    {
        showProducts(cart,cartItems);
        printf("\n\n - press Any Key ");
            getch();
        showCustomerMenu(u,arr,len);
    }

    if(input == 5)
    {
        checkout();
    }
    if(input==6)
    {
        free(cart);
        cart=(struct product*)calloc(sizeOfCart,sizeof(struct product));
        cartItems=0;
        printf("\n - Cart Cleared\n - Press Any Key  ");
        getch();
        showCustomerMenu(u,arr,len);
    }
}

void showProducts(struct product *arr,int len)
{
    for(int i=0;i<5;i++)
        printf("\n");
    if(len==0)
    {
        printf(" - No Products To Show  ");
    } else
    for(int i=0;i<len;i++)
    if(strlen((arr+i)->name)>0)
    {

        printf("    %d. %s\n",(arr+i)->id,(arr+i)->name);
        printf("    category: %s\n",(arr+i)->category);
        printf("    price: %f$\n",(arr+i)->price);
        printf("    units sold : %d\n",(arr+i)->sold);
        printf("    description: %s\n",(arr+i)->description);
        printf("\n\n");
    }
}
void addToCart(struct user u,struct product *arr,int len)
{
    int id;
    if(cartItems>sizeOfCart/2)
    {
        sizeOfCart*=sizeOfCart;
        cart=realloc(cart,sizeOfCart*sizeof(struct product));
    }
    printf("\n\n - Enter The ID Of Product : ");
    scanf("%d",&id);
    int i;
    for(i=0;i<productCounts;i++)
        if(products[i].id==id)
        {
            cart[cartItems]=products[i];
            cartItems++;
            printf("\n\n - Item Added To Cart \n - Press Any Key");
            getch();
            showCustomerMenu(u,arr,cartItems);
            break;
        }
        if(i==productCounts){
            printf("Enter a valid id for product");
        addToCart(u,arr,len);
        }
}
sortProductsByCategory(char category[20],struct user u)
{
    int c;
   char categories[4][20] = {"fashion","plastic","electronic","reading"};
   for( c=0;c<4;c++)
   {
       if(strcmp(strlwr(category),categories[c])==0)
       {
           struct product productsSorted[50];
           int len=0;
           for(int p=0;p<productCounts;p++)
               if(strcmp(products[p].category,categories[c])==0)
               {
                  productsSorted[p]=products[p];
                  len++;
               }
            showCustomerMenu(u,productsSorted,len);
       }
   }
   //PRODUCT NOT FOUND
   if(c==4)
   {
    printf("\n\n - THE CATEGORY ENTERED IS WRONG CHOOSE FROM THE FOLLWING \n\n - %s/%s/%s/%s",categories[0],categories[1],categories[2],categories[3]);
    printf("\n\n PRESS ANY KEY");
    getch();
    showCustomerMenu(u,products,productCounts);
   }
}
void checkout()
{
    for(int i=0;i<5;i++)
        printf("\n");
   for(int i=0;i<25;i++)
        printf("  ");
    printf("BILLING AND DETAILS\n");
    if(cartItems==0)
        printf("No Items Are Added In The Cart");
     else
    {
    float total=0;
    for(int i=0;i<cartItems;i++)
    {
        struct product p = cart[i];
        printf(" - %s  =  %f$\n",p.name,p.price);
        total+=p.price;
    }
    printf(" - Platform Fee  =  0.25$\n");
    total+=0.25;
    printf(" - total  =  %f\n\n\n\n\n",total);
    }

    free(products);
    free(cart);
     exit(0);
}

void showMerchantMenu(struct user u)
{
    system("cls");
 // FOR ADDING VERTICAL SPACE
 for(int i=0;i<5;i++)
    printf("\n");
    printf("       Welcome Back %s ",strupr(u.name));
    for(int i=0;i<5;i++)
    printf("\n");
    for(int i=0;i<25;i++)
        printf("  ");
    printf("MERCHANT ACCOUNT");
    printf("\n\n\n - ENTER 1 FOR PRODUCT LISTING");
    for(int k=0;k<55;k++)
    printf(" ");
    printf("- ENTER 2 FOR DELETING A LISTING   \n");
     printf("\n\n - ENTER 3 FOR SIGN OUT");
      for(int k=0;k<60;k++)
    printf(" ");
    printf("- ENTER 4 FOR showing all products   \n");
    printf("\n\n   ENTER : ");
    int input;
    scanf("%d",&input);
    if(input==1)
        addProduct(u);
    if(input==2)
        deleteProduct(u);
    if(input==3)
        showMenu();
    if(input==4)
    {
     showProducts(products,productCounts);
     printf("\n - Press Any Key");
     getch();
     showMerchantMenu(u);
    }
}
void addProduct(struct user u)
{
    if(productCounts>sizeOfProducts/2)
    {
        sizeOfProducts*=2;
        products=realloc(products,sizeOfProducts*sizeof(struct product));
    }
    struct product p;
    system("cls");
    for(int i=0;i<5;i++)
        printf("\n");
    for(int i=0;i<25;i++)
        printf("  ");
    printf("PRODUCT LISTING");
    printf("\n\n - ENTER THE TITLE OF PRODUCT : ");
    fflush(stdin);
    gets(p.name);
    fflush(stdin);
    int  categoryRight = 0;
     do
    {
     char categories[4][20] = {"fashion","plastic","electronic","reading"};
     printf("\n\n - FASHION/ELECTRONIC/READING/PLASTIC\n - ENTER THE CATEGORY OF PRODUCT : ");
     gets(p.category);
     // check if category is correct
     int i;
     for( i=0;i<4;i++)
     {
          if(strcmp(categories[i],strlwr(p.category))==0)
          {
            categoryRight=1;
            break;
          }
      }
      if(i==4)
        printf("\n\n - WRONG CATEGORY ENTERED");
     } while(categoryRight==0);
    fflush(stdin);
    printf("\n\n - ENTER THE DESCRIPTION OF PRODUCT : ");
    gets(p.description);
    printf("\n\n - ENTER THE PRICE OF PRODUCT in (X$ format) : ");
    scanf("%f$",&p.price);
    p.id=productCounts+1;
    printf("\n\n - THE ID OF %s IS %d.PLEASE MEMORIZE IT OR NOTE IT DOWN  AS IT IS ONLY DISPLAYED ONCE.",p.name,p.id);
    p.sold=0;
    *(products+productCounts++)=p;
    printf("\n - PRODUCT ADDED SUCCESSFULLY \n PRESS ANY KEY");
    getch();
    showMerchantMenu(u);
}
void deleteProduct(struct user u)
{
    int id;
   system("cls");
    for(int i=0;i<5;i++)
        printf("\n");
    for(int i=0;i<25;i++)
        printf("  ");
    printf("PRODUCT DELETION");
    printf("\n\n - ENTER THE ID OF PRODUCT : ");
    scanf("%d",&id);
    int k;
    for(k=0;k<productCounts;k++)
    {
        struct product p = products[k];
        if(p.id==id)
        {
            for(int j=k;j<=productCounts;j++)
            {
                products[j] = products[j+1];
            }
             printf("\n\n - SUCCESSFULLY DELETED %s",p.name);
             productCounts--;
             break;
        }
    }
    if(k>productCounts)
        printf("\n - No product with ID %d was found",id);
    printf("\n   Press Any Key");
    getch();
    showMerchantMenu(u);
}


