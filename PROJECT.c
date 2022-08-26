#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct item
{
	 char item_name[20];
	 float price;
	 int qnty;
};
struct order 
{
	 char customer[20];
	 char date[10];
	 int num_of_items;
	 struct item itm[20];
};

   void BillHead(char name[],char date[])
   {
   	 printf("\n\n\n\t\t\t\t\t\t*****TYRE PARTY*****");
   	 printf("\n\n    Date: %s",date);
   	 printf("\n    Invoice to: %s",name);
   	 printf("\n  --------------------------------------------------------------");
   	 printf("\n     ITEM\t\t\tQTY\t\t\tTOTAL");
   	 printf("\n  --------------------------------------------------------------");
   }
   void BillBody(char item[],int qty,float price)
   {
   	printf("\n     %s\t\t\t\t%d\t\t\t%.2f",item,qty,price*qty);
   	
   }
   void BillFooter(float price)
   {
   	 printf("\n  --------------------------------------------------------------");
   	 printf("\n     Sub total\t\t\t\t\t\t%.2f\n",price);
   	 printf("\n     Discount@20%\t\t\t\t\t%.2f\n",0.2*price);
   	 printf("\n                                                     ___________");
   	 printf("\n     Net total\t\t\t\t\t\t%.2f\n",price-(price*0.2));
   	 printf("\n     CGST@9%\t\t\t\t\t\t%.2f",0.09*price-(price*0.2));
   	 printf("\n     SGST@9%\t\t\t\t\t\t%.2f\n",0.09*price-(price*0.2)); 
   	 printf("\n  --------------------------------------------------------------");
   	 printf("\n     Grand total\t\t\t\t\t%.2f",2*(0.09*price-(price*0.2))+price-(price*0.2));
   	 printf("\n  --------------------------------------------------------------");
   }
void main()
{ int i,a,choice,count=0;
  char c,save,name[20]; 
  float total;
  FILE *fp;
  struct order o1,o2;
do
{
 printf("\t\t\t======================TYRE PARTY====================== ");
 printf("\n \n");
 printf("\tPlease select your preferred option:\n");
 printf("\t1.GENERATE INVOICE\n\t2.SHOW ALL INVOICES\n\t3.SEARCH INVOICES\n\t4.EXIT");
 printf("\n \n\tEnter your choice: ");
 scanf("%d",&choice);
 printf("\n\n\n");
 switch(choice)
 {
 	 case 1:
 	 	system("cls");
 	 	printf("\tPlease enter the name of the customer:\t");
 	 	fflush(stdin);
 	 	fgets(o1.customer,20,stdin);
 	 	strcpy(o1.date,__DATE__);
 	    printf("\tEnter the number of items \t");
 	    scanf("%d",&o1.num_of_items);
 	    for(i=1;i<=o1.num_of_items;i++)
 	    {   fflush(stdin);
 	        printf("\n\n");
 	    	printf("\tEnter item%d:\t\t\t",i); 
 	    	fgets(o1.itm[i].item_name,20,stdin);
 	    	printf("\n\tEnter price of the item \t");
 	    	scanf("%f",&o1.itm[i].price);
 	    	printf("\n\tEnter the quantity\t\t");
 	    	scanf("%d",&o1.itm[i].qnty);
 	    	total=total+o1.itm[i].price*o1.itm[i].qnty;
		 }
		 BillHead(o1.customer,o1.date);
		 for(i=1;i<=o1.num_of_items;i++)
		 {
		 BillBody(o1.itm[i].item_name,o1.itm[i].qnty,o1.itm[i].price);
       	}
       	BillFooter(total);
       	printf("\n\nDo you want to save this invoice[y/n]:\t");
       	fflush(stdin);
       	scanf("%c",&save);
       	if(save=='y'||save=='Y')
       	{
       	fp=fopen("invoice.txt","a+");
       	fwrite(&o1,sizeof(o1),1,fp);
       	printf("\nSucessfully saved!!!\n");
       	fclose(fp);
	    }
 	 	break;
 	case 2:
 		system("cls");
 	    printf("\t\t\t\t************YOUR PREVIOUS INVOICES************\t\t\t\n\n");
 	        fp=fopen("invoice.txt","r");
 	         while(fread(&o2,sizeof(o2),1,fp))
 	    { 
 	        BillHead(o2.customer,o2.date);
 	        for(i=1;i<=o2.num_of_items;i++)
		 {
		 BillBody(o2.itm[i].item_name,o2.itm[i].qnty,o2.itm[i].price);
		 total=total+o2.itm[i].price*o2.itm[i].qnty;
       	 }
       	BillFooter(total);
		 }
		 fclose(fp);
 	 	break;
 	case 3:
 		system("cls");
 		fflush(stdin);
 	 	printf("\n\n\tPLEASE ENTER THE NAME OF THE CUSTOMER:\t");
 	 	fgets(name,20,stdin);
 	 	printf("\n\n\t\t\t\t************INVOICE OF %s************\t\t\t\n\n",name);
 	        fp=fopen("invoice.txt","r");
 	         while(fread(&o2,sizeof(o2),1,fp))
 	    { if(!strcmp(o2.customer,name))
		 {
		    count=1;
 	        BillHead(o2.customer,o2.date);
 	        for(i=1;i<=o2.num_of_items;i++)
		 {
		 BillBody(o2.itm[i].item_name,o2.itm[i].qnty,o2.itm[i].price);
		 total=total+o2.itm[i].price*o2.itm[i].qnty;
       	 }
       	BillFooter(total);
		 }
	    }
	    if(count==0)
	    printf("\n\tSorry No Invoice Found ");
		 fclose(fp);
 	 	break;
	 case 4:
	    exit(0);
 	    break;
     default:printf("invalid choice");		  	
 } 
 fflush(stdin);
 printf("\n\n\t\t \nDO YOU WANT TO CONTINUE  [Y/N]:    ");
 scanf("%c",&c);
}while(c=='Y'||c=='y');
}

