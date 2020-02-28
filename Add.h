#include<fstream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

int nor,mor;
class Bill
{
public: char name[50],ItemNo[5],price[10],total[10],quantity[3];
		char seg[5],tax[5],discount[5],cnt[5];
  
	   int add_M(Bill &i);
	  int add(Bill &a);
	  int upd_M(Bill &u);
	  void upd_MRed(char *,int);
	  int del(Bill &d);
	  int del_M(Bill &d);
};

int Bill::add_M(Bill &i)
{
	char buf[500];
	int flag=1;
	ifstream o("trace.txt");
	if(o){
		int add;
		char item[5];
	fstream in("index_M.txt",ios::in);
	while (!o.eof())
	{
		o >> nor;
	}
	for(int j=0;j<nor;j++)
	{
		in.getline(item,5,'|');
		in.getline(seg,5,'|');
		add = atoi(seg);
		if (strcmp(item,i.ItemNo)==0)
		{
			 flag=0;
		}
	}
	in.close();
	}
if(flag==1){
	fstream file("all.txt", ios::out | ios::app);
	fstream ind("index_M.txt",ios::out | ios::app);

	file.seekg(0, ios::end);

    ind << i.ItemNo << "|" << file.tellg() << "|";
	strcpy(buf,i.ItemNo);
	strcat(buf,"|");
	strcat(buf,i.name);
	strcat(buf,"|");
	strcat(buf,i.price);
	strcat(buf,"|");
	strcat(buf,i.cnt);
	strcat(buf,"|");
	file<<buf;
	
	if(o){
	while(!o.eof())
    {
        o >> nor;
    }
	}
	nor++;
	fstream f1("trace.txt",ios::out | ios::app);
	f1 << nor <<"\n";
	file.close();
	ind.close();
}
	return flag;

}

int Bill::add(Bill &a)
{
	 
	 float p,tp,g,dis,t,netamt;
	 int q,c;
		 int flag=0;
	 char key[5],ItemNo[5],name[50],price[10],seg[5],count[5];
		char sadd[50];
	 int add;
	fstream file("bill.txt", ios::out | ios::app);
	fstream o("trace.txt",ios::in);
	fstream m("trace_b.txt",ios::in);
	fstream ind("index.txt",ios::out | ios::app);
	fstream in("index_M.txt",ios::in);
	fstream r("all.txt",ios::in);
	while (!o.eof())
	{
		o >> nor;
	}
	for(int i=0;i<nor;i++)
	{
		in.getline(ItemNo,5,'|');
		in.getline(seg,5,'|');
		add = atoi(seg);
		if (strcmp(ItemNo,a.ItemNo)==0)
		{
			flag=1;
		r.seekg(add);
		r.getline(ItemNo,5,'|');
		r.getline(name,50,'|');
		r.getline(price,10,'|');
		r.getline(count,5,'|');
			c=atoi(count);
			q=atoi(a.quantity);
			if(q>c)
			{
				flag=2;
				return flag;
			}
			p=atof(price);
			t=atof(a.tax);
			dis = atof(a.discount);
			tp=q*p;
			g=p+(p*(t/100));
			netamt=q*(g-(g*(dis/100)));
			gcvt(netamt,7,total);

		file.seekg(0, ios::end);

    ind << a.ItemNo << "|" << file.tellg() << "|";

			file<<a.ItemNo<<"|"<<name<<"|"<<a.quantity<<"|"<<price<<"|"<<total<<"|";
			upd_MRed(a.ItemNo,q);	
			if(m)
			{
				while(!m.eof())
				m>>mor;
			}
	mor++;
	fstream m("trace_b.txt",ios::out | ios::app);
	m<<mor<<"\n";
			m.close();
		}
	}

		o.close();
		file.close();
		return flag;
	}


int Bill::upd_M(Bill &u)
{
    Bill d[100];
	 char key[5],ItemNo[5],name[20],price[10],seg[5],count[5];
	fstream r("all.txt",ios::in);
	fstream f("index_M.txt",ios::in);
	fstream o("trace.txt",ios::in);
	int i = 0,j=0,k=0;
	int n = 0;
	int s =0;
	int tp=0;
	while (!r.eof())
	{
		r.getline(d[i].ItemNo,5,'|');
		r.getline(d[i].name,50,'|');
		r.getline(d[i].price,10,'|');
		r.getline(d[i].cnt,5,'|');
		i++;
		n++;
	}
	int flag = 0;
	for (i = 0; i <n-1 ; i++)
	{
		if (strcmp(d[i].ItemNo,u.ItemNo)==0)
		{
		    
			strcpy(d[i].cnt,u.cnt);
			flag = 1;
			break;
		}
	}

	if(flag==1)
    {
        fstream file("all.txt",ios::out|ios::trunc);
     	for (i = 0; i < n - 1; i++)
        			file << d[i].ItemNo << "|" << d[i].name << "|" << d[i].price <<"|"<< d[i].cnt << "|";
file.close();

    }
   
	r.close();
    f.close();
	return flag;
}

void Bill::upd_MRed(char* item, int q)
{
    Bill d[100];
	float up;
	fstream r("all.txt",ios::in);
	fstream f("index_M.txt",ios::in);
	fstream o("trace.txt",ios::in);
	int i = 0,j=0,k=0;
	int n = 0;
	int s =0;
	int tp=0;
	while (!r.eof())
	{
		r.getline(d[i].ItemNo,5,'|');
		r.getline(d[i].name,50,'|');
		r.getline(d[i].price,10,'|');
		r.getline(d[i].cnt,5,'|');
		i++;
		n++;
	}
	int flag = 0;
	for (i = 0; i <n-1 ; i++)
	{
		if (strcmp(d[i].ItemNo,item)==0)
		{
			up = atoi(d[i].cnt);
			up-= q;
			itoa(up,d[i].cnt,10);
			//gcvt(up,4,d[i].cnt);
			flag = 1;
			break;
		}
	}

	if(flag==1)
    {
        fstream file("all.txt",ios::out|ios::trunc);
     	for (i = 0; i < n - 1; i++)
        			file << d[i].ItemNo << "|" << d[i].name << "|" << d[i].price <<"|"<< d[i].cnt << "|";
file.close();

    }
   
	r.close();
    f.close();
}

int Bill::del(Bill &d)
{
	Bill b[100];
	int flag=0,i=0;
	fstream f1("index.txt",ios::in);
	ifstream m("trace_b.txt",ios::in);
	while(!m.eof())
	{
		m>>mor;
	}
	while(!f1.eof())
	{
		f1.getline(b[i].ItemNo,5,'|');
		f1.getline(b[i].seg,5,'|');
		i++;
	}

	for(int i=0;i<mor;i++)
	{

		if(strcmp(d.ItemNo,b[i].ItemNo)==0)
		{ 

			flag=1;
		
			for(int j=i;j<mor;j++)
			{
				strcpy(b[j].ItemNo,b[j+1].ItemNo);
				strcpy(b[j].seg,b[j+1].seg);
			}
			mor--;
		}
		if(flag==1)
		{
			fstream f2("index.txt",ios::out|ios::trunc);
			for(int i=0;i<mor;i++)
			f2<<b[i].ItemNo << "|" << b[i].seg << "|" ;
	fstream m1("trace_b.txt",ios::out|ios::trunc);
		m1 << mor;
		}
		
	}

	
	f1.close();
	return flag;
}

int Bill::del_M(Bill &d)
{
	Bill b[100];
	int flag=0,i=0;
	fstream f1("index_M.txt",ios::in);
	ifstream o("trace.txt",ios::in);
	while(!o.eof())
	{
		o>>nor;
	}
	o.close();
	while(!f1.eof())
	{
		f1.getline(b[i].ItemNo,5,'|');
		f1.getline(b[i].seg,5,'|');
		i++;
	}

	for(int i=0;i<nor;i++)
	{

		if(strcmp(d.ItemNo,b[i].ItemNo)==0)
		{ 

			flag=1;
		
			for(int j=i;j<nor;j++)
			{
				strcpy(b[j].ItemNo,b[j+1].ItemNo);
				strcpy(b[j].seg,b[j+1].seg);
			}
		nor--;
		}
	}
		f1.close();
		if(flag==1)
		{
			fstream f2("index_M.txt",ios::out|ios::trunc);
			for(int i=0;i<nor;i++)
			f2<<b[i].ItemNo << "|" << b[i].seg << "|" ;
			f2.close();
	fstream o1("trace.txt",ios::out|ios::trunc);
		o1 << nor;
		o1.close();
		}
		
	return flag;
}
