#pragma once
#include<iostream>
#include<Windows.h>
#include"mylib.h"
#include"xuly.h"
#include"khaibao.h"
#include"chuanhoa.h"
#include"file.h"
#include <stdio.h>
#include <dos.h>
#include <string.h>
#include"Menu1.h"

#define consolewitgh 720 //mac dinh chieu doc man hinh console la 720
#define consolehight 1360  //mac dinh chieu ngang man hinh console la 1360


using namespace std;



const int so_item = 16;
const int dong = 11;
const int cot = 4;
const int Up = 72;
const int Down = 80;
const int BACK = 27;
const int ENTER = 13;


char thucdon[so_item][50] = {
"Them vat tu                             ",
"Xoa vat tu                              ",
"Chinh sua vat tu                        ",
"In danh sach vat tu                     ",
"Them nhan vien                          ",
"Xoa nhan vien                           ",
"Chinh sua nhan vien                     ",
"In danh sach nhan vien                  ",
"Lap hoa don nhap                        ",
"Lap hoa don xuat                        ",
"Tra hang                                ",
"In hoa don                              ",
"Liet ke hoa don do 1 nhan vien da nhap  ",
"In doanh thu thang trong 1 nam          ",
"Thoat.                                  " };


void HighLight() {
	SetColor(15);
	SetBGColor(2);
}
void Normal() {
	SetColor(2);
	SetBGColor(0);
}


int MenuDong(char td[so_item][50]) {
	Normal();
	int chon = 0;
	int i;
	for (i = 0; i < so_item; i++)
	{
		gotoxy(cot, dong + i);
		cout << td[i];
	}
	HighLight();
	gotoxy(cot, dong + chon);
	cout << td[chon];
	char kytu;
	do {
		kytu = _getch();
		if (kytu == -32) kytu = _getch();
		switch (kytu) 
		{
		   case Up:if (chon > 0)
		   {

			   Normal();
			   gotoxy(cot, dong + chon); cout << td[chon];
			   chon--;
			   HighLight();
			   gotoxy(cot, dong + chon); 	cout << td[chon];
		   }
				break;
		   case Down:if (chon + 1 < so_item)
		   {
			   Normal();
			   gotoxy(cot, dong + chon);	cout << td[chon];
			   chon++;
			   HighLight();
			   gotoxy(cot, dong + chon); 	cout << td[chon];

		   }
				  break;
		   case ENTER: return chon + 1;
		}  // end switch
	} while (1);
}


int main()
{

	resizeConsole(consolehight, consolewitgh);
	SetConsoleTitle(TEXT("QUAN LY VAT TU"));

	//== Khai bao ==
	DS_NHAN_VIEN ds_nv;
	ds_ct_hoadon ds_ct_hd;
	TREE_VATTU c;
	DS_VATTU ds_vt;
	DS_HOA_DON ds_hd;



	//==GHI file====
	doc_file_nv(ds_nv);
	doc_file_vt(ds_vt);
	menuu();
	//clear_screen(50, 5, 110, 34);
	int chon;
	char key;
	int vitriy = 10;
	while (1) {
		ancontro();
		chon = MenuDong(thucdon);
		switch (chon) {

		case 1: gotoxy(5, 4);
			hiencontro();
			cout << "Them vat tu  " << chon;
			//clear_screen(15, 41, 120, 42);
			clear_screen(50, 5, 115, 34);
			menu_nhapvt();
			Nhap_vat_tu(ds_vt);
			break;
		case 2:gotoxy(5, 4);
			hiencontro();
			cout << "Xoa vat tu" << chon;
			//clear_screen(15, 41, 120, 42);
			clear_screen(50, 5, 115, 34);
			menu_xoa_vt();
			Xoa_vat_tu(ds_vt);
			clear_screen(50, 5, 115, 34);
			break;
		case 3: gotoxy(5, 4);
			hiencontro();
			cout << "Chinh sua vat tu " << chon;
			//clear_screen(15, 41, 120, 42);
			clear_screen(50, 5, 115, 34);
			menu_hieuchinh_vt();
			hieu_chinh_vattu(ds_vt);
			break;
		case 4: gotoxy(5, 4);
			//hiencontro();
			cout << "In danh sach vat tu " << chon;
			//clear_screen(15, 41, 120, 42);
			clear_screen(50, 5, 115, 34);
			menu_xuat_ds_vt();
			In_ds_vat_tu_giam_dan(ds_vt.tree_ds_vt);
			gotoxy(50, 30);
			SetBGColor(2);
			cout << ds_vt.sl_vt;
			break;
		case 5:gotoxy(5, 4);
			hiencontro();
			cout << "Them nhan vien " << chon;
			//clear_screen(15, 41, 120, 42);
			clear_screen(50, 5, 115, 34);
			menu_nhap_nv();
			them_nhan_vien(ds_nv);
			clear_screen(50, 5, 115, 34);
			break;
		case 6: gotoxy(5, 4);
			hiencontro();
			cout << "Xoa nhan vien " << chon;
			//clear_screen(15, 41, 120, 42);
			clear_screen(50, 5, 115, 34);
			menu_xoa_nv();
			Xoa_nhan_vien(ds_nv);
			break;
		case 7: gotoxy(5, 4);
			hiencontro();
			cout << "Chinh sua nhan vien " << chon;
			//clear_screen(15, 41, 120, 42);
			clear_screen(50, 5, 115, 34);
			menu_hieuchinh_nv();
			Hieu_chinh_nv(ds_nv);
			break;
		case 8:gotoxy(5, 4);
			//hiencontro();
			cout << "Xuat danh sach nhan vien " << chon;
			//clear_screen(15, 41, 120, 42);
			clear_screen(50, 5, 115, 34);
			menu_xuat_ds_nv();
			Bubble_Sort(ds_nv);
			xuat_ds_nhanvien(ds_nv);
			break;
		case 9: gotoxy(5, 4);
			hiencontro();
			cout << "Lap hoa don nhap" << chon;
			//clear_screen(15, 41, 120, 42);
			clear_screen(50, 5, 115, 34);

			menu_lap_hoadon();
			Lap_hoa_don_N(ds_nv, ds_vt);
			break;
		case 10: gotoxy(5, 4);
			hiencontro();
			cout << "Lap hoa don xuat " << chon;
			//clear_screen(15, 41, 120, 42);
			clear_screen(50, 5, 115, 34);
			menu_lap_hoadon();
			Lap_hoa_don_X(ds_nv, ds_vt);
			break;
		case 11:gotoxy(5, 4);
			hiencontro();
			cout << "Tra hang " << chon;
			//clear_screen(15, 41, 120, 42);
			clear_screen(50, 5, 115, 34);
			menu_trahang();
			Tra_hang(ds_nv,ds_vt);
			break;
		case 12: gotoxy(5, 4);
			hiencontro();
			cout << "In hoa don " << chon;
			//clear_screen(15, 41, 120, 42);
			clear_screen(50, 5, 115, 34);
			menu_xuat_ds_hd();
			In_hoadon(ds_nv);
			break;
		case 13: gotoxy(5, 4);
			cout << "Liet ke hoa don " << chon;
			//clear_screen(15, 41, 120, 42);
			hiencontro();
			clear_screen(50, 5, 115, 34);

			break;
		case 14:gotoxy(5, 4);
			hiencontro();
			cout << "In doanh thu thang trong 1 nam " << chon;
			//clear_screen(15, 41, 120, 42);
			clear_screen(50, 5, 115, 34);
			break;

		case 15:gotoxy(5, 4);
			ghi_file_nv(ds_nv);
			Ghi_file_vt(ds_vt);
			exit(0);
		case so_item: return 0;
		}
		key = _getch();
		if (key == BACK) {
			break;
		}
	}
	system("pause");
	_getch();
	return 0;

}
