#include <stdio.h>
int main(){
int a[3][3] ={1,2,3, 4,5,6,7,8,9};
int b[3][3] ={0,0,0,0,0,0,0,0,0};
int i,j,c1,c2,c3;
for (i = 0; i < 3; ++i)
for ( j = 0; j<3; ++j)
*(*(b+j)+i)= a[i][j];
c1=*(b[0]+0);
c2=*(b[1]+1);
c3=*(b[2]+2);
printf("%d %d %d \n",c1,c2,c3);

return 0;
}