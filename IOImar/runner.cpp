#include <cstdio>

#define REGSIZE 9

int reg[REGSIZE+10];

char buff1[100], buff2[100], buff3[100];

main()
{
  scanf("%s %s %s",buff1,buff2,buff3);
  for(int i=0; i<REGSIZE; i++)
    scanf("%d",&reg[i]);

  int scount = 0;
  int max_scount = 0;
  while(scanf("%s",buff1) == 1) {
    if(buff1[0] == 'P') {
      int r;
      scanf("%d",&r);
      r--;
      printf("%d\n",reg[r]);
      scount = 0;
    }
    if(buff1[0] == 'S') {
      int r1, r2;
      scanf("%d %d",&r1,&r2);
      r1--; r2--;
      reg[r2] = reg[r1] + 1;

      if(reg[r2] > 1000) {
        printf("Register %d overflow\n", r2+1);
        break;
      }
      
      scount++;
      if(scount > max_scount) {
        max_scount = scount;
      }
    }
  }
  printf("Max S Count = %d\n",max_scount);
}