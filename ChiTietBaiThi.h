#pragma once
#include <fstream>
#include "CauHoi.h"
#include "De.h"

#define MAXCHITIET 10000

struct ChiTietBaiThi{
	char maSV[15];
	char maMH[15];
	int slch;
	int thoiGian;
	CauHoi *cauHoi;
	char *danhSachCauTraLoi;//trong diem, t?o 2 bien chua ds cau hoi, ds cau tra loi
};

struct DanhSachChiTietBaiThi{
	ChiTietBaiThi *danhSach[MAXCHITIET];//mang con tro
	int soLuong=0;
};

ChiTietBaiThi taoChiTietBaiThi(char maSV[], char maMH[], int slch, int thoiGian, DanhSachCauHoi &danhSachCauHoi,
 int *danhSachCHThi, int **danhSachSXThuTuDapAn, char *danhSachTraLoi){
	ChiTietBaiThi chiTiet;
	strcpy(chiTiet.maSV, maSV);
	strcpy(chiTiet.maMH, maMH);
	chiTiet.slch=slch;
	chiTiet.thoiGian=thoiGian;
	chiTiet.danhSachCauTraLoi = danhSachTraLoi;
	
	int n = slch;
	chiTiet.cauHoi = new CauHoi[n];
	for(int i=0; i<n; i++){
		CauHoi tmpCauHoi = danhSachCauHoi.danhSachCauHoi[danhSachCHThi[i]];
		
		char noidung[200]="", dapAnA[100]="", dapAnB[100]="", dapAnC[100]="", dapAnD[100]="", dapAnDung=' ';
		strcpy(noidung, tmpCauHoi.noiDung);
		
		if(danhSachSXThuTuDapAn[i][0]==0){
			strcpy(dapAnA, tmpCauHoi.dapAnA);
			dapAnDung='A';
		}
		else if(danhSachSXThuTuDapAn[i][0]==1){
			strcpy(dapAnA, tmpCauHoi.dapAnB);
		}
		else if(danhSachSXThuTuDapAn[i][0]==2){
			strcpy(dapAnA, tmpCauHoi.dapAnC);
		}
		else if(danhSachSXThuTuDapAn[i][0]==3){
			strcpy(dapAnA, tmpCauHoi.dapAnD);
		}
		
		if(danhSachSXThuTuDapAn[i][1]==0){
			strcpy(dapAnB, tmpCauHoi.dapAnA);
			dapAnDung='B';
		}
		else if(danhSachSXThuTuDapAn[i][1]==1){
			strcpy(dapAnB, tmpCauHoi.dapAnB);
		}
		else if(danhSachSXThuTuDapAn[i][1]==2){
			strcpy(dapAnB, tmpCauHoi.dapAnC);
		}
		else if(danhSachSXThuTuDapAn[i][1]==3){
			strcpy(dapAnB, tmpCauHoi.dapAnD);
		}
		
		if(danhSachSXThuTuDapAn[i][2]==0){
			strcpy(dapAnC, tmpCauHoi.dapAnA);
			dapAnDung='C';
		}
		else if(danhSachSXThuTuDapAn[i][2]==1){
			strcpy(dapAnC, tmpCauHoi.dapAnB);
		}
		else if(danhSachSXThuTuDapAn[i][2]==2){
			strcpy(dapAnC, tmpCauHoi.dapAnC);
		}
		else if(danhSachSXThuTuDapAn[i][2]==3){
			strcpy(dapAnC, tmpCauHoi.dapAnD);
		}
		
		if(danhSachSXThuTuDapAn[i][3]==0){
			strcpy(dapAnD, tmpCauHoi.dapAnA);
			dapAnDung='D';
		}
		else if(danhSachSXThuTuDapAn[i][3]==1){
			strcpy(dapAnD, tmpCauHoi.dapAnB);
		}
		else if(danhSachSXThuTuDapAn[i][3]==2){
			strcpy(dapAnD, tmpCauHoi.dapAnC);
		}
		else if(danhSachSXThuTuDapAn[i][3]==3){
			strcpy(dapAnD, tmpCauHoi.dapAnD);
		}
		
		chiTiet.cauHoi[i] = taoCauHoi(noidung, dapAnA, dapAnB, dapAnC, dapAnD, dapAnDung);
	}
	
	return chiTiet;
	
}

ChiTietBaiThi *timBaiThi(DanhSachChiTietBaiThi &danhSachChiTietBaiThi, char maSV[], char maMon[]){
	for(int i=0; i<danhSachChiTietBaiThi.soLuong; i++){
		if(strcmp(danhSachChiTietBaiThi.danhSach[i]->maSV, maSV)==0 && strcmp(danhSachChiTietBaiThi.danhSach[i]->maMH, maMon)==0){
			return danhSachChiTietBaiThi.danhSach[i];
		}
	}
	return NULL;
}

void themChiTiet(DanhSachChiTietBaiThi &danhSachChiTietBaiThi, ChiTietBaiThi chiTiet){
	
	danhSachChiTietBaiThi.danhSach[danhSachChiTietBaiThi.soLuong] = new ChiTietBaiThi;
	*danhSachChiTietBaiThi.danhSach[danhSachChiTietBaiThi.soLuong++] = chiTiet;
	
}

//void xoaDanhSachChiTietBaiThi(DanhSachChiTietBaiThi &danhSachChiTietBaiThi){
//	for(int i=0; i<danhSachChiTietBaiThi.soLuong; i++){
//		delete[] danhSachChiTietBaiThi.danhSach[i]->cauHoi;
//		delete[] danhSachChiTietBaiThi.danhSach[i]->danhSachCauTraLoi;
//		delete danhSachChiTietBaiThi.danhSach[i];
//	}
//}

void ghiFileChiTiet(DanhSachChiTietBaiThi &danhSachChiTietBaiThi){
	
	std::fstream file;
	
	file.open("ChiTietDeThi.txt", std::ios::out);
	
	for(int i=0; i<danhSachChiTietBaiThi.soLuong; i++){
		file<<danhSachChiTietBaiThi.danhSach[i]->maSV<<std::endl;
		file<<danhSachChiTietBaiThi.danhSach[i]->maMH<<std::endl;
		
		int n = danhSachChiTietBaiThi.danhSach[i]->slch;
		file<<n<<std::endl;
		
		for(int j=0; j<n; j++){
			file<<danhSachChiTietBaiThi.danhSach[i]->cauHoi[j].noiDung<<std::endl;
			file<<danhSachChiTietBaiThi.danhSach[i]->cauHoi[j].dapAnA<<std::endl;
			file<<danhSachChiTietBaiThi.danhSach[i]->cauHoi[j].dapAnB<<std::endl;
			file<<danhSachChiTietBaiThi.danhSach[i]->cauHoi[j].dapAnC<<std::endl;
			file<<danhSachChiTietBaiThi.danhSach[i]->cauHoi[j].dapAnD<<std::endl;
			file<<danhSachChiTietBaiThi.danhSach[i]->cauHoi[j].dapAnDung<<std::endl;
			file<<((danhSachChiTietBaiThi.danhSach[i]->danhSachCauTraLoi[j]==' ')?'-':danhSachChiTietBaiThi.danhSach[i]->danhSachCauTraLoi[j])<<std::endl;
		}	
	}
	
	file.close();
	
}

void docFileChiTiet(DanhSachChiTietBaiThi &danhSachChiTietBaiThi){
	
	std::fstream file;
	
	file.open("ChiTietDeThi.txt", std::ios::in);
	
	if(file==NULL) return;
	
//	xoaDanhSachChiTietBaiThi(danhSachChiTietBaiThi);
	
	ChiTietBaiThi chiTiet;
	while(file.getline(chiTiet.maSV, sizeof(chiTiet.maSV), '\n')){
		if(strlen(chiTiet.maSV)==0) break;
		
		file.getline(chiTiet.maMH, sizeof(chiTiet.maMH), '\n');
		
//		int n = timDeThi(danhSachDe, chiTiet.maDe).slch;
		int n=0;
		file>>n;
		file.ignore();
		chiTiet.slch=n;
		chiTiet.cauHoi = new CauHoi[n];
		chiTiet.danhSachCauTraLoi = new char[n];
		for(int j=0; j<n; j++){
			file.getline(chiTiet.cauHoi[j].noiDung, sizeof(chiTiet.cauHoi[j].noiDung), '\n');
			file.getline(chiTiet.cauHoi[j].dapAnA, sizeof(chiTiet.cauHoi[j].dapAnA), '\n');
			file.getline(chiTiet.cauHoi[j].dapAnB, sizeof(chiTiet.cauHoi[j].dapAnB), '\n');
			file.getline(chiTiet.cauHoi[j].dapAnC, sizeof(chiTiet.cauHoi[j].dapAnC), '\n');
			file.getline(chiTiet.cauHoi[j].dapAnD, sizeof(chiTiet.cauHoi[j].dapAnD), '\n');
			file>>chiTiet.cauHoi[j].dapAnDung;
			file.ignore();
			file>>chiTiet.danhSachCauTraLoi[j];
			if(chiTiet.danhSachCauTraLoi[j]=='-'){
				chiTiet.danhSachCauTraLoi[j]=' ';
			}
			file.ignore();
		}
		
//		std::cout<<"\nDoc:"<<endl;
//		std::cout<<"MASV:"<<chiTiet.maSV<<endl;
//		std::cout<<"MADE:"<<chiTiet.maDe<<endl;
//		std::cout<<"DS CAU HOI: "<<endl;
//		for(int i=0; i<5; i++){
//			std::cout<<"Noi dung: "<<chiTiet.cauHoi[i].noiDung<<endl;
//		}
		
		themChiTiet(danhSachChiTietBaiThi, chiTiet);
	}
	
	file.close();
	
//	std::cout<<"\nFile:"<<endl;
//	std::cout<<"MASV:"<<danhSachChiTietBaiThi.danhSach[0]->maSV<<endl;
//	std::cout<<"MADE:"<<danhSachChiTietBaiThi.danhSach[0]->maDe<<endl;
//	std::cout<<"DS CAU HOI: "<<endl;
//	for(int i=0; i<timDeThi(danhSachDe, danhSachChiTietBaiThi.danhSach[0]->maDe).slch; i++){
//		std::cout<<"Noi dung: "<<danhSachChiTietBaiThi.danhSach[0]->cauHoi[i].noiDung<<endl;
//	}
}
