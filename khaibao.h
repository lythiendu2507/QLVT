#pragma once
#include<iostream>
#include<string>
#include<fstream>

//Ma vat tu co toi da la 10 ky tu
#define max_vt 10

//Ten vat tu co toi da la 50 ký tu 
#define max_tenvt 50

//Danh sach nhan vien co toi da 500nv
#define max_nv  500

//so ky tu toi da cua so hoa don
#define max_hd  20

//Mot chi tiet hoa don co toi da 20 vat tu 
#define max_ct_hd 20

using namespace std;



//----------- kb: danhsach chi tiet hoadon ----------------------
struct ct_hoadon
{
	string MAVT;
	float SOLUONG;
	int  DONGIA;
	float VAT;//% thue
	bool TRANGTHAI; //1 = khach mua ;;0 = khach tra
};
typedef struct ct_hoadon CT_HOADON;


struct ds_ct_hoadon
{
	CT_HOADON ct_hd[max_ct_hd];
	int sl_ct_hd = 0;
};
typedef struct ct_ds_hoadon DS_CT_HOADON;


//----------- kb: danhsach hoadon ----------------------
struct ngaythang {
	int ngay;
	int thang;
	int nam;
};
struct hoa_don
{
	string soHD;
	ngaythang NGAYLAPHOADON; // lap them struct ngay thang nam 
	bool LOAI;  //x:1 la xuat , n:0 la nhap
				//*ctds_hoadon
	ds_ct_hoadon ds_ct_hoadon;

	hoa_don* pnext;
};
typedef struct hoa_don HOA_DON;


struct ds_hoadon
{
	HOA_DON* pheap = NULL;
	int sl_hd = 0;
};
typedef struct ds_hoadon DS_HOA_DON;


//----------- kb: Vat tu ----------------------
struct vattu
{
	string MA_VT;
	string TEN_VT;
	string DONVITINH;
	float SOLUONGTON;

	vattu *pleft;
	vattu *pright;
};
typedef struct vattu* TREE_VATTU;

struct ds_vattu
{
	TREE_VATTU tree_ds_vt = NULL;
	int sl_vt = 0;

};
typedef struct ds_vattu DS_VATTU;




//----------- kb: Nhan vien ----------------------

struct nhanvien
{
	int MANV;
	string HO;
	string TEN;
	bool PHAI;  // 0: La nv phai nu .. 1: La nv phai nam
	int SO_CMND;
	//*dshd
	DS_HOA_DON danh_sach_hd;
	bool kt;//true : nv da lap hoa don, //false nv chua lap hoa don.

};
typedef struct nhanvien NHAN_VIEN;

struct ds_nhanvien
{
	NHAN_VIEN *ds[max_nv];
	int sl_nv = 0;
};
typedef struct ds_nhanvien DS_NHAN_VIEN;