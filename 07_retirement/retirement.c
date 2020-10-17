#include <stdlib.h>
#include <stdio.h>

struct retire_info_t{
  int months; //number of months it is applicable to
  double contribution; //how many dollars are contributed (or spend if negative) from the account per month
  double rate_of_return; //rate of returns (assume to be "after inflation")
};

typedef struct retire_info_t retire_info;

double account_calculation (double contribution,
			 double rate_of_return,
			 double initial)
{
  double account_balance = initial;
  double interest_earned;
  interest_earned = account_balance*rate_of_return;
  account_balance = interest_earned+contribution+account_balance;
  return account_balance;
}

void retirement (int startAge, //months
		 double initial, //initial savings in dollars
		 retire_info working, //info about working
		 retire_info retired) //info about being retired
{
  double account_balance = initial;
  for (int i=0;i<working.months;i++){
    printf("Age %3d month %2d you have $%.2lf\n",startAge/12,startAge%12,account_balance);
    account_balance = account_calculation(working.contribution,working.rate_of_return,account_balance);
    startAge++;
  }
  for (int i=0;i<retired.months;i++){
    printf("Age %3d month %2d you have $%.2lf\n",startAge/12,startAge%12,account_balance);
    account_balance = account_calculation(retired.contribution,retired.rate_of_return,account_balance);
    startAge++;
  }
}

int main(void){
  retire_info working;
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045/12;

  retire_info retired;
  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01/12;

  retirement(327,21345,working,retired);
  
  return EXIT_SUCCESS;
}
