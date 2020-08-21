#pragma once
#include<iostream>
#include<string>
#include"khaibao.h"
#include"chuanhoa.h"
#include"mylib.h"
#include"file.h"
#include"Menu1.h"
#include<string.h>
#include<conio.h>
#include<ctime>
#pragma warning(disable : 4996) 


//====vattu====
bool kt_trung_mavt(TREE_VATTU t, string ma);
void hoan_vi_2_vt(TREE_VATTU t, TREE_VATTU a);




using namespace std;
//=============khai bai nguyen mau ham ============







//===============ham thoi gian =========
bool Check_Date(int nam, int thang, int ngay)
{
	int Thang[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0)
	{
		Thang[1] = 29;
	}
	if (thang >= 1 && thang <= 12)
	{
		if (ngay >= 1 && ngay <= Thang[thang - 1])
		{
			return true;
		}
	}
	return false;
}
//==================================================== VAT TU =====================================================================

//====================== Ham ho tro vat tu ===========
//==========kt trung ma vt =========
bool kt_trung_mavt(TREE_VATTU t, string ma)
{
	if (t == NULL)
	{
		return false;
	}
	else
	{
		if (t->MA_VT == ma)
		{
			return true;
		}
		else if (t->MA_VT < ma)
		{

			return(kt_trung_mavt(t->pright, ma));

		}
		else if (t->MA_VT > ma)
		{
			return(kt_trung_mavt(t->pleft, ma));
		}
	}
}
//=============Hoan vi hai vat tu ==============
void hoan_vi_2_vt(TREE_VATTU t, TREE_VATTU a)
{
	TREE_VATTU tam = new vattu;
	tam->MA_VT = t->MA_VT;
	tam->TEN_VT = t->TEN_VT;
	tam->DONVITINH = t->DONVITINH;
	tam->SOLUONGTON = t->SOLUONGTON;

	t->MA_VT = a->MA_VT;
	t->TEN_VT = a->TEN_VT;
	t->DONVITINH = a->DONVITINH;
	t->SOLUONGTON = a->SOLUONGTON;

	a->MA_VT = tam->MA_VT;
	a->TEN_VT = tam->TEN_VT;
	a->DONVITINH = tam->DONVITINH;
	a->SOLUONGTON = tam->SOLUONGTON;

}

void node_thay_the(TREE_VATTU &t, TREE_VATTU &x)
{
	if (t->pleft != NULL)
	{
		node_thay_the(t->pleft, x);
	}
	else
	{
		hoan_vi_2_vt(t, x);
		x = t; // x se luu vi tri nay de ty giai phong
		t = t->pright;
	}
}


//====================== Ham ho tro vat tu ===========
//====================================================






// ---------------Nhap vat tu-------------------------
void Nhap_vat_tu(DS_VATTU &ds_vt)
{
	TREE_VATTU p = Khoi_tao_node_vat_tu();

	gotoxy(80, 10);
	cout << "";
	getline(cin, p->MA_VT);
	chuan_hoa_vattu(p->MA_VT);
	bool kt = kt_trung_mavt(ds_vt.tree_ds_vt, p->MA_VT);
	gotoxy(50,28);
	cout << kt;
	if (kt == 0)
	{
		gotoxy(80, 12);
		cout << " ";
		getline(cin, p->TEN_VT);
		chuan_hoa_chu(p->TEN_VT);

		gotoxy(80, 14);
		cout << " ";
		getline(cin, p->DONVITINH);
		chuan_hoa_vattu(p->DONVITINH);
		gotoxy(80, 18);
		cout << " ";
		cin >> p->SOLUONGTON;
		while (getchar() != '\n');
		them_vattu(ds_vt.tree_ds_vt, p);
		ds_vt.sl_vt++;
	}
	else
	{
		
		gotoxy(50, 30);
		cout << "Ma vat tu bi trung. Moi nhap lai!!!";
		system("pause");
		clear_screen(50, 5, 110, 34);
		menu_nhapvt();
		return(Nhap_vat_tu(ds_vt));

		
	}

}


//-------------------xoa 1 vat tu --------------------
void xoa_1_vat_tu(TREE_VATTU &t, string ma)
{
	if (t != NULL)
	{
		if (t->MA_VT == ma)
		{
			TREE_VATTU x = t; // luu vi tri node can giai phong
			if (t->pright == NULL)
			{
				t = t->pleft;
			}
			else if (t->pleft == NULL)
			{
				t = t->pright;
			}
			else if (t->pleft != NULL && t->pright != NULL)
			{
				// node thay the la node trai cung cua node con ben phai
				node_thay_the(t->pright, x);

			}
			delete x;
		}
		else if (t->MA_VT < ma)

		{
			xoa_1_vat_tu(t->pright, ma);
		}
		else if (t->MA_VT > ma)
		{
			xoa_1_vat_tu(t->pleft, ma);
		}
	}
}

//--------In danh sach vat tu theo mavatu giam dan----
void In_ds_vat_tu_giam_dan(TREE_VATTU t)
{
	TREE_VATTU p = new vattu;
	SetBGColor(2);

	int i = 10;
	//gotoxy(55, i);
	while (t)
	{
		if (t->pright == NULL)
		{
			gotoxy(50, i);
			cout << t->MA_VT;
			gotoxy(66, i);
			cout << t->TEN_VT;
			gotoxy(95, i);
			cout << t->DONVITINH;
			gotoxy(119, i);
			cout << t->SOLUONGTON;
			i = i + 2;
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
				gotoxy(50, i);
				cout << t->MA_VT;
				gotoxy(66, i);
				cout << t->TEN_VT;
				gotoxy(95, i);
				cout << t->DONVITINH;
				gotoxy(119, i);
				cout << t->SOLUONGTON;
				i = i + 2;
				t = t->pleft;

			}

		}
	}

}



//---------------- Xoa vat tu ------------------------
void Xoa_vat_tu(DS_VATTU &ds_vt)
{
	gotoxy(50, 18);
	string ma;
	cout << " ";
	getline(cin, ma);
	chuan_hoa_vattu(ma);
	bool kt = kt_trung_mavt(ds_vt.tree_ds_vt, ma);
	if (kt == true)
	{
		xoa_1_vat_tu(ds_vt.tree_ds_vt, ma);
		ds_vt.sl_vt--;
		gotoxy(50, 30);
		cout << "Xoa vat tu co ma " << ma << " thanh cong !!";
		system("pause");
		_getch();
		return;
	}
	else
	{
		gotoxy(50, 30);
		cout << "Ma vat tu khong ton tai, Moi nhap lai !!!!";
		system("pause");
		_getch();
		return(Xoa_vat_tu(ds_vt));
		menu_xoa_vt();
	}
}


//----------------hieu chinh 1 vat tu ---------
void hieu_chinh_1_vattu(TREE_VATTU &t, string ma)
{
	if (t != NULL)
	{
		if (t->MA_VT == ma)
		{
			gotoxy(85, 14);
			cout << "";
			getline(cin, t->TEN_VT);
			gotoxy(85, 16);
			cout << "";
			getline(cin, t->DONVITINH);
			gotoxy(85, 18);
			cout << t->SOLUONGTON;
			chuan_hoa_chu(t->TEN_VT);
			chuan_hoa_chu(t->DONVITINH);
			gotoxy(85, 28);
			cout << "Da hieu chinh vat tu thanh cong.";
			_getch();
			return;
		}
		else if (t->MA_VT > ma)
		{
			hieu_chinh_1_vattu(t->pleft, ma);
		}
		else if (t->MA_VT < ma)
		{
			hieu_chinh_1_vattu(t->pright, ma);
		}
	}
}



//----------------- Hieu chinh vat tu ------------------------
void hieu_chinh_vattu(DS_VATTU &ds_vt)
{
	gotoxy(85, 10);
	string a;
	cout << "";
	getline(cin, a);
	int kt = kt_trung_mavt(ds_vt.tree_ds_vt, a);
	if (kt == true)
	{
		hieu_chinh_1_vattu(ds_vt.tree_ds_vt, a);
	}
	else
	{
		gotoxy(50, 28);
		cout << "Ma vat tu khong ton tai, moi nhap lai...";
		system("pause");
		return(hieu_chinh_vattu(ds_vt));
		menu_hieuchinh_vt();
	}
}





//==========================================================================================================================================

//================================================= NHANVIEN ===============================================================================

//-------------------kt ma nv co ton tai hay khong ------------------
int kt_ma_nv(int a, DS_NHAN_VIEN ds_nv)
{
	for (int i = 0; i < ds_nv.sl_nv; i++)
	{
		//kt nhan vien ton tai
		if (ds_nv.ds[i]->MANV == a)
		{
			//kt chua lap hoa don
			
				return i;
			
		}
	}
	return -1;
}

//--------------kt_cmnd---------------------
int kt_trung_cmnd(int a,int ma, DS_NHAN_VIEN ds_nv)
{
	for (int i = 0; i < ds_nv.sl_nv; i++)
	{
		//kt nhan vien ton tai
		if (ds_nv.ds[i]->MANV == a)
		{
			//kt chua lap hoa don
			if (ds_nv.ds[i]->SO_CMND == ma)
			{
				return i;
			}
			

		}
	}
	return -1;
}

//-----------lay ma nhan vien --------------
int lay_ma_nv(int a, DS_NHAN_VIEN ds_nv)
{
	for (int i = 0; i < ds_nv.sl_nv; i++)
	{
		if (ds_nv.ds[i]->MANV == a)
		{
			return i;
		}
	}
	return -1;
}



void Bubble_Sort(DS_NHAN_VIEN &ds_nv)
{
	int i, j;
	NHAN_VIEN	*temp = new NHAN_VIEN;
	for (i = 1; i < ds_nv.sl_nv; i++)
	{
		for (j = ds_nv.sl_nv - 1; j >= i; j--)
		{
			if (ds_nv.ds[j - 1]->TEN > ds_nv.ds[j]->TEN)
			{
				temp->MANV = ds_nv.ds[j - 1]->MANV;
				temp->HO = ds_nv.ds[j - 1]->HO;
				temp->TEN = ds_nv.ds[j - 1]->TEN;
				temp->PHAI = ds_nv.ds[j - 1]->PHAI;
				temp->SO_CMND = ds_nv.ds[j - 1]->SO_CMND;
				temp->danh_sach_hd = ds_nv.ds[j - 1]->danh_sach_hd;


				ds_nv.ds[j - 1]->MANV = ds_nv.ds[j]->MANV;
				ds_nv.ds[j - 1]->HO = ds_nv.ds[j]->HO;
				ds_nv.ds[j - 1]->TEN = ds_nv.ds[j]->TEN;
				ds_nv.ds[j - 1]->PHAI = ds_nv.ds[j]->PHAI;
				ds_nv.ds[j - 1]->SO_CMND = ds_nv.ds[j]->SO_CMND;
				ds_nv.ds[j - 1]->danh_sach_hd = ds_nv.ds[j]->danh_sach_hd;

				ds_nv.ds[j]->MANV = temp->MANV;
				ds_nv.ds[j]->HO = temp->HO;
				ds_nv.ds[j]->TEN = temp->TEN;
				ds_nv.ds[j]->PHAI = temp->PHAI;
				ds_nv.ds[j]->SO_CMND = temp->SO_CMND;
				ds_nv.ds[j]->danh_sach_hd = temp->danh_sach_hd;
			}
			else if (ds_nv.ds[j - 1]->TEN == ds_nv.ds[j]->TEN && ds_nv.ds[j - 1]->HO > ds_nv.ds[j]->HO)
			{
				temp->MANV = ds_nv.ds[j - 1]->MANV;
				temp->HO = ds_nv.ds[j - 1]->HO;
				temp->TEN = ds_nv.ds[j - 1]->TEN;
				temp->PHAI = ds_nv.ds[j - 1]->PHAI;
				temp->SO_CMND = ds_nv.ds[j - 1]->SO_CMND;
				temp->danh_sach_hd = ds_nv.ds[j - 1]->danh_sach_hd;


				ds_nv.ds[j - 1]->MANV = ds_nv.ds[j]->MANV;
				ds_nv.ds[j - 1]->HO = ds_nv.ds[j]->HO;
				ds_nv.ds[j - 1]->TEN = ds_nv.ds[j]->TEN;
				ds_nv.ds[j - 1]->PHAI = ds_nv.ds[j]->PHAI;
				ds_nv.ds[j - 1]->SO_CMND = ds_nv.ds[j]->SO_CMND;
				ds_nv.ds[j - 1]->danh_sach_hd = ds_nv.ds[j]->danh_sach_hd;

				ds_nv.ds[j]->MANV = temp->MANV;
				ds_nv.ds[j]->HO = temp->HO;
				ds_nv.ds[j]->TEN = temp->TEN;
				ds_nv.ds[j]->PHAI = temp->PHAI;
				ds_nv.ds[j]->SO_CMND = temp->SO_CMND;
				ds_nv.ds[j]->danh_sach_hd = temp->danh_sach_hd;
			}
			else if (ds_nv.ds[j - 1]->TEN == ds_nv.ds[j]->TEN && ds_nv.ds[j - 1]->HO == ds_nv.ds[j]->HO && ds_nv.ds[j - 1]->MANV > ds_nv.ds[j]->MANV)
			{
				temp->MANV = ds_nv.ds[j - 1]->MANV;
				temp->HO = ds_nv.ds[j - 1]->HO;
				temp->TEN = ds_nv.ds[j - 1]->TEN;
				temp->PHAI = ds_nv.ds[j - 1]->PHAI;
				temp->SO_CMND = ds_nv.ds[j - 1]->SO_CMND;
				temp->danh_sach_hd = ds_nv.ds[j - 1]->danh_sach_hd;


				ds_nv.ds[j - 1]->MANV = ds_nv.ds[j]->MANV;
				ds_nv.ds[j - 1]->HO = ds_nv.ds[j]->HO;
				ds_nv.ds[j - 1]->TEN = ds_nv.ds[j]->TEN;
				ds_nv.ds[j - 1]->PHAI = ds_nv.ds[j]->PHAI;
				ds_nv.ds[j - 1]->SO_CMND = ds_nv.ds[j]->SO_CMND;
				ds_nv.ds[j - 1]->danh_sach_hd = ds_nv.ds[j]->danh_sach_hd;

				ds_nv.ds[j]->MANV = temp->MANV;
				ds_nv.ds[j]->HO = temp->HO;
				ds_nv.ds[j]->TEN = temp->TEN;
				ds_nv.ds[j]->PHAI = temp->PHAI;
				ds_nv.ds[j]->SO_CMND = temp->SO_CMND;
				ds_nv.ds[j]->danh_sach_hd = temp->danh_sach_hd;
			}
		}


	}

}


//--------------Them Nhan vien ------------------
void them_nhan_vien(DS_NHAN_VIEN &ds_nv)
{
	NHAN_VIEN *p = new NHAN_VIEN;

	gotoxy(80, 10);
	cout << " ";
	cin >> p->MANV;
	int a = p->MANV;
	int kt = kt_ma_nv(a, ds_nv);
	if (kt <= 0)
	{
		while (getchar() != '\n');
		gotoxy(80, 12);
		cout << " ";
		getline(cin, p->HO);
		gotoxy(80, 14);
		cout << " ";
		getline(cin, p->TEN);
		gotoxy(80, 16);
		cout << " ";
		cin >> p->PHAI;
		gotoxy(80, 18);
		cout << " ";
		cin >> p->SO_CMND;
		
		int kt_scmnd = kt_trung_cmnd(p->MANV, p->SO_CMND, ds_nv);
		if (kt_scmnd < 0)
		{
			cout << "Chung minh nhan dan da co. Moi nhap lai lai...";
			system("pause");
			return;
		}
		else
		{
			p->kt = true;
			p->danh_sach_hd.sl_hd = 0;
			p->danh_sach_hd.pheap = NULL;

			chuan_hoa_chu(p->HO);
			chuan_hoa_chu(p->TEN);

			ds_nv.ds[ds_nv.sl_nv] = p;
			ds_nv.sl_nv++;
		}
		
	}
	else if (kt > 0)
	{
		gotoxy(50, 30);
		cout << "Ma nhan vien da ton tai, moi nhap lai !!";
		return(them_nhan_vien(ds_nv));
	}


}





//===========KT_xoa====================

//----------------Xoa Nhan vien--------------------
void Xoa_nhan_vien(DS_NHAN_VIEN &ds_nv)
{
	int a;
	gotoxy(75, 10);
	cout << " "; cin >> a;
	int vt = lay_ma_nv(a, ds_nv);
	if (vt < 0)
	{
		gotoxy(15, 31);
		SetBGColor(2);
		cout << "Nhan vien khong ton tai hoac da duoc lap hoa don, moi nhap lai...";
		clear_screen(50, 5, 115, 34);
		return(Xoa_nhan_vien(ds_nv));
		menu_xoa_nv();
	}
	else
	{
		for (int i = vt; i < ds_nv.sl_nv - 1; i++)
		{
			ds_nv.ds[i]->MANV = ds_nv.ds[i + 1]->MANV;
			ds_nv.ds[i]->HO = ds_nv.ds[i + 1]->HO;
			ds_nv.ds[i]->TEN = ds_nv.ds[i + 1]->TEN;
			ds_nv.ds[i]->PHAI = ds_nv.ds[i + 1]->PHAI;
			ds_nv.ds[i]->SO_CMND = ds_nv.ds[i + 1]->SO_CMND;
			ds_nv.ds[i]->danh_sach_hd = ds_nv.ds[i + 1]->danh_sach_hd;
			ds_nv.ds[i]->kt = ds_nv.ds[i + 1]->kt;

		}
		NHAN_VIEN *tam = ds_nv.ds[ds_nv.sl_nv - 1];
		ds_nv.sl_nv--;

		gotoxy(15, 41);
		SetBGColor(2);
		cout << "Da xoa thanh cong !!";
		return;
	}

}



//-----------------Hieu chinh -----------------
void Hieu_chinh_nv(DS_NHAN_VIEN &ds_nv)
{
	int a;
	gotoxy(110, 10);
	cout << " ";
	cin >> a;
	int vt = lay_ma_nv(a, ds_nv);
	gotoxy(110, 32);
	cout << vt;
	if (vt < 0)
	{
		clear_screen(15, 41, 120, 42);
		gotoxy(15, 30);
		SetBGColor(2);
		cout << "Ma nhan vien khong ton tai";

	}
	else
	{
		for (int i = vt; i < ds_nv.sl_nv; i++)
		{
			gotoxy(110, 12);
			cout << "";
			cin.ignore();
			getline(cin, ds_nv.ds[i]->HO);
			gotoxy(110, 14);
			cout << " ";
			getline(cin, ds_nv.ds[i]->TEN);
			gotoxy(110, 16);
			cout << " ";
			cin >> ds_nv.ds[i]->PHAI;
			gotoxy(110, 18);
			cout << ds_nv.ds[i]->SO_CMND;

			chuan_hoa_chu(ds_nv.ds[i]->HO);
			chuan_hoa_chu(ds_nv.ds[i]->TEN);

			gotoxy(50, 30);
			cout << "Da thay doi thong tin nhan vien thanh cong !!";
			return;
		}

	}



}

//----------------------XUAT DANH SACH NHAN VIEN --------------

void xuat_ds_nhanvien(DS_NHAN_VIEN ds_nv)
{

	for (int i = 0; i < ds_nv.sl_nv; i++)
	{
		gotoxy(50, i + 8);
		cout << int(ds_nv.ds[i]->MANV);
		gotoxy(62, i + 8);
		cout << ds_nv.ds[i]->HO;
		gotoxy(78, i + 8);
		cout << ds_nv.ds[i]->TEN;
		gotoxy(91, i + 8);
		cout << ds_nv.ds[i]->PHAI;
		gotoxy(102, i + 8);
		cout << ds_nv.ds[i]->SO_CMND;
		gotoxy(130, i + 8);
		cout << ds_nv.ds[i]->danh_sach_hd.sl_hd;
	}
}


//========================================================================================================================

//================================================== HOA DON =============================================================
//====================Ham ho tro nhap hoa don-ct hoa don ======

//-------------------kt ma nv co ton tai hay khong ------------------
int kt_ma_nv_hd(int a, DS_NHAN_VIEN ds_nv)
{
	for (int i = 0; i < ds_nv.sl_nv; i++)
	{
		//kt nhan vien ton tai
		if (ds_nv.ds[i]->MANV == a)
		{
			return i;
		}
	}
	return -1;
}

//----------- Ham kiem tra so luong chi tiet hoa don ----------
void kt_sl_ct_hd(ds_ct_hoadon sl_ct_hd)
{
	if (sl_ct_hd.sl_ct_hd == 20)
	{
		cout << "So luong chi tiet hoa don da day. ";
		return;
	}

}
//----------hieu chinh so luong ton Xuat cua vat tu ----------------
void hieu_chinh_soluongton_X(TREE_VATTU &t, string ma, float slt)
{


	if (t == NULL)
	{
		return;
	}
	else
	{
		if (t->MA_VT == ma)
		{
			if (t->SOLUONGTON > slt)

			{
				t->SOLUONGTON -= slt;
			}
			else
			{
				gotoxy(50, 30);
				cout << "So luong ton chi con " << t->SOLUONGTON << " Moi nhap lai ";
			}

		}
		else if (t->MA_VT < ma)
		{

			return hieu_chinh_soluongton_X(t->pright, ma, slt);

		}
		else if (t->MA_VT > ma)
		{
			return hieu_chinh_soluongton_X(t->pleft, ma, slt);
		}

	}
}


//----------hieu chinh so luong ton Nhap cua vat tu ----------------
void hieu_chinh_soluongton_N(TREE_VATTU &t, string &ma, float slt)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		if (t->MA_VT == ma)
		{
			t->SOLUONGTON += slt;
		}
		else if (t->MA_VT < ma)
		{

			return hieu_chinh_soluongton_N(t->pright, ma, slt);

		}
		else if (t->MA_VT > ma)
		{
			return hieu_chinh_soluongton_N(t->pleft, ma, slt);
		}

	}
}




//-------------------Nhap chi tiet nhap hoa don ------------------
void Nhap_chi_tiet_nhd(DS_VATTU &ds_vt, DS_NHAN_VIEN &ds_nv)
{
	//int i = 19; //i la vi tri bat dau cua toa do y;
	//for (int k = 0; k < slvt; k++)
	//{
	//	string ma;
	//	clear_screen(50, 17, 100, 10);
	//	SetBGColor(2);
	//	cin.ignore();
	//	gotoxy(50, i);
	//	cout << "Nhap ma vat tu " << k + 1 << ": ";
	//	getline(cin, ma);
	//	chuan_hoa_vattuu(ma);

	//	bool kt = kt_trung_mavt(ds_vt.tree_ds_vt, ma);

	//	if (kt == true)
	//	{

	//		ds_nv.ds[vt]->danh_sach_hd.pheap->ds_ct_hoadon = new ds_ct_hoadon;
	//		cout << ds_nv.ds[vt]->danh_sach_hd.pheap->soHD;

	//		gotoxy(80, i);
	//		cout << "So Luong: ";
	//		cin >> ds_nv.ds[vt]->danh_sach_hd.pheap->ds_ct_hoadon->ct_hd[k].SOLUONG;
	//		hieu_chinh_soluongton_N(ds_vt.tree_ds_vt, ma, ds_nv.ds[vt]->danh_sach_hd.pheap->ds_ct_hoadon->ct_hd[k].SOLUONG);


	//		gotoxy(95, i);
	//		cout << "Don Gia: ";
	//		cin >> ds_nv.ds[vt]->danh_sach_hd.pheap->ds_ct_hoadon->ct_hd[k].DONGIA;
	//		gotoxy(110, i);
	//		cout << "VAT: ";
	//		cin >> ds_nv.ds[vt]->danh_sach_hd.pheap->ds_ct_hoadon->ct_hd[k].VAT;
	//		gotoxy(125, i);

	//		ds_nv.ds[vt]->danh_sach_hd.pheap->ds_ct_hoadon->ct_hd[k].TRANGTHAI = "0"; // Hoa don nhap thi so luong vat tu trong kho mac dinh la tang.
	//		ds_nv.ds[vt]->danh_sach_hd.pheap->ds_ct_hoadon->sl_ct_hd++;
	//		i += 2;
	//	}
	//	else
	//	{
	//		gotoxy(50, 40);
	//		cout << "Vat tu khong ton tai!!";
	//		cout << "Moi nhap lai !!!";
	//		clear_screen(50, 17, 100, 10);
	//		Nhap_chi_tiet_nhd(ds_vt, ds_nv);
	//	}
	//}

	//gotoxy(50, 40);
	//cout << "Nhap chi tiet hoa don thanh cong!!!!!!!   ";

}


//-------------------Nhap chi tiet xuat hoa don ------------------
void Nhap_chi_tiet_xhd(DS_VATTU &ds_vt, ds_ct_hoadon &ds_ct_hoad, DS_HOA_DON &ds_hd, int slhd)
{
	//string a;

	//int i = 18; //int dem = 0;
	//for (int k = 0; k < slhd; k++)
	//{
	//	string ma;
	//	//ds_ct_hoad.ct_hd[k] =  CT_HOADON[k];
	//	clear_screen(50, 17, 100, 10);
	//	SetBGColor(2);
	//	cin.ignore();
	//	gotoxy(50, i);
	//	cout << "Nhap ma vat tu " << k + 1 << ": ";
	//	getline(cin, ma);
	//	chuan_hoa_vattuu(ma);
	//	//cin.ignore();
	//	bool kt = kt_trung_mavt(ds_vt.tree_ds_vt, ma);

	//	gotoxy(50, 35);
	//	//cout << kt;
	//	if (kt)
	//	{

	//		//ma = ds_ct_hoad.ct_hd[k].MAVT;
	//		gotoxy(80, i);
	//		cout << "So Luong: ";
	//		cin >> ds_ct_hoad.ct_hd[k].SOLUONG;
	//		hieu_chinh_soluongton_X(ds_vt.tree_ds_vt, ma, ds_ct_hoad.ct_hd[k].SOLUONG);

	//		/*gotoxy(95, 30);
	//		cout << ds_ct_hoad.ct_hd[k].SOLUONG;*/
	//		gotoxy(95, i);
	//		cout << "Don Gia: ";
	//		cin >> ds_ct_hoad.ct_hd[k].DONGIA;
	//		gotoxy(110, i);
	//		cout << "VAT: ";
	//		cin >> ds_ct_hoad.ct_hd[k].VAT;
	//		gotoxy(125, i);
	//		cout << "Trang Thai: ";
	//		cin >> ds_ct_hoad.ct_hd[k].TRANGTHAI;
	//		i += 2;
	//		ds_ct_hoad.sl_ct_hd++;
	//	}
	//	else
	//	{
	//		gotoxy(50, 40);
	//		cout << "Vat tu khong ton tai!!";
	//		cout << "Moi nhap lai !!!";
	//		clear_screen(50, 17, 100, 10);
	//		Nhap_chi_tiet_xhd(ds_vt, ds_ct_hoad, ds_hd, slhd);
	//	}
	//}
	//gotoxy(50, 40);
	//cout << "Nhap chi tiet hoa don thanh cong!!!!!!!   ";
	//ds_hd.sl_hd++;
}

//----------------------------------in hoa don --------------------------


//----------Lap hoa don Nhap--------------
void Lap_hoa_don_N(DS_NHAN_VIEN &ds_nv, DS_VATTU &ds_vt)
{
	int a;
	gotoxy(90, 8);
	cout << "";
	cin >> a;
	int vt = kt_ma_nv_hd(a, ds_nv); //gan vt thanh vi tri cua nhan vien co manv = a;
	if (vt < 0)
	{
		gotoxy(50, 32);
		cout << "Ma nhan vien khong ton tai!!";
		return;
	}
	else
	{
		gotoxy(100, 8);
		cout << ds_nv.ds[vt]->HO;
		gotoxy(105, 8);
		cout << ds_nv.ds[vt]->TEN;
		HOA_DON * p = khoi_tao_node_hd();
		time_t baygio = time(0);
		tm *ltm = localtime(&baygio);
		p->NGAYLAPHOADON.nam = 1900 + ltm->tm_year;
		p->NGAYLAPHOADON.thang = 1 + ltm->tm_mon;
		p->NGAYLAPHOADON.ngay = ltm->tm_mday;
		while (getchar() != '\n');
		gotoxy(90, 10);
		cout << "";
		getline(cin, p->soHD);
		p->LOAI = 0;
		if (p->LOAI == 0)
		{
			gotoxy(50, 12);
			cout << "LOAI HOA DON: N";
		}
		else
		{
			gotoxy(50, 12);
			cout << "LOAI HOA DON: X";
		}

		gotoxy(74, 14);
		cout << p->NGAYLAPHOADON.ngay;
		

		gotoxy(77, 14);
		cout <<"/" <<p->NGAYLAPHOADON.thang;
		

		gotoxy(80, 14);
		cout << "/" << p->NGAYLAPHOADON.nam;
		

		Them_1_hd(ds_nv.ds[vt]->danh_sach_hd.pheap, p); // Them 1 node vao dau dslk cua hoa don ma nhan vien thu vt nhap vao;
		ds_nv.ds[vt]->danh_sach_hd.sl_hd++;
		gotoxy(74, 16);
		cout << "NHAP HOA DON THANH CONG, NHAN PHIM VAT KY DE TIEP TUC LAP CHI TIET HOA DON!!!!";

		gotoxy(50, 17);
		int slvt;
		cout << "Nhap so vat tu lap hoa don: "; cin >> slvt;
		//Nhap_chi_tiet_nhd(ds_vt,ds_nv);
		//ds_nv.ds[vt]->danh_sach_hd.sl_hd++;

        Nhap_chi_tiet_hd_N:
		int i = 19; //i la vi tri bat dau cua toa do y;
		
		for (int k = 0; k < slvt; k++)
		{
			string ma;
			clear_screen(50, 17, 100, 10);
			SetBGColor(2);
			cin.ignore();
			gotoxy(50, i);
			cout << "Nhap ma vat tu " << k + 1 << ": ";
			getline(cin, ma);
			chuan_hoa_vattuu(ma);

			bool kt = kt_trung_mavt(ds_vt.tree_ds_vt, ma);

			if (kt == true)
			{

				//ds_nv.ds[vt]->danh_sach_hd.pheap->ds_ct_hoadon = new ds_ct_hoadon;
				//cout << ds_nv.ds[vt]->danh_sach_hd.pheap->soHD;
				ds_nv.ds[vt]->danh_sach_hd.pheap->ds_ct_hoadon.ct_hd[k].MAVT = ma;
				gotoxy(80, i);
				cout << "So Luong: ";
				cin >> ds_nv.ds[vt]->danh_sach_hd.pheap->ds_ct_hoadon.ct_hd[k].SOLUONG;
				hieu_chinh_soluongton_N(ds_vt.tree_ds_vt, ma, ds_nv.ds[vt]->danh_sach_hd.pheap->ds_ct_hoadon.ct_hd[k].SOLUONG);


				gotoxy(95, i);
				cout << "Don Gia: ";
				cin >> ds_nv.ds[vt]->danh_sach_hd.pheap->ds_ct_hoadon.ct_hd[k].DONGIA;
				gotoxy(110, i);
				cout << "VAT: ";
				cin >> ds_nv.ds[vt]->danh_sach_hd.pheap->ds_ct_hoadon.ct_hd[k].VAT;
				gotoxy(125, i);

				ds_nv.ds[vt]->danh_sach_hd.pheap->ds_ct_hoadon.ct_hd[k].TRANGTHAI = "0"; // Hoa don nhap thi so luong vat tu trong kho mac dinh la tang.
				cout << ds_nv.ds[vt]->danh_sach_hd.pheap->ds_ct_hoadon.ct_hd[k].TRANGTHAI;



				ds_nv.ds[vt]->danh_sach_hd.pheap->ds_ct_hoadon.sl_ct_hd++;
				
				i += 2;//toa do dia chi y tang tu dong.
			}
			else
			{
				gotoxy(50, 40);
				cout << "Vat tu khong ton tai!!";
				cout << "Moi nhap lai !!!";
				clear_screen(50, 17, 100, 10);
				k--;
			   // Nhap_chi_tiet_hd_N:
			}
		}

		gotoxy(50, 40);
		cout << "Nhap chi tiet hoa don thanh cong!!!!!!!   ";


	}
}



//----------Lap hoa don Xuat--------------
void Lap_hoa_don_X(DS_NHAN_VIEN &ds_nv, DS_VATTU &ds_vt)
{
	SetColor(WHITE);
	int a;
	gotoxy(90, 8);
	cout << "";
	cin >> a;
	int vt = kt_ma_nv_hd(a, ds_nv); //gan vt thanh vi tri cua nhan vien co manv = a;
	if (vt < 0)
	{
		gotoxy(50, 32);
		cout << "Ma nhan vien khong ton tai!!";
		return;
	}
	else
	{
		gotoxy(100, 8);
		cout << ds_nv.ds[vt]->HO;
		gotoxy(105, 8);
		cout << ds_nv.ds[vt]->TEN;
		HOA_DON * p = khoi_tao_node_hd();

		time_t baygio = time(0);
		tm *ltm = localtime(&baygio);
		p->NGAYLAPHOADON.nam = 1900 + ltm->tm_year;
		p->NGAYLAPHOADON.thang = 1 + ltm->tm_mon;
		p->NGAYLAPHOADON.ngay = ltm->tm_mday;

		while (getchar() != '\n');
		gotoxy(90, 10);
		cout << "";
		getline(cin, p->soHD);
		p->LOAI = 0;
		if (p->LOAI == 1)
		{
			gotoxy(50, 12);
			cout << "LOAI HOA DON: N";
		}
		else
		{
			gotoxy(50, 12);
			cout << "LOAI HOA DON: X";
		}

		gotoxy(74, 14);
		cout << p->NGAYLAPHOADON.ngay;


		gotoxy(77, 14);
		cout << "/" << p->NGAYLAPHOADON.thang;


		gotoxy(80, 14);
		cout << "/" << p->NGAYLAPHOADON.nam;

		Them_1_hd(ds_nv.ds[vt]->danh_sach_hd.pheap, p); // Them 1 node vao dau dslk cua hoa don ma nhan vien thu vt nhap vao;
		ds_nv.ds[vt]->danh_sach_hd.sl_hd++;
		gotoxy(74, 17);
		cout << "NHAP HOA DON THANH CONG, NHAN PHIM VAT KY DE TIEP TUC LAP CHI TIET HOA DON!!!!";

		gotoxy(50, 17);
		int slvt;
		cout << "Nhap so vat tu lap hoa don: "; cin >> slvt;
		//Nhap_chi_tiet_nhd(ds_vt,ds_nv);
		//ds_nv.ds[vt]->danh_sach_hd.sl_hd++;

	    //Nhap_chi_tiet_hd_N:
		int i = 19; //i la vi tri bat dau cua toa do y;
		for (int k = 0; k < slvt; k++)
		{
			string ma;
		//	clear_screen(50, 17, 100, 10);
			SetBGColor(2);
			cin.ignore();
			gotoxy(50, i);
			cout << "Nhap ma vat tu " << k + 1 << ": ";
			getline(cin, ma);
			chuan_hoa_vattuu(ma);

			bool kt = kt_trung_mavt(ds_vt.tree_ds_vt, ma);

			if (kt == true)
			{
				
				//ds_nv.ds[vt]->danh_sach_hd.pheap->ds_ct_hoadon = new ds_ct_hoadon;
				ds_nv.ds[vt]->danh_sach_hd.pheap->ds_ct_hoadon.ct_hd[k].MAVT = ma;
				//cout << ds_nv.ds[vt]->danh_sach_hd.pheap->soHD;

				gotoxy(80, i);
				cout << "So Luong: ";
				cin >> ds_nv.ds[vt]->danh_sach_hd.pheap->ds_ct_hoadon.ct_hd[k].SOLUONG;
				

				gotoxy(95, i);
				cout << "Don Gia: ";
				cin >> ds_nv.ds[vt]->danh_sach_hd.pheap->ds_ct_hoadon.ct_hd[k].DONGIA;

				gotoxy(110, i);
				cout << "VAT: ";
				cin >> ds_nv.ds[vt]->danh_sach_hd.pheap->ds_ct_hoadon.ct_hd[k].VAT;

				gotoxy(125, i);
				cout << "Trang Thai: ";
				cin >> ds_nv.ds[vt]->danh_sach_hd.pheap->ds_ct_hoadon.ct_hd[k].TRANGTHAI;
				if (ds_nv.ds[vt]->danh_sach_hd.pheap->ds_ct_hoadon.ct_hd[k].TRANGTHAI == 0)
				{//trang thai = 0 la` khach tra hang thi so luong cua kho se tang len
					hieu_chinh_soluongton_N(ds_vt.tree_ds_vt, ma, ds_nv.ds[vt]->danh_sach_hd.pheap->ds_ct_hoadon.ct_hd[k].SOLUONG);
				}
				else//trang thai = 1 la` khach mua hang thi so luong cua kho se giam xuong
				{
					hieu_chinh_soluongton_X(ds_vt.tree_ds_vt, ma, ds_nv.ds[vt]->danh_sach_hd.pheap->ds_ct_hoadon.ct_hd[k].SOLUONG);
				}

				//ds_nv.ds[vt]->danh_sach_hd.pheap->ds_ct_hoadon->
				ds_nv.ds[vt]->danh_sach_hd.pheap->ds_ct_hoadon.sl_ct_hd++;
				i += 2;
			}
			else
			{
				gotoxy(50, 32);
				cout << "Vat tu khong ton tai!!";
				cout << "Moi nhap lai !!!";
				clear_screen(50, 17, 100, 10);
				k--;
			//Nhap_chi_tiet_hd_N:
			}
		}

		gotoxy(50, 40);
		cout << "Nhap chi tiet hoa don thanh cong!!!!!!!   ";


	}
}
//=========================================================================================================






//===================================================IN HOA DON ==========================================


//-------------Ham kiem tra so hoa don ------------------------
int Kt_sohd_trung(DS_NHAN_VIEN ds_nv, string s)
{
	for (int i = 0; i < ds_nv.sl_nv; i++)
	{
		for (HOA_DON *k = ds_nv.ds[i]->danh_sach_hd.pheap; k != NULL; k = k->pnext)
		{
			if (k->soHD == s)
			{

				return i;

			}
		}

		
	}
	return -1;
}


//-------------Ham lay ma nhan vien co so hoa don can tim------------------------
int Lay_sohd(DS_NHAN_VIEN ds_nv, string s)
{
	for (int i = 0; i < ds_nv.sl_nv; i++)
	{
		if (ds_nv.ds[i]->danh_sach_hd.pheap->soHD == s)
		{
			return i;
		}
		else
		{
			return -1;
		}
	}

}







//===================================================TRA HANG ==========================================
//------------lay vi tri vat tu tu hoa don nhap vao --------
int lay_vt_mavt_trong_hd(ds_ct_hoadon ds_ct_hd, string ma)
{
	for (int i = 0; i < ds_ct_hd.sl_ct_hd; i++)
	{
		if (ds_ct_hd.ct_hd[i].MAVT == ma)
		{
			return i;
		}
	}
	return -1;
}

//-----------------------kiem tra ngay ------------------------
void kt_ngay(int y, int m, int d, int &ngayhan,DS_NHAN_VIEN ds_nv)
{
	HOA_DON *p = new HOA_DON;
	int ngay, thang, nam;
	time_t baygio = time(0);
	tm *ltm = localtime(&baygio);
	p->NGAYLAPHOADON.ngay = 1900 + ltm->tm_year;
	p->NGAYLAPHOADON.thang = 1 + ltm->tm_mon;
	p->NGAYLAPHOADON.nam = ltm->tm_mday;

	ngay = p->NGAYLAPHOADON.ngay;
	thang = p->NGAYLAPHOADON.thang;
	nam = p->NGAYLAPHOADON.nam;
	

	while (y >= nam)
	{
		if (y == nam && m == thang)
		{
			ngayhan += d - ngay;
			break;
		}
		else
		{
			//Cac thang 4,6,8,9,11 co 30 ngay 
			if (thang == 4 || thang == 6 || thang == 8 || thang == 9 || thang == 11)
			{
				ngayhan += 30 - ngay;
			}
			// Cac thang 1 3  5 7 10 12 co 31 ngay
			if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 10 || thang ==12)
			{
				ngayhan += 31 - ngay;
			}
			if (thang == 2)
			{
				if (nam % 4 && nam % 100 != 0 || nam % 400 == 0)
				{
					ngayhan += 29 - ngay;
				}
				else
				{
					ngayhan += 28 - ngay;
				}
				thang++; ngay = 0;
				if (m == 13)
				{
					// Tang nam.gan thang = 1
					nam++; thang = 1;
				}
			}
		}
	}

}
//-------------------Tra hang --------------------------------
void Tra_hang(DS_NHAN_VIEN &ds_nv, DS_VATTU &ds_vt)
{
	Nhap_tra_hang:
	string tam;
	gotoxy(83, 6);
	cout << ""; getline(cin, tam); // Nhap so hoa don vao de in chi tiet hoa don.
	int a = Kt_sohd_trung(ds_nv, tam);
	
	if (a < 0)
	{
		gotoxy(50, 30);
		cout << "So hoa don khong ton tai. Moi nhap lai ma hoa donn.";
		system("pause");
		clear_screen(50, 5, 115, 34);
		menu_trahang();
		return(Tra_hang(ds_nv,ds_vt));
		//goto Nhap_tra_hang;
	}
	else
	{
		int j = 0;// toa do diem y .
				  //int stt_nv_hd = Lay_sohd(ds_nv, tam);
		HOA_DON *p = ds_nv.ds[a]->danh_sach_hd.pheap;

		while (p != NULL)
		{
			if (p->soHD == tam)
			{
				gotoxy(115, 11);
				cout << "" << ds_nv.ds[a]->MANV;
				gotoxy(111, 10);
				cout << "" << p->NGAYLAPHOADON.ngay;
				gotoxy(115, 10);
				cout << "/" << p->NGAYLAPHOADON.thang;
				gotoxy(119, 10);
				cout << "/" << p->NGAYLAPHOADON.nam;
				gotoxy(120, 12);
				cout << "" << ds_nv.ds[a]->HO;
				gotoxy(127, 12);
				cout << "" << ds_nv.ds[a]->TEN;
				if (p->LOAI == 0)
				{
					gotoxy(113, 13);
					cout << "Nhap";
				}
				else
				{
					gotoxy(113, 13);
					cout << "Xuat";
				}


				for (int k = 0; k < p->ds_ct_hoadon.sl_ct_hd; k++) // DUyet het chi tiet hoa don cua hoa don nhap vao.
				{
					//if (p->ds_ct_hoadon)
					gotoxy(68, j + 17);
					cout << p->ds_ct_hoadon.ct_hd[k].MAVT;
					gotoxy(80, j + 17);
					cout << p->ds_ct_hoadon.ct_hd[k].SOLUONG;
					gotoxy(96, j + 17);
					cout << p->ds_ct_hoadon.ct_hd[k].DONGIA;
					gotoxy(110, j + 17);
					cout << p->ds_ct_hoadon.ct_hd[k].VAT;
					gotoxy(125, j + 17);
					cout << p->ds_ct_hoadon.ct_hd[k].TRANGTHAI;
					j++;
				}

			}
			p = p->pnext;
		}
	}

	Nhap_vat_tu_de_tra_hang:
	string mavt_t;
	int hantra = 0;
	
	gotoxy(50, 27);
	cout << ""; // NHap vao ma vat tu can tra hang.
	getline(cin, mavt_t);
	HOA_DON *p = ds_nv.ds[a]->danh_sach_hd.pheap;

	kt_ngay(p->NGAYLAPHOADON.nam,p->NGAYLAPHOADON.thang, p->NGAYLAPHOADON.ngay,hantra,ds_nv);
	gotoxy(50, 28);
	cout << hantra;
	while (p != NULL)
	{
		if (p->soHD == tam)
		{
			if (hantra > 3)
			{
				cout << "Vat tu da qua han tra. Moi nhap lai vat tu muon tra....";
				system("pause");
				clear_screen(50, 27, 115, 34);
				goto Nhap_vat_tu_de_tra_hang;
				menu_trahang();
				
			}
			else
			{
				if (p->LOAI == 0)// Neu hoa don la "hoa don nhap" thi khong tra hang.
				{
					cout << "Loai hoa don nhap nay khong the tra hang. Moi nhap lai...";
					system("pause");
					clear_screen(50, 27, 115, 34);
					goto Nhap_vat_tu_de_tra_hang;
				}
				else
				{
					for (int k = 0; k < p->ds_ct_hoadon.sl_ct_hd; k++) // DUyet het chi tiet hoa don cua hoa don nhap vao.
					{
						int vitri_vt = lay_vt_mavt_trong_hd(p->ds_ct_hoadon, mavt_t);
						if (vitri_vt < 0)
						{
							cout << "Ma vat tu khong co trong hoa don, moi kiem tra lai.";
							system("pause");
							clear_screen(50, 27, 115, 34);
							goto Nhap_vat_tu_de_tra_hang;
						}
						else
						{
							if (p->ds_ct_hoadon.ct_hd[k].TRANGTHAI == 0)
							{
								cout << "Vat tu nay da duoc tra lai. Moi nhap vat tu khac...";
								system("pause");
								clear_screen(50, 27, 115, 34);
								goto Nhap_vat_tu_de_tra_hang;
							}
							else
							{
								hieu_chinh_soluongton_N(ds_vt.tree_ds_vt, mavt_t, p->ds_ct_hoadon.ct_hd[k].SOLUONG);
								p->ds_ct_hoadon.ct_hd[k].TRANGTHAI = 0;
								gotoxy(50, 9);
								cout << "Tra hang thanh cong...";
								break;
							}
						}
					}
				}
			}
		}
		p = p->pnext;
	}

}

//--------------In hoa don -----------------------------------------------
void In_hoadon(DS_NHAN_VIEN ds_nv)
{
	string tam;
	gotoxy(83, 6);
	Nhap_hoa_don:
	cout << ""; getline(cin, tam);
	int a = Kt_sohd_trung(ds_nv, tam);
	//ds_nv.ds[a]->danh_sach_hd.pheap->ds_ct_hoadon = new ds_ct_hoadon;
	if (a < 0)
	{
		gotoxy(50, 30);
		cout << "So hoa don khong ton tai. Moi nhap lai...";
		goto Nhap_hoa_don;
		return;
	}
	else
	{
		int j = 0;// toa do diem y .
				  //int stt_nv_hd = Lay_sohd(ds_nv, tam);
		HOA_DON *p = ds_nv.ds[a]->danh_sach_hd.pheap;

		while (p != NULL)
		{
			if (p->soHD == tam)
			{
				gotoxy(115, 11);
				cout << " " << ds_nv.ds[a]->MANV;
				gotoxy(111, 10);
				cout << " " << p->NGAYLAPHOADON.ngay;
				gotoxy(115, 10);
				cout << "/" << p->NGAYLAPHOADON.thang;
				gotoxy(119, 10);
				cout << "/" << p->NGAYLAPHOADON.nam;
				gotoxy(120, 12);
				cout << " " << ds_nv.ds[a]->HO;
				gotoxy(127, 12);
				cout << " " << ds_nv.ds[a]->TEN;
				if (p->LOAI == 0)
				{
					gotoxy(113, 13);
					cout << "Nhap";
				}
				else
				{
					gotoxy(113, 13);
					cout << "Xuat";
				}


				for (int k = 0; k < p->ds_ct_hoadon.sl_ct_hd; k++) // DUyet het chi tiet hoa don cua hoa don nhap vao.
				{
					//if (p->ds_ct_hoadon)
					gotoxy(68, j + 17);
					cout << p->ds_ct_hoadon.ct_hd[k].MAVT;
					gotoxy(80, j + 17);
					cout << p->ds_ct_hoadon.ct_hd[k].SOLUONG;
					gotoxy(96, j + 17);
					cout << p->ds_ct_hoadon.ct_hd[k].DONGIA;
					gotoxy(110, j + 17);
					cout << p->ds_ct_hoadon.ct_hd[k].VAT;
					gotoxy(125, j + 17);
					cout << p->ds_ct_hoadon.ct_hd[k].TRANGTHAI;
					j++;
				}

			}
			p = p->pnext;
		}
	}


}