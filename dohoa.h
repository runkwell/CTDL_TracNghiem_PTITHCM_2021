#pragma once
#include <winbgim.h> 
#include <iostream>
#include "Lop.h"
#include "MonHoc.h"

#include <cmath>
using namespace std;
const int H= 700;
const int W=1360;
short int MID[1350][680];

void doiSangChuoi(char s[], int n){
	if(n==0){
		strcpy(s,"0");
		return;
	}
	char c[100];
	int i=0;
	while(n>0){
		c[i] = (n%10)+'0';
		n/=10;
		i++;
	}
	
	for(int j=0; j<i; j++){
		s[j] = c[i-j-1];
	}
	s[i]='\0';
}

int doiSangSo(char s[]){
	int len = strlen(s);
	int n=0;
	for(int i=0; i<len; i++){
		n = n*10+(s[i]-'0');
	}
	return n;
}

void doiSangChuoiThuc(char s[], float diem){
	strcpy(s,"");
	int a = floor(diem);
	char chrA[5]="";
	itoa(a, chrA, 10);
	strcat(s, chrA);
	a = floor(((float)diem-a)*100);
	itoa(a, chrA, 10);
	strcat(s, ".");
	strcat(s, chrA);
}


void khoitaoID()
{
	for(int i=10;i<1350;i++)
	{
		for(int j=10;j<680;j++)
		MID[i][j]=0;
	}
}
void taoID(int x1,int y1,int x2,int y2, int ID)
{
	for(int i=x1;i<x2;i++)
	{
		for(int j=y1;j<y2;j++)
		MID[i][j]=ID;
	}
}
const int ENTER = 13;
const int BACKSPACE = 8;



void button(int x1, int y1, int x2, int y2, int ID, char* s,int cochu, int clbar, int clw)
{
	setfillstyle(1,clbar);
	bar(x1,y1,x2,y2);
	setcolor(clw);
	setbkcolor(clbar);
	settextstyle(0,0,cochu);
	outtextxy(x1+10,y1+10,s);	
	taoID(x1,y1,x2,y2,ID);
}
void taoo(int x1,int y1,int x2, int y2, int ID,int mau, int mauvien)
{
	setfillstyle(1,mau);
	bar(x1,y1,x2,y2);
	setcolor(mauvien);
	rectangle(x1,y1,x2,y2);
	taoID(x1,y1,x2,y2,ID);
	setcolor(0);
	setbkcolor(9);
}
void taodong(int x1,int y1, int docao,int Mangdodai[], int mau, int mauvien,int ID , int socot)
{
	int y2= y1+docao;
	int	x2;
	
	for(int i=0;i<socot;i++)
	{
	    x2=x1+Mangdodai[i];
		taoo(x1,y1,x2,y2,ID,mau,mauvien);
		x1=x2;
	
	}
}
void taobang(int x1,int y1, int docao,int socot,int Mangdodai[], int mau, int mauvien,int soluong, int ID, int trang,char td[][50] )
{//taobang(410,70,25,3,dd,15,9,16,999,trang,td);
	setcolor(0);
	setbkcolor(15);
	settextstyle(0,0,2);
	int y=y1;
	for(int i=1;i<=soluong;i++)
	{
		taodong(x1,y1,docao,Mangdodai,mau, mauvien,ID+i,socot);
		if(i!=1)
		{
			char temp[4];
			itoa((i-1)+15*(trang-1),temp,10);
			setcolor(0);
			setbkcolor(15);
			outtextxy(x1+5,y1+5,temp);
		}
		y1=y1+docao;
		
	}
	for(int i=0;i<socot;i++)
	{
	setcolor(0);
	setbkcolor(15);
		outtextxy(x1+5,y+5,td[i]);
		x1=x1+Mangdodai[i];
	}	
}
void taobang1(int x1,int y1, int docao,int socot,int Mangdodai[], int mau, int mauvien,int soluong, int ID, int trang,char td[][50] )
{
	setcolor(0);
	setbkcolor(mau);
	settextstyle(0,0,2);
	int y=y1;
	for(int i=1;i<=soluong;i++)
	{
		taodong(x1,y1,docao,Mangdodai,mau, mauvien,ID+i,socot);
		y1=y1+docao;
		
	}
	for(int i=0;i<socot;i++)
	{
		outtextxy(x1+5,y+5,td[i]);
		x1=x1+Mangdodai[i];
	}	
}





#define PATH_FILE "matcngaunhien.txt"




void ScannerMa(char s[],int max, int px ,int py,int ID,int &IDnext)
{
	setcolor(9);
	setbkcolor(15);
	settextstyle(0,0,2);
	int mx=-1;
	int my=-1;
	unsigned int l = strlen(s);
		s[l] ='|';
		s[l+1]=0;
	cout<<"Nien Khoa in Scanner: "<<s<<endl;
	outtextxy(px,py,s);
	while(1)
	{
		getmouseclick(WM_LBUTTONDOWN,mx,my);
		clearmouseclick(WM_LBUTTONDOWN);
		delay(1);
		if  (!(((mx==-1)&&(my==-1))||(MID[my][mx]== ID))) {
			s[l] = ' ';
			s[l+1]=0;
			outtextxy(px,py,s);
			s[l]= '\0';	
			break;
		}
		if(kbhit())
		{			
		char c = getch();
			if(l<max)
			{
				
				if(c=='-')
				{
					s[l] = c;
					l++;
					s[l]=0;
				}
				if(c>='A' && c<='Z')
				{
				s[l] = c;
					l++;
					s[l]=0;
				}
				if(c>='a' && c<='z')
				{
					c=c+'A'-'a';
					s[l] = c;
					l++;
					s[l]=0;
				//	continue;
				}
				
				if(c>='0' && c<='9')
				{
					s[l] = c;
					l++;
					s[l]=0;
				}
				outtextxy(px,py,s);	
			}
			if(c == ENTER) {
				s[l] = ' ';
				s[l+1]=0;
				outtextxy(px,py,s);
				s[l]= '\0';
				break;
			}
			if(c == BACKSPACE&&l>0)
			{
				s[l]=' ';
				s[l+1]=0;
				outtextxy(px,py,s);	
				s[l-1] =' ';
				l--;
			}
			s[l] = '|';
			s[l+1]=' ';
			s[l+2]=0;
			outtextxy(px,py,s);	
			if(s[l]==' ') s[l]=0;
		
		}
	}
	if((mx!=-1)&&(my!=-1)) {
	IDnext=MID[mx][my];
	}
}

void Scannermk(char s[],int max, int px ,int py,int ID,int &IDnext,char a[])
{
	cout<<"vo nhap chuoi";
	setcolor(9);
	setbkcolor(15);
	settextstyle(0,0,2);
	
	int mx=-1;
	int my=-1;
	unsigned int l = strlen(s);
	unsigned int n = strlen(s);
//	cout<<l;
	s[l] ='|';
	s[l+1]=0;
	a[n] ='|';
	a[n+1]=NULL;
	outtextxy(px,py,a);
	while(1)
{ 
    
         delay(0.1);
		getmouseclick(WM_LBUTTONDOWN,mx,my);
		clearmouseclick(WM_LBUTTONDOWN);
		
		if  (!(((mx==-1)&&(my==-1))||(MID[my][mx]== ID))) {
			cout<<" thoat";
			s[l] = ' ';
			s[l+1]=0;
			a[n] = ' ';
			a[n+1]=0;
			outtextxy(px,py,a);
			s[l]= '\0';	
			a[n]= '\0';
			break;
		}
		if(kbhit())
		{			
		char c = getch();
			if(l<max)
			{
				if(c!=NULL&&c!=BACKSPACE&&c!=ENTER)
				{
					a[n]='*';
					n++;
					outtextxy(px,py,a);
				}
				if((l==0||s[l-1]==' '))
				{
					if(c<='z'&&c>='a')
					c=c+'A'-'a';
					else
					c=c;
					
				}
				else if(c<='Z'&&c>='A')
				c=c-'A'+'a';
				if(c=='_')
				{
					s[l] = c;
					l++;
					s[l]=0;
				}
				if(c>='a' && c<='z')
				{
					s[l] = c;
					l++;
					s[l]=0;
				}
				if(c>='A' && c<='Z')
				{
				s[l] = c;
					l++;
					s[l]=0;
				}
				if(c>='0' && c<='9')
				{
					s[l] = c;
					l++;
					s[l]=0;
				}
				if(l>0) if(s[l-1]!=' ' && c == ' ')
				{
					s[l] = c;
					l++;
					s[l]=0;
				}
				if((l==0||s[l-1]==' ')&&(s[l]>='a'||s[l]<='z')||(n==0||a[n-1]==' ')&&(a[n]>='a'||a[n]<='z'))
				s[l]=s[l]+'A'-'a';
				s[l+1]=0;
				a[n]=' ';
				a[n+1]=NULL;
					outtextxy(px,py,a);
			}
			if(c == ENTER) {
				s[l] = ' ';
				s[l+1]=0;
				a[n] = ' ';
				a[n+1]=NULL;
					outtextxy(px,py,a);
				s[l]= '\0';
				a[n]= '\0';
				break;
			}
			if(c == BACKSPACE&&l>0)
			{
				s[l]=' ';
				s[l+1]=0;
				a[n]=' ';
				a[n+1]=NULL;
				outtextxy(px,py,a);
				s[l-1] =' ';
				l--;
				a[n-1] =' ';
				n--;
			}
			a[n] = '|';
			a[n+1]=' ';
			a[n+2]=0;
			outtextxy(px,py,a);	
			if(a[n]==' ') a[n]=NULL;
		
		}
	}
	if((mx!=-1)&&(my!=-1)) {
	IDnext=MID[mx][my];
	}
}

void ScannerString(char s[],int max, int px ,int py,int ID,int &IDnext)
{
	cout<<"vo nhap chuoi";
	setcolor(9);
	setbkcolor(15);
	settextstyle(0,0,2);
	int mx=-1;
	int my=-1;
	unsigned int l = strlen(s);
//	cout<<l;
	s[l] ='|';
	s[l+1]=0;
	outtextxy(px,py,s);
	while(1)
{ 
         delay(0.1);
		getmouseclick(WM_LBUTTONDOWN,mx,my);
		clearmouseclick(WM_LBUTTONDOWN);
		
		if  (!(((mx==-1)&&(my==-1))||(MID[my][mx]== ID))) {
			cout<<" thoat";
			s[l] = ' ';
			s[l+1]=0;
			outtextxy(px,py,s);
			s[l]= '\0';	
			break;
		}
		if(kbhit())
		{			
		char c = getch();
			if(l<max)
			{
				if((l==0||s[l-1]==' '))
				{
					if(c<='z'&&c>='a')
					c=c+'A'-'a';
					else
					c=c;
					
				}
				else if(c<='Z'&&c>='A')
				c=c-'A'+'a';
				if(c=='_')
				{
					s[l] = c;
					l++;
					s[l]=0;
				}
				if(c>='a' && c<='z')
				{
					s[l] = c;
					l++;
					s[l]=0;
				}
				if(c>='A' && c<='Z')
				{
				s[l] = c;
					l++;
					s[l]=0;
				}
				if(c>='0' && c<='9')
				{
					s[l] = c;
					l++;
					s[l]=0;
				}
				if(l>0) if(s[l-1]!=' ' && c == ' ')
				{
					s[l] = c;
					l++;
					s[l]=0;
				}
				if((l==0||s[l-1]==' ')&&(s[l]>='a'||s[l]<='z'))
				s[l]=s[l]+'A'-'a';
				s[l+1]=0;
				outtextxy(px,py,s);	
			}
			if(c == ENTER) {
				s[l] = ' ';
				s[l+1]=0;
				outtextxy(px,py,s);
				s[l]= '\0';
				break;
			}
			if(c == BACKSPACE&&l>0)
			{
				s[l]=' ';
				s[l+1]=0;
				outtextxy(px,py,s);	
				s[l-1] =' ';
				l--;
			}
			s[l] = '|';
			s[l+1]=' ';
			s[l+2]=0;
			outtextxy(px,py,s);	
			if(s[l]==' ') s[l]=0;
		
		}
	}
	if((mx!=-1)&&(my!=-1)) {
	IDnext=MID[mx][my];
	}
}

void ScannerName(char s[],int max, int px ,int py,int ID, int &IDnext)
{
	setcolor(9);
	setbkcolor(15);
	settextstyle(0,0,2);
	int mx=-1;
	int my=-1;
	unsigned int l = strlen(s);
	s[l] ='|';
	s[l+1]=0;
	outtextxy(px,py,s);
	while(1)
	{
		getmouseclick(WM_LBUTTONDOWN,mx,my);
		clearmouseclick(WM_LBUTTONDOWN);
		delay(1);
		if  (!(((mx==-1)&&(my==-1))||(MID[my][mx]== ID))) {
			s[l] = ' ';
			s[l+1]=0;
			outtextxy(px,py,s);
			s[l]= '\0';	
			break;
		}
		if(kbhit())
		{			
		char c = getch();
			if(l<max)
			{

				if((l==0||s[l-1]==' '))
				{
					if(c<='z'&&c>='a')
					c=c+'A'-'a';
					else
					c=c;
					
				}
				else if(c<='Z'&&c>='A')
				c=c-'A'+'a';

				if(c>='a' && c<='z')
				{
					s[l] = c;
					l++;
					s[l]=0;
				}
				if(c>='A' && c<='Z')
				{
				s[l] = c;
					l++;
					s[l]=0;
				}
				
				if(l>0) if(s[l-1]!=' ' && c == ' ')
				{
					s[l] = c;
					l++;
					s[l]=0;
				}
				
			}
			if(c == ENTER) {
				s[l] = ' ';
				s[l+1]=0;
				outtextxy(px,py,s);
				s[l]= '\0';
				break;
			}
			if(c == BACKSPACE&&l>0)
			{
				s[l]=' ';
				s[l+1]=0;
				outtextxy(px,py,s);
				s[l-1] =' ';
				l--;
			}
			s[l] = '|';
			s[l+1]=' ';
			s[l+2]=0;
			outtextxy(px,py,s);	
			if(s[l]==' ') s[l]='\0';
		
		}
	}
	if((mx!=-1)&&(my!=-1)) {
	IDnext=MID[mx][my];
	}
}

int ScannerNum(char s[], int max, int px ,int py,int ID, int &IDnext)
{
	setcolor(9);
	setbkcolor(15);
	settextstyle(0,0,2);

	int mx=-1;
	int my=-1;
	unsigned int l = strlen(s);
	s[l] ='|';
	s[l+1]=0;
	outtextxy(px,py,s);
	while(1)
	{
		getmouseclick(WM_LBUTTONDOWN,mx,my);
		clearmouseclick(WM_LBUTTONDOWN);
		delay(1);
		if  (!(((mx==-1)&&(my==-1))||(MID[my][mx]== ID))) {
			
			s[l] = ' ';
			s[l+1]=0;
			outtextxy(px,py,s);
			s[l]= '\0';	
			break;
		}
		if(kbhit())
		{
				
			char c = getch();
			
			if(l<max)
			{
				
				if(c>='0' && c<='9')
				{
					s[l] = c;
					s[l+1]=0;
				 outtextxy(px,py,s);
					l++;
				}
			}
			if(c == ENTER) {
				s[l] = ' ';
				s[l+1]=0;
				outtextxy(px,py,s);
				s[l]= '\0';
				break;
			}
			if(c == BACKSPACE&&l>0){
				s[l]=' ';
				s[l+1]=0;
				outtextxy(px,py,s);
				s[l-1] =' ';
			
				l--;
			}
			s[l] = '|';
			s[l+1]=' ';
			s[l+2]=0;
			outtextxy(px,py,s);	
			if(s[l]==' ') s[l]='\0';
		}
	}
	if((mx!=-1)&&(my!=-1)) 
	IDnext=MID[mx][my];
}

int ScannerFloat(char s[], int max, int px ,int py,int ID, int &IDnext)
{
	setcolor(9);
	setbkcolor(15);
	settextstyle(0,0,2);

	int mx=-1;
	int my=-1;
	unsigned int l = strlen(s);
	s[l] ='|';
	s[l+1]=0;
	outtextxy(px,py,s);
	while(1)
	{
		getmouseclick(WM_LBUTTONDOWN,mx,my);
		clearmouseclick(WM_LBUTTONDOWN);
		delay(1);
		if  (!(((mx==-1)&&(my==-1))||(MID[my][mx]== ID))) {
			
			s[l] = ' ';
			s[l+1]=0;
			outtextxy(px,py,s);
			s[l]= '\0';	
			break;
		}
		if(kbhit())
		{
				
			char c = getch();
			
			if(l<max)
			{
				
				if(c>='0' && c<='9' || c=='.')
				{
					s[l] = c;
					s[l+1]=0;
				 outtextxy(px,py,s);
					l++;
				}
			}
			if(c == ENTER) {
				s[l] = ' ';
				s[l+1]=0;
				outtextxy(px,py,s);
				s[l]= '\0';
				break;
			}
			if(c == BACKSPACE&&l>0){
				s[l]=' ';
				s[l+1]=0;
				outtextxy(px,py,s);
				s[l-1] =' ';
			
				l--;
			}
			s[l] = '|';
			s[l+1]=' ';
			s[l+2]=0;
			outtextxy(px,py,s);	
			if(s[l]==' ') s[l]='\0';
		}
	}
	if((mx!=-1)&&(my!=-1)) 
	IDnext=MID[mx][my];
}

void outWrapTextXY(int x, int y, int soKyTuTrenMotHang, int khoangCachGiuaHang, char s[]){
//	setcolor(9);
	setbkcolor(15);
	settextstyle(0,0,2);
	int len = strlen(s);
	
	int sPos = 0;
	int cSpace = 0;
	int countLineChar = 0;
	int rowCount = 0;
	while(sPos<len){
		if(s[sPos]==' '){
			cSpace=sPos;
		}
		sPos++;
		countLineChar++;
		if(countLineChar==soKyTuTrenMotHang){
			countLineChar=0;
			sPos=cSpace+1;
			rowCount++;
		}
	}
	
	if(countLineChar>0) rowCount++;
	
	sPos = 0;
	cSpace = 0;
	countLineChar = 0;
	char **charList = new char*[rowCount];
	int i = 0;
	int startPosition = 0;
	while(sPos<len){
		if(s[sPos]==' '){
			cSpace=sPos;
		}
		sPos++;
		countLineChar++;
		if(countLineChar==soKyTuTrenMotHang){
			countLineChar=0;
			charList[i] = new char[soKyTuTrenMotHang+1];
			strncpy(charList[i], &s[startPosition], cSpace-startPosition);
			charList[i][cSpace-startPosition]=0;
			sPos=cSpace+1;
			startPosition=sPos;
			i++;
		}
	}
	
	if(countLineChar>0){
		charList[i] = new char[soKyTuTrenMotHang+1];
		strncpy(charList[i], &s[startPosition], len-startPosition);
		charList[i][len-startPosition]=0;
	}
	
	for(int i=0; i<rowCount; i++){
		outtextxy(x, y+(i*khoangCachGiuaHang), charList[i]);
	}
	
}

void ScannerWrapString(char s[],int max, int px ,int py,int ID,int &IDnext, int lineChar, int lineSpace){
	cout<<"vo nhapo chuoi";
	setcolor(9);
	setbkcolor(15);
	settextstyle(0,0,2);

	int mx=-1;
	int my=-1;
	unsigned int l = strlen(s);
	s[l] ='|';
	s[l+1]=0;
	outWrapTextXY(px,py, lineChar, lineSpace, s);
	while(1)
{ 
         delay(0.1);
		getmouseclick(WM_LBUTTONDOWN,mx,my);
		clearmouseclick(WM_LBUTTONDOWN);
		
		if  (!(((mx==-1)&&(my==-1))||(MID[my][mx]== ID))) {
			cout<<" thoat";
			setcolor(15);
			outWrapTextXY(px,py, lineChar, lineSpace, s);
			setcolor(9);
			s[l] = ' ';
			s[l+1]=0;
			outWrapTextXY(px,py, lineChar, lineSpace, s);
			s[l]= '\0';	
			break;
		}
		if(kbhit())
		{			
		setcolor(15);
		outWrapTextXY(px,py, lineChar, lineSpace, s);
		setcolor(9);
		char c = getch();
			if(l<max)
			{
				if((l==0||s[l-1]==' '))
				{
					if(c<='z'&&c>='a')
					c=c+'A'-'a';
					else
					c=c;
					
				}
				else if(c<='Z'&&c>='A')
				c=c-'A'+'a';
				setcolor(15);
				outWrapTextXY(px,py, lineChar, lineSpace, s);
				setcolor(9);
				if(c=='_')
				{
					s[l] = c;
					l++;
					s[l]=0;
				}
				if(c>='a' && c<='z')
				{
					s[l] = c;
					l++;
					s[l]=0;
				}
				if(c>='A' && c<='Z')
				{
				s[l] = c;
					l++;
					s[l]=0;
				}
				if(c>='0' && c<='9')
				{
					s[l] = c;
					l++;
					s[l]=0;
				}
				if(l>0) if(s[l-1]!=' ' && c == ' ')
				{
					s[l] = c;
					l++;
					s[l]=0;
				}
				if((l==0||s[l-1]==' ')&&(s[l]>='a'||s[l]<='z'))
				s[l]=s[l]+'A'-'a';
				s[l+1]=0;
				outWrapTextXY(px,py, lineChar, lineSpace, s);
			}
			if(c == ENTER) {
				setcolor(15);
				outWrapTextXY(px,py, lineChar, lineSpace, s);
				setcolor(9);
				s[l] = ' ';
				s[l+1]=0;
				outWrapTextXY(px,py, lineChar, lineSpace, s);
				s[l]= '\0';
				break;
			}
			if(c == BACKSPACE&&l>0)
			{
				setcolor(15);
				outWrapTextXY(px,py, lineChar, lineSpace, s);
				setcolor(9);
				s[l]=' ';
				s[l+1]=0;
				outWrapTextXY(px,py, lineChar, lineSpace, s);
				s[l-1] =' ';
				l--;
			}
			setcolor(15);
			outWrapTextXY(px,py, lineChar, lineSpace, s);
			setcolor(9);
			s[l] = '|';
			s[l+1]=' ';
			s[l+2]=0;
			outWrapTextXY(px,py, lineChar, lineSpace, s);
			if(s[l]==' ') s[l]=0;
		
		}
	}
	if((mx!=-1)&&(my!=-1)) {
	IDnext=MID[mx][my];
	}
}
void form_dangnhap(){

	setbkcolor(15);				// set background
	cleardevice();
	taoo(10+440,10+190,500+440,300+190,0,9,14);
	taoo(100+440,100+190,450+440,150+190,1,15,14);
	taoo(100+440,160+190,450+440,210+190,2,15,14);
	button(215+440,10+190,215+440,100+190,0,"LOGIN",3,9,0);
	button(215+440,220+190,375+440,270+190,3,"DANG NHAP",2,2,0);

}
void khunghienthi();
void thongtinlop(){
	setcolor(9);
	setbkcolor(9);
	rectangle(10,65,400+110,780);
	setcolor(0); 
	outtextxy(15,90,"MA LOP");
	taoo(140,90,395+110,120,11,15,9);
    outtextxy(15,130,"TEN LOP");
    taoo(140,130,395+110,190,12,15,9);
}
void banglop(int trang){
		setcolor(9);
	setbkcolor(15);
	int dd[3]={70,190,500};//100,300,500
	char td[][50]={"STT","MA LOP","TEN LOP"};
	taobang(550,70,25,3,dd,15,9,16,999,trang,td);
}
void cumchucnanglop(){

	button(15,200,115,230,13,"LUU",2,2,0);
	button(295+100,200,395+100,230,14,"XOA",2,2,0);
	
	button(450+90,480,550+90,510,15,"PREVI",2,2,0);
	button(1220,480,1320,510,16,"NEXT",2,2,0);
	button(100+50,240,320+50,270,17,"DS SINH VIEN",2,2,0);
		button(100+50,290,320+50,320,99,"  THOAT",2,2,0);
	
	
}
void khungquanlylop(){

     setcolor(9);
     
	rectangle(5,60,1345,780);
	thongtinlop();
	banglop(1);
	cumchucnanglop();

}
void thongtinsinhvien(){
		setcolor(9);
	setbkcolor(9);
	rectangle(10,65,400,780);
	setcolor(0); 
	
	outtextxy(15,90,"MA LOP");    //21
	taoo(140,90,395,120,21,15,9);
    outtextxy(15,130,"MSSV  ");
    taoo(140,130,395,160,22,15,9);  //22
     outtextxy(15,170,"HO    ");      //23
    taoo(140,170,395,200,23,15,9);
     outtextxy(15,210,"TEN   ");
    taoo(140,210,395,240,24,15,9);  //24
    button(15+100,250,115+100,280,25,"  NAM",2,15,0);       //25
     button(290,250,390,280,26,"  NU",2,15,0);         //26

    
}
void cumchucnangsinhvien(){
		 button(15+100,300,115+100,330,27,"LUU",2,2,0);    //27
      button(290,300,390,330,28,"XOA",2,2,0);  
      button(200,350,320,380,29,"THOAT",2,2,0);     //29
      button(1320,70,1350,100,2100,">",2,2,0);         //2100
	   button(1320,105,1350,135,2101,"<",2,2,0);          //2101                              // in cac cot ds diem
	button(450,480,550,510,2102,"PREVI",2,2,0);            //2002
	button(1220,480,1320,510,2103,"NEXT",2,2,0);          //2103
    taoo(410,  520, 1200, 550, 2200, 15, 9);
    button(1220,520,1320,550,2201,"LOC",2,2,0);
	}
void bangsinhvien(int trang){
	setcolor(9);
	setbkcolor(15);
	int dd[9]={60,180,250,70,70,70,70,70,70};
	char td[][50]={"STT","MSSV","HO TEN"," "," "," "," "," "," "};
	taobang(410,70,25,9,dd,15,9,16,1999,trang,td);
}	
void khungquanlysinhvien(){
    setcolor(9);
	rectangle(5,60,1345,780);
	thongtinsinhvien();
	bangsinhvien(1);
	cumchucnangsinhvien();
}

void thongtinmonhoc(){
	setcolor(9);
	setbkcolor(9);
	rectangle(10,65,500,780);
	setcolor(0); 
	outtextxy(15,90,"MA MON");
	taoo(140,90,495,120,31,15,9);  //31
    outtextxy(15,130,"TEN MON");
    taoo(140,130,495,160,32,15,9); //32
}
void bangmonhoc(int trang){
		setcolor(9);
	setbkcolor(15);
	int dd[3]={100,200,500};
	char td[][50]={"STT","MA MON","TEN MON"};
	taobang(510,70,25,3,dd,15,9,16,2999,trang,td);
}
void cumchucnangmonhoc(){
	button(50,200,150,230,33,"LUU",2,2,0);
	button(330,200,430,230,34,"XOA",2,2,0);
	
	button(550,480,650,510,35,"PREVI",2,2,0);
	button(1220,480,1320,510,36,"NEXT",2,2,0);
	button(140,240,360,270,37,"DS CAU HOI",2,2,0);
	button(140,290,360,320,99,"  THOAT",2,2,0);
	
}
void khungquanlymonhoc(){

     setcolor(9);
	rectangle(5,60,1345,780);
		thongtinmonhoc();
	bangmonhoc(1);
	cumchucnangmonhoc();
}
void thongtincauhoi(){
	setcolor(9);
	setbkcolor(9);
//	rectangle(10,65,400,780);
	setcolor(0); 
	outtextxy(15,90,"MA MON");
	taoo(130,90,395,120,41,15,9);  //41
    outtextxy(410,90,"TEN MON");
    taoo(530,90,810,120,42,15,9); //42
    
    outtextxy(15,125,"CAU HOI");
    taoo(130,125,1340,155,43,15,9);  //43
    outtextxy(15,160,"A");
    taoo(130,160,1340,190,431,15,9); //431
      outtextxy(15,195,"B");
    taoo(130,195,1340,225,432,15,9);  //432
      outtextxy(15,230,"C");
    taoo(130,230,1340,260,433,15,9);   //433
      outtextxy(15,265,"D");
    taoo(130,265,1340,295,434,15,9);   //434
    
}
void bangcauhoi(int trang){
	setcolor(9);
	setbkcolor(15);
	int dd[2]={100,1230};
	char td[][50]={"STT","                  CAU HOI"};
	taobang(15,300,30,2,dd,15,9,11,3999,trang,td);
	
}
void cumchucnangcauhoi(){

	button(990,90,1090,120,44,"LUU",2,2,0); //44
	button(1100,90,1200,120,45,"XOA",2,2,0); //45
	
	button(300,640,400,670,46,"PREVI",2,2,0); //46
	button(930,640,1030,670,47,"NEXT",2,2,0); //47
	
	
	
}
void khungquanlycauhoi(){

    setcolor(9);

	thongtincauhoi();
	bangcauhoi(1);
	cumchucnangcauhoi();
}

void thongtinbode(){
		setcolor(9);
	setbkcolor(9);
	rectangle(10,65,400,780);

	setcolor(0);
	outtextxy(15,90,"MA DE  ");    //51
	taoo(140,90,395,120,51,15,9);
    outtextxy(15,130,"MA MON ");
    taoo(140,130,395,160,52,15,9);  //52
     outtextxy(15,170,"SLCH   ");      
    taoo(140,170,395,200,53,15,9);  //53
     outtextxy(15,210,"TIME   ");
    taoo(140,210,395,240,54,15,9);    //54
    

    
}
void cumchucnangbode(){
		 button(15+100,300,115+100,330,55,"TAO",2,2,0); //55    
      button(290,300,390,330,56,"XOA",2,2,0);  
      
      button(200,350,320,380,99,"THOAT",2,2,0);     
           
	button(450,480,550,510,57,"PREVI",2,2,0);         
	button(1220,480,1320,510,58,"NEXT",2,2,0);         
      
	}
void bangbode(int trang){
	setcolor(9);
	setbkcolor(15);
	int dd[5]={120,200,200,200,200};
	char td[][50]={"STT","MA DE","MA MON","SLCH ","THOI GIAN"};
	taobang(410,70,25,5,dd,15,9,16,5000,trang,td);
}	
void khungquanlybode(){

    setcolor(9);
	rectangle(5,60,1345,780);
	thongtinbode();
	bangbode(1);
	cumchucnangbode();
}
void khungchucnangthi(char monhoc[], char maMon[], char slch[], char diem[], bool isSV){
		
	rectangle(10,65,400,780);
	setcolor(0);
//	outtextxy(15,90,"MON  ");    //61
//	taoo(140,90,395,120,61,15,9);
	if(strlen(monhoc)>0){
		setbkcolor(15);
		outtextxy(420, 750, monhoc);
	}
	setbkcolor(9);
    outtextxy(15,130,"MA MON ");
    taoo(140,130,395,160,62,15,9);  //62
    outtextxy(145, 132, maMon);
    
     outtextxy(15,170,"SLCH   ");      
    taoo(140,170,395,200,63,15,9);  //63
    outtextxy(145, 172, slch);
    
     outtextxy(15,210,"TIME   ");
    taoo(140,210,395,240,64,15,9);    //64
        
     outtextxy(15,250,"DIEM  ");
    taoo(140,250,395,280,65,15,9);    //65
    outtextxy(145, 252, diem);
    
    button(15,300,395,340,66,"       BAT DAU",2,2,0);
    button(15,350,395,390,67,"       NOP BAI",2,2,0);
    if(isSV){
    	button(15,400,395,440,68,"    XEM CHI TIET",2,2,0);
	}
    
    	button(15,445,395,485,99,"        THOAT",2,2,0);
    
}
 void khunghienthithi(/*char *ch, char *a, char *b , char *c, char *d*/){
 	setbkcolor(9);
	rectangle(400,65,1340,490);
	
 }
  void giaodiencautraloi(char *dsTraLoi, int sl){
	
	setcolor(0);
    setbkcolor(9);
    int x=410;
    int y=500;
	char so[10]="";
    for(int i=1;i<=sl;i++){
    	setfillstyle(1, 2);
		setbkcolor(2);
		setcolor(0);
		itoa(i,so,10);
    	if(dsTraLoi!=NULL){
    		if(dsTraLoi[i-1]==' '){
	    		setfillstyle(1, 9);
	    		setbkcolor(9);
	    		setcolor(0);
			}
			else{
				so[strlen(so)] = dsTraLoi[i-1];
	    		so[strlen(so)+1]=0;
			}
		}
		bar(x,y,x+50,y+20);
    	outtextxy(x,y,so);
    	if(x<1300)
    	x=x+50+5;
    	else{
			x=310;
	    	y=y+20+5;
		}
    }   
    
}
int timvitri(int mx, int my, int sl){
	int x=400;
    int y=500;
	  for(int i=1;i<=sl;i++){
//    	bar(x,y,x+50,y+20);
       if(x<mx&&mx<x+50&&my>y&&my<y+20)
         return i;
    	if(x<1300)
    	x=x+50+5;
    	else
    	{x=310;
    	y=y+20+5;
		}
    	}
    return -1;
}
 void khungtraloi(int slch, char *dsDapAn){
 	giaodiencautraloi(dsDapAn, slch);
 }

void khungthi(int sl, char *dsDapAn, char monhoc[], char maMon[], char slch[], char diem[], bool isSV){
	settextstyle(0,0,2);
    setcolor(9);
	rectangle(5,60,1345,780);
	khungchucnangthi(monhoc, maMon, slch, diem, isSV);
	khunghienthithi();
	khungtraloi(sl, dsDapAn);
}
void menuchinh(	 int lc){
    setbkcolor(15);					// set background
   	cleardevice();
	setcolor(0);
    	
	button(5,5,220,50,1,"  QL LOP",2,9,0);
    button(230,5,450,50,2,"QL SINH VIEN",2,9,0);
    button(460,5,680,50,3," QL MON HOC",2,9,0);
    button(690,5,910,50,4," QL CAU HOI",2,9,0);
    button(920,5,1140,50,6," THI THU",2,9,0);
//    button(1150,5,1340,50,6,"  THI THU",2,9,0);
    setfillstyle(1,15);
     bar(5,50,1340,60);
     setcolor(9);
	rectangle(5,60,1345,780);	
    
    switch(lc){
    	case 1:{
    			button(5,5,220,50+10,1,"  QL LOP",2,1,15);
    button(230,5,450,50,2,"QL SINH VIEN",2,9,0);
    button(460,5,680,50,3," QL MON HOC",2,9,0);
    button(690,5,910,50,4," QL CAU HOI",2,9,0);
     button(920,5,1140,50,6," THI THU",2,9,0);
//    button(920,5,1140,50,5," QL BO DE",2,9,0);
//    button(1150,5,1340,50,6,"  THI THU",2,9,0);
    break;
		}
    	case 2:{
    			button(5,5,220,50,1,"  QL LOP",2,9,0);
    button(230,5,450,50+10,2,"QL SINH VIEN",2,1,15);
    button(460,5,680,50,3," QL MON HOC",2,9,0);
    button(690,5,910,50,4," QL CAU HOI",2,9,0);
    button(920,5,1140,50,6," THI THU",2,9,0);
    break;
		}
		case 3:{
    			button(5,5,220,50,1,"  QL LOP",2,9,0);
    button(230,5,450,50,2,"QL SINH VIEN",2,9,0);
    button(460,5,680,50+10,3," QL MON HOC",2,1,15);
    button(690,5,910,50,4," QL CAU HOI",2,9,0);
     button(920,5,1140,50,6," THI THU",2,9,0);
    break;
		}
		case 4:{
    		button(5,5,220,50,1,"  QL LOP",2,9,0);
    button(230,5,450,50,2,"QL SINH VIEN",2,9,0);
    button(460,5,680,50,3," QL MON HOC",2,9,0);
    button(690,5,910,50+10,4," QL CAU HOI",2,1,15);
    button(920,5,1140,50,6," THI THU",2,9,0);
    break;
		}
    	case 5:{
    			button(5,5,220,50,1,"  QL LOP",2,9,0);
    button(230,5,450,50,2,"QL SINH VIEN",2,9,0);
    button(460,5,680,50,3," QL MON HOC",2,9,0);
    button(690,5,910,50,4," QL CAU HOI",2,9,0);
   button(920,5,1140,50,6," THI THU",2,9,0);
    break;
		}
		case 6:{
    			button(5,5,220,50,1,"  QL LOP",2,9,0);
    button(230,5,450,50,2,"QL SINH VIEN",2,9,0);
    button(460,5,680,50,3," QL MON HOC",2,9,0);
    button(690,5,910,50,4," QL CAU HOI",2,9,0);
    button(920,5,1140,50+10,6," THI THU",2,1,15);
    break;
		}
			
  }
    

	
}

void khunghienthi(){
	setfillstyle(1,15);
//     bar(5,50,1340,60);
     setcolor(9);
	rectangle(5,60,1345,780);	
   setcolor(9);
	rectangle(0,60,1340,780);	
}
	
void inDSLop(DanhSachLop danhSachLop, int trang){
	setcolor(9);
	setbkcolor(15);
	for(int i=0; i<15 && i+15*(trang-1)<danhSachLop.soLuong; i++){
		outtextxy(510+113, 72+(i+1)*25, danhSachLop.danhSachLop[i+15*(trang-1)]->maLop);
		outtextxy(510+302, 72+(i+1)*25, danhSachLop.danhSachLop[i+15*(trang-1)]->tenLop);
	}
}

void layThongTinLop(Lop lop){
	setcolor(9);
	setbkcolor(15);
	outtextxy(145,95, lop.maLop);
//	outtextxy(145, 135, lop.tenLop);
	outWrapTextXY(145, 135, 16, 30, lop.tenLop);
}

void clearThongTinLop(){
	setcolor(9);
	setbkcolor(15);
	outtextxy(145,95, "               ");
//	outtextxy(145, 135, "               ");
	outWrapTextXY(145, 135, 16, 30, "                            ");
}

void inDSSinhVien(DanhSachSinhVien danhSachSinhVien, SinhVien *&mangSinhVien, int &n, int trang){
	setcolor(9);
	setbkcolor(15);
//	int dd[9]={60,180,250,70,70,70,70,70,70};
//	char td[][50]={"STT","MSSV","HO TEN"," "," "," "," "," "," "};
//	taobang(410,70,25,9,dd,15,9,16,1999,trang,td);
	
	if(mangSinhVien!=NULL){
		delete[] mangSinhVien;
	}
	
	mangSinhVien = danhSachTuyenTinh(danhSachSinhVien, n);
	
	for(int i=0; i<15 && i+15*(trang-1)<n; i++){
		outtextxy(470+5, 72+(i+1)*25, mangSinhVien[i+15*(trang-1)].maSV);
		char hoten[60] = "";
		strcpy(hoten, mangSinhVien[i+15*(trang-1)].ho);
		strcat(hoten, " ");
		strcat(hoten, mangSinhVien[i+15*(trang-1)].ten);
		outtextxy(470+180+5, 72+(i+1)*25, hoten);
	}
	
}

void layThongTinSinhVien(SinhVien sinhVien){
	setcolor(9);
	setbkcolor(15);
	outtextxy(145, 135, sinhVien.maSV);
	outtextxy(145, 175, sinhVien.ho);
	outtextxy(145, 215, sinhVien.ten);
	if(strcmp(sinhVien.phai,"NAM")==0){
		button(15+100,250,115+100,280,25,"  NAM",2,2,0);
    	button(290,250,390,280,26,"  NU",2,15,0);
	}
	else{
		button(15+100,250,115+100,280,25,"  NAM",2,15,0);
    	button(290,250,390,280,26,"  NU",2,2,0);
	}
}
void clearThongTinSinhVien(){
	setcolor(9);
	setbkcolor(15);
	outtextxy(145, 135, "               ");
	outtextxy(145, 175, "               ");
	outtextxy(145, 215, "               ");
	button(15+100,250,115+100,280,25,"  NAM",2,2,0);
	button(290,250,390,280,26,"  NU",2,15,0);
}

void inDSMonHoc(DanhSachMonHoc &danhSachMonHoc, MonHoc *&mangMonHoc, int &nMonHoc, int trang){
	setcolor(9);
	setbkcolor(15);
//	int dd[3]={100,300,500};
//	char td[][50]={"STT","MA MON","TEN MON"};
//	taobang(410,70,25,3,dd,15,9,16,2999,trang,td);
	
	if(mangMonHoc!=NULL){
		delete[] mangMonHoc;
	}
	
	mangMonHoc = doCayVaoMangTuyenTinh(danhSachMonHoc, nMonHoc);
	

	for(int i=0; i<15 && i+15*(trang-1)<nMonHoc; i++){
		outtextxy(620+5, 72+(i+1)*25, mangMonHoc[i+15*(trang-1)].maMH);
		outtextxy(620+200+5, 72+(i+1)*25, mangMonHoc[i+15*(trang-1)].tenMH);
	}	
		
}

void layThongTinMonHoc(MonHoc monHoc){
	setcolor(9);
	setbkcolor(15);
	outtextxy(145,95, monHoc.maMH);
	outtextxy(145, 135, monHoc.tenMH);
}

void clearThongTinMonHoc(){
	setcolor(9);
	setbkcolor(15);
	outtextxy(145,95, "               ");
	outtextxy(145, 135, "               ");
}

void inDSCauHoi(DanhSachCauHoi &danhSachCauHoi, int trang){
	setcolor(9);
	setbkcolor(15);
	
	for(int i=0; i<10 && i+10*(trang-1)<danhSachCauHoi.soLuong; i++){
		outtextxy(115+5, 302+(i+1)*30, danhSachCauHoi.danhSachCauHoi[i+10*(trang-1)].noiDung);
	}
	
}

void layThongTinCauHoi(CauHoi cauHoi){
	setcolor(9);
	setbkcolor(15);
	outtextxy(135,130, cauHoi.noiDung);
	outtextxy(135,165, cauHoi.dapAnA);
	outtextxy(135,200, cauHoi.dapAnB);
	outtextxy(135,235, cauHoi.dapAnC);
	outtextxy(135,270, cauHoi.dapAnD);
}

void clearThongTinCauHoi(){
	setcolor(9);
	setbkcolor(15);
	outtextxy(135,130, "                                                                      ");
	outtextxy(135,165, "                                                                      ");
	outtextxy(135,200, "                                                                      ");
	outtextxy(135,235, "                                                                      ");
	outtextxy(135,270, "                                                                      ");
}


void clearDanhSachCauHoi(){
	setcolor(9);
		setbkcolor(15);
		outtextxy(120,332, "                                             ");
		outtextxy(120,362, "                                             ");
		outtextxy(120,392, "                                             ");
		outtextxy(120,422, "                                             ");
		outtextxy(120,452, "                                             ");
		outtextxy(120,482, "                                             ");
		outtextxy(120,512, "                                             ");
		outtextxy(120,542, "                                             ");
		outtextxy(120,572, "                                             ");
		outtextxy(120,602, "                                             ");
	
}

void hienThiCauHoi(CauHoi cauHoi, int ord, int *dsSX, char dapAn){
 	setcolor(9);
	setbkcolor(15);
	setfillstyle(1, 15);
	bar(400,65,1340,490);
	rectangle(400,65,1340,490);
	
	settextstyle(0,0,2);
	char title[1000]="Cau ";
	char order[5]="";
	doiSangChuoi(order, ord);
	strcat(title, order);
	strcat(title, ": ");
	strcat(title, cauHoi.noiDung);
	outtextxy(405,145,title);
	
	
	if(dapAn=='A'){
		button(405,180,445,210,611,"A",2,14,0);
	}
	else{
		button(405,180,445,210,611,"A",2,9,0);
	}
	if(dsSX[0]==0){
		outtextxy(455,180,cauHoi.dapAnA);
	}
	else if(dsSX[0]==1){
		outtextxy(455,180,cauHoi.dapAnB);
	}
	else if(dsSX[0]==2){
		outtextxy(455,180,cauHoi.dapAnC);
	}
	else if(dsSX[0]==3){
		outtextxy(455,180,cauHoi.dapAnD);
	}

	if(dapAn=='B'){
		button(405,180+77,445,210+77,612,"B",2,14,0);
	}
	else{
		button(405,180+77,445,210+77,612,"B",2,9,0);
	}
	if(dsSX[1]==0){
		outtextxy(455,180+77,cauHoi.dapAnA);
	}
	else if(dsSX[1]==1){
		outtextxy(455,180+77,cauHoi.dapAnB);
	}
	else if(dsSX[1]==2){
		outtextxy(455,180+77,cauHoi.dapAnC);
	}
	else if(dsSX[1]==3){
		outtextxy(455,180+77,cauHoi.dapAnD);
	}

	if(dapAn=='C'){
		button(405,180+77+77,445,210+77+77,613,"C",2,14,0);
	}
	else{
		button(405,180+77+77,445,210+77+77,613,"C",2,9,0);
	}
	if(dsSX[2]==0){
		outtextxy(455,180+77+77,cauHoi.dapAnA);
	}
	else if(dsSX[2]==1){
		outtextxy(455,180+77+77,cauHoi.dapAnB);
	}
	else if(dsSX[2]==2){
		outtextxy(455,180+77+77,cauHoi.dapAnC);
	}
	else if(dsSX[2]==3){
		outtextxy(455,180+77+77,cauHoi.dapAnD);
	}

	if(dapAn=='D'){
		button(405,180+77+77+77,445,210+77+77+77,614,"D",2,14,0);
	}
	else{
		button(405,180+77+77+77,445,210+77+77+77,614,"D",2,9,0);
	}
	if(dsSX[3]==0){
		outtextxy(455,180+77+77+77,cauHoi.dapAnA);
	}
	else if(dsSX[3]==1){
		outtextxy(455,180+77+77+77,cauHoi.dapAnB);
	}
	else if(dsSX[3]==2){
		outtextxy(455,180+77+77+77,cauHoi.dapAnC);
	}
	else if(dsSX[3]==3){
		outtextxy(455,180+77+77+77,cauHoi.dapAnD);
	}
	
}

void inDSDiem(float **dsDiem, int nSV, int nMon, int trang, int cot, char dsMon[][20]){
//	int dd[9]={60,180,250,70,70,70,70,70,70};
//	char td[][50]={"STT","MSSV","HO TEN"," "," "," "," "," "," "};
//	taobang(410,70,25,9,dd,15,9,16,1999,trang,td);
	if(dsDiem==NULL) return;
	setcolor(9);
	setbkcolor(15);
	settextstyle(0,0,2);
	int x=410;
	int y=70;
	int d=25;
	
	int maxCol = 6;
	
	for(int j=0; j<maxCol && j+(cot-1)*maxCol < nMon; j++){
		if(j==0){
			outtextxy(x+65+180+250, y+1, dsMon[j+(cot-1)*maxCol]);
		}
		else if(j==1){
			outtextxy(x+65+180+250+70, y+1, dsMon[j+(cot-1)*maxCol]);
		}
		else if(j==2){
			outtextxy(x+65+180+250+70+70, y+1, dsMon[j+(cot-1)*maxCol]);
		}
		else if(j==3){
			outtextxy(x+65+180+250+70+70+70, y+1, dsMon[j+(cot-1)*maxCol]);
		}
		else if(j==4){
			outtextxy(x+65+180+250+70+70+70+70, y+1, dsMon[j+(cot-1)*maxCol]);
		}
		else if(j==5){
			outtextxy(x+65+180+250+70+70+70+70+70, y+1, dsMon[j+(cot-1)*maxCol]);
		}
	}
	
	for(int i=0; i<15 && i+(trang-1)*15 < nSV; i++){
		for(int j=0; j<maxCol && j+(cot-1)*maxCol < nMon; j++){
			char diem[13];
			if(dsDiem[i+(trang-1)*15][j+(cot-1)*maxCol]==-1){
				strcpy(diem, "CT");
			}
			else{
				doiSangChuoiThuc(diem, dsDiem[i+(trang-1)*15][j+(cot-1)*maxCol]);
			}
			
			if(j==0){
				outtextxy(x+65+180+250, y+(25*(i+1)+1), diem);
			}
			else if(j==1){
				outtextxy(x+65+180+250+70, y+(25*(i+1)+1), diem);
			}
			else if(j==2){
				outtextxy(x+65+180+250+70+70, y+(25*(i+1)+1), diem);
			}
			else if(j==3){
				outtextxy(x+65+180+250+70+70+70, y+(25*(i+1)+1), diem);
			}
			else if(j==4){
				outtextxy(x+65+180+250+70+70+70+70, y+(25*(i+1)+1), diem);
			}
			else if(j==5){
				outtextxy(x+65+180+250+70+70+70+70+70, y+(25*(i+1)+1), diem);
			}
		}
	}
}

void inLoi(char c[]){
	setcolor(9);
	setbkcolor(15);
	settextstyle(0,0,2);
	outtextxy(15, 400, c);
}
void clearLoi(){
	setcolor(9);
	setbkcolor(15);
	settextstyle(0,0,2);
	outtextxy(15, 400, "                      ");
}

void inLoi(int x, int y, char c[]){
	setcolor(9);
	setbkcolor(15);
	settextstyle(0,0,2);
	outtextxy(x, y, c);
}
void clearLoi(int x, int y){
	setcolor(9);
	setbkcolor(15);
	settextstyle(0,0,2);
	outtextxy(x, y, "                      ");
}
