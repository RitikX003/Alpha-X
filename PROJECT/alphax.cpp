#include<iostream>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<fstream>
using namespace std;
int i,n;
ifstream fin;
ofstream fout;
fstream fio;
void display();
class stock
{
	char name[20],pass[15];
	float pr; int quan;

public:
	void get();
	void get2();
	void show();
    int stchk(char nm[30]);    
    void withd(int qty);
    void refil(int qty);
}s;
void stock::get()
{
	cin>>name>>pr>>quan;
}
void stock::get2()
{
	cin>>name>>quan;
}
void stock::show()
{
	
	cout<<"\n"<<name<<"\t\t\t"<<quan<<"\t\t\t"<<pr;
}
int stock::stchk(char nm[30])
{
	if(strcmp(nm,name)==0)
	 return 0;
	else 
	return 1;
}
void stock::withd(int qty)
{
	if(quan>=qty)
	{
		quan-=qty;
		cout<<"\n\nStock updated.\n";
		cout<<"\n\nTotal price to be paid:"<<pr*qty;
    }
	else 
	   cout<<"\n\nInsufficient stock";
	    getch();	
}
void stock::refil(int qty)
{	
		quan+=qty;
		cout<<"\n\nStock updated.";
	    getch();	
}
void add()
{
    system("cls");
	display();
	getch();
	system("cls");	
	cout<<"\nEnter the No. of Products that you want to add: ";
    cin>>n;
    if (n!=0)
    {
	int j,l,sum=0;
	fout.open("shop.dat",ios::binary|ios::app);
	for(i=0;i<n;i++)
	{
		cout<<"\n\nInput the Name, Price and the Quantity of item respectively\n\n";
	    s.get();
	    fout.write((char*)&s,sizeof(s));
        cout<<"\n\nitem updated";
		cin.get();
    }
    cout<<"\n\nStock Updated!!";
    fout.close();
    cin.get();
    system("cls");
    display();
}

	else
{

	fout.close();
	cin.get();
	system("cls");
	cout<<"\n\nNo items to be added";
}
}
void withdraw()
{
	system("cls");
	char temp[100];int qty;
	int i=0;
	long pos=0;
	display();
	cout<<"\n\nEnter the product's name: \n"<<endl;
	cin>>temp;
	cout<<"\n\nEnter quantity: \n"<<endl;
	cin>>qty;
	fio.open("shop.dat",ios::binary|ios::out|ios::in);
     while(fio)
     {
	    pos=fio.tellp();
	    fio.read((char*)&s,sizeof(s));
	    if(s.stchk(temp)==0)
	    {
		  
		  s.withd(qty);
		  fio.seekp(pos);
		  fio.write((char*)&s,sizeof(s));
		  i++;break;
	    }
     }
     
    
     if(i!=1)
       cout<<"\n\n!!Record not found!!";
     fio.close();
    cin.get();
    system("cls");
	 display(); 
	getch();
}
void display()
{
	int i=1;
	cout<<"\n==================================================================";
	cout<<"\n\n=================\tTHE STOCK ITEMS ARE\t==================";
	cout<<"\n\n==================================================================\n";
	cout<<"\n\nPARTICULARS\tSTOCK AVAILABLE\t\t\t PRICE";
	cout<<"\n\n============================================================\n";	
	 fin.open("shop.dat",ios::binary);
     while(!fin.eof())
     {
	  fin.read((char*)&s,sizeof(s));
	  if(!fin.eof())
	  {
	     if(fin.tellg()<0)
	     {	i=0; break;}
	     s.show();
	  }
     }
     if(i==0)
     {	cout<<"\n\n\t\t\t!!Empty record room!!";
	getch();
     }
     fin.close();
    
}
void refill()
{
	system("cls");
	char temp[100];int qty;
	int i=0;
	long pos=0;
	display();
	cout<<"\n\nEnter the products name \n"<<endl;
	cin>>temp;
	cout<<"\n\nEnter quantity: \n"<<endl;
	cin>>qty;
	fio.open("shop.dat",ios::binary|ios::out|ios::in);
     while(fio)
     {
	    pos=fio.tellp();
	    fio.read((char*)&s,sizeof(s));
	    if(s.stchk(temp)==0)
	    {
		  
		  s.refil(qty);
		  fio.seekp(pos);
		  fio.write((char*)&s,sizeof(s));
		  i++;break;
	    }
     }
     if(i!=1)
       cout<<"\n\n!!Record not found!!";
     fio.close();
    system("cls");
    cin.get();
	 display(); cin.get();
    
	
}
void remove()
{
	system("cls");	
	 int i=0;
     char temp[30];
     cout<<"\n\t\t\t\tDelete Record";
     cout<<"\n\nEnter the name of the product:";
     cin>>temp;
     fout.open("temp.dat",ios::binary);
     fin.open("shop.dat",ios::binary);
     while(!fin.eof())
     {
	  fin.read((char*)&s,sizeof(s));
	  if(!fin.eof())
	    if(s.stchk(temp)==0)
	    {
		  s.show();
		  cout<<"\n\n\t\tRecord deleted";
		  i++;
	    }
	    else
		  fout.write((char*)&s,sizeof(s));
     }
     if(i==0)
       cout<<"\n\n!!Record not found!!";
     fin.close();
     fout.close();
     remove("shop.dat");
     rename("temp.dat","shop.dat");
}
int main()
{
	char pass1[10],pass2[10];
	int i,j;
	cout<<"\n\n\n\n\n\n\n\n\n\n\n \t\t\t|============  WELCOME TO DEPARTMENTAL STORE MANAGEMENT ============|";
	getch();
	system("cls");
	cout<<"\n\t\t  WELCOME TO DEPARTMENTAL STORE MANAGEMENT \n";	
	cout<<"=============================================================";
	cout<<"\n\n\t\t   1. Dealer Menu\n\n\t\t   2. Customer Menu\n\n\t\t   3. Employee Menu";
	cout<<"\n\n=============================================================\n";
	cout<<"\n\nEnter Your Choice:";
	cin>>j;
	if(j==1)
	{
	
	system("cls");
	  system("cls");
    cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPlease enter the password: ";
	
	for(int z=0;z<6;z++)
	{
		pass1[z]=getch();
		system("cls");
		cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPlease enter the password: ";
		for(i=1;i<=(z+1);i++)
		{
			cout<<"*";
		}
	}
	if(strcmp(pass1,"alphax")==0)
	{
    system("cls");
	dealer:
	system("cls");
	cout<<"=================================================================";
	cout<<"\n\n\t\t\t    DEALER MENU\n1. Add new product\n2. Display stock\n3. Refill\n4. Remove an item\n5. Exit:";
	cout<<"\n\n\n==========================END OF MENU=============================";
	cout<<"\n\n Enter your Choice :\t";
	cin>>i;
	if(i==1)
	{
		add();getch();
	goto dealer;
	}

	else if(i==2)
	{
		system("cls");
	display();getch();goto dealer;
	}
	else if(i==3)
	{
		refill();goto dealer;
	}
	else if(i==4)
	{
		remove();getch();goto dealer;
	}
	else 
	{
		system("cls");
	getch();
	exit(0);
}
}
else
{
	cout<<"\n\n\nINPUT CORRECT PASSWORD!!!\n\n";
	getch();
	exit(0);
}
	}
	if(j==2)
	{
		custom:
	system("cls");
	cout<<"=================================================================";
	cout<<"\n\n\t\t\t    CUSTOMER MENU\n1. Purchase\n2. Display stock\n3. Exit:";
	cout<<"\n\n\n==========================END OF MENU=============================";
	cout<<"\n\n Enter your Choice :\t";
	cin>>i;
	
	
	
	if (i==1)
	{
	withdraw();getch();goto custom;
	}
	else if(i==2)
	{
		system("cls");
	display();getch();goto custom;
	}
	
	else 
	{
		system("cls");
	getch();
	exit(0);
}
	
}
if(j==3)

{
	system("cls");
	cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPlease enter the password: ";
	
	for(int z=0;z<6;z++)
	{
		pass2[z]=getch();
		system("cls");
		cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPlease enter the password : ";
		for(i=1;i<=(z+1);i++)
		{
			cout<<"*";
		}
	}
	if(strcmp(pass2,"alphax")==0)
	{
	empmenu:
	system("cls");
	cout<<"=================================================================";
	cout<<"\n\n\t\t\tEMPLOYEE MENU\n1. Display stock\n2. Refill\n3. Exit";
	cout<<"\n\n\n==========================END OF MENU=============================";
	cout<<"\n\n Enter your Choice :\t";
	cin>>i;
	if(i==1)
	{
		system("cls");
	display();
	getch();
	goto empmenu;
	}
	else if(i==2)
	{
		refill();
		goto empmenu;
	}
	else 
	{
		system("cls");
	cout<<"\n\n\n\t\t\tThank You!!";
	getch();
	exit(0);
   }
}
else
{
	cout<<"\n\nSorry!! Please Provide Valid Password..\n\n";
	getch();	
	exit(0);
}
	}	
	getch();	
}
