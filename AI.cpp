#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "already.h"
#include "checking.h"
extern int temp1, chir, pengpai, pengtemp, ck, i, pengr, now, zimor, zigangr, strategycheckif, active, focus;
extern int shoupai[5][14], chistate[4][5][3], chitemp[3], peng[4][5], pengstate[4][5], valsp[5], state[5], lichi[5];
extern int peng[4][5], gang[4][9], guoshiwushuang[13], prior_value[14], qipaidui[4][40];

void strategy()//&&&AI策略，也在check（）函数中有一部分策略
{
	int prior_point[14][1] = { 0 };//优先级点数 
	int shoupaizhonglei[14] = { 0 };//手牌种类 
	int i, k, j, tmp, tmp1;
	int cnt;
	int guding[14] = { 0 };//一次次判定以后会固定一些牌，比如凑齐刻子和xxx后，就会将其固定，后续不再对其进行价值判断 
	int yaojiupai[14] = { 0 };
	int yaojiupaicnt = 0, gudingcnt = 0, restcnt = 0, pointcnt = 0;//一些计数变量 
	int xyzy = 0, xyzz = 0;//刻子中的y和z 
	int rest[14] = { 0 };//还需要检验的牌 
	//优先打出幺九牌
	ck = now;
	checkzimo();
	checkzigang();
	if (zimor == 1)
	{
		alhu(now);
		return;
	}
	if (lichi[now] == 1)
	{
		getout(focus, now);
		return;
	}
	if (zigangr > -1)
	{
		alzigang(now);
		zigangr = -1;
		return;
	}
	for (i = 0; i < valsp[now] + 1; i++)
	{
		if (shoupai[now][i] > -1 && shoupai[now][i] < 4 || shoupai[now][i] > 31 && shoupai[now][i] < 40 || shoupai[now][i] > 67 && shoupai[now][i] < 76 || shoupai[now][i] >103 && shoupai[now][i] < 136)
		{
			yaojiupai[yaojiupaicnt] = i;
			yaojiupaicnt++;
		}
	}
	if (yaojiupaicnt != 0)
	{
		tmp = now;
		getout(yaojiupai[yaojiupaicnt - 1], now);
		tmp1 = now;
		now = tmp;
		ck = tmp;
		checklichi();
		if (state[0] == 1)
			allichi(tmp);
		now = tmp1;
		return;
	}
	if (yaojiupaicnt == 0)
	{
		//以下操作是挑出xxx类型的牌,找到后将其归入固定数组内 
		for (k = 0; k < valsp[now] + 1; k++)
		{
			shoupaizhonglei[k] = (shoupai[now][k] / 4) * 4;
		}
		for (k = 0; k < valsp[now] + 1; k++)
		{
			if ((k < valsp[now] - 1)&&(shoupaizhonglei[k] == shoupaizhonglei[k + 1]) && (shoupaizhonglei[k] == shoupaizhonglei[k + 2]))
			{
				guding[gudingcnt] = k;
				guding[gudingcnt + 1] = k + 1;
				guding[gudingcnt + 2] = k + 2;
				gudingcnt += 3;
				k += 2;
				continue;
			}
			else {
				rest[restcnt] = k;
				restcnt++;
			}
		}
		//寻找xxx结束 
		//寻找刻子begin 
		for (k = 0; k < restcnt; k++)
		{
			cnt = 1;
			for (j = 0; j < restcnt; j++)
			{
				if (shoupaizhonglei[rest[j]] == shoupaizhonglei[rest[k]] + 4)
				{
					cnt++;
					xyzy = j;
					break;
				}
			}
			for (j = 0; j < restcnt; j++)
			{
				if (shoupaizhonglei[rest[j]] == shoupaizhonglei[rest[k]] + 8)
				{
					cnt++;
					xyzz = j;
					break;
				}
			}
			//找到刻子后，将其归入固定数组
			if (cnt == 3)
			{
				guding[gudingcnt] = rest[k];
				guding[gudingcnt + 1] = rest[xyzy];
				guding[gudingcnt + 2] = rest[xyzz];
				gudingcnt += 3;
				k += 2;
			}
		}//寻找刻子end 
		//形成新的rest数组 
		restcnt = 0;
		for (k = 0; k < valsp[ck] + 1; k++)
		{
			for (j = 0; j < gudingcnt; j++)
			{
				if (k == guding[j])
					break;
			}
			if (j == gudingcnt)
			{
				rest[restcnt] = k;
				restcnt++;
			}
		}
		//形成完毕
		//固定眼 
		for (k = 0; k < restcnt - 1; k++)
		{
			if (shoupaizhonglei[rest[k]] == shoupaizhonglei[rest[k + 1]])
			{
				guding[gudingcnt] = rest[k];
				guding[gudingcnt + 1] = rest[k + 1];
				gudingcnt += 2;
				k++;
			}
		}
		//形成新的rest数组 
		restcnt = 0;
		for (k = 0; k < valsp[ck] + 1; k++)
		{
			for (j = 0; j < gudingcnt; j++)
			{
				if (k == guding[j])
					break;
			}
			if (j == gudingcnt)
			{
				rest[restcnt] = k;
				restcnt++;
			}
		}
		//形成完毕
		//计算rest数组中各牌的点数
		for (k = 0; k < restcnt - 1; k++)
		{
			//碰到对子 
			if (shoupaizhonglei[rest[k]] == shoupaizhonglei[rest[k + 1]])
			{
				cnt = 0;
				//检视弃牌堆 
				for (i = 0; i < 4; i++)
				{
					for (j = 1; j <= qipaidui[i][0]; j++)
					{
						if (shoupaizhonglei[rest[k]] == (qipaidui[i][j] / 4 * 4))
						{
							cnt++;
						}
						if (cnt == 2)
						{
							break;
						}
					}
					break;
				}
				//检视完毕
				if (cnt == 2)
				{
					prior_point[rest[k]][0] = 0;
					prior_point[rest[k + 1]][0] = 0;
					continue;
				}
				//检验吃牌堆 
				for (i = 0; i < 4; i++)
				{
					for (j = 1; j < chistate[i][0][0] + 1; j++)
					{
						if (shoupaizhonglei[rest[k]] >= (chistate[i][j][0] / 4 * 4) && shoupaizhonglei[rest[k]] <= ((chistate[i][j][0] / 4 * 4) + 8))
						{
							cnt++;
							if (cnt == 2)
							{
								break;
							}
						}
					}
					if (cnt == 2)
					{
						break;
					}
				}
				if (cnt == 2)
				{
					prior_point[rest[k]][0] = 0;
					prior_point[rest[k + 1]][0] = 0;
					continue;
				}
				//检验完毕
				if (cnt == 0)
				{
					prior_point[rest[k]][0] = 20;
					prior_point[rest[k + 1]][0] = 20;
					continue;
				}
				if (cnt == 1)
				{
					prior_point[rest[k]][0] = 10;
					prior_point[rest[k + 1]][0] = 10;
				}
			}
			//对子结算结束
			//遇到xy类型 
			if (shoupaizhonglei[rest[k]] == shoupaizhonglei[rest[k + 1] - 1] && shoupaizhonglei[rest[k]] < 108)
			{
				//单独讨论边张
				//（二万、二条、二筒） 
				if (shoupaizhonglei[rest[k]] == 4 || shoupaizhonglei[rest[k]] == 40 || shoupaizhonglei[rest[k]] == 76)
				{
					cnt = 0;
					//检视弃牌堆 
					for (i = 0; i < 4; i++)
					{
						for (j = 1; j <= qipaidui[i][0]; j++)
						{
							if (shoupaizhonglei[rest[k]] + 8 == (qipaidui[i][j] / 4 * 4))
							{
								cnt++;
							}
						}
					}
					//检视完毕

					//检验吃牌堆 
					for (i = 0; i < 4; i++)
					{
						for (j = 1; j < chistate[i][0][0] + 1; j++)
						{
							if ((shoupaizhonglei[rest[k]] + 8) >= (chistate[i][j][0] / 4 * 4) && shoupaizhonglei[rest[k] + 8] <= ((chistate[i][j][0] / 4 * 4) + 8))
							{
								cnt++;
							}
						}
					}
					//检验完毕

					//检验碰牌堆
					for (i = 0; i < 4; i++)
					{
						for (j = 1; j < peng[i][0] + 1; j++)
						{
							if ((shoupaizhonglei[rest[k]] + 8) == (peng[i][j] / 4 * 4))
								cnt += 3;
						}
					}
					//检验完毕

					//检验杠牌堆
					for (i = 0; i < 4; i++)
					{
						for (j = 1; j < gang[i][0] + 1; j++)
						{
							if ((shoupaizhonglei[rest[k]] + 8) == (gang[i][j] / 4 * 4))
								cnt += 4;
						}
					}
					//检验完毕

					//检验自家手牌
					for (i = 0; i < valsp[now] + 1; i++)
					{
						if ((shoupaizhonglei[rest[k]] + 8) == (shoupaizhonglei[i] / 4 * 4))
						{
							cnt++;
						}
					}
					//检验完毕
					if (cnt == 0)
					{
						prior_point[rest[k]][0] = 40;
					}
					if (cnt == 1)
					{
						prior_point[rest[k]][0] = 30;
					}
					if (cnt == 2)
					{
						prior_point[rest[k]][0] = 20;
					}
					if (cnt == 3)
					{
						prior_point[rest[k]][0] = 10;
					}
					if (cnt == 4)
					{
						prior_point[rest[k]][0] = 0;
					}
				}
				//（七万、七条、七筒） 
				if (shoupaizhonglei[rest[k]] == 24 || shoupaizhonglei[rest[k]] == 60 || shoupaizhonglei[rest[k]] == 96)
				{
					cnt = 0;
					//检视弃牌堆 
					for (i = 0; i < 4; i++)
					{
						for (j = 1; j <= qipaidui[i][0]; j++)
						{
							if (shoupaizhonglei[rest[k]] - 8 == (qipaidui[i][j] / 4 * 4))
							{
								cnt++;
							}
						}
					}
					//检视完毕

					//检验吃牌堆 
					for (i = 0; i < 4; i++)
					{
						for (j = 1; j < chistate[i][0][0] + 1; j++)
						{
							if ((shoupaizhonglei[rest[k]] - 8) >= (chistate[i][j][0] / 4 * 4) && shoupaizhonglei[rest[k] - 8] <= ((chistate[i][j][0] / 4 * 4) + 8))
							{
								cnt++;
							}
						}
					}
					//检验完毕

					//检验碰牌堆
					for (i = 0; i < 4; i++)
					{
						for (j = 1; j < peng[i][0] + 1; j++)
						{
							if ((shoupaizhonglei[rest[k]] - 8) == (peng[i][j] / 4 * 4))
								cnt += 3;
						}
					}
					//检验完毕

					//检验杠牌堆
					for (i = 0; i < 4; i++)
					{
						for (j = 1; j < gang[i][0] + 1; j++)
						{
							if ((shoupaizhonglei[rest[k]] - 8) == (gang[i][j] / 4 * 4))
								cnt += 4;
						}
					}
					//检验完毕

					//检验自家手牌
					for (i = 0; i < valsp[now] + 1; i++)
					{
						if ((shoupaizhonglei[rest[k]] - 8) == (shoupaizhonglei[i] / 4 * 4))
						{
							cnt++;
						}
					}
					//检验完毕
					if (cnt == 0)
					{
						prior_point[rest[k]][0] = 40;
					}
					if (cnt == 1)
					{
						prior_point[rest[k]][0] = 30;
					}
					if (cnt == 2)
					{
						prior_point[rest[k]][0] = 20;
					}
					if (cnt == 3)
					{
						prior_point[rest[k]][0] = 10;
					}
					if (cnt == 4)
					{
						prior_point[rest[k]][0] = 0;
					}
				}
				//讨论非边张情况
				else
				{
					cnt = 0;
					//检视弃牌堆 
					for (i = 0; i < 4; i++)
					{
						for (j = 1; j <= qipaidui[i][0]; j++)
						{
							if (shoupaizhonglei[rest[k]] - 4 == (qipaidui[i][j] / 4 * 4))
							{
								cnt++;
							}
						}
					}
					//检视完毕

					//检验吃牌堆 
					for (i = 0; i < 4; i++)
					{
						for (j = 1; j < chistate[i][0][0] + 1; j++)
						{
							if ((shoupaizhonglei[rest[k]] - 4) >= (chistate[i][j][0]/ 4 * 4) && shoupaizhonglei[rest[k] - 4] <= ((chistate[i][j][0] / 4 * 4) + 8))
							{
								cnt++;
							}
						}
					}
					//检验完毕

					//检验碰牌堆
					for (i = 0; i < 4; i++)
					{
						for (j = 1; j < peng[i][0] + 1; j++)
						{
							if ((shoupaizhonglei[rest[k]] - 4) == (peng[i][j] / 4 * 4))
								cnt += 3;
						}
					}
					//检验完毕

					//检验杠牌堆
					for (i = 0; i < 4; i++)
					{
						for (j = 1; j < gang[i][0] + 1; j++ )
						{
							if ((shoupaizhonglei[rest[k]] - 4) == (gang[i][j] / 4 * 4))
								cnt += 4;
						}
					}
					//检验完毕

					//检验自家手牌
					for (i = 0; i < valsp[now] + 1; i++)
					{
						if ((shoupaizhonglei[rest[k]] - 4) == (shoupaizhonglei[i] / 4 * 4))
						{
							cnt++;
						}
					}
					//检验完毕

					//检视弃牌堆 
					for (i = 0; i < 4; i++)
					{
						for (j = 1; j <= qipaidui[i][0]; j++)
						{
							if (shoupaizhonglei[rest[k]] + 8 == (qipaidui[i][j] / 4 * 4))
							{
								cnt++;
							}
						}
					}
					//检视完毕

					//检验吃牌堆 
					for (i = 0; i < 4; i++)
					{
						for (j = 1; j < chistate[i][0][0] + 1; j++)
						{
							if ((shoupaizhonglei[rest[k]] + 8) >= (chistate[i][j][0] / 4 * 4) && shoupaizhonglei[rest[k] + 8] <= ((chistate[i][j][0] / 4 * 4) + 8))
							{
								cnt++;
							}
						}
					}
					//检验完毕

					//检验碰牌堆
					for (i = 0; i < 4; i++)
					{
						for (j = 1; j < peng[i][0] + 1; j++)
						{
							if ((shoupaizhonglei[rest[k]] + 8) == (peng[i][j] / 4 * 4))
								cnt += 3;
						}
					}
					//检验完毕

					//检验杠牌堆
					for (i = 0; i < 4; i++)
					{
						for (j = 1; j < gang[i][0] + 1; j++)
						{
							if ((shoupaizhonglei[rest[k]] + 8) == (gang[i][j] / 4 * 4))
								cnt += 4;
						}
					}
					//检验完毕

					//检验自家手牌
					for (i = 0; i < valsp[now] + 1; i++)
					{
						if ((shoupaizhonglei[rest[k]] + 8) == (shoupaizhonglei[i] / 4 * 4))
						{
							cnt++;
						}
					}
					//检验完毕
					if (cnt == 0)
						prior_point[rest[k]][0] = 80;
					if (cnt == 1)
						prior_point[rest[k]][0] = 70;
					if (cnt == 2)
						prior_point[rest[k]][0] = 60;
					if (cnt == 3)
						prior_point[rest[k]][0] = 50;
					if (cnt == 4)
						prior_point[rest[k]][0] = 40;
					if (cnt == 5)
						prior_point[rest[k]][0] = 30;
					if (cnt == 6)
						prior_point[rest[k]][0] = 20;
					if (cnt == 7)
						prior_point[rest[k]][0] = 10;
					if (cnt == 8)
						prior_point[rest[k]][0] = 0;
				}
			}
			//xy类型结算结束 

			//遇到xz类型
			if (shoupaizhonglei[rest[k]] == (shoupaizhonglei[rest[k]] + 8))
			{
				cnt = 0;
				//检视弃牌堆 
				for (i = 0; i < 4; i++)
				{
					for (j = 1; j <= qipaidui[i][0]; j++)
					{
						if (shoupaizhonglei[rest[k]] + 4 == (qipaidui[i][j] / 4 * 4))
						{
							cnt++;
						}
					}
				}
				//检视完毕

				//检验吃牌堆 
				for (i = 0; i < 4; i++)
				{
					for (j = 1; j < chistate[i][0][0] + 1; j++)
					{
						if ((shoupaizhonglei[rest[k]] + 4) >= (chistate[i][j][0] / 4 * 4) && shoupaizhonglei[rest[k] - 8] <= ((chistate[i][j][0] / 4 * 4) + 8))
						{
							cnt++;
						}
					}
				}
				//检验完毕

				//检验碰牌堆
				for (i = 0; i < 4; i++)
				{
					for (j = 1; j < peng[i][0] + 1; j++)
					{
						if ((shoupaizhonglei[rest[k]] + 4) == (peng[i][j] / 4 * 4))
							cnt += 3;
					}
				}
				//检验完毕

				//检验杠牌堆
				for (i = 0; i < 4; i++)
				{
					for (j = 1; j < gang[i][0] + 1; j++)
					{
						if ((shoupaizhonglei[rest[k]] + 4) == (gang[i][j] / 4 * 4))
							cnt += 4;
					}
				}
				//检验完毕

				//检验自家手牌
				for (i = 0; i < valsp[now] + 1; i++)
				{
					if ((shoupaizhonglei[rest[k]] + 4) == (shoupaizhonglei[i] / 4 * 4))
					{
						cnt++;
					}
				}
				//检验完毕
				if (cnt == 0)
					prior_point[rest[k]][0] = 40;
				if (cnt == 1)
					prior_point[rest[k]][0] = 30;
				if (cnt == 2)
					prior_point[rest[k]][0] = 20;
				if (cnt == 3)
					prior_point[rest[k]][0] = 10;
				if (cnt == 4)
					prior_point[rest[k]][0] = 0;
			}
		}
		//考虑rest数组中最后一个元素的优先级点数
		if (restcnt > 1 && shoupaizhonglei[rest[restcnt - 2]] <= (shoupaizhonglei[rest[restcnt - 1]] - 12))
		{
			prior_point[rest[restcnt - 1]][0] = 0;
		}
		else if(restcnt > 1)
		{
			prior_point[rest[restcnt - 1]][0] = prior_point[rest[restcnt - 2]][0];
		}
		k = 200;
		j = -1;
		for (i = 0; i < restcnt; i++)
		{
			if (k >= prior_point[rest[i]][0])
			{
				k = prior_point[rest[i]][0];
				j = i;
			}
		}
		if (j < 0)
		{
			tmp = now;
			getout(0, now);
			tmp1 = now;
			now = tmp;
			ck = tmp;
			checklichi();
			if (state[0] == 1)
				allichi(tmp);
			now = tmp1;
			return;
		}
		else 
		{
			tmp = now;
			getout(rest[j], now);
			tmp1 = now;
			now = tmp;
			ck = tmp;
			checklichi();
			if (state[0] == 1)
				allichi(tmp);
			now = tmp1;
			return;
		}
	}
	getout(0, now);
	return;
}
void strategychi()//&&&AI策略
{
	chistate[ck][0][0]++;
	for (i = 0; i < 3; i++)
		chistate[ck][chistate[ck][0][0]][i] = chitemp[i];
	for (temp1 = chir + 1; temp1 < valsp[ck]; temp1++)
	{
		shoupai[ck][temp1 - 2] = shoupai[ck][temp1];
	}
}
void strategypeng()//&&&AI策略
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
void strategycheck()//&&&策略
{
	int temp1;
	strategycheckif = 0;
	if (state[4] == 1)
	{
		alhu(ck);
		now = ck;
		strategycheckif = 1;
		return;
	}
	else if (state[3] == 1)
	{
		for (temp1 = 0; temp1 < 13; temp1++)
			if (active / 4 * 4 == guoshiwushuang[temp1])
				return;
		algang(ck);
		now = ck;
		strategycheckif = 1;
		return;
	}
	else if (state[2] == 1)
	{
		for (temp1 = 0; temp1 < 13; temp1++)
			if (active / 4 * 4 == guoshiwushuang[temp1])
				return;
		alpeng(ck);
		strategycheckif = 1;
		return;
	}
}