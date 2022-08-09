#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <graphics.h>
#include <conio.h>
#include "AI.h"
#include "check_currnt.h"
#include "GUI.h"
#include "printing.h"
#ifdef TARGET_OS_MAC
#define slp(x) [NSThread sleepForTimeInterval: x*0.001]
#endif

#ifdef _WIN32
#include <windows.h>
#define slp Sleep
#endif

#ifdef __linux__
#include <unistd.h>;
#define slp(x) sleep(x*0.001)
#endif
extern int zhuang, active, now, ck, wholestate, nowpai, drastate, gangnum, currenting, froming;
extern int i, j, k, r, m, temp, temp1, temphu, temphu1, tempck;
extern int gangr, gangpai, pengr, pengpai, hur, ifzimo, rongnum, jiang, zigangr, lichir, jiagangr;
extern int zimor, guoshiwushuangr, qiduizir, chir, dranum, lidranum, pengtemp, jiagangr1, jiagangr2;
extern int hutype, aaa, abc, q, get, fu, fu1, fan, fan1, point, point1, yiman, dian, danqi, ganghou, yixun, yifa, focus;
extern int chizuo, chiyou, chika;
extern int lichi[5], chistate[4][5][3], peng[4][5], gang[4][9], pengstate[4][5], qipaidui[4][40], state[5];
extern int menqianqing[4], shoupai[5][14], valsp[5], xyz[4], xxx[4], cking[34], chitemp[3], feng1[4], order[136], wlichi[4];
extern char mingzi[4][7], feng[4][5], pai[136][6];
extern int guoshiwushuang[13];

void allichi(int who)//*al代表already，下同 
{
	IMAGE s;
	if (who == 1)
	{
		loadimage(&s, _T(".\\anniu\\立直.png"), 180, 72);
		putimage(880, 260, &s);
		Sleep(2000);
	}
	if (who == 2)
	{
		loadimage(&s, _T(".\\anniu\\立直.png"), 180, 72);
		putimage(600, 100, &s);
		Sleep(2000);
	}
	if (who == 3)
	{
		loadimage(&s, _T(".\\anniu\\立直.png"), 180, 72);
		putimage(360, 250, &s);
		Sleep(2000);
	}
	yifa = who;
	if (yixun > 0)
		wlichi[who] = 1;
	lichi[who] = 1;
}
void putin(int who)//*摸牌
{
	int temp2;
	currenting = 0;
	shoupai[who][valsp[who]] = order[nowpai];
	active = shoupai[who][valsp[who]];
	if (now == 0)
	{
		currenting = 1;
		majiangpai(order[nowpai], 1, 1150, 525);
		Sleep(1500);
	}
	for (i = valsp[who]; (shoupai[who][i] < shoupai[who][i - 1]) && (i > 0); i--)
	{
		temp2 = shoupai[who][i];
		shoupai[who][i] = shoupai[who][i - 1];
		shoupai[who][i - 1] = temp2;
	}
	focus = i;//补丁
	bases();
	Sleep(1000);
	currenting = 0;
	nowpai++;
}

void getout(int chsn, int who)//*打牌
{
	int temp6;
	bases();
	for (i = chsn; i < valsp[who]; i++)
	{
		temp6 = shoupai[who][i];
		shoupai[who][i] = shoupai[who][i + 1];
		shoupai[who][i + 1] = temp6;
	}
	active = shoupai[who][valsp[who]];
	froming = who;
	shoupai[who][valsp[who]] = 0;
	now = (who == 3) ? 0 : (who + 1);
	qipaidui[(now == 0) ? 3 : (now - 1)][0]++;
	temp6 = (qipaidui[(now == 0) ? 3 : (now - 1)][0] > 0) ? (qipaidui[(now == 0) ? 3 : (now - 1)][0]) : 1;
	qipaidui[(now == 0) ? 3 : (now - 1)][temp6] = active;
	bases();
	check();
	bases();
	//slp(500);
	ganghou = 0;
}
void alchi(int who)//*吃牌后程序
{
	IMAGE s;
	if (ck == 1)
	{
		loadimage(&s, _T(".\\anniu\\吃.png"), 180, 72);
		putimage(880, 260, &s);
		slp(2000);
	}
	if (ck == 2)
	{
		loadimage(&s, _T(".\\anniu\\吃.png"), 180, 72);
		putimage(600, 100, &s);
		slp(2000);
	}
	if (ck == 3)
	{
		loadimage(&s, _T(".\\anniu\\吃.png"), 180, 72);
		putimage(360, 250, &s);
		slp(2000);
	}
	int i, j, k, altemp1, altemp2, altemp;
	int altmp[13] = { 0 }, altmp1[13] = { 0 };
	now = ck;
	MOUSEMSG m;
	menqianqing[ck] = 0;
	yixun = 0;
	yifa = -1;
	if (ck != 0)
	{
		strategychi();
	}
	else
	{
		bases();
		setbkmode(TRANSPARENT);
		settextcolor(WHITE);
		LOGFONT f;
		gettextstyle(&f);
		f.lfHeight = 25;
		wcscpy_s(f.lfFaceName, _T("Ink Free"));
		f.lfItalic = 0;
		f.lfWeight = 1500;
		f.lfQuality = ANTIALIASED_QUALITY;
		settextstyle(&f);
		outtextxy(200, 490, _T("请选择用于吃的牌："));
		altemp = active / 4 * 4;
		for (i = 1; i < valsp[0] + 1; i++)
			if (chizuo == 1)
				if (chiyou == 1 && ((shoupai[0][i - 1] > altemp - 9 && shoupai[0][i - 1] < altemp) || (shoupai[0][i - 1] > altemp + 3 && shoupai[0][i - 1] < altemp + 12)))
				{
					altmp[i - 1] = 1;
					continue;
				}
				else if (chiyou == 0 && chika == 1 && ((shoupai[0][i - 1] > altemp - 5 && shoupai[0][i - 1] < altemp) || (shoupai[0][i - 1] > altemp + 3 && shoupai[0][i - 1] < altemp + 12)))
				{
					altmp[i - 1] = 1;
					continue;
				}
				else if (shoupai[0][i - 1] > altemp + 3 && shoupai[0][i - 1] < altemp + 12)
				{
					altmp[i - 1] = 1;
					continue;
				}
				else
					continue;
			else
			{
				if (chiyou == 1 && chika == 0 && shoupai[0][i - 1] > altemp - 9 && shoupai[0][i - 1] < altemp)
				{
					altmp[i - 1] = 1;
					continue;
				}
				else if (chiyou == 1 && ((shoupai[0][i - 1] > altemp - 9 && shoupai[0][i - 1] < altemp) || (shoupai[0][i - 1] > altemp + 3 && shoupai[0][i - 1] < altemp + 8)))
				{
					altmp[i - 1] = 1;
					continue;
				}
				else if ((shoupai[0][i - 1] > altemp - 5 && shoupai[0][i - 1] < altemp) || (shoupai[0][i - 1] > altemp + 3 && shoupai[0][i - 1] < altemp + 8))
				{
					altmp[i - 1] = 1;
					continue;
				}
			}
		while (true)
		{
			int info = 0;
			m = GetMouseMsg();
			if (m.uMsg == WM_LBUTTONUP)
			{
				for (int j = 0; j < valsp[0] + 1; j++)
				{
					if (m.x >= 303 + (13 - valsp[0]) / 3 * 189 + j * 63 && m.y >= 525 && m.y <= 630 && m.x <= 366 + (13 - valsp[0]) / 3 * 189 + j * 63)
					{
						i = j + 1;
						info = 1;
						break;
					}
				}
			}
			if (info == 1)
				break;
		}
		if (altmp[i - 1] == 1)
			altemp1 = i;
		else for (j = 0; j < valsp[ck]; j++)
		{
			if (altmp[j] == 1)
			{
				altemp1 = j + 1;
				break;
			}
		}
		k = shoupai[0][altemp1 - 1] / 4 - altemp / 4;
		setfillcolor(RGB(51, 102, 127));
		POINT pts[] = { {303 + (13 - valsp[0]) / 3 * 189 + (altemp1 - 1) * 63, 475}, {366 + (13 - valsp[0]) / 3 * 189 + (altemp1 - 1) * 63, 475}, {335 + (13 - valsp[0]) / 3 * 189 + (altemp1 - 1) * 63, 525} };
		fillpolygon(pts, 3);
		outtextxy(200, 490, _T("请选择用于吃的牌："));
		if (k == -2)
		{
			chitemp[2] = active;
			chitemp[0] = shoupai[0][altemp1 - 1];
			for (i = 1; i < valsp[0] + 1; i++)
				if (shoupai[0][i - 1] > altemp - 5 && shoupai[0][i - 1] < altemp)
				{
					altmp1[i - 1] = 1;
					continue;
				}
		}
		else if (k == -1)
		{
			for (i = 1; i < valsp[0] + 1; i++)
				if ((shoupai[0][i - 1] > altemp - 9 && shoupai[0][i - 1] < altemp - 4) || (shoupai[0][i - 1] > altemp + 3 && shoupai[0][i - 1] < altemp + 8))
				{
					altmp1[i - 1] = 1;
					continue;
				}
		}
		else if (k == 1)
		{
			for (i = 1; i < valsp[0] + 1; i++)
				if ((shoupai[0][i - 1] > altemp - 5 && shoupai[0][i - 1] < altemp) || (shoupai[0][i - 1] > altemp + 7 && shoupai[0][i - 1] < altemp + 12))
				{
					altmp1[i - 1] = 1;
					continue;
				}
		}
		else
		{
			chitemp[0] = active;
			chitemp[2] = shoupai[0][altemp1 - 1];
			for (i = 1; i < valsp[0] + 1; i++)
				if (shoupai[0][i - 1] > altemp + 3 && shoupai[0][i - 1] < altemp + 8)
				{
					altmp1[i - 1] = 1;
					continue;
				}
		}
		while (true)
		{
			int info = 0;
			m = GetMouseMsg();
			if (m.uMsg == WM_LBUTTONUP)
			{
				for (int j = 0; j < valsp[0] + 1; j++)
				{
					if (m.x >= 303 + (13 - valsp[0]) / 3 * 189 + j * 63 && m.y >= 525 && m.y <= 630 && m.x <= 366 + (13 - valsp[0]) / 3 * 189 + j * 63)
					{
						i = j + 1;
						info = 1;
						break;
					}
				}
			}
			if (info == 1)
				break;
		}
		if (altmp1[i - 1] == 1)
			altemp2 = i;
		else for (j = 0; j < valsp[ck]; j++)
		{
			if (altmp1[j] == 1)
			{
				altemp2 = j + 1;
				break;
			}
		}
		POINT pts2[] = { {303 + (13 - valsp[0]) / 3 * 189 + (altemp2 - 1) * 63, 475}, {366 + (13 - valsp[0]) / 3 * 189 + (altemp2 - 1) * 63, 475}, {335 + (13 - valsp[0]) / 3 * 189 + (altemp2 - 1) * 63, 525} };
		fillpolygon(pts2, 3);
		slp(500);
		if (k == -2 || k == 2)
		{
			chitemp[1] = shoupai[0][altemp2 - 1];
		}
		else if (k == 1)
		{
			if (altemp2 > altemp1)
			{
				chitemp[0] = active;
				chitemp[1] = shoupai[0][altemp1 - 1];
				chitemp[2] = shoupai[0][altemp2 - 1];
			}
			else
			{
				chitemp[1] = active;
				chitemp[2] = shoupai[0][altemp1 - 1];
				chitemp[0] = shoupai[0][altemp2 - 1];
			}
		}
		else
		{
			if (altemp2 > altemp1)
			{
				chitemp[1] = active;
				chitemp[0] = shoupai[0][altemp1 - 1];
				chitemp[2] = shoupai[0][altemp2 - 1];
			}
			else
			{
				chitemp[2] = active;
				chitemp[1] = shoupai[0][altemp1 - 1];
				chitemp[0] = shoupai[0][altemp2 - 1];
			}
		}
		chistate[ck][0][0]++;
		for (temp1 = (altemp1 > altemp2) ? altemp2 : altemp1; temp1 < valsp[ck]; temp1++)
		{
			if (temp1 < ((altemp2 > altemp1) ? altemp2 : altemp1) - 1)
				shoupai[ck][temp1 - 1] = shoupai[ck][temp1];
			else if (temp1 > ((altemp2 > altemp1) ? altemp2 : altemp1) - 1)
				shoupai[ck][temp1 - 2] = shoupai[ck][temp1];
		}
		for (i = 0; i < 3; i++)
			chistate[ck][chistate[ck][0][0]][i] = chitemp[i];
	}
	valsp[ck] -= 3;
	if (ck == 0)
		currenting = 1;
	bases();
	currenting = 0;
	if (ck != 0)
	{
		qipaidui[froming][0]--;
	}
	else
	{
		while (true)
		{
			int info = 0;
			m = GetMouseMsg();
			if (m.uMsg == WM_LBUTTONUP)
			{
				for (int j = 0; j < valsp[0] + 1; j++)
				{
					if (m.x >= 303 + (13 - valsp[0]) / 3 * 189 + j * 63 && m.y >= 525 && m.y <= 630 && m.x <= 366 + (13 - valsp[0]) / 3 * 189 + j * 63)
					{
						i = j + 1;
						info = 1;
						break;
					}
				}
			}
			if (info == 1)
				break;
		}
		qipaidui[froming][0]--;
		bases();
		getout(i - 1, 0);
		bases();
	}
}
void alpeng(int who)//*碰牌后程序
{
	IMAGE s;
	if (ck == 1)
	{
		loadimage(&s, _T(".\\anniu\\碰.png"), 180, 72);
		putimage(880, 260, &s);
		slp(2000);
	}
	if (ck == 2)
	{
		loadimage(&s, _T(".\\anniu\\碰.png"), 180, 72);
		putimage(600, 100, &s);
		slp(2000);
	}
	if (ck == 3)
	{
		loadimage(&s, _T(".\\anniu\\碰.png"), 180, 72);
		putimage(360, 250, &s);
		slp(2000);
	}
	MOUSEMSG m;
	int altemp1, altemp2;
	now = who;
	menqianqing[ck] = 0;
	yixun = 0;
	yifa = -1;
	if (state[3] == 0)
	{
		peng[ck][0]++;
		peng[ck][peng[ck][0]] = pengpai;
		pengstate[ck][peng[ck][0]] = pengtemp;
		pengstate[ck][0] += pengtemp;
		for (temp1 = pengr + 1; temp1 < valsp[ck]; temp1++)
		{
			shoupai[ck][temp1 - 2] = shoupai[ck][temp1];
		}
	}
	else if (ck != 0)
		strategypeng();
	else
	{
		bases();
		setbkmode(TRANSPARENT);
		settextcolor(WHITE);
		LOGFONT f;
		gettextstyle(&f);
		f.lfHeight = 25;
		wcscpy_s(f.lfFaceName, _T("Ink Free"));
		f.lfItalic = 0;
		f.lfWeight = 1500;
		f.lfQuality = ANTIALIASED_QUALITY;
		settextstyle(&f);
		outtextxy(200, 490, _T("请选择用于碰的牌："));
		peng[ck][0]++;
		peng[ck][peng[ck][0]] = pengpai;
		while (true)
		{
			int info = 0;
			m = GetMouseMsg();
			if (m.uMsg == WM_LBUTTONUP)
			{
				for (int j = 0; j < valsp[0] + 1; j++)
				{
					if (m.x >= 303 + (13 - valsp[0]) / 3 * 189 + j * 63 && m.y >= 525 && m.y <= 630 && m.x <= 366 + (13 - valsp[0]) / 3 * 189 + j * 63)
					{
						i = j;
						info = 1;
						break;
					}
				}
			}
			if (info == 1)
				break;
		}
		if (i > pengr - 1 && i < pengr + 3)
			altemp1 = i;
		else altemp1 = pengr;
		setfillcolor(RGB(51, 102, 127));
		POINT pts[] = { {303 + (13 - valsp[0]) / 3 * 189 + (altemp1 - 1) * 63, 475}, {366 + (13 - valsp[0]) / 3 * 189 + (altemp1 - 1) * 63, 475}, {335 + (13 - valsp[0]) / 3 * 189 + (altemp1 - 1) * 63, 525} };
		fillpolygon(pts, 3);
		outtextxy(200, 490, _T("请选择用于碰的牌："));
		if ((shoupai[0][altemp1 - 1] == 19) || (shoupai[0][altemp1 - 1] == 55) || (shoupai[0][altemp1 - 1] == 90) || (shoupai[0][altemp1 - 1] == 91))
			pengtemp = 1;
		else pengtemp = 0;
		while (true)
		{
			int info = 0;
			m = GetMouseMsg();
			if (m.uMsg == WM_LBUTTONUP)
			{
				for (int j = 0; j < valsp[0] + 1; j++)
				{
					if (m.x >= 303 + (13 - valsp[0]) / 3 * 189 + j * 63 && m.y >= 525 && m.y <= 630 && m.x <= 366 + (13 - valsp[0]) / 3 * 189 + j * 63)
					{
						i = j;
						info = 1;
						break;
					}
				}
			}
			if (info == 1)
				break;
		}
		if (i > pengr - 1 && i < pengr + 3 && i != altemp1)
			altemp2 = i;
		else altemp2 = (altemp1 == pengr) ? (pengr + 1) : pengr;
		POINT pts2[] = { {303 + (13 - valsp[0]) / 3 * 189 + (altemp2 - 1) * 63, 475}, {366 + (13 - valsp[0]) / 3 * 189 + (altemp2 - 1) * 63, 475}, {335 + (13 - valsp[0]) / 3 * 189 + (altemp2 - 1) * 63, 525} };
		fillpolygon(pts2, 3);
		slp(500);
		if ((shoupai[0][altemp2 - 1] == 19) || (shoupai[0][altemp2 - 1] == 55) || (shoupai[0][altemp2 - 1] == 90) || (shoupai[0][altemp2 - 1] == 91))
			pengtemp += 1;
		else pengtemp += 0;
		pengstate[ck][peng[ck][0]] = pengtemp;
		pengstate[ck][0] += pengtemp;
		for (temp1 = altemp1; temp1 < valsp[ck]; temp1++)
		{
			if (temp1 < altemp2 - 1)
				shoupai[ck][temp1 - 1] = shoupai[ck][temp1];
			else if (temp1 > altemp2 - 1)
				shoupai[ck][temp1 - 2] = shoupai[ck][temp1];
		}
	}
	valsp[who] -= 3;
	if (ck != 0)
	{
		qipaidui[froming][0]--;
		now = who;
		strategy();
	}
	else
	{
		currenting = 1;
		bases();
		currenting = 0;
		while (true)
		{
			int info = 0;
			m = GetMouseMsg();
			if (m.uMsg == WM_LBUTTONUP)
			{
				for (int j = 0; j < valsp[0] + 1; j++)
				{
					if (m.x >= 303 + (13 - valsp[0]) / 3 * 189 + j * 63 && m.y >= 525 && m.y <= 630 && m.x <= 366 + (13 - valsp[0]) / 3 * 189 + j * 63)
					{
						i = j + 1;
						info = 1;
						break;
					}
				}
			}
			if (info == 1)
				break;
		}
		qipaidui[froming][0]--;
		getout(i - 1, 0);
		bases();
	}
}

void algang(int who)//*明杠后程序
{
	IMAGE s;
	if (ck == 1)
	{
		loadimage(&s, _T(".\\anniu\\杠.png"), 180, 72);
		putimage(880, 260, &s);
		slp(2000);
	}
	if (ck == 2)
	{
		loadimage(&s, _T(".\\anniu\\杠.png"), 180, 72);
		putimage(600, 100, &s);
		slp(2000);
	}
	if (ck == 3)
	{
		loadimage(&s, _T(".\\anniu\\杠.png"), 180, 72);
		putimage(360, 250, &s);
		slp(2000);
	}
	now = ck;
	ganghou = 1;
	gangnum++;
	drastate++;
	menqianqing[ck] = 0;
	yixun = 0;
	yifa = -1;
	gang[ck][0]++;
	gang[ck][gang[ck][0]] = gangpai;
	gang[ck][gang[ck][0] + 4] = 2;
	for (temp1 = gangr + 1; temp1 < valsp[ck]; temp1++)
	{
		shoupai[ck][temp1 - 3] = shoupai[ck][temp1];
	}
	valsp[ck] -= 3;
	bases();
	qipaidui[froming][0]--;
}

void alhu(int who)//#胡牌后程序
{
	int r, tempck;
	wholestate = who;
	shoupai[ck][valsp[ck]] = active;
	for (r = valsp[ck]; (r > 0) && (shoupai[ck][r] < shoupai[ck][r - 1]); r--)
	{
		tempck = shoupai[ck][r];
		shoupai[ck][r] = shoupai[ck][r - 1];
		shoupai[ck][r - 1] = tempck;
	}
	if (who == 0)
		currenting = 1;
}

void alzigang(int who)//*already暗杠 
{
	IMAGE s;
	if (ck == 1)
	{
		loadimage(&s, _T(".\\anniu\\杠.png"), 180, 72);
		putimage(880, 260, &s);
		slp(2000);
	}
	if (ck == 2)
	{
		loadimage(&s, _T(".\\anniu\\杠.png"), 180, 72);
		putimage(600, 100, &s);
		slp(2000);
	}
	if (ck == 3)
	{
		loadimage(&s, _T(".\\anniu\\杠.png"), 180, 72);
		putimage(360, 250, &s);
		slp(2000);
	}
	gangnum++;
	drastate++;
	gang[who][0]++;
	gang[who][gang[who][0]] = gangpai;
	gang[who][gang[who][0] + 4] = 1;
	for (temp1 = zigangr + 1; temp1 < valsp[who] + 1; temp1++)
	{
		shoupai[who][temp1 - 4] = shoupai[who][temp1];
	}
	valsp[who] -= 3;
	putin(who);
	if(who == 0)
		currenting = 1;
	bases();
	if (who == 0)
		currnt();
	else strategy();
}

void aljiagang()//*加杠后程序
{
	int temp2, temp4;
	gangnum++;
	IMAGE s;
	if (ck == 1)
	{
		loadimage(&s, _T(".\\anniu\\杠.png"), 180, 72);
		putimage(880, 260, &s);
		slp(2000);
	}
	if (ck == 2)
	{
		loadimage(&s, _T(".\\anniu\\杠.png"), 180, 72);
		putimage(600, 100, &s);
		slp(2000);
	}
	if (ck == 3)
	{
		loadimage(&s, _T(".\\anniu\\杠.png"), 180, 72);
		putimage(360, 250, &s);
		slp(2000);
	}
	drastate++;
	gang[now][0]++;
	gang[now][gang[now][0]] = jiagangr2;
	gang[now][gang[now][0] + 4] = 3;
	for (temp4 = jiagangr; temp4 < valsp[now]; temp4++)
	{
		temp2 = shoupai[now][temp4];
		shoupai[now][temp4] = shoupai[now][temp4 + 1];
		shoupai[now][temp4 + 1] = temp2;
	}
	for (temp4 = jiagangr1; temp4 < peng[now][0]; temp4++)
	{
		temp2 = peng[now][temp4];
		peng[now][temp4] = peng[now][temp4 + 1];
		peng[now][temp4 + 1] = temp2;
	}
	peng[now][temp4] = 0;
	peng[now][0]--;
	bases();
}
