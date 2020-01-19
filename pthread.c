#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
struct stu
{
  int num;
  int age;
};

void *prt(void *args)
{
   struct stu stu2;
   stu2 =(struct stu)(*((struct stu *)args));


//or


//struct stu *p
//p = (struct stu *)args;


   printf("num=%d\n",stu2.num);
   printf("age=%d\n",stu2.num);        
}

int main()
{
   pthread_t tid[5];
   int i ;
   int ret;
   struct stu stu1;
   stu1.num = 28;
   stu1.age = 22; 
   for(i=0;i<5;i++)
{
   ret = pthread_create(&tid[i],NULL,prt,&stu1);
   if(ret!=0)
{
	printf("create failure\n");
      	return -1;
}  
}
   for(i=0;i<5;++i)
{
   pthread_join(tid[i],NULL);
}

   return 0;
}
