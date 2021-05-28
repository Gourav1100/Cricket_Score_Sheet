#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<fstream.h>
#include<graphics.h>
#include<process.h>
class css{
	int overs,overn[8][5],o[8][1];
	char nb[8][2],mo[8][2],overso[8][1],rs[8][2],w[8][2],wides[8][2],bname[11][20];
	char score[11][3], sixes[11][2],fours[11][2],pname[11][20],ho[11][6],ballsp[11][2];
	char a[6][20],runo[18][2],wico[18][2];
	char fname[20];
	int initno;
	public:
	void initialise(){
		clrscr();
		cout<<"\n\n\t\tEnter HOME CLUB name: ";
		cin>>a[0];
		cout<<"\n\n\t\tEnter VISITOR name: ";
		cin>>a[1];
		cout<<"\n\n\t\tInnings of: ";
		cin>>a[2];
		cout<<"\n\n\t\tDate: ";
		cin>>a[3];
		cout<<"\n\n\t\tPlayed at : ";
		cin>>a[4];
		cout<<"\n\n\t\tEnter no. of overs: ";
		cin>>overs;
	}
	int vs(int,int,int,int);
	int cs(int,int,int,int);
	int ss();
	void search();
	css(){
		initno=0;
	}
}r;
int main()
{
	clrscr();
	char c[1];
	int gd=DETECT,gs;
	initgraph(&gd,&gs,"C:\\TurboC3\\BGI");
	int x=getmaxx(),y=getmaxy();
	cleardevice();
	setfillstyle(1,CYAN);
	floodfill(x,y,CYAN);
	setfillstyle(1,YELLOW);
	circle(50,50,30);
	floodfill(50,50,WHITE);
	setfillstyle(1,2);
	circle(x,y,x);
	floodfill(x,y,WHITE);
	settextstyle(8,0,3);
	outtextxy(x/4,(y-180)/3," **** Cricket ScoreSheet **** ");
	outtextxy(x/4,(y-90)/3," 1. Create Scoresheet");
	outtextxy(x/4,y/3," 2. View Scoresheet");
	outtextxy(x/4,(y+90)/3," 3. Save File");
	outtextxy(x/4,(y+180)/3," 4. Load File");
	outtextxy(x/4,(y+270)/3," 5. Know More");
	outtextxy(x/4,(y+360)/3," 6. Exit");
	c[1]=getch();
	settextstyle(0,0,1);
	switch(c[1])
	{
		case '1' :	closegraph();
				r.cs(gd,gs,x,y);
				break;
		case '2' :	closegraph();
				r.vs(gd,gs,x,y);
				break;
		case '3' :	closegraph();
				r.ss();
				break;
		case '4' :	closegraph();
				r.search();
				break;
		case '5' :      outtextxy(x/5,(y+560)/3,"***** All Copyrights owned By G@urav B. XII-A ******");
				outtextxy(x/4,(y+620)/3," ******** System Requirements: ********");
				outtextxy(x/4,(y+660)/3,"    Recommended System Memory: 128MB");
				outtextxy(x/4,(y+700)/3,"    Recommended Virtual Memory: 64MB");
				outtextxy(x/4,(y+740)/3,"      Hard Drive space: 10MB");
				getch();
				main();
				break;
		case '6' :	closegraph();
				exit(0);
				break;
		default:	outtextxy(x/2,(y+540)/3,"Invalid!!Input");
				getch();
				main();
				break;
	}
	closegraph();
	return 0;
}
int css::cs(int gd,int gs,int x,int y){
	clrscr();
	if(initno==0){
		initialise();
		initno=1;
	}
	int b[3],i=0;
	char c[2],ch='y';
	edit:
	cout<<"\n\n\t\tWhat to do next: ";
	cout<<"\n\t\t1.See scoresheet;\t\t2.Edit batsman names;\n"<<
		"\t\t3.Edit batsman data;\t\t4.Edit bowlers names;"
		<<"\n\t\t5.Edit bowlers data;\t\t6.Edit over details;"
		<<"\n\t\t7.Exit;\n\t\tInput choice: ";
	cin>>b[0];
	if(b[0]==2)
	{
		clrscr();
		ch='y';
		cout<<"\n\n\t***** ScoreSheet Editing ***** ";
		while(ch=='y'|| ch=='Y')
		{
			cout<<"\n\n\t\tEnter Batsman no.: ";
			cin>>b[1];
			cout<<"\n\t\tEnter Batsman Name: ";
			cin>>pname[b[1]-1];
			cout<<"\n\n\n\t\tDo you want to continue: (y=yes n=no) ";
			cin>>ch;
		}
		goto sheet_view;
	}
	if(b[0]==3)
	{
		clrscr();
		i=0;
		ch='y';
		while(ch=='y'|| ch=='Y')
		{
			cout<<"Enter Batsman no.: ";
			cin>>b[1];
			cout<<"Enter name: ";
			cin>>a[5];
			cout<<"Are "<<r.pname[b[1]-1]<<" and "<<r.a[5]<<" same. (y=yes and n=no)";
			cin>>ch;
			if(ch=='y' || ch=='Y')
			{
				cout<<"Input Runs: ";
				cin>>score[b[1]-1];
				cout<<"Input sixes: ";
				cin>>sixes[b[1]-1];
				cout<<"Input Fours: ";
				cin>>fours[b[1]-1];
				cout<<"Input no. of balls played: ";
				cin>>ballsp[b[1]-1];
				cout<<"How Out : ";
				cin>>ho[b[1]-1];
			}
			i=i+1;
			if(ch=='n' || ch=='N')
			{i=0;}
			else{i=0;}
			cout<<"Do you want  to continue:(y=yes n=no) ";
			cin>>ch;
		}
		goto sheet_view;
	}
	if(b[0]==1)
	{
		cout<<"\n\n\t**** While on sheet press any key to exit *****";
		getch();
		goto sheet_view;
	}
	if(b[0]==4)
	{
		clrscr();
		ch='y';
		cout<<"\n\n\t***** ScoreSheet Editing ***** ";
		while(ch=='y'|| ch=='Y')
		{
			cout<<"\n\n\t\tEnter bowler no: ";
			cin>>b[1];
			cout<<"\n\t\tEnter Bowler Name: ";
			cin>>bname[b[1]-1];
			cout<<"\n\n\n\t\tDo you want to continue: (y=yes n=no) ";
			cin>>ch;
		}
		goto sheet_view;
	}
	if(b[0]==5)
	{
		clrscr();
		i=0;
		ch='y';
		while(ch=='y'|| ch=='Y')
		{       cout<<"***** Bowler's Data Editing *****";
			cout<<"\n\nEnter Bowler no.: ";
			cin>>b[1];
			cout<<"Enter name: ";
			cin>>a[5];
			cout<<"Are "<<r.bname[b[1]-1]<<" and "<<r.a[5]<<" same. (y=yes and n=no): ";
			cin>>ch;
			if(ch=='n' || ch=='N')
			{i=0;}
			else{i=0;}
			if(ch=='y' || ch=='Y')
			{
				cout<<"Input no. of overs bowled: ";
				cin>>o[b[1]-1][0];
				int g=o[b[1]-1][0];
				for(int j=0;j<g;j++)
				{
					cout<<"Input over no: ";
					cin>>overn[b[1]-1][j];
				}
				cout<<"Input Runs given: ";
				cin>>rs[b[1]-1];
				cout<<"Input no. of Wideballs: ";
				cin>>wides[b[1]-1];
				cout<<"Input no. of noballs : ";
				cin>>nb[b[1]-1];
				cout<<"Input no. of wickets taken: ";
				cin>>w[b[1]-1];
				cout<<"Input no. of m.overs: ";
				cin>>mo[b[1]-1];
				cout<<"Do you want  to continue:(y=yes n=no) ";
				cin>>ch;
			}
			b[2]=o[b[1]-1][0];
			b[2]=b[2]+48;
			overso[b[1]-1][0]=b[2];
			i=i+1;
		}
		goto sheet_view;
	}
	if(b[0]==7)
	{
		main();
	}
	if(b[0]==6)
	{
		clrscr();
		cout<<"\n\n\n\t\t***** OVER DATA EDITING *****";
		for(i=0;i<overs;i++)
		{
			cout<<"\nEnter Runs scored in "<<i+1<<" over : ";
			cin>>runo[i];
			cout<<"Enter no of Wickets in "<<i+1<<" over :";
		}	cin>>wico[i];

	}
	else
	{
		goto edit;
	}
	getch();
	goto sheet_view;
	sheet_view:
	initgraph(&gd,&gs,"C:\\TurboC3\\BGI");
	cleardevice();
	setfillstyle(3,CYAN);
	floodfill(x,y,CYAN);
	rectangle(1,2,101,52);
	rectangle(105,2,205,52);
	rectangle(209,2,309,52);
	rectangle(313,2,413,52);
	rectangle(417,2,517,52);
	rectangle(1,56,517,316);
	rectangle(521,2,637,296);
	rectangle(1,320,637,473);
	line(1,21,101,21);
	line(1,76,517,76);
	line(105,21,205,21);
	line(209,21,309,21);
	line(313,21,413,21);
	line(417,21,517,21);
	line(180,56,180,315);
	line(30,76,30,315);
	line(599,2,599,296);
	line(559,2,559,296);
	line(210,56,210,315);
	line(310,56,310,315);
	line(350,76,350,315);
	line(400,56,400,315);
	line(440,56,440,315);
	line(480,56,480,315);
	line(180,320,180,473);
	line(30,338,30,473);
	for(i=2;i<13;i++)
	{
		line(1,(56+(i*21.7)),517,(56+(i*21.7)));
	}
	for(i=0;i<20;i++)
	{
		line(521,(2+(i*14.7)),637,(2+(i*14.7)));
	}
	for(i=0;i<=9;i++)
	{
		line(1,(320+(i*17)),637,(320+(i*17)));
	}
	for(i=2;i<25;i++)
	{
		line(180,(56+(i*10.8)),210,(56+(i*10.8)));
	}
	for(i=2;i<25;i++)
	{
		line(310,(56+(i*10.8)),400,(56+(i*10.8)));
	}
	for(i=0;i<10;i++)
	{
		line((200+(i*20)),320,(200+(i*20)),473);
	}
	for(i=0;i<16;i++)
	{
		line(180,(338+(i*8.5)),380,(338+(i*8.5)));
	}
	for(i=0;i<6;i++)
	{
		line((380+(42*i)),320,(380+(i*42)),473);
	}
	outtextxy(15,7,"HOME CLUB ");
	outtextxy(10,35,a[0]);
	outtextxy(120,7," VISITOR ");
	outtextxy(115,35,a[1]);
	outtextxy(215,7," INNINGS OF ");
	outtextxy(212,35,a[2]);
	outtextxy(325,7," PLAYED AT ");
	outtextxy(320,35,a[4]);
	outtextxy(440,7," DATE ");
	outtextxy(430,35,a[3]);
	outtextxy(50,63," BATSMAN");
	outtextxy(175,63," I/O");
	outtextxy(210,63," RUNS SCORED");
	outtextxy(335,63," 4/6");
	outtextxy(394,63," BALLS");
	outtextxy(434,63," H.OUT");
	outtextxy(475,63," RUNS");
	outtextxy(5,85," 1");
	outtextxy(5,107," 2");
	outtextxy(5,129," 3");
	outtextxy(5,151," 4");
	outtextxy(5,173," 5");
	outtextxy(5,195," 6");
	outtextxy(5,217," 7");
	outtextxy(5,239," 8");
	outtextxy(5,261," 9");
	outtextxy(4,283," 10");
	outtextxy(4,305," 11");
	for(i=0;i<11;i++)
	{
		outtextxy(50,85+(21.7*i),pname[i]);
		outtextxy(260,85+(21.7*i),score[i]);
		outtextxy(360,80+(21.7*i),fours[i]);
		outtextxy(360,90+(21.7*i),sixes[i]);
		outtextxy(495,85+(21.7*i),score[i]);
		outtextxy(460,85+(21.7*i),ho[i]);
		outtextxy(435,85+(21.7*i),ballsp[i]);
	}
	outtextxy(50,325," BOWLER");
	for(i=0;i<8;i++)
	{
		outtextxy(50,344+(i*17),bname[i]);
		outtextxy(397,344+(i*17),wides[i]);
		outtextxy(440,344+(i*17),nb[i]);
		outtextxy(480,344+(i*17),overso[i]);
		outtextxy(525,344+(i*17),mo[i]);
		outtextxy(565,344+(i*17),rs[i]);
		outtextxy(608,344+(i*17),w[i]);
	}
	outtextxy(5,344," 1");
	outtextxy(5,360," 2");
	outtextxy(5,376," 3");
	outtextxy(5,393," 4");
	outtextxy(5,410," 5");
	outtextxy(5,428," 6");
	outtextxy(5,444," 7");
	outtextxy(5,460," 8");
	outtextxy(180,325," 1");
	outtextxy(200,325," 2");
	outtextxy(220,325," 3");
	outtextxy(240,325," 4");
	outtextxy(260,325," 5");
	outtextxy(280,325," 6");
	outtextxy(300,325," 7");
	outtextxy(320,325," 8");
	outtextxy(340,325," 9");
	outtextxy(362,325,"10");
	outtextxy(382,325,"WIDES");
	outtextxy(434,325,"NB");
	outtextxy(482,325,"O");
	outtextxy(525,325,"M");
	outtextxy(568,325,"R");
	outtextxy(610,325,"W");
	outtextxy(521.5,7,"OVERS");
	outtextxy(563,7,"RUNS");
	outtextxy(603,7,"WIC.");
	for(i=0;i<r.overs;i++)
	{
		outtextxy(575,20+(i*15.3),runo[i]);
		outtextxy(615,20+(i*15.3),wico[i]);
	}
	for(i=0;i<10;i++)
	{
		for(int j=0;j<5;j++)
		{
			int e=overn[i][j];
			if(e==1)
			outtextxy(190,339+(i*17),"x");
			if(e==2)
			outtextxy(210,339+(i*17),"x");
			if(e==3)
			outtextxy(230,339+(i*17),"x");
			if(e==4)
			outtextxy(250,339+(i*17),"x");
			if(e==5)
			outtextxy(270,339+(i*17),"x");
			if(e==6)
			outtextxy(290,339+(i*17),"x");
			if(e==7)
			outtextxy(310,339+(i*17),"x");
			if(e==8)
			outtextxy(330,339+(i*17),"x");
			if(e==9)
			outtextxy(350,339+(i*17),"x");
			if(e==10)
			outtextxy(370,339+(i*17),"x");
			if(e==11)
			outtextxy(190,347+(i*17),"x");
			if(e==12)
			outtextxy(210,347+(i*17),"x");
			if(e==13)
			outtextxy(230,347+(i*17),"x");
			if(e==14)
			outtextxy(250,347+(i*17),"x");
			if(e==15)
			outtextxy(270,347+(i*17),"x");
			if(e==16)
			outtextxy(290,347+(i*17),"x");
			if(e==17)
			outtextxy(310,347+(i*17),"x");
			if(e==18)
			outtextxy(330,347+(i*17),"x");
			if(e!=1)
			outtextxy(190,339+(i*17),"o");
			if(e!=2)
			outtextxy(210,339+(i*17),"o");
			if(e!=3)
			outtextxy(230,339+(i*17),"o");
			if(e!=4)
			outtextxy(250,339+(i*17),"o");
			if(e!=5)
			outtextxy(270,339+(i*17),"o");
			if(e!=6)
			outtextxy(290,339+(i*17),"o");
			if(e!=7)
			outtextxy(310,339+(i*17),"o");
			if(e!=8)
			outtextxy(330,339+(i*17),"o");
			if(e!=9)
			outtextxy(350,339+(i*17),"o");
			if(e!=10)
			outtextxy(370,339+(i*17),"o");
			if(e!=11)
			outtextxy(190,347+(i*17),"o");
			if(e!=12)
			outtextxy(210,347+(i*17),"o");
			if(e!=13)
			outtextxy(230,347+(i*17),"o");
			if(e!=14)
			outtextxy(250,347+(i*17),"o");
			if(e!=15)
			outtextxy(270,347+(i*17),"o");
			if(e!=16)
			outtextxy(290,347+(i*17),"o");
			if(e!=17)
			outtextxy(310,347+(i*17),"o");
			if(e!=18)
			outtextxy(330,347+(i*17),"o");
		}
	}
	outtextxy(525,20," 1");
	outtextxy(525,36," 2");
	outtextxy(525,50," 3");
	outtextxy(525,66," 4");
	outtextxy(525,80," 5");
	outtextxy(525,95," 6");
	outtextxy(525,110," 7");
	outtextxy(525,124," 8");
	outtextxy(525,140," 9");
	outtextxy(525,153," 10");
	outtextxy(525,168," 11");
	outtextxy(525,182," 12");
	outtextxy(525,198," 13");
	outtextxy(525,212," 14");
	outtextxy(525,228," 15");
	outtextxy(525,242," 16");
	outtextxy(525,256," 17");
	outtextxy(525,270," 18");
	outtextxy(521.5,286,"TOTAL" );
	for(i=18;i>overs;i--)
	{
		outtextxy(570,(i*15)," -    -");
	}
	for(i=0;i<8;i++)
	{
		outtextxy(345,347+(17*i),"-  -");
	}
	for(i=0;i<11;i++)
	{
		outtextxy(320,80+(i*21.54)," 4");
		outtextxy(320,90.72+(i*21.54)," 6");
	}
	c[0]=getch();
	switch(c[0])
	{
		default  :      closegraph();
				goto edit;
				break;
	}
	return 0;
}
int css::vs(int gd,int gs,int x,int y)
{
	char c[1];
	initgraph(&gd,&gs,"C:\\TurboC3\\BGI");
	cleardevice();
	setfillstyle(6,RED);
	floodfill(x,y,WHITE);
	rectangle(1,2,101,52);
	rectangle(105,2,205,52);
	rectangle(209,2,309,52);
	rectangle(313,2,413,52);
	rectangle(417,2,517,52);
	rectangle(1,56,517,316);
	rectangle(521,2,637,296);
	rectangle(1,320,637,473);
	line(1,21,101,21);
	line(1,76,517,76);
	line(105,21,205,21);
	line(209,21,309,21);
	line(313,21,413,21);
	line(417,21,517,21);
	line(180,56,180,315);
	line(30,76,30,315);
	line(599,2,599,296);
	line(559,2,559,296);
	line(210,56,210,315);
	line(310,56,310,315);
	line(350,76,350,315);
	line(400,56,400,315);
	line(440,56,440,315);
	line(480,56,480,315);
	line(180,320,180,473);
	line(30,338,30,473);
	for(int i=2;i<13;i++)
	{
		line(1,(56+(i*21.7)),517,(56+(i*21.7)));
	}
	for(i=0;i<20;i++)
	{
		line(521,(2+(i*14.7)),637,(2+(i*14.7)));
	}
	for(i=0;i<=9;i++)
	{
		line(1,(320+(i*17)),637,(320+(i*17)));
	}
	for(i=2;i<25;i++)
	{
		line(180,(56+(i*10.8)),210,(56+(i*10.8)));
	}
	for(i=2;i<25;i++)
	{
		line(310,(56+(i*10.8)),400,(56+(i*10.8)));
	}
	for(i=0;i<10;i++)
	{
		line((200+(i*20)),320,(200+(i*20)),473);
	}
	for(i=0;i<16;i++)
	{
		line(180,(338+(i*8.5)),380,(338+(i*8.5)));
	}
	for(i=0;i<6;i++)
	{
		line((380+(42*i)),320,(380+(i*42)),473);
	}
	outtextxy(15,7,"HOME CLUB ");
	outtextxy(10,35,a[0]);
	outtextxy(120,7," VISITOR ");
	outtextxy(115,35,a[1]);
	outtextxy(215,7," INNINGS OF ");
	outtextxy(212,35,a[2]);
	outtextxy(325,7," PLAYED AT ");
	outtextxy(320,35,a[4]);
	outtextxy(440,7," DATE ");
	outtextxy(430,35,a[3]);
	outtextxy(50,63," BATSMAN");
	outtextxy(175,63," I/O");
	outtextxy(210,63," RUNS SCORED");
	outtextxy(335,63," 4/6");
	outtextxy(394,63," BALLS");
	outtextxy(434,63," H.OUT");
	outtextxy(475,63," RUNS");
	outtextxy(5,85," 1");
	outtextxy(5,107," 2");
	outtextxy(5,129," 3");
	outtextxy(5,151," 4");
	outtextxy(5,173," 5");
	outtextxy(5,195," 6");
	outtextxy(5,217," 7");
	outtextxy(5,239," 8");
	outtextxy(5,261," 9");
	outtextxy(4,283," 10");
	outtextxy(4,305," 11");
	for(i=0;i<11;i++)
	{
		outtextxy(50,85+(21.7*i),pname[i]);
		outtextxy(260,85+(21.7*i),score[i]);
		outtextxy(360,80+(21.7*i),fours[i]);
		outtextxy(360,90+(21.7*i),sixes[i]);
		outtextxy(495,85+(21.7*i),score[i]);
		outtextxy(460,85+(21.7*i),ho[i]);
		outtextxy(435,85+(21.7*i),ballsp[i]);
	}
	outtextxy(50,325," BOWLER");
	for(i=0;i<8;i++)
	{
		outtextxy(50,344+(i*17),bname[i]);
		outtextxy(397,344+(i*17),wides[i]);
		outtextxy(440,344+(i*17),nb[i]);
		outtextxy(480,344+(i*17),overso[i]);
		outtextxy(525,344+(i*17),mo[i]);
		outtextxy(565,344+(i*17),rs[i]);
		outtextxy(608,344+(i*17),w[i]);
	}
	outtextxy(5,344," 1");
	outtextxy(5,360," 2");
	outtextxy(5,376," 3");
	outtextxy(5,393," 4");
	outtextxy(5,410," 5");
	outtextxy(5,428," 6");
	outtextxy(5,444," 7");
	outtextxy(5,460," 8");
	outtextxy(180,325," 1");
	outtextxy(200,325," 2");
	outtextxy(220,325," 3");
	outtextxy(240,325," 4");
	outtextxy(260,325," 5");
	outtextxy(280,325," 6");
	outtextxy(300,325," 7");
	outtextxy(320,325," 8");
	outtextxy(340,325," 9");
	outtextxy(362,325,"10");
	outtextxy(382,325,"WIDES");
	outtextxy(434,325,"NB");
	outtextxy(482,325,"O");
	outtextxy(525,325,"M");
	outtextxy(568,325,"R");
	outtextxy(610,325,"W");
	outtextxy(521.5,7,"OVERS");
	outtextxy(563,7,"RUNS");
	outtextxy(603,7,"WIC.");
	for(i=0;i<r.overs;i++)
	{
		outtextxy(575,20+(i*15.3),runo[i]);
		outtextxy(615,20+(i*15.3),wico[i]);
	}
	for(i=0;i<10;i++)
	{
		for(int j=0;j<5;j++)
		{
			int e=overn[i][j];
			if(e==1)
			outtextxy(190,339+(i*17),"x");
			if(e==2)
			outtextxy(210,339+(i*17),"x");
			if(e==3)
			outtextxy(230,339+(i*17),"x");
			if(e==4)
			outtextxy(250,339+(i*17),"x");
			if(e==5)
			outtextxy(270,339+(i*17),"x");
			if(e==6)
			outtextxy(290,339+(i*17),"x");
			if(e==7)
			outtextxy(310,339+(i*17),"x");
			if(e==8)
			outtextxy(330,339+(i*17),"x");
			if(e==9)
			outtextxy(350,339+(i*17),"x");
			if(e==10)
			outtextxy(370,339+(i*17),"x");
			if(e==11)
			outtextxy(190,347+(i*17),"x");
			if(e==12)
			outtextxy(210,347+(i*17),"x");
			if(e==13)
			outtextxy(230,347+(i*17),"x");
			if(e==14)
			outtextxy(250,347+(i*17),"x");
			if(e==15)
			outtextxy(270,347+(i*17),"x");
			if(e==16)
			outtextxy(290,347+(i*17),"x");
			if(e==17)
			outtextxy(310,347+(i*17),"x");
			if(e==18)
			outtextxy(330,347+(i*17),"x");
			if(e!=1)
			outtextxy(190,339+(i*17),"o");
			if(e!=2)
			outtextxy(210,339+(i*17),"o");
			if(e!=3)
			outtextxy(230,339+(i*17),"o");
			if(e!=4)
			outtextxy(250,339+(i*17),"o");
			if(e!=5)
			outtextxy(270,339+(i*17),"o");
			if(e!=6)
			outtextxy(290,339+(i*17),"o");
			if(e!=7)
			outtextxy(310,339+(i*17),"o");
			if(e!=8)
			outtextxy(330,339+(i*17),"o");
			if(e!=9)
			outtextxy(350,339+(i*17),"o");
			if(e!=10)
			outtextxy(370,339+(i*17),"o");
			if(e!=11)
			outtextxy(190,347+(i*17),"o");
			if(e!=12)
			outtextxy(210,347+(i*17),"o");
			if(e!=13)
			outtextxy(230,347+(i*17),"o");
			if(e!=14)
			outtextxy(250,347+(i*17),"o");
			if(e!=15)
			outtextxy(270,347+(i*17),"o");
			if(e!=16)
			outtextxy(290,347+(i*17),"o");
			if(e!=17)
			outtextxy(310,347+(i*17),"o");
			if(e!=18)
			outtextxy(330,347+(i*17),"o");
		}
	}
	outtextxy(525,20," 1");
	outtextxy(525,36," 2");
	outtextxy(525,50," 3");
	outtextxy(525,66," 4");
	outtextxy(525,80," 5");
	outtextxy(525,95," 6");
	outtextxy(525,110," 7");
	outtextxy(525,124," 8");
	outtextxy(525,140," 9");
	outtextxy(525,153," 10");
	outtextxy(525,168," 11");
	outtextxy(525,182," 12");
	outtextxy(525,198," 13");
	outtextxy(525,212," 14");
	outtextxy(525,228," 15");
	outtextxy(525,242," 16");
	outtextxy(525,256," 17");
	outtextxy(525,270," 18");
	outtextxy(521.5,286,"TOTAL" );
	for(i=18;i>overs;i--)
	{
		outtextxy(570,(i*15)," -    -");
	}
	for(i=0;i<8;i++)
	{
		outtextxy(345,347+(17*i),"-  -");
	}
	for(i=0;i<11;i++)
	{
		outtextxy(320,80+(i*21.54)," 4");
		outtextxy(320,90.72+(i*21.54)," 6");
	}
	c[0]=getch();
	switch(c[0])
	{
		default  :      closegraph();
				main();
				break;
	}
	return 0;
}
int css::ss(){
	clrscr();
	int gd=DETECT,gs,mx,my;
	char c[1];
	css user[60];
	for(int i=0;i<10;i++)
	{
		c[i]='\0';
	}
	initgraph(&gd,&gs,"C:\\TurboC3\\BGI");
	cleardevice();
	int midx=getmaxx()/2,midy=getmaxy()/2,a,b;
	cleardevice();
	setfillstyle(3,5);
	floodfill(0,0,5);
	setcolor(15);
	bar3d(midx-250,midy-100,midx+250,midy+100,10,1);
	setfillstyle(1,8);
	floodfill(midx,midy,15);
	floodfill(midx+255,midy,15);
	floodfill(midx,midy-105,15);
	setcolor(0);
	rectangle(midx-240,midy-70,midx+240,midy-40);
	rectangle(midx-240,midy-15,midx-20,midy+15);
	rectangle(midx-240,midy+20,midx-20,midy+50);
	setfillstyle(1,15);
	floodfill(midx-230,midy-65,0);
	floodfill(midx-230,midy-10,0);
	floodfill(midx-230,midy+25,0);
	settextstyle(3,0,2);
	outtextxy(midx-240,midy-95,"Filename: ");
	a=textwidth("** Save **");
	b=textheight("** Save **");
	outtextxy(midx-130-(a/2),midy-(b/2),"** Save **");
	a=textwidth("** Cancel **");
	b=textheight("** Cancel **");
	outtextxy(midx-130-(a/2),midy+35-(b/2),"** Cancel **");
	i=0;
	fstream fin;
	while(1){
		if(i==15){
			if(fname[i-4]=='.' && fname[i-3]=='d' && fname[i-2]=='a' && fname[i-1]=='t')
			{
				fname[i+1]='\0';
			}
			else if(fname[i-4]=='.' && fname[i-3]=='t' && fname[i-2]=='x' && fname[i-1]=='t')
			{
				fname[i+1]='\0';
			}
			else{
				fname[i]='.';
				fname[i+1]='d';
				fname[i+2]='a';
				fname[i+3]='t';
				fname[i+4]='\0';
			}
			break;
		}
		c[0]=fname[i]=getch();
		a=textwidth(c);
		b=textheight(c);
		outtextxy(midx-235+(i*12),midy-55-(b/2),c);
		if(fname[i]==13 && i>4){
			fname[i]=NULL;
			if(fname[i-4]=='.' && fname[i-3]=='d' && fname[i-2]=='a' && fname[i-1]=='t')
			{
				fname[i+1]='\0';
			}
			else if(fname[i-4]=='.' && fname[i-3]=='t' && fname[i-2]=='x' && fname[i-1]=='t')
			{
				fname[i+1]='\0';
			}
			else{
				fname[i]='.';
				fname[i+1]='d';
				fname[i+2]='a';
				fname[i+3]='t';
				fname[i+4]='\0';
			}
			break;
		}
		if(i<=4 && c[0]==13)
		{
			fname[i]=NULL;
			i=i-1;
			c[0]=NULL;
		}
		if(c[0]==8)
		{
			fname[i]=NULL;
			i=i-1;
			if(i<0)
			i=0;
			setcolor(15);
			for(int j=0;j<30;j++)
			line(midx-235+(i*12)+j,midy-68,midx-235+(i*12)+j,midy-42);
			setcolor(0);
			i=i-1;
		}
		if(c[0]==27)
		{
			main();
		}
		i=i+1;
	}
	closegraph();
	fin.open("files.dat",ios::binary|ios::out|ios::app);
	for(i=0;!fin.eof();i++){
	}
	user[i].overs=overs;
	for(int j=0;j<8;j++){
		user[i].overn[j][0]=overn[j][0];
		user[i].overn[j][1]=overn[j][1];
		user[i].overn[j][2]=overn[j][2];
		user[i].overn[j][3]=overn[j][3];
		user[i].overn[j][4]=overn[j][4];
		user[i].o[j][0]=o[j][0];
		strcpy(user[i].nb[j],nb[j]);
		strcpy(user[i].mo[j],mo[j]);
		strcpy(user[i].overso[j],overso[j]);
		strcpy(user[i].rs[j],rs[j]);
		strcpy(user[i].w[j],w[j]);
		strcpy(user[i].wides[j],wides[j]);
	}
	for(j=0;j<11;j++){
		strcpy(user[i].bname[j],bname[j]);
		strcpy(user[i].score[j],score[j]);
		strcpy(user[i].sixes[j],sixes[j]);
		strcpy(user[i].fours[j],fours[j]);
		strcpy(user[i].pname[j],pname[j]);
		strcpy(user[i].ho[j],ho[j]);
		strcpy(user[i].ballsp[j],ballsp[j]);
	}
	for(j=0;j<6;j++){
		strcpy(user[i].a[j], r.a[j]);
	}
	for(j=0;j<18;j++){
		strcpy(user[i].runo[j],runo[j]);
		strcpy(user[i].wico[j],wico[j]);
	}
	user[i].initno=initno;
	strcpy(user[i].fname,fname);
	fin.write((char *)&user[i],sizeof user[i]);
	return 0;
}
void css::search(){

}