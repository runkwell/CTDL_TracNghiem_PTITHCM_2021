#pragma once
#include "SinhVien.h"
#include <fstream>

#define MAX_LOP 300

struct Lop{
	char maLop[13];
	char tenLop[30];
	DanhSachSinhVien danhSachSinhVien;
};

struct DanhSachLop{
	Lop *danhSachLop[MAX_LOP];
	int soLuong = 0;
};

Lop taoLopMoi(char maLop[], char tenLop[]){
	Lop lopHoc;
	strcpy(lopHoc.maLop, maLop);
	strcpy(lopHoc.tenLop, tenLop);
	return lopHoc;
}

void themLopVaoDS(DanhSachLop &danhSachLop, Lop lopMoi){
	danhSachLop.danhSachLop[danhSachLop.soLuong] = new Lop;
	*danhSachLop.danhSachLop[danhSachLop.soLuong] = lopMoi;
	danhSachLop.soLuong++;
}

Lop *timKiemLop(DanhSachLop &danhSachLop, char maLop[]){
	for(int i=0; i<danhSachLop.soLuong; i++){
		if(strcmp(danhSachLop.danhSachLop[i]->maLop, maLop)==0){
			return danhSachLop.danhSachLop[i];
		}
	}
	return NULL;
}
Lop *timKiemtheochisovitriLop(DanhSachLop &danhSachLop, int vt){
	if(vt==0) return NULL;
	if(vt>danhSachLop.soLuong) return NULL;
	return danhSachLop.danhSachLop[vt-1];
}

bool kiemtraxoa(DanhSachLop &danhSachLop, char maLop[]){
	for(int i=0; i<danhSachLop.soLuong; i++){
		if(strcmp(danhSachLop.danhSachLop[i]->maLop, maLop)==0){
			if(danhSachLop.danhSachLop[i]->danhSachSinhVien.soLuong>0) return false;
			else return true;
		}
	}
	return false;
}

void xoaLop(DanhSachLop &danhSachLop, char maLop[]){
	for(int i=0; i<danhSachLop.soLuong; i++){
		if(strcmp(danhSachLop.danhSachLop[i]->maLop, maLop)==0){
			for(int j=i; j<danhSachLop.soLuong-1; j++){
				danhSachLop.danhSachLop[j] = danhSachLop.danhSachLop[j+1];
			}
			danhSachLop.soLuong--;
			return;
		}
	}
}

void suaThongTinLop(DanhSachLop &danhSachLop, char maLop[], char tenMoi[]){
	for(int i=0; i<danhSachLop.soLuong; i++){
		if(strcmp(danhSachLop.danhSachLop[i]->maLop, maLop)==0){
			strcpy(danhSachLop.danhSachLop[i]->tenLop, tenMoi);
			return;
		}
	}
}

void suaSinhVienTrongLop(DanhSachLop &danhSachLop, char maLop[], char maSV[], char hoMoi[], char tenMoi[]){
	
	for(int i=0; i<danhSachLop.soLuong; i++){
		if(strcmp(danhSachLop.danhSachLop[i]->maLop, maLop)==0){
			suaThongTinSinhVien(danhSachLop.danhSachLop[i]->danhSachSinhVien, maSV, hoMoi, tenMoi);
			return;
		}
	}
	
}

void themSinhVienVaoLop(DanhSachLop &danhSachLop, char maLop[], SinhVien sv){
	for(int i=0; i<danhSachLop.soLuong; i++){
		if(strcmp(danhSachLop.danhSachLop[i]->maLop, maLop)==0){
			themSinhVienVaoDSCoThuTu(danhSachLop.danhSachLop[i]->danhSachSinhVien, sv);
			return;
		}
	}
}

void themDiemVaoSinhVienOLop(DanhSachLop &danhSachLop, char maLop[], char maSV[], Diem diem){
	for(int i=0; i<danhSachLop.soLuong; i++){
		if(strcmp(danhSachLop.danhSachLop[i]->maLop, maLop)==0){
			themDiemVaoSinhVien(danhSachLop.danhSachLop[i]->danhSachSinhVien, maSV, diem);
			return;
		}
	}
}

void themDiemVaoSinhVienTrongCacLop(DanhSachLop &danhSachLop, char maSV[], Diem diem){
	for(int i=0; i<danhSachLop.soLuong; i++){
		if(timKiemSinhVienTheoMa(danhSachLop.danhSachLop[i]->danhSachSinhVien, maSV)!=NULL){
			themDiemVaoSinhVien(danhSachLop.danhSachLop[i]->danhSachSinhVien, maSV, diem);
			return;
		}
	}
}

void suaDiemVaoSinhVienTrongCacLop(DanhSachLop &danhSachLop, char maSV[], char maMH[], float diem){
	for(int i=0; i<danhSachLop.soLuong; i++){
		if(timKiemSinhVienTheoMa(danhSachLop.danhSachLop[i]->danhSachSinhVien, maSV)!=NULL){
			suaDiemVaoSinhVien(danhSachLop.danhSachLop[i]->danhSachSinhVien, maSV, maMH, diem);
			return;
		}
	}
}

void xoaSinhVienTrongLop(DanhSachLop &danhSachLop, char maLop[], char maSV[]){
	for(int i=0; i<danhSachLop.soLuong; i++){
		if(strcmp(danhSachLop.danhSachLop[i]->maLop, maLop)==0){
			xoaSinhVienTheoMa(danhSachLop.danhSachLop[i]->danhSachSinhVien, maSV);
			return;
		}
	}
}

bool kiemTraXoaSinhVienTrongLop(DanhSachLop &danhSachLop, char maLop[], char maSV[]){
	for(int i=0; i<danhSachLop.soLuong; i++){
		if(strcmp(danhSachLop.danhSachLop[i]->maLop, maLop)==0){
			return kiemTraXoaSinhVienTheoMa(danhSachLop.danhSachLop[i]->danhSachSinhVien, maSV);
		}
	}
}

void xoaDSLop(DanhSachLop &dsLop){
	for(int i=0; i<dsLop.soLuong; i++){
		xoaDSSinhVien(dsLop.danhSachLop[i]->danhSachSinhVien);
		delete dsLop.danhSachLop[i];
	}
	dsLop.soLuong = 0;
}

NodeSinhVien *timKiemTrongTatCaSinhVien(DanhSachLop &danhSachLop, char maSV[]){
	for(int i=0; i<danhSachLop.soLuong; i++){
		if(timKiemSinhVienTheoMa(danhSachLop.danhSachLop[i]->danhSachSinhVien, maSV)!=NULL){
			return timKiemSinhVienTheoMa(danhSachLop.danhSachLop[i]->danhSachSinhVien, maSV);
		}
	}
	return NULL;
}

void ghiFileDSLopSVDiem(DanhSachLop &dsLop){
	
	std::fstream file;
	file.open("LopSinhVienDiem.txt", std::ios::out);
	
	file<<dsLop.soLuong<<std::endl;
	
	for(int i=0; i<dsLop.soLuong; i++){
		file<<dsLop.danhSachLop[i]->maLop<<std::endl;
		file<<dsLop.danhSachLop[i]->tenLop<<std::endl;
		
		file<<dsLop.danhSachLop[i]->danhSachSinhVien.soLuong<<std::endl;
		NodeSinhVien *tmpSV = dsLop.danhSachLop[i]->danhSachSinhVien.first;
		while(tmpSV!=NULL){
			file<<tmpSV->sinhVien.maSV<<std::endl;
			file<<tmpSV->sinhVien.pass<<std::endl;
			file<<tmpSV->sinhVien.ho<<std::endl;
			file<<tmpSV->sinhVien.ten<<std::endl;
			file<<tmpSV->sinhVien.phai<<std::endl;
			
			file<<tmpSV->sinhVien.danhSachDiem.soLuong<<std::endl;
			NodeDiem *tmpDiem = tmpSV->sinhVien.danhSachDiem.first;
			while(tmpDiem!=NULL){
				file<<tmpDiem->diem.maMH<<std::endl;
				file<<tmpDiem->diem.diem<<std::endl;
				
				tmpDiem = tmpDiem->next;
			}
			
			tmpSV = tmpSV->next;
		}
		
	}
	
	file.close();
	
}

void docFileLopSVDiem(DanhSachLop &dsLop){
	std::fstream file;
	file.open("LopSinhVienDiem.txt", std::ios::in);
	if(file==NULL) return;
	
	xoaDSLop(dsLop);
	
	int nLop;
	file>>nLop;
	file.ignore();
	
	for(int i=0; i<nLop; i++){
		Lop lop;
		file.getline(lop.maLop, sizeof(lop.maLop), '\n');
		file.getline(lop.tenLop, sizeof(lop.tenLop), '\n');
		themLopVaoDS(dsLop, lop);
//		std::cout<<"Lop: "<<dsLop.soLuong<<std::endl;
//		std::cout<<"Ma lop: "<<dsLop.danhSachLop[i]->maLop<<std::endl;
//		std::cout<<"Ten lop: "<<dsLop.danhSachLop[i]->tenLop<<std::endl;
		
		int nSinhVien;
		file>>nSinhVien;
		file.ignore();
//		std::cout<<"So SV: "<<nSinhVien<<std::endl;
		for(int j=0; j<nSinhVien; j++){
			SinhVien sinhVien;
			file.getline(sinhVien.maSV, sizeof(sinhVien.maSV), '\n');
			file.getline(sinhVien.pass, sizeof(sinhVien.pass), '\n');
			file.getline(sinhVien.ho, sizeof(sinhVien.ho), '\n');
			file.getline(sinhVien.ten, sizeof(sinhVien.ten), '\n');
			file.getline(sinhVien.phai, sizeof(sinhVien.phai), '\n');
			themSinhVienVaoLop(dsLop, lop.maLop, sinhVien);
//			std::cout<<"Ma sinh vien: "<<sinhVien.maSV<<std::endl;
//			std::cout<<"Pass sinh vien: "<<sinhVien.pass<<std::endl;
//			std::cout<<"Ho sinh vien: "<<sinhVien.ho<<std::endl;
//			std::cout<<"Ten sinh vien: "<<sinhVien.ten<<std::endl;
//			std::cout<<"Phai sinh vien: "<<sinhVien.phai<<std::endl;
			
			int nDiem;
			file>>nDiem;
			file.ignore();
			for(int k=0; k<nDiem; k++){
				Diem diem;
				file.getline(diem.maMH, sizeof(diem.maMH), '\n');
				file>>diem.diem;
				file.ignore();
//				file.getline(diem.diem, sizeof(diem.diem), '\n');
				themDiemVaoSinhVienOLop(dsLop, lop.maLop, sinhVien.maSV, diem);
			}
		}	
	}
	
//	std::cout<<dsLop.soLuong<<std::endl;
//	for(int i=0; i<dsLop.soLuong; i++){
//		std::cout<<dsLop.danhSachLop[i]->maLop<<std::endl;
//	}
	
	file.close();
}
