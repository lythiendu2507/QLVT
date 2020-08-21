#pragma once
#include"mylib.h"
#include<iostream>
using namespace std;


//==========================================MENU NHAN VIEN==============================================
void menu_nhap_nv()
{
	SetBGColor(2);
	gotoxy(50, 7);
	cout << "                              NHAP NHAN VIEN              "; 
	gotoxy(50, 10);
	cout << "NHAP MA NHAN VIEN:          ";
	gotoxy(50, 12);
	cout << "NHAP HO NHAN VIEN:          ";
	gotoxy(50, 14);
	cout << "NHAP TEN NHAN VIEN:         ";
	gotoxy(50, 16);
	cout << "NHAP PHAI NHAN VIEN:        ";
	gotoxy(50, 18);
	cout << "NHAP SO CMND CUA NHAN VIEN: ";
	gotoxy(50, 34);
	cout << "HUONG DAN NHAP: Ma nhan vien thi khong duoc trung.                     ";
	gotoxy(50, 35);
	cout << "                So CMND khong duoc trung                               ";
	gotoxy(50, 36);
	cout << "                Phai nhan vien chi nhan 2 gia tri: 1 = NAM; 0 = NU     ";


}

void menu_xoa_nv()
{
	SetBGColor(2);
	gotoxy(50, 4);
	cout << "                     ================ XOA NHAN VIEN ==============   ";
	gotoxy(50, 34);
	cout << "Nhan vien da lap hoa don thi khong the xoa !!!";
	gotoxy(50,10);
	cout << "NHAP MA NHAN VIEN CAN XOA: ";
	gotoxy(50, 22);
	cout << "HUONG DAN NHAP: Nhan vien da lap hoa don thi khong the bi xoa.";
}

void menu_hieuchinh_nv()
{
	SetBGColor(2);
	SetColor(WHITE);
	gotoxy(50, 7);
	cout << "                              HIEU CHINH NHAN VIEN             ";
	gotoxy(50, 10);
	cout << "NHAP MA NHAN VIEN MUON HIEU CHINH:         ";
	gotoxy(50, 12);
	cout << "NHAP HO NHAN VIEN:                         ";
	gotoxy(50, 14);
	cout << "NHAP TEN NHAN VIEN:                        ";
	gotoxy(50, 16);
	cout << "NHAP PHAI NHAN VIEN:                       ";
	gotoxy(50, 18);
	cout << "CMND CUA NHAN VIEN:                        ";
	gotoxy(50, 22);
	cout << "HUONG DAN NHAP: Ma nhan vien va so CMND khong the hieu chinh.";
}

void menu_xuat_ds_nv()
{
	gotoxy(50,4);
	cout << "                     ================ DANH SACH NHAN VIEN ==============";
	gotoxy(50,7);
	cout << "MA NV       HO              TEN          PHAI      SO CMND         HOA DON DA LAP";
}
//==========================================MENU VAT TU==============================================
void menu_nhapvt()
{
	SetBGColor(2);
	SetColor(WHITE);
	gotoxy(50, 7);
	cout << "                              NHAP VAT TU              ";
	gotoxy(50, 10);
	cout << "NHAP MA VAT TU:         ";
	gotoxy(50, 12);
	cout << "NHAP TEN VAT TU:        ";
	gotoxy(50, 14);
	cout << "NHAP DON VI TINH:       ";
	gotoxy(50, 18);
	cout << "NHAP SO LUONG TON:      ";
	gotoxy(50, 22);
	cout << "HUONG DAN NHAP: Ma vat tu khong duoc trung.";
	
}

void menu_xoa_vt()
{
	SetBGColor(2);
	gotoxy(50, 4);
	cout << "                     ================ XOA VAT TU ==============   ";

	gotoxy(50, 10);
	cout << "NHAP MA VAT TU CAN XOA: ";
	gotoxy(50, 22);
	cout << "HUONG DAN NHAP: .";
}

void menu_hieuchinh_vt()
{
	SetBGColor(2);
	SetColor(WHITE);
	gotoxy(50, 7);
	cout << "                              HIEU CHINH VAT TU             ";
	gotoxy(50, 10);
	cout << "NHAP MA VAT TU MUON HIEU CHINH:         ";
	gotoxy(50, 14);
	cout << "NHAP TEN VAT TU:                         ";
	gotoxy(50, 16);
	cout << "NHAP DON VI TINH:                        ";
	gotoxy(50, 18);
	cout << "SO LUONG TON:                        ";
	gotoxy(50, 22);
	cout << "HUONG DAN NHAP: Ma vat tu va so luong ton khong the hieu chinh.";
}

void menu_xuat_ds_vt()
{
	SetBGColor(2);
	SetColor(WHITE);
	gotoxy(50, 4);
	cout << "                     ================ DANH SACH VAT TU TON KHO ==============";
	gotoxy(50, 7);
	cout << "MA VAT TU       TEN VAT TU                   DON VI TINH             SO LUONG TON";
}


//==========================================MENU HOA DON========================================================

void menu_lap_hoadon()
{
	SetBGColor(2);
	gotoxy(50, 4);
	cout << "                     ================ LAP HOA DON ==============   ";
	gotoxy(50, 8);
	cout << "NHAP MA NHAN VIEN LAP HOA DON:       ";
	gotoxy(50, 10);
	cout << "NHAP SO HOA DON:                     ";
	gotoxy(50, 14);
	cout << "NHAP NGAY LAP HOA DON:    /  /     .";


	gotoxy(50, 22);
	cout << "HUONG DAN NHAP: Nhan vien da lap hoa don thi khong the bi xoa.";
}





void menu_xuat_ds_hd()
{
	//SetBGColor(2);
	SetColor(WHITE);
	gotoxy(50, 4);
	cout << "                     ================ DANH SACH HOA DON ==============";
	gotoxy(50, 6);
	cout << "NHAP SO HOA DON DE IN DANH SACH: ";
	gotoxy(50, 8);
	cout << "                                          BANG LIET KE CHI TIET HOA DON                                                      ";
	gotoxy(50, 10);
	cout << "                                                  NGAY LAP: ";
	gotoxy(50, 11);
	cout << "                                              MA NHAN VIEN LAP: ";
	gotoxy(50, 12);
	cout << "                                              HO TEN NHAN VIEN LAP: ";
	gotoxy(50, 13);
	cout << "                                                  LOAI: ";
	gotoxy(50, 15);
	cout << "                  MAVT        SOLUONG          DONGIA         VAT           TRANG THAI";
}



void menu_trahang()
{
	//SetBGColor(2);
	SetColor(WHITE);
	gotoxy(50, 4);
	cout << "                     ================ MENU TRA HANG ==============";
	gotoxy(50, 6);
	cout << "NHAP SO HOA DON DE TRA HANG: ";
	gotoxy(50, 8);
	cout << "                                          BANG LIET KE CHI TIET HOA DON                                                      ";
	gotoxy(50, 10);
	cout << "                                                  NGAY LAP: ";
	gotoxy(50, 11);
	cout << "                                              MA NHAN VIEN LAP: ";
	gotoxy(50, 12);
	cout << "                                              HO TEN NHAN VIEN LAP: ";
	gotoxy(50, 13);
	cout << "                                                  LOAI: ";
	gotoxy(50, 15);
	cout << "                  MAVT        SOLUONG          DONGIA         VAT           TRANG THAI";

	gotoxy(50,35);
	cout << "NHAP VAT TU CAN TRA: ";
}

//=====================================================menu chinh ==============================================



void ve_khung_tren()
{
	SetBGColor(2);
	int x = 0, y = 0;
	gotoxy(x, y);
	while (x<166)
	{
		cout << " ";
		x++;
	}
}
void ve_khung_duoi()
{
	SetBGColor(2);
	int x = 1, y = 42;
	gotoxy(x, y);
	while (x<166)
	{
		gotoxy(x, y);
		cout << " ";
		x++;
	}
}

void ve_khung_duoi1()
{
	SetBGColor(2);
	int x = 1, y = 39;
	gotoxy(x, y);
	while (x<166)
	{
		gotoxy(x, y);
		cout << " ";
		x++;
	}
}

void ve_khung_phai()
{
	SetBGColor(2);
	int x = 164, y = 0;
	gotoxy(x, y);
	while (y<44)
	{
		gotoxy(x, y);
		cout << " ";
		y++;
	}
}

void ve_khung_trai()
{
	int x = 0, y = 0;
	gotoxy(x, y);
	while (y<44)
	{
		gotoxy(x, y);
		cout << " ";
		y++;
	}
}
void ve_khung_giua()
{
	int x = 48, y = 1;
	gotoxy(x, y);
	while (y<39)
	{
		gotoxy(x, y);
		cout << " ";
		y++;
	}
}

void khung_luachon()
{
	int x = 1, y = 6;
	gotoxy(x, y);
	while (x<48)
	{
		gotoxy(x, y);
		cout << " ";
		x++;
	}
}

void khung_huong_dan()
{
	int x = 1, y = 33;
	gotoxy(x, y);
	while (x<48)
	{
		gotoxy(x, y);
		cout << " ";
		x++;
	}
}

void huong_dan()
{
	SetColor(2);
	SetBGColor(0);
	gotoxy(2, 35);
	cout << "* HUONG DAN: Dung phim 4 phim mui ten de ";
	gotoxy(2, 36);
	cout << "   di chuyen, ESC de thoat,";
	gotoxy(2, 37);
	cout << "   ENTER de chon.";
	gotoxy(5, 41);
	cout << "*THONG BAO: ";
}






void menuu()
{

	ve_khung_duoi();
	ve_khung_tren();
	ve_khung_trai();
	ve_khung_phai();
	ve_khung_giua();
	ve_khung_duoi1();
	khung_huong_dan();
	khung_luachon();
	huong_dan();
	
}




void chac_chan()
{

}