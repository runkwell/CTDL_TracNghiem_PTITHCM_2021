#pragma once
#include "MonHoc.h"
#include <fstream>
#include <cstdlib>
#include <ctime>

int *taoMangNguyenNgauNhienNPhanTu(int n, int max){//boc ngau nhien cau hoi vd 5/7 
	int *mang = new int[max];//mang dong
	for(int i=0; i<max-1; i++){
		mang[i]=i;
	}
	srand(time(NULL));
	
	for(int i=max-2; i>=0; i--){
		int j = rand() % (i+1);// sinh so ngau nhien tu 0 toi i
		int tmp = mang[j];
		mang[j] = mang[i];
		mang[i]= tmp;
	}
	int *ketQua = new int[n];
	for(int i=0; i<n; i++){
		ketQua[i]=mang[i];
	}
	delete[] mang;
	return ketQua;
}

int *layNgauNhienCauHoi(DanhSachMonHoc &danhSachMonHoc, int soLuongCauHoi, char maMH[]){//mang dong 2 chieu
	return taoMangNguyenNgauNhienNPhanTu(soLuongCauHoi, timKiemMonHoc(danhSachMonHoc, maMH)->monHoc.danhSachCauHoi.soLuong);
}

int **sapXepThuTuDapAn(int soLuong){ // dao dap an
	
	srand(time(NULL));
	
	int **dsSX = new int*[soLuong];
	for(int i=0; i<soLuong; i++){
		dsSX[i] = new int[4];
		for(int j=0; j<4; j++){
			dsSX[i][j]=j;
		}
		
		for(int j=3; j>=0; j--){
			int k = rand() % (j+1);
			int tmp = dsSX[i][k];
			dsSX[i][k] = dsSX[i][j];
			dsSX[i][j]= tmp;
		}
	}
	
	return dsSX;
}
