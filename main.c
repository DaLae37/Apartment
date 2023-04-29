#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>

void Gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main(void)
{
	srand((unsigned int)time(NULL));
	system("mode con: cols=60 lines=28");
	system("title 아파트");
	int in, out, what, x, y, bo, to;
	int day = 0, people = 0, love = 100, money = 0, zero = 0, police = 1, sos = 0;
	static int a[20][20];
	while (1)
	{
		system("cls");
		if (sos >= 3 && sos % 3 == 0)
		{
			sos++;
			Gotoxy(15, 10); printf("이제 제발 그마마아ㅏㅇㄴ");
			getch();
			continue;
		}
		if (day > 100)
		{
			Gotoxy(20, 20); printf("실패.....");
			break;
		}
		Gotoxy(45, 2); printf("%d 일", day);
		Gotoxy(45, 4); printf("주민수 : %d명", people);
		Gotoxy(45, 6); printf("행복도 : %d", love);
		Gotoxy(45, 8); printf("돈 : %d원", money);
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				if (a[i][j] ==0)
				{
					zero++;
				}
			}
		}
		if (zero == 0)
		{
			Gotoxy(20, 20); printf("성공");
			break;
		}
		zero = 0;
		for (int i = 0; i < 20; i++)
		{
			Gotoxy(1, i + 1);
			for (int j = 0; j < 20; j++)
			{
				if (a[i][j] == 0)
				{
					printf("□");
				}
				else if (a[i][j] == 1)
				{
					printf("■");
				}
			}
			puts("");
		}
		while (1)
		{
			system("cls");
			for (int i = 0; i < 20; i++)
			{
				Gotoxy(1, i + 1);
				for (int j = 0; j < 20; j++)
				{
					if (a[i][j] == 0)
					{
						printf("□");
					}
					else if (a[i][j] == 1)
					{
						printf("■");
					}
				}
				puts("");
			}
			Gotoxy(45, 2); printf("%d 일", day);
			Gotoxy(45, 4); printf("주민수 : %d명", people);
			Gotoxy(45, 6); printf("행복도 : %d", love);
			Gotoxy(45, 8); printf("돈 : %d원", money);
			Gotoxy(2, 22); printf("1 : 휴식  2 : 관리세 징수  3 : 관리세 면제  4 : 상점");
			Gotoxy(2, 24); scanf("%d", &what);
			if (what == 1)
			{
				Gotoxy(1, 25); printf("휴식을 선택하셨습니다");
				if (love <= 50)
				{
					out = rand() % 2 + 1;
					if (out == 1)
					{
						for (int i = 0; i < 20; i++)
						{
							for (int j = 0; j < 20; j++)
							{
								if (a[j][i] == 1)
								{
									a[j][i] = 0;
									bo = 1;
									break;
								}
							}
							if (bo = 1)
							{
								break;
							}
						}
						people -= 1;
						love += 5;
					}
				}
				else if (love > 50)
				{
					in = rand() % 2 + 1;
					if (in == 1)
					{
						while (1)
						{
							x = rand() % 20;
							y = rand() % 20;
							if (a[x][y] == 1)
							{
								continue;
							}
							a[x][y] = 1;
							break;
						}
						people += 1;
						love -= 5;
					}
				}
				money += people * 50;
				break;
			}
			else if (what == 2)
			{
				if (people == 0)
				{
					Gotoxy(1, 25); printf("주민이 없습니다");
					getch();
					continue;
				}
				Gotoxy(1, 25); printf("관리비를 징수 했습니다");
				getch();
				x = rand() % 10 + 1;
				money += people * 100;
				love -= x;
				break;
			}
			else if (what == 3)
			{
				Gotoxy(1, 25); printf("관리비를 면제 했습니다");
				getch();
				y = rand() & 10 + 1;
				money -= people * 90;
				if (money < 0)
				{
					Gotoxy(1, 25); printf("돈이 부족합니다");
					money += people * 90;
					getch();
					continue;
				}
				love += y;
				break;
			}
			else if (what == 4)
			{
				while (1)
				{
					system("cls");
					Gotoxy(2, 10); printf("1. 아파트 청소(행복+5) : -900원");
					Gotoxy(2, 11); printf("2. 아파트 보수공사(행복+15) : -3000원");
					Gotoxy(2, 12); printf("3. 아파트 홍보 (주민+1) : -4000원");
					if (police == 1)
					{
						Gotoxy(2, 13); printf("4. 경비 해고(행복-5) : +1000원");
					}
					Gotoxy(2, 14); printf("5. 상점 나가기");
					Gotoxy(2, 20); scanf("%d", &to);
					if (to == 1)
					{
						money -= 900;
						if (money < 0)
						{
							money += 900;
							Gotoxy(2, 21); printf("돈이 부족합니다");
							getch();
							continue;
						}
						love += 5;
					}
					else if (to == 2)
					{
						money -= 3000;
						if (money < 0)
						{
							money += 3000;
							Gotoxy(2, 21); printf("돈이 부족합니다");
							getch();
							continue;
						}
						love += 15;
					}
					else if (to == 3)
					{
						money -= 4000;
						if (money < 0)
						{
							money += 4000;
							Gotoxy(2, 21); printf("돈이 부족합니다");
							getch();
							continue;
						}
						people += 1;
					}
					else if (to == 4 && police == 1)
					{
						police -= 1;
						break;
					}
					else if (to == 5)
					{
						system("cls");
						break;
					}
				}
				if (to == 5)
				{
					system("cls");
					continue;
				}
			}
			else
			{
				Gotoxy(1, 25); printf("없는 메뉴 입니다");
				sos += 1;
				day--;
				break;
			}
		}
		day++;
		Sleep(1000);
	}
	getch();
	return 0;
}