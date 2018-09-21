#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MatrixSize 4000000
#define VectorSize 2000

long NUM_BUFFERS;
long *result;
long **buffers;
pthread_mutex_t *mutexes;

typedef struct 
{
	long param1;
	int param2; 
	long* param3;
	long* param4;
	int param5;
}param;

void *runner(void *param); /* the thread */

long *multiply(long *matA, long *matB);
long *readMatrix(char *filename);
long *getColumn(int col, long *matrix);
long *getRow(int row, long *matrix);
long dotProduct(long *vec1, long *vec2);
int getLock();
int releaseLock();
int saveResultMatrix(/*long *result*/);

int main(int argc, char* argv[])
{
	NUM_BUFFERS=atoi(argv[1]);
	/*long *completeMatrix;
	long *aColumn;
	long *aRow;
	long aDotProduct;*/
	result=malloc(MatrixSize*sizeof(long));
	mutexes=malloc(NUM_BUFFERS*sizeof(pthread_mutex_t));
	/*printf("check1\n");
	completeMatrix= readMatrix("matA.dat");
	aColumn= getColumn(0,completeMatrix);
	aRow= getRow(0,completeMatrix);
	aDotProduct= dotProduct(aColumn, aRow);
	printf("check2\n");*/
	multiply(readMatrix("matA.dat"), readMatrix("matB.dat"));
	return 0;
}

long *multiply(long *matA, long *matB)
{

	pthread_t tid[NUM_BUFFERS];
	pthread_attr_t attr; /* set of attributes for the thread */

	param parameters[NUM_BUFFERS];

	long i;
	int j=0;
	int lockID;
	/* get the default attributes */
	pthread_attr_init(&attr);
	


	for(i=0; i<MatrixSize; i++)
	{	
		lockID=getLock();	
		parameters[lockID].param1=i;
		parameters[lockID].param2=j;
		parameters[lockID].param3=matA;
		parameters[lockID].param4=matB;
		parameters[lockID].param5=lockID;

		/* create the thread */
		pthread_create(&tid[lockID],&attr,runner,(void *)&(parameters[lockID]));
		
		//printf("\n%d\n",tid[lockID]);
		if(!((i+1)%VectorSize))
		{
			j++;
		}
	}
	/* now wait for the thread to exit */

	for (i = 0; i < MatrixSize; i++) 
	{
		pthread_join(tid[i],NULL);
		//printf("%d\n",result[i]);
	}
	saveResultMatrix();
}
long *readMatrix(char *filename)
{
	FILE *matrixFile;
	matrixFile= fopen(filename, "r");
	unsigned char c;
	int i=0;
	long *acum;
	acum=malloc(MatrixSize*sizeof(long));
	while(/*!feof(matrixFile)*/i!=MatrixSize/**/)
	{
		c= fgetc(matrixFile);
		if((int)c != 10)
		{
			acum[i]= (acum[i]*10)+c-0x30;
		}
		else
		{
			//printf("%d \n", acum[i]);
			i++;
			acum[i]=0;
		}
	}
	fclose(matrixFile);
	return acum;
}
long *getColumn(int col, long *matrix)
{
	long *acum;
	acum= malloc(VectorSize*sizeof(long));
	long i=0;//(long)col;
	while(i<VectorSize)
	{
		acum[i]=matrix[i*VectorSize+(long)col];
		//printf("%d\n",acum[i]);
		i++;
	}
	return acum;
}
long *getRow(int row, long *matrix)
{
	long *acum;
	acum= malloc(VectorSize*sizeof(long));
	long init=((long)row)*VectorSize;
	long i=0;//init;
	while(i<VectorSize)
	{
		acum[i]=matrix[init+i];
		//printf("%d\n",acum[i]);
		i++;
	}
	return acum;

}
long dotProduct(long *vec1, long *vec2)
{

	long acum=0;
	int i;
	for(i=0;i<VectorSize;i++)
	{
		acum+=vec1[i]*vec2[i];
	}
	return acum;
}
int getLock()
{
	int i=0;
	while(pthread_mutex_trylock(&mutexes[i])!=0)
	{
		i++;
		if(i==NUM_BUFFERS)
		{
			i=0;
		}
	}	
	//printf("check1 %i\n", i);
	return i;
}
int releaseLock(int lock)
{
	return pthread_mutex_unlock(&mutexes[lock]);
}
int saveResultMatrix(/*long *result*/)
{
	FILE *resultFile;
	resultFile= fopen("result.dat", "w+");
	long i=0;
	while(/*!feof(matrixFile)*/i!=MatrixSize/**/)
	{
		fprintf(resultFile, "%d\n", result[i]);
		i++;
	}
	fclose(resultFile);
}

void *runner(void *params) 
{
	param *parameters= (param *) params;
	//int i, upper = atoi(param);
	//sum = 0;

	/*if (upper > 0) {
		for (i = 1; i <= upper; i++)
			sum += i;
	}*/		
	result[parameters->param1]=dotProduct(getRow(parameters->param2,parameters->param3),getColumn((parameters->param1)%VectorSize,parameters->param4));
	//printf("check1\n");
	releaseLock(parameters->param5);
	pthread_exit(0);
}
