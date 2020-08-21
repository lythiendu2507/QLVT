#pragma once
#include"khaibao.h"
#include"file.h"
#include"xuly.h"
#include<string.h>


//---khoi tao node hoa don -----------------
HOA_DON *khoi_tao_node_hd()
{
	HOA_DON * p = new HOA_DON;
	p->pnext = NULL;
	return p;
}

//----------Them 1 hoa don -----------
void Them_1_hd(HOA_DON *&pheap, HOA_DON *p)
{
	if (pheap == NULL)
	{
		pheap = p;
	}
	else
	{

		p->pnext = pheap;
		pheap = p;

	}
}






//-----------------DOC file nhan vien--------------------
void doc_file_nv(DS_NHAN_VIEN &ds_nv)
{
	ifstream filein;
	filein.open("ds_nv.txt", ios_base::in);
	filein >> ds_nv.sl_nv;
	gotoxy(50,5);
	cout << "So luong nhan vien:" << ds_nv.sl_nv << endl;
	int z = 20;
	for(int i = 0 ; i<ds_nv.sl_nv; i++)
	{
		ds_nv.ds[i] = new NHAN_VIEN;
		filein >> ds_nv.ds[i]->MANV; 
		filein.ignore();
		getline(filein, ds_nv.ds[i]->HO, '#'); 
		getline(filein, ds_nv.ds[i]->TEN, '#');
		filein >> ds_nv.ds[i]->PHAI;
		filein.ignore();
		filein >> ds_nv.ds[i]->SO_CMND;
		filein.ignore();
		filein >> ds_nv.ds[i]->danh_sach_hd.sl_hd;
		//HOA_DON *p = ds_nv.ds[i]->danh_sach_hd.pheap;
		
		for (int j = 0; j<ds_nv.ds[i]->danh_sach_hd.sl_hd;j++)
		{
			filein.ignore();
			HOA_DON * p = khoi_tao_node_hd();
			getline(filein, p->soHD, '$');
			filein >> p->NGAYLAPHOADON.ngay;
			filein.ignore();
			filein >> p->NGAYLAPHOADON.thang;
			filein.ignore();
			filein >> p->NGAYLAPHOADON.nam;
			filein.ignore();
			filein >> p->LOAI;
			filein.ignore();
			filein >> p->ds_ct_hoadon.sl_ct_hd;
			Them_1_hd(ds_nv.ds[i]->danh_sach_hd.pheap, p);
			
			for (int k = 0; k < p->ds_ct_hoadon.sl_ct_hd; k++)
			{
				filein.ignore();
				getline(filein, p->ds_ct_hoadon.ct_hd[k].MAVT, '@');
				filein >> p->ds_ct_hoadon.ct_hd[k].SOLUONG;
				filein.ignore();
				filein >> p->ds_ct_hoadon.ct_hd[k].DONGIA;
				filein.ignore();
				filein >> p->ds_ct_hoadon.ct_hd[k].VAT;
				filein.ignore();
				filein >> p->ds_ct_hoadon.ct_hd[k].TRANGTHAI;
				//filein.ignore();
			}

		}
		
		
	}

	filein.close();
}


//-----------------NHAP file nhan vien--------------------
void ghi_file_nv(DS_NHAN_VIEN &ds_nv)
{
	ofstream fileout;
	fileout.open("ds_nv.txt");	
	fileout << ds_nv.sl_nv << endl;
	for (int i = 0; i < ds_nv.sl_nv; i++)
	{
		fileout << ds_nv.ds[i]->MANV << " ";
		//filein.ignore();
		fileout<< ds_nv.ds[i]->HO<< "#";
		fileout<< ds_nv.ds[i]->TEN<< "#";
		fileout << ds_nv.ds[i]->PHAI << "#";
		//fileout.ignore();
		fileout << ds_nv.ds[i]->SO_CMND << "#";
		fileout << ds_nv.ds[i]->danh_sach_hd.sl_hd<<endl;
		
		for (int j = 0; j < ds_nv.ds[i]->danh_sach_hd.sl_hd; j++)
		{
			fileout << ds_nv.ds[i]->danh_sach_hd.pheap->soHD<<"$";
			fileout << ds_nv.ds[i]->danh_sach_hd.pheap->NGAYLAPHOADON.ngay << "$";
			fileout << ds_nv.ds[i]->danh_sach_hd.pheap->NGAYLAPHOADON.thang << "$";
			fileout << ds_nv.ds[i]->danh_sach_hd.pheap->NGAYLAPHOADON.nam << "$";
			fileout << ds_nv.ds[i]->danh_sach_hd.pheap->LOAI << "$";
			fileout << ds_nv.ds[i]->danh_sach_hd.pheap->ds_ct_hoadon.sl_ct_hd<<endl;

			for (int k = 0 ;k < ds_nv.ds[i]->danh_sach_hd.pheap->ds_ct_hoadon.sl_ct_hd; k++)
			{
				fileout << ds_nv.ds[i]->danh_sach_hd.pheap->ds_ct_hoadon.ct_hd[j].MAVT<<"@";
				fileout << ds_nv.ds[i]->danh_sach_hd.pheap->ds_ct_hoadon.ct_hd[j].SOLUONG << "@";
				fileout << ds_nv.ds[i]->danh_sach_hd.pheap->ds_ct_hoadon.ct_hd[j].DONGIA << "@";
				fileout << ds_nv.ds[i]->danh_sach_hd.pheap->ds_ct_hoadon.ct_hd[j].VAT << "@";
				fileout << ds_nv.ds[i]->danh_sach_hd.pheap->ds_ct_hoadon.ct_hd[j].TRANGTHAI<<endl;
			}
		}
	}	
	fileout.close();
}


//-----------------DOC file vat tu--------------------
void doc_file_vt(DS_VATTU &ds_vt)
{
	ifstream filein;
	filein.open("ds_vt.txt");
	filein >> ds_vt.sl_vt; 
	for(int i=0;i<ds_vt.sl_vt;i++)
	{
		
		TREE_VATTU x = Khoi_tao_node_vat_tu();
		filein.ignore();
		//filein >> ws;
		getline(filein,x->MA_VT, '#');
		getline(filein, x->TEN_VT, '#'); 
		getline(filein, x->DONVITINH, '#');
		filein>> x->SOLUONGTON;

		them_vattu(ds_vt.tree_ds_vt, x);

	}
	filein.close();
}


//-------------------Khi file vat tu------------------------
void Ghi_file_vt(DS_VATTU &ds_vt)
{
	ofstream fileout;
	fileout.open("ds_vt.txt");
	fileout << ds_vt.sl_vt<<endl;
	
	TREE_VATTU t = ds_vt.tree_ds_vt;
	TREE_VATTU p;
	while (t)
	{
		if (t->pright == NULL)
		{
			
			fileout<< t->MA_VT<<"#";
			fileout << t->TEN_VT<<"#";
			fileout << t->DONVITINH<<"#";
			fileout << t->SOLUONGTON<<endl;
			t = t->pleft;
		}
		else
		{
			p = t->pright;
			while (p->pleft && p->pleft != t)
			{
				p = p->pleft;
			}
			if (p->pleft == NULL)
			{
				p->pleft = t;
				t = t->pright;
			}
			else
			{
				p->pleft = NULL;
				fileout << t->MA_VT << "#";
				fileout << t->TEN_VT << "#";
				fileout << t->DONVITINH << "#";
				fileout << t->SOLUONGTON << endl;
				t = t->pleft;

			}

		}
	}
	fileout.close();
}