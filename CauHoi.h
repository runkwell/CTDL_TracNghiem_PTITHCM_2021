#pragma once

#include <iostream>
#include <string.h>
#include <fstream>

#define MAX 200

struct CauHoi{
	char noiDung[200];
	char dapAnA[100];
	char dapAnB[100];
	char dapAnC[100];
	char dapAnD[100];
	char dapAnDung;
};

struct DanhSachCauHoi{
	CauHoi danhSachCauHoi[MAX];
	int soLuong = 0;
};

CauHoi taoCauHoi(char noiDung[], char dapAnA[], char dapAnB[], char dapAnC[], char dapAnD[], char dapAnDung){
	CauHoi cauHoiMoi;
	strcpy(cauHoiMoi.noiDung, noiDung);
	strcpy(cauHoiMoi.dapAnA, dapAnA);
	strcpy(cauHoiMoi.dapAnB, dapAnB);
	strcpy(cauHoiMoi.dapAnC, dapAnC);
	strcpy(cauHoiMoi.dapAnD, dapAnD);
	cauHoiMoi.dapAnDung = dapAnDung;
	return cauHoiMoi;
}

void themCauHoiVaoMang(DanhSachCauHoi &danhSachCauHoi, CauHoi cauHoi){
//	cout<<"\ncauhoi khi them: "<<cauHoi.noiDung;
	danhSachCauHoi.danhSachCauHoi[danhSachCauHoi.soLuong++] = cauHoi;
//	cout<<"\ncauhoi khi them hàm Cau Hoi: "<<danh;
}

CauHoi timCauHoi(DanhSachCauHoi &danhSachCauHoi, int viTri){
	
	if(viTri<0 || viTri>=danhSachCauHoi.soLuong){
		return taoCauHoi("","","","","",'0');
	}
	
	return danhSachCauHoi.danhSachCauHoi[viTri];
	
}

void hieuChinhCauHoi(DanhSachCauHoi &danhSachCauHoi, char noiDung[], char dapAnA[], char dapAnB[], char dapAnC[], char dapAnD[], char dapAnDung, int viTri){
	if(viTri<0 || viTri>=danhSachCauHoi.soLuong){
		return;
	}
	
	strcpy(danhSachCauHoi.danhSachCauHoi[viTri].noiDung, noiDung);
	strcpy(danhSachCauHoi.danhSachCauHoi[viTri].dapAnA, dapAnA);
	strcpy(danhSachCauHoi.danhSachCauHoi[viTri].dapAnB, dapAnB);
	strcpy(danhSachCauHoi.danhSachCauHoi[viTri].dapAnC, dapAnC);
	strcpy(danhSachCauHoi.danhSachCauHoi[viTri].dapAnD, dapAnD);
	danhSachCauHoi.danhSachCauHoi[viTri].dapAnDung = dapAnDung;
	
}

void xoaCauHoi(DanhSachCauHoi &danhSachCauHoi, int viTri){
	if(viTri<0 || viTri>=danhSachCauHoi.soLuong){
		return;
	}
	for(int i=viTri; i<danhSachCauHoi.soLuong-1; i++){
		danhSachCauHoi.danhSachCauHoi[i] = danhSachCauHoi.danhSachCauHoi[i+1];
	}
	danhSachCauHoi.soLuong--;
}

void xoaDanhSachCauHoi(DanhSachCauHoi &danhSachCauHoi){
	danhSachCauHoi.soLuong=0;
}
