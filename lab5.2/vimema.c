#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define cant 1000
#define binz 65536
#define pgsize 256

unsigned int dirs[cant];
unsigned int tlb[16];
char backst[binz];
char fismem[binz];
unsigned char pgtab[pgsize];

//Wrong phisical address starts at direction 23


void readbin(void)
{
	int i;
	FILE *bin;
	bin = fopen("/home/oscreader/Documents/os-lab/lab5.2/OS-Labs/lab5.2/BACKING_STORE.bin","rb");
	fread(&backst,sizeof(backst),1,bin);
}

int getfrombs(int index)
{
	int num;
	num = backst[index];
	printf("Read val %d\n", num);
	return num;
}

void getNum(char *filename)
{
	int i;
	FILE *dir;
	dir = fopen(filename,"r");
	printf("%s\n", filename);
	if(dir)
	{
		for(i=0 ; i<cant ; i++)
		{
			fscanf(dir,"%d",&(dirs[i]));
			//printf("%d\n", dirs[i]);
		}
		fclose(dir);
	}
	printf("Scan finished\n");
}

int getVAdd(int line)
{
	int num;
	//printf("Real address %d ",dirs[line]);
	num = dirs[line];
	//printf("and got %d, Page number: %d, Offset: %d, in %d\n", dirs[line], num, num >> 8, num & 0b11111111, line);
	return num;
}



int main(void)
{
	int index0, index1, counter; 
	unsigned int vadd, padd;
	char flags;
	padd=0;
	readbin();//Store the backing store data.
	getNum("/home/oscreader/Documents/os-lab/lab5.2/OS-Labs/lab5.2/addresses.txt");//getting the addresses.
	counter=0;
	for(index0 = 0; index0 < cant; index0++)//we go through all addresses
	{
		flags=0;
		vadd = getVAdd(index0);//we get the current virtual address
		index1=0;
		do // We first check if it is in the TLB.
		{
			if((tlb[index1] >> 8) == (vadd >> 8))//if the data is in the TLB
			{
				flags |= 0b01;
				padd = ((tlb[index1] & 0b11111111) << 8) + (vadd & 0b11111111);//calculate the physical address.
			}
			else if (index1 ==15)//If wo have gotten to the end of the TLB
			{
				flags |= 0b11;//We set two flags, one to stop checking the TLB and another to check the the page table.
			}
			index1++;
		}while(!(flags & 0b01));
		index1=0;//recycle counters.
		while(flags & 0b10)//Now we check the Page table in case that the address was not in the TLB.
		{
			if(pgtab[index1] == (vadd >> 8))//If it is in the Page table.
			{
				flags = 0;
				padd = (index1 << 8) + (vadd & 0b11111111);//calculate the physical address.
			}
			else if (index1 >= pgsize)//If we have gotten to the end of the Page table.
			{
				flags = 0b100;//we turn off the first two flags to stop chacking in the Page table, additionally we turn on a flag to load a page from the Backing store.
			}
			index1++;
		}
		index1=0;//Recycle counters.
		if(flags & 0b100)//If the address did not match to neither any entry of the TLB nor  any one of the Page table.
		{
			flags=0;
			tlb[counter%16] = (vadd & 0b1111111100000000) + counter;//We update the TLB.
			pgtab[counter] = (vadd >> 8);//Update the Page table.
			for(index1 = 0; index1 < pgsize; index1++)//Load the needed page
			{
				fismem[(counter << 8)+index1] = backst[(vadd & 0b1111111100000000) + index1];
			}
			padd = (counter << 8) + (vadd & 0b11111111);//calculate the physical address.
			counter++;
		}
		printf("%d.- Virtual address: %d,Physical address: %d Value: %d\n",index0, vadd, padd, fismem[padd]);//Print the result.

}

