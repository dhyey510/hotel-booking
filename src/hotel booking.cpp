#include<iostream>
#include<conio.h>
#include<fstream>
#include<windows.h>
//#include<dhyey.h>
using namespace std;
void gotoxy (int x, int y)
{

COORD coord;
coord.X = x;
coord.Y = y;

SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
string password;
string u_name;
void loading(char username1[],char password[]);
void login();
void booking_cancel();
void signup();
void homepage();
void symbol();
void your_booking()
{
system("cls");
    symbol();
    gotoxy(70,35);
    cout<<"Backspace - return to homepage";
    FILE *fp;
    fp=fopen("sign.txt","r");
    char un[15],pa[6],na[40],gender[8];
    char *pass=&password[0];
    int age;
    fseek(fp,0,SEEK_SET);
    char ch=getc(fp);
    fseek(fp,0,SEEK_SET);
    fscanf(fp,"%s %d %s %s %s ",na,&age,gender,un,pa);
    int count=0;
        while(strcmp(pass,pa))
        {
            if(ch!=EOF)
            {
                fseek(fp,0,SEEK_CUR);
                long int a=ftell(fp);
                ch=getc(fp);
                fseek(fp,a,SEEK_SET);
                fscanf(fp,"%s %d %s %s %s",na,&age,gender,un,pa);
            }
            else
            {
                count++;
                break;
            }

        }
    if(count==0)
    {
       gotoxy(10,19);
        cout<<"Name   : "<<na;
        gotoxy(10,20);
        cout<<"Age    : "<<age;
        gotoxy(10,21);
        cout<<"Gender : "<<gender<<endl<<endl;
        gotoxy(10,23);
        for(int i=0;i<143;i++)
            cout<<"-";
    }
   else
   {
       gotoxy(75,20);
        cout<<"no data found";
   }
    fclose(fp);

    fp=fopen("user.txt","r");
    char no[3],date1[9],date2[9],name[80],hotelname1[10],hotelname2[10],hotelname3[10];
    char *nana=&u_name[0];
    int person;
    fseek(fp,0,SEEK_SET);
    char ch1=getc(fp);
    fseek(fp,0,SEEK_SET);
    fscanf(fp,"%s %s %s %d %s %s %s %s",name,date1,date2,&person,no,hotelname1,hotelname2,hotelname3);
    int count1=0,i=1,x=10,y=27;
    gotoxy(x,y);
    cout<<"Sr.no";
    gotoxy(40,y);
    cout<<"Check In";
    gotoxy(70,y);
    cout<<"Check Out";
    gotoxy(100,y);
    cout<<"Persons";
    gotoxy(130,y);
    cout<<"Room No";
    gotoxy(150,y);
    cout<<"Hotel Name";
    y=30;
    while(ch1!=EOF)
    {
        if(strcmp(nana,name))
        {
            fseek(fp,0,SEEK_CUR);
            long int a=ftell(fp);
            ch1=getc(fp);
            fseek(fp,a,SEEK_SET);
            fscanf(fp,"%s %s %s %d %s %s %s %s",name,date1,date2,&person,no,hotelname1,hotelname2,hotelname3);
        }
        else
        {
          gotoxy(10,y);
          cout<<i;
          gotoxy(40,y);
          cout<<date1;
          gotoxy(70,y);
          cout<<date2;
          gotoxy(100,y);
          cout<<person;
          gotoxy(130,y);
          cout<<no;
          gotoxy(150,y);
          cout<<hotelname1<<" "<<hotelname2<<" "<<hotelname3;
          i++;
          y++;
          count1++;
          fseek(fp,0,SEEK_CUR);
            long int a=ftell(fp);
            ch1=getc(fp);
            fseek(fp,a,SEEK_SET);
            fscanf(fp,"%s %s %s %d %s %s %s %s",name,date1,date2,&person,no,hotelname1,hotelname2,hotelname3);

        }
    }
    if(count1<1)
    {
        gotoxy(75,30);
        cout<<"No data found";
    }
    fclose(fp);
    gotoxy(70,35);
    char ch2=_getch();
    if(ch2==8)
        homepage();
    else
        homepage();

}
char *h_name1,*h_name2,*h_name3;
void bookingroom();
void clickdesign();
void click();
void click1();
void searchpage();
void design();
void search();
void room(char *r_no,char *checkin,char *checkout,int p)
{
    system("cls");

    //char *n1=&u_name[0];
    FILE *fp,*fp1;
    fp=fopen("user.txt","a");
    fclose(fp);
    fp=fopen("user.txt","r");
    char no[3],date1[9],date2[9],na[40],hotelname1[10],hotelname2[10],hotelname3[10];
    int person;
    fseek(fp,0,SEEK_SET);
    char ch=getc(fp);
    fseek(fp,0,SEEK_SET);
    fscanf(fp,"%s %s %s %d %s %s %s %s",na,date1,date2,&person,no,hotelname1,hotelname2,hotelname3);
    int count=0;
    while(strcmp(r_no,no) || (strcmp(date1,checkin) || strcmp(date2,checkout)) || (strcmp(h_name1,hotelname1) || strcmp(hotelname2,h_name2) || strcmp(h_name3,hotelname3)))
    {
        if(ch!=EOF)
        {
            fseek(fp,0,SEEK_CUR);
            long int a=ftell(fp);
            ch=getc(fp);
            fseek(fp,a,SEEK_SET);
            fscanf(fp,"%s %s %s %d %s %s %s %s",na,date1,date2,&person,no,hotelname1,hotelname2,hotelname3);
        }
        else
        {
            count++;
            break;
        }
    }
    fclose(fp);
    if(count<1)
    {
        system("cls");
        gotoxy(75,23);
        cout<<"Oops!! "<<r_no<<" is already book by another person...Try another room..";
        for(int j=0;j<707000000;j++);
        bookingroom();
    }
    else
    {
            fp1=fopen("user.txt","a");
            char h=u_name[0];
            fprintf(fp,"\n%c%s %s %s %d %s %s %s %s",h,&u_name[1],checkin,checkout,p,r_no,h_name1,h_name2,h_name3);
            fclose(fp1);
            system("cls");
            gotoxy(70,23);
            cout<<"Room Booking successfully..";
            for(int j=0;j<707000000;j++);
            homepage();
    }
}
void room(char *r_no,char *checkin,char *checkout,int p,char *er_no)
{
    system("cls");
    //char *n1=&u_name[0];
    FILE *fp,*fp1;
    fp=fopen("user.txt","a");
    fclose(fp);
    fp=fopen("user.txt","r");
    char no[3],no2[3],date1[9],date2[9],na[80],hotelname1[10],hotelname2[10],hotelname3[10];
    int person;
    fseek(fp,0,SEEK_SET);
    char ch=getc(fp);
    fseek(fp,0,SEEK_SET);
    fscanf(fp,"%s %s %s %d %s %s %s %s %s",na,date1,date2,&person,no,no2,hotelname1,hotelname2,hotelname3);
    int count=0;
    while((strcmp(r_no,no) && strcmp(er_no,no2)) || (strcmp(date1,checkin)|| strcmp(date2,checkout))|| (strcmp(h_name1,hotelname1) || strcmp(hotelname2,h_name2) || strcmp(h_name3,hotelname3)))
    {
        if(ch!=EOF)
        {
            fseek(fp,0,SEEK_CUR);
            long int a=ftell(fp);
            ch=getc(fp);
            fseek(fp,a,SEEK_SET);
            fscanf(fp,"%s %s %s %d %s %s %s %s %s",na,date1,date2,&person,no,no2,hotelname1,hotelname2,hotelname3);
        }
        else
        {
            count++;
            break;
        }
    }
    fclose(fp);
    if(count<1)
        {
            system("cls");
            gotoxy(75,23);
            cout<<"Oops!! "<<r_no<<" is already book by another person...Try another room..";
            bookingroom();
        }
    else
        {
            fp1=fopen("user.txt","a");
            char h1=u_name[0];
            fprintf(fp,"\n%c%s %s %s %d %s %s %s %s %s",h1,&u_name[1],checkin,checkout,p,r_no,er_no,h_name1,h_name2,h_name3);
            fclose(fp1);
            system("cls");
            gotoxy(70,23);
            cout<<"Room Booking successfully..";
            for(int j=0;j<707000000;j++);
            homepage();
        }
}
void bk_room(string number)
{
    system("cls");
    symbol();
    gotoxy(75,18);
    cout<<"Room No : "<<number;
    gotoxy(70,25);
    cout<<"Check in (DD/MM/YY) : ";
    char check_in[9];
    cin>>check_in;
    gotoxy(70,27);
    cout<<"Check Out (DD/MM/YY) : ";
    char check_out[9];
    cin>>check_out;


    gotoxy(70,29);
    cout<<"Persons : ";
    int per;
    cin>>per;
    if(per>=4)
    {
        gotoxy(70,31);
        cout<<"Are you need extra room (y/n) : ";
        char c;
        cin>>c;
        if(c=='y' || c=='Y')
        {
            system("cls");
            symbol();
            int x=65,y=20;
            gotoxy(73,15);
            cout<<"Choose your room ... ";
            gotoxy(75,20);
            cout<<"Ground Floor";
            gotoxy(70,22);
            cout<<"D1";
            gotoxy(75,22);
            cout<<"D2";
            gotoxy(85,22);
            cout<<"D3";
            gotoxy(90,22);
            cout<<"D4";
            gotoxy(75,25);
            cout<<"First Floor";
            gotoxy(70,27);
            cout<<"D5";
            gotoxy(75,27);
            cout<<"D6";
            gotoxy(85,27);
            cout<<"D7";
            gotoxy(90,27);
            cout<<"D8";
            gotoxy(70,30);
            cout<<"enter which room you want : ";
            char no2[3];
            cin>>no2;
            room(&number[0],&check_in[0],&check_out[0],per,&no2[0]);
        }
        else
            room(&number[0],&check_in[0],&check_out[0],per);

    }
    room(&number[0],&check_in[0],&check_out[0],per);
}
void bookingroom()
{
    system("cls");

    int x=70,y=22;
    gotoxy(73,15);
    cout<<"Choose your room ... ";

    gotoxy(75,20);
    cout<<"Ground Floor";
    gotoxy(70,22);
    cout<<"D1";
    gotoxy(75,22);
    cout<<"D2";
    gotoxy(85,22);
    cout<<"D3";
    gotoxy(90,22);
    cout<<"D4";

    gotoxy(75,25);
    cout<<"First Floor";
    gotoxy(70,27);
    cout<<"D5";
    gotoxy(75,27);
    cout<<"D6";
    gotoxy(85,27);
    cout<<"D7";
    gotoxy(90,27);
    cout<<"D8";

    gotoxy(70,35);
    cout<<"Backspace - return to homepage";
    gotoxy(70,22);

    char chi=_getch();
    while(chi!=13 && chi!=8)
    {
        chi=_getch();
        switch(chi)
        {
            case 72:if(y==22)
                        break;
                    else
                    {
                        x=70;
                        y=22;
                        gotoxy(x,y);
                    }
                    break;

            case 80:if(y==27)
                        break;
                    else
                    {
                        x=70;
                        y=27;
                        gotoxy(x,y);
                    }
                    break;

            case 77:if(x==90)
                            break;
                        else
                        {
                            if(x==75)
                                x=x+10;
                            else
                                x=x+5;
                            gotoxy(x,y);
                        }
                    break;

            case 75:if(x==70)
                            break;
                        else
                            {
                                if(x==85)
                                    x=x-10;
                                else
                                    x=x-5;
                                gotoxy(x,y);
                            }
                            break;

        }
        chi=_getch();
        if(chi==8)
            break;
    }
    if(chi==8)

        homepage();
    //char rono[3];
    switch(y)
    {
        case 22:switch(x)
                {
                    case 70:{string rono="D1";
                            bk_room(rono);}
                                break;

                    case 75:{
                        string rono="D2";
                        bk_room(rono);}
                            break;

                    case 85:{
                                string rono="D3";
                                bk_room(rono);
                            }
                                break;

                    case 90:{
                        string rono="D4";
                        bk_room(rono);}
                            break;
                }
                break;

        case 27:switch(x)
                {
                    case 70:{string rono="D5";
                        bk_room(rono);}
                                break;

                    case 75:{string rono="D6";
                        bk_room(rono);}
                                break;

                    case 85:{string rono="D7";
                        bk_room(rono);}
                                break;

                    case 90:{string rono="D8";bk_room(rono);}
                            break;
                }
    }
}
void vadodara()
{
    searchpage();
    FILE *fp1;
    char hname1[10],hname2[10],hname3[10],city[10],star[6],c[]="vadodara";
    int n1;

    gotoxy(25,17);
    cout<<"Hotel Name";
    gotoxy(80,17);
    cout<<"City";
    gotoxy(120,17);
    cout<<"Star";
    gotoxy(110,10);
    cout<<"vadodara";
    if((fp1=fopen("HOTEL.txt","r"))==NULL)
    {
        cout<<"NO";
    }
    fseek(fp1,0,SEEK_SET);
    char ch=getc(fp1);
    fseek(fp1,0,SEEK_SET);
    fscanf(fp1,"%s %s %s %s %d %s",hname1,hname2,hname3,city,&n1,star);
    gotoxy(25,25);
    //cout<<hname1<<hname2<<hname3;
    int count=0,y3=19,i=1;
    while(ch!=EOF)
    {
        if(strcmp(city,c))
        {
            fseek(fp1,0,SEEK_CUR);
            long int a=ftell(fp1);
            ch=getc(fp1);
            fseek(fp1,a,SEEK_SET);
            fscanf(fp1,"%s %s %s %s %d %s",hname1,hname2,hname3,city,&n1,star);
        }
        else
        {
                gotoxy(25,y3);
                cout<<i<<". "<<hname1<<" "<<hname2<<" "<<hname3;
                i++;
                gotoxy(80,y3);
                cout<<city;
                gotoxy(120,y3);
                cout<<n1<<" Star";
                y3=y3+2;
                fseek(fp1,0,SEEK_CUR);
                long int a=ftell(fp1);
                ch=getc(fp1);
                fseek(fp1,a,SEEK_SET);
                fscanf(fp1,"%s %s %s %s %d %s",hname1,hname2,hname3,city,&n1,star);
        }
    }
    fclose(fp1);
    int x2=9,y2=10;
    gotoxy(x2,y2);
    char ch1=_getch();
    while(ch1!=13 && ch1!=8)
    {
        ch1=_getch();
        switch(ch1)
        {
            case 75:if(x2==9)
                        break;
                    else
                    {
                        x2=9;
                        gotoxy(x2,y2);
                        break;
                    }
            case 77:if(x2==110)
                       break;
                    else
                    {
                        x2=110;
                        gotoxy(x2,y2);
                        break;
                    }
            case 72:if(y2==10)
                        {
                         //   y2=19;
                            break;
                        }
                    else
                    {
                        if(y2==19)
                           {
                             y2=10;
                             x2=9;
                             gotoxy(x2,y2);
                           }
                        else
                        { y2=y2-2;
                          gotoxy(x2,y2);
                        }
                        break;
                    }
            case 80:if(y2==21)
                      break;
                    else
                    {
                        if(y2==10)
                            {
                                y2=19;
                                x2=19;
                                gotoxy(x2,y2);
                            }
                        else
                        { y2=y2+2;
                          gotoxy(x2,y2);
                        }
                        break;
                    }
    }
}
if(ch1==8)
    design();
else
{
    switch(x2)
    {
        case 110:click1();break;
        case 9:switch(y2)
                {
                   case 10:searchpage();search();break;

                }
                break;
        case 19:switch(y2)
                {
                    case 19:bookingroom();break;
                   case 21:bookingroom();break;
                }
                break;
    }
}
}
void mumbai()
{
    searchpage();
    FILE *fp1;
    char hname1[10],hname2[10],hname3[10],city[10],star[6],c[]="mumbai";
    int n1;

    gotoxy(25,17);
    cout<<"Hotel Name";
    gotoxy(80,17);
    cout<<"City";
    gotoxy(120,17);
    cout<<"Star";
    gotoxy(110,10);
    cout<<"Mumbai ";
    if((fp1=fopen("HOTEL.txt","r"))==NULL)
    {
        cout<<"NO";
    }
    fseek(fp1,0,SEEK_SET);
    char ch=getc(fp1);
    fseek(fp1,0,SEEK_SET);
    fscanf(fp1,"%s %s %s %s %d %s",hname1,hname2,hname3,city,&n1,star);
    gotoxy(25,25);
    //cout<<hname1<<hname2<<hname3;
    int count=0,y3=19,i=1;
    while(ch!=EOF)
    {
        if(strcmp(city,c))
        {
            fseek(fp1,0,SEEK_CUR);
            long int a=ftell(fp1);
            ch=getc(fp1);
            fseek(fp1,a,SEEK_SET);
            fscanf(fp1,"%s %s %s %s %d %s",hname1,hname2,hname3,city,&n1,star);
        }
        else
        {
                gotoxy(25,y3);
                cout<<i<<". "<<hname1<<" "<<hname2<<" "<<hname3;
                i++;
                gotoxy(80,y3);
                cout<<city;
                gotoxy(120,y3);
                cout<<n1<<" Star";
                y3=y3+2;
                fseek(fp1,0,SEEK_CUR);
                long int a=ftell(fp1);
                ch=getc(fp1);
                fseek(fp1,a,SEEK_SET);
                fscanf(fp1,"%s %s %s %s %d %s",hname1,hname2,hname3,city,&n1,star);
        }
    }
    fclose(fp1);
    int x2=9,y2=10;
    gotoxy(x2,y2);
    char ch1=_getch();
    while(ch1!=13 && ch1!=8)
    {
        ch1=_getch();
        switch(ch1)
        {
            case 75:if(x2==9)
                        break;
                    else
                    {
                        x2=9;
                        gotoxy(x2,y2);
                        break;
                    }
            case 77:if(x2==110)
                       break;
                    else
                    {
                        x2=110;
                        gotoxy(x2,y2);
                        break;
                    }
            case 72:if(y2==10)
                        {
                         //   y2=19;
                            break;
                        }
                    else
                    {
                        if(y2==19)
                           {
                             y2=10;
                             x2=9;
                             gotoxy(x2,y2);
                           }
                        else
                        { y2=y2-2;
                          gotoxy(x2,y2);
                        }
                        break;
                    }
            case 80:if(y2==23)
                      break;
                    else
                    {
                        if(y2==10)
                            {
                                y2=19;
                                x2=19;
                                gotoxy(x2,y2);
                            }
                        else
                        { y2=y2+2;
                          gotoxy(x2,y2);
                        }
                        break;
                    }
    }
}
if(ch1==8)
    design();
else
{
    switch(x2)
    {
        case 110:click1();break;
        case 9:switch(y2)
                {
                   case 10:searchpage();search();break;

                }
                break;
        case 19:switch(y2)
                {
                    case 19:
                   case 21:
                    case 23: bookingroom();break;
                }
    }
}
}
void surat();
void sr_surat()
{
    searchpage();
    FILE *fp1;
    char hname1[10],hname2[10],hname3[10],city[10],star[6],c[]="surat";
    int n1;

    gotoxy(25,17);
    cout<<"Hotel Name";
    gotoxy(80,17);
    cout<<"City";
    gotoxy(120,17);
    cout<<"Star";
    gotoxy(19,10);
    cout<<h_name1<<" "<<h_name2<<" "<<h_name3;
    gotoxy(110,10);
    cout<<"surat ";
    if((fp1=fopen("HOTEL.txt","r"))==NULL)
    {
        cout<<"NO";
    }
    fseek(fp1,0,SEEK_SET);
    char ch=getc(fp1);
    fseek(fp1,0,SEEK_SET);
    fscanf(fp1,"%s %s %s %s %d %s",hname1,hname2,hname3,city,&n1,star);
    gotoxy(25,25);
    //cout<<hname1<<hname2<<hname3;
    int count=0,y3=19,i=1;
    while(ch!=EOF)
    {
        if(strcmp(hname1,h_name1) ||strcmp(hname2,h_name2) || strcmp(hname3,h_name3)|| strcmp(city,c))
        {
            fseek(fp1,0,SEEK_CUR);
            long int a=ftell(fp1);
            ch=getc(fp1);
            fseek(fp1,a,SEEK_SET);
            fscanf(fp1,"%s %s %s %s %d %s",hname1,hname2,hname3,city,&n1,star);
        }
        else
        {
                gotoxy(25,y3);
                cout<<i<<". "<<hname1<<" "<<hname2<<" "<<hname3;
                i++;
                gotoxy(80,y3);
                cout<<city;
                gotoxy(120,y3);
                cout<<n1<<" Star";
                y3=y3+2;
                fseek(fp1,0,SEEK_CUR);
                long int a=ftell(fp1);
                ch=getc(fp1);
                fseek(fp1,a,SEEK_SET);
                fscanf(fp1,"%s %s %s %s %d %s",hname1,hname2,hname3,city,&n1,star);
        }
    }
    fclose(fp1);
    int x2=9,y2=10;
    gotoxy(x2,y2);
    char ch1=_getch();
    while(ch1!=13 && ch1!=8)
    {
        ch1=_getch();
        switch(ch1)
        {
            case 75:if(x2==9)
                        break;
                    else
                    {
                        x2=9;
                        gotoxy(x2,y2);
                        break;
                    }
            case 77:if(x2==110)
                       break;
                    else
                    {
                        x2=110;
                        gotoxy(x2,y2);
                        break;
                    }
            case 72:if(y2==10)
                        {
                         //   y2=19;
                            break;
                        }
                    else
                    {
                        if(y2==19)
                           {
                             y2=10;
                             x2=9;
                             gotoxy(x2,y2);
                           }
                        else
                        { y2=y2-2;
                          gotoxy(x2,y2);
                        }
                        break;
                    }
            case 80:if(y2==19)
                      break;
                    else
                    {
                        if(y2==10)
                            {
                                y2=19;
                                x2=19;
                                gotoxy(x2,y2);
                            }
                        else
                        { y2=y2+2;
                          gotoxy(x2,y2);
                        }
                        break;
                    }
    }
}
if(ch1==8)
    design();
else
{
    switch(x2)
    {
        case 110:click();break;
        case 9:switch(y2)
                {
                   case 10:searchpage();search();break;
                }
                break;
        case 19:switch(y2)
                {
                    case 19:bookingroom();break;
                }
                break;
    }
}
}
void sr_vadodara()
{
    searchpage();
    FILE *fp1;
    char hname1[10],hname2[10],hname3[10],city[10],star[6],c[]="vadodara";
    int n1;

    gotoxy(25,17);
    cout<<"Hotel Name";
    gotoxy(80,17);
    cout<<"City";
    gotoxy(120,17);
    cout<<"Star";
    gotoxy(19,10);
    cout<<h_name1<<" "<<h_name2<<" "<<h_name3;
    gotoxy(110,10);
    cout<<"Vadodara";
    if((fp1=fopen("HOTEL.txt","r"))==NULL)
    {
        cout<<"NO";
    }
    fseek(fp1,0,SEEK_SET);
    char ch=getc(fp1);
    fseek(fp1,0,SEEK_SET);
    fscanf(fp1,"%s %s %s %s %d %s",hname1,hname2,hname3,city,&n1,star);
    gotoxy(25,25);
    //cout<<hname1<<hname2<<hname3;
    int count=0,y3=19,i=1;
    while(ch!=EOF)
    {
        if(strcmp(hname1,h_name1) ||strcmp(hname2,h_name2) || strcmp(hname3,h_name3)|| strcmp(city,c))
        {
            fseek(fp1,0,SEEK_CUR);
            long int a=ftell(fp1);
            ch=getc(fp1);
            fseek(fp1,a,SEEK_SET);
            fscanf(fp1,"%s %s %s %s %d %s",hname1,hname2,hname3,city,&n1,star);
        }
        else
        {
                gotoxy(25,y3);
                cout<<i<<". "<<hname1<<" "<<hname2<<" "<<hname3;
                i++;
                gotoxy(80,y3);
                cout<<city;
                gotoxy(120,y3);
                cout<<n1<<" Star";
                y3=y3+2;
                fseek(fp1,0,SEEK_CUR);
                long int a=ftell(fp1);
                ch=getc(fp1);
                fseek(fp1,a,SEEK_SET);
                fscanf(fp1,"%s %s %s %s %d %s",hname1,hname2,hname3,city,&n1,star);
        }
    }
    fclose(fp1);
    int x2=9,y2=10;
    gotoxy(x2,y2);
    char ch1=_getch();
    while(ch1!=13 && ch1!=8)
    {
        ch1=_getch();
        switch(ch1)
        {
            case 75:if(x2==9)
                        break;
                    else
                    {
                        x2=9;
                        gotoxy(x2,y2);
                        break;
                    }
            case 77:if(x2==110)
                       break;
                    else
                    {
                        x2=110;
                        gotoxy(x2,y2);
                        break;
                    }
            case 72:if(y2==10)
                        {
                         //   y2=19;
                            break;
                        }
                    else
                    {
                        if(y2==19)
                           {
                             y2=10;
                             x2=9;
                             gotoxy(x2,y2);
                           }
                        else
                        { y2=y2-2;
                          gotoxy(x2,y2);
                        }
                        break;
                    }
            case 80:if(y2==19)
                      break;
                    else
                    {
                        if(y2==10)
                            {
                                y2=19;
                                x2=19;
                                gotoxy(x2,y2);
                            }
                        else
                        { y2=y2+2;
                          gotoxy(x2,y2);
                        }
                        break;
                    }
    }
}
if(ch1==8)
    design();
else
{
    switch(x2)
    {
        case 110:click();break;
        case 9:switch(y2)
                {
                   case 10:searchpage();search();break;

                }
                break;
        case 19:switch(y2)
                {
                    case 19:bookingroom();break;
                }
                break;
    }
}
}
void sr_mumbai()
{
    searchpage();
    FILE *fp1;
    char hname1[10],hname2[10],hname3[10],city[10],star[6],c[]="mumbai";
    int n1;

    gotoxy(25,17);
    cout<<"Hotel Name";
    gotoxy(80,17);
    cout<<"City";
    gotoxy(120,17);
    cout<<"Star";
    gotoxy(19,10);
    cout<<h_name1<<" "<<h_name2<<" "<<h_name3;
    gotoxy(110,10);
    cout<<"Mumbai ";
    if((fp1=fopen("HOTEL.txt","r"))==NULL)
    {
        cout<<"NO";
    }
    fseek(fp1,0,SEEK_SET);
    char ch=getc(fp1);
    fseek(fp1,0,SEEK_SET);
    fscanf(fp1,"%s %s %s %s %d %s",hname1,hname2,hname3,city,&n1,star);
    gotoxy(25,25);
    //cout<<hname1<<hname2<<hname3;
    int count=0,y3=19,i=1;
    while(ch!=EOF)
    {
        if(strcmp(hname1,h_name1) ||strcmp(hname2,h_name2) || strcmp(hname3,h_name3)|| strcmp(city,c))
        {
            fseek(fp1,0,SEEK_CUR);
            long int a=ftell(fp1);
            ch=getc(fp1);
            fseek(fp1,a,SEEK_SET);
            fscanf(fp1,"%s %s %s %s %d %s",hname1,hname2,hname3,city,&n1,star);
        }
        else
        {
                gotoxy(25,y3);
                cout<<i<<". "<<hname1<<" "<<hname2<<" "<<hname3;
                i++;
                gotoxy(80,y3);
                cout<<city;
                gotoxy(120,y3);
                cout<<n1<<" Star";
                y3=y3+2;
                fseek(fp1,0,SEEK_CUR);
                long int a=ftell(fp1);
                ch=getc(fp1);
                fseek(fp1,a,SEEK_SET);
                fscanf(fp1,"%s %s %s %s %d %s",hname1,hname2,hname3,city,&n1,star);
        }
    }
    fclose(fp1);
    int x2=9,y2=10;
    gotoxy(x2,y2);
    char ch1=_getch();
    while(ch1!=13 && ch1!=8)
    {
        ch1=_getch();
        switch(ch1)
        {
            case 75:if(x2==9)
                        break;
                    else
                    {
                        x2=9;
                        gotoxy(x2,y2);
                        break;
                    }
            case 77:if(x2==110)
                       break;
                    else
                    {
                        x2=110;
                        gotoxy(x2,y2);
                        break;
                    }
            case 72:if(y2==10)
                        {
                         //   y2=19;
                            break;
                        }
                    else
                    {
                        if(y2==19)
                           {
                             y2=10;
                             x2=9;
                             gotoxy(x2,y2);
                           }
                        else
                        { y2=y2-2;
                          gotoxy(x2,y2);
                        }
                        break;
                    }
            case 80:if(y2==19)
                      break;
                    else
                    {
                        if(y2==10)
                            {
                                y2=19;
                                x2=19;
                                gotoxy(x2,y2);
                            }
                        else
                        { y2=y2+2;
                          gotoxy(x2,y2);
                        }
                        break;
                    }
    }
}
if(ch1==8)
    design();
else
{
    switch(x2)
    {
        case 110:click();break;
        case 9:switch(y2)
                {
                   case 10:searchpage();search();break;
                }
                break;
        case 19:switch(y2)
                {
                    case 19:bookingroom();break;
                }
                break;
    }
}
}
void doubleclick()
{

    int x1=108,y1=9;
    char c1=205,d1=187,e1=186,f1=188,h1=200,g1=201;
    gotoxy(20,9);
    for(int i=0;i<9;i++)
    {
        x1++;
        gotoxy(x1,y1);
        cout<<" ";
    }
    x1++;
    gotoxy(x1,y1);
    cout<<" ";
    for(int i=0;i<4;i++)
    {
        y1++;
        gotoxy(x1,y1);
        cout<<" ";
    }
    y1++;
    gotoxy(x1,y1);
    cout<<" ";
    for(int i=0;i<9;i++)
    {
        x1--;
        gotoxy(x1,y1);
        cout<<" ";
    }
    x1--;
    gotoxy(x1,y1);
    cout<<" ";
    for(int i=0;i<4;i++)
    {
        y1--;
        gotoxy(x1,y1);
        cout<<" ";
    }
    y1--;
    gotoxy(x1,y1);
    cout<<" ";
    gotoxy(110,10);
    cout<<"        ";
    gotoxy(110,11);
    cout<<"        ";
    gotoxy(110,12);
    cout<<"        ";
    gotoxy(110,13);
    cout<<"        ";
    x1=108;y1=9;
    gotoxy(20,9);
    for(int i=0;i<9;i++)
    {
        x1++;
        gotoxy(x1,y1);
        cout<<c1;
    }
    x1++;
    gotoxy(x1,y1);
    cout<<d1;
    for(int i=0;i<1;i++)
    {
        y1++;
        gotoxy(x1,y1);
        cout<<e1;
    }
    y1++;
    gotoxy(x1,y1);
    cout<<f1;
    for(int i=0;i<9;i++)
    {
        x1--;
        gotoxy(x1,y1);
        cout<<c1;
    }
    x1--;
    gotoxy(x1,y1);
    cout<<h1;
    for(int i=0;i<1;i++)
    {
        y1--;
        gotoxy(x1,y1);
        cout<<e1;
    }
    y1--;
    gotoxy(x1,y1);
    cout<<g1;
    // ggetch();
    gotoxy(110,10);
    cout<<"CITIES";
    int x2=9,y2=10;
    gotoxy(x2,y2);
    char ch=_getch();
    while(ch!=13 && ch!=8)
    {
        ch=_getch();
        switch(ch)
        {
            case 75:if(x2==9)
                        break;
                    else
                    {
                        x2=9;
                        gotoxy(x2,y2);
                        break;
                    }
            case 77:if(x2==110)
                       break;
                    else
                    {
                        x2=110;
                        gotoxy(x2,y2);
                        break;
                    }
            case 72:if(y2==10)
                        {
                         //   y2=19;
                            break;
                        }
                    else
                    {
                        if(y2==19)
                           {
                             y2=10;
                             x2=9;
                             gotoxy(x2,y2);
                           }
                        else
                        { y2=y2-2;
                          gotoxy(x2,y2);
                        }
                        break;
                    }
            case 80:if(y2==23)
                      break;
                    else
                    {
                        if(y2==10)
                            {
                                y2=19;
                                x2=19;
                                gotoxy(x2,y2);
                            }
                        else
                        { y2=y2+2;
                          gotoxy(x2,y2);
                        }
                        break;
                    }
    }
}
if(ch==8)
    design();
else
{
    switch(x2)
    {
        case 110:click();break;
        case 9:switch(y2)
                {
                   case 10:searchpage();search();break;

                }
                break;

        case 19:switch(y2)
                {
                   case 19:
                   case 21:
                   case 23:bookingroom();break;
                }
    }
  }
}
void click1()
{
    int x1=108,y1=9;
    char c1=205,d1=187,e1=186,f1=188,h1=200,g1=201;
    gotoxy(20,9);
    for(int i=0;i<9;i++)
    {
        x1++;
        gotoxy(x1,y1);
        cout<<c1;
    }
    x1++;
    gotoxy(x1,y1);
    cout<<d1;
    for(int i=0;i<4;i++)
    {
        y1++;
        gotoxy(x1,y1);
        cout<<e1;
    }
    y1++;
    gotoxy(x1,y1);
    cout<<f1;
    for(int i=0;i<9;i++)
    {
        x1--;
        gotoxy(x1,y1);
        cout<<c1;
    }
    x1--;
    gotoxy(x1,y1);
    cout<<h1;
    for(int i=0;i<4;i++)
    {
        y1--;
        gotoxy(x1,y1);
        cout<<e1;
    }
    y1--;
    gotoxy(x1,y1);
    cout<<g1;
    // ggetch();
    gotoxy(110,10);
    cout<<"CITIES  ";
    gotoxy(110,11);
    cout<<" \b\b SURAT   ";
    gotoxy(110,12);
    cout<<"VADODARA";
    gotoxy(110,13);
    cout<<"MUMBAI";
     int x2=110,y2=10;
    gotoxy(x2,y2);
    char ch=_getch();
    while(ch!=13)
    {
        ch=_getch();
        switch(ch)
        {
            case 72:if(y2==10)
                        break;
                    else
                    {
                       y2--;
                       gotoxy(x2,y2);
                       break;
                    }
            case 80:if(y2==13)
                        break;
                    else
                    {
                        y2++;
                        gotoxy(x2,y2);
                        break;
                    }
        }
    }
switch(y2)
{
    case 10:doubleclick();break;
    case 11:surat();break;
    case 12:vadodara();break;
    case 13:mumbai();break;
}
}
void click()
{
    int x1=108,y1=9;
    char c1=205,d1=187,e1=186,f1=188,h1=200,g1=201;
    gotoxy(20,9);
    for(int i=0;i<9;i++)
    {
        x1++;
        gotoxy(x1,y1);
        cout<<c1;
    }
    x1++;
    gotoxy(x1,y1);
    cout<<d1;
    for(int i=0;i<4;i++)
    {
        y1++;
        gotoxy(x1,y1);
        cout<<e1;
    }
    y1++;
    gotoxy(x1,y1);
    cout<<f1;
    for(int i=0;i<9;i++)
    {
        x1--;
        gotoxy(x1,y1);
        cout<<c1;
    }
    x1--;
    gotoxy(x1,y1);
    cout<<h1;
    for(int i=0;i<4;i++)
    {
        y1--;
        gotoxy(x1,y1);
        cout<<e1;
    }
    y1--;
    gotoxy(x1,y1);
    cout<<g1;
    // ggetch();
    gotoxy(110,10);
    cout<<"CITIES  ";
    gotoxy(110,11);
    cout<<" \b\b SURAT   ";
    gotoxy(110,12);
    cout<<"VADODARA";
    gotoxy(110,13);
    cout<<"MUMBAI";
     int x2=110,y2=10;
    gotoxy(x2,y2);
    char ch=_getch();
    while(ch!=13)
    {
        ch=_getch();
        switch(ch)
        {
            case 72:if(y2==10)
                        break;
                    else
                    {
                       y2--;
                       gotoxy(x2,y2);
                       break;
                    }
            case 80:if(y2==13)
                        break;
                    else
                    {
                        y2++;
                        gotoxy(x2,y2);
                        break;
                    }
        }
    }
switch(y2)
{
    case 10:doubleclick();break;
    case 11:sr_surat();break;
    case 12:sr_vadodara();break;
    case 13:sr_mumbai();break;
}
}
void hotels()
{
    gotoxy(25,17);
    cout<<"Hotel Name";
    gotoxy(80,17);
    cout<<"City";
    gotoxy(120,17);
    cout<<"Star";

     gotoxy(20,19);
     cout<<"1.      T G B";
     gotoxy(80,19);
     cout<<"surat";
     gotoxy(120,19);
     cout<<"5 star";

     gotoxy(20,21);
     cout<<"2.      Hot & Spice";
     gotoxy(80,21);
     cout<<"mumbai";
     gotoxy(120,21);
     cout<<"4 star";


     gotoxy(20,23);
     cout<<"3.      Sugar & Spice";
     gotoxy(80,23);
     cout<<"surat";
     gotoxy(120,23);
     cout<<"5 star";


     gotoxy(20,25);
     cout<<"4.      T G B";
     gotoxy(80,25);
     cout<<"mumbai";
     gotoxy(120,25);
     cout<<"5 star";


     gotoxy(20,27);
     cout<<"5.      Jack Roll Jack";
     gotoxy(80,27);
     cout<<"mumbai";
     gotoxy(120,27);
     cout<<"3 star";


     gotoxy(20,29);
     cout<<"6.      T G B";
     gotoxy(80,29);
     cout<<"vadodara";
     gotoxy(120,29);
     cout<<"5 star";


     gotoxy(20,31);
     cout<<"7.      Four Star Hotel";
     gotoxy(80,31);
     cout<<"surat";
     gotoxy(120,31);
     cout<<"3.5 star";


     gotoxy(20,33);
     cout<<"8.      Hot & Spice";
     gotoxy(80,33);
     cout<<"surat";
     gotoxy(120,33);
     cout<<"4 star";


     gotoxy(20,35);
     cout<<"9.      Hot & Spice";
     gotoxy(80,35);
     cout<<"vadodara";
     gotoxy(120,35);
     cout<<"5 star";
}
void surat()
{
    searchpage();
    FILE *fp1;
    char hname1[10],hname2[10],hname3[10],city[10],star[6],c[]="surat";
    int n1;

    gotoxy(25,17);
    cout<<"Hotel Name";
    gotoxy(80,17);
    cout<<"City";
    gotoxy(120,17);
    cout<<"Star";
    gotoxy(110,10);
    cout<<"surat ";
    if((fp1=fopen("HOTEL.txt","r"))==NULL)
    {
        cout<<"NO";
    }
    fseek(fp1,0,SEEK_SET);
    char ch=getc(fp1);
    fseek(fp1,0,SEEK_SET);
    fscanf(fp1,"%s %s %s %s %d %s",hname1,hname2,hname3,city,&n1,star);
    gotoxy(25,25);
    //cout<<hname1<<hname2<<hname3;
    int count=0,y3=19,i=1;
    while(ch!=EOF)
    {
        if(strcmp(city,c))
        {
            fseek(fp1,0,SEEK_CUR);
            long int a=ftell(fp1);
            ch=getc(fp1);
            fseek(fp1,a,SEEK_SET);
            fscanf(fp1,"%s %s %s %s %d %s",hname1,hname2,hname3,city,&n1,star);
        }
        else
        {
                gotoxy(25,y3);
                cout<<i<<". "<<hname1<<" "<<hname2<<" "<<hname3;
                i++;
                gotoxy(80,y3);
                cout<<city;
                gotoxy(120,y3);
                cout<<n1<<" Star";
                y3=y3+2;
                fseek(fp1,0,SEEK_CUR);
                long int a=ftell(fp1);
                ch=getc(fp1);
                fseek(fp1,a,SEEK_SET);
                fscanf(fp1,"%s %s %s %s %d %s",hname1,hname2,hname3,city,&n1,star);
        }
    }
    fclose(fp1);
    int x2=9,y2=10;
    gotoxy(x2,y2);
    char ch1=_getch();
    while(ch1!=13 && ch1!=8)
    {
        ch1=_getch();
        switch(ch1)
        {
            case 75:if(x2==9)
                        break;
                    else
                    {
                        x2=9;
                        gotoxy(x2,y2);
                        break;
                    }
            case 77:if(x2==110)
                       break;
                    else
                    {
                        x2=110;
                        gotoxy(x2,y2);
                        break;
                    }
            case 72:if(y2==10)
                        {
                         //   y2=19;
                            break;
                        }
                    else
                    {
                        if(y2==19)
                           {
                             y2=10;
                             x2=9;
                             gotoxy(x2,y2);
                           }
                        else
                        { y2=y2-2;
                          gotoxy(x2,y2);
                        }
                        break;
                    }
            case 80:if(y2==25)
                      break;
                    else
                    {
                        if(y2==10)
                            {
                                y2=19;
                                x2=19;
                                gotoxy(x2,y2);
                            }
                        else
                        { y2=y2+2;
                          gotoxy(x2,y2);
                        }
                        break;
                    }
    }
}
if(ch1==8)
    design();
else
{
    switch(x2)
    {
        case 110:click1();break;
        case 9:switch(y2)
                {
                   case 10:searchpage();search();break;

                }
                break;
        case 19:switch(y2)
                {
                   case 19:
                   case 21:
                   case 23:
                   case 25: bookingroom();break;
                }
                break;
    }
}
}
void search()
{
    FILE *fp1;
    char hotelname1[10],hotelname2[10],hotelname3[10],hname1[10],hname2[10],hname3[10],city[10],star[6];
    int n1;

    gotoxy(25,17);
    cout<<"Hotel Name";
    gotoxy(80,17);
    cout<<"City";
    gotoxy(120,17);
    cout<<"Star";
    gotoxy(19,10);
    cin>>hotelname1>>hotelname2>>hotelname3;
    h_name1=hotelname1;
    h_name2=hotelname2;
    h_name3=hotelname3;
    if((fp1=fopen("HOTEL.txt","r"))==NULL)
    {
        cout<<"NO";
    }
    fseek(fp1,0,SEEK_SET);
    char ch=getc(fp1);
    fseek(fp1,0,SEEK_SET);
    fscanf(fp1,"%s %s %s %s %d %s",hname1,hname2,hname3,city,&n1,star);
    gotoxy(25,25);
    //cout<<hname1[2]<<hname2<<hname3;
    int count=0,y3=19,i=1;
    while(ch!=EOF)
    {
        if(strcmp(hname1,hotelname1) || strcmp(hname2,hotelname2)|| strcmp(hname3,hotelname3))
        {
            fseek(fp1,0,SEEK_CUR);
            long int a=ftell(fp1);
            ch=getc(fp1);
            fseek(fp1,a,SEEK_SET);
            fscanf(fp1,"%s %s %s %s %d %s",hname1,hname2,hname3,city,&n1,star);
        }
        else
        {
                gotoxy(25,y3);
                cout<<i<<". "<<hname1<<" "<<hname2<<" "<<hname3;
                i++;
                gotoxy(80,y3);
                cout<<city;
                gotoxy(120,y3);
                cout<<n1<<" Star";
                y3=y3+2;
                fseek(fp1,0,SEEK_CUR);
                long int a=ftell(fp1);
                ch=getc(fp1);
                fseek(fp1,a,SEEK_SET);
                fscanf(fp1,"%s %s %s %s %d %s",hname1,hname2,hname3,city,&n1,star);
        }
    }

    fclose(fp1);
    gotoxy(9,10);
    char ch2=_getch();
    int y2=10,x2=9;
    while(ch2!=13 && ch2!=8)
    {
       ch2=_getch();
        switch(ch2)
        {
            case 75:if(x2==9)
                        break;
                    else
                    {
                        x2=9;
                        gotoxy(x2,y2);
                        break;
                    }
            case 77:if(x2==110)
                       break;
                    else
                    {
                        x2=110;
                        gotoxy(x2,y2);
                        break;
                    }
            case 72:if(y2==10)
                        {
                         //   y2=19;
                            break;
                        }
                    else
                    {
                        if(y2==19)
                           {
                             y2=10;
                             x2=9;
                             gotoxy(x2,y2);
                           }
                        else
                        { y2=y2-2;
                          gotoxy(x2,y2);
                        }
                        break;
                    }
            case 80:if(y2==23)
                      break;
                    else
                    {
                        if(y2==10)
                            {
                                y2=19;
                                x2=19;
                                gotoxy(x2,y2);
                            }
                        else
                        { y2=y2+2;
                          gotoxy(x2,y2);
                        }
                        break;
                    }
        }
    }
    if(ch2==8)
    {
        design();
    }
    switch(x2)
    {
        case 110:click();break;
        case 9:switch(y2)
                {
                   case 10:searchpage();break;
                }
                break;
        case 19:switch(y2)
                {
                   case 19:
                   case 21:
                   case 23:bookingroom();break;
                }
                break;
    }

}
void searchpage()
{
        system("cls");
    gotoxy(75,5);
    cout<<"...Choose Your Hotel...";
    int x=18,y=9;
    char c=196,d=191,e=179,f=217,h=192,g=218;
    gotoxy(20,9);
    for(int i=0;i<45;i++)
    {
        cout<<c;
        x++;
        gotoxy(x,y);
    }
    cout<<d;
    for(int i=0;i<1;i++)
    {
        y++;
        gotoxy(x,y);
        cout<<e;
    }
    y++;
    gotoxy(x,y);
    cout<<f;
    for(int i=0;i<44;i++)
    {
        x--;
        gotoxy(x,y);
        cout<<c;
    }
    x--;
    gotoxy(x,y);
    cout<<h;
    for(int i=0;i<1;i++)
    {
        y--;
        gotoxy(x,y);
        cout<<e;
    }
    y--;
    gotoxy(x,y);
    cout<<g;
    gotoxy(10,10);
    cout<<"Search";

    int x1=108,y1=9;
    char c1=205,d1=187,e1=186,f1=188,h1=200,g1=201;
    gotoxy(20,9);
    for(int i=0;i<9;i++)
    {
        x1++;
        gotoxy(x1,y1);
        cout<<c1;
    }
    x1++;
    gotoxy(x1,y1);
    cout<<d1;
    for(int i=0;i<1;i++)
    {
        y1++;
        gotoxy(x1,y1);
        cout<<e1;
    }
    y1++;
    gotoxy(x1,y1);
    cout<<f1;
    for(int i=0;i<9;i++)
    {
        x1--;
        gotoxy(x1,y1);
        cout<<c1;
    }
    x1--;
    gotoxy(x1,y1);
    cout<<h1;
    for(int i=0;i<1;i++)
    {
        y1--;
        gotoxy(x1,y1);
        cout<<e1;
    }
    y1--;
    gotoxy(x1,y1);
    cout<<g1;
    // ggetch();
    gotoxy(110,10);
    cout<<"CITIES";

    //search();
}
void design()
{
    system("cls");
    gotoxy(75,5);
    FILE *fp ,*fp1;
    fp=fopen("HOTEL.txt","w");
    fprintf(fp,"T G B vadodara 5 star\nHot And Spice mumbai 4 star\nSugar And Spice surat 5 star\nT G B mumbai 5 star\nJack Roll Jack mumbai 3 star\nT G B surat 5 star\nFour Star Hotel surat 3 star\nHot And Spice surat 4 star\nHot And Spice vadodara 5 star");
    fclose(fp);
    cout<<"...Choose Your Hotel...";
    int x=18,y=9;
    char c=196,d=191,e=179,f=217,h=192,g=218;
    gotoxy(20,9);
    for(int i=0;i<45;i++)
    {
        cout<<c;
        x++;
        gotoxy(x,y);
    }
    cout<<d;
    for(int i=0;i<1;i++)
    {
        y++;
        gotoxy(x,y);
        cout<<e;
    }
    y++;
    gotoxy(x,y);
    cout<<f;
    for(int i=0;i<44;i++)
    {
        x--;
        gotoxy(x,y);
        cout<<c;
    }
    x--;
    gotoxy(x,y);
    cout<<h;
    for(int i=0;i<1;i++)
    {
        y--;
        gotoxy(x,y);
        cout<<e;
    }
    y--;
    gotoxy(x,y);
    cout<<g;
    gotoxy(10,10);
    cout<<"Search";

    int x1=108,y1=9;
    char c1=205,d1=187,e1=186,f1=188,h1=200,g1=201;
    gotoxy(20,9);
    for(int i=0;i<9;i++)
    {
        x1++;
        gotoxy(x1,y1);
        cout<<c1;
    }
    x1++;
    gotoxy(x1,y1);
    cout<<d1;
    for(int i=0;i<1;i++)
    {
        y1++;
        gotoxy(x1,y1);
        cout<<e1;
    }
    y1++;
    gotoxy(x1,y1);
    cout<<f1;
    for(int i=0;i<9;i++)
    {
        x1--;
        gotoxy(x1,y1);
        cout<<c1;
    }
    x1--;
    gotoxy(x1,y1);
    cout<<h1;
    for(int i=0;i<1;i++)
    {
        y1--;
        gotoxy(x1,y1);
        cout<<e1;
    }
    y1--;
    gotoxy(x1,y1);
    cout<<g1;
    // ggetch();
    gotoxy(110,10);
    cout<<"CITIES";

    hotels();

    int x2=9,y2=10;
    gotoxy(x2,y2);
    char ch=_getch();
    while(ch!=13 && ch!=8)
    {
        ch=_getch();
        switch(ch)
        {
            case 75:if(x2==9)
                        break;
                    else
                    {
                        x2=9;
                        gotoxy(x2,y2);
                        break;
                    }
            case 77:if(x2==110)
                       break;
                    else
                    {
                        x2=110;
                        gotoxy(x2,y2);
                        break;
                    }
            case 72:if(y2==10)
                        {
                         //   y2=19;
                            break;
                        }
                    else
                    {
                        if(y2==19)
                           {
                             y2=10;
                             x2=9;
                             gotoxy(x2,y2);
                           }
                        else
                        { y2=y2-2;
                          gotoxy(x2,y2);
                        }
                        break;
                    }
            case 80:if(y2==35)
                      break;
                    else
                    {
                        if(y2==10)
                            {
                                y2=19;
                                x2=19;
                                gotoxy(x2,y2);
                            }
                        else
                        { y2=y2+2;
                          gotoxy(x2,y2);
                        }
                        break;
                    }
    }
}
if(ch==8)
    homepage();
else
{
    switch(x2)
    {
        case 110:clickdesign();break;
        case 9:
                switch(y2)
                {
                   case 10:searchpage();search();break;

                }
                break;
        case 19: switch(y2)
                  {
                   case 19:bookingroom();break;
                   case 21:bookingroom();break;
                   case 23:bookingroom();break;
                   case 25:bookingroom();break;
                   case 27:bookingroom();break;
                   case 29:bookingroom();break;
                   case 31:bookingroom();break;
                   case 33:bookingroom();break;
                   case 35:bookingroom();break;
                  }

                break;
    }
   }
}
void clickdesign()
{
    system("cls");
    gotoxy(75,5);
    cout<<"...Choose Your Hotel...";
    int x=18,y=9;
    char c=196,d=191,e=179,f=217,h=192,g=218;
    gotoxy(20,9);
    for(int i=0;i<45;i++)
    {
        cout<<c;
        x++;
        gotoxy(x,y);
    }
    cout<<d;
    for(int i=0;i<1;i++)
    {
        y++;
        gotoxy(x,y);
        cout<<e;
    }
    y++;
    gotoxy(x,y);
    cout<<f;
    for(int i=0;i<44;i++)
    {
        x--;
        gotoxy(x,y);
        cout<<c;
    }
    x--;
    gotoxy(x,y);
    cout<<h;
    for(int i=0;i<1;i++)
    {
        y--;
        gotoxy(x,y);
        cout<<e;
    }
    y--;
    gotoxy(x,y);
    cout<<g;
    gotoxy(10,10);
    cout<<"Search";

    hotels();
    int x1=108,y1=9;
    char c1=205,d1=187,e1=186,f1=188,h1=200,g1=201;
    gotoxy(20,9);
    for(int i=0;i<9;i++)
    {
        x1++;
        gotoxy(x1,y1);
        cout<<c1;
    }
    x1++;
    gotoxy(x1,y1);
    cout<<d1;
    for(int i=0;i<4;i++)
    {
        y1++;
        gotoxy(x1,y1);
        cout<<e1;
    }
    y1++;
    gotoxy(x1,y1);
    cout<<f1;
    for(int i=0;i<9;i++)
    {
        x1--;
        gotoxy(x1,y1);
        cout<<c1;
    }
    x1--;
    gotoxy(x1,y1);
    cout<<h1;
    for(int i=0;i<4;i++)
    {
        y1--;
        gotoxy(x1,y1);
        cout<<e1;
    }
    y1--;
    gotoxy(x1,y1);
    cout<<g1;
    // ggetch();
    gotoxy(110,10);
    cout<<"CITIES";
    gotoxy(110,11);
    cout<<"SURAT";
    gotoxy(110,12);
    cout<<"VADODARA";
    gotoxy(110,13);
    cout<<"MUMBAI";
     int x2=110,y2=10;
    gotoxy(x2,y2);
    char ch=_getch();
    while(ch!=13)
    {
        ch=_getch();
        switch(ch)
        {
            case 72:if(y2==10)
                        break;
                    else
                    {
                       y2--;
                       gotoxy(x2,y2);
                       break;
                    }
            case 80:if(y2==13)
                        break;
                    else
                    {
                        y2++;
                        gotoxy(x2,y2);
                        break;
                    }
        }
    }
switch(y2)
{
    case 10:design();break;
    case 11:surat();break;
    case 12:vadodara();break;
    case 13:mumbai();break;
}
}
void room_booking()
{
    system("cls");
     design();

}
void before_room()
{
    system("cls");

    FILE *fp;
    if((fp=fopen("sign.txt","r"))==NULL)
    {
        cout<<"file not created";
        exit(0);
    }
    char s[15],pa[5],na[80],gender[8];
    char *pass=&password[0];
    char *un=&u_name[0];
    int age;
    fseek(fp,0,SEEK_SET);
    char ch=getc(fp);
    fseek(fp,0,SEEK_SET);
    fscanf(fp,"%s %d %s %s %s ",na,&age,gender,s,pa);
    //u_name=na;
    while(strcmp(pa,pass) || strcmp(s,un))
    {
        if(ch!=EOF)
        {
            fseek(fp,0,SEEK_CUR);
            long int a=ftell(fp);
            ch=getc(fp);
            fseek(fp,a,SEEK_SET);
            fscanf(fp,"%s %d %s %s %s ",na,&age,gender,s,pa);
        }
        else
        {
            break;
        }
    }



    gotoxy(75,20);
    char st[]="WELCOME ";
    char *st1=na;
    char *finall=strcat(st,st1);
    int length=strlen(finall);
    for(int i=0;i<length;i++)
    {
        for(int j=0;j<15000000;j++);
        finall[i]=toupper(finall[i]);
        cout<<finall[i];
    }
    //gotoxy(x,y);
    fclose(fp);
    for(int j=0;j<707000000;j++);
    room_booking();
}
void remove1(int n)
{
    fstream fp,fp1;
    fp.open("user.txt",ios::in);
    fp1.open("temp.txt",ios::out);
    string s1;
    int count=0;
    while(!fp.eof())
    {
        getline(fp,s1);
        if(s1[0]==u_name[0])
        {
            count++;
            if(count==n)
                continue;

        }
        fp1<<s1<<endl;
    }
    fp.close();
    fp1.close();

    fp.open("user.txt",ios::out);
    fp1.open("temp.txt",ios::in);
    while(!fp1.eof())
    {
        getline(fp1,s1);
        fp<<s1<<endl;
    }
    fp.close();
    //remove("temp.txt");
    fp1.close();
    booking_cancel();
}
void booking_cancel()
{
    system("cls");
    symbol();
    gotoxy(70,35);
    cout<<"Backspace - return to homepage";
    FILE *fp;
    fp=fopen("sign.txt","r");
    char un[15],pa[6],na[40],gender[8];
    char *pass=&password[0];
    int age;
    fseek(fp,0,SEEK_SET);
    char ch=getc(fp);
    fseek(fp,0,SEEK_SET);
    fscanf(fp,"%s %d %s %s %s ",na,&age,gender,un,pa);
    int count=0;
        while(strcmp(pass,pa))
        {
            if(ch!=EOF)
            {
                fseek(fp,0,SEEK_CUR);
                long int a=ftell(fp);
                ch=getc(fp);
                fseek(fp,a,SEEK_SET);
                fscanf(fp,"%s %d %s %s %s",na,&age,gender,un,pa);
            }
            else
            {
                count++;
                break;
            }

        }
    if(count==0)
    {
       gotoxy(10,19);
        cout<<"Name   : "<<na;
        gotoxy(10,20);
        cout<<"Age    : "<<age;
        gotoxy(10,21);
        cout<<"Gender : "<<gender<<endl<<endl;
        gotoxy(10,23);
        for(int i=0;i<143;i++)
            cout<<"-";
    }
   else
   {
       gotoxy(75,20);
        cout<<"no data found";
   }
    fclose(fp);

    fp=fopen("user.txt","r");
    char no[3],date1[9],date2[9],name[80],hotelname1[10],hotelname2[10],hotelname3[10];
    char *nana=&u_name[0];
    int person;
    fseek(fp,0,SEEK_SET);
    char ch1=getc(fp);
    fseek(fp,0,SEEK_SET);
    fscanf(fp,"%s %s %s %d %s %s %s %s",name,date1,date2,&person,no,hotelname1,hotelname2,hotelname3);
    int count1=0,i=1,x=10,y=27;
    gotoxy(x,y);
    cout<<"Sr.no";
    gotoxy(40,y);
    cout<<"Check In";
    gotoxy(70,y);
    cout<<"Check Out";
    gotoxy(100,y);
    cout<<"Persons";
    gotoxy(130,y);
    cout<<"Room No";
    gotoxy(150,y);
    cout<<"Hotel Name";
    y=30;
    while(ch1!=EOF)
    {
        if(strcmp(nana,name))
        {
            fseek(fp,0,SEEK_CUR);
            long int a=ftell(fp);
            ch1=getc(fp);
            fseek(fp,a,SEEK_SET);
            fscanf(fp,"%s %s %s %d %s %s %s %s",name,date1,date2,&person,no,hotelname1,hotelname2,hotelname3);
        }
        else
        {
          gotoxy(10,y);
          cout<<i;
          gotoxy(40,y);
          cout<<date1;
          gotoxy(70,y);
          cout<<date2;
          gotoxy(100,y);
          cout<<person;
          gotoxy(130,y);
          cout<<no;
          gotoxy(150,y);
          cout<<hotelname1<<" "<<hotelname2<<" "<<hotelname3;
          i++;
          y++;
          count1++;
          fseek(fp,0,SEEK_CUR);
            long int a=ftell(fp);
            ch1=getc(fp);
            fseek(fp,a,SEEK_SET);
            fscanf(fp,"%s %s %s %d %s %s %s %s",name,date1,date2,&person,no,hotelname1,hotelname2,hotelname3);

        }
    }
    if(count1<1)
    {
        gotoxy(75,30);
        cout<<"No data found";
    }
    fclose(fp);
    gotoxy(70,35);
    int x2=10,y2=30;
    gotoxy(x2,y2);
    char ch2=_getch();
    while(ch2!=13 && ch2!=8)
    {
        switch(ch2=_getch())
        {
            case 72:if(y2==30)
                        break;
                    else
                    {
                        y2--;
                        gotoxy(x2,y2);
                    }
                    break;
            case 80:if(y2==32)
                     break;
                     else
                     {
                         y2++;
                         gotoxy(x2,y2);
                     }
                     break;
        }
    }
    if(ch2==8)
        homepage();
    else
    {
    system("cls");
    gotoxy(70,20);
    cout<<"Are You Sure You Want To Cancel?";
    gotoxy(76,22);
    cout<<"Yes";
    gotoxy(91,22);
    cout<<"No";
    int x3=76,y3=22;
    gotoxy(x3,y3);
    char ch3=_getch();
    while(ch3!=13)
    {
        switch(ch3=_getch())
        {
            case 75:if(x3==76)
                        break;
                    else
                    {
                        x3=76;
                        gotoxy(x3,y3);
                    }
                    break;

            case 77:if(x3==91)
                        break;
                    else
                    {
                        x3=91;
                        gotoxy(x3,y3);
                    }
                    break;
        }
    }
    if(x3==76)
      {
            switch(y2)
        {
            case 30: remove1(1);break;
            case 31: remove1(2);break;
            case 32: remove1(3);break;
        }
      }
      else
      {
       booking_cancel();
      }
    }
    //homepage();
}
void about()
{
    system("cls");
    symbol();
    gotoxy(65,25);
    cout<<"APPLICATION MADE BY 'DHYEY DESAI'";
    gotoxy(80,27);
    cout<<"18IT030";
    gotoxy(73,35);
    cout<<"Backspace - quit";
    gotoxy(86,27);
    char ch=_getch();
    while(ch!=8)
    {
        ch=_getch();
    }
    homepage();
}
void yes()
{
    system("cls");
    gotoxy(55,10);
    string st="We Would Like Your Feedback To Improve Our Application.";
    for(int i=0;i<55;i++)
    {
        for(int j=0;j<17000000;j++);
        cout<<st[i];
    }
    gotoxy(70,14);
    string st1="Please Rate This Application";
    for(int i=0;i<28;i++)
    {
        for(int j=0;j<17000000;j++);
        cout<<st1[i];
    }
    gotoxy(72,17);
    cout<<"1";
    gotoxy(76,17);
    cout<<"2";
    gotoxy(80,17);
    cout<<"3";
    gotoxy(84,17);
    cout<<"4";
    gotoxy(88,17);
    cout<<"5";
    int x=72;
    gotoxy(x,18);
    char ch=_getch();
    if(ch!=13)
    {
        ch=_getch();
        while(ch!=13)
        {
            switch(ch)
            {
                case 77:if(x==88)
                            break;
                        else
                            {
                                x=x+4;
                                gotoxy(x,18);
                            }
                            break;

                case 75:if(x==72)
                            break;
                        else
                        {
                                x=x-4;
                                gotoxy(x,18);
                        }
                        break;
            }
            ch=_getch();
            if(ch!=13)
                ch=_getch();
        }
        switch(x)
        {
            case 72: gotoxy(75,25);
                    cout<<"1 star";
                    gotoxy(65,27);
                    cout<<"Thanks for giving your feedback...";break;

            case 76:gotoxy(75,25);
                    cout<<"2 star";
                    gotoxy(65,27);
                    cout<<"Thanks for giving your feedback...";break;

            case 80:gotoxy(75,25);
                    cout<<"3 star";
                    gotoxy(65,27);
                    cout<<"Thanks for giving your feedback...";break;

            case 84:gotoxy(75,25);
                    cout<<"4 star";
                    gotoxy(65,27);
                    cout<<"Thanks for giving your feedback...";break;

            case 88:gotoxy(75,25);
                    cout<<"5 star";
                    gotoxy(65,27);
                    cout<<"Thanks for giving your feedback...";break;
        }
    }
    else
    {
        gotoxy(75,25);
        cout<<"1 star";
        gotoxy(65,27);
        cout<<"Thanks for giving your feedback...";
    }
     for(int j=0;j<917000000;j++);
    system("cls");
    exit(0);
}
void no()
{
    homepage();
}
void exit()
{
    system("cls");
    gotoxy(70,20);
    string st="Thanks a lot .... Visit Again |||";
    for(int i=0;i<34;i++)
    {
        for(int j=0;j<17000000;j++);
        cout<<st[i];
    }
    for(int j=0;j<95111000;j++);
    system("cls");
    gotoxy(79,20);
    string st1="Exit ?";
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<17000000;j++);
        cout<<st1[i];
    }
    gotoxy(77,23);
    cout<<"Yes";
    gotoxy(83,23);
    cout<<"No";
    int x=77;
    gotoxy(x,23);
    char ch=_getch();
    if(ch!=13)
    {
        ch=_getch();
        while(ch!=13)
        {
            switch(ch)
            {
                case 77:if(x==83)
                            break;
                        else
                        {
                            x=83;
                            gotoxy(x,23);
                        }
                    break;

                case 75:if(x==77)
                            break;
                        else
                            {
                                x=77;
                                gotoxy(x,23);
                            }
                            break;
            }
            ch=_getch();
            if(ch!=13)
                ch=_getch();
        }
        switch(x)
        {
            case 77: yes();break;
            case 83: no();break;
        }
    }
    else
    {
            yes();
    }

}
void homepage()
{
    system("cls");
    symbol();
    char d=219;
    gotoxy(69,15);
    for(int i=0;i<25;i++)
        cout<<d;
    gotoxy(69,16);
    cout<<d<<"                       "<<d;
    gotoxy(69,17);
    cout<<d<<"      YOUR BOOKING     "<<d;
    gotoxy(69,18);
    cout<<d<<"                       "<<d;
    gotoxy(69,19);
    cout<<d<<"       BOOK HOTEL      "<<d;
    gotoxy(69,20);
    cout<<d<<"                       "<<d;
    gotoxy(69,21);
    //cout<<d<<"       FOOD ORDER      "<<d;
    //gotoxy(69,22);
    //cout<<d<<"                       "<<d;
    //gotoxy(69,23);
    cout<<d<<"     BOOKING CANCEL    "<<d;
    gotoxy(69,22);
    cout<<d<<"                       "<<d;
    gotoxy(69,23);
    cout<<d<<"         ABOUT         "<<d;
    gotoxy(69,24);
    cout<<d<<"                       "<<d;
    gotoxy(69,25);
    for(int i=0;i<25;i++)
        cout<<d;
    gotoxy(60,35);
    cout<<"'Backspace' - quit        'Enter' - select option";
    int i=17;
    gotoxy(71,17);
    char ch=_getch();
            if(ch!=13 && ch!=8)
            {
                ch=_getch();
                while(ch!=13 && ch!=8)
                {
                    switch(ch)
                    {
                        case 72:
                                if(i==17)
                                {
                                    break;
                                }
                                else
                                {
                                    i=i-2;
                                    gotoxy(71,i);
                                    break;
                                }


                            case 80://for(j=i;j<=25;j=j+2)
                                    if(i==23)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                       i=i+2;
                                      gotoxy(71,i);
                                      break;
                                    }

                    }
                    ch=_getch();
                    if(ch!=13 && ch!=8)
                    ch=_getch();
                }
                if(ch==13)
                {
                    switch(i)
                    {
                    case 17: your_booking();break;
                    case 19: before_room();break;
                    //case 21: food_order();break;
                    case 21: booking_cancel();break;
                    case 23: about();break;
                    //case 25: exit(0);break;
                    }
                }
                else
                    exit();
            }
            else if(ch==13)
                your_booking();
                else
                    exit();

}
void first()
{
    int x=67,y=22;
    char c=233;
    system("cls");
    for(int j=0;j<900100000;j++);
    gotoxy(70,20);
    string st="WELCOME TO MY HOTEL BOOKING APP";
    for(int i=0;i<32;i++)
    {
        for(int j=0;j<15000000;j++);
        cout<<st[i];
    }
    //gotoxy(x,y);
    for(int j=0;j<90100000;j++);
    for(int i=0;i<35;i++)
    {
        for(int j=0;j<9500000;j++);
        x++;
        gotoxy(x,y);
        cout<<c;
    }
    for(int g=0;g<5;g++)
    {
        for(int j=0;j<9500000;j++);
        y--;
        gotoxy(x,y);
        cout<<c;
    }
    for(int i=0;i<35;i++)
    {
        for(int j=0;j<9500000;j++);
        x--;
        gotoxy(x,y);
        cout<<c;
    }
    for(int g=0;g<5;g++)
    {
        for(int j=0;j<9500000;j++);
        y++;
        gotoxy(x,y);
        cout<<c;
    }
    //login();

}
void symbol();
void showpass(string pass,int hx,int hy,int lx1,int ly1,int px,int py,char username[])
{
    int x=hx-1,y=hy;
    char *un=&username[0];
    char *passw=&pass[0];
    gotoxy(px,py);
    cout<<passw;
    gotoxy(hx,hy);
    cout<<"hide password";
    gotoxy(hx,hy+1);
    cout<<"-------------";
    gotoxy(x,y);
    char ch=_getch();
    if(ch==13)
    {
        gotoxy(px,py);
        for(int i=0;i<5;i++)
        cout<<"*";
        gotoxy(hx,hy);
        cout<<"show password";
        gotoxy(hx,hy+1);
        cout<<"-------------";
        gotoxy(x,y);
    }
    ch=_getch();
    while(ch!=13)
        {
            if(ch!=72 && ch!=80)
                ch=_getch();
            switch(ch)
            {
                case 72:if(x==(hx-1))
                        break;
                    else
                    {
                        x=hx-1,y=hy;
                        gotoxy(x,y);
                    }
                    break;
                case 80:if(x==(lx1-1))
                        break;
                    else
                    {
                        x=lx1-1,y=ly1;
                        gotoxy(x,y);
                    }
                    break;
           }
        ch=_getch();
      }
      switch(x)
      {
          case 104:showpass(pass,hx,hy,lx1,ly1,px,py,username);break;
          case 79:loading(&un[0],&passw[0]);break;
      }
}
void showpass2(string pass,int hx,int hy,int lx1,int ly1,int px,int py,string username)
{
    int x=hx-1,y=hy;
    gotoxy(px,py);
    cout<<pass;
    gotoxy(hx,hy);
    cout<<"hide password";
    gotoxy(hx,hy+1);
    cout<<"-------------";
    gotoxy(x,y);
    char ch=_getch();
    if(ch==13)
    {
        gotoxy(px,py);
        for(int i=0;i<5;i++)
        cout<<"*";
        gotoxy(hx,hy);
        cout<<"show password";
        gotoxy(hx,hy+1);
        cout<<"-------------";
        gotoxy(x,y);
    }
    ch=_getch();
    while(ch!=13)
        {
            if(ch!=72 && ch!=80)
                ch=_getch();
            switch(ch)
            {
                case 72:if(x==(hx-1))
                        break;
                    else
                    {
                        x=hx-1,y=hy;
                        gotoxy(x,y);
                    }
                    break;
                case 80:if(x==(lx1-1))
                        break;
                    else
                    {
                        x=lx1-1,y=ly1;
                        gotoxy(x,y);
                    }
                    break;
           }
        ch=_getch();
      }
      switch(x)
      {
          case 86:showpass2(pass,87,28,72,40,80,28,username);break;
          case 71:system("cls");
                    gotoxy(70,20);
                    cout<<"Sign in successful...";
                    for(int i=0;i<107000000;i++);break;
      }
}
void loading(char username1[],char password[])
{
    system("cls");
    char *un1=&username1[0];                 //bcz in c++, string not divide in single character so strcmp not work
    char *pass=&password[0];
    gotoxy(70,20);
    cout<<"please wait";
    for(int i=1;i<2;i++)
    {
        for(int i=0;i<7;i++)
        {
            cout<<".";
            for(int j=1;j<=99999999;j++);
        }
        for(int k=1;k<=7;k++)
        {
            cout<<"\b";
            cout<<" ";
            cout<<"\b";
            for(int j=1;j<=99999999;j++);
        }
    }
    FILE *fp;
    if((fp=fopen("sign.txt","r"))==NULL)
    {
        cout<<"file not created";
        exit(0);
    }
    char s1[15],pa[5],na[80],gender[8],u;
    int age;
    fseek(fp,0,SEEK_SET);
    char ch=getc(fp);
    fseek(fp,0,SEEK_SET);
    fscanf(fp,"%s %d %s %s %s ",na,&age,gender,s1,pa);
    //gotoxy(75,30);
    //cout<<&s1[1]<<pa<<pass<<&un1[1];
    gotoxy(70,20);
    int count=0;
    while(strcmp(&s1[1],&un1[1]) || strcmp(pa,pass))
    {
        if(ch!=EOF)
        {
            fseek(fp,0,SEEK_CUR);
            long int a=ftell(fp);
            ch=getc(fp);
            fseek(fp,a,SEEK_SET);
            fscanf(fp,"%s %d %s %s %s",na,&age,gender,s1,pa);//
            u_name=na;           //
            //s[]=strcat(u,s1);
        }
        else
        {
            count++;
            break;
        }
    }
    if(count>0)
    {
        for(int c=1;c<=11;c++)
        {
            cout<<"\b";
            cout<<" ";
            cout<<"\b";
        }
        cout<<"Sorry! Incorrect username or incorrect password....\n";
        gotoxy(75,22);
        cout<<"TRY AGAIN";
        gotoxy(95,22);
        cout<<"SIGN UP";
        int x=75,y=22;
        gotoxy(x,y);
       // cout<<f;
        char ch=_getch();
        while(ch!=13)
        {
            ch=_getch();
            switch(ch)
            {
                case 75:if(x==75)
                            break;
                        else
                        {
                            x=75;
                        gotoxy(x,y);
                        }
                        break;

                case 77:if(x==95)
                            break;
                        else
                        {
                            x=95;
                        gotoxy(x,y);
                        }
                        break;
            }
            ch=_getch();
        }
        switch(x)
        {
            case 75:login();break;
            case 95:signup();break;
        }
    }
    else
    {
        for(int c=1;c<=11;c++)
        {
            cout<<"\b";
            cout<<" ";
            cout<<"\b";
        }
        cout<<"Login successfully....\n";
         for(int j=1;j<=707000000;j++);
    }
}
void signup()
{
    system("cls");
    symbol();
    gotoxy(60,20);
    cout<<"Name(only name)   : ";
    gotoxy(60,22);
    cout<<"Age               : ";
    gotoxy(60,24);
    cout<<"Gender            : ";
    gotoxy(60,26);
    cout<<"User_name[max 15] : ";
    gotoxy(60,28);
    cout<<"Password[max 5]   : ";
    gotoxy(80,20);
    char name[40];
    cin>>name;
    //int lenth=strlen(name);
    //int j=lenth+1;
    //name[j]='\0';
    gotoxy(80,22);
    int age;
    cin>>age;
    gotoxy(80,24);
    char gender[7];
    cin>>gender;
    fflush(stdin);
    gotoxy(80,26);
    char un[15],u;
    cin>>un;
    u=un[0];
    gotoxy(80,28);
    char c=' ',n2[5];
    int i=0;
    while(i<5)
    {
        n2[i]=_getch();
        c=n2[i];
        if(c==13)
            break;
        else
            cout<<"*";
        i++;
    }
    n2[i]='\0';
    password=n2;
    FILE *fp;
    fp=fopen("sign.txt","a");
    fprintf(fp,"\n%s %d %s %c%s %s",name,age,gender,u,&un[1],n2);
    fclose(fp);
    gotoxy(87,28);
    cout<<"show password";
    gotoxy(87,29);
    cout<<"-------------";
    gotoxy(72,40);
    cout<<"SIGN IN";
    int x=86,y=28;
    gotoxy(x,y);
    char ch=_getch();
    while(ch!=13)
    {
        ch=_getch();
        switch(ch)
        {
            case 72:if(y==28)
                        break;
                    else
                    {
                        x=86;
                        y=28;
                        gotoxy(x,y);
                    }
                    break;

            case 80:if(y==40)
                        break;
                    else
                    {
                        x=71;
                        y=40;
                        gotoxy(x,y);
                    }
                    break;

        }
        ch=_getch();
    }
    switch(y)
    {
        case 28:showpass2(n2,87,28,72,40,80,28,un);
                  break;

        case 40:system("cls");
                    gotoxy(70,20);
                    cout<<"Sign in successful...";
                    for(int i=0;i<107000000;i++);
                    u_name=name;
            break;
    }
}
void login()
{
    system("cls");
    symbol();
    gotoxy(65,20);
    cout<<"User_name[max 15] : ";
    char un[15];
    gotoxy(65,23);
    cout<<"Password[max 5]   : ";
    gotoxy(85,20);
    cin>>un;
    gotoxy(85,23);
    char c=' ',n2[5];
    int i=0;
    while(i<5)
    {
        n2[i]=_getch();
        c=n2[i];
        if(c==13)
            break;
        else
            cout<<"*";
        i++;
    }
    n2[i]='\0';
    password=n2;
    gotoxy(105,23);
    cout<<"show password";
    gotoxy(105,24);
    cout<<"-------------";
    gotoxy(80,30);
    cout<<"LOGIN";
    int x=104,y=23;
    gotoxy(x,y);
    char ch=_getch();
    while(ch!=13)
    {
        ch=_getch();
        switch(ch)
        {
            case 72:if(y==23)
                        break;
                    else
                    {
                        x=104;
                        y=23;
                        gotoxy(x,y);
                    }
                    break;

            case 80:if(y==30)
                        break;
                    else
                    {
                        x=79;
                        y=30;
                        gotoxy(x,y);
                    }
                    break;

        }
        ch=_getch();
    }
    switch(y)
    {
        case 23:showpass(n2,105,23,80,30,85,23,un);
                  break;

        case 30:loading(un,n2);
            break;
    }
}
void loginpage()
{
    system("cls");
    symbol();
    gotoxy(78,19);
    cout<<"Login";
    gotoxy(78,23);
    cout<<"Signup";
    int x=76,y=19;
    gotoxy(x,y);
    char ch=_getch();
    while(ch!=13)
    {
        ch=_getch();
        switch(ch)
        {
            case 72:if(y==19)
                        break;
                    else
                    {
                        y=19;
                        gotoxy(x,y);
                    }
                    break;

            case 80:if(y==23)
                        break;
                    else
                    {
                        y=23;
                        gotoxy(x,y);
                    }
                    break;
        }
        ch=_getch();
    }
    switch(y)
    {
        case 19:login();break;
        case 23:signup();break;
    }

}
int main()
{
    system("cls");
    first();
    loginpage();
    homepage();
}
void symbol()
{
  system("cls");
  char c=176,d=168,e=175;
   //system("cls");
    //char c=176,d=236;
    gotoxy(75,8);
    for(int i=0;i<13;i++)
        cout<<c;
    gotoxy(75,9);
    cout<<c<<"           "<<c;
    gotoxy(75,10);
    cout<<c<<"   "<<"INVERT"<<"  "<<c;
    gotoxy(75,11);
    cout<<c<<"     "<<d<<"     "<<c;
    gotoxy(75,12);
    cout<<c<<"           "<<c;
    gotoxy(75,13);
    for(int i=0;i<13;i++)
        cout<<c;
}



