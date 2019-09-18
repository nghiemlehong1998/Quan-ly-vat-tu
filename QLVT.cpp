// code cua le hong nghiem
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <Windows.h>
#include "mylib.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#define MAXNV 501
#define MAXVT 500
using namespace std;

int KiemTraChuoi(string s)
{
 if(s[0]==32 || s.size()==0) return 0;//ki tu dau tien ko duoc nhap khoan trang.va do dai phai khac 0
    return 1;
}
int KiemTraDoDaiMa(string s) //Kiem tra do dai cua ma
{
    if(s.size()==5) return 1;
    return 0;
}

int Num(char x){ return x - '0';}
int ChuyenThanhSo(string  s) //Chuyen string thanh int 
{
    int res = 0;
    for(int i=0;i<s.size();i++) res = res*10 + Num(s[i]);
    return res;
}
string ChuyenThanhChuoi(int number){
    string s = "";
	while (number!=0){
		s=char((number%10)+48) + s;
		number=number/10;
	}
	if (s.length() < 2) s = '0' + s;
	return s;
}
int KiemTraNhapSoLuongTon(string s)
{
		for(int i = 0; i<s.size();i++)
	{
		if(	Num(s[i]) !=0 && Num(s[i])!=1 && Num(s[i])!=2 && Num(s[i])!=3 && Num(s[i])!=4 && Num(s[i])!=5 && Num(s[i])!=6 && Num(s[i])!=7 && Num(s[i])!=8 && Num(s[i])!=9 )
		{
			return 0;
		}
			
	}
	return 1;
}
int KiemTraNhapSoThapPhan(string s)
{
	for(int i = 0; i<s.size();i++)
	{
		if(	Num(s[i]) !=0 && Num(s[i])!=1 && Num(s[i])!=2 && Num(s[i])!=3 && Num(s[i])!=4 && Num(s[i])!=5 && Num(s[i])!=6 && Num(s[i])!=7 && Num(s[i])!=8 && Num(s[i])!=9&&Num(s[i])!=-2)
		{
			return 0;
		}
			
	}
	return 1;
}
int KiemTraBoTrong(string s)
{
	if (s.size()!=0) return 1;
	return 0;
}
void HD()
{
	char l=179;

    for(int i=0;i<=91;i++)
	{
		gotoxy(i,32);
		cout<<"_";
	}
    gotoxy(1,33);
    cout<<"+LUU Y:";
    gotoxy(60,33);
    cout<<"+Nhap phim ESC de thoat/tro ve.";
    
}
void MauCB()
{
    SetBGColor(2);
    SetColor(11);
}
void MauChon()
{
    SetBGColor(11);
    SetColor(12);
}
void MauLoi()
{
    SetBGColor(15);
    SetColor(12);
}
void Normal () {
	SetColor(WHITE);
	SetBGColor(0);
}
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
void resizeconsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, true);
}
void KhungNho(int x,int y)//khung bao quanh chu chon
{
	gotoxy(x,y);
//	SetColor(14);
	for(int i=0;i<30;i++)
	{
		if(i==0)
			cout<<char(218);
		else if(i==29)
			cout<<char(191);
		else cout<<char(196);
	}
	gotoxy(x,y+1);
	cout<<char(179);
	gotoxy(x+29,y+1);
	cout<<char(179);
	gotoxy(x,y+2);
	for(int i=0;i<30;i++)
	{
		if(i==0)
			cout<<char(192);
		else if(i==29)
			cout<<char(217);
		else cout<<char(196);
	}
	gotoxy(x+1,y+1);
}

void CanhBao(string s, int cot,int hang)
{
    do
    {

        gotoxy(cot,hang);
        cout<<s;//hien thi 1 chuoi ki tu
        Sleep(500);
        gotoxy(cot,hang);
        for(int i=0;i<s.size();i++) cout<<" ";
        Sleep(200);

    }
    while(!kbhit());
    gotoxy(cot,hang); for(int i=0;i<s.size();i++) cout<<" ";
}


// VAT TU
typedef struct 
{
	char mavt[11];
	char tenvt[10];
	char dvt[5];
	int sl;
} VatTu;

struct Node
{
	VatTu Data; 
	struct Node *left;
	struct Node *right;
};
typedef struct Node NODE;
typedef NODE* Tree;
Tree t = NULL; // Khoi tao cay nhi phan
//NHAN VIEN
typedef struct NhanVien
{
	string MANV;
	string HO;
	string TEN;
	string PHAI;
};
NhanVien *NVien[MAXNV];
int SLNV = 0;

int KiemTraTrungMaNV(int i)
{
	for(int j=0;j<SLNV;j++)
		if(NVien[j]->MANV==NVien[i]->MANV && j!=i)
			return 0;
	return 1;
}
//NGAY GIO VA HOA DON
struct Date
{
	int NGAY;
	int THANG;
	int NAM;
};
Date LayGioHeThong() //lay gio he thong
{
	time_t t = time(0);
	struct tm * now = localtime( & t );
	Date NgayHeThong;
	NgayHeThong.NGAY = now->tm_mday;
	NgayHeThong.THANG = now->tm_mon + 1;
	NgayHeThong.NAM = now->tm_year + 1900;
	return NgayHeThong;
}
string ChuyenNgayThanhChuoi(Date date)
	{
		string s = "";
		string tam = "";
		tam = ChuyenThanhChuoi(date.NGAY);
		s += tam + " / ";
		tam = ChuyenThanhChuoi(date.THANG);
		s += tam + " / ";
		tam = ChuyenThanhChuoi(date.NAM);
		s += tam;
		return s;
	}
string ChuyenNgayThanhChuoi2(Date date)
{
	string s= "";
	string tam ="";
	tam = ChuyenThanhChuoi(date.NAM);
	s += tam;
	tam = ChuyenThanhChuoi(date.THANG);
	s += tam;
	tam = ChuyenThanhChuoi(date.NGAY);
	s +=tam;
	return s; 
}
struct CT_HOADON
{
	char mavt[11];
	int soluong;
	long dongia;
	float VAT;
	struct CT_HOADON *next;
};
struct HOADON
{
	char SoHD[20];
	Date Ngay;
	char loai;
	string MANV;
 	CT_HOADON *CT_next;
	struct HOADON *next;
};
HOADON *first = NULL;

////////////////////
//VAT TU
int SoSanhChuoi(VatTu x, VatTu y)// So sanh hai chuoi x va y
{
	return strcmp(x.mavt,y.mavt);
}
/*void KhoiTaoCay(Tree &t) //Khoi tao cay luc ban dau
{
	t = NULL;
}*/

int KiemTraTrungMaVT(Tree root, string a)
{
	char s[11];
	strcpy(s , a.c_str());
	const int STACKSIZE = 500;
	Tree Stack [STACKSIZE];
	int sp = -1;
	Tree p = root;
	while (p!=NULL)
	{
		if(strcmp(p->Data.mavt, s) == 0 ) return 1 ;
		if(p->right!=NULL)
			Stack[++sp]=p->right;
		if(p->left!=NULL)
			p=p->left;
		else if(sp==-1)
		{
			break;
		}
		else p=Stack[sp--];
	}
	return 0;
}
int KiemTraCay(Tree t)
{
	return (t != NULL?  1:0);
}
void InSert(Tree &t, VatTu x)
{
	if(t == NULL)
	{
		NODE *q = new NODE;
		q ->Data = x;
		q ->left = q ->right = NULL;
		t = q;
	}
	else
	{
		if(SoSanhChuoi(t->Data, x)>0)
		{
			InSert(t ->left, x);
		}
		else if(SoSanhChuoi(t->Data, x )<0)
		{
			InSert(t ->right, x);
		}
	}
}

void SaveVT(Tree root)//dung duyet file theo kieu nlr khong de quy, de luu vao file txt
{

	ofstream f("VATTU.txt",ios::out);	
	const int STACKSIZE = 500;
	Tree Stack [STACKSIZE];
	int sp = -1;
	Tree p = root;
	while (p!=NULL)
	{
		f<< p->Data.mavt <<endl;
		f<< p->Data.tenvt << endl;
		f<< p->Data.dvt<<endl;
		f<< p->Data.sl<<endl;
		if(p->right!=NULL)
			Stack[++sp]=p->right;
		if(p->left!=NULL)
			p=p->left;
		else if(sp==-1)
		{
			break;
		}
		else p=Stack[sp--];
	}
	f.close();
}

void LoadVT(Tree &t) // Load file vao cay
{
   ifstream f ("VATTU.txt",ios::in);
   
   	while(!f.eof())
   		{
   			VatTu x;
			f>>x.mavt;
			f>>x.tenvt;
			f>>x.dvt;	
 	 		f>>x.sl; 
			   	 if(f.tellg()==-1)
  				{
  					break;
    			}
  				 else 
  				 {
   					InSert(t,x);	
   				}
   				
 	 		}
   f.close();
}

void HuongDanNhap()
{
    char l=179; 	 
    KhungNho(25,0);
    cout <<"      + THEM VAT TU +   ";
    cout <<endl;
    gotoxy(25,3);
    cout <<"     |Huong dan su dung|"; 
    cout <<endl;
    gotoxy(5,4);
    cout << "Nhap phim ESC ket thuc va khong luu " <<endl;
    gotoxy(5,5);
    cout << "Nhap Enter de tiep tuc nhap         " <<endl;
  	cout <<endl;    

		KhungNho(20,10);
		gotoxy(1,11);
		cout << "NHAP MA VAT TU ";
		KhungNho(20,13);
		gotoxy(1,14);
		cout << "NHAP TEN VAT TU ";
		KhungNho(20,16);
		gotoxy(1,17);
		cout <<"NHAP DON VI TINH ";
	
}

int NhapVatTuMoi()
{
	system("cls");
	HD();
	HuongDanNhap();
	int dong1=11, dong2 =14, dong3=17, dong4=20; //khai bao vi tri tung cot nhap
	int flag = 1;
	string f[3];
	f[0]="";//ma vat tu
	f[1]="";//ten vat tu
	f[2]="";//don vi tinh
/*	flag = 1: Nhap ma vat tu
	flag = 2: Nhap ten vat tu
	flag = 3: Nhap doi vi tinh*/
			
	 int vitri1 = 22, vitri2 = 22, vitri3 = 22;
 //	 int x = wherex();
  	 int y = wherey();
	 gotoxy(vitri1,dong1);
	 int check = 0;
while(check==0)
{
    while(kbhit())
    {
    	VatTu noidung; 
  
        if(flag==1)
        {
            vitri1 = 22 + f[0].size();//vi tri  con tro nam o cuoi cung cua chuoi           
            gotoxy(5,6);
            cout<<"*Ma Vat Tu phai co 5 ky tu                           ";
            gotoxy(5,7); 
            cout<<"*Gom cac ki tu  (A-Z)                                ";
            gotoxy(5,8);
            cout<<"*Cac so (0-9)                                        ";
           	gotoxy(vitri1, dong1);
       }
       else if(flag==2)
       {
       		vitri2 = 22 + f[1].size();//vi tri con nam o cuoi cung cua chuoi
            gotoxy(5,6);
            cout<<"*Ten VT khong bat dau bang khoang trang              ";
            gotoxy(5,7);
            cout<<"*Gom cac ki tu             (A-Z)                     ";
            gotoxy(5,8);
            cout<<"*Cac so (0-9)                                        ";
            gotoxy(vitri2, dong2);
	   }
	   else if(flag == 3)
	   {
	   	    vitri3 = 22 + f[2].size();
            gotoxy(5,6);
            cout<<"*DVT khong bat dau bang khoang trang                   ";
            gotoxy(5,7);
            cout<<"*Gom cac ki tu            (A-Z)                  	  ";
            gotoxy(5,8);
            cout<<"*Cac so (0-9)                                          ";
            gotoxy(vitri3, dong3);
         //   gotoxy(vitri,y);
         
	   }

	   //___________
	    char c = getch();
        if(c==27)//27 la phim esc thi thoat khoi khoi menu nhap vat tu
        {
        
			check = 1;
			return 1;
         
        }
        else if(c == 13) //Enter de nhan du lieu kiem tra
        {
        	if(flag == 1)
        	{
        		
        		  if(KiemTraTrungMaVT(t, f[0])==1)
                {
                    string s = "Ma vat tu ban nhap bi trung. Xin hay nhap lai               " ;
                    gotoxy(22,dong1);
                    cout<<f[0];//to mau
                     while(!kbhit())
                        CanhBao(s,2,25);
                    do
                    {
                      char  c1= getch();
                    }while(c!=13&&c!=27);
                    gotoxy(vitri1,dong1);
                   
                }
                else if(KiemTraDoDaiMa(f[0])==0)
                {
                    string s ="Ma vat tu phai co 5 chu so. Xin hay nhap lai             ";
                    gotoxy(22,dong1);                 
                    cout<<f[0];
                    while(!kbhit())
                        CanhBao(s,2,25);
                    do
                    {
                      char  c1= getch();
                    }while(c!=13&&c!=27);
                    gotoxy(vitri1,dong1);
                    
                }
              
                else
                {
                
                    gotoxy(22,dong1);
                    cout<<f[0];//xuat ra ma vat tu dung
                          
                    gotoxy(vitri2,dong2);
                    flag=2;//qua phan kiem tra ten
                }
			}
			else if(flag == 2)
			{
				if (KiemTraChuoi(f[1])==0)
                {                 
                    string s= "Ban da nhap sai ten vat tu. Ban hay nhap lai                  ";
                    gotoxy(22,dong2);
                    cout<<f[1];
                    while(!kbhit())
                        CanhBao(s,2,25);
                    do
                    {
                      char  c1= getch();
                    }while(c!=13&&c!=27);
                    gotoxy(vitri2,dong2);
                    
                }
               
                else
                {
                    gotoxy(22,dong2);
                    cout<<f[1];
              //    strcpy(noidung.tenvt, f[1].c_str());   
                    gotoxy(vitri3,dong3);  
                    flag=3;
                }
			}
			else if (flag == 3)
			{
					if (KiemTraChuoi(f[2])==0)
                {                 
                    string s= "Ban da nhap sai ten vat tu. Ban hay nhap lai                  ";
                    gotoxy(22,dong3);
                    cout<<f[2];
                    while(!kbhit())
                        CanhBao(s,2,25);
                    do
                    {
                      char  c1= getch();
                    }while(c!=13&&c!=27);
                    gotoxy(vitri3,dong3);
                    
                }
               
                else
                {
					strcpy(noidung.mavt, f[0].c_str());
                	strupr(noidung.mavt);
					strcpy(noidung.tenvt, f[1].c_str());
					strupr(noidung.tenvt);
					strcpy(noidung.dvt,f[2].c_str());
					noidung.sl = 0;
					InSert(t,noidung);
					SaveVT(t);
					return 0;
                   
                }
			}
		                
	    }
			
		else if((c>=48&&c<=57) || (c>=97 && c<=122) || (c>=65 && c<=90) || (c==32))//chi dc nhap so.chu thuong.chu hoa.khoang trang.
    	{
        	if (flag==1 && vitri1<40 && c!=32)//khong duoc nhap vao khoang trang
        	{
           		gotoxy(vitri1,dong1); //tang vi tri con tro nhap len,,de nhap ki tu tiep theo ko bi chong len
           		 if (c>=97 && c<=122) c = c-32; //chuyen tu ky tu thuong sang ky tu hoa
           		 cout<<c; //xuat ky tu vua nhap ra man hinh
           		 f[0].insert(f[0].end(),1,c);//chen ky tu vua nhap vao cuoi chuoi
           		 vitri1++; //tang vi tri cot xuat hien ky tu
       		 }
           else if (flag==2 && vitri2<40 /*&& c!=32*/)//khong duoc nhap vao khoang trang
            {
                gotoxy(vitri2,dong2);
                if (c>=97 && c<=122) c=c-32;
                cout<<c;
                f[1].insert(f[1].end(),1,c);
                vitri2++;
            }
            else if (flag==3 && vitri3<40 /*&& c!=32*/)
            {
                gotoxy(vitri3,dong3);
                if (c>=97 && c<=122) c=c-32;
                cout<<c;
                f[2].insert(f[2].end(),1,c);
                vitri3++;
            }
          
    	}	
            else if(c==8) //phim backspace.phim xoa chu
            {
                if(flag==1 && f[0].size()!=0)
                {
                    vitri1--;
                    gotoxy(vitri1,dong1);
                    cout << " ";
                    gotoxy(vitri1,dong1);
                    f[0].erase(f[0].end()-1);//xoa tu vi tri cuoi cung
                }
                else if(flag==2 && f[1].size()!=0)
                {
                    vitri2--;
                    gotoxy(vitri2,dong2);
                    cout << " ";
                    gotoxy(vitri2,dong2);
                    f[1].erase(f[1].end()-1);
                }
                else if(flag==3 && f[2].size()!=0)
                {
                    vitri3--;
                    gotoxy(vitri3,dong3);
                    cout << " ";
                    gotoxy(vitri3,dong3);
                    f[2].erase(f[2].end()-1);
                }
              
               
            }      
			else if (c==-32) 
			{
				char kk =getch();
			
				
				 if (kk== 72) //mui ten di len 
           		 {
           
                        if (flag == 1 && f[3]!="" )
                        {
                        	  gotoxy(vitri3,dong3);
                           	 flag=3;
						}
					
                          
                        else if (flag == 2 && f[0]!="" )
                        {
                        	gotoxy(vitri1,dong1);
                            flag=1;
						}
                            
                        else if (flag == 3 && f[1]!="")
                        {
                        	 gotoxy(vitri2,dong2);
                            flag=2;
						}
                           
                        
                        	
           			 }
            	else if (kk==80) //mui ten di xuong
            	{
            /*	if (y = dong1) flag =1;
			    if (y = dong2) flag =2;
				 if (y = dong3) flag =3;
				  if (y = dong4) flag =4;  */
                   // i=i+1; y = y+1;
                    if (flag == 1 && f[1]!="" ) //&& i<=ds.n)
                    {
                    	gotoxy(vitri2,dong2);
                        flag=2;
					}
                        
                    else if (flag == 2 &&f[2]!="" )//&& i<=ds.n)
                    {
                    	 gotoxy(vitri3,dong3);
                        flag=3;
					}
                       
                    else if (flag == 3 &&f[3]!="" )// && i<=ds.n)
                    {
                    	gotoxy(vitri1,dong1);
                        flag=1;
					}
                              
              	}
              	
            }
					
	}
}

}
void EscNhapVatTuMoi()
{
	int check = 0;
	while(check == 0)
	{
		check = NhapVatTuMoi();
	}
}

int  TinhSoNode(Tree root)
{
	int dem = 0;
	const int STACKSIZE = 500;
	Tree Stack [STACKSIZE];
	int sp = -1;
	Tree p = root;
	while (p!=NULL)
	{
		dem++;
		if(p->right!=NULL)
			Stack[++sp]=p->right;
		if(p->left!=NULL)
			p=p->left;
		else if(sp==-1)
		{
			break;
		}
		else p=Stack[sp--];
	}
	return dem;
}

Tree TimKiem (Tree t, string a)
{
	char s[11];
	strcpy(s,a.c_str());
	Tree  p;
	p=t;
	while(p!=NULL&&strcmp(s,p->Data.mavt)!=0)
	if(strcmp(s,p->Data.mavt) < 0)
		p=p->left;
	else
		p=p->right;
	return p;
}

void KhoiTaoMenuHieuChinhVT()
{
	system("cls");
	gotoxy(5,1);
	cout << "HIEU CHINH THONG TIN VAT TU";
	gotoxy(1,3);
	cout << "1. HIEU CHINH TEN VAT TU   ";
	gotoxy(1,5);
	cout << "2. HIEU CHINH DON VI TINH  ";
	HD();
}
void HieuChinhVatTu(string s)
{
	Tree p;
	p = TimKiem(t,s);
	KhoiTaoMenuHieuChinhVT();
	string lc[6];
	lc[3]="1. HIEU CHINH TEN VAT TU   ";
	lc[5]="2. HIEU CHINH DON VI TINH  ";
	gotoxy(1,3);
	MauChon();
	cout << lc[3];
	  while(1)
    {
    	char kk = getch();
    	if (kk == 72)//phim di chuyen len
           	{
                int y = wherey();
                if (y == 3) //neu dang o hang dau ma nhan phim len thi di chuyen xuong hang cuoi cung
               	 {
                    gotoxy(1,y);
                    Normal ();
                    cout<<lc[y];
                    gotoxy(1,5);
                    MauChon();
                    cout<<lc[5];
                   	Normal ();
                }
                else 
                {
                    gotoxy(1,y);
                    Normal ();
                    cout<<lc[y];
                    gotoxy(1,y-2);
                    MauChon();
                    cout<<lc[y-2];
                   	Normal ();
                }
            }
         if (kk==80)
            {
                int y = wherey();
                if (y == 5) //neu o hang cuoi ma di chuyen xuong thi dua con tro ve hang dau
                {
                    gotoxy(1,5);
                    Normal ();
                    cout<<lc[y];
                    gotoxy(1,3);
                    MauChon();
                    cout<<lc[3];
                   	Normal ();
                }
                else
                {
                    gotoxy(1,y);
                    Normal();
                    cout<<lc[y];
                    gotoxy(1,y+2);
                    MauChon();
                    cout<<lc[y+2];
                   	Normal ();
                }
            }
            if(kk==13)
            {
            	int y = wherey();
            	if(y== 3)
            	{
            		string tenvtmoi="";
            		do{
					Normal();
            		system("cls");
            		gotoxy(2,3);
            		cout <<"NHAP TEN VAT TU MOI : ";
           			KhungNho(23,2);
           			gotoxy(0,5) ;
           			cout<<"*Ten VT khong bat dau bang khoang trang              "<<endl;
           			cout<<"*Gom cac ki tu (a-z), (A-Z)                     "<<endl;
           			cout<<"*Cac so (0-9)                                    "<<endl;
           			gotoxy(24,3);
           			getline(cin,tenvtmoi);
           			if(KiemTraChuoi(tenvtmoi)==0)
           				{
           					string s = "Ban da nhap sai quy tac nhap ten vat tu  ";
           					while(!kbhit())CanhBao(s,40,10);
					    }	
           			}
           			while(KiemTraChuoi(tenvtmoi)==0);
           			strcpy(p->Data.tenvt,tenvtmoi.c_str());
           			strupr(p->Data.tenvt);
           			string s = "Da chinh sua ten vat tu  ";
					while(!kbhit()) CanhBao(s,40,10);
					SaveVT(t);
					system("PAUSE");
            		break;	
				}
				if(y==5)
				{
					string dvtmoi="";
            		do{
					Normal();
            		system("cls");
            		gotoxy(2,3);
            		cout <<"NHAP DON VI TINH VAT TU MOI : ";
           			KhungNho(31,2);
           			gotoxy(0,5) ;
           			cout<<"*Don vi VT khong bat dau bang khoang trang              "<<endl;
           			cout<<"*Gom cac ki tu (a-z), (A-Z)                     "<<endl;
           			cout<<"*Cac so (0-9)                                    "<<endl;
           			gotoxy(32,3);
           			getline(cin,dvtmoi);
           			if(KiemTraChuoi(dvtmoi)==0)
           				{
           					string s = "Ban da nhap sai quy tac nhap don vi vat tu  ";
           					while(!kbhit())CanhBao(s,40,10);
					    }	
           			}
           			while(KiemTraChuoi(dvtmoi)==0);
           			strcpy(p->Data.dvt,dvtmoi.c_str());
           			strupr(p->Data.dvt);
           			string s = "Da chinh sua don vi vat tu ";
					while(!kbhit()) CanhBao(s,40,10);
					SaveVT(t);
					system("PAUSE");
            		break;		
				}
			
			}
			if(kk==27)
			{
				Normal();
				break;
			}
        
	}
	
}

int MenuHieuChinhVT()
{
		system("CLS");
	HD();
	KhungNho(30,1);
	cout<<" + HIEU CHINH VAT TU +"<<endl;
	if (TinhSoNode(t)==0)
    {
    	gotoxy(28,5);
        cout<<"Ban chua nhap vat tu nao ca!!!";  
        gotoxy(25,12);
    }
    	gotoxy(15,6);
	cout<<"Nhap vao ma vat tu can h/c: ";
	char c=179;
	string s;
	int x=wherex();
	int y=wherey();
	int check=0;
	int vitri=x;
	int xc,xk;
	while(check==0)
	{
        while (kbhit())
        {
            char k =getch();
            if (k==13)			//ENTER
            {
            	int flagE=0;
                if (KiemTraDoDaiMa(s)==0)
                {
                    string t="Ma vat tu phai co 5 ky tu. Xin hay nhap lai.";
                    while(!kbhit())
                    CanhBao(t,20,5);
                    do
                    {
                      char  c1= getch();
                    }
					while(k!=13);                
                }
                else
                {
                    if (KiemTraTrungMaVT(t,s)==0)
                    {
                        string t="Ma vat tu sai khong ton tai. Kiem tra lai ma";
                        while(!kbhit())
                        CanhBao(t,15,4);
                    	do
                    	{
                      	char  c1= getch();
                   		 }
							while(k!=13);
                    
                    }
                     
                    else
                    {
						HieuChinhVatTu(s);
						check = 1;
						return 1;
    	            }
    	        }
			}
			if(k==27)
			{
				check=1;
				return 1;
			}
            if (((k>=48&&c<=57) || (k>=97 && k<=122) || (k>=65 && k<=90))&&vitri<70)
            {
                gotoxy(vitri,y);
                if (k>=97 && k<=122) k = k-32;		//In chu hoa
                cout<<k;
                s.insert(s.end(),1,k);
                vitri++;
            }
            else if (k==8)
            {
                if (s.size()!=0)
                {
                    vitri--;
                    gotoxy(vitri,y);
                    cout <<" ";
                    gotoxy(vitri,y);
                    s.erase(s.end()-1);
                }
            }
        }
	}

    
}
void EscHieuChinhVT()
{
	int check =0;
	while(check == 0)
	{
		check = MenuHieuChinhVT();
	}
}




/*void DuyetCay(Tree t, VatTu A[], int &dem)
{
	
	NODE *p;
	while( t )
	{
		if( t->left == NULL ){
			A[dem]=t->Data;
			dem++;
			t = t->right;
		}
		else{
			p = t->left;
			while(p->right && p->right != t ){
				p = p->right;
			}
			if( p->right == NULL ){
				p->right = t;
				t = t->left;
			}
			else{
				p->right = NULL;
				A[dem]=t->Data;
				dem++;
				t = t->right;
			}
		}
	}
}*/
void DuyetCay(Tree root,VatTu A[],int &dem)
{
	const int STACKSIZE = 500;
	Tree Stack [STACKSIZE];
	int sp = -1;
	Tree p = root;
	while (p!=NULL)
	{
		A[dem]=p->Data;
		dem++;
		if(p->right!=NULL)
			Stack[++sp]=p->right;
		if(p->left!=NULL)
			p=p->left;
		else if(sp==-1)
		{
			break;
		}
		else p=Stack[sp--];
	}
}
void SapXepTheoTenVT(VatTu A[])
{
	int i,j;
	int n =TinhSoNode(t);
	VatTu t;
	 for ( i = 1; i < n; i++)
	  {
      	for (j = 1; j < n; j++)
		   {
         	if (strcmp(A[j - 1].tenvt, A[j].tenvt) > 0)
			  {
           		t = A[j - 1];
           		A[j - 1] = A[j];
            	A[j] = t;
         	  }
      	   }
     }
}


void DanhSachVT(VatTu A[])//Duyet de in vat tu
{
	int n = TinhSoNode(t);
	for(int i = 0 ; i < n ; i++)
	{
	cout << (char)179<<setw(21)<< A[i].mavt << (char)179<<setw(21)<<A[i].tenvt << (char)179 <<setw(21) << A[i].dvt << (char)179<<setw(21)<<A[i].sl <<(char)179<<endl;
	}
		
}


void InDanhSachVT()
{		
		int dem = 0;
		VatTu A[MAXVT];
		DuyetCay(t,A,dem);
		SapXepTheoTenVT(A);
		//gotoxy (25,0);
		HD();
		KhungNho(30,1);
		cout << " + DANH SACH VAT TU + " <<endl;
		if(TinhSoNode(t)==0)
		{
			gotoxy(29,10); 
        	cout<<"Ban chua co vat tu nao !!!";	
		}
		else
		{
			gotoxy(0,5);
			cout << (char)218;
			for(int i = 0; i<= 20;i++) cout <<(char)196;
			cout<<(char)194;
			for(int i = 0; i<= 20;i++) cout <<(char)196;
			cout << (char)194;
			for(int i = 0; i<= 20;i++) cout <<(char)196;
			cout << (char)194;
			for(int i = 0; i<= 20;i++) cout <<(char)196;
			cout << (char)191<<endl;
			cout << (char)179<< "     MA  VAT TU      ";
			cout << (char)179<< "     TEN VAT TU      ";
			cout << (char)179<< "     DON VI TINH     ";
			cout << (char)179<< "     SO LUONG TON    "<<(char)179<<endl;
			cout << (char)195;
			for(int i = 0; i<= 20;i++) cout <<(char)196;
			cout << (char)197;
			for(int i = 0; i<= 20;i++) cout <<(char)196;
			cout << (char)197;
			for(int i = 0; i<= 20;i++) cout <<(char)196;
			cout << (char)197;
			for(int i = 0; i<= 20;i++) cout <<(char)196;
			cout << (char)180<<endl;
			DanhSachVT(A);
			cout<<(char)192;
			for(int i = 0; i<= 20;i++) cout <<(char)196;
			cout << (char)193;
			for(int i = 0; i<= 20;i++) cout <<(char)196;
			cout << (char) 193;
			for(int i = 0; i<= 20;i++) cout <<(char)196;
			cout << (char) 193;
			for(int i = 0; i<= 20;i++) cout <<(char)196;
			cout <<(char)217<<endl;
		}
	
	while(!kbhit())
	{
		char c =getch();
		if(c==27)
		{
			break;
		}
	}


}

Tree rp =NULL;
void RemoveCase3(Tree &r)
{
	if(r->left!=NULL)
	RemoveCase3(r->left);
	//den day r la nut cuc trai cua cay con ben phai co nut goc la rp
	else 
	{
		strcpy (rp->Data.mavt,r->Data.mavt);
		strcpy(	rp->Data.dvt,r->Data.dvt);
		rp->Data.sl=r->Data.sl;
		strcpy(	rp->Data.tenvt,r->Data.tenvt);
		rp=r;
		r=rp->right;
	}
}

void XoaVatTu(string x,Tree &p)
{
	
	if(strcmp(x.c_str(),p->Data.mavt)<0) XoaVatTu(x,p->left);
	else if(strcmp(x.c_str(),p->Data.mavt)>0) XoaVatTu(x,p->right);
	else 
	{
		rp=p;
		if(rp->right==NULL)p=rp->left;
		//p la nut la hoac la nut chi co cay con ben trai
		else if(rp->left==NULL)
		p=rp->right;//p la nut co cay con ben phai
		else RemoveCase3(rp->right);
		delete rp;
	}
	
}

int KiemTraVatTuNamTrongHD(string s)//Kiem tra xem vat tu co duoc lap hoa don khong
{
	HOADON *C = new HOADON;
	for(HOADON *C=first;C!=NULL;C=C->next)
    {
    	for (CT_HOADON *p = C->CT_next; p!=NULL; p = p->next)
    		{
    			if(strcmp(p->mavt,s.c_str())==0)
    			return 0;
			}  
	}
	return 1;
}
int MenuXoaVatTu()
{
   	system("CLS");
	HD();
	KhungNho(30,1);
	cout<<" + TAC VU XOA VAT TU +"<<endl;
	if (TinhSoNode(t)==0)
    {
    	gotoxy(28,5);
        cout<<"Ban chua nhap vat tu nao ca!!!";  
        gotoxy(25,12);
    }
    else
    {
    gotoxy(30,7);
	int dem=0;
	VatTu B[MAXVT];
	DuyetCay(t,B,dem);
	SapXepTheoTenVT(B);
			//gotoxy (25,0);
	cout << "DANH SACH VAT TU " <<endl;
	cout << (char)218;
	for(int i = 0; i<= 20;i++) cout <<(char)196;
	cout<<(char)194;
	for(int i = 0; i<= 20;i++) cout <<(char)196;
	cout << (char)194;
	for(int i = 0; i<= 20;i++) cout <<(char)196;
	cout << (char)194;
	for(int i = 0; i<= 20;i++) cout <<(char)196;
	cout << (char)191<<endl;
	cout << (char)179<< "     MA  VAT TU      ";
	cout << (char)179<< "     TEN VAT TU      ";
	cout << (char)179<< "     DON VI TINH     ";
	cout << (char)179<< "     SO LUONG TON    "<<(char)179<<endl;
	cout << (char)195;
	for(int i = 0; i<= 20;i++) cout <<(char)196;
	cout << (char)197;
	for(int i = 0; i<= 20;i++) cout <<(char)196;
	cout << (char)197;
	for(int i = 0; i<= 20;i++) cout <<(char)196;
	cout << (char)197;
	for(int i = 0; i<= 20;i++) cout <<(char)196;
	cout << (char)180<<endl;
	DanhSachVT(B);
	cout<<(char)192;
	for(int i = 0; i<= 20;i++) cout <<(char)196;
	cout << (char)193;
	for(int i = 0; i<= 20;i++) cout <<(char)196;
	cout << (char) 193;
	for(int i = 0; i<= 20;i++) cout <<(char)196;
	cout << (char) 193;
	for(int i = 0; i<= 20;i++) cout <<(char)196;
	cout <<(char)217 <<endl;
	}
	gotoxy(15,6);
	cout<<"Nhap vao ma vat tu can xoa: ";
	char c=179;
	string s;
	int x=wherex();
	int y=wherey();
	int check=0;
	int vitri=x;
	int xc,xk;
	while(check==0)
	{
        while (kbhit())
        {
            char k =getch();
            if (k==13)			//ENTER
            {
            	int flagE=0;
                if (KiemTraDoDaiMa(s)==0)
                {
                    string t="Ma vat tu phai co 5 ky tu. Xin hay nhap lai.";
                    while(!kbhit())
                    CanhBao(t,20,5);
                    do
                    {
                      char  c1= getch();
                    }
					while(k!=13);                
                }
                else
                {
                    if (KiemTraTrungMaVT(t,s)==0)
                    {
                        string t="Ma vat tu sai khong ton tai. Kiem tra lai ma";
                        while(!kbhit())
                        CanhBao(t,15,4);
                    	do
                    	{
                      	char  c1= getch();
                   		 }
							while(k!=13);
                    
                    }
                     if( KiemTraVatTuNamTrongHD(s)==0)
                    {
                    	string t="Ma vat tu da duoc lap hoa don                  ";
                        while(!kbhit())
                        CanhBao(t,15,4);
                    	do
                    	{
                      	char  c1= getch();
                   		 }
							while(k!=13);
					}
                    else
                    {
						XoaVatTu(s,t);
						system("cls");
						HD();
						KhungNho(30,1);
						cout<<" + TAC VU XOA NHAN VIEN +"<<endl;
						gotoxy(30,7);
							int dem=0;
						VatTu B[MAXVT];
						DuyetCay(t,B,dem);
						SapXepTheoTenVT(B);
						//gotoxy (25,0);
						cout << "DANH SACH VAT TU " <<endl;
						cout << (char)218;
						for(int i = 0; i<= 20;i++) cout <<(char)196;
						cout<<(char)194;
						for(int i = 0; i<= 20;i++) cout <<(char)196;
						cout << (char)194;
						for(int i = 0; i<= 20;i++) cout <<(char)196;
						cout << (char)194;
						for(int i = 0; i<= 20;i++) cout <<(char)196;
						cout << (char)191<<endl;
						cout << (char)179<< "     MA  VAT TU      ";
						cout << (char)179<< "     TEN VAT TU      ";
						cout << (char)179<< "     DON VI TINH     ";
						cout << (char)179<< "     SO LUONG TON    "<<(char)179<<endl;
						cout << (char)195;
						for(int i = 0; i<= 20;i++) cout <<(char)196;
						cout << (char)197;
						for(int i = 0; i<= 20;i++) cout <<(char)196;
						cout << (char)197;
						for(int i = 0; i<= 20;i++) cout <<(char)196;
						cout << (char)197;
						for(int i = 0; i<= 20;i++) cout <<(char)196;
						cout << (char)180<<endl;
						DanhSachVT(B);
						cout<<(char)192;
						for(int i = 0; i<= 20;i++) cout <<(char)196;
						cout << (char)193;
						for(int i = 0; i<= 20;i++) cout <<(char)196;
						cout << (char) 193;
						for(int i = 0; i<= 20;i++) cout <<(char)196;
						cout << (char) 193;
						for(int i = 0; i<= 20;i++) cout <<(char)196;
						cout <<(char)217 <<endl;
						cout<<"                                                               ";
						gotoxy(20,20);						
						cout<<"Xoa thanh cong ! Ban co muon tiep tuc xoa ?(";
						xc=wherex();
						cout<<"Co/";
						xk=wherex();
						cout<<"Khong)";
						gotoxy(xc,wherey());
						cout<<"Co";
						int flagE=0;
						while(1)
						{
							while(!kbhit())	Sleep(100);
							char kk=getch();
							if(kk==-32)
							{
								char cc=getch();
								if(cc==77 && flagE==0)
								{
									gotoxy(xc,wherey());
									cout<<"Co";
									gotoxy(xk,wherey());
									cout<<"Khong";
									flagE=1;
								}
								if(cc==75 && flagE==1)
								{
									gotoxy(xk,wherey());
									cout<<"Khong";
									gotoxy(xc,wherey());
									cout<<"Co";
									flagE=0;
								}
							}
							if(kk==13)
							{
								if(flagE==1)
								{
									check=1;
									return 1;
								}
								if(flagE==0)
								{
									
									XoaManHinh();				
									return 0;
								}
							}
        	            }
    	            }
    	        }
			}
			if(k==27)
			{
				check=1;
				return 1;
			}
            if (((k>=48&&c<=57) || (k>=97 && k<=122) || (k>=65 && k<=90))&&vitri<70)
            {
                gotoxy(vitri,y);
                if (k>=97 && k<=122) k = k-32;		//In chu hoa
                cout<<k;
                s.insert(s.end(),1,k);
                vitri++;
            }
            else if (k==8)
            {
                if (s.size()!=0)
                {
                    vitri--;
                    gotoxy(vitri,y);
                    cout <<" ";
                    gotoxy(vitri,y);
                    s.erase(s.end()-1);
                }
            }
        }
	}
}
void EscXoaVT()
{
	int check = 0;
	while(check ==0)
	{
		check = MenuXoaVatTu();
	}
}


void KhoiTaoMenuVT()
{
  
	gotoxy(0,0);
    gotoxy(1,1);
    gotoxy(37,1);   
    cout<<"MENU VAT TU";
    KhungNho(30,3);
    KhungNho(30,6);
    KhungNho(30,9);
    KhungNho(30,12);
    KhungNho(30,15);
   
    gotoxy(31,4);
    cout<<"1. Nhap vat tu.            ";
    gotoxy(31,7);
    cout<<"2. Hieu chinh vat tu.      ";
    gotoxy(31,10);
    cout<<"3. Xoa vat tu.             ";
    gotoxy(31,13);
    cout<<"4. Danh sach VT trong kho. ";
    gotoxy(31,16);
    cout<<"5. Save vat tu.            "; 
  

}

int MenuVT()
{   
    system("CLS");
    int check =0;
    KhoiTaoMenuVT();//tao menu vat tu
    string lt[23];
    lt[4]  = "1. Nhap vat tu.            ";
    lt[7]  = "2. Hieu chinh vat tu.      ";
    lt[10] = "3. Xoa vat tu.             ";
    lt[13] = "4. Danh sach VT trong kho. ";
    lt[16] = "5. Save vat tu.            ";
    
    HD();
    gotoxy(31,4);
    MauChon();
    cout<<lt[4];//chon cai thu nhat
    while(check == 0)
    {
    	char kk = getch();
    	if (kk == 72)//phim di chuyen len
           	{
                int y = wherey();
                if (y == 4) //neu dang o hang dau ma nhan phim len thi di chuyen xuong hang cuoi cung
               	 {
                    gotoxy(31,y);
                    Normal ();
                    cout<<lt[4];
                    gotoxy(31,16);
                    MauChon();
                    cout<<lt[16];
                   	Normal ();
                }
                else//moi lan chay qua nhay 3 hang
                {
                    gotoxy(31,y);
                    Normal ();
                    cout<<lt[y];
                    gotoxy(31,y-3);
                    MauChon();
                    cout<<lt[y-3];
                   	Normal ();
                }
            }
        else if (kk==80)
            {
                int y = wherey();
                if (y == 16) //neu o hang cuoi ma di chuyen xuong thi dua con tro ve hang dau
                {
                    gotoxy(31,16);
                    Normal ();
                    cout<<lt[16];
                    gotoxy(31,4);
                    MauChon();
                    cout<<lt[4];
                   	Normal ();
                }
                else
                {
                    gotoxy(31,y);
                    Normal();
                    cout<<lt[y];
                    gotoxy(31,y+3);
                    MauChon();
                    cout<<lt[y+3];
                   	Normal ();
                }
            }
         else   if(kk==13)
            {
            	  int y = wherey();
            	  if(y==4)
            	  {
            	 	Normal ();
            	  	system("cls");
            	 	EscNhapVatTuMoi();
            		return 0;
				  }
				  if(y==7)
				  {
				  	Normal();
				  
				  	system("cls");
				  	EscHieuChinhVT();
					return 0;
				  }
				  if(y==10)
				  {
				  	
				  	Normal();
				  
				  	system("cls");
				  	EscXoaVT();
					return 0;
				  }
				  if(y==13)
				  {
				  	
				  	Normal();
				  	system("cls");
				 	InDanhSachVT();
					return 0;
				  }
				  if(y==16)
				  {
				  	
					Normal();
				  	SaveVT(t);
				  	system("cls");
				  	HD();
				  	string s="Da save file";
				  	CanhBao(s,30,10);
				  	system("PAUSE");
				  	return 0;
				  }
				  
			}
		else if(kk==27)
		{
			
			return 1;
					
		}      
	}
}
void EscVT()
{
	int check =0;
	while(check == 0)
	{
	check = MenuVT();	
	}
}
 // NHAN VIEN
 void HuongDanNhapNV()
{
	char c=179;
    KhungNho(30,1);
    cout<<"  + TAC VU NHAP NHAN VIEN +"<<endl;
    HD();
    gotoxy(10,9);
    cout<<endl;
    int cot1=10, cot2=21, cot3=41, cot4=51, cot5=61;//int cot1=35, cot2=46, cot3=66, cot4=76, cot5=86;11.20.10.10
    int y = wherey()+2;
    gotoxy(cot1,y-1);
    for(int i=1;i<51;i++)
    {
    	if(i==11 || i==31 || i==41)
    	    cout<<char(194);
    	    else if(i==1)
                cout<<char(218);
            else if(i==50)
                cout<<char(191);
        else
    		cout<<char(196);
	}
    gotoxy(cot1,y);
    cout<<char(179)<<"   MA NV";
    gotoxy(cot2-1,y);
    cout<<c;
    gotoxy(cot2,y);
    cout<<"\t   HO";
    gotoxy(cot3-1,y);
    cout<<c;
    gotoxy(cot3,y);
    cout<<"   TEN";
    gotoxy(cot4-1,y);
    cout<<c;
    gotoxy(cot4,y);
    cout<<"   PHAI "<<char(179);
    cout<<endl;
    gotoxy(cot1,wherey());
    for(int i=1;i<51;i++)
    {
    	if(i==11 || i==31 || i==41)
    		cout<<char(197);
    		else if(i==1)
                cout<<char(195);
            else if(i==50)
                cout<<char(180);
    	else
    		cout<<char(196);
    }
    cout<<endl;
    gotoxy(cot1,wherey());
}
void NhapNhanVien()
{
    system("CLS");  
    char c;
    HuongDanNhapNV();  
     if (SLNV==MAXNV)
    {
    	string t="Khong the nhap them nhan vien !";
    	CanhBao(t,15,10);
    	gotoxy(15,12);
    	system("Pause");
    	return;
    }
    int i = SLNV;
    NVien[i] = new NhanVien;
    NVien[i]->MANV="";
    NVien[i]->HO="";
    NVien[i]->TEN="";
    NVien[i]->PHAI="";
    int vitri;
    int cot1=10, cot2=21, cot3=41, cot4=51, cot5=61;
    char k=179;
    int y=wherey();
    gotoxy(cot1+1,y);
    int flag=1;
    int check=0;
    int hs = wherey();
    while(check==0)
    {
    	while(kbhit())
    	{
            gotoxy(cot1,y);
            cout<<k;
            if (flag == 1)
            {
            vitri = cot1 + NVien[i]->MANV.size();//vi tri con con tro  nam o cuoi cung cua chuoi
            gotoxy(23,4);
            cout<<"                                  ";
            gotoxy(23,4);
            cout<<char(26)<<"Ma Nhan Vien phai co 5 chu so";
            gotoxy(23,5);
            cout<<char(26)<<"Gom cac ki tu  (A-Z)";
            gotoxy(23,6);
            cout<<char(26)<<"Cac so (0-9)";     
            gotoxy(vitri,y);
            }
            else if (flag == 2)
                 {
           			 vitri = cot2 + NVien[i]->HO.size();
           			 gotoxy(23,4);
          			 cout<<"                                            ";
          			 gotoxy(23,4);
           		     cout<<char(26)<<"Khong duoc bat dau bang khoang trang ";
          	     	  gotoxy(23,5);
          			  cout<<char(26)<<"Gom cac ki tu  (A-Z)                ";
          			  gotoxy(23,6);
          			  cout<<char(26)<<"Cac so (0-9)";	  
          			  gotoxy(vitri,y);
               }
            else if (flag ==3)

            {
          	  vitri = cot3 + NVien[i]->TEN.size();//vi tri con con tro  nam o cuoi cung cua chuoi
          	 
          	  gotoxy(23,4);
          	  cout<<"                                                         ";
          	  gotoxy(23,4);
	          gotoxy(23,5);
          	  cout<<char(26)<<"Gom cac ki tu  (A-Z)                            ";
         	   gotoxy(23,6); 
         	   cout<<char(26)<<"Cac so (0-9)                                     ";	  
          	  gotoxy(vitri,y);
            }
            else if(flag ==4)

            	   {
         			   vitri = cot4 + NVien[i]->PHAI.size();  			   
         			   gotoxy(23,4);
         			   cout<<"                                                     ";
         			   gotoxy(23,4);
         			   cout<<char(26)<<"Chi duoc nhap \"NAM\" hoac \"NU\"           ";
         			   gotoxy(23,5);
          			  cout<<char(26)<<"Gom cac ki tu  (A-Z)";
          			 
          			  gotoxy(vitri,y);
       				}		
            gotoxy(cot1+1,y);
            char c=getch();
            if(c==27)		//ESC
            {
            	check=1;
            	break;
            }
            else if(c==13 || c==9)		//Enter hoac Tab
            {
            	if(flag==1)
            	{
            		if(KiemTraTrungMaNV(i)==0) //Kiem tra trung ma nhan vien
            		{
            			gotoxy(cot1+1,y);			
            			cout<<NVien[i]->MANV;
            			while(!kbhit())
                        CanhBao("ban da nhap trung ma nhan vien.vui long nhap lai !!!",20,10);
                       do
                       {
                           char  c1= getch();
                       }
					   while(c!=13&&c!=27);
                       gotoxy(vitri,y);
                     
            		}
        	   		else if (KiemTraDoDaiMa(NVien[i]->MANV)==0)
                    {
                    	gotoxy(cot1+1,y);
            			cout<<NVien[i]->MANV;
            			CanhBao("Ma nhan vien phai co 5 chu so. Xin hay nhap lai!!!",20,10);
                        do
                        {
                            char  c1= getch();
                        }
						while(c!=13&&c!=27);
                        gotoxy(vitri,y);
                       
                    }
        	   		else
        	   		{
        	   			
        	   			gotoxy(13,10);
        	   			cout<<"                                              ";
        	   			gotoxy(cot1+1,y);
        	   			cout<<NVien[i]->MANV;
        	   			gotoxy(cot2-1,y);
        	   			cout<<k;
        	   			flag=2;
        	   		}
            	}
            	else if(flag==2)
            	{
            		if(KiemTraChuoi(NVien[i]->HO)==false)
            		{

            			gotoxy(cot2,y);
            		
            			cout<<NVien[i]->HO;
            			CanhBao("Ban da nhap sai ho. Xin vui long nhap lai.!!!",20,10);
                        do
                        {
                            char  c1= getch();
                        }
						while(c!=13&&c!=27);
                        gotoxy(vitri,y);
                        
            		}
            		else
            		{
            			gotoxy(13,10);
            			gotoxy(cot2,y);
            			cout<<NVien[i]->HO;
            			gotoxy(cot3-1,y);
            			cout<<k;
            			flag=3;
            		}
            	}
            	else if(flag==3)
            	{
            		if(KiemTraChuoi(NVien[i]->TEN)==0)
            		{
            			gotoxy(cot3,y);
            		
            			cout<<NVien[i]->TEN;
            			CanhBao("Ban da nhap sai ten. Xin vui long nhap lai.!!!",35,10);
                        do
                        {
                           char  c1= getch();
                        }
						while(c!=13&&c!=27);
                        gotoxy(vitri,y);
                        
            		}
            		else
            		{
            			
            			gotoxy(cot3,y);
            			cout<<NVien[i]->TEN;
            			gotoxy(cot4-1,y);
            			cout<<k;
            			flag=4;
            		}
            	}
            	else if(flag==4)
            	{
            		if(NVien[i]->PHAI!= "NAM" && NVien[i]->PHAI!="NU")
            		{
            			gotoxy(cot4,y);
            		
            			cout<<NVien[i]->PHAI;
            			CanhBao("Ban da nhap sai phai. Xin vui long nhap lai.!!!",35,10);
                        do
                        {
                           char  c1= getch();
                        }
						while(c!=13&&c!=27);
                        gotoxy(vitri,y);
                        
            		}
            		else
            		{
            			
            			gotoxy(cot4,y);
            			cout<<NVien[i]->PHAI;
            			gotoxy(cot4+8,y);
            			cout<<char(179);
            			flag=1;
            			gotoxy(cot1+1,y+1);
            			i++;
            			SLNV++;
            			NVien[i] = new NhanVien;
            			y=wherey();
            		
            		}
            	}
            }
            else if ((c>=48&&c<=57) || (c>=97 && c<=122) || (c>=65 && c<=90)|| (c==32))
            {
            	if(flag==1 && vitri < 15 && c!=32)
            	{
            		gotoxy(vitri+1,y);
            		if (c>=97 && c<=122) c=c-32;
            		cout<<c;
            		NVien[i]->MANV.insert(NVien[i]->MANV.end(),1,c);
            		vitri++;
            	}
            	else if(flag==2 && vitri < 40)
            	{
            		gotoxy(vitri,y);
            		if (c>=97 && c<=122) c=c-32;
            		cout<<c;
            		NVien[i]->HO.insert(NVien[i]->HO.end(),1,c);
            		vitri++;
            	}
            	else if(flag==3 && vitri < 50)
            	{
            		gotoxy(vitri,y);
            		if (c>=97 && c<=122) c=c-32;
            		cout<<c;
            		NVien[i]->TEN.insert(NVien[i]->TEN.end(),1,c);
            		vitri++;
            	}
            	if(flag==4 && vitri < 57)
            	{
            		gotoxy(vitri,y);
            		if (c>=97 && c<=122) c=c-32;
            		cout<<c;
            		NVien[i]->PHAI.insert(NVien[i]->PHAI.end(),1,c);
            		vitri++;
            	}
            }
            else if(c==8)		//Backspace
            {
            	if(flag==1 && NVien[i]->MANV!="")
            	{
                    vitri--;
                    gotoxy(vitri+1,y);
                    cout << " ";
                    gotoxy(vitri+1,y);
                    NVien[i]->MANV.erase(NVien[i]->MANV.end()-1);
            	}
            	else if(flag==2 &&NVien[i]->HO!="")
            	{
            		vitri--;
            		gotoxy(vitri,y);
            		cout << " ";
            		gotoxy(vitri,y);
            		NVien[i]->HO.erase(NVien[i]->HO.end()-1);
           		}
           		else if(flag==3 && NVien[i]->TEN!="")
           		{
           			vitri--;
           			gotoxy(vitri,y);
           			cout<< " ";
           			gotoxy(vitri,y);
           			NVien[i]->TEN.erase(NVien[i]->TEN.end()-1);
           		}
           		else if(flag==4 && NVien[i]->PHAI!="")
           		{
           			vitri--;
           			gotoxy(vitri,y);
           			cout<< " ";
           			gotoxy(vitri,y);
           			NVien[i]->PHAI.erase(NVien[i]->PHAI.end()-1);
           		}
            }
			else if(c==-32)
			{
                c = getch();
                if (c==72)  //mui ten di len
                {
                    if (y>hs)
                    {
                        i=i-1; y = y - 1;
                        if (flag == 1)
                            gotoxy(cot1+NVien[i]->MANV.size(),y);
                        else if (flag == 2)
                            gotoxy(cot2+NVien[i]->HO.size(),y);
                        else if (flag == 3)
                            gotoxy(cot3+NVien[i]->TEN.size(),y);
                        else if (flag == 4)
                        	gotoxy(cot4+NVien[i]->PHAI.size(),y);
                    }
                }
                if (c==80) //mui ten di xuong
                {
                    i=i+1; y = y + 1;
                    if (flag == 1 && i<=SLNV)
                        gotoxy(cot1+NVien[i]->MANV.size(),y);
                    else if (flag == 2 && i<=SLNV)
                        gotoxy(cot2+NVien[i]->HO.size(),y);
                    else if (flag == 3 && i<=SLNV)
                        gotoxy(cot3+NVien[i]->TEN.size(),y);
                    else if (flag == 4 && i<=SLNV)
                    	gotoxy(cot4+NVien[i]->PHAI.size(),y);
                    else
                    {
                    	i--;y--;
                    }
                }
                if (c==75) //mui ten qua trai
                {
                    if (flag == 2)
                    {
                        flag=1;
                        gotoxy(cot1+NVien[i]->MANV.size(),y);
                    }
                    else if (flag == 3)
                    {
                        flag = 2;
                        gotoxy(cot2+NVien[i]->HO.size(),y);
                    }
                    else if (flag == 4)
                    {
                    	flag = 3;
                    	gotoxy(cot3+NVien[i]->TEN.size(),y);
                    }
               }
                if (c==77) //mui ten qa phai
                {
                    if (flag == 1 && NVien[i]->MANV!="")
                    {
                    	gotoxy(cot2-1,y);
                    	cout<<k;
                        flag = 2;
                        gotoxy(cot2+NVien[i]->HO.size(),y);
                    }
                    else if (flag == 2 && NVien[i]->HO!="")
                    {
                    	gotoxy(cot3-1,y);
                    	cout<<k;
                        flag = 3;
                        gotoxy(cot3+NVien[i]->TEN.size(),y);
                    }
                    else if (flag == 3 && NVien[i]->TEN!="")
                    {
                    	gotoxy(cot4-1,y);
                    	cout<<k;
                    	gotoxy(cot5-1,y);
                    	cout<<k;
                    	flag = 4;
                    	gotoxy(cot4+NVien[i]->PHAI.size(),y);
                    }
                }
			}
		}
	}
}

void SapXepNV()
{
	int i,j;
	 for ( i = 1 ; i < SLNV ; i++)
	  {
      	for (j = 1; j < SLNV ; j++)
		   {
         	if (NVien[j-1]->TEN.compare(NVien[j]->TEN)  > 0)
			  {
			  	NhanVien  *t;
           		t = NVien[j - 1];
           		NVien[j - 1] = NVien[j];
            	NVien[j] = t;
         	  }
         	  else if(NVien[j-1]->TEN.compare(NVien[j]->TEN) == 0)
         	  {
         	  	if(NVien[j-1]->HO.compare(NVien[j]->HO)>0)
         	  	{
         	  		NhanVien  *t;
           			t = NVien[j - 1];
           			NVien[j - 1] = NVien[j];
            		NVien[j] = t;
				}
			   }
       
      	   }
     }
}
void DS()
{
	SapXepNV();
	char c=179;
//	MauCB();
	int cot1=10, cot2=21, cot3=41, cot4=51, cot5=61;
	int y=wherey()+1;
	gotoxy(cot1,y-1);
	for(int i=1;i<51;i++)
    {
    	if(i==11 || i==31 || i==41)
    	    cout<<char(194);
    	    else if(i==1)
                cout<<char(218);
            else if(i==50)
                cout<<char(191);
        else
    		cout<<char(196);
	}
	gotoxy(cot1,y);
	cout<<char(179)<<"   MA NV";
	gotoxy(cot2-1,y);
	cout<<c<<"\t   HO";
	gotoxy(cot3-1,y);
	cout<<c<<"   TEN";
	gotoxy(cot4-1,y);
	cout<<c<<"   PHAI "<<char(179);
	cout<<endl;
	gotoxy(10,wherey());
	for(int i=1;i<51;i++)
	{
		if(i==11 || i==31|| i==41)
			cout<<char(197);
			else if(i==1)
                cout<<char(195);
            else if(i==50)
                cout<<char(180);
		else
			cout<<char(196);
	}
	cout<<endl;
	gotoxy(cot1,wherey());
	for(int i=0;i<SLNV;i++)
	{
		gotoxy(cot1,wherey());
		cout<<char(179);
		gotoxy(cot1+1,wherey());
		cout<<NVien[i]->MANV;
		gotoxy(cot2-1,wherey());
		cout<<c<<NVien[i]->HO;
		gotoxy(cot3-1,wherey());
		cout<<c<<NVien[i]->TEN;
		gotoxy(cot4-1,wherey());
		cout<<c<<"   "<<NVien[i]->PHAI;
		gotoxy(cot4+8,wherey());
		cout<<char(179);
		cout<<endl;
	}
	gotoxy(cot1,wherey());
	cout<<(char)192;
	for(int i = 0; i<= 8;i++) cout <<(char)196;
	cout << (char)193;
	for(int i = 0; i<= 18;i++) cout <<(char)196;
	cout << (char) 193;
	for(int i = 0; i<= 8;i++) cout <<(char)196;
	cout << (char) 193;
	for(int i = 0; i<= 7;i++) cout <<(char)196;
	cout <<(char)217<<endl;
	cout<<"                                                                     "<<endl;
	//SetColor(10);
	gotoxy(cot1,wherey());
	cout<<"So luong nhan vien: "<< SLNV<< endl;
}
void InDanhSachNV()
{	
	system("CLS");
	HD();
	KhungNho(30,1);
	cout<<"	+ DANH SACH NHAN VIEN +"<<endl;
	if (SLNV==0)
    {
    	gotoxy(32,10);
    
        cout<<"Ban chua nhap nhan vien nao !!!";
        
    }
    else
    {
        gotoxy(0,5);
        DS();
    }
    int check=0;
	while(check==0)
	{
		if(!kbhit())
		{
			char c=getch();
			if(c==27)
			{
				check=1;
				break;
			}
		}
		else check=0;
	}
}


int  TimKiemNhanVien(string manv)
{
	for(int i = 0 ; i < SLNV ; i++ )
	{
		if(NVien[i]->MANV==manv)
		return i;		
	}
	return -1;
}

void XoaNhanVien(int i)
{
	for(int a=i;a<SLNV-1;a++)
		NVien[a]=NVien[a+1];
	SLNV=SLNV-1;
}

int MenuXoaNhanVien()
{
   	system("CLS");
	HD();
	KhungNho(30,1);
	cout<<" + TAC VU XOA NHAN VIEN +"<<endl;
	if (SLNV==0)
    {
    	gotoxy(28,5);
        cout<<"Ban chua nhap nhan vien nao ca!!!";  
        gotoxy(25,12);
    }
	gotoxy(10,7);
	DS();
	gotoxy(15,6);
	cout<<"Nhap vao ma nhan vien can xoa: ";
	char c=179;
	string s;
	int x=wherex();
	int y=wherey();
	int check=0;
	int vitri=x;
	int xc,xk;
	while(check==0)
	{
        while (kbhit())
        {
            char k =getch();
            if (k==13)			//ENTER
            {
            	int flagE=0;
                if (KiemTraDoDaiMa(s)==0)
                {
                    string t="Ma Nhan Vien phai co 5 ky tu. Xin hay nhap lai.";
                    while(!kbhit())
                    CanhBao(t,20,5);
                    do
                    {
                      char  c1= getch();
                    }
					while(k!=13);                
                }
                else
                {
                    int i;
                    for (i=0; i<SLNV; i++)
                        if (NVien[i]->MANV == s) break;
                    if (i==SLNV)
                    {
                        string t="Ma nhan vien sai khong ton tai. Kiem tra lai ma";
                        while(!kbhit())
                        CanhBao(t,15,4);
                    	do
                    	{
                      	char  c1= getch();
                   		 }
							while(k!=13);
                    
                    }
                    else
                    {
						XoaNhanVien(i);
						system("cls");
						HD();
						KhungNho(30,1);
						cout<<" + TAC VU XOA NHAN VIEN +"<<endl;
						gotoxy(10,7);
						DS();
						cout<<"                                                               ";
						gotoxy(20,20);						
						cout<<"Xoa thanh cong ! Ban co muon tiep tuc xoa ?(";
						xc=wherex();
						cout<<"Co/";
						xk=wherex();
						cout<<"Khong)";
						gotoxy(xc,wherey());
					
						cout<<"Co";
						int flagE=0;
						while(1)
						{
							while(!kbhit())	Sleep(100);
							char kk=getch();
							if(kk==-32)
							{
								char cc=getch();
								if(cc==77 && flagE==0)
								{
									gotoxy(xc,wherey());
									cout<<"Co";
									gotoxy(xk,wherey());
									cout<<"Khong";
									flagE=1;
								}
								if(cc==75 && flagE==1)
								{
									gotoxy(xk,wherey());
									cout<<"Khong";
									gotoxy(xc,wherey());
									cout<<"Co";
									flagE=0;
								}
							}
							if(kk==13)
							{
								if(flagE==1)
								{
									check=1;
									return 1;
								}
								if(flagE==0)
								{
									
									XoaManHinh();	
									
									return 0;
								}
							}
        	            }
    	            }
    	        }
			}
			if(k==27)
			{
				check=1;
				return 1;
			}
            if ((k>=48&&c<=57) || (k>=97 && k<=122) || (k>=65 && k<=90))
            {
                gotoxy(vitri,y);
                if (k>=97 && k<=122) k = k-32;		//In chu hoa
                cout<<k;
                s.insert(s.end(),1,k);
                vitri++;
            }
            else if (k==8)
            {
                if (s.size()!=0)
                {
                    vitri--;
                    gotoxy(vitri,y);
                    cout <<" ";
                    gotoxy(vitri,y);
                    s.erase(s.end()-1);
                }
            }
        }
	}
}
void EscXoaNhanVien()
{
	int check = 0;
	while(check == 0)
	{
		check = MenuXoaNhanVien();
	}
}

void LoadNV()
{
	ifstream f("NHANVIEN.txt",ios::in);
		NVien[SLNV]=new NhanVien;
	if(!f.fail())
	while((getline(f,NVien[SLNV]->MANV))!=false)
	{
		fflush(stdin);	
		getline(f,NVien[SLNV]->HO);
		getline(f,NVien[SLNV]->TEN);
		getline(f,NVien[SLNV]->PHAI);
		int flag=0;
		for(int i=0;i<SLNV;i++)
			if(NVien[i]->MANV==NVien[SLNV]->MANV)
			{
				flag=1;
				break;
			}
		if(flag==0)
		{
			SLNV++;
			NVien[SLNV] = new NhanVien;
		}
			
	}
	f.close();
}
void SaveNV()
{
	ofstream a("NHANVIEN.txt",ios::out);
	for(int i=0;i<SLNV;i++)
		a<<NVien[i]->MANV<<endl<<NVien[i]->HO<<endl<<NVien[i]->TEN<<endl<<NVien[i]->PHAI<<endl;
	a.close();
}
void KhoiTaoMenuNV()
{
  
	gotoxy(0,0);
    gotoxy(1,1);
    gotoxy(35,1);   
    cout<<"MENU NHAN VIEN";
    KhungNho(30,3);
    KhungNho(30,6);
    KhungNho(30,9);
    KhungNho(30,12);


    gotoxy(31,4);
    cout<<"1. Nhap nhan vien          ";
    gotoxy(31,7);
    cout<<"2. Xoa Nhan Vien           ";
    gotoxy(31,10);
    cout<<"3. Danh Sach NV            ";
    gotoxy(31,13);
    cout<<"4. Save Nhan Vien          ";


}

int MenuNV()
{   
	Normal();
    system("CLS");
    int check =0;
    KhoiTaoMenuNV();//tao menu nhan vien
    string lt[14];
    lt[4]  = "1. Nhap nhan vien          ";
    lt[7]  = "2. Xoa Nhan Vien           ";
    lt[10] = "3. Danh Sach NV            ";
    lt[13] = "4. Save Nhan Vien          ";   
    HD();
    gotoxy(31,4);
    MauChon();
    cout<<lt[4];//chon cai thu nhat
    while(check == 0)
    {
    	char kk = getch();
    	if (kk == 72)//phim di chuyen len
           	{
                int y = wherey();
                if (y == 4) //neu dang o hang dau ma nhan phim len thi di chuyen xuong hang cuoi cung
               	 {
                    gotoxy(31,y);
                    Normal ();
                    cout<<lt[4];
                    gotoxy(31,13);
                    MauChon();
                    cout<<lt[13];
                   	Normal ();
                }
                else//moi lan chay qua nhay 3 hang
                {
                    gotoxy(31,y);
                    Normal ();
                    cout<<lt[y];
                    gotoxy(31,y-3);
                    MauChon();
                    cout<<lt[y-3];
                   	Normal ();
                }
            }
        else if (kk==80)
            {
                int y = wherey();
                if (y == 13) //neu o hang cuoi ma di chuyen xuong thi dua con tro ve hang dau
                {
                    gotoxy(31,13);
                    Normal ();
                    cout<<lt[13];
                    gotoxy(31,4);
                    MauChon();
                    cout<<lt[4];
                   	Normal ();
                }
                else
                {
                    gotoxy(31,y);
                    Normal();
                    cout<<lt[y];
                    gotoxy(31,y+3);
                    MauChon();
                    cout<<lt[y+3];
                   	Normal ();
                }
            }
         else   if(kk==13)
            {
            	  int y = wherey();
            	  if(y==4)
            	  {
            	  	Normal();
            		NhapNhanVien();
            		return 0;
				  }
				  if(y==7)
				  {
				 	Normal();
				 	EscXoaNhanVien();
					return 0;
				  }
				  if(y==10)
				  {
				  	Normal();
					InDanhSachNV();
					return 0;
				  }
				  if(y==13)
				  {
				  	Normal();
				  	SaveNV();	
				  	system("cls");
				  	HD();
				  	string s="Da save file";
				  	CanhBao(s,30,10);
				  	system("PAUSE");
				  	return 0;
				  	
				  
				
				  }
				 
			
			}
		else if(kk==27)
		{
			
			return 1;
					
		}      
	}
}
void EscNV()
{
	int check =0;
	while(check == 0)
	{
	check = MenuNV();	
	}
}
//HOA DON
int KiemTraTrungSHD(string a)
{
	char s[20];
	strcpy(s, a.c_str() );
	for(HOADON *p=first; p!=NULL;p=p->next)
	{
		if(strcmp(s, p->SoHD)==0) return 0;
	}
	return 1;
}
int KiemTraTrungMANV(string a)
{
	for (int i=0 ; i < SLNV; i++)
	{
		if(a.compare(NVien[i]->MANV)==0) return 0;
	}
	return 1;
}
int KiemTraThoiGianNhap(int ngay,int thang,int nam)
{
	if(nam<=0)
	{
		return 0;
	}
	else if(thang <= 0 || thang > 12)
	{
		return 0;
	}
	else if(ngay<=0||ngay>31)
	{
		return 0;
	}
	switch(thang){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if(ngay <=0 || ngay > 31)
			 {
				return 0;
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if(ngay <= 0 || ngay > 30) 
			{
				return 0;
			}
			break;
		case 2:
			if((nam % 4 == 0 && (ngay <= 0 || ngay > 29)) || (nam % 4 != 0 && (ngay <= 0 || ngay > 28)))
			 {
				return 0;
			}
			break;	
	}
	
	return 1;
}

void SaveHD()
{
    SaveVT(t);
	ofstream a ("HOADON.txt",ios::out);
	HOADON *b ;
	for(b=first;b!=NULL;b=b->next)
	{
		a<<"HD"<<endl;
		a<<b->SoHD<<" "<<b->MANV<<" "<<b->Ngay.NGAY<<" "<<b->Ngay.THANG<<" "<<b->Ngay.NAM<<" "<<b->loai<<endl;
        CT_HOADON *c;
        for (c = b->CT_next; c !=NULL; c = c->next)
    	{
	        a<<"VT"<<endl;
            a<<c->mavt<<" "<<c->soluong<<" "<<c->dongia<<" "<<c->VAT <<endl;
        }
        a<<"break"<<endl;
	}
	a.close();
}

void LoadHD()
{
    LoadVT(t);
    LoadNV();
	ifstream a ("HOADON.txt",ios::in);
	string f;
	if(!a.fail())
	while((a>>f)!=NULL)
	{
		if(f=="HD")
		{
			CT_HOADON *FirstT=NULL;
			HOADON *b=new HOADON;
			a>>b->SoHD>>b->MANV>>b->Ngay.NGAY>>b->Ngay.THANG>>b->Ngay.NAM>>b->loai;
			a>>f;
			while(f=="VT")
			{
				CT_HOADON *TAM=new CT_HOADON;
				a>>TAM->mavt>>TAM->soluong>>TAM->dongia>>TAM->VAT;
				TAM->next=FirstT;
				FirstT=TAM;
				a>>f;
			}
			int flag=0;
			HOADON *CHECK;
			for(CHECK=first;CHECK!=NULL;CHECK=CHECK->next)
				if(CHECK->SoHD==b->SoHD)
				{
					flag=1;
					break;
				}
			if(flag==0)
			{
				b->CT_next=FirstT;
				b->next=first;
				first=b;
			}
		}
	}
	a.close();
}
void InsertChiTietNhapXuat(CT_HOADON *&First, string MaVT, long dongia, int soluong,float vat)//them vat tu vao ct hoa don
{
    CT_HOADON *q = new CT_HOADON;
    strcpy(q->mavt, MaVT.c_str());
    q->soluong = soluong;
    q->dongia=dongia;
    q->VAT=vat;
    q->next = First;
    First = q;
}
void InsertHoaDon(HOADON *&first, string MSHD, string MaNV, Date NGAY, char LOAI,CT_HOADON *&First)
{	
    HOADON *q = new HOADON;
    strcpy(q ->SoHD, MSHD.c_str());
    q ->loai = LOAI;
    q ->MANV = MaNV ;
    q ->Ngay = NGAY;
    q ->CT_next = First;
    q ->next = first;
    first = q;
    SaveHD();
			
}
void InHuongDanNhapCTHD()
{
    char l = 179;
    int y = wherey()+2;
    int cot1=1, cot2=5, cot3=13, cot4=26, cot5=34, cot6=45, cot7=55, cot8=65;
    gotoxy(cot1-1,y-1);
    for(int i=1;i<65;i++)
    {
    			if(i==5 || i==13 || i==26 || i==34 || i==45||i==54)
                    cout<<char(194);
                else    if(i==1)
                    cout<<char(218);
              else  if(i==64)
                    cout<<char(191);
    	else
    		cout<<char(196);
    }
    gotoxy(cot1-1,y);
    cout<<l;
    gotoxy(cot1,y);
    cout<<"STT";
    gotoxy(cot2-1,y);
    cout<<l;
    gotoxy(cot2,y);
    cout<<" MA VT";
    gotoxy(cot3-1,y);
    cout<<l;
    gotoxy(cot3,y);
    cout<<"   TEN VT";
    gotoxy(cot4-1,y);
    cout<<l;
    gotoxy(cot4,y);
    cout<<"  DVT" ;
    gotoxy(cot5-1,y);
    cout<<l;
    gotoxy(cot5,y);
    cout<<" SO LUONG";
    gotoxy(cot6-1,y);
    cout<<l;
    gotoxy(cot6,y);
    cout<<" DON GIA";
    gotoxy(cot7-2,y);
    cout<<l;
    gotoxy(cot7,y);
    cout<<"%VAT    "<<l;
    cout<<endl;
    gotoxy(cot1-1,y+1);
    for(int i=1;i<65;i++)
    {
    			if(i==5 || i==13 || i==26 || i==34 || i==45||i==54)
                    cout<<char(197);
                else    if(i==1)
                    cout<<char(195);
             else  if(i==64)
                    cout<<char(180);
    	else
    		cout<<char(196);
    }
    cout<<endl;
}
void NhapCTHoaDon(CT_HOADON *&F, int tinhieu)
{//tin hieu = 1 la nhap, tin hieu=0 la xuat
	cout << endl;
	InHuongDanNhapCTHD();
	string MaVT="";
	int soluong;
	long dongia;
    float vat;
    char l = 179;
    int y = wherey();
    int cot1=1, cot2=5, cot3=13, cot4=26, cot5=34, cot6=45, cot7=55, cot8 =65;
    int vitri;
    int flag = 1;
    int i=0;
 //   int j; //lay vi tri cua ma vat tu
 	int check = 0;
while(check ==0)
{
 	if(flag == 1)
	{
		i++;//dem so thu tu vat tu nhap vao
    	gotoxy(cot1-1,y);
        cout<<l;
        gotoxy(cot1+1,y);
        cout<<i;
		gotoxy(cot2-1,y);
    	cout<<l;
    	gotoxy(cot2,y);
        flag=2;
	}
	if(flag ==2 )
	{
			 
			gotoxy(cot2,y);
            while (!kbhit())
            {
                vitri = cot2 + MaVT.size();
               char c = getch();
               gotoxy(vitri, y);
                if (c==27)//ESC
                {
                	check == 1;
                	return;
                }
                else if (c==13 || c==9)
                {
                    if (KiemTraDoDaiMa(MaVT)==0) //ktra ma nhap co dung hay khong
                    {
                        string t="Do dai ma vat tu la 5 ky tu. Xin nhap lai!!!";
                        gotoxy(cot2,y);
                        cout<<MaVT;
                         while(!kbhit())
                        CanhBao(t,10,1);
                    do
                    {
                      char  c1= getch();
                    }
                    while(c!=13&&c!=27);
                    gotoxy(vitri,y);
                    }
                    else if (KiemTraTrungMaVT(t,MaVT)==0) //kiem tra vat tu co ton tai hay khong
                    {
                        string t="Ma vat tu nay khong ton tai. Xin nhap lai!!!";
                        gotoxy(cot2,y);
                        cout<<MaVT;
                         while(!kbhit())
                        CanhBao(t,10,1);
                    do
                    {
                      char  c1= getch();
                    }
                    while(c!=13&&c!=27);
                    gotoxy(vitri,y);

                    }
                    else if (KiemTraTrungMaVT(t,MaVT)==1)
                    {
                    	Tree p = TimKiem(t,MaVT);
                        gotoxy(cot2,y);
                        cout<<MaVT;
                        gotoxy(cot3-1,y);
                        cout<<l;
                        gotoxy(cot3,y);
                        cout<<p->Data.tenvt;
                        gotoxy(cot4-1,y);
                        cout<<l;
                        gotoxy(cot4,y);
                        cout<<p->Data.dvt;
                        flag = 5;
                        break;
                    }
                }
                else if ((c>=48&&c<=57) || (c>=97 && c<=122) || (c>=65 && c<=90))
                {
                   if(vitri<10)
                    {
                        gotoxy(vitri,y);
                        if (c>=97 && c<=122) c=c-32;
                        cout<<c;
                        MaVT.insert(MaVT.end(),1,c);
                        vitri++;
                    }
                }
                else if (c==8)//backspace
                {
                    if (MaVT.size()!=0)
                    {
                        vitri--;
                        gotoxy(vitri,y);
                        cout<<" ";
                        gotoxy(vitri,y);
                        MaVT.erase(MaVT.end()-1);
                    }
                }
            }
          
		
	}
	if(flag == 5)
	{
		gotoxy(cot5-1,y);
        cout<<l;
        string a="";
 tt:
        gotoxy(cot5,y);
        getline(cin,a);
        if(KiemTraNhapSoLuongTon(a)==1)
          {
            soluong=ChuyenThanhSo(a);
            gotoxy(cot6-1,y);
            cout<<l;
          }
        else
        {
           gotoxy(cot5,y);
           cout<<"            ";
           CanhBao("Ban da nhap sai so luong, ban nhap nhap lai!!!",15,1);
           getch();
            goto tt;
        }
            if (tinhieu == 1)
			{
				Tree p = TimKiem(t,MaVT);
				p->Data.sl=p->Data.sl+soluong;
				//nhap thi tang so luong vat tu co trong kho
			}
            else
            {
            	Tree p = TimKiem(t,MaVT);
                if (soluong <= p->Data.sl)
                {
                   p->Data.sl =p->Data.sl-soluong;
				   //giam so luong vat tu co trong kho
                 
                }
                else
                {
                    string t="So luong ban nhap lon hon so luong vat tu ton kho, ban hay nhap lai!!!";
                    CanhBao(t,2,1);
                    getch();
                    gotoxy(cot5,y);
                    cout<<"                ";
                    goto tt;
                }
            }
            flag=6;
	}
//	 flag=6;
       
        if(flag=6) // don gia
        {
        	   	    	gotoxy(cot6,y);
              		  string a;
 				ttdg:
       				 gotoxy(cot6,y);
       				getline(cin,a);
      				 if(KiemTraNhapSoLuongTon(a)==1)
         			 {
          				 dongia=ChuyenThanhSo(a);
          				 gotoxy(cot6+8,y);
            			 cout<<l;
            		
         				 }
     		 		  else
       				 {
         			  	gotoxy(cot6,y);
          			 	cout<<"             ";
          			 	CanhBao("Ban da nhap sai don gia, ban nhap nhap lai!!!",15,1);
          				 getch();
            			goto ttdg;
					}	
		
					
			flag=7;
		}
		if(flag ==7)
		{
       		  gotoxy(cot7,y);
       		if (tinhieu == 1)
        	{
        		  string a;
 				ttvat:
 					
       				 gotoxy(cot7,y);
       				 getline(cin,a);
      				 if(KiemTraNhapSoThapPhan(a)==1)
         			 {
          				 vat = atof(a.c_str());
          				 gotoxy(cot7+8,y);
            			 cout<<l;
            		
         				 }
     		 		  else
       				 {
         			  	gotoxy(cot7,y);
          			 	cout<<"             ";
          			    	CanhBao("Ban da nhap sai VAT, ban nhap nhap lai!!!",15,1);
          				 getch();
            			goto ttvat;
					}	
              	
            			
         		
			}
			else
			{
				HOADON *q;
                int dem=0;
                for (q = first; q!=NULL; q = q->next)//chay tu hoa don dau den hoa don cuoi
                    if (q->loai == 'N')
                    {
                        for (CT_HOADON *p = q->CT_next; p!=NULL; p = p->next)
							if (strcmp(p->mavt, MaVT.c_str())==0)
                            {
                                vat = p->VAT;
                                cout<<vat;// cout VAT cua vat tu
                                gotoxy(cot8-2,y);
                                cout<<l;
                                dem++;
                                break;
                            }
                            if(dem!=0) break;
                    }
			}
			flag=1;
            InsertChiTietNhapXuat(F,MaVT,dongia,soluong,vat);//them cac vat tu vao CT_HOADON
            y++; //tang so hang len.
            MaVT = "";//sao khi them thi gan lai MaVT="" de tiep tuc nhap vat tu moi
    		gotoxy(cot1,y);
		}
}

}

void HoaDonNhap(string MSHD)
{
	system("cls");
	HD();
	string MaNV="";
	Date Ngay = LayGioHeThong();
	CT_HOADON *First = NULL;
	gotoxy(25,0);
    cout<<"+ HOA DON NHAP +"<<endl;
    cout <<endl;
    cout << "                     TP HCM, ngay " << ChuyenNgayThanhChuoi(Ngay) <<endl;
    gotoxy(10,4);
    cout << "So Hoa Don : " << MSHD;
    gotoxy(40,4);
    cout << "Nhap Ma Nhan Vien : " ;
    int xNV = wherex();
  	gotoxy(xNV,4);
  	int check =0;
  	while(check ==0)
  	{
  		while(kbhit())
  		{
  			int vitri = xNV + MaNV.size();
  			gotoxy(vitri,4);
  			 char c = getch();
            if (c==27)
            {
            	check = 1;
               break;
            }
             else if ((c>=48&&c<=57) || (c>=97 && c<=122) || (c>=65 && c<=90))
            {
                    gotoxy(vitri,4);
                    if (c>=97 && c<=122) c = c-32;
                    cout<<c;
                    MaNV.insert(MaNV.end(),1,c);
                	vitri ++;
            }
            else if (c==13)
            {
            	if (KiemTraDoDaiMa(MaNV) == 0)
                    {
            
                        gotoxy(xNV,4);
                        cout<<MaNV;
                   		 while(!kbhit())
                        CanhBao("Do dai ma nhan vien la 5 ky tu. Xin nhap lai!!!",17,1);
                    	do
                    	{
                     		 char  c1= getch();
                   		 }while(c!=13&&c!=27);
                    	gotoxy(vitri,4);
                        
                    }
                    else if (KiemTraTrungMANV(MaNV)==1)
                    {
                       
                        gotoxy(xNV,4);
                        cout<<MaNV;
                   		 while(!kbhit())
                        CanhBao("Ma nhan vien khong ton tai. Xin nhap lai!!!",17,1);
                  	  do
                   	 {
                    	  char  c1= getch();
                   		 }while(c!=13&&c!=27);
                   		 gotoxy(vitri,4);
                        
                    }
                    else
                    {
                        gotoxy(xNV,4);
                        cout<<MaNV<<endl;
						int k =TimKiemNhanVien(MaNV);
						cout << "               Ho va ten nhan vien : " << NVien[k]->HO<<" " <<NVien[k]->TEN;
                      //  check=1;
                        int y1=wherey();
  					  	gotoxy(0,y1+1);
   						NhapCTHoaDon(First,1);
   						InsertHoaDon(first,MSHD,MaNV,Ngay,'N',First);
   						break;
                    }
                    
            	
			}
			else if ( c== 8 && MaNV.size()!=0)
			{
                    vitri--;
                    gotoxy(vitri,4);
                    cout<<" ";
                    gotoxy(vitri,4);
                    MaNV.erase(MaNV.end()-1);
			}
		  }
	  }

   
    
    
}
void HoaDonXuat(string MSHD)
{
	system("cls");
	HD();
	string MaNV="";
	Date Ngay = LayGioHeThong();
	CT_HOADON *First = NULL;
	gotoxy(25,0);
    cout<<"+ HOA DON XUAT +"<<endl;
    cout <<endl;
    cout << "                     TP HCM, ngay " << ChuyenNgayThanhChuoi(Ngay) <<endl;
    gotoxy(10,4);
    cout << "So Hoa Don : " << MSHD;
    gotoxy(40,4);
    cout << "Nhap Ma Nhan Vien : " ;
    int xNV = wherex();
  	gotoxy(xNV,4);
  	int check =0;
  	while(check ==0)
  	{
  		while(kbhit())
  		{
  			int vitri = xNV + MaNV.size();
  			gotoxy(vitri,4);
  			 char c = getch();
            if (c==27)
            {
            	check =1;
            	break;
            }
             else if ((c>=48&&c<=57) || (c>=97 && c<=122) || (c>=65 && c<=90))
            {
                    gotoxy(vitri,4);
                    if (c>=97 && c<=122) c = c-32;
                    cout<<c;
                    MaNV.insert(MaNV.end(),1,c);
                	vitri ++;
            }
            else if (c==13)
            {
            	if (KiemTraDoDaiMa(MaNV) == 0)
                    {
            
                        gotoxy(xNV,4);
                        cout<<MaNV;
                   		 while(!kbhit())
                        CanhBao("Do dai ma nhan vien la 5 ky tu. Xin nhap lai!!!",17,1);
                    	do
                    	{
                     		 char  c1= getch();
                   		 }while(c!=13&&c!=27);
                    	gotoxy(vitri,4);
                        
                    }
                    else if (KiemTraTrungMANV(MaNV)==1)
                    {
                       
                        gotoxy(xNV,4);
                        cout<<MaNV;
                   		 while(!kbhit())
                        CanhBao("Ma nhan vien khong ton tai. Xin nhap lai!!!",17,1);
                  	  do
                   	 {
                    	  char  c1= getch();
                   		 }while(c!=13&&c!=27);
                   		 gotoxy(vitri,4);
                        
                    }
                    else
                    {
                        gotoxy(xNV,4);
                        cout<<MaNV<<endl;
						int k =TimKiemNhanVien(MaNV);
						cout << "               Ho va ten nhan vien : " << NVien[k]->HO<<" " <<NVien[k]->TEN;
                        //check=1;
  	                  	int y1=wherey();
  					    gotoxy(0,y1+1);
   					    NhapCTHoaDon(First,0);
    					InsertHoaDon(first,MSHD,MaNV,Ngay,'X',First);
    					break ;
                    }
                    
            	
			}
			else if ( c== 8 && MaNV.size()!=0)
			{
                    vitri--;
                    gotoxy(vitri,4);
                    cout<<" ";
                    gotoxy(vitri,4);
                    MaNV.erase(MaNV.end()-1);
			}
		  }
	  }

}

void GiaoDienLapHoaDon()
{
		KhungNho(20,4);
		gotoxy(1,5);
		cout << "SO HOA DON      ";
		KhungNho(20,7);
		gotoxy(1,8);
		cout << "LOAI             ";
		cout <<endl;
}
void LapHoaDon()
{
	string MSHD="";
	string MaNV="";
	Date Ngay = LayGioHeThong();
 //  char Loai = 78;//78 la 'N'
    system("CLS");
 	 gotoxy(20,0);
    cout<<"     + LAP HOA DON +"<<endl;
    cout <<endl;
    cout << "                     TP HCM, ngay " << ChuyenNgayThanhChuoi(Ngay) <<endl;
   
    if (t==NULL)
    {
        string t="Hien trong kho khong co vat tu nao het!!!";
        CanhBao(t,20,10);
        gotoxy(20,12);
        system("Pause");
        return ;
       
    }
    if (SLNV==0)
    {
        string t="Hien cong ty chua co nhan vien nao het!!! ";
        CanhBao(t,20,10);
        gotoxy(20,12);
        system("Pause");
        return ;
        
    }
     GiaoDienLapHoaDon();
  	int dong1=5, dong2 =8;  //khai bao vi tri tung dong nhap
	int flag = 1;
	string f[3];
	f[1]="";//So hoa don
	f[2]="";//Hoa Don Nhap Hoac Xuat
/*	flag = 1: 
	flag = 2: 
*/	
	 int vitri1 = 22, vitri2 = 22;
 //	 int x = wherex();
  	 int y = wherey();
  	  HD();
	 gotoxy(vitri1,dong1);
	 int check = 0;
	
while(check==0)
{
    while(kbhit())
    {
        if(flag==1)
        {
            vitri1 = 22 + f[1].size();//vi tri  con tro nam o cuoi cung cua chuoi           
            gotoxy(5,15);
            cout<<"*So Hoa Don phai co 5 ky tu                                   ";
            gotoxy(5,16); 
            cout<<"*Gom cac ki tu (A-Z), Khong bat dau bang khoan trang   ";
            gotoxy(5,17);
            cout<<"*Cac so (0-9)                                                 ";
           	gotoxy(vitri1, dong1);
       }
       else if(flag==2)
       {
       		vitri2 = 22 + f[2].size();//vi tri con nam o cuoi cung cua chuoi
            gotoxy(5,15);
            cout<<"*Dien N neu la hoa don nhap, X neu la hoa don xuat             ";
            gotoxy(5,16);
            cout<<"*Gom cac ki tu N va X                                          ";
            gotoxy(5,17);
            cout<<"                                                               ";
            gotoxy(vitri2, dong2);
	   } 
	   //___________
	    char c = getch();
        if(c==27)//27 la phim esc thi thoat 
        {
			check = 1;
			break;
        }
        else if(c == 13) //Enter de nhan du lieu kiem tra
        {
        	if(flag == 1)
        	{
        		
        		  if(KiemTraTrungSHD(f[1])==0)
                {
                    string s = "So hoa don ban nhap bi trung. Xin hay nhap lai               " ;
                    gotoxy(22,dong1);
                    cout<<f[1];//to mau
                     while(!kbhit())
                        CanhBao(s,2,25);
                    do
                    {
                      char  c1= getch();
                    }while(c!=13&&c!=27);
                    gotoxy(vitri1,dong1);
                   
                }
                else if(KiemTraDoDaiMa(f[1])==0)
                {
                    string s ="So hoa don phai co 5 ky tu. Xin hay nhap lai             ";
                    gotoxy(22,dong1);                 
                    cout<<f[1];
                    while(!kbhit())
                        CanhBao(s,2,25);
                    do
                    {
                      char  c1= getch();
                    }while(c!=13&&c!=27);
                    gotoxy(vitri1,dong1);
                    
                }
              
                else
                {
                
                    gotoxy(22,dong1);
                    cout<<f[1];                 
                    gotoxy(vitri2,dong2);
                    flag=2;//qua phan kiem tra ten
                }
			}
			else if(flag == 2)
			{
				if(f[2].compare("N")!=0 && f[2].compare("X")!=0)
            		{
        
            			gotoxy(22,dong2);
            		
            			cout<<f[2];
            			CanhBao("Ban da nhap sai phai. Xin vui long nhap lai.!!!",2,25);
                        do
                        {
                           char  c1= getch();
                        }
						while(c!=13&&c!=27);
                        gotoxy(vitri2,dong2);
                        
            		}
               
               		 else 
                   {
                		if(f[2].compare("N")==0)
                		{
                			HoaDonNhap(f[1]);
                			
						}
                		if(f[2].compare("X")==0)
                		{
                			HoaDonXuat(f[1]);
                					
						}
                    }
			 }
				                
	    }
			
		else if((c>=48&&c<=57) || (c>=97 && c<=122) || (c>=65 && c<=90) || (c==32))//chi dc nhap so.chu thuong.chu hoa.khoang trang.
    	{
        	if (flag==1 && vitri1<40 && c!=32)//khong duoc nhap vao khoang trang
        	{
           		gotoxy(vitri1,dong1); //tang vi tri con tro nhap len,,de nhap ki tu tiep theo ko bi chong len
           		 if (c>=97 && c<=122) c = c-32; //chuyen tu ky tu thuong sang ky tu hoa
           		 cout<<c; //xuat ky tu vua nhap ra man hinh
           		 f[1].insert(f[1].end(),1,c);//chen ky tu vua nhap vao cuoi chuoi
           		 vitri1++; //tang vi tri cot xuat hien ky tu
       		 }
           else if (flag==2 && vitri2<40 /*&& c!=32*/)//khong duoc nhap vao khoang trang
            {
                gotoxy(vitri2,dong2);
                if (c>=97 && c<=122) c=c-32;
                cout<<c;
                f[2].insert(f[2].end(),1,c);
                vitri2++;
            }
           
          
    	}	
            else if(c==8) //phim backspace.phim xoa chu
            {
                if(flag==1 && f[1].size()!=0)
                {
                    vitri1--;
                    gotoxy(vitri1,dong1);
                    cout << " ";
                    gotoxy(vitri1,dong1);
                    f[1].erase(f[1].end()-1);//xoa tu vi tri cuoi cung
                   // c=getch();
                }
                else if(flag==2 && f[2].size()!=0)
                {
                    vitri2--;
                    gotoxy(vitri2,dong2);
                    cout << " ";
                    gotoxy(vitri2,dong2);
                    f[2].erase(f[2].end()-1);
                    //c=getch();
                }
               
            }      
			else if (c==-32) 
			{
				char kk =getch();
			
				
				 if (kk== 72) //mui ten di len 
           		 {
           
                        if (flag == 1 && f[3]!="" )
                        {
                        	  gotoxy(vitri2,dong2);
                           	  flag=2;
						}
					
                          
                        else if (flag == 2 && f[0]!="" )
                        {
                        	gotoxy(vitri1,dong1);
                            flag=1;
						}
                        	
           			 }
            	else if (kk==80) //mui ten di xuong
            	{
            /*	if (y = dong1) flag =1;
			    if (y = dong2) flag =2;
				 if (y = dong3) flag =3;
				  if (y = dong4) flag =4;  */
                   // i=i+1; y = y+1;
                    if (flag == 1 && f[1]!="" ) //&& i<=ds.n)
                    {
                    	gotoxy(vitri2,dong2);
                        flag=2;
					}
                        
                    else if (flag == 2 &&f[2]!="" )//&& i<=ds.n)
                    {
                    	 gotoxy(vitri1,dong1);
                        flag=1;
					}
                       
                              
              	}
              	
            }
					
	}
}

}


void InChiTietHD(HOADON *F)//in ra hoa don can tim
{
	int tab=15,i;
	int stt=0;
	char  l=179;
    int cot1=1, cot2=5, cot3=16, cot4=37, cot5=48, cot6=59, cot7=69, cot8 = 79;
	cout<<"Thong tin hoa don:"<<endl<<endl;
	cout<<"So hop dong:";
	gotoxy(tab,wherey());
	cout<<F->SoHD<<endl;
	cout<<"Loai hop dong:";
	gotoxy(tab,wherey());
	if(F->loai=='N')
		cout<<"Nhap"<<endl;
	else if(F->loai='X')
		cout<<"Xuat"<<endl;
	cout<<"Ma nhan vien:";
	gotoxy(tab,wherey());
	cout<<F->MANV<<endl;
	cout<<"Ngay "<<F->Ngay.NGAY<<" thang "<<F->Ngay.THANG<<" nam "<<F->Ngay.NAM<<endl<<endl;
	cout<<"Danh sach cac vat tu trong hoa don"<<endl<<endl<<endl;
	gotoxy(cot1-1,wherey());
	cout<<l<<"STT";
	gotoxy(cot2-1,wherey());
	cout<<l<<" Ma VT";
	gotoxy(cot3-1,wherey());
	cout<<l<<"     Ten VT";
	gotoxy(cot4-1,wherey());
	cout<<l<<" So luong";
	gotoxy(cot5-1,wherey());
	cout<<l<<" Don gia";
	gotoxy(cot6-1,wherey());
	cout<<l<<"  DVT  ";
	gotoxy(cot7-1,wherey());
	cout<<l<<"VAT    "<<l<<endl;
	gotoxy(0,wherey()-2);
	  for(int i=1;i<78;i++)
    {
    			if(i==5 || i==16 || i==37 || i==48 || i==59 ||i==69)
                    cout<<char(194);
                else    if(i==1)
                    cout<<char(218);
              else  if(i==77)
                    cout<<char(191);
    	else
    		cout<<char(196);
    }
    gotoxy(0,wherey()+2);
    for(int i=1;i<78;i++)
	{
		if(i==5 || i==16 || i==37 || i==48 || i==59||i==69)
			cout<<char(197);
			else if(i==1)
                cout<<char(195);
            else if(i==77)
                cout<<char(180);
        else
			cout<<char(196);
	}
	cout<<endl;
	CT_HOADON *C;
	for(C=F->CT_next; C!=NULL; C=C->next)
	{
	    gotoxy(0,wherey());
	    cout<<l;
		stt++;
		cout<<" "<<stt;
		gotoxy(cot2-1,wherey());
		cout<<l<<C->mavt;
		string a;
		a=C->mavt;
		Tree p;
		p=TimKiem(t,a);
		gotoxy(cot3-1,wherey());
		cout<<l<<p->Data.tenvt;
		gotoxy(cot4-1,wherey());
		cout<<l<<C->soluong;
		gotoxy(cot5-1,wherey());
		cout<<l<<C->dongia;
		gotoxy(cot6-1,wherey());
		cout<<l<<p->Data.dvt;
		gotoxy(cot7-1,wherey());
		cout<<l<<setw(7)<<C->VAT<< l<<endl;
	}
}
void InThongTinTheoSoHD(string f)//f la soHD can tin f=find//tim ra cai hoa don can in
{
	int y=wherey()+1;
    for(int i=0;i<22;i++)
	{
		for(int j=0;j<80;j++)
			cout<<" ";//xoa hoa don da tim truoc do
            gotoxy(0,y+i);
	}

	//gotoxy(0,y);
	int check=0;
	HOADON *K;//k la con tro tro den hoadon can in ra
	for(K=first;K!=NULL;K=K->next)//chay het ds cac hoa don
		if(K->SoHD==f)
		{
			check=1;//danh dau da tim thay hoadon
			break;
		}
	if(check==0)
	{
		string t="Khong tim thay hoa don!!!";
		CanhBao(t,20,1);
	
	}
	else//neu co thi xuat ra hoadon do
	{
		gotoxy(0,4);
		InChiTietHD(K);//in ra ban vat tu
	}
}
void InMotHoaDon()//in nhiu lan theo soHD va kiem tra sohoadon can tim
{
	system("cls");
	HD();
	string f;
	int check=0;
	gotoxy(22,0);	
	cout<<"+ THONG TIN MOT HOA DON +";
	gotoxy(13,2);
	cout<<"Nhap vao so hoa don can xem thong tin: ";
    if (first==NULL)
    {
    	string t="Hien cong ty chua co hoa don nao het!!!";
    	CanhBao(t,15,10);
    	gotoxy(15,12);
   
    	system("Pause");
    	return;
    }
	int XHD=wherex();
    while (check==0)
    {
        while (kbhit())
        {
            int vitri;
            vitri = XHD + f.size();
            gotoxy(vitri,2);
            char c = getch();
            if(c==27)
            {
            	gotoxy(15,1);
            	cout<<"Ban co muon tro lai muc truoc ?(";
            	int xc,xk;
            	xc=wherex();
            	cout<<"Co/";
            	xk=wherex();
            	cout<<"Khong)";
            	gotoxy(xc,wherey()); 
            	cout<<"Co";
            	int flagO=0;
            	while(1)
            	{
	                while (!kbhit()) Sleep(100);
	                c=getch();
	                if(c==-32)
	                {
	                	char cc=getch();
	                	if(cc==77 && flagO==0)
	                	{
	                		gotoxy(xc,wherey());
	                		cout<<"Co";
	                		gotoxy(xk,wherey());
	                		cout<<"Khong";
	                		flagO=1;
	                	}
	                	if(cc==75 && flagO==1)
	                	{
	                		gotoxy(xk,wherey());
	                		cout<<"Khong";
	                		gotoxy(xc,wherey());	
	                		cout<<"Co";
	                		flagO=0;
	                	}
	                }
	                if(c==13)
	                {
	                	if(flagO==0)
	                	{
	                		check=2;
	                		break;
	                	}
	                	else
	                	{
	                	
	                		gotoxy(15,1);
	                		cout<<"                                                           ";
	                		gotoxy(vitri,2);
	                		break;
	                	}
	                }
				}
				if(check==2)
					break;
            }
            else if ((c>=48&&c<=57) || (c>=97 && c<=122) || (c>=65 && c<=90))
            {
                gotoxy(vitri,2);
                if(f.size()<=8)
                {
	                if (c>=97 && c<=122) c = c-32;
    	            cout<<c;
        	        f.insert(f.end(),1,c);
        	    }
            }
            else if (c==8)
            {
                if (f.size()!=0)
                {
                   
                    vitri--;
                    gotoxy(vitri,2);
                    cout<<" ";
                    gotoxy(vitri,2);
                    f.erase(f.end()-1);
                }
            }
            else if (c==13 || c==9)
            {
            	InThongTinTheoSoHD(f);
            	gotoxy(vitri,2);
            }
        }
    }
}
void VeBangLietKeHoaDon()//Giao dien in hoa don trong mot khoang thoi gian
{
		//	gotoxy(0,5);
			cout << (char)218;
			for(int i = 0; i<= 10;i++) cout <<(char)196;
			cout<<(char)194;
			for(int i = 0; i<= 20;i++) cout <<(char)196;
			cout << (char)194;
			for(int i = 0; i<= 10;i++) cout <<(char)196;
			cout << (char)194;
			for(int i = 0; i<= 20;i++) cout <<(char)196;
			cout << (char)194;
			for(int i = 0; i<= 10;i++) cout <<(char)196;
			cout << (char)191<<endl;
			cout << (char)179<< "SO HOA DON ";
			cout << (char)179<< "     NGAY LAP        ";
			cout << (char)179<< "LOAI HD    ";
			cout << (char)179<< "     HO TEN NV LAP   ";
			cout << (char)179<< "TRI GIA HD "<<(char)179<<endl;
			cout << (char)195;
			for(int i = 0; i<= 10;i++) cout <<(char)196;
			cout << (char)197;
			for(int i = 0; i<= 20;i++) cout <<(char)196;
			cout << (char)197;
			for(int i = 0; i<= 10;i++) cout <<(char)196;
			cout << (char)197;
			for(int i = 0; i<= 20;i++) cout <<(char)196;
			cout << (char)197;
			for(int i = 0; i<= 10;i++) cout <<(char)196;
			cout << (char)180<<endl;
	
}
int SoSanhThoiGian(Date a, Date b, Date x)// Xac dinh thoi diem nam trong khoang thoi gian
{
	string aa=	ChuyenNgayThanhChuoi2(a);
	string bb=	ChuyenNgayThanhChuoi2(b);
	string xx=	ChuyenNgayThanhChuoi2(x);
	int aaa = 	ChuyenThanhSo(aa);
	int bbb =   ChuyenThanhSo(bb);
	int xxx =   ChuyenThanhSo(xx);
	if(xxx>=aaa && xxx<= bbb)return 1;
	return 0;
}
void InHoaDonTrongKhoangThoiGian(Date a, Date b)//q la hoadon can in a/b la khoang time
{
	
	int dem = 0;
	HOADON *C = new HOADON;
	for(C=first;C!=NULL;C=C->next)
    {
        if(SoSanhThoiGian(a,b,C->Ngay)==1)
        {	dem++;
        	if(dem==1) VeBangLietKeHoaDon();
        	float trigia= 0;
        	int i = TimKiemNhanVien(C->MANV);
        	for (CT_HOADON *p = C->CT_next; p!=NULL; p = p->next)
        	{
        		trigia =trigia + p->dongia*p->soluong + p->dongia*p->soluong*p->VAT/100;
			}
           	cout << (char)179<<setw(11)<<C->SoHD<<(char)179<<setw(21)<<ChuyenNgayThanhChuoi(C->Ngay)<<(char)179<<setw(11)<<C->loai<<(char)179<<setw(11)<<NVien[i]->HO<<setw(10)<<NVien[i]->TEN<<(char)179<<setw(11)<<trigia<<(char)179<<endl;
            
        }
        
    }
    if(dem==0) 
	{
		cout <<endl;
		cout << "Khong co hoa don trong khoang thoi gian tren. " <<endl;
		cout << "Nhan ESC de ket thuc ";
	}
    
}
int Checka(char a[])//kiem tra ngay thang nam nhap vao..chi nhan nhap so.
{
	int i =0;
	while(a[i]!=NULL)
	{
		if('0'>a[i]||a[i]>'9')// a nho hon 0 (48) va a lon hon 9 (57)
		return 0;
		i++;
	}
return 1;
}
int KiemTraNgay(int ngay, int thang, int nam)
{
	if(thang<1 || thang>12)
		return 0;
	if(nam<2000)
		return 0;
    switch(thang)
	{
    	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
    		if(ngay>31 || ngay<1)
    			return 0;
    		break;
    	case 4: case 6: case 9: case 11:
    		if(ngay>30 || ngay<1)
    			return 0;
    		break;
    	case 2:
    		if(((ngay>28 || ngay<1) && (nam%4)!=0) || ((ngay>29 || ngay<1) && (nam%4)==0))
    			return 0;
    		break;
    }
    return 1;
}
void ThongKeHoaDon()
{
	system("cls");
	gotoxy(22,0);
	cout<<"+ THONG TIN CAC HOA DON +";
	HD();
	Date aa,bb;
	int ngay,thang,nam;
	gotoxy(0,2);
	 if (first==NULL)
    {
    
    	string t="Hien cong ty chua co hoa don nao het!!!";
    	CanhBao(t,15,10);
    	gotoxy(15,12);
    	system("Pause");
    	return;
    }
    gotoxy(15,wherey());
	cout<<"Nhap vao khoang thoi gian can tim cac hoa don:";
	int check=0;
	int xngay,xthang,xnam;
    	//nhap ngay thang nam thu 1
    while(check!=1)
    {
        gotoxy(5,3);
    
        cout<<"                                                                       ";
        gotoxy(2,5);
        cout<<"So 1 ";
        cout<<"Tp HCM, Ngay ";
        xngay = wherex();
        gotoxy(xngay+5,5);
        cout<<"Thang ";
        xthang = wherex();
        gotoxy(xthang+5,5);
        cout<<"Nam ";
       
        xnam = wherex();
        char a[5];//bien tam dung de nhap ngay thang nam
ttn:
        gotoxy(xngay,5);
        cin>>a;
        if(Checka(a))
            ngay=atoi(a);
        else
        {
           gotoxy(xngay,5);
           cout<<"     ";
           CanhBao("Ban da nhap sai ngay, ban nhap nhap lai!!!",15,4);
           getch();
            goto ttn;
        }
ttt:
        gotoxy(xthang,5);
        cin>>a;
        if(Checka(a))
            thang=atoi(a);
        else
        {
           gotoxy(xthang,5);
           cout<<"     ";
           CanhBao("Ban da nhap sai thang, ban nhap nhap lai!!!",15,4);
           getch();
            goto ttt;
        }
ttnam:
        gotoxy(xnam,5);
        cin>>a;
        if(Checka(a))
            nam=atoi(a);
        else
        {
           gotoxy(xngay,5);
           cout<<"     ";
           CanhBao("Ban da nhap sai nam, ban nhap nhap lai!!!",15,4);
           getch();
            goto ttnam;
        }

        if(KiemTraNgay(ngay,thang,nam)==1)//dua vao struct data neu dung
        {
            aa.NGAY=ngay;
            aa.THANG=thang;
            aa.NAM=nam;
            check=1;
        }
        else
        {
            string t="Ban da nhap sai ngay thang nam. 1<=Ngay<=31, 1<=thang<=12, 2000<=nam";
            CanhBao(t,5,3);
            getch();
           
            gotoxy(xngay,5);
            for (int i=xngay; i<xngay+5; i++) cout<<" ";
            gotoxy(xthang,5);
            for (int i=xthang; i<xthang+5; i++) cout<<" ";
            gotoxy(xnam,5);
            for (int i=xnam; i<xnam+5; i++) cout<<" ";
        }
    }
    //nhap ngay thang nam thu 2
    check=0;
    while(check!=1)
    {
        
        gotoxy(2,6);
        
        cout<<"So 2:";
        cout<<"Tp HCM, Ngay ";
        gotoxy(xngay+5,6);
        cout<<"Thang ";
        gotoxy(xthang+5,6);
        cout<<"Nam ";
       
                   char a[5];//bien tam dung de nhap ngay thang nam
ttn2:
        gotoxy(xngay,6);
        cin>>a;
        if(Checka(a))
            ngay=atoi(a);
        else
        {
           gotoxy(xngay,6);
           cout<<"     ";
           CanhBao("Ban da nhap sai ngay, ban nhap nhap lai!!!",15,4);
           getch();
            goto ttn2;
        }
ttt2:
        gotoxy(xthang,6);
        cin>>a;
        if(Checka(a))
            thang=atoi(a);
        else
        {
           gotoxy(xthang,6);
           cout<<"     ";
           CanhBao("Ban da nhap sai thang, ban nhap nhap lai!!!",15,4);
           getch();
            goto ttt2;
        }
ttnam2:
        gotoxy(xnam,6);
        cin>>a;
        if(Checka(a))
            nam=atoi(a);
        else
        {
           gotoxy(xngay,6);
           cout<<"     ";
           CanhBao("Ban da nhap sai nam, ban nhap nhap lai!!!",15,4);
           getch();
            goto ttnam2;
        }
        if(KiemTraNgay(ngay,thang,nam)==1)
        {
            bb.NGAY=ngay;
            bb.THANG=thang;
            bb.NAM=nam;
            check=1;
        }
        else
        {
            string t="Ban da nhap sai ngay thang nam. 1<=Ngay<=31, 1<=thang<=12, 2000<=nam";
            CanhBao(t,5,3);
            getch();
            
            gotoxy(xngay,6);
            for (int i=xngay; i<xngay+5; i++) cout<<" ";
            gotoxy(xthang,6);
            for (int i=xthang; i<xthang+5; i++) cout<<" ";
            gotoxy(xnam,6);
            for (int i=xnam; i<xnam+5; i++) cout<<" ";
        }
    }
    cout << endl;
   
   InHoaDonTrongKhoangThoiGian(aa,bb);

	char c = getch();
	  if (c==27)//ESC
    {
        return;
    }  
    
}

float TinhDoanhThu(HOADON *first, string MAVT,Date a, Date b)// q la xuat 
{
	float doanhthu = 0;
	HOADON *C = new HOADON;
	for(HOADON *C=first;C!=NULL;C=C->next)
    {
    	if(SoSanhThoiGian(a,b,C->Ngay)==1)
    	{
    			if(C->loai=='X')
    		{
    			 for (CT_HOADON *p = C->CT_next; p!=NULL; p = p->next)
    			 {
    			 	if(strcmp(p->mavt,MAVT.c_str())==0)
    			 	{
    			 		doanhthu = doanhthu + p->dongia*p->soluong+p->dongia*p->soluong*p->VAT/100;
					 }
				 }
			}
    		 
		}
    
      
           
    }
    return doanhthu;
	
}

typedef struct
{
	char mavt[11];
	float doanhthu;	
} DoanhThu;

void DuyetCay2(Tree root, DoanhThu A[], int &dem, Date a, Date b)
{
	const int STACKSIZE = 500;
	Tree Stack [STACKSIZE];
	int sp = -1;
	Tree p = root;
	while (p!=NULL)
	{
		strcpy(A[dem].mavt,p->Data.mavt) ;
		A[dem].doanhthu=TinhDoanhThu(first,A[dem].mavt,a,b);
		
		dem++;
		if(p->right!=NULL)
			Stack[++sp]=p->right;
		if(p->left!=NULL)
			p=p->left;
		else if(sp==-1)
		{
			break;
		}
		else p=Stack[sp--];
	}

}
void SapXepTheoDoanhThu(DoanhThu A[])
{
	int i,j;
	int n = TinhSoNode(t);
	DoanhThu t;
	 for ( i = 1; i < n; i++)
	  {
      	for (j = 1; j < n; j++)
		   {
         	if (A[j - 1].doanhthu < A[j].doanhthu)
			  {
           		t = A[j - 1];
           		A[j - 1] = A[j];
            	A[j] = t;
         	  }
      	   }
     }
}
void DanhSach10VT(DoanhThu A[])//Duyet de in top 10 vat tu, A[] da sap xep
{
		int n = TinhSoNode(t);
		int STT =0;
		for(int i = 0; i<n; i++)
		{
			string a="";
			a=A[i].mavt;
			Tree p=TimKiem(t,a);
			if(A[i].doanhthu!=0&&STT<10)
			{
				STT++;
				cout <<(char)179<<setw(11)<<STT<<(char)179<<setw(21)<<p->Data.tenvt<<(char)179<<setw(21)<<A[i].doanhthu<<(char)179<<endl;
				
			}
			if(A[i].doanhthu!=0&&i>9)
			{
				if(A[i].doanhthu==A[9].doanhthu)
				{
				STT++;
				cout <<(char)179<<setw(11)<<STT<<(char)179<<setw(21)<<p->Data.tenvt<<(char)179<<setw(21)<<A[i].doanhthu<<(char)179<<endl;
				}
			}
		}
}

void GiaoDienIn10VT()
{
			cout << (char)218;
			for(int i = 0; i<= 10;i++) cout <<(char)196;
			cout<<(char)194;
			for(int i = 0; i<= 20;i++) cout <<(char)196;
			cout << (char)194;
			for(int i = 0; i<= 20;i++) cout <<(char)196;
			cout << (char)191<<endl;
			cout << (char)179<< "STT        ";
			cout << (char)179<< "     TEN VAT TU      ";
			cout << (char)179<< "     DOANH THU       ";
			cout <<(char)179<<endl;
			cout << (char)195;
			for(int i = 0; i<= 10;i++) cout <<(char)196;
			cout << (char)197;
			for(int i = 0; i<= 20;i++) cout <<(char)196;
			cout << (char)197;
			for(int i = 0; i<= 20;i++) cout <<(char)196;
			cout << (char)180<<endl;
}

void In10VatTu()//In 10 vat tu co doanh thu cao nhat
{
	system("cls");
	gotoxy(15,0);
	cout << "+ TOP 10 VAT TU CO DOANH THU CAO + ";
		HD();
	Date aa,bb;
	int ngay,thang,nam;
	gotoxy(0,2);
	 if (first==NULL)
    {
    	string t="Hien cong ty chua co hoa don nao het!!!";
    	CanhBao(t,15,10);
    	gotoxy(15,12);
    	system("Pause");
    	return;
    }
    gotoxy(15,wherey());
	cout<<"Nhap vao khoang thoi gian can tim cac hoa don:";
	int check=0;
	int xngay,xthang,xnam;
    	//nhap ngay thang nam thu 1
    while(check!=1)
    {
        gotoxy(5,3);
    
        cout<<"                                                                       ";
        gotoxy(2,5);
        cout<<"So 1:";
        cout<<"Tp HCM, Ngay ";
        xngay = wherex();
        gotoxy(xngay+5,5);
        cout<<"Thang ";
        xthang = wherex();
        gotoxy(xthang+5,5);
        cout<<"Nam ";
       
        xnam = wherex();
        char a[5];//bien tam dung de nhap ngay thang nam
ttn:
        gotoxy(xngay,5);
        cin>>a;
        if(Checka(a))
            ngay=atoi(a);
        else
        {
           gotoxy(xngay,5);
           cout<<"     ";
           CanhBao("Ban da nhap sai ngay, ban nhap nhap lai!!!",15,4);
           getch();
            goto ttn;
        }
ttt:
        gotoxy(xthang,5);
        cin>>a;
        if(Checka(a))
            thang=atoi(a);
        else
        {
           gotoxy(xthang,5);
           cout<<"     ";
           CanhBao("Ban da nhap sai thang, ban nhap nhap lai!!!",15,4);
           getch();
            goto ttt;
        }
ttnam:
        gotoxy(xnam,5);
        cin>>a;
        if(Checka(a))
            nam=atoi(a);
        else
        {
           gotoxy(xngay,5);
           cout<<"     ";
           CanhBao("Ban da nhap sai nam, ban nhap nhap lai!!!",15,4);
           getch();
            goto ttnam;
        }

        if(KiemTraNgay(ngay,thang,nam)==1)//dua vao struct data neu dung
        {
            aa.NGAY=ngay;
            aa.THANG=thang;
            aa.NAM=nam;
            check=1;
        }
        else
        {
            string t="Ban da nhap sai ngay thang nam. 1<=Ngay<=31, 1<=thang<=12, 2000<=nam";
            CanhBao(t,5,3);
            getch();
           
            gotoxy(xngay,5);
            for (int i=xngay; i<xngay+5; i++) cout<<" ";
            gotoxy(xthang,5);
            for (int i=xthang; i<xthang+5; i++) cout<<" ";
            gotoxy(xnam,5);
            for (int i=xnam; i<xnam+5; i++) cout<<" ";
        }
    }
    //nhap ngay thang nam thu 2
    check=0;
    while(check!=1)
    {
        
        gotoxy(2,6);
        
        cout<<"So 2:";
        cout<<"Tp HCM, Ngay ";
        gotoxy(xngay+5,6);
        cout<<"Thang ";
        gotoxy(xthang+5,6);
        cout<<"Nam ";
       
                   char a[5];//bien tam dung de nhap ngay thang nam
ttn2:
        gotoxy(xngay,6);
        cin>>a;
        if(Checka(a))
            ngay=atoi(a);
        else
        {
           gotoxy(xngay,6);
           cout<<"     ";
           CanhBao("Ban da nhap sai ngay, ban nhap nhap lai!!!",15,4);
           getch();
            goto ttn2;
        }
ttt2:
        gotoxy(xthang,6);
        cin>>a;
        if(Checka(a))
            thang=atoi(a);
        else
        {
           gotoxy(xthang,6);
           cout<<"     ";
           CanhBao("Ban da nhap sai thang, ban nhap nhap lai!!!",15,4);
           getch();
            goto ttt2;
        }
ttnam2:
        gotoxy(xnam,6);
        cin>>a;
        if(Checka(a))
            nam=atoi(a);
        else
        {
           gotoxy(xngay,6);
           cout<<"     ";
           CanhBao("Ban da nhap sai nam, ban nhap nhap lai!!!",15,4);
           getch();
            goto ttnam2;
        }
        if(KiemTraNgay(ngay,thang,nam)==1)
        {
            bb.NGAY=ngay;
            bb.THANG=thang;
            bb.NAM=nam;
            check=1;
        }
        else
        {
            string t="Ban da nhap sai ngay thang nam. 1<=Ngay<=31, 1<=thang<=12, 2000<=nam";
            CanhBao(t,5,3);
            getch();
            
            gotoxy(xngay,6);
            for (int i=xngay; i<xngay+5; i++) cout<<" ";
            gotoxy(xthang,6);
            for (int i=xthang; i<xthang+5; i++) cout<<" ";
            gotoxy(xnam,6);
            for (int i=xnam; i<xnam+5; i++) cout<<" ";
        }
    }
  //  cout << endl;
    int dem = 0;
	DoanhThu A[MAXVT];
    DuyetCay2 (t,A,dem,aa,bb);
    SapXepTheoDoanhThu(A);
   if(A[0].doanhthu==0)
   {
    	cout << "Khong co vat tu nao xuat trong thoi gian tren"<<endl;
    	cout << "Nhan ESC de ket thuc ";
	}
	else
	{
		GiaoDienIn10VT();
    	DanhSach10VT(A);
	}
   	char c = getch();
	  if (c==27)//ESC
    {
        return;
    }  
}


void KhoiTaoMenuHoaDon()
{
	gotoxy(0,0);
    gotoxy(1,1);
    gotoxy(37,1);   
    cout<<"MENU HOA DON ";
    KhungNho(30,3);
    KhungNho(30,6);
    KhungNho(30,9);
    KhungNho(30,12);
    KhungNho(30,15);
    gotoxy(31,4);
    cout<<"1. Lap hoa don             ";
    gotoxy(31,7);
    cout<<"2. In hoa don              ";
    gotoxy(31,10);
    cout<<"3. Thong ke hoa don        ";
    gotoxy(31,13);
    cout<<"4. 10 VT co doanh thu cao  ";
    gotoxy(31,16);
    cout<<"5. Save hoa don            "; 

}
int MenuHD()
{

	system("CLS");
    int check =0;
    KhoiTaoMenuHoaDon();//tao menu vat tu
    string lt[23];
    lt[4]  = "1. Lap hoa don             ";
    lt[7]  = "2. In hoa don              ";
    lt[10] = "3. Thong ke hoa don        ";
    lt[13] = "4. 10 VT co doanh thu cao  ";
    lt[16] = "5. Save hoa don            ";
    HD();
    gotoxy(31,4);
    MauChon();
    cout<<lt[4];//chon cai thu nhat
	 while(check == 0)
    {
    	char kk = getch();
    	if (kk == 72)//phim di chuyen len
           	{
                int y = wherey();
                if (y == 4) //neu dang o hang dau ma nhan phim len thi di chuyen xuong hang cuoi cung
               	 {
                    gotoxy(31,y);
                    Normal ();
                    cout<<lt[4];
                    gotoxy(31,16);
                    MauChon();
                    cout<<lt[16];
                   	Normal ();
                }
                else//moi lan chay qua nhay 3 hang
                {
                    gotoxy(31,y);
                    Normal ();
                    cout<<lt[y];
                    gotoxy(31,y-3);
                    MauChon();
                    cout<<lt[y-3];
                   	Normal ();
                }
            }
        else if (kk==80)
            {
                int y = wherey();
                if (y == 16) //neu o hang cuoi ma di chuyen xuong thi dua con tro ve hang dau
                {
                    gotoxy(31,16);
                    Normal ();
                    cout<<lt[16];
                    gotoxy(31,4);
                    MauChon();
                    cout<<lt[4];
                   	Normal ();
                }
                else
                {
                    gotoxy(31,y);
                    Normal();
                    cout<<lt[y];
                    gotoxy(31,y+3);
                    MauChon();
                    cout<<lt[y+3];
                   	Normal ();
                }
            }
         else if(kk==13)
            {
            	  int y = wherey();
            	  if(y==4)
            	  {
            	 	Normal ();
            	  	system("cls");
            	  	LapHoaDon();
            	 	SaveHD();
            	  	return 0;
				  }
				  if(y==7)
				  {
				  	Normal();
				  	system("cls");
				  	InMotHoaDon();
				  	SaveHD();
				  	return 0;
				  }
				  if(y==10)
				  {
				  	Normal();
				  	system("cls");
				  	ThongKeHoaDon();
				  	SaveHD();
				  	return 0;
				  	
				  }
				  if(y==13)
				  {
				  	Normal();
				  	system("cls");
				  	In10VatTu();
				  	return 0;
				  }
				  if(y==16)
				  {
				  	
					Normal();
				  	SaveHD();
				  	system("cls");
				  	HD();
				  	string s="Da save file";
				  	CanhBao(s,30,10);
				  	system("PAUSE");
				  	return 0;
				  }
		
			}
		else if(kk==27)
		{
		
			return 1;
					
		}      
	}

}

void EscHD()
{
	int check =0;
	while(check ==0)
	{
	check = MenuHD();	
	}
}

void KhoiTaoMenuChinh()
{
	gotoxy(0,0);
    gotoxy(1,1);
    gotoxy(32,1);   
    cout<<"+ QUAN LY NHAP XUAT VAT TU +";
    KhungNho(30,3);
    KhungNho(30,6);
    KhungNho(30,9);
    KhungNho(30,12);
    KhungNho(30,15);
    gotoxy(31,4);
    cout<<"1. Vat Tu                  ";
    gotoxy(31,7);
    cout<<"2. Nhan Vien               ";
    gotoxy(31,10);
    cout<<"3. Hoa Don                 ";
    gotoxy(31,13);
    cout<<"5. Save                    ";
    gotoxy(31,16);
    cout<<"7. Thoat                   ";
   
}
int MenuChinh()
{
	
	Normal();
	system("CLS");
    int check =0;
    KhoiTaoMenuChinh();//tao menu vat tu
    string lt[23];
    lt[4]  = "1. Vat Tu                  ";
    lt[7]  = "2. Nhan Vien               ";
    lt[10] = "3. Hoa Don                 ";
    lt[13] = "5. Save                    ";
    lt[16] = "7. Thoat                   ";
    HD();
    gotoxy(31,4);
    MauChon();
    cout<<lt[4];//chon cai thu nhat
    
	 while(check == 0)
    {
    	char kk = getch();
    	if (kk == 72)//phim di chuyen len
           	{
                int y = wherey();
                if (y == 4) //neu dang o hang dau ma nhan phim len thi di chuyen xuong hang cuoi cung
               	 {
                    gotoxy(31,y);
                    Normal ();
                    cout<<lt[4];
                    gotoxy(31,16);
                    MauChon();
                    cout<<lt[16];
                   	Normal ();
                }
                else//moi lan chay qua nhay 3 hang
                {
                    gotoxy(31,y);
                    Normal ();
                    cout<<lt[y];
                    gotoxy(31,y-3);
                    MauChon();
                    cout<<lt[y-3];
                   	Normal ();
                }
            }
        else if (kk==80)
            {
                int y = wherey();
                if (y == 16) //neu o hang cuoi ma di chuyen xuong thi dua con tro ve hang dau
                {
                    gotoxy(31,16);
                    Normal ();
                    cout<<lt[16];
                    gotoxy(31,4);
                    MauChon();
                    cout<<lt[4];
                   	Normal();
                }
                else
                {
                    gotoxy(31,y);
                    Normal();
                    cout<<lt[y];
                    gotoxy(31,y+3);
                    MauChon();
                    cout<<lt[y+3];
                   	Normal ();
                }
            }
         else if(kk==13)
            {
            	  int y = wherey();
            	  if(y==4)
            	  {
            	 	Normal ();
            	  	system("cls");
            	 	EscVT();
            	 	SaveVT(t);
            		return 0;
				  }
				  if(y==7)
				  {
				  	EscNV();
				  	SaveNV();
				  	return 0;
				  }
				  if(y==10)
				  {
				  	Normal();
				  	system("cls");
				  	EscHD();
				 // 	SaveHD();
				  	return 0;
				  	
				  }
				  if(y==13)
				  {
				  	Normal();
				  	SaveVT(t);
				  	SaveNV();
				  	SaveHD();
				  	system("cls");
				  	HD();
				  	string s="Da save file";
				  	CanhBao(s,30,10);
				  	system("PAUSE");
				  	return 0;
				  }
				  if(y==16)
				  {
				  		gotoxy(20,25);						
						cout<<" Ban co muon thoat chuong trinh ?(";
						int xc=wherex();
						cout<<"Co/";
						int xk=wherex();
						cout<<"Khong)";
						gotoxy(xc,wherey());
					
						cout<<"Co";
						int flagE=0;
						while(1)
						{
							while(!kbhit())	Sleep(100);
							char kk=getch();
							if(kk==-32)
							{
								char cc=getch();
								if(cc==77 && flagE==0)
								{
									gotoxy(xc,wherey());
									cout<<"Co";
									gotoxy(xk,wherey());
									cout<<"Khong";
									flagE=1;
								}
								if(cc==75 && flagE==1)
								{
									gotoxy(xk,wherey());
									cout<<"Khong";
									gotoxy(xc,wherey());
									cout<<"Co";
									flagE=0;
								}
							}
							if(kk==13)
							{
								if(flagE==1)
								{
								
									return 0;
								}
								if(flagE==0)
								{
									return 1;
								}
							}
        	            }
				
				  }
			}
		else if(kk==27)
		{
			Normal();
			gotoxy(20,25);						
			cout<<" Ban co muon thoat chuong trinh ?(";
			int xc=wherex();
			cout<<"Co/";
			int xk=wherex();
			cout<<"Khong)";
			gotoxy(xc,wherey());	
			cout<<"Co";
			int flagE=0;
			while(1)
						{
							while(!kbhit())	Sleep(100);
							char kk=getch();
							if(kk==-32)
							{
								char cc=getch();
								if(cc==77 && flagE==0)
								{
									gotoxy(xc,wherey());
									cout<<"Co";
									gotoxy(xk,wherey());
									cout<<"Khong";
									flagE=1;
								}
								if(cc==75 && flagE==1)
								{
									gotoxy(xk,wherey());
									cout<<"Khong";
									gotoxy(xc,wherey());
									cout<<"Co";
									flagE=0;
								}
							}
							if(kk==13)
							{
								if(flagE==1)
								{
									return 0;
								}
								if(flagE==0)
								{
									return 1;
								}
							}
        	            }
				
		
					
		}      
	}

}

void EscMenuChinh()
{
	int check =0;
	while(check ==0)
	{
		check = MenuChinh();
	}
}

int main()
{
	resizeconsole(775,600);
	LoadHD();
	EscMenuChinh();
	return 0;
}
