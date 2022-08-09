#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include "checking.h"
#include "already.h"
#include "AI.h"
#include "printing.h"
#include "GUI.h"
extern int zhuang, active, now, ck, wholestate, nowpai, drastate, gangnum, currenting, strategycheckif;
extern int i, j, k, r, m, temp, temp1, temphu, temphu1, tempck;
extern int gangr, gangpai, pengr, pengpai, hur, ifzimo, rongnum, jiang, zigangr, lichir, jiagangr;
extern int zimor, guoshiwushuangr, qiduizir, chir, dranum, lidranum, pengtemp, jiagangr1, jiagangr2;
extern int hutype, aaa, abc, q, get, fu, fu1, fan, fan1, point, point1, yiman, dian, danqi, ganghou, yixun, yifa, focus;
extern int chizuo, chiyou, chika;
extern int lichi[5], chistate[4][5][3], peng[4][5], gang[4][9], pengstate[4][5], qipaidui[4][40], state[5];
extern int menqianqing[4], shoupai[5][14], valsp[5], xyz[4], xxx[4], cking[34], chitemp[3], feng1[4], order[136];
extern char statemz[5][7], mingzi[4][7], feng[4][5], manguanlv[11][13], yizhong[52][32], pai[136][6];
extern int guoshiwushuang[13];
int check()//*检查打出牌是否触发吃、碰、杠、胡
{
	MOUSEMSG m;
	int mode;
	bases();
	for (i = 0, ck = now; i < 3; i++, ck = (ck == 3) ? 0 : (ck + 1))
	{
		if (ck == 0)
		{
			for (j = 0; j < 5; j++)
				state[j] = 0;
			temp = 0;
			if (now == 0)
			{
				checkchi();
			}
			checkpeng();
			checkgang();
			checkrong();
			if ((temp != 0) && (lichi[ck] == 0))
			{
				k = 0;
				for (j = 1; j < 5; j++)
					if (state[j] == 1)
						anniu(j, j);
				anniu(5, 5);
				FlushMouseMsgBuffer();
				while (true)
				{
					int info = 0;
					m = GetMouseMsg();
					if (m.uMsg == WM_LBUTTONUP)
					{
						for (int j = 1; j < 6; j++)
						{
							if (m.x >= 288 + j * 100 && m.y >= 480 && m.y <= 528 && m.x <= 348 + j * 100 && state[j] == 1)
							{
								mode = j;
								info = 1;
								break;
							}
							else if (m.x >= 788 && m.y >= 480 && m.y <= 528 && m.x <= 888)
							{
								mode = 5;
								info = 1;
								break;
							}
						}
					}
					if (info == 1)
						break;
				}
				bases();
				if (state[mode] > 0||mode == 5)
					switch (mode)
					{
					case 0: allichi(0); return 0;
					case 1: alchi(0); return 0;
					case 2: alpeng(0); return 0;
					case 3: algang(0); 	return 0;
					case 4: alhu(0); return 0;
					default: return 0;
					}
				else return 0;
			}
			else if (state[4] == 1)
			{
				bases();
				anniu(4, 4);
				anniu(5, 5);
				FlushMouseMsgBuffer();
				while (true)
				{
					int info = 0;
					m = GetMouseMsg();
					if (m.uMsg == WM_LBUTTONUP)
					{
						for (int j = 4; j < 6; j++)
						{
							if (m.x >= 688 && m.y >= 480 && m.y <= 528 && m.x <= 748)
							{
								mode = 4;
								info = 1;
								break;
							}
							else if (m.x >= 788 && m.y >= 480 && m.y <= 528 && m.x <= 888)
							{
								mode = 5;
								info = 1;
								break;
							}
						}
					}
					if (info == 1)
						break;
				}
				if (mode == 4)
					alhu(0);
				else return 0;
			}
		}
		else
		{
			for (j = 0; j < 5; j++)
				state[j] = 0;
			temp = 0;
			if (valsp[ck] == 1)
			{
				if (shoupai[ck][0] == shoupai[ck][1])
				{
					checkrong();
					if (hur == 1)
						alhu(ck);
				}
				return 0;
			}
			if (lichi[ck] == 0)
			{
				if (now == ck)
					checkchi();
				checkpeng();
				checkgang();
			}
			checkrong();
			if (lichi[ck] == 0 && state[1] + state[2] + state[3] + state[4] > 0)
			{
				bases();
				strategycheck();
				if(strategycheckif == 1)
					return 0;
			}
			else if (state[4] == 1)
			{
				bases();
				alhu(ck); 
				return 0;
			}
		}
	}
	return 1;
}
void currnt()//*自己回合 
{
	int mode, tmp;
	MOUSEMSG m;
	ck = 0;
	checkzimo();
	checkzigang();
	checkjiagang();
	if (lichi[0] == 1)
	{
		if (zimor == 1)
		{
			anniu(6, 4);
			anniu(5, 5);
			FlushMouseMsgBuffer();
			while (true)
			{
				int info = 0;
				m = GetMouseMsg();
				if (m.uMsg == WM_LBUTTONUP)
				{
					for (int j = 4; j < 6; j++)
					{
						if (m.x >= 688 && m.y >= 480 && m.y <= 528 && m.x <= 788)
						{
							mode = 4;
							info = 1;
							break;
						}
						else if (m.x >= 788 && m.y >= 480 && m.y <= 528 && m.x <= 888)
						{
							mode = 5;
							info = 1;
							break;
						}
					}
				}
				if (info == 1)
					break;
			}
			if ((zimor == 1) && (mode == 4))
			{
				wholestate = 0;
				return;
			}
		}
		getout(focus, 0);
		hur = 0;
		now = 1;
	}
	else 
	{
		if ((zimor == 1) || (zigangr > -1) || (jiagangr > -1))
		{
			if ((zigangr + jiagangr > -2) && (lichi[now] == 0))
				anniu(3, 3);
			if (zimor == 1)
				anniu(6, 4);
			anniu(5, 5);
			FlushMouseMsgBuffer();
			while (true)
			{
				int info = 0;
				m = GetMouseMsg();
				if (m.uMsg == WM_LBUTTONUP)
				{
						if (m.x >= 588 && m.y >= 480 && m.y <= 528 && m.x <= 648)
						{
							mode = 3;
							info = 1;
							break;
						}
						if (m.x >= 688 && m.y >= 480 && m.y <= 528 && m.x <= 788)
						{
							mode = 4;
							info = 1;
							break;
						}
						else if (m.x >= 788 && m.y >= 480 && m.y <= 528 && m.x <= 888)
						{
							mode = 5;
							info = 1;
							break;
						}
				}
				if (info == 1)
					break;
			}
			if ((zigangr > -1) && (mode == 3) && (lichi[now] == 0))
			{
				alzigang(0);
				return;
			}
			else if ((jiagangr > -1) && (mode == 3) && (lichi[now] == 0))
			{
				aljiagang();
				return;
			}
			else if ((zimor == 1) && (mode == 4))
			{
				wholestate = 0;
				return;
			}
			currenting = 1;
			majiangpai(order[nowpai], 1, 1150, 525);
		}
		FlushMouseMsgBuffer();
		while (true)
		{
			int info = 0;
			m = GetMouseMsg();
			if (m.uMsg == WM_LBUTTONUP)
			{
				for (int j = 0; j < valsp[0] + 1; j++)
				{
					if (m.x >= 303 + (13 - valsp[0]) / 3 * 189 + j * 63 && m.y >= 525&&m.y<=630&&m.x<= 366 + (13 - valsp[0]) / 3 * 189 + j * 63)
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
		getout(i - 1, 0);
		bases();
		tmp = now;
		now = 0;
		checklichi();
		now = tmp;
		if (state[0] == 1)
		{
			bases();
			anniu(0, 0);//立直
			anniu(5, 5);
			FlushMouseMsgBuffer();
			while (true)
			{
				int info = 0;
				m = GetMouseMsg();
				if (m.uMsg == WM_LBUTTONUP)
				{
						if (m.x >= 288 && m.y >= 480 && m.y <= 528 && m.x <= 388)
						{
							mode = 0;
							info = 1;
							break;
						}
						else if (m.x >= 788 && m.y >= 480 && m.y <= 528 && m.x <= 888)
						{
							mode = 5;
							info = 1;
							break;
						}
				}
				if (info == 1)
					break;
			}
			if (mode == 0)
				allichi(0);
		}
		hur = 0;
	}
}