#include<iostream>
#include<fstream>
#include <bits/stdc++.h>
#include<string.h>
#include<conio.h>
using namespace std;

class pass
{
public:
    char p[20];
    void password(int x)
    {
       if(x==1234)
       {
           cout<<"\nEnter password(less than 10 characters)";
           cin.ignore();
           cin.getline(p,20);
           fstream wr;
           wr.open("pass.txt",ios::out);
           wr.write((char*)this,sizeof(pass));
           wr.close();
       }
       else
       {
           cout<<"\nCode Error";
       }
    }
};
pass obj1;

class hotel
{

public:
    int room_no;
    char date[15];
    char date1[15];
    char name[30];
    char mob[15];
    char adr[15];
    char address[50];



    void accept()
    {
        cin.ignore();
        cout<<"\nEnter Check-in  date ";
        cin.getline(date,15);
        cout<<"\nEnter full name ";
        cin.getline(name,30);
        cout<<"\nEnter mobile number ";
        cin>>mob;
        cin.ignore();
        cout<<"\nEnter aadhar card number ";
        cin.getline(adr,15);
        cout<<"\nEnter address ";
        cin.getline(address,50);
    }
    void display()
    {
        cout<<"\nRoom number       "<<room_no;
        cout<<"\nName              "<<name;
        cout<<"\nMobile number     "<<mob;
        cout<<"\nAadhar card number "<<adr;
        cout<<"\nAddress           "<<address;
        cout<<"\n----------------------------";
    }

};
hotel obj;
int check(int r)
{
    int flag=1;
    fstream rd;
    rd.open("record.txt",ios::in);
    rd.seekg(0,ios::end);
    int n=rd.tellg();
    n=n/sizeof(obj);
    rd.seekg(0,ios::beg);
    for(int i=1;i<=n;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(r==obj.room_no)
        {
            flag=0;
            break;
        }
    }
    return flag;
}
void alotroom()
{

    int r,c;
    cout<<"\nEnter room number ";
    cin>>r;
    c=check(r);
    if(c==0)
    {
        cout<<"\nROOM ALREADY BOOKED";
    }
    else
    {
        obj.room_no=r;
        obj.accept();
        fstream wr;
        wr.open("record.txt",ios::app);
        wr.write((char*)&obj,sizeof(obj));
    }
}

void rstatus()
{
       fstream rd;
      rd.open("record.txt",ios::in);
      rd.seekg(0,ios::end);
      int n=rd.tellg();
      n=n/sizeof(obj);
      rd.seekg(0,ios::beg);
      for(int i=1;i<=n;i++)
       {
        rd.read((char*)&obj,sizeof(obj));
        cout<<"\nRoom number       "<<obj.room_no;
        cout<<"\nName              "<<obj.name;
        cout<<"\nMobile number     "<<obj.mob;
        cout<<"\n----------------------------";
       }
}
void edit()
 {
        int rno;
        cout<<"\nEnter room number ";
        cin>>rno;
        fstream wr,rd;
        rd.open("record.txt",ios::in);
        wr.open("temp.txt",ios::out);
        rd.seekg(0,ios::end);
        int n=rd.tellg();
        n=n/sizeof(obj);
        rd.seekg(0,ios::beg);
        for(int i=1;i<=n;i++)
        {
            rd.read((char*)&obj,sizeof(obj));
            if (obj.room_no==rno)
            {
                cout<<"\nEnter new room number ";
                cin>>rno;
                obj.room_no=rno;
                obj.accept();
                wr.write((char*)&obj,sizeof(obj));
            }
            else
            {
                wr.write((char*)&obj,sizeof(obj));
            }
        }
        rd.close();
        wr.close();
        remove("record.txt");
        rename("temp.txt","record.txt");
 }

    void customerinfo()
    {
        char p1[20];
    fstream rdp;
    rdp.open("pass.txt",ios::in);
    rdp.read((char*)&obj1,sizeof(pass));
    cout<<"\nEnter password ";
    for(int i=0;i<strlen(obj1.p);i++)
    {
        p1[i]=getch();
        cout<<"*";
    }
    p1[strlen(obj1.p)]='\0';
    if(strcmp(p1,obj1.p)==0)
     {
      fstream rd;
      rd.open("record.txt",ios::in);
      rd.seekg(0,ios::end);
      int n=rd.tellg();
      n=n/sizeof(obj);
      rd.seekg(0,ios::beg);
      for(int i=1;i<=n;i++)
       {
        rd.read((char*)&obj,sizeof(obj));
        obj.display();
       }
     }
    else
     {
        cout<<"\nPassword Mismatch";
     }
    }
void leaveroom()
{
    int rno;
    cout<<"\nEnter room number ";
    cin>>rno;
    fstream rd,wr,nwr;
    rd.open("record.txt",ios::in);
    wr.open("temp.txt",ios::app);
    nwr.open("prevreco.txt",ios::app);
    rd.seekg(0,ios::end);
    int n=rd.tellg();
    n=n/sizeof(obj);
    rd.seekg(0,ios::beg);
    for(int i=1;i<=n;i++)
        {
            rd.read((char*)&obj,sizeof(obj));
            if (obj.room_no==rno)
            {

                cin.ignore();
                cout<<"\nEnter checkout date ";
                cin.getline(obj.date1,15);
                nwr.write((char*)&obj,sizeof(obj));
            }
            else
            {
                wr.write((char*)&obj,sizeof(obj));
            }
        }
     rd.close();
     wr.close();
     remove("record.txt");
     rename("temp.txt","record.txt");
}
void oldreco()
{
    fstream rd;
    rd.open("prevreco.txt",ios::in);
    rd.seekg(0,ios::end);
    int n=rd.tellg();
    n=n/sizeof(obj);
    rd.seekg(0,ios::beg);
    for(int i=1;i<=n;i++)
        {
            rd.read((char*)&obj,sizeof(obj));
            obj.display();
            cout<<"\nCheck-out date "<<obj.date1;
        }
}
main()
{
 int e=1,x;
 while(e!=0)
 {
     cout<<"\n\t\tWELCOME TO HOTEL MANAGEMENT PROJECT\n ";
     cout<<"\t\t_______________________________________ ";
     cout<<"\n\t\t1.Press 1 to book a room              ";
     cout<<"\n\t\t2.Press 2 to view all rooms status    ";
     cout<<"\n\t\t3.Press 3 to view customer information";
     cout<<"\n\t\t4.Press 4 to edit the data            ";
     cout<<"\n\t\t5.Press 5 to leave the room           ";
     cout<<"\n\t\t6.Enter 6 to view old record          ";
     cout<<"\n\t\t7.Enter 7 to change password          ";
     cout<<"\n\t\t8.Enter 0 to exit                     ";
     cout<<"\n\t\t______________________________________";
     cout<<"\nSelect your choice                    ";
     cin>>x;
     switch(x)
     {
         case 1:
         {
             alotroom();
             break;
         }
         case 2:
         {
             rstatus();
             break;
         }
         case 3:
         {
             customerinfo();
             break;
         }
         case 4:
         {
             edit();
             break;
         }
         case 5:
         {
             leaveroom();
             break;
         }
         case 6:
         {
            oldreco();
             break;
         }

         case 7:
         {
             int y;
             cout<<"\nEnter passcode - ";
             cin>>y;
             obj1.password(y);
             break;
         }
         case 0:
         {
             e=0;
             break;
         }
     }
 }
     cout<<"\nBYE BYE !!!";
}

