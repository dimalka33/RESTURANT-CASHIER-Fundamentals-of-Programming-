#include <stdio.h>

void displayMessage(float cash,float total);

int main()
{


	float cash,total;

	displayMessage(cash,total);





}

void displayMessage(float cash,float total)
	{

	    int numItems;

	printf("Enter the number of items:");
	scanf("%d",&numItems);

	char items[numItems][50];

	int quantities[numItems];

	float prices[numItems];

	    FILE*fp;
	    fp=fopen("bill.txt","w");
	    for(int i=0 ; i<numItems ; i++)
	    {

            printf("Enter details for Item %d\n",i+1);

            printf("Enter Item Name: ");
            scanf("%s",items[i]);

            printf("Enter Quantity: ");
            scanf("%d",&quantities[i]);

            printf("Enter Price per Unit: ");
            scanf("%f",&prices[i]);

	    }
	    float itemtotal;

	fprintf(fp,"     __________**********ABC Restaurant**********__________\n" );

	fprintf(fp," Items              Quantity            Unit_Price            Total\n");
	fprintf(fp,"---------          ----------          ------------       ------------------\n");

	for(int i=0 ; i<numItems ;i++)
	{

		itemtotal=quantities[i] * prices[i];

		fprintf(fp," %s %15.2d\t\tRs %7.2f\t\tRs %.2f\n",items[i],quantities[i],prices[i],itemtotal);

		total=total+itemtotal;

	}

	fprintf(fp,"                                                              ------------\n");


	fprintf(fp,"                                                         Total= Rs %.2f\n",total);

	printf("                                                         Total= Rs %.2f\n",total);
	float balance;

		printf("                                                    Enter Cash= Rs ");
		scanf("%f",&cash);



	fprintf(fp,"                                                    Enter Cash= Rs%7.2f\n",cash);


	fprintf(fp,"                                                              ------------\n");
	printf("                                                               ------------\n");


		balance=cash-total;

		printf("                                                       Balance= Rs %.2f\n",balance);

		fprintf(fp,"                                                       Balance= Rs %.2f\n",balance);



	fprintf(fp,"              ______Thank You!Come Again!______\n");

	fclose(fp);


	}

