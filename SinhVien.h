#pragma once
#include "Diem.h"
#include <iostream>
using namespace std;
struct SinhVien{
	char maSV[15];
	char ho[10];
	char ten[50];
	char phai[5];
	char pass[20];
	DanhSachDiem danhSachDiem;
};

struct NodeSinhVien{
	SinhVien sinhVien;
	NodeSinhVien *next = NULL;
};

struct DanhSachSinhVien{
	NodeSinhVien *first = NULL;
	int soLuong= 0;
};

SinhVien taoSinhVien(char maSV[], char ho[], char ten[], char phai[], char pass[]){
	SinhVien sinhVienMoi;
	strcpy(sinhVienMoi.maSV, maSV);
	strcpy(sinhVienMoi.ho, ho);
	strcpy(sinhVienMoi.ten, ten);
	strcpy(sinhVienMoi.phai, phai);
	strcpy(sinhVienMoi.pass, pass);
	return sinhVienMoi;
}

NodeSinhVien *taoNodeSinhVien(SinhVien sv){
	NodeSinhVien *nodeSinhVien = new NodeSinhVien;
	nodeSinhVien->sinhVien = sv;
	nodeSinhVien->next = NULL;
	return nodeSinhVien;
}

void themSinhVienVaoCuoiDS(DanhSachSinhVien &danhSachSinhVien, SinhVien sv){
	NodeSinhVien *tmp = taoNodeSinhVien(sv);
	
	if(danhSachSinhVien.first==NULL){
		danhSachSinhVien.first = tmp;
	}
	else{
		NodeSinhVien *nodeChay = danhSachSinhVien.first;
		while(nodeChay->next!=NULL){
			nodeChay = nodeChay->next;
		}
		
		nodeChay->next = tmp;
	}
	danhSachSinhVien.soLuong++;
	
}

void themSinhVienVaoDSCoThuTu(DanhSachSinhVien &danhSachSinhVien, SinhVien sv){
	
	NodeSinhVien *tmp = taoNodeSinhVien(sv);
	
	if(danhSachSinhVien.first==NULL){
		danhSachSinhVien.first = tmp;
		danhSachSinhVien.soLuong++;
		return;
	}
	
	if(strcmp(tmp->sinhVien.maSV, danhSachSinhVien.first->sinhVien.maSV)<0){
		tmp->next = danhSachSinhVien.first;
		danhSachSinhVien.first = tmp;
		danhSachSinhVien.soLuong++;
	}
	else{
		NodeSinhVien *nodeChay = danhSachSinhVien.first;
		
		while(true){
			if(nodeChay->next==NULL) break;
			if(strcmp(nodeChay->next->sinhVien.maSV,tmp->sinhVien.maSV)>0){
				tmp->next = nodeChay->next;
				nodeChay->next = tmp;
				danhSachSinhVien.soLuong++;
				return;
			}
			nodeChay=nodeChay->next;
		}
		
		themSinhVienVaoCuoiDS(danhSachSinhVien, sv);
	}	
	
}

NodeSinhVien *timKiemSinhVienTheoMa(DanhSachSinhVien &danhSachSinhVien, char maSV[]){
	NodeSinhVien *nodeChay = danhSachSinhVien.first;
	while(nodeChay!=NULL){
//		cout<<nodeChay->sinhVien.maSV<<" va "<<maSV<<endl;
		if(strcmp(nodeChay->sinhVien.maSV, maSV)==0){
			return nodeChay;
		}
		nodeChay=nodeChay->next;
	}
	return NULL;
}

void xoaSinhVienTheoMa(DanhSachSinhVien &danhSachSinhVien, char maSV[]){
	if(strcmp(danhSachSinhVien.first->sinhVien.maSV,maSV)==0){
		NodeSinhVien *nodeXoa = danhSachSinhVien.first;
		danhSachSinhVien.first = danhSachSinhVien.first->next;
		delete nodeXoa;
	}
	else{
		NodeSinhVien *nodeChay = danhSachSinhVien.first;
		NodeSinhVien *nodeTruoc = NULL;
		
		while(strcmp(nodeChay->sinhVien.maSV,maSV)!=0 && nodeChay->next!=NULL){
			nodeTruoc = nodeChay;
			nodeChay = nodeChay->next;
		}
		
		if(strcmp(nodeChay->sinhVien.maSV,maSV)==0){
			nodeTruoc->next = nodeChay->next;
			delete nodeChay;
		}
	}
	danhSachSinhVien.soLuong--;
}

bool kiemTraXoaSinhVienTheoMa(DanhSachSinhVien &danhSachSinhVien, char maSV[]){
	if(strcmp(danhSachSinhVien.first->sinhVien.maSV,maSV)==0){
		if(danhSachSinhVien.first->sinhVien.danhSachDiem.soLuong>0) return false;
		return true;
	}
	else{
		NodeSinhVien *nodeChay = danhSachSinhVien.first;
		NodeSinhVien *nodeTruoc = NULL;
		
		while(strcmp(nodeChay->sinhVien.maSV,maSV)!=0 && nodeChay->next!=NULL){
			nodeTruoc = nodeChay;
			nodeChay = nodeChay->next;
		}
		
		if(strcmp(nodeChay->sinhVien.maSV,maSV)==0){
			if(nodeChay->sinhVien.danhSachDiem.soLuong>0) return false;
			return true;
		}
	}
}

void suaThongTinSinhVien(DanhSachSinhVien &danhSachSinhVien, char maSV[], char hoMoi[], char tenMoi[]){
	NodeSinhVien *svCanSua = timKiemSinhVienTheoMa(danhSachSinhVien, maSV);
	strcpy(svCanSua->sinhVien.ho, hoMoi);
	strcpy(svCanSua->sinhVien.ten, tenMoi);
}

void themDiemVaoSinhVien(DanhSachSinhVien &danhSachSinhVien, char maSV[], Diem diem){
	NodeSinhVien *nodeChay = danhSachSinhVien.first;
	while(nodeChay!=NULL){
		if(strcmp(nodeChay->sinhVien.maSV, maSV)==0){
			themDiemVaoCuoiDS(nodeChay->sinhVien.danhSachDiem, diem);
			return;
		}
		nodeChay=nodeChay->next;
	}
}

void suaDiemVaoSinhVien(DanhSachSinhVien &danhSachSinhVien, char maSV[], char maMH[], float diem){
	NodeSinhVien *nodeChay = danhSachSinhVien.first;
	while(nodeChay!=NULL){
		if(strcmp(nodeChay->sinhVien.maSV, maSV)==0){
			suaDiem(nodeChay->sinhVien.danhSachDiem, maMH, diem);
			return;
		}
		nodeChay=nodeChay->next;
	}
}

SinhVien *danhSachTuyenTinh(DanhSachSinhVien &danhSachSinhVien, int &n){
	
	SinhVien *dsTT = new SinhVien[danhSachSinhVien.soLuong];
	
	NodeSinhVien *node = danhSachSinhVien.first;
	n=0;
	while(node!=NULL){
		*(dsTT+n)= node->sinhVien;
		n++;
		node = node->next;
	}
	
	return dsTT;
	
}

void xoaDSSinhVien(DanhSachSinhVien &dsSinhVien){
	NodeSinhVien *tmpSV = dsSinhVien.first;
	while(tmpSV!=NULL){
		NodeSinhVien *xoa = tmpSV;
		tmpSV = tmpSV->next;
		xoaDSDiem(xoa->sinhVien.danhSachDiem);
		delete xoa;
	}
	dsSinhVien.soLuong=0;
}
