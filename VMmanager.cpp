#include<iostream>
#include<fstream>
#define PGSZ 1024
#define FRSZ 1024
#define NOOFP 64
#define NOOFF 1024

using namespace std;


int pagetable[NOOFP];
int phyMem[NOOFF*FRSZ];

int main()
{
	
	memset(pagetable , -1 , sizeof(pagetable));
	memset(phyMem , -1 , sizeof(phyMem));
	
	fstream virtual_address;
	virtual_address.open("virtual-addresses.txt" , ios::in);
	
	FILE *backinstore;
	backinstore = fopen("backing-store.bin" , "rb");
	
	
    int page_fault = 0;
    int tot_record = 0;
    	
	if(!virtual_address)
	{
		cout << "No file found !" << endl;
	}
	else
	{
    	string line;
    	
		while(getline(virtual_address,line))
		{
			tot_record++;
			
			long addr = stoi(line);
			int pgno = addr>>10;
			int offset = addr - (pgno<<10);
			cout << "PageNo: " << pgno << " Offset: " << offset << " ";
			int val = 0;
			
			if(pagetable[pgno] == -1)
			{
				page_fault++;
				// page not found
				
				for(int i = 0 ; i < NOOFF ; i ++)
				{
					if(phyMem[i*PGSZ] == -1)
					{
						// ith frame is free
						// load data in ith frame
						int data;
						
						for(int j = 0 ; j < PGSZ ; j ++)
						{
							fseek(backinstore ,PGSZ*pgno + j ,SEEK_SET);
							fread(&data, 1 , 1 , backinstore);
							phyMem[i*PGSZ + j] = data;
						}
						
						pagetable[pgno] = i; 
						break;
					}
				}
				
				
			}
			
			int frno = pagetable[pgno];
			cout << " FrameNo: " << frno << " ";
			int phyadd = frno*PGSZ + offset;
			cout <<"Phyaddr : " << phyadd << " Value : "<<phyMem[phyadd] << endl;
			
		}
	}
	
	cout << "Page Rate : " << (double)page_fault*100/(double)tot_record << endl;

	return 0;
}
