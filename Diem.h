#pragma once
#include <iostream>
#include <string.h>

struct Diem{
	char maMH[15];
	float diem;
};

struct NodeDiem{
	Diem diem;
	NodeDiem *next=NULL;
};

struct DanhSachDiem{
	NodeDiem *first=NULL;//chua co phan tu nao thi node dau bang null
	int soLuong = 0;//so luong bang 0
};

Diem taoDiem(char maMH[], float diem){
	Diem diemMoi;
	strcpy(diemMoi.maMH, maMH);//dua ma mon hoc vao diem
	diemMoi.diem = diem;//gan gia tri cho diem
	return diemMoi;//tra ve 1 node
}

NodeDiem *taoNodeDiem(Diem diem){//truyen diemMoi vao 
	NodeDiem *nodeDiem = new NodeDiem;
	nodeDiem->diem = diem;
	nodeDiem->next = NULL;
	return nodeDiem;
}

void themDiemVaoCuoiDS(DanhSachDiem &danhSachDiem, Diem diem){
	NodeDiem *tmp = taoNodeDiem(diem);
	
	if(danhSachDiem.first==NULL){
		danhSachDiem.first = tmp;
	}
	else{
		NodeDiem *nodeChay = danhSachDiem.first;
		while(nodeChay->next!=NULL){//duyet den cuoi ds
			nodeChay = nodeChay->next;
		}
		
		nodeChay->next = tmp;
	}
	danhSachDiem.soLuong++;
	
}

void xoaDSDiem(DanhSachDiem &dsDiem){
	NodeDiem *tmpDiem = dsDiem.first;
	while(tmpDiem!=NULL){
		NodeDiem *xoa = tmpDiem;
		tmpDiem=tmpDiem->next;
		delete xoa;
	}
	dsDiem.soLuong=0;
}

float timDiem(DanhSachDiem dsDiem, char maMH[]){
	NodeDiem *tmpDiem = dsDiem.first;
	while(tmpDiem!=NULL){
		if(strcmp(tmpDiem->diem.maMH, maMH)==0){
			return tmpDiem->diem.diem;
		}
		tmpDiem=tmpDiem->next;
	}
	return -1;
}

void suaDiem(DanhSachDiem dsDiem, char maMH[], float diem){
	NodeDiem *tmpDiem = dsDiem.first;
	while(tmpDiem!=NULL){
		if(strcmp(tmpDiem->diem.maMH, maMH)==0){
			tmpDiem->diem.diem = diem;
		}
		tmpDiem=tmpDiem->next;
	}
}
