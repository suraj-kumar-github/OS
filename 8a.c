#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int count1, count2 ,temp, tree[256][2],pids[100], ppids[100], count;

void pidDfs()
{

	int parent[256];
	int i, j, count =0;
	int pid;
	for(i=0;i<3;i++)
	{
		
		//printf("i: %d\n", i);
		if((pid =fork()) == 0)
		{
			tree[count][0]=getppid();
			tree[count++][1]=getpid();
			temp = count;
			pids[count1++] = getpid();
			ppids[count2++] = getppid();
		//	printf("[Child-%d]%d	from parent ID:%d\n", i,getpid(), getppid());
			//printf("|---%d	from parent ID:%d\n",getpid(), getppid());
			
			//sleep(2);
		}
		else if(pid<0){
			printf("Error in creation of new child process!\n");
		}
		else
		{
			wait(NULL);
			
			/*
			pids[count1++] = getpid();
			ppids[count2++] = getppid();
			printf("[Parent-%d]%d	from parent ID:%d\n",i, getpid(), getppid());
			sleep(2);
			*/
		}
	}
	wait(&status == pid);
	for(i=0;i<temp;i++)
	{
				printf("Parent: %d\t Child: %d\n",tree[i][0], tree[i][1] );	
	}
	
	for(i=0;i<temp;i++)
	{
		for(j=0;j<temp;j++)
		{
			printf("%d\n", tree[i][0] );
			if(tree[i][0] ==tree[j][0])
			{
				printf("|----%d\n", tree[j][1]);
			}
	}
}
}
void main()
{
	int i;
	pidDfs();
//	printf("-\n");
	
	/*
	for(i=0;i<count1;i++)
	{
		printf("%d\n", pids[i]);
	}
*/
	

}

