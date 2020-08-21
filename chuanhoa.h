#pragma once 

#include<string>
#include<iostream>
#include<string.h>
using namespace std;

void chuan_hoa_chu(string &a)
{
	//xoa khoang trang o dau 
	while (a[0] == ' ')
	{
		a.erase(a.begin() + 0);
	}
	//xoa dau cach o phia sau 
	
		while (a[a.length() - 1] == ' ')
		{
			a.erase(a.begin() + a.length() - 1);
		}
	
	// dau cach o giua cac ky tu 
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == ' ' && a[i + 1] == ' ')
		{
			a.erase(a.begin() + i + 1);
			i--;
		}
	}
	// sua doi ky tu hoa o chu cai dau  
	if (a[0] > 96 && a[0] < 123)
	{
		a[0] = a[0] - 32;
	}
	// chuan hoa ky tu o cac chu sau
	for (int i = 1; i < a.length(); i++)
	{
		if (a[i] > 64 && a[i] < 91)
		{
			a[i] = a[i] + 32;
		}
	}
	// chuan hoa ky tu sau khoang trang
	for (int i = 1; i < a.length(); i++)
	{
		if (a[i] == ' ')
		{
			a[i + 1] = a[i + 1] - 32;
		}
	}
}


void chuan_hoa_vattu(string &a)
{
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] < 123 && a[i] > 96)
		{
			a[i] = a[i] - 32;
		}
	}
}

string chuan_hoa_vattuu(string &a)
{
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] < 123 && a[i] > 96)
		{
			a[i] = a[i] - 32;
			
		}
	}
	return a;
}


//----------------- khoi tao node vat tu -------------
TREE_VATTU Khoi_tao_node_vat_tu()
{
	TREE_VATTU p = new vattu;
	//cin.ignore();

	p->pright = NULL;
	p->pleft = NULL;
	return p;
}

//----------- Them 1 vat tu --------------------------
void them_vattu(TREE_VATTU &t, TREE_VATTU p)
{
	if (t == NULL)
	{
		t = p;
	}
	else
	{
		if (p->MA_VT > t->MA_VT)
		{
			them_vattu(t->pright, p);
		}
		else if (p->MA_VT < t->MA_VT)
		{
			them_vattu(t->pleft, p);
		}
	}
}

