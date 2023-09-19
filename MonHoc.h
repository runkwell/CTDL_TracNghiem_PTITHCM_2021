#pragma once

#include <string.h>
#include <fstream>
#include "CauHoi.h"

struct MonHoc{
	char maMH[15];
	char tenMH[30];
	DanhSachCauHoi danhSachCauHoi;
};

struct NodeMonHoc{
	MonHoc monHoc;
	NodeMonHoc *left = NULL;
	NodeMonHoc *right = NULL;
};

struct DanhSachMonHoc{
	NodeMonHoc *root = NULL;
	int soLuong = 0;
};

MonHoc taoMonHocMoi(char maMH[], char tenMH[]){
	MonHoc monHoc;
	strcpy(monHoc.maMH, maMH);
	strcpy(monHoc.tenMH, tenMH);
	return monHoc;
}

NodeMonHoc *taoNodeMonHoc(MonHoc monHoc){
	NodeMonHoc *nodeMonHoc = new NodeMonHoc;
	
	nodeMonHoc->monHoc = monHoc;
	nodeMonHoc->left=NULL;
	nodeMonHoc->right=NULL;
	
	return nodeMonHoc;
}

void themNodeVaoCay(DanhSachMonHoc &danhSachMonHoc, MonHoc monHoc){
	NodeMonHoc *tmp = taoNodeMonHoc(monHoc);
	if(danhSachMonHoc.root==NULL){
		danhSachMonHoc.root = tmp;
	}
	else{
		NodeMonHoc *tam = danhSachMonHoc.root;
		NodeMonHoc *truoctam = tam;
		while(tam!=NULL){
			truoctam=tam;
			if(strcmp(monHoc.maMH,tam->monHoc.maMH)<0){
				tam=tam->left;
			}
			else if(strcmp(monHoc.maMH,tam->monHoc.maMH)>0){
				tam=tam->right;
			}
			else{
				return;
			}
		}
		if(strcmp(monHoc.maMH,truoctam->monHoc.maMH)<0){
			truoctam->left=tmp;
		}
		else if(strcmp(monHoc.maMH,truoctam->monHoc.maMH)>0){
			truoctam->right=tmp;
		}
	}
	danhSachMonHoc.soLuong++;
}

NodeMonHoc *timKiemMonHoc(DanhSachMonHoc &danhSachMonHoc, char maMH[]){
	NodeMonHoc *tam = danhSachMonHoc.root;
	while(tam!=NULL){
		if(strcmp(tam->monHoc.maMH,maMH)==0){
			return tam;
		}
		else if(strcmp(maMH,tam->monHoc.maMH)<0){
			tam=tam->left;
		}
		else if(strcmp(maMH,tam->monHoc.maMH)>0){
			tam=tam->right;
		}
	}
	return NULL;
}

void hieuChinhMonHocTheoMa(DanhSachMonHoc &danhSachMonHoc, char maMH[], char tenMH[]){
	NodeMonHoc *tam = timKiemMonHoc(danhSachMonHoc, maMH);
	if(tam!=NULL){
		strcpy(tam->monHoc.tenMH, tenMH);
	}
}

bool kiemTraXoaMonHoc(DanhSachMonHoc danhSachMonHoc, char maMH[]){
	NodeMonHoc *monHoc = timKiemMonHoc(danhSachMonHoc, maMH);
	if(monHoc==NULL) return false;
	if(monHoc->monHoc.danhSachCauHoi.soLuong>0) return false;
	return true;
}

void xoaNodeGoc(DanhSachMonHoc &danhSachMonHoc, char maMH[]){
	//Xoa goc co khong con
	if(danhSachMonHoc.root->right==NULL && danhSachMonHoc.root->left==NULL){
		delete danhSachMonHoc.root;
		danhSachMonHoc.root=NULL;
	}
	//xoa goc co 1 con
	else if(danhSachMonHoc.root->right==NULL || danhSachMonHoc.root->left==NULL){
		NodeMonHoc *nodeCanXoa = danhSachMonHoc.root;
		if(danhSachMonHoc.root->left==NULL){
			danhSachMonHoc.root=danhSachMonHoc.root->right;
		}
		else if(danhSachMonHoc.root->right==NULL){
			danhSachMonHoc.root=danhSachMonHoc.root->left;
		}
		delete nodeCanXoa;
	}
	//xoa goc hai con
	else if(danhSachMonHoc.root->left!=NULL && danhSachMonHoc.root->right!=NULL){
		NodeMonHoc *nodeThayThe = danhSachMonHoc.root->right;
		NodeMonHoc *nodeTruocThayThe = danhSachMonHoc.root;
		
		while(nodeThayThe->left!=NULL){
			nodeTruocThayThe=nodeThayThe;
			nodeThayThe=nodeThayThe->left;
		}
		
		MonHoc tmp = danhSachMonHoc.root->monHoc;
		danhSachMonHoc.root->monHoc=nodeThayThe->monHoc;
		nodeThayThe->monHoc=tmp;
		
		if(nodeTruocThayThe==danhSachMonHoc.root){
			if(nodeThayThe->right!=NULL){
				nodeTruocThayThe->right=nodeThayThe->right;
			}
			else{
				nodeTruocThayThe->right=NULL;
			}
		}
		else{
			if(nodeThayThe->right!=NULL){
				nodeTruocThayThe->left=nodeThayThe->right;
			}
			else{
				nodeTruocThayThe->left=NULL;
			}
		}
		
		delete nodeThayThe;
	}
}

void xoaNodeKhongPhaiGoc(DanhSachMonHoc &danhSachMonHoc, char maMH[]){
	NodeMonHoc *nodeCanXoa = danhSachMonHoc.root;
	NodeMonHoc *nodeTruocXoa = NULL;
	while(nodeCanXoa!=NULL){
		//tim node Truoc Xoa va node Can Xoa
		nodeTruocXoa=nodeCanXoa;
		if(strcmp(nodeCanXoa->monHoc.maMH, maMH)<0){
			nodeCanXoa=nodeCanXoa->right;
		}
		else if(strcmp(nodeCanXoa->monHoc.maMH, maMH)>0){
			nodeCanXoa=nodeCanXoa->left;
		}
		
		//tim xong nodeTruocXoa va nodeCanXoa
		if(strcmp(nodeCanXoa->monHoc.maMH, maMH)==0){
			//thuc Hien xoa
			//xoa node khong con
			if(nodeCanXoa->right==NULL && nodeCanXoa->left==NULL){
				if(strcmp(nodeCanXoa->monHoc.maMH, nodeTruocXoa->monHoc.maMH)<0){
					nodeTruocXoa->left=NULL;
				}
				else if(strcmp(nodeCanXoa->monHoc.maMH, nodeTruocXoa->monHoc.maMH)>0){
					nodeTruocXoa->right=NULL;
				}
				delete nodeCanXoa;
				return;
			}
			//xoa node 1 con
			else if(nodeCanXoa->right==NULL || nodeCanXoa->left==NULL){
				//nodeCanXoa nam ben trai nodeTruocXoa
				if(strcmp(nodeCanXoa->monHoc.maMH, nodeTruocXoa->monHoc.maMH)<0){
					if(nodeCanXoa->left==NULL){
						nodeTruocXoa->left = nodeCanXoa->right;
					}
					else if(nodeCanXoa->right==NULL){
						nodeTruocXoa->left = nodeCanXoa->left;
					}
				}
				//nodeCanXoa nam ben phai nodeTruocXoa
				else if(strcmp(nodeCanXoa->monHoc.maMH, nodeTruocXoa->monHoc.maMH)>0){
					if(nodeCanXoa->left==NULL){
						nodeTruocXoa->right = nodeCanXoa->right;
					}
					else if(nodeCanXoa->right==NULL){
						nodeTruocXoa->right = nodeCanXoa->left;
					}
				}
				delete nodeCanXoa;
				return;
			}
			//xoa node 2 con
			else if(nodeCanXoa->right!=NULL && nodeCanXoa->left!=NULL){
				NodeMonHoc *nodeThayThe = nodeCanXoa->right;
				NodeMonHoc *nodeTruocThayThe = nodeCanXoa;
				
				while(nodeThayThe->left!=NULL){
					nodeTruocThayThe=nodeThayThe;
					nodeThayThe=nodeThayThe->left;
				}
				
				MonHoc tmp = nodeCanXoa->monHoc;
				nodeCanXoa->monHoc=nodeThayThe->monHoc;
				nodeThayThe->monHoc=tmp;
				
				
				if(nodeTruocThayThe==nodeCanXoa){
					if(nodeThayThe->right!=NULL){
						nodeTruocThayThe->right=nodeThayThe->right;
					}
					else{
						nodeTruocThayThe->right=NULL;
					}
				}
				else{
					if(nodeThayThe->right!=NULL){
						nodeTruocThayThe->left=nodeThayThe->right;
					}
					else{
						nodeTruocThayThe->left=NULL;
					}
				}
				
				delete nodeThayThe;
				return;
			}
		}
		
	}
}

void xoaNodeKhoiCayTheoMa(DanhSachMonHoc &danhSachMonHoc, char maMH[]){
	if(danhSachMonHoc.root!=NULL){
		if(strcmp(danhSachMonHoc.root->monHoc.maMH, maMH)==0){
			xoaNodeGoc(danhSachMonHoc, maMH);
		}
		else{
			xoaNodeKhongPhaiGoc(danhSachMonHoc, maMH);
		}
	}
	danhSachMonHoc.soLuong--;
}

void deQuyXoaNode(NodeMonHoc *node){
	if(node!=NULL){
		deQuyXoaNode(node->left);
		deQuyXoaNode(node->right);
		delete node;
	}
}

void xoaDanhSachMonHoc(DanhSachMonHoc &danhSachMonHoc){
	deQuyXoaNode(danhSachMonHoc.root);
	danhSachMonHoc.root=NULL;
	danhSachMonHoc.soLuong=0;
}

void danhSachMonHocTuyenTinh(NodeMonHoc *node, MonHoc *&monHoc, int &i){
	if(node!=NULL){
		danhSachMonHocTuyenTinh(node->left, monHoc, i);
		*(monHoc+i) = node->monHoc;
		i++;
		danhSachMonHocTuyenTinh(node->right, monHoc, i);
	}
}

MonHoc *doCayVaoMangTuyenTinh(DanhSachMonHoc &danhSachMonHoc, int &n){
	
	MonHoc *danhSachMonHocTT = new MonHoc[danhSachMonHoc.soLuong];
	n=0;
	
	if(danhSachMonHoc.root!=NULL){
		danhSachMonHocTuyenTinh(danhSachMonHoc.root, danhSachMonHocTT, n);
	}
	
	return danhSachMonHocTT;
	
}

void themCauHoiVaoMonHoc(DanhSachMonHoc &danhSachMonHoc, CauHoi cauHoi, char maMH[]){
	themCauHoiVaoMang(timKiemMonHoc(danhSachMonHoc, maMH)->monHoc.danhSachCauHoi, cauHoi);
//	cout<<"\ncauhoi sau khi them: "<<timKiemMonHoc(danhSachMonHoc, maMH)->monHoc.danhSachCauHoi.danhSachCauHoi[0].noiDung;
}

CauHoi timCauHoiTrongMonHoc(DanhSachMonHoc danhSachMonHoc, int viTri, char maMH[]){
	return timCauHoi(timKiemMonHoc(danhSachMonHoc, maMH)->monHoc.danhSachCauHoi, viTri);
}

void hieuChinhCauHoiTrongMonHoc(DanhSachMonHoc &danhSachMonHoc, int viTri, char maMH[], char noiDung[], char dapAnA[], char dapAnB[], char dapAnC[], char dapAnD[], char dapAnDung){
	hieuChinhCauHoi(timKiemMonHoc(danhSachMonHoc, maMH)->monHoc.danhSachCauHoi, noiDung, dapAnA, dapAnB, dapAnC, dapAnD, dapAnDung, viTri);
}

void xoaCauHoiTrongMonHoc(DanhSachMonHoc &danhSachMonHoc, int viTri, char maMH[]){
	xoaCauHoi(timKiemMonHoc(danhSachMonHoc, maMH)->monHoc.danhSachCauHoi, viTri);
}

void ghiFile(NodeMonHoc *node, std::fstream &file){
	if(node!=NULL){
		file<<node->monHoc.maMH<<std::endl;
		file<<node->monHoc.tenMH<<std::endl;
		file<<node->monHoc.danhSachCauHoi.soLuong<<std::endl;
		
		for(int i=0; i<node->monHoc.danhSachCauHoi.soLuong; i++){
			file<<node->monHoc.danhSachCauHoi.danhSachCauHoi[i].noiDung<<std::endl;
			file<<node->monHoc.danhSachCauHoi.danhSachCauHoi[i].dapAnA<<std::endl;
			file<<node->monHoc.danhSachCauHoi.danhSachCauHoi[i].dapAnB<<std::endl;
			file<<node->monHoc.danhSachCauHoi.danhSachCauHoi[i].dapAnC<<std::endl;
			file<<node->monHoc.danhSachCauHoi.danhSachCauHoi[i].dapAnD<<std::endl;
			file<<node->monHoc.danhSachCauHoi.danhSachCauHoi[i].dapAnDung<<std::endl;
		}
		
		ghiFile(node->left, file);
		ghiFile(node->right, file);
	}
}

void ghiFileDSMonHoc(DanhSachMonHoc &danhSachMonHoc){
	
	std::fstream file;
	
	file.open("MonHocCauHoi.txt", std::ios::out);
	
	ghiFile(danhSachMonHoc.root,file);
	
	file.close();
	
}

void docFileDSMonHoc(DanhSachMonHoc &danhSachMonHoc){
	std::fstream file;
	
	file.open("MonHocCauHoi.txt", std::ios::in);
	
	if(file==NULL) return;
	
	xoaDanhSachMonHoc(danhSachMonHoc);
	
	MonHoc monHoc;
	while(file.getline(monHoc.maMH, sizeof(monHoc.maMH), '\n')){
		if(strlen(monHoc.maMH)==0) break;
		file.getline(monHoc.tenMH, sizeof(monHoc.tenMH), '\n');
		
		themNodeVaoCay(danhSachMonHoc, monHoc);

		int nCauHoi;
		file>>nCauHoi;
		file.ignore();
		
		CauHoi cauHoi;
		for(int i=0; i<nCauHoi; i++){
			file.getline(cauHoi.noiDung, sizeof(cauHoi.noiDung), '\n');
			file.getline(cauHoi.dapAnA, sizeof(cauHoi.dapAnA), '\n');
			file.getline(cauHoi.dapAnB, sizeof(cauHoi.dapAnB), '\n');
			file.getline(cauHoi.dapAnC, sizeof(cauHoi.dapAnC), '\n');
			file.getline(cauHoi.dapAnD, sizeof(cauHoi.dapAnD), '\n');
			file>>cauHoi.dapAnDung;
			file.ignore();
			themCauHoiVaoMonHoc(danhSachMonHoc, cauHoi, monHoc.maMH);
		}

	}
	
	file.close();
}
