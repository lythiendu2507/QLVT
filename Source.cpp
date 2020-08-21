#include"mylib.h"

using namespace std;


const int so_item = 16;
const int dong = 11;
const int cot = 4;
const int Up = 72;
const int Down = 80;
const int BACK = 27;
const int ENTER = 13;



char menu[so_item][50] = {
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


int main()
{

	



	int c;
	int chon = 0;
	
	do
	{
		gotoxy(TOADOX, TOADOY + 9 + chon * 6);
		VeHinhChuNhat(TOADOX, TOADOY + 9 + chon * 6, WIDTH_MENU_BAR, 3, BLACK);
		gotoxy(TOADOX + (WIDTH_MENU_BAR - menu[chon].length()) / 2, TOADOY + 10 + chon * 6);
		//SetColor(7);
		//SetBGColor(BLACK);
		cout << menu[chon];
		c = KeyPressed();
		if (c == KEY_DOWN)
		{
			VeHinhChuNhat(TOADOX, TOADOY + 9 + chon * 6, WIDTH_MENU_BAR, 3, CYAN);
			SetColor(WHITE);
			SetBGColor(CYAN);
			gotoxy(TOADOX + (WIDTH_MENU_BAR - menu[chon].length()) / 2, TOADOY + 10 + chon * 6);
			cout << menu[chon];
			for (int i = 0; i < WIDTH_MENU_BAR; i++)
			{
				gotoxy(TOADOX + i, TOADOY + 9 + chon * 6);
				cout << char(196);
				gotoxy(TOADOX + i, TOADOY + 11 + chon * 6);
				cout << char(196);
			}
			if (chon <= 4)
			{
				chon++;
				if (chon == 5) chon = 0;
			}
		}
		if (c == KEY_UP)
		{
			VeHinhChuNhat(TOADOX, TOADOY + 9 + chon * 6, WIDTH_MENU_BAR, 3, CYAN);
			SetColor(WHITE);
			SetBGColor(CYAN);
			gotoxy(TOADOX + (WIDTH_MENU_BAR - menu[chon].length()) / 2, TOADOY + 10 + chon * 6);
			cout << menu[chon];
			for (int i = 0; i < WIDTH_MENU_BAR; i++)
			{
				gotoxy(TOADOX + i, TOADOY + 9 + chon * 6);
				cout << char(196);
				gotoxy(TOADOX + i, TOADOY + 11 + chon * 6);
				cout << char(196);
			}
			if (chon >= 0)
			{
				chon--;
				if (chon == -1) chon = 4;
			}
		}
		if (c == KEY_ENTER)
		{
			switch (chon)
			{
			case 0:
				DuyetDanhSachVatTu(ds, root);
				XoaManHinh();
				VeFooter("Esc: Thoat");
				break;
			case 1:
				DuyetDanhSachNhanVien(ds, root);
				XoaManHinh();
				VeFooter("Esc: Thoat");
				break;
			case 2:
				InHoaDon(ds, root);
				XoaManHinh();
				VeFooter("Esc: Thoat");
				break;
			case 3:
				ModuleThongKeHoaDon(ds);
				XoaManHinh();
				VeFooter("Esc: Thoat");
				break;
			case 4:
				ModuleThongKeVatTu(ds, root);
				XoaManHinh();
				VeFooter("Esc: Thoat");
				break;
			}
		}
	} while (c != KEY_ESC);
	if (c == KEY_ESC)
	{
		GhiFile(ds);
		GhiFile(root);
		XoaCay(root);
		XoaDanhSach(ds);
		system("cls");
		exit(1);
	}
}