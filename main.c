/*Simplest logic to find the Weekday of an input date (in correct format).

Example if the input date is

17-06-1900
then the output would be
Sunday

Similarly, if the input is

29-02-1900
then the output should be
Thursday

And, if the input is 
29-02-1901

Then it should treat it as 

Invalid Date (because 29th for Feb is not a valid date day for year 1901)

# Contact: P K Subudhi
# mailtopksubudhi@gmail.com
# WhatsApp: +91-8895174939
# Website: www.pksubudhi.com

*/
#include <stdio.h>

//Prototypes
int isLeapYear(int);
int isValidDate(int,int,int);

//Function to check if the input date is valid or not
//Valid Year Range is 1800 to 2999

int isValidDate(int dd, int mm, int yy)
{
	//Number of days in a calender year
	int mday[]={31,28,31,30,31,30,31,31,30,31,30,31};
	//Checking Valid Year
	if(yy<1800 || yy>2999)
	{
		return 0;
	}
	//Checking valid Month
	if(mm<1 || mm>12)
	{
		return 0;
	}
	//Checking if the year is Leap Year or not
	if(isLeapYear(yy))
	{
		//If the year is Leap Year then it sets 29 days in the month of Feb
		mday[1]=29;
	}
	//Checks Valid Date Day
	if(dd<1 || dd>mday[mm-1])
	{
		return 0;
	}
	return 1; //If all correct then return 1 as an indication for a valid Date
}
int isLeapYear(int yy)
{
	if(yy%400==0)//First it should check if the year is completely divisible by 400
	{
		return 1;
	}
	else
	{
		if(yy%100==0) //Then it should check if it is completely divisible by 100
		{
			return 1;
		}
		else
		{
			if(yy%4==0) //Otherwise check if it is divisible by 4
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
}
int dayCode(int dd, int mm, int yy)
{
	//Findout number of days since 01-01-1800 (which is out first day in calculation)-Wednesday
	int i, tot_day=0;
	
	//Number of days in a calender year
	int mday[]={31,28,31,30,31,30,31,31,30,31,30,31};
	for(i=1800;i<yy;i++)
	{
		if(isLeapYear(i))
		{
			tot_day+=366;
			mday[1]=29;
		}
		else
		{
			tot_day+=365;
		}
	}
	for(i=0;i<mm-1;i++)
	{
		tot_day+=mday[i];
	}
	tot_day+=dd;
	printf("\nTOTAL DAYS IS: %d %d\n\n",tot_day, tot_day%7);
	
	return (tot_day)%7;
	
	
}
// This function will return week day number from 0 to 6
int wd(int year, int month, int day) 
{
    int wday=0;
    wday=(day  + ((153 * (month + 12 * ((14 - month) / 12) - 3) + 2) / 5) \
        + (365 * (year + 4800 - ((14 - month) / 12)))              \
        + ((year + 4800 - ((14 - month) / 12)) / 4)                \
        - ((year + 4800 - ((14 - month) / 12)) / 100)              \
        + ((year + 4800 - ((14 - month) / 12)) / 400)              \
        - 32045                                                    \
      )%7;
     return wday;   
}
 
int main()
{
    int day,month,year;
    int wDayNo=0;
    //char dayNames[][15]={"Tuesday","Wednesday", "Thursday","Friday","Saturday","Sunday", "Monday"};
 	char dayNames[][15]={"Sunday", "Monday","Tuesday","Wednesday", "Thursday","Friday","Saturday"};
    //input date 
    printf("Input date (DD-MM-YYYY): ");
    scanf("%d-%d-%d",&day,&month,&year);
    
    //check date is correct or not
    if(isValidDate(day,month,year)==1){
        printf("Date is correct [%02d/%02d/%02d].\n",day,month,year);
        //get weekday number
        //wDayNo=dayCode(day,month,year);
        wDayNo=wd(year,month,day);
        //print weekday according to wDayNo
        printf("week day is: %s\n",dayNames[wDayNo]);
    }
    else
        printf("Date is in-correct.\n");        
    return 0;
}
