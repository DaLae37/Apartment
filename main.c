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
	system("title ����Ʈ");
	int in, out, what, x, y, bo, to;
	int day = 0, people = 0, love = 100, money = 0, zero = 0, police = 1, sos = 0;
	static int a[20][20];
	while (1)
	{
		system("cls");
		if (sos >= 3 && sos % 3 == 0)
		{
			sos++;
			Gotoxy(15, 10); printf("���� ���� �׸����Ƥ�����");
			getch();
			continue;
		}
		if (day > 100)
		{
			Gotoxy(20, 20); printf("����.....");
			break;
		}
		Gotoxy(45, 2); printf("%d ��", day);
		Gotoxy(45, 4); printf("�ֹμ� : %d��", people);
		Gotoxy(45, 6); printf("�ູ�� : %d", love);
		Gotoxy(45, 8); printf("�� : %d��", money);
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
			Gotoxy(20, 20); printf("����");
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
					printf("��");
				}
				else if (a[i][j] == 1)
				{
					printf("��");
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
						printf("��");
					}
					else if (a[i][j] == 1)
					{
						printf("��");
					}
				}
				puts("");
			}
			Gotoxy(45, 2); printf("%d ��", day);
			Gotoxy(45, 4); printf("�ֹμ� : %d��", people);
			Gotoxy(45, 6); printf("�ູ�� : %d", love);
			Gotoxy(45, 8); printf("�� : %d��", money);
			Gotoxy(2, 22); printf("1 : �޽�  2 : ������ ¡��  3 : ������ ����  4 : ����");
			Gotoxy(2, 24); scanf("%d", &what);
			if (what == 1)
			{
				Gotoxy(1, 25); printf("�޽��� �����ϼ̽��ϴ�");
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
					Gotoxy(1, 25); printf("�ֹ��� �����ϴ�");
					getch();
					continue;
				}
				Gotoxy(1, 25); printf("������ ¡�� �߽��ϴ�");
				getch();
				x = rand() % 10 + 1;
				money += people * 100;
				love -= x;
				break;
			}
			else if (what == 3)
			{
				Gotoxy(1, 25); printf("������ ���� �߽��ϴ�");
				getch();
				y = rand() & 10 + 1;
				money -= people * 90;
				if (money < 0)
				{
					Gotoxy(1, 25); printf("���� �����մϴ�");
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
					Gotoxy(2, 10); printf("1. ����Ʈ û��(�ູ+5) : -900��");
					Gotoxy(2, 11); printf("2. ����Ʈ ��������(�ູ+15) : -3000��");
					Gotoxy(2, 12); printf("3. ����Ʈ ȫ�� (�ֹ�+1) : -4000��");
					if (police == 1)
					{
						Gotoxy(2, 13); printf("4. ��� �ذ�(�ູ-5) : +1000��");
					}
					Gotoxy(2, 14); printf("5. ���� ������");
					Gotoxy(2, 20); scanf("%d", &to);
					if (to == 1)
					{
						money -= 900;
						if (money < 0)
						{
							money += 900;
							Gotoxy(2, 21); printf("���� �����մϴ�");
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
							Gotoxy(2, 21); printf("���� �����մϴ�");
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
							Gotoxy(2, 21); printf("���� �����մϴ�");
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
				Gotoxy(1, 25); printf("���� �޴� �Դϴ�");
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