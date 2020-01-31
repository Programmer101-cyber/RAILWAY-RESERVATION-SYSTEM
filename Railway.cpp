//---------------------------------------header file start-------------------------------------------
#include<iostream>
#include<cstdio>
#include<fstream>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<string.h>

using namespace std;
//---------------------------------------user define function start----------------------------------
void pp1();
void pp2();
void d();

void admin();
void password();
void addtrain();
void dlttrain();
void viewtrain();
void passkey();

void viewticket();							//LEFT and Pretty Printing LEFT
void bookticket();
void cancelticket();
//-----------------------------------------struture train---------------------------------------------
struct train
{
	char num[5];
	char s,name[20],dep[20],dept[4],des[20],dest[4];
	char HA1[3],HA1P[5],A1[3],A1P[5],B1[3],B1P[5];
}t;
//-----------------------------------------structure passenger----------------------------------------
struct passenger
{
	char pname[20],page[2],psex,pb[3],pseat[3];
}p[50];
//---------------------------------------Global Variables---------------------------------------------
int i,j;
//---------------------------------------display 1----------------------------------------------------
inline void pp1()
{
	cout<<("\n\n\n\n\t\t\t\t\t\t\t ======================================================\n");
	cout<<("\t\t\t\t\t\t\t ============ RAILWAY  RESERVATION  SYSTEM ============\n");
	cout<<("\t\t\t\t\t\t\t ======================================================\n");							
}
//---------------------------------------display 2----------------------------------------------------
inline void pp2()
{
	cout<<("\n\n\n\n\t\t\t\t\t\t\t ::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    cout<<("\t\t\t\t\t\t\t :::::::::::: RAILWAY  RESERVATION  SYSTEM ::::::::::::\n");
	cout<<("\t\t\t\t\t\t\t ::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
}
//---------------------------------------display 3----------------------------------------------------
inline void d()
{
	cout<<("\n\n\n\n\n\t\t\t\t\t\t\t\t\t    INCORRECT  CHOICE\n");
	cout<<("\n\t\t\t\t\t\t\t\t\t  PRESS ANY TO CONTINUE\n");
	getch();
	system("cls");
}
//-----------------------------------------arranger---------------------------------------------------
inline void arranger(char *s)
{
	if(s[0]!=0)
		while(s[2]==0)
		{
			s[2]=s[1];
			s[1]=s[0];
			s[0]='0';
		}
}
//---------------------------------------Seat Recorder------------------------------------------------
void seater(char *seat)
{
	if(seat[2]=='0'||seat[2]=='C')
	{
		if(seat[1]=='0'||seat[1]=='A')
		{
			if(seat[0]=='0'||seat[0]=='R')
				strcpy(seat,"RAC");
			else
			{
				seat[2]='9';
				seat[1]='9';
				--seat[0];
			}
		}
		else
		{
			seat[2]='9';
			--seat[1];
		}
	}
	else
		--seat[2];
}
//---------------------------------------main function start------------------------------------------
int main()
{
	char ch;
	system("cls");
	srand(time(0));
	time_t currentTime;
	time(&currentTime);
	cout<<ctime(&currentTime);
	pp2();
	cout<<("\n\n\n\t\t\t\t\t\t\t\t  <<<<<<<<< WELCOME  USERS >>>>>>>>>\n");
	cout<<("\n\t\t\t\t\t\t\t\t\t\t MENU");
	cout<<("\n\t\t\t\t\t\t\t\t\t       ________\n\n");
	cout<<("\n\t\t\t\t\t\t\t [1] ADMIN");
	cout<<("\n\t\t\t\t\t\t\t [2] BOOK TICKET");
	cout<<("\n\t\t\t\t\t\t\t [3] CANCEL TICKET");
	cout<<("\n\t\t\t\t\t\t\t [4] EXIT\n");
	cout<<("\n\n\n\t\t\t\t\t\t\t ENTER YOUR CHOICE: ");
	ch=getch();
	cout<<ch<<"\n";
	switch(ch)
	{
		case '1':
			password();
			break;
		case '2':
			bookticket();
			break;
		case '3':
			cancelticket();
			break;
		case '4':
			system("cls");
			pp2();
			cout<<("\n\n\t\t\t\t\t\t\t\t\t     BROUGHT TO YOU\n\n");
			cout<<("\t\t\t\t\t\t\t\t\t\t   By\n\n");
			cout<<("\t\t\t\t\t\t\t\t      ~ ANCHIT | TUHIN | SHREYAN ~\n");
			getch();
			exit(0);
			break;
		default:
			system("cls");
			pp1();
			d();
			main();
	}
	return 0;
}
//---------------------------------------book ticket function-----------------------------------------
void bookticket()
{
	int pn;
	bool c=false,x;
	char pnr[5],usern[20],sex,phone[10];
	char d[6],n[5];
	char st[3];
	
	system("cls");
	time_t currentTime;
	time(&currentTime);
	
	cout<<ctime(&currentTime)<<"\b";
	pp1();
	viewtrain();
	cout<<"\n\n\t\t\t\t\t\t\t\t    Enter Travelling Details\n";
	cout<<"\t\t\t\t\t\t\t\t      Date(ddmmyy): ";
	gets(d);
	
	ifstream fi;
	fi.open("Train.txt",ios::in|ios::binary);
	if(fi.seekg(0,ios::end),fi.tellg()==0)
	{
		cout<<"\n\n\t\t\t\t\t\t\t\t\t  Trains Not Available";
		getch();
		main();
	}
	else
	{
		fi.seekg(0,ios::beg);
		cout<<"\t\t\t\t\t\t\t\t      Train Number: ";
		gets(n);
		while(!fi.eof())
		{
			fi.read((char*)&t,sizeof(train));
			if(fi.eof())
				break;
			if(n[0]==t.num[0]&&n[1]==t.num[1]&&n[2]==t.num[2]&&n[3]==t.num[3]&&n[4]==t.num[4])
			{
				c=true;
				break;
			}
			fi.seekg(1,ios::cur);
		}
		if(c!=true)
		{
			cout<<"\nTrain Not Found";
			cout<<"\nPress Enter to Try Again:";
			if(getch()==13)
				bookticket();
			else
				main();
		}
	}
	if(c==true)
	{
		ofstream f;
		f.open("Passenger.txt",ios::app);
		
		cout<<"\n\n\t\t\t\t\t\t\t\t     Enter Personel Details\n\t\t\t\t\t\t\t\t      Name: ";
		gets(usern);
		do
		{
			cout<<"\n\t\t\t\t\t\t\t\t      M -Male\t F- Female\t O- Others\n\t\t\t\t\t\t\t\t      Sex: ";
			cin>>sex;
			if(sex!='M'&&sex!='F'&&sex!='O')
				cout<<"Invalid Input\n";
		}while(sex!='M'&&sex!='F'&&sex!='O');
		do
		{
			x=true;
			cout<<"\n\t\t\t\t\t\t\t\t      Enter Ten Digit Mobile Number: ";
			cin>>phone;
			for(i=0;i<10;i++)
				if(!(phone[i]>47&&phone[i]<58))
				{
					cout<<"\nInvalid Input";
					x=false;
					break;
				}
		}while(x==false);
		do
		{
			cout<<"\n\t\t\t\t\t\t\t\t      Number of Passengers:";
			cin>>pn;
			if(pn>20)
				cout<<"\n\n\t\t\t\t\t\t\t\t      Maximum 20 tickets can be Booked per User";
		}while(pn>20);
		int b[pn];
		cout<<"\n\t\t\t\t\t\t\t\t    Enter Passenger Details";
		for(i=0;i<pn;i++)
		{
			cout<<"\n\t\t\t\t\t\t\t\t      "<<i+1<<".Passenger";
			cout<<"\n\t\t\t\t\t\t\t\t      Name: ";
			cin>>p[i].pname;
			cout<<"\n\t\t\t\t\t\t\t\t      Age: ";
			cin>>p[i].page;
			do
			{
				cout<<"\n\t\t\t\t\t\t\t\t      M -Male\t F- Female\t O- Others\n\t\t\t\t\t\t\t\t      Sex: ";
				cin>>p[i].psex;
				if(p[i].psex!='M'&&p[i].psex!='F'&&p[i].psex!='O')
					cout<<"\n\t\t\t\t\t\t\t\t      Invalid Input\n";
			}while(p[i].psex!='M'&&p[i].psex!='F'&&p[i].psex!='O');
			do
			{	
				cout<<"\t\t\t\t\t\t\t\t      Tier:\n\t\t\t\t\t\t\t\t      1:AC1\n\t\t\t\t\t\t\t\t      2.AC2\n\t\t\t\t\t\t\t\t      3.SL\n";
				cin>>b[i];
				if(b[i]==1)
					strcpy(p[i].pb,"AC1");
				else if(b[i]==2)
					strcpy(p[i].pb,"AC2");
				else if(b[i]==3)
					strcpy(p[i].pb,"SL");
				else
				{
					cout<<"\n\n\t\t\t\t\t\t\t\t      Wrong Choice";
					b[i]=4;
				}
			}while(b[i]==4);
		}
		
		cout<<"\n\n\t\t\t\t\t\t\t\t  Press Enter To Confirm Ticket";
		if(getch()==13)
		{
			ofstream fo;
			fo.open("t1.txt",ios::out);
			fi.seekg(0,ios::beg);
			while(!fi.eof())
			{
				fi.read((char*)&t,sizeof(train));
				if(fi.eof())
					break;
				{
					if(!((strcmp(n,t.name)!=0)&&(n[0]!=t.num[0])))
						for(i=0;i<pn;i++)
						{
							if(b[i]==1)
							{
								strcpy(st,t.HA1);
								seater(t.HA1);
							}
							else if(b[i]==2)
							{
								strcpy(st,t.A1);
								seater(t.A1);
							}
							else
							{
								strcpy(st,t.B1);
								seater(t.B1);
							}
							p[i].pseat[0]=st[0];
							p[i].pseat[1]=st[1];
							p[i].pseat[2]=st[2];
						}
					fo.write((char*)&t,sizeof(train));
					fo.put(13);
				}
				fi.seekg(1,ios::cur);
			}
			fi.close();
			fo.close();
			remove("Train.txt");
			rename("t1.txt","Train.txt");
			
			int pnrl=(rand()+11111)%1000000;
			for(i=0;i<5;i++)
			{
				pnr[i]=(char)((pnrl%10)+48);
				pnrl/=10;
			}
			f<<"@"<<n<<pnr<<"\n";
			f<<d[0]<<d[1]<<"."<<d[2]<<d[3]<<"."<<d[4]<<d[5]<<"\n";
			f<<usern<<"\n"<<sex<<"\n"<<phone<<"\n";
			for(i=0;i<pn;i++)
			{
				f.write((char*)&p[i],sizeof(passenger));
				f.put(13);
			}
			f<<"\n\n";
			f.close();
			
			cout<<"\n\t\t\t\t\t\t\t\t\tPNR Number: "<<n<<pnr;
		}
		else
			cout<<"\n\n\t\t\t\t\t\t\t\t        Ticket Cancelled";
		getch();
		exit(0);
	}
	getch();
}
//---------------------------------------cancel ticket function---------------------------------------
void cancelticket()
{
	bool found=false;
	char pnr[10],test[10],c;
	system("cls");
	time_t currentTime;
	time(&currentTime);
	cout<<ctime(&currentTime)<<"\b";
	pp1();
	cout<<"\n\n\t\t\t\t\t\t\t\t      Enter Details:";
	cout<<"\n\t\t\t\t\t\t\t\t      PNR: ";
	gets(pnr);
	
	ifstream fi;
	fi.open("Passenger.txt",ios::in|ios::binary);
	ofstream fo;
	fo.open("t1.txt",ios::out);
	if(fi.seekg(0,ios::end),fi.tellg()==0)
		cout<<"\nTicket not Availaible";
	else
	{
		fi.seekg(0,ios::beg);
		while(!fi.eof())
		{
			fi.get(c);
			if(fi.eof())
				break;
			if(c=='@')
			{
				fi.read(test,10);
				if(strcmp(pnr,test)==0)
				{
					cout<<"Press Enter To Cancel Ticket";
					if(getch()==13)
						found=true;
					else
						goto cancel;
					do
					{
						fi.get(c);
						if(fi.eof())
							break;
					}while(c!='@');
				}
				else
					fi.seekg(-10,ios::cur);
			}
			fo<<c;
		}
		if(found==false)
			cout<<"\nTicket not Available";
	}
	cancel:
	fi.close();
	fo.close();
	if(found==false)
		remove("t1.txt");
	else
	{
		remove("Passenger.txt");
		rename("t1.txt","Passenger.txt");
	}
	getch();
	main();
}
//-------------------------------------admin portal function------------------------------------------
void admin()
{
	char ch;
	system("cls");
	pp1();
	cout<<("\n\n\t\t\t\t\t\t\t    <<<<<<<<<<<<<< WELCOME USER ADMIN >>>>>>>>>>>>>>\n\n\n");
	cout<<("\t\t\t\t\t\t\t\t  ||                                ||\n");
	cout<<("\t\t\t\t\t\t\t\t  ||      CHOOSE YOUR OPERATION     ||\n");
	cout<<("\t\t\t\t\t\t\t\t  ||--------------------------------||\n");
	cout<<("\t\t\t\t\t\t\t\t  ||      [1] ADD TRAIN             ||\n");
	cout<<("\t\t\t\t\t\t\t\t  ||      [2] DELETE TRAIN          ||\n");
	cout<<("\t\t\t\t\t\t\t\t  ||      [3] VIEW TRAIN            ||\n");
	cout<<("\t\t\t\t\t\t\t\t  ||      [4] CHANGE PASSKEY        ||\n");
	cout<<("\t\t\t\t\t\t\t\t  ||      [5] MAIN MENU             ||\n");
	cout<<("\t\t\t\t\t\t\t\t  ||                                ||\n");
	cout<<("\n\t\t\t\t\t\t\t\t  ENTER YOUR CHOICE: ");
	ch=getch();
	cout<<ch<<"\n";
	switch(ch)
	{
		case '1':
			addtrain();
			break;
		case '2':
			dlttrain();
			break;
		case '3':
			viewtrain();
			getch();
			admin();
			break;
		case '4':
			passkey();
			main();
			break;	
		case '5':
			system("cls");
			main();
			break;
		default:
			d();
			admin();
	}
	getch();
}
//---------------------------------------Password Function--------------------------------------------
void password()
{          
	bool f=true;
	cout<<("\n\t\t\t\t\t\t\t Enter PassKey: ");
	char p[30]={0};
	px:
	for(i=0;i<30;i++)
	{
		p[i]=getch();
		if(p[i]==13)
			break;
		else if(p[i]==8)
		{
			if((i-1)<0)
				goto px;
			cout<<"\b \b";
			p[--i]=8;
			--i;
		}
		else
			cout<<"*";
	}

	ifstream fi;
	fi.open("Password.txt",ios::in|ios::binary);
	char c[30];
	for(j=0;;j++)
	{
		fi.get(c[j]);
		if(c[j]==13)
			break;
	}
	fi.close();
	for(i=0;i<30;i++)
	{
		if(c[i]==13&&p[i]==13)
			break;
		if(c[i]!=p[i])
		{
			f=false;
			break;
		}
	}
	{
		if(f==true)
		{
			cout<<("\n\n\t\t\t\t\t\t\t\t <<<<<<<<< Login Successful >>>>>>>>>");
			getch();
			system("cls");
			admin();
		}
		else
		{
			cout<<"\n\n\t\t\t\t\t\t\t\t\t      !!!ERROR!!!";
			cout<<"\n\n\t\t\t\t\t\t\t\t <<<<<<<< Incorrect PassKey >>>>>>>>";
			getch();
			system("cls");
			main();
		}
	}
}
//----------------------------------------change passkey----------------------------------------------
void passkey()
{
	char p[30];
	ofstream fo;
	cout<<"\n\t\t\t\t\t\t\t\t  (Minimun 2 Characters)\n\t\t\t\t\t\t\t\t  Enter New PassKey: ";
	cin.getline(p,30);
	fo.open("Password.txt",ios::out);
	fo<<p;
	fo.put(13);
	fo.close();
	cout<<"\n\t\t\t\t\t\t\t\t\t~PassKey Changed";
	getch();
}
//--------------------------------------add train function--------------------------------------------
void addtrain()
{
	ofstream fo;
	fo.open("Train.txt",ios::app);
	cout<<"\n\t\t\t\t\t\t\t\t  Enter Train Details:\n";
	cout<<"\t\t\t\t\t\t\t\t  Train Number: ";
	gets(t.num);
	t.s=' ';
	cout<<"\t\t\t\t\t\t\t\t  Train Name: ";
	gets(t.name);
	cout<<"\t\t\t\t\t\t\t\t  Departure Point: ";
	gets(t.dep);
	cout<<"\t\t\t\t\t\t\t\t  Departure Time: ";	
	gets(t.dept);
	cout<<"\t\t\t\t\t\t\t\t  Destination Point: ";
	gets(t.des);			
	cout<<"\t\t\t\t\t\t\t\t  Destination Time: ";
	gets(t.dest);
	cout<<"\t\t\t\t\t\t\t\t  Seats Per Tier:\n";
	cout<<"\t\t\t\t\t\t\t\t  AC Tier 1: ";
	gets(t.HA1);
	arranger(t.HA1);
	cout<<"\t\t\t\t\t\t\t\t  Price: ";
	gets(t.HA1P);
	cout<<"\t\t\t\t\t\t\t\t  AC Tier 2: ";
	gets(t.A1);
	arranger(t.A1);
	cout<<"\t\t\t\t\t\t\t\t  Price: ";
	gets(t.A1P);
	cout<<"\t\t\t\t\t\t\t\t  SL Tier 3: ";
	gets(t.B1);
	arranger(t.B1);
	cout<<"\t\t\t\t\t\t\t\t  Price: ";
	gets(t.B1P);
	if(t.num[0]==0||t.name[0]==0||t.dep[0]==0||t.dept==t.dest||t.des[0]==0)
		cout<<"\t\t\t\t\t\t\t\t\t\tInvalid Input";
	else
	{
		fo.write((char*)&t,sizeof(train));
		fo.put(13);
		fo.close();
		viewtrain();
		cout<<"\n\t\t\t\t\t\t\t\t\t\t ~Data Added";
	}
	getch();
	admin();
}
//------------------------------------delete train function-------------------------------------------
void dlttrain()
{
	bool check=false;
	char n[20];
	viewtrain();
	
	ifstream fi;
	fi.open("Train.txt",ios::in|ios::binary);
	ofstream fo;
	fo.open("t1.txt",ios::out);
	if(fi.seekg(0,ios::end),fi.tellg()==0)
		cout<<"\n\t\t\t\t\t\t\t\tTrain not Availaible";
	else
	{
		fi.seekg(0,ios::beg);
		cout<<"\n\t\t\t\t\t\t\t\t  Enter Train Details:";
		cout<<"\n\t\t\t\t\t\t\t\t  Train Number of the train to be deleted: ";
		gets(n);
		while(!fi.eof())
		{
			fi.read((char*)&t,sizeof(train));
			if(fi.eof())
				break;
			{
				if((strcmp(n,t.name)==0)||((n[0]==t.num[0])&&(n[1]==t.num[1])&&(n[2]==t.num[2])&&(n[3]==t.num[3])&&(n[4]==t.num[4])))
					check==true;
				else
				{
					fo.write((char*)&t,sizeof(train));
					fo.put(13);
				}
			}
			fi.seekg(1,ios::cur);
		}
			cout<<"\n\t\t\t\t\t\t\t\t Train "<<n<<" deleted";
	}
	fi.close();
	fo.close();
	remove("Train.txt");
	rename("t1.txt","Train.txt");
	getch();
	admin();
}
//-------------------------------------view trains function-------------------------------------------
void viewtrain()								
{
	char l;
	long i=0;
	ifstream fi;
	fi.open("Train.txt",ios::in);
	cout<<"\n\t\t   | T-No. |      Train Name      |    Departure Point     Time |  Destination Point    Time | AC1  Price | AC2  Price |  SL  Price |";
	cout<<"\n\t\t   |_______________________________________________________________________________________________________________________________|";
	while(!fi.eof())
	{
		fi.get(l);
		if(fi.tellg()==i+1)
		{
			cout<<"\n\t\t   | ";
			i+=99;
		}
		if(fi.eof())
			break;				
		cout<<l;						// Escape Sequence Pattern Below
		if(fi.tellg()==i+5-99)			//5 |1_20 | 20  4 | 20  4 | 3  5 | 3  5 | 3  5 |
			cout<<" |";
		if(fi.tellg()==i+26-99||fi.tellg()==i+50-99||fi.tellg()==i+74-99||fi.tellg()==i+82-99||fi.tellg()==i+90-99||fi.tellg()==i+98-99)
		cout<<" | ";
		if(fi.tellg()==i+46-99||fi.tellg()==i+70-99||fi.tellg()==i+77-99||fi.tellg()==i+85-99||fi.tellg()==i+93-99)
		cout<<"  ";	
	}
	fi.close();
	cout<<endl;
}
//----------------------------------------------------file close--------------------------------------
//----------------------------------------------------program close-----------------------------------
