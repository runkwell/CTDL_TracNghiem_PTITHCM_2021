#pragma once
#include "dohoa.h"
#include "Lop.h"
#include "MonHoc.h"
#include "De.h"
#include "thoiGian.h"
#include "ChiTietBaiThi.h"
#include <cmath>

float **danhSachDiem(SinhVien *mangTamSV, int nSV, char dsMon[][20], int &nDSMon);
float **danhSachDiemMotMon(SinhVien *mangTamSV, int nSV, char dsMon[][20], int &nDSMon, char maMon[]);

void run();
char *dangnhaptaikhoan(DanhSachLop &danhSachLop){
		form_dangnhap();
		char *nguoidung= new char;
		char *mk= new char;
	    strcpy(nguoidung,"");
	    strcpy(mk,"");
		char *cmk= new char;
		strcpy(cmk,"");
		int mx,my,key;
		mx=my=-1;
		key=0;
		while(1) {
		delay(0.01);
		getmouseclick(WM_LBUTTONDOWN,mx,my);
		clearmouseclick(WM_LBUTTONDOWN);
		key=MID[mx][my];
		
		lb:
		if(key>0)
		switch(key){
			case 1:{
				ScannerMa(nguoidung,20,100+440,100+190,key,key);
				
				goto lb;
				break;
			}
			case 2:{
				cout<<"mat khau ";
			    Scannermk(mk,20,100+440,160+190,key,key,cmk);
				goto lb;
				break;
			}
			case 3:{
				cout<<".."<<nguoidung<<".."<<mk<<"..";
				if(strlen(nguoidung)*strlen(mk)==0)
				{
					key =0;
					setbkcolor(15);
						setcolor(12);
						outtextxy(440,500,"    Vui long dien day du thong tin             ");
					goto lb;
				}
				if(strcmp(nguoidung,"GV")==0&&strcmp(mk,"Gv")==0)
				return "GV";
				else{
					NodeSinhVien *sinhVien = timKiemTrongTatCaSinhVien(danhSachLop, nguoidung);
					if(sinhVien!=NULL){
						if(strcmp(mk,sinhVien->sinhVien.pass)==0)	return nguoidung;
						else{
							setbkcolor(15);
							setcolor(12);
							outtextxy(440,500,"            SAI MAT KHAU             ");
							key=0;
							goto lb;
						}
					}
				}
				setbkcolor(15);
						setcolor(12);
						outtextxy(440,500,"            TAI KHOAN KHONG TON TAI             ");
						key=0;
				goto lb;
				break;
			}
		}
       }
}
int RunQLSinhVien(DanhSachLop &danhSachLop, char maLop[], DanhSachMonHoc &danhSachMonHoc){
		menuchinh(2);
		khungquanlysinhvien();
		
		SinhVien *mangSinhVien=NULL;
		int nSinhVien = 0;
		
		int trang=1;
		int cot=1;
		char malop[14]="";
		strcpy(malop, maLop);
		char MaSinhVien[14]="";
	    char Ho[50]="";
    	char Ten[50]="";
    	bool Phai;
    	
    	bool isEdit=false;
    	
    	char dsMonHocDiem[100][20];
		float **dsDiem=NULL;
		int nDiem=0;
		
		char maMonLoc[15] = "";
    	
    	Lop *lop = timKiemLop(danhSachLop, malop);
    	if(lop!=NULL){
    		setcolor(9);
			setbkcolor(15);
    		outtextxy(145, 95, malop);
    		inDSSinhVien(lop->danhSachSinhVien, mangSinhVien, nSinhVien, trang);
    		dsDiem = danhSachDiem(mangSinhVien, nSinhVien, dsMonHocDiem, nDiem);
	    	inDSDiem(dsDiem, nSinhVien, nDiem, trang, cot, dsMonHocDiem);
		}
    	
    	int mx,my,key;
		mx=my=-1;
		key=0;
		while(1) {
		delay(0.01);
		getmouseclick(WM_LBUTTONDOWN,mx,my);
		clearmouseclick(WM_LBUTTONDOWN);
		key=MID[mx][my];
		lb:
		if(key>0)
		switch(key){
		
		case 21:{
			ScannerMa(malop,20,145,95,key,key);
			lop = timKiemLop(danhSachLop, malop);
	    	if(lop!=NULL){
	    		inDSSinhVien(lop->danhSachSinhVien, mangSinhVien, nSinhVien, trang);
	    		dsDiem = danhSachDiem(mangSinhVien, nSinhVien, dsMonHocDiem, nDiem);
	    		inDSDiem(dsDiem, nSinhVien, nDiem, trang, cot, dsMonHocDiem);
			}
			goto lb;
			break;
		}
		case 22:{
			ScannerMa(MaSinhVien,20,145,135,key,key);
			goto lb;
			break;
		}
		case 23:{
			ScannerName(Ho,50,145,175,key,key);
			goto lb;
			break;
		}
		case 24:{
			ScannerName(Ten,50,145,215,key,key);
			goto lb;
			break;
		}
		case 25:{
			Phai =true;
		 	button(15+100,250,115+100,280,25,"  NAM",2,2,0);       //25
     		button(290,250,390,280,26,"  NU",2,15,0);         //26
            key=0;
            goto lb;
			break;
		}
		case 26:{
			Phai =false;
		 	button(15+100,250,115+100,280,25,"  NAM",2,15,0);       //25
     		button(290,250,390,280,26,"  NU",2,2,0);         //26
			key=0;
            goto lb;
			break;
		}
		case 27:{
			//luu
			if(strlen(MaSinhVien)==0 || strlen(Ho)==0 || strlen(Ten)==0){
				clearLoi();
				inLoi("Phai dien du thong tin");
				break;
			}
			NodeSinhVien *tmpSinhVien = timKiemTrongTatCaSinhVien(danhSachLop, MaSinhVien);
			if(!isEdit){
				if(tmpSinhVien==NULL){
					if(Phai){
						themSinhVienVaoLop(danhSachLop, malop, taoSinhVien(MaSinhVien, Ho, Ten, "NAM", "123"));
					}
					else{
						themSinhVienVaoLop(danhSachLop, malop, taoSinhVien(MaSinhVien, Ho, Ten, "NU", "123"));
					}
					bangsinhvien(trang);
					inDSSinhVien(lop->danhSachSinhVien, mangSinhVien, nSinhVien, trang);
					dsDiem = danhSachDiem(mangSinhVien, nSinhVien, dsMonHocDiem, nDiem);
	    			inDSDiem(dsDiem, nSinhVien, nDiem, trang, cot, dsMonHocDiem);
					clearThongTinSinhVien();
					strcpy(MaSinhVien,"");
					strcpy(Ho,"");
					strcpy(Ten,"");
					Phai=true;
					ghiFileDSLopSVDiem(danhSachLop);
					isEdit=false;
					clearLoi();
				}
				else{
					clearLoi();
					inLoi("Sinh vien da ton tai");
				}
			}
			else{
				if(tmpSinhVien==NULL){
					clearLoi();
					inLoi("Sinh vien khong ton tai");
				}
				else{
//					if(Phai){
					suaSinhVienTrongLop(danhSachLop, malop, MaSinhVien, Ho, Ten);
//					}
//					else{
//						suaSinhVienTrongLop(danhSachLop, malop, MaSinhVien, Ho, Ten);
//					}
					bangsinhvien(trang);
					inDSSinhVien(lop->danhSachSinhVien, mangSinhVien, nSinhVien, trang);
					dsDiem = danhSachDiem(mangSinhVien, nSinhVien, dsMonHocDiem, nDiem);
	    			inDSDiem(dsDiem, nSinhVien, nDiem, trang, cot, dsMonHocDiem);
					clearThongTinSinhVien();
					strcpy(MaSinhVien,"");
					strcpy(Ho,"");
					strcpy(Ten,"");
					Phai=true;
					ghiFileDSLopSVDiem(danhSachLop);
					isEdit=false;
					clearLoi();
				}
			}
			break;
		}
		case 28:{
			// xoa
			if(strlen(MaSinhVien)==0){
				clearLoi();
				inLoi("Chon sinh vien muon xoa");
				break;
			}
			if(kiemTraXoaSinhVienTrongLop(danhSachLop, malop, MaSinhVien)){
				xoaSinhVienTrongLop(danhSachLop, malop, MaSinhVien);
				clearThongTinSinhVien();
				bangsinhvien(trang);
				inDSSinhVien(lop->danhSachSinhVien, mangSinhVien, nSinhVien, trang);
				dsDiem = danhSachDiem(mangSinhVien, nSinhVien, dsMonHocDiem, nDiem);
	    		inDSDiem(dsDiem, nSinhVien, nDiem, trang, cot, dsMonHocDiem);
				strcpy(MaSinhVien,"");
				strcpy(Ho, "");
				strcpy(Ten, "");
				Phai=true;
				ghiFileDSLopSVDiem(danhSachLop);
				clearLoi();
				isEdit=false;
			}
			else{
				clearLoi();
				inLoi("Sinn vien khong the xoa");
			}
			break;
		}
		case 29:{
			run();
			break;
		}
		case 2100:{
			// in cac cot diem tiep
			cot++;
			bangsinhvien(trang);
			if(lop!=NULL){
				inDSSinhVien(lop->danhSachSinhVien, mangSinhVien, nSinhVien, trang);
				dsDiem = danhSachDiem(mangSinhVien, nSinhVien, dsMonHocDiem, nDiem);
	    		inDSDiem(dsDiem, nSinhVien, nDiem, trang, cot, dsMonHocDiem);
			}
			break;
		}
		case 2101:{
			// in cac ot diem truoc
			if(cot>1) cot--;
			bangsinhvien(trang);
			if(lop!=NULL){
				inDSSinhVien(lop->danhSachSinhVien, mangSinhVien, nSinhVien, trang);
				dsDiem = danhSachDiem(mangSinhVien, nSinhVien, dsMonHocDiem, nDiem);
	    		inDSDiem(dsDiem, nSinhVien, nDiem, trang, cot, dsMonHocDiem);
			}
			break;
		}
		case 2102:{
			if(trang>1)trang--;
			bangsinhvien(trang);
			if(lop!=NULL){
				inDSSinhVien(lop->danhSachSinhVien, mangSinhVien, nSinhVien, trang);
				dsDiem = danhSachDiem(mangSinhVien, nSinhVien, dsMonHocDiem, nDiem);
	    		inDSDiem(dsDiem, nSinhVien, nDiem, trang, cot, dsMonHocDiem);
			}
			break;
		}
		case 2103:{
			trang++;
			bangsinhvien(trang);
			if(lop!=NULL){
				inDSSinhVien(lop->danhSachSinhVien, mangSinhVien, nSinhVien, trang);
				dsDiem = danhSachDiem(mangSinhVien, nSinhVien, dsMonHocDiem, nDiem);
	    		inDSDiem(dsDiem, nSinhVien, nDiem, trang, cot, dsMonHocDiem);
			}
			break;
		}
		case 2001: case 2002: case 2003: case 2004: case 2005: case 2006: case 2007: case 2008: case 2009: case 2010: case 2011: case 2012: case 2013: case 2014: case 2015:{ 
				int vt = key-2000+(trang-1)*15;
				if(vt==0) break;
				if(vt>nSinhVien) break;
				clearThongTinSinhVien();
				layThongTinSinhVien(mangSinhVien[vt-1]);
				strcpy(MaSinhVien, mangSinhVien[vt-1].maSV);
				strcpy(Ho, mangSinhVien[vt-1].ho);
				strcpy(Ten, mangSinhVien[vt-1].ten);
				if(strcmp(mangSinhVien[vt-1].phai, "NAM")==0){
					Phai = true;
				}
				else{
					Phai = false;
				}
				isEdit=true;
				break;
			}
		case 2200:{//quet ma mon hoc
			ScannerMa(maMonLoc, 12, 415, 522, key, key);
			goto lb;
			break;
		}
		case 2201:{//loc mon hoc
			setcolor(9);
			outtextxy(415, 560, "                                                ");
			if(strlen(maMonLoc)==0){
				clearLoi();
				trang=1;
				bangsinhvien(trang);
				inDSSinhVien(lop->danhSachSinhVien, mangSinhVien, nSinhVien, trang);
				dsDiem = danhSachDiem(mangSinhVien, nSinhVien, dsMonHocDiem, nDiem);
	    		inDSDiem(dsDiem, nSinhVien, nDiem, trang, cot, dsMonHocDiem);
			}
			else{
				if(timKiemMonHoc(danhSachMonHoc, maMonLoc)==NULL){
					clearLoi();
					inLoi("Khong tim thay mon");
				}
				else{
					clearLoi();
					trang=1;
					bangsinhvien(trang);
					setcolor(9);
					outtextxy(415, 560, timKiemMonHoc(danhSachMonHoc, maMonLoc)->monHoc.tenMH);
					inDSSinhVien(lop->danhSachSinhVien, mangSinhVien, nSinhVien, trang);
					dsDiem = danhSachDiemMotMon(mangSinhVien, nSinhVien, dsMonHocDiem, nDiem, maMonLoc);//in ds diem 1 mon
		    		inDSDiem(dsDiem, nSinhVien, nDiem, trang, cot, dsMonHocDiem);
				}
			}
			break;
		}
		default:{
				if(key==1||key==2||key==3||key==4||key==5||key==6)
				return key;
			}
			
	}
	
}}
int RunQLLop(DanhSachLop &danhSachLop, DanhSachMonHoc &danhSachMonHoc){ 

		bool isEdit = false;

        char malop[14]="";
        char tenlop[30]="";
	    int trang=1;
		menuchinh(1);
		khungquanlylop();
		inDSLop(danhSachLop, trang);
		int mx,my,key;
		mx=my=-1;
		key=0;
		while(1) {
		delay(0.01);
		getmouseclick(WM_LBUTTONDOWN,mx,my);
		clearmouseclick(WM_LBUTTONDOWN);
		key=MID[mx][my];
		lb:
		if(key>0)
		switch(key){
			case 11:{
				ScannerMa(malop,20,140+5,90+5,key,key);
				goto lb;
				break;
			}
			case 12:{
//				ScannerString(tenlop,50,140+5,130+5,key,key);
				ScannerWrapString(tenlop, 30, 145, 135, key, key, 16, 30);
				goto lb;
				break;
			}
			case 13:{
				/// ham luu
				if(strlen(malop)==0 || strlen(tenlop)==0){
					clearLoi();
					inLoi("Phai dien du thong tin");
					break;
				}
				if(!isEdit){
					if(timKiemLop(danhSachLop, malop)==NULL){
						themLopVaoDS(danhSachLop, taoLopMoi(malop, tenlop));
						banglop(trang);
						inDSLop(danhSachLop, trang);
						clearThongTinLop();
						strcpy(malop,"");
						strcpy(tenlop,"");
						ghiFileDSLopSVDiem(danhSachLop);
						isEdit = false;
						clearLoi();
					}
					else{
						clearLoi();
						inLoi("Lop da ton tai");
					}
				}
				else{
					if(timKiemLop(danhSachLop, malop)==NULL){
						clearLoi();
						inLoi("Lop khong ton tai");
					}
					else{
						suaThongTinLop(danhSachLop, malop, tenlop);
						banglop(trang);
						inDSLop(danhSachLop, trang);
						clearThongTinLop();
						strcpy(malop,"");
						strcpy(tenlop,"");
						ghiFileDSLopSVDiem(danhSachLop);
						isEdit = false;
						clearLoi();
					}
				}
				break;
			}
			case 14:{
				//xoa
				if(strlen(malop)==0){
					clearLoi();
					inLoi("Chon lop truoc khi xoa");
					break;
				}
				if(kiemtraxoa(danhSachLop, malop)){
					xoaLop(danhSachLop, malop);
					banglop(trang);
					inDSLop(danhSachLop, trang);
					clearThongTinLop();
					strcpy(malop,"");
					strcpy(tenlop,"");
					ghiFileDSLopSVDiem(danhSachLop);
					clearLoi();
					isEdit=false;
				}
				else{
					clearLoi();
					inLoi("Khong the xoa lop nay");
				}
				break;
			}
			case 15:{
				// lui trang
				if(trang>1) trang--;
				banglop(trang);
				inDSLop(danhSachLop, trang);
				break;
			}
			case 16:{
			    trang++;
				banglop(trang);
				inDSLop(danhSachLop, trang);
				break;
			}
			case 17:{
				RunQLSinhVien(danhSachLop, malop, danhSachMonHoc);
				break;
			} 
			case 99:{
				run();
				break;
			}
			case 1001: case 1002: case 1003: case 1004: case 1005: case 1006: case 1007: case 1008: case 1009: case 1010: case 1011: case 1012: case 1013: case 1014: case 1015:{ 
//				cap nhat lai du kien thong tin ten lop va ma lop
				int vt = key-1000+(trang-1)*15;
				Lop *lop = timKiemtheochisovitriLop(danhSachLop, vt);
				if(lop==NULL) break;
				clearThongTinLop();
				layThongTinLop(*lop);
				strcpy(malop, lop->maLop);
				strcpy(tenlop, lop->tenLop);
				isEdit = true;
				break;
			}
			default:{
				if(key==1||key==2||key==3||key==4||key==5||key==6)
				return key;
			}
		}
}}
int RunQuanlycauhoi(DanhSachMonHoc &danhSachMonHoc, char *maMon){ 
        char mamon[14]="";
        strcpy(mamon, maMon);
        char tenmon[30]="";
        char cauhoi[500]="";
        char dapanA[500]="";
        char dapanB[500]="";
        char dapanC[500]="";
        char dapanD[500]="";

	    int trang =1;
	    
	    bool isEdit=false;
	    
		menuchinh(4);
		khungquanlycauhoi();
		
		NodeMonHoc *monHoc = timKiemMonHoc(danhSachMonHoc, mamon);
		if(monHoc!=NULL){
			inDSCauHoi(monHoc->monHoc.danhSachCauHoi, trang);
			strcpy(tenmon, monHoc->monHoc.tenMH);
			outtextxy(145, 95, monHoc->monHoc.maMH);
			outtextxy(535, 95, monHoc->monHoc.tenMH);
		}
		
		int vt=0;
		
		int mx,my,key;
		mx=my=-1;
		key=0;
		while(1) {
		delay(0.01);
		getmouseclick(WM_LBUTTONDOWN,mx,my);
		clearmouseclick(WM_LBUTTONDOWN);
		key=MID[mx][my];
		lb:
		if(key>0)
		switch(key){
			case 41:{		
				ScannerMa(mamon,20,140+5,90+5,key,key);
				monHoc = timKiemMonHoc(danhSachMonHoc, mamon);
				if(monHoc!=NULL){
					bangcauhoi(trang);
					inDSCauHoi(monHoc->monHoc.danhSachCauHoi, trang);
					strcpy(tenmon, monHoc->monHoc.tenMH);
					outtextxy(535, 95, monHoc->monHoc.tenMH);
				}
				goto lb;
				break;
			}
			case 43:{
				ScannerString(cauhoi,500,130+5,125+5,key,key);
				goto lb;
				break;
			}
			case 431:{
				ScannerString(dapanA,500,130+5,160+5,key,key);
				goto lb;
				break;
			}
			case 432:{
				ScannerString(dapanB,500,130+5,195+5,key,key);
				goto lb;
				break;
			}
			case 433:{
				ScannerString(dapanC,500,130+5,230+5,key,key);
				goto lb;
				break;
			}
			case 434:{
				ScannerString(dapanD,500,130+5,265+5,key,key);
				goto lb;
				break;
			}
			case 44:{
				// luu
				if(strlen(mamon)==0 || strlen(cauhoi)==0 || strlen(dapanA)==0 || strlen(dapanB)==0 || strlen(dapanC)==0 || strlen(dapanD)==0){
					clearLoi(15, 670);
					inLoi(15, 670,"Phai dien du thong tin");
					break;
				}
				monHoc = timKiemMonHoc(danhSachMonHoc, mamon);
				if(!isEdit){
					if(monHoc!=NULL){
						themCauHoiVaoMonHoc(danhSachMonHoc, taoCauHoi(cauhoi, dapanA, dapanB, dapanC, dapanD, 'A'), mamon);
						bangcauhoi(trang);
						inDSCauHoi(monHoc->monHoc.danhSachCauHoi, trang);
						clearThongTinCauHoi();
						strcpy(cauhoi,"");
						strcpy(dapanA,"");
						strcpy(dapanB,"");
						strcpy(dapanC,"");
						strcpy(dapanD,"");
						ghiFileDSMonHoc(danhSachMonHoc);
						isEdit=false;
						clearLoi(15, 670);
					}
					else{
						clearLoi(15, 670);
						inLoi(15, 670,"Mon hoc khong ton tai");
					}
				}
				else{
					if(monHoc!=NULL){
						hieuChinhCauHoiTrongMonHoc(danhSachMonHoc, vt-1, mamon, cauhoi, dapanA, dapanB, dapanC, dapanD, 'A');
						bangcauhoi(trang);
						inDSCauHoi(monHoc->monHoc.danhSachCauHoi, trang);
						clearThongTinCauHoi();
						strcpy(cauhoi,"");
						strcpy(dapanA,"");
						strcpy(dapanB,"");
						strcpy(dapanC,"");
						strcpy(dapanD,"");
						ghiFileDSMonHoc(danhSachMonHoc);
						isEdit=false;
						clearLoi(15, 670);
					}
					else{
						clearLoi(15, 670);
						inLoi(15, 670,"Mon hoc khong ton tai");
					}
				}
					
				break;
			}
			case 45:{//xoa
				if(isEdit){
					if(monHoc!=NULL){
						xoaCauHoiTrongMonHoc(danhSachMonHoc, vt-1, mamon);
						bangcauhoi(trang);
						inDSCauHoi(monHoc->monHoc.danhSachCauHoi, trang);
						clearThongTinCauHoi();
						strcpy(cauhoi,"");
						strcpy(dapanA,"");
						strcpy(dapanB,"");
						strcpy(dapanC,"");
						strcpy(dapanD,"");
						ghiFileDSMonHoc(danhSachMonHoc);
						isEdit=false;
						clearLoi(15, 670);
					}
					else{
						clearLoi(15, 670);
						inLoi(15, 670,"Mon hoc khong ton tai");
					}
				}
					
				break;
			}
			case 46:{
				// lui trang
				if(trang>1) trang--;
				bangcauhoi(trang);
				if(monHoc!=NULL){
					inDSCauHoi(monHoc->monHoc.danhSachCauHoi, trang);
				}
				break;
			}
			case 47:{
			    trang++;
				bangcauhoi(trang);
				if(monHoc!=NULL){
					inDSCauHoi(monHoc->monHoc.danhSachCauHoi, trang);
				}
				break;
			}
		 
		
			case 4001: case 4002: case 4003: case 4004: case 4005: case 4006: case 4007: case 4008: case 4009: case 4010: { 
//				cap nhat lai du kien thong tin ten lop va ma lop
				vt = key-4000+(trang-1)*10;
				if(monHoc==NULL) break;
				if(vt==0) break;
				if(vt>monHoc->monHoc.danhSachCauHoi.soLuong) break;
				clearThongTinCauHoi();
				CauHoi cauHoi = timCauHoi(monHoc->monHoc.danhSachCauHoi, vt-1);
				layThongTinCauHoi(cauHoi);
				strcpy(cauhoi, cauHoi.noiDung);
				strcpy(dapanA, cauHoi.dapAnA);
				strcpy(dapanB, cauHoi.dapAnB);
				strcpy(dapanC, cauHoi.dapAnC);
				strcpy(dapanD, cauHoi.dapAnD);
				isEdit=true;
				break;
			}
			default:{
				if(key==1||key==2||key==3||key==4||key==5||key==6)
				return key;
			}
		}
}}
int RunQuanlyMonhoc(DanhSachMonHoc &danhSachMonHoc){ 
        char mamon[14]="";
        char tenmon[30]="";
	    int trang =1;
	    
	    bool isEdit=false;
	    
	    MonHoc *mangMonHoc=NULL;
	    int nMonHoc = 0;
	    
		menuchinh(3);
		khungquanlymonhoc();
		inDSMonHoc(danhSachMonHoc, mangMonHoc, nMonHoc, trang);
		int mx,my,key;
		mx=my=-1;
		key=0;
		while(1) {
		delay(0.01);
		getmouseclick(WM_LBUTTONDOWN,mx,my);
		clearmouseclick(WM_LBUTTONDOWN);
		key=MID[mx][my];
		lb:
		if(key>0)
		switch(key){
			case 31:{
				ScannerMa(mamon,20,140+5,90+5,key,key);
				goto lb;
				break;
			}
			case 32:{
				ScannerString(tenmon,50,140+5,130+5,key,key);
				goto lb;
				break;
			}
			case 33:{
				/// ham luu
				if(strlen(mamon)==0 || strlen(tenmon)==0){
					clearLoi();
					inLoi("Phai dien du thong tin");
					break;
				}
				if(!isEdit){
					if(timKiemMonHoc(danhSachMonHoc, mamon)==NULL){
						themNodeVaoCay(danhSachMonHoc, taoMonHocMoi(mamon, tenmon));
						bangmonhoc(trang);
						inDSMonHoc(danhSachMonHoc, mangMonHoc, nMonHoc, trang);
						clearThongTinMonHoc();
						strcpy(mamon, "");
						strcpy(tenmon,"");
						ghiFileDSMonHoc(danhSachMonHoc);
						isEdit = false;
						clearLoi();
					}
					else{
						clearLoi();
						inLoi("Mon hoc da ton tai");
					}
				}
				else{
					if(timKiemMonHoc(danhSachMonHoc, mamon)==NULL){
						clearLoi();
						inLoi("Mon hoc khong ton tai");
					}
					else{
						hieuChinhMonHocTheoMa(danhSachMonHoc, mamon, tenmon);
						bangmonhoc(trang);
						inDSMonHoc(danhSachMonHoc, mangMonHoc, nMonHoc, trang);
						clearThongTinMonHoc();
						strcpy(mamon, "");
						strcpy(tenmon,"");
						ghiFileDSMonHoc(danhSachMonHoc);
						isEdit = false;
						clearLoi();
					}
				}
					
				break;
			}
			case 34:{
				// xoa
				if(strlen(mamon)==0){
					clearLoi();
					inLoi("Chon mon hoc muon xoa");
					break;
				}
				if(kiemTraXoaMonHoc(danhSachMonHoc, mamon)){
					xoaNodeKhoiCayTheoMa(danhSachMonHoc, mamon);
					clearThongTinMonHoc();
					bangmonhoc(trang);
					inDSMonHoc(danhSachMonHoc, mangMonHoc, nMonHoc, trang);
					strcpy(mamon,"");
					strcpy(tenmon,"");
					ghiFileDSMonHoc(danhSachMonHoc);
					isEdit=false;
					clearLoi();
				}
				else{
					clearLoi();
					inLoi("Khong the xoa mon nay");
				}
				break;
			}
			case 35:{
				// lui trang
				if(trang>1) trang--;
				bangmonhoc(trang);
				inDSMonHoc(danhSachMonHoc, mangMonHoc, nMonHoc, trang);
				break;
			}
			case 36:{
			    trang++;
				bangmonhoc(trang);
				inDSMonHoc(danhSachMonHoc, mangMonHoc, nMonHoc, trang);
				break;
			}
			case 37:{
				RunQuanlycauhoi(danhSachMonHoc, mamon);
				break;
			} 
			case 99:{
				run();
				break;
			}
			case 3001: case 3002: case 3003: case 3004: case 3005: case 3006: case 3007: case 3008: case 3009: case 3010: case 3011: case 3012: case 3013: case 3014: case 3015:{ 
//				cap nhat lai du kien thong tin ten lop va ma lop
				int vt = key-3000+(trang-1)*15;
				if(vt==0) break;
				if(vt>nMonHoc) break;
				clearThongTinMonHoc();
				layThongTinMonHoc(mangMonHoc[vt-1]);
				strcpy(mamon, mangMonHoc[vt-1].maMH);
				strcpy(tenmon, mangMonHoc[vt-1].tenMH);
				isEdit=true;
				break;
			}
			default:{
				if(key==1||key==2||key==3||key==4||key==5||key==6)
				return key;
			}
		}
}}
int Runthithu(DanhSachMonHoc &danhSachMonHoc){
  		menuchinh(6);
		khungthi(0, NULL, "", "", "", "", false);
		int trang =1;
		char Mamon[14]="";
	    char sltc[50]="";
    	char Time[50]="";
    	char ketQuaThi[10]="";
    	
    	int *id=NULL;
    	DanhSachCauHoi danhSachCauHoi;
    	int nCauHoi=0;
    	int **dsSXDapAn = NULL;
    	char *dsDapAn=NULL;
    	int diem = 0;
    	
    	Hour h;
    	h.hour=0;
    	h.minute=0;
    	h.second=0;
    	int stt = 0;
    	char a[8] = { '0','0',':','0','0',':','0','0'};
    	insertarray(a, &h);
//		outtextxy(145, 212, a);
		int tik = 0;
		
    	int vt=0;
    	
    	int mx,my,key;
		mx=my=-1;
		key=0;
		while(1) {
			
			while(!ismouseclick(WM_LBUTTONDOWN) && stt==1) {
				tik++;
				if(tik==60){
					tik=0;
					if (!changetime(&h)){
						stt=-1;
						
						for(int i=0; i<nCauHoi; i++){
							if(dsDapAn[i]!=' '){
								if(dsSXDapAn[i][(int)dsDapAn[i]-'A']==0){
									diem++;
								}
							}
						}
						
						char ketQua[10]="";
						char cDiem[5] = "", cNCauHoi[10]="";
						doiSangChuoi(cDiem, diem);
						doiSangChuoi(cNCauHoi, nCauHoi);
						strcpy(ketQua, cDiem);
						strcat(ketQua, "/");
						strcat(ketQua, cNCauHoi);
						
						outtextxy(145, 252, ketQua);
						
						strcpy(ketQuaThi, ketQua);
						
					}
					insertarray(a, &h);
				}
				setbkcolor(9);
				outtextxy(145, 212, a);//in time
				delay(0.001);
			}
			
		delay(0.01);
		getmouseclick(WM_LBUTTONDOWN,mx,my);
		clearmouseclick(WM_LBUTTONDOWN);
		key=MID[mx][my];
		if(mx>=400&&mx<=1340&&my>500&&my<680) key=60;
	
		lb:
		if(key>0){ cout<<key;
		switch(key){
			case 99:{
				run();
				break;
			}
			case 62:{
				ScannerMa(Mamon,20,145,132,key,key);
			//	outtextxy(480,620,timKiemMonHoc(danhSachMonHoc,Mamon)->monHoc.tenMH);
				goto lb;
				break;
			}
			case 63:{//soluong cau hoi
				ScannerNum(sltc,5,145,172,key,key);
				goto lb;
				break;
			}
			case 64:{//thoi gian
				ScannerNum(Time,10,145,212,key,key);
				goto lb;
				break;
			}
			case 66:{
				//Bat dau
				if(strlen(Mamon)==0 || strlen(sltc)==0 || strlen(Time)==0){
					clearLoi();
					inLoi("Khong duoc bo trong");
					break;
				}
				NodeMonHoc *monHocTimThay = timKiemMonHoc(danhSachMonHoc, Mamon);
				if(monHocTimThay==NULL){
					clearLoi();
					inLoi("Khong tim thay mon");
					break;
				}
				if(doiSangSo(sltc)>monHocTimThay->monHoc.danhSachCauHoi.soLuong){
					clearLoi();
					inLoi("SL khong dap ung du");
					break;
				}
				if(stt==0){
					danhSachCauHoi = monHocTimThay->monHoc.danhSachCauHoi;
					id = layNgauNhienCauHoi(danhSachMonHoc, doiSangSo(sltc), Mamon);
					nCauHoi = doiSangSo(sltc);
					int min = doiSangSo(Time);
					h.hour = floor(min/60);
					h.minute = min%60;
					h.second = 0;
					dsSXDapAn = sapXepThuTuDapAn(nCauHoi);
					dsDapAn = new char[nCauHoi];
					for(int i=0; i<nCauHoi; i++){
						dsDapAn[i]=' ';
					}
					doiSangChuoi(sltc, nCauHoi);
					khungthi(nCauHoi, dsDapAn, timKiemMonHoc(danhSachMonHoc, Mamon)->monHoc.tenMH, Mamon, sltc, "", false);
					hienThiCauHoi(danhSachCauHoi.danhSachCauHoi[id[vt]], vt+1, dsSXDapAn[vt], dsDapAn[vt]);
					stt=1;
				}
				break;
			}
			case 67:{
				//Nop bai
				if(stt==1){
					stt=-1;
					
					for(int i=0; i<nCauHoi; i++){
						if(dsDapAn[i]!=' '){
							if(dsSXDapAn[i][(int)dsDapAn[i]-'A']==0){
								diem++;
							}
						}
					}
					
					char ketQua[10]="";
					char cDiem[5] = "", cNCauHoi[10]="";
					doiSangChuoi(cDiem, diem);
					doiSangChuoi(cNCauHoi, nCauHoi);
					strcpy(ketQua, cDiem);
					strcat(ketQua, "/");
					strcat(ketQua, cNCauHoi);
					
					outtextxy(145, 252, ketQua);
					
					strcpy(ketQuaThi, ketQua);
				}
				
				break;
			}
			case 60:{
				cout<<" vi tri cau hoi thi"<<timvitri(mx,my,nCauHoi);
				vt = timvitri(mx,my,nCauHoi)-1;
				if(vt>=0&&vt<=nCauHoi) {
				khungthi(nCauHoi, dsDapAn, timKiemMonHoc(danhSachMonHoc, Mamon)->monHoc.tenMH, Mamon, sltc, ketQuaThi, false);
				hienThiCauHoi(danhSachCauHoi.danhSachCauHoi[id[vt]], vt+1, dsSXDapAn[vt], dsDapAn[vt]);}
				break;
			}
			case 611:{
				if(stt==1){
					button(405,180,445,210,611,"A",2,14,0);
					button(405,180+77,445,210+77,612,"B",2,9,0);
					button(405,180+77+77,445,210+77+77,613,"C",2,9,0);
					button(405,180+77+77+77,445,210+77+77+77,614,"D",2,9,0);
					dsDapAn[vt]='A';
					khungthi(nCauHoi, dsDapAn, timKiemMonHoc(danhSachMonHoc, Mamon)->monHoc.tenMH, Mamon, sltc, "", false);
					hienThiCauHoi(danhSachCauHoi.danhSachCauHoi[id[vt]], vt+1, dsSXDapAn[vt], dsDapAn[vt]);
				}
				break;
			}
			case 612:{
				if(stt==1){
					button(405,180,445,210,611,"A",2,9,0);
					button(405,180+77,445,210+77,612,"B",2,14,0);
					button(405,180+77+77,445,210+77+77,613,"C",2,9,0);
					button(405,180+77+77+77,445,210+77+77+77,614,"D",2,9,0);
					dsDapAn[vt]='B';
					khungthi(nCauHoi, dsDapAn, timKiemMonHoc(danhSachMonHoc, Mamon)->monHoc.tenMH, Mamon, sltc, "", false);
					hienThiCauHoi(danhSachCauHoi.danhSachCauHoi[id[vt]], vt+1, dsSXDapAn[vt], dsDapAn[vt]);
				}
				break;
			}
			case 613:{
				if(stt==1){
					button(405,180,445,210,611,"A",2,9,0);
					button(405,180+77,445,210+77,612,"B",2,9,0);
					button(405,180+77+77,445,210+77+77,613,"C",2,14,0);
					button(405,180+77+77+77,445,210+77+77+77,614,"D",2,9,0);
					dsDapAn[vt]='C';
					khungthi(nCauHoi, dsDapAn, timKiemMonHoc(danhSachMonHoc, Mamon)->monHoc.tenMH, Mamon, sltc, "", false);
					hienThiCauHoi(danhSachCauHoi.danhSachCauHoi[id[vt]], vt+1, dsSXDapAn[vt], dsDapAn[vt]);
				}
				break;
			}
			case 614:{
				if(stt==1){
					button(405,180,445,210,611,"A",2,9,0);
					button(405,180+77,445,210+77,612,"B",2,9,0);
					button(405,180+77+77,445,210+77+77,613,"C",2,9,0);
					button(405,180+77+77+77,445,210+77+77+77,614,"D",2,14,0);
					dsDapAn[vt]='D';
					khungthi(nCauHoi, dsDapAn, timKiemMonHoc(danhSachMonHoc, Mamon)->monHoc.tenMH, Mamon, sltc, "", false);
					hienThiCauHoi(danhSachCauHoi.danhSachCauHoi[id[vt]], vt+1, dsSXDapAn[vt], dsDapAn[vt]);
				}
				break;
			}
			default:{
				if(key==1||key==2||key==3||key==4||key==5||key==6)
				return key;
			}}
		}}
}
void runADMIN(DanhSachLop &danhSachLop, DanhSachMonHoc &danhSachMonHoc){
	    menuchinh(1);
		khungquanlylop();
		
		int mx,my,key;
		mx=my=-1;
		key=1;
		goto lb;
		while(1) {
		delay(0.01);
		getmouseclick(WM_LBUTTONDOWN,mx,my);
		clearmouseclick(WM_LBUTTONDOWN);
		key=MID[mx][my];
		lb:
		if(key>0)
		switch(key){
			case 1:{
				menuchinh(key);
				khungquanlylop();
				key=RunQLLop(danhSachLop, danhSachMonHoc);
				goto lb;
				break;
			}
			case 2:{
				char *malop="";
			   	menuchinh(key);
			   	khungquanlysinhvien();
			   	key=RunQLSinhVien(danhSachLop, malop, danhSachMonHoc);
			   	goto lb;
				break;
			}
			case 3:{
				menuchinh(key);
				khungquanlymonhoc();
			    key=RunQuanlyMonhoc(danhSachMonHoc);
			    goto lb;
				break;
			}
			case 4:{
				menuchinh(key);
			   	khungquanlycauhoi();
			   	key=RunQuanlycauhoi(danhSachMonHoc, "");
				break;
			}
			case 5:{
//				menuchinh(key);
//				khungquanlybode();
//				key = RunQLbode(danhSachDeThi, danhSachMonHoc);
//				break;
			}
			case 6:{
				menuchinh(key);
				khungthi(0, NULL, "", "", "", "", false);
				key = Runthithu(danhSachMonHoc);
				break;
			}
		}
       }
}
void runSinhvien(char *nguoidung, DanhSachMonHoc &danhSachMonHoc, DanhSachLop &danhSachLopHoc, DanhSachChiTietBaiThi &danhSachChiTietBaiThi){
		setbkcolor(15);					// set background
   		cleardevice();

	   	setcolor(0);
	   	setbkcolor(15);
	   	settextstyle(0,0,2);
	   	NodeSinhVien *sinhVien = timKiemTrongTatCaSinhVien(danhSachLopHoc, nguoidung);
	   	outtextxy(10,5,"MSSV:");
	   	outtextxy(100,5,sinhVien->sinhVien.maSV);
	   	char hoTen[60]="";
	   	strcpy(hoTen, sinhVien->sinhVien.ho);
	   	strcat(hoTen, " ");
	   	strcat(hoTen, sinhVien->sinhVien.ten);
	    outtextxy(400,5,"HO TEN:");
	  
    	outtextxy(550,5,hoTen);
		
		khungthi(0, NULL, "", "", "", "", true);
		int trang =1;
		char Mamon[14]="";
	    char sltc[50]="";
    	char Time[50]="";
    	char ketQuaThi[10]="";
    	
    	int *id=NULL;
    	DanhSachCauHoi danhSachCauHoi;
    	int nCauHoi=0;
    	int **dsSXDapAn = NULL;
    	char *dsDapAn=NULL;
    	int diem = 0;
    	
    	Hour h;
    	h.hour=0;
    	h.minute=0;
    	h.second=0;
    	int stt = 0;
    	char a[8] = { '0','0',':','0','0',':','0','0'};
    	insertarray(a, &h);
//		outtextxy(145, 212, a);
		int tik = 0;
		
    	int vt=0;
    	
    	
    	int mx,my,key;
		mx=my=-1;
		key=0;
		while(1) {
			
			while(!ismouseclick(WM_LBUTTONDOWN) && stt==1) {
				tik++;
				if(tik==60){
					tik=0;
					if (!changetime(&h)){
						stt=-1;
						
						for(int i=0; i<nCauHoi; i++){
							if(dsDapAn[i]!=' '){
								if(dsSXDapAn[i][(int)dsDapAn[i]-'A']==0){
									diem++;
								}
							}
						}
						
						char ketQua[10]="";
						char cDiem[5] = "", cNCauHoi[10]="";
						doiSangChuoi(cDiem, diem);
						doiSangChuoi(cNCauHoi, nCauHoi);
						strcpy(ketQua, cDiem);
						strcat(ketQua, "/");
						strcat(ketQua, cNCauHoi);
						
						outtextxy(145, 252, ketQua);
						
						strcpy(ketQuaThi, ketQua);
						
						float diemFloat = ((float)diem/nCauHoi)*10.0;
						float timD = timDiem(sinhVien->sinhVien.danhSachDiem, Mamon);
						if(timD==-1){
							themDiemVaoSinhVienTrongCacLop(danhSachLopHoc, nguoidung, taoDiem(Mamon, diemFloat));
							ghiFileDSLopSVDiem(danhSachLopHoc);
						}
						else if(timD<diemFloat){
							suaDiemVaoSinhVienTrongCacLop(danhSachLopHoc, nguoidung, Mamon, diemFloat);
							ghiFileDSLopSVDiem(danhSachLopHoc);
						}
						
						themChiTiet(danhSachChiTietBaiThi, taoChiTietBaiThi(nguoidung, Mamon, doiSangSo(sltc), doiSangSo(Time), danhSachCauHoi, id, dsSXDapAn, dsDapAn));
						ghiFileChiTiet(danhSachChiTietBaiThi);
						
					}
					insertarray(a, &h);
				}
				setbkcolor(9);
				outtextxy(145, 212, a);
				delay(0.001);
			}
			
		delay(0.01);
		getmouseclick(WM_LBUTTONDOWN,mx,my);
		clearmouseclick(WM_LBUTTONDOWN);
		
		key=MID[mx][my];
		if(mx>=400&&mx<=1340&&my>500&&my<680)
		key=60;
		
		lb:
		if(key>0)
		switch(key){
			case 99:{
				if(stt==1){
					stt=-1;//stt trang thai thi
					
					for(int i=0; i<nCauHoi; i++){
						if(dsDapAn[i]!=' '){
							if(dsSXDapAn[i][(int)dsDapAn[i]-'A']==0){
								diem++;
							}
						}
					}
					
					char ketQua[10]="";
					char cDiem[5] = "", cNCauHoi[10]="";
					doiSangChuoi(cDiem, diem);
					doiSangChuoi(cNCauHoi, nCauHoi);
					strcpy(ketQua, cDiem);
					strcat(ketQua, "/");
					strcat(ketQua, cNCauHoi);
					
					outtextxy(145, 252, ketQua);
					
					strcpy(ketQuaThi, ketQua);
					
					float diemFloat = ((float)diem/nCauHoi)*10.0;
					int timD = timDiem(sinhVien->sinhVien.danhSachDiem, Mamon);
					if(timD==-1){
						themDiemVaoSinhVienTrongCacLop(danhSachLopHoc, nguoidung, taoDiem(Mamon, diemFloat));
						ghiFileDSLopSVDiem(danhSachLopHoc);
					}
					else if(timD<diemFloat){
						suaDiemVaoSinhVienTrongCacLop(danhSachLopHoc, nguoidung, Mamon, diemFloat);
						ghiFileDSLopSVDiem(danhSachLopHoc);
					}
					
					themChiTiet(danhSachChiTietBaiThi, taoChiTietBaiThi(nguoidung, Mamon, nCauHoi, doiSangSo(Time), danhSachCauHoi, id, dsSXDapAn, dsDapAn));
					ghiFileChiTiet(danhSachChiTietBaiThi);
					
				}	
			run();
				}
			case 62:{
				ScannerMa(Mamon,20,145,132,key,key);
				goto lb;
				break;
			}
			case 63:{
				ScannerNum(sltc,5,145,172,key,key);
				goto lb;
				break;
			}
			case 64:{
				ScannerNum(Time,10,145,212,key,key);
				goto lb;
				break;
			}
			case 66:{
				//Bat dau
				if(strlen(Mamon)==0 || strlen(sltc)==0 || strlen(Time)==0){
					clearLoi(15,500);
					inLoi(15,500,"Khong duoc bo trong");
					break;
				}
				NodeMonHoc *monHocTimThay = timKiemMonHoc(danhSachMonHoc, Mamon);
				if(monHocTimThay==NULL){
					clearLoi(15,500);
					inLoi(15,500,"Khong tim thay mon");
					break;
				}
				if(doiSangSo(sltc)>monHocTimThay->monHoc.danhSachCauHoi.soLuong){
					clearLoi(15,500);
					inLoi(15,500,"SL khong dap ung du");
					break;
				}
				if(stt==0){
					if(timDiem(sinhVien->sinhVien.danhSachDiem, Mamon)!=-1){
						clearLoi(15,500);
						inLoi(15, 500, "SV da thi mon nay");
						break;
					}
					danhSachCauHoi = timKiemMonHoc(danhSachMonHoc, Mamon)->monHoc.danhSachCauHoi;
					id = layNgauNhienCauHoi(danhSachMonHoc, doiSangSo(sltc), Mamon);
					nCauHoi = doiSangSo(sltc);
//					strcpy(Mamon, timDeThi(danhSachDeThi, made).maMH);
					int min = doiSangSo(Time);
					h.hour = floor(min/60);
					h.minute = min%60;
					h.second = 0;
					dsSXDapAn = sapXepThuTuDapAn(nCauHoi);
					dsDapAn = new char[nCauHoi];
					for(int i=0; i<nCauHoi; i++){
						dsDapAn[i]=' ';
					}
//					doiSangChuoi(sltc, nCauHoi);
					khungthi(nCauHoi, dsDapAn, timKiemMonHoc(danhSachMonHoc, Mamon)->monHoc.tenMH, Mamon, sltc, "", true);
					hienThiCauHoi(danhSachCauHoi.danhSachCauHoi[id[vt]], vt+1, dsSXDapAn[vt], dsDapAn[vt]);
					stt=1;
					clearLoi(15,500);
				}
				break;
			}
			case 67:{
				//Nop bai
				if(stt==1){
					stt=-1;
					
					for(int i=0; i<nCauHoi; i++){
						if(dsDapAn[i]!=' '){
							if(dsSXDapAn[i][(int)dsDapAn[i]-'A']==0){
								diem++;
							}
						}
					}
					
					char ketQua[10]="";
					char cDiem[5] = "", cNCauHoi[10]="";
					doiSangChuoi(cDiem, diem);
					doiSangChuoi(cNCauHoi, nCauHoi);
					strcpy(ketQua, cDiem);
					strcat(ketQua, "/");
					strcat(ketQua, cNCauHoi);
					
					outtextxy(145, 252, ketQua);//in ra ket qua
					
					strcpy(ketQuaThi, ketQua);
					
					float diemFloat = ((float)diem/nCauHoi)*10.0;
					int timD = timDiem(sinhVien->sinhVien.danhSachDiem, Mamon);
					if(timD==-1){
						themDiemVaoSinhVienTrongCacLop(danhSachLopHoc, nguoidung, taoDiem(Mamon, diemFloat));
						ghiFileDSLopSVDiem(danhSachLopHoc);
					}
//					else if(timD<diemFloat){
//						suaDiemVaoSinhVienTrongCacLop(danhSachLopHoc, nguoidung, Mamon, diemFloat);
//						ghiFileDSLopSVDiem(danhSachLopHoc);
//					}
					
					themChiTiet(danhSachChiTietBaiThi, taoChiTietBaiThi(nguoidung, Mamon, nCauHoi, doiSangSo(Time), danhSachCauHoi, id, dsSXDapAn, dsDapAn));
					ghiFileChiTiet(danhSachChiTietBaiThi);
					
				}
				
				break;
			}
			case 68:{
				if(strlen(Mamon)==0){
					clearLoi(15,500);
					inLoi(15,500,"Nhap Ma Mon de xem");
				}
				if(stt==0){
					ChiTietBaiThi *chiTiet = timBaiThi(danhSachChiTietBaiThi, nguoidung, Mamon);
					if(chiTiet!=NULL){
						
						stt=-2;
						
						nCauHoi = chiTiet->slch;
//						std::cout<<"\nnCauHoi: "<<nCauHoi;
						xoaDanhSachCauHoi(danhSachCauHoi);
						dsDapAn = chiTiet->danhSachCauTraLoi;
//						std::cout<<"\nnDSTraLoi: ";
						for(int i=0; i<nCauHoi; i++){
							std::cout<<" "<<dsDapAn[i];
						}
						id = new int[nCauHoi];
						dsSXDapAn = new int*[nCauHoi];
						for(int i=0; i<nCauHoi; i++){
							themCauHoiVaoMang(danhSachCauHoi, chiTiet->cauHoi[i]);
							id[i]=i;
							dsSXDapAn[i] = new int[4];
							for(int j=0; j<4; j++){
								dsSXDapAn[i][j] = j;
							}
						}

						doiSangChuoi(sltc, nCauHoi);
						khungthi(nCauHoi, dsDapAn, timKiemMonHoc(danhSachMonHoc, Mamon)->monHoc.tenMH, Mamon, sltc, "", true);
						hienThiCauHoi(danhSachCauHoi.danhSachCauHoi[id[vt]], vt+1, dsSXDapAn[vt], dsDapAn[vt]);
						clearLoi(15,500);
					}
					else{
						clearLoi(15,500);
						inLoi(15,500,"Khong tim thay mon");
					}
					
				}
				break;
			}
			case 60:{
//				cout<<timvitri(mx,my,nCauHoi);
				vt = timvitri(mx,my,nCauHoi)-1;
			    if(vt>=0&&vt<=nCauHoi){
				khungthi(nCauHoi, dsDapAn, timKiemMonHoc(danhSachMonHoc, Mamon)->monHoc.tenMH, Mamon, sltc, ketQuaThi, true);
				hienThiCauHoi(danhSachCauHoi.danhSachCauHoi[id[vt]], vt+1, dsSXDapAn[vt], dsDapAn[vt]);}
				break;
			}
			case 611:{
				if(stt==1){
					button(405,180,445,210,611,"A",2,14,0);
					button(405,180+77,445,210+77,612,"B",2,9,0);
					button(405,180+77+77,445,210+77+77,613,"C",2,9,0);
					button(405,180+77+77+77,445,210+77+77+77,614,"D",2,9,0);
					dsDapAn[vt]='A';
					khungthi(nCauHoi, dsDapAn, timKiemMonHoc(danhSachMonHoc, Mamon)->monHoc.tenMH, Mamon, sltc, "", true);
					hienThiCauHoi(danhSachCauHoi.danhSachCauHoi[id[vt]], vt+1, dsSXDapAn[vt], dsDapAn[vt]);
				}
				break;
			}
			case 612:{
				if(stt==1){
					button(405,180,445,210,611,"A",2,9,0);
					button(405,180+77,445,210+77,612,"B",2,14,0);
					button(405,180+77+77,445,210+77+77,613,"C",2,9,0);
					button(405,180+77+77+77,445,210+77+77+77,614,"D",2,9,0);
					dsDapAn[vt]='B';
					khungthi(nCauHoi, dsDapAn, timKiemMonHoc(danhSachMonHoc, Mamon)->monHoc.tenMH, Mamon, sltc, "", true);
					hienThiCauHoi(danhSachCauHoi.danhSachCauHoi[id[vt]], vt+1, dsSXDapAn[vt], dsDapAn[vt]);
				}
				break;
			}
			case 613:{
				if(stt==1){
					button(405,180,445,210,611,"A",2,9,0);
					button(405,180+77,445,210+77,612,"B",2,9,0);
					button(405,180+77+77,445,210+77+77,613,"C",2,14,0);
					button(405,180+77+77+77,445,210+77+77+77,614,"D",2,9,0);
					dsDapAn[vt]='C';
					khungthi(nCauHoi, dsDapAn, timKiemMonHoc(danhSachMonHoc, Mamon)->monHoc.tenMH, Mamon, sltc, "", true);
					hienThiCauHoi(danhSachCauHoi.danhSachCauHoi[id[vt]], vt+1, dsSXDapAn[vt], dsDapAn[vt]);
				}
				break;
			}
			case 614:{
				if(stt==1){
					button(405,180,445,210,611,"A",2,9,0);
					button(405,180+77,445,210+77,612,"B",2,9,0);
					button(405,180+77+77,445,210+77+77,613,"C",2,9,0);
					button(405,180+77+77+77,445,210+77+77+77,614,"D",2,14,0);
					dsDapAn[vt]='D';
					khungthi(nCauHoi, dsDapAn, timKiemMonHoc(danhSachMonHoc, Mamon)->monHoc.tenMH, Mamon, sltc, "", true);
					hienThiCauHoi(danhSachCauHoi.danhSachCauHoi[id[vt]], vt+1, dsSXDapAn[vt], dsDapAn[vt]);
				}
				break;
			}
			
		}}
}

void run(){
	
	DanhSachLop danhSachLop;
	DanhSachMonHoc danhSachMonHoc;
	DanhSachChiTietBaiThi danhSachChiTietBaiThi;
	
	docFileLopSVDiem(danhSachLop);
	docFileDSMonHoc(danhSachMonHoc);
	docFileChiTiet(danhSachChiTietBaiThi);
	
	char *nguoidung="";
	nguoidung =	dangnhaptaikhoan(danhSachLop);
	if(strcmp(nguoidung,"GV")==0){
		runADMIN(danhSachLop, danhSachMonHoc);
	}
	else{
		runSinhvien(nguoidung, danhSachMonHoc, danhSachLop, danhSachChiTietBaiThi);
	}	
}

float **danhSachDiem(SinhVien *mangTamSV, int nSV, char dsMon[][20], int &nDSMon){
	if(mangTamSV==NULL) return NULL;
	
	nDSMon=0;
	
	for(int i=0; i<nSV; i++){
		NodeDiem *tmpDiem = mangTamSV[i].danhSachDiem.first;
		while(tmpDiem!=NULL){
			bool isExist = false;
			for(int j=0; j<nDSMon; j++){
				if(strcmp(tmpDiem->diem.maMH, dsMon[j])==0){
					isExist=true;
					break;
				}
			}
			if(isExist==false){
				strcpy(dsMon[nDSMon], tmpDiem->diem.maMH);
				nDSMon++;
			}
			
			tmpDiem = tmpDiem->next;
		}
	}
	
	std::cout<<"DS Mon:"<<std::endl;
	for(int i=0; i<nDSMon; i++){
		std::cout<<dsMon[i]<<std::endl;
	}
	
	float **dsDiem = new float*[nSV];
	for(int i=0; i<nSV; i++){
		dsDiem[i] = new float[nDSMon];
	}
	
	for(int i=0; i<nSV; i++){
		for(int j=0; j<nDSMon; j++){
			dsDiem[i][j]=-1;
		}
	}
	
	for(int i=0; i<nSV; i++){
		NodeDiem *tmpDiem = mangTamSV[i].danhSachDiem.first;
		while(tmpDiem!=NULL){
			for(int j=0; j<nDSMon; j++){
				if(strcmp(tmpDiem->diem.maMH, dsMon[j])==0){
					if(tmpDiem->diem.diem>dsDiem[i][j]){
						dsDiem[i][j] = tmpDiem->diem.diem;
					}
					break;
				}
			}
			
			tmpDiem = tmpDiem->next;
		}
	}
	
	return dsDiem;
	
}
//float **danhSachDiem(SinhVien *mangTamSV, int nSV, char dsMon[][20], int &nDSMon)
float **danhSachDiemMotMon(SinhVien *mangTamSV, int nSV, char dsMon[][20], int &nDSMon, char maMon[]){
	if(mangTamSV==NULL) return NULL;
	
	nDSMon=1;
	strcpy(dsMon[0], maMon);
	
	float **dsDiem = new float*[nSV];
	for(int i=0; i<nSV; i++){
		dsDiem[i] = new float[1];
	}
	
	for(int i=0; i<nSV; i++){
		dsDiem[i][0]=-1;
	}
	
	for(int i=0; i<nSV; i++){
		NodeDiem *tmpDiem = mangTamSV[i].danhSachDiem.first;
		while(tmpDiem!=NULL){
			if(strcmp(tmpDiem->diem.maMH, maMon)==0){
				if(tmpDiem->diem.diem>dsDiem[i][0]){
					dsDiem[i][0] = tmpDiem->diem.diem;
				}
				break;
			}
			tmpDiem = tmpDiem->next;
		}
	}
	
	return dsDiem;
	
}
