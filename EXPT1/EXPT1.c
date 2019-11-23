#include<stdio.h>
#include<stdlib.h>
void additem();
void deleteitem();
void updatebill();
void displaycart();

int stock[5][3]={{0,0,0},{1,12,100},{2,15,200},{3,17,150},{4,25,250}};
typedef struct{
     int code;
int quantity;
    float cost;
}cartitems;
cartitems c[10];    //array of structure
int inum=0;
float total=0;

int main()
{
int i,j,n,choice;
do{
printf("\n\nItem code\tQuantity\tPrice\n");
        for(i=1;i<5;i++)
        {
            for(j=0;j<3;j++)
printf("%d\t\t",stock[i][j]);
printf("\n");
        }
printf("\nPlease enter your choice:  ");
printf("\n\n1:Add item to cart\n2:Delete item from cart\n3:Display\n4:exit:");
scanf("%d",&choice);

    switch(choice)
    {
        case 1:additem();
            break;
        case 2:deleteitem();
            break;
        case 3:displaycart();
            break;
        default: exit(0);
    };
}while(1);
    return 0;
}
void additem()
{
printf("\nYou have called additem\n");
printf("\nEnter the code and quantity of the item to be added to your cart:");
scanf("%d %d",&c[inum].code,&c[inum].quantity);

    c[inum].cost=c[inum].quantity*stock[c[inum].code][2];

printf("\nThe item with code%d is added to the cast\n", c[inum].code);
printf("\nYour cart contains....\n");
printf("\nItem code\t quantity\tcost\n");
    printf("%d\t\t%d\t\t%0.2f",c[inum].code,c[inum].quantity,c[inum].cost);

    stock[c[inum].code][1]=stock[c[inum].code][1]-c[inum].quantity;
inum++;
updatebill();
    return;
}

void deleteitem()
{
printf("\nYour have called deleteitem()\n");
printf("\nLast item from your cart deleted\n");
inum--;

    stock[c[inum].code][1]=stock[c[inum].code][1]+c[inum].quantity;
updatebill();
    return;
}
void updatebill()
{
int i;
    total=0;
printf("\nYou have called updatebill\n");
printf("\nThere are %d items in your cart...\n\n",inum);

    for(i=0;i<inum;i++)
        total=total+c[i].cost;
    return;
}

void displaycart()
{
int i;
printf("\nYou have called displaycart()\n");
printf("\nThere are %d items in your cart...\n\n",inum);
printf("\nItemcode\tquantity\tamount\n");

    for(i=0;i<inum;i++)
printf("\n%d\t\t%d\t\t%5.2f",c[i].code,c[i].quantity,c[i].cost);
printf("\n\n\n\t\t\tGrand total is:%5.2f\n",total);
    return;
}
