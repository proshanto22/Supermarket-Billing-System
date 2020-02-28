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

	   char* disp();
	  void unpack(int);
	  void unpack_M(int);
	  char* disp_M();

};
void Bill::unpack_M(int add)
{
	fstream file("all.txt",ios::in);
	file.seekg(add);
	file.getline(ItemNo,5,'|');
		file.getline(name,50,'|');
		file.getline(price,10,'|');
		file.getline(cnt,5,'|');
		file.close();
}
void Bill::unpack(int add)
{
	fstream file("bill.txt",ios::in);
	file.seekg(add);
	file.getline(ItemNo,5,'|');
		file.getline(name,50,'|');
		file.getline(quantity,3,'|');
		file.getline(price,10,'|');
		file.getline(total,10,'|');
		file.close();
}
char* disp_M()
{
	Bill s;
	int add;
	char seg[10],Item[10];
	char* result = new char[10000];
	fstream o("trace.txt",ios::in);
	fstream in("index_M.txt",ios::in);
	strcpy_s(result, 1000, "ITEM NO");
	strcat_s(result, 1000, "\t");
	strcat_s(result, 1000, "NAME");
	strcat_s(result, 1000, "\t\t");
	strcat_s(result, 1000, "PRICE");
	strcat_s(result, 1000, "\t");
	strcat_s(result, 1000, "COUNT");
	strcat_s(result, 1000, "\r\n");
	while (!o.eof())
	{
		o >> nor;
	}
	for (int i = 0; i < nor; i++)
	{
		in.getline(Item,10,'|');
		in.getline(seg,10,'|');
		add = atoi(seg);
		s.unpack_M(add);
		strcat_s(result, 1000, s.ItemNo);
		strcat_s(result, 1000, "\t");
		strcat_s(result, 1000, s.name);
		strcat_s(result, 1000, "\t\t");
		strcat_s(result, 1000, s.price);
		strcat_s(result, 1000, "\t");
		strcat_s(result, 1000, s.cnt);
		strcat_s(result, 1000, "\r\n");
	}
	o.close();
	in.close();
	return result;
}

char* disp()
{
	Bill s;
	int add;
	char seg[10],Item[10];
	char* result = new char[10000];
	fstream o("trace_b.txt",ios::in);
	fstream in("index.txt",ios::in);
	strcpy_s(result, 1000, "ITEM NO");
	strcat_s(result, 1000, "\t");
	strcat_s(result, 1000, "NAME");
	strcat_s(result, 1000, "\t\t");
	strcat_s(result, 1000, "QUANTITY");
	strcat_s(result, 1000, "\t");
	strcat_s(result, 1000, "PRICE");
	strcat_s(result, 1000, "\t");
	strcat_s(result, 1000, "GRAND TOTAL");
	strcat_s(result, 1000, "\r\n");
	while (!o.eof())
	{
		o >> mor;
	}
	for (int i = 0; i < mor; i++)
	{
		in.getline(Item,10,'|');
		in.getline(seg,10,'|');
		add = atoi(seg);
		s.unpack(add);
		strcat_s(result, 1000, s.ItemNo);
		strcat_s(result, 1000, "\t");
		strcat_s(result, 1000, s.name);
		strcat_s(result, 1000, "\t\t");
		strcat_s(result, 1000, s.quantity);
		strcat_s(result, 1000, "\t");
		strcat_s(result, 1000, s.price);
		strcat_s(result, 1000, "\t");
		strcat_s(result, 1000, s.total);
		strcat_s(result, 1000, "\r\n");
	}
	o.close();
	in.close();
	return result;
}

/*char* search_I(Bill &d)
{
	Bill s;
	int add;
	char seg[10],Item[10];
	char* result = new char[10000];
	fstream o("trace.txt",ios::in);
	fstream in("index_M.txt",ios::in);
	strcpy_s(result, 1000, "ITEM NO");
	strcat_s(result, 1000, "\t");
	strcat_s(result, 1000, "NAME");
	strcat_s(result, 1000, "\t\t");
	strcat_s(result, 1000, "PRICE");
	strcat_s(result, 1000, "\t");
	strcat_s(result, 1000, "COUNT");
	strcat_s(result, 1000, "\r\n");
	while (!o.eof())
	{
		o >> nor;
	}
	for (int i = 0; i < nor; i++)
	{
		in.getline(Item,10,'|');
		in.getline(seg,10,'|');
		if(strcmp(Item,d.ItemNo)==0)
		{
		add = atoi(seg);
		s.unpack_M(add);
		strcat_s(result, 1000, s.ItemNo);
		strcat_s(result, 1000, "\t");
		strcat_s(result, 1000, s.name);
		strcat_s(result, 1000, "\t\t");
		strcat_s(result, 1000, s.price);
		strcat_s(result, 1000, "\t");
		strcat_s(result, 1000, s.cnt);
		strcat_s(result, 1000, "\r\n");
		}}
	o.close();
	in.close();
	return result;
}*/