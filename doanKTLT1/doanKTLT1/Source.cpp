#include"console.h"
#include<iostream>
#include<conio.h>
#include<iomanip>
#define MAUNEN 1
#define MAUCHU 7
using namespace std;
typedef char str[31];
str thaotac[2] = { "TEACHER","STUDENT" };
enum TRANGTHAI{UP, DOWN, LEFT, RIGHT, ENTER, BACK};
//1 phim mui ten len,xuong ,phai ,trai deu tra ve gia tri kep, muon xac dinh no co 2 cong doan
//1:kieu int la 224
//2:kieu char

TRANGTHAI key(int z)//1:lên 2:xuống,3:enter
{
	if (z == 224) {
		char c;
		c = _getch();
		if (c == 72)return UP;
		if (c == 80)return DOWN;
		if (c == 77)return RIGHT;
		if (c == 75)return LEFT;
	}
	else if (z == 13) return ENTER;
}
int menu(str thaotac[2], int n) {
	int tt = 0;// bien chi ra dang o thao tac nao , tt=0 la chi thao tac 1
		int* mau = new int[n];
		for (int i = 0; i < n; i++) 
			mau[i] = MAUCHU;
		mau[0] = MAUNEN;//dang o thao tac 1
		//dung vong while vo han cho den khi tra ve gia tri ham thi tu dong dung
		while (1) {
			//in ra man hinh giao dien menu
			clrscr();//reset lai man hinh
			for (int i = 0; i < n; i++) {
				TextColor(mau[i]);//doi mau chu cho chu chuan bi in ra man hinh
				cout <<setw(50)<< i + 1<<") " << thaotac[i] << endl;
			}
			int z = _getch();
			TRANGTHAI trangthai = key(z);
			switch (trangthai)
			{
			case UP: {
				if (tt == 0) {
					tt = n - 1;
				}
				else {
					tt--;
				}
				break;
			}
			case DOWN: {
				if (tt == n - 1) {
					tt = 0;
				}
				else{
					tt++;
				}
				break;
			}
			case ENTER: return tt;
			}
			//reset lai mau truoc khi chon lai thao tac de in ra
			for (int i = 0; i < n; i++)
				mau[i] = MAUCHU;
			mau[tt] = MAUNEN;
			delete[]mau;
		}
}
int main() {
	//system("color xx") x dau la mau chu, x sau la mau nen
	cout<<menu(thaotac, 2);
	system("pause");
	return 0;
}