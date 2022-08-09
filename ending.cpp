#include <stdio.h>
#include <stdlib.h>
#include "ckhu.h"
extern int nowpai, gangnum, zimor, abc, ck, zhuang, aaa, abc, hur, yiman, now;
extern int lichi[5], chistate[4][5][3], peng[4][5], gang[4][9], pengstate[4][5];
extern int guoshiwushuangr, qiduizir, temp, hutype, fan, fu, yiman, i, q, yifa, ganghou, yixun, danqi, point, point1;
extern int fan1, fu1, get, dian, active, wholestate;
extern int menqianqing[4], shoupai[5][14], valsp[5], xyz[4], xxx[4], cking[34], state[5], ifyouyi[52], alyi[52];
extern int wlichi[4];
void checkfan()//#结算点数
{
	int temp7, temp8, temp9, youyi = 0, youzi = 0, youzi1 = 0, youzi2 = 0, zitou = 0, yijiu = 0, penggang = 0, chi1 = chistate[ck][0][0];
	fan = 0, yiman = 0;
	for (i = 0; i < 52; i++)
		ifyouyi[i] = 0;
	for (temp7 = 0; temp7 < chi1; temp7++)
		xyz[temp7 + abc] = chistate[ck][temp7 + 1][0] / 4;
	for (temp7 = 0; temp7 < peng[ck][0]; temp7++, penggang++)
	{
		xxx[temp7 + aaa] = peng[ck][temp7 + 1] / 4;
		if (xxx[temp7 + aaa] % 9 == 8 || xxx[temp7 + aaa] % 9 == 0 || xxx[temp7 + aaa] > 26)
			fu += 4;
		else fu += 2;
	}
	for (temp7 = 0; temp7 < gang[ck][0]; temp7++, penggang++)
	{
		xxx[temp7 + aaa + peng[ck][0]] = gang[ck][temp7 + 1] / 4;
		if (xxx[temp7 + aaa + peng[ck][0]] % 9 == 8 || xxx[temp7 + aaa + peng[ck][0]] % 9 == 0 || xxx[temp7 + aaa + peng[ck][0]] > 26)
		{
			if (gang[ck][temp7 + 5] == 3)
				fu += 32;
			else fu += 16;
		}
		else
		{
			if (gang[ck][temp7 + 5] == 3)
				fu += 16;
			else fu += 8;
		}
	}
	fu = (fu % 10 == 0) ? fu : (fu / 10 * 10 + 10);
	//役牌番数 
	for (temp7 = 0; temp7 < aaa + penggang; temp7++)
	{
		if (xxx[temp7] > 30)
		{
			fan++;
			ifyouyi[xxx[temp7] + 10]++;
		}
		if (xxx[temp7] == 27)
		{
			fan++;
			ifyouyi[44]++;
		}
		if (xxx[temp7] == (ck + 4 - zhuang) % 4)
		{
			fan++;
			ifyouyi[xxx[temp7] + 21]++;
		}
	}
	//
	if (lichi[ck] == 1)
	{
		fan++;
		if (wlichi[ck] == 1)
		{
			fan++;
			ifyouyi[10] = 1;
		}
		else ifyouyi[0] = 1;
	}
	if (yifa > -1)
	{
		fan++;
		ifyouyi[9] = 1;
	}
	if (ganghou == 1)
	{
		fan++;
		ifyouyi[6] = 1;
	}
	if (yixun == 2 && zimor == 1)
	{
		yiman++;
		if (now == zhuang)
			ifyouyi[26]++;
		else ifyouyi[27]++;
	}
	if (gang[ck][0] > 2)
	{
		if (gang[ck][0] == 4)
		{
			yiman++;
			ifyouyi[35] = 1;
		}
		else
		{
			fan += 2;
			ifyouyi[12] = 1;
		}
	}
	for (temp7 = 0; temp7 < penggang + aaa; temp7++)//以下为断幺九判定 
	{
		if (xxx[temp7] % 9 == 8 || xxx[temp7] % 9 == 0)
			if (xxx[temp7] < 27)
				yijiu++;
		if (xxx[temp7] > 30)
			youzi2++;
		else if (xxx[temp7] > 26)
			youzi1++;
	}
	for (temp7 = 0; temp7 < chi1 + abc; temp7++)//以下为断幺九判定
	{
		if (xyz[temp7] % 9 == 6 || xyz[temp7] % 9 == 0)
			yijiu++;
	}
	if (q % 9 == 0 || q % 9 == 8)
		if (q < 27)
			yijiu++;
		else if (q > 30)
			zitou = 2;
		else if (q > 26)
			zitou = 1;
	youzi = youzi1 + youzi2;
	if (youzi + yijiu + zitou < 1)//以下为断幺九判定
	{
		fan++;
		ifyouyi[1] = 1;
	}
	if (menqianqing[ck] == 1)
	{
		if (zimor == 1)
		{
			fan++;
			ifyouyi[2] = 1;
		}
		if (fu == 20)
		{
			fan++;
			ifyouyi[3] = 1;
		}
		for (temp7 = 1, temp8 = xyz[0]; temp7 < abc; temp7++)
		{
			if (xyz[temp7] == temp8)
			{
				fan += 1;
				ifyouyi[4] = 1;
				if (temp7 == 1)
					if (xyz[3] == xyz[2])
					{
						fan += 2;
						ifyouyi[21] = 1;
						ifyouyi[4] = 0;
						break;
					}
				break;
			}
			else
			{
				temp8 = xyz[temp7];
			}
		}
		if (aaa == 4)
		{
			if (danqi == 1)
			{
				yiman += 2;
				ifyouyi[37] = 1;
			}
			else
			{
				yiman += 1;
				ifyouyi[29] = 1;
			}
		}
	}
	if (youzi + zitou > 0)
	{
		if (youzi1 == 4)
		{
			yiman += 2;
			ifyouyi[39] = 1;
		}
		if (youzi2 == 3)
		{
			yiman += 1;
			ifyouyi[28] = 1;
		}
		if (zitou == 2 && youzi2 == 2)
		{
			fan += 2;
			ifyouyi[15] = 1;
		}
		if (zitou == 1 && youzi1 == 3)
		{
			yiman += 1;
			ifyouyi[34] = 1;
		}
		if (zitou > 0 && youzi == 4)
		{
			yiman += 1;
			ifyouyi[30] = 1;
		}
		if (youzi + yijiu == 4)
		{
			if (chi1 + abc == 0)
			{
				fan += 2;
				ifyouyi[16] = 1;
			}
			else
			{
				fan += (1 + menqianqing[ck]);
				ifyouyi[18] = 1;
			}
		}
		temp7 = 1;
		if (q < 27)
			temp9 = q;
		else if (aaa + penggang > 0)
			temp9 = xxx[0];
		else temp9 = xyz[0];
		for (temp8 = 0; temp8 < aaa + penggang; temp8++)
			if (xxx[temp8] / 9 != temp9 / 9 && xxx[temp8] < 27)
			{
				temp7 = 0;
				break;
			}
		for (temp8 = 0; temp8 < abc + chi1; temp8++)
			if (xyz[temp8] / 9 != temp9 / 9 && xyz[temp8] < 27)
			{
				temp7 = 0;
				break;
			}
		if (temp7 == 1)
		{
			fan += (2 + menqianqing[ck]);
			ifyouyi[23] = 1;
		}
	}
	else
	{
		if (yijiu == 4 && (q % 9 == 0 || q % 9 == 8))
		{
			if (abc + chi1 == 0)
			{
				yiman += 1;
				ifyouyi[32] = 1;
			}
			else
			{
				fan += (2 + menqianqing[ck]);
				ifyouyi[22] = 1;
			}
		}
		temp7 = 1;
		for (temp8 = 0; temp8 < aaa + penggang; temp8++)
			if (xxx[temp8] / 9 != q / 9)
			{
				temp7 = 0;
				break;
			}
		for (temp8 = 0; temp8 < abc + chi1; temp8++)
			if (xyz[temp8] / 9 != q / 9)
			{
				temp7 = 0;
				break;
			}
		if (temp7 == 1)
		{
			fan += (5 + menqianqing[ck]);
			ifyouyi[24] = 1;
		}
	}
	if (nowpai == 122 + gangnum)
	{
		fan++;
		if (zimor == 1)
			ifyouyi[7] = 1;
		else ifyouyi[8] = 1;
	}
	if (aaa == 3)
	{
		fan += 2;
		ifyouyi[14] = 1;
	}
	if (aaa + penggang == 4)
	{
		fan += 2;
		ifyouyi[13] = 1;
	}
	if (abc + chi1 > 2)
	{
		for (temp7 = 0; temp7 < abc + chi1; temp7++)
			if (xyz[temp7] % 9 == 0)
				for (temp8 = 0; temp8 < abc + chi1; temp8++)
					if (xyz[temp7] % 9 == 3 && xyz[temp7] / 9 == xyz[temp8] / 9)
						for (temp9 = 0; temp9 < abc + chi1; temp9++)
							if (xyz[temp9] % 9 == 6 && xyz[temp7] / 9 == xyz[temp9] / 9)
							{
								fan += (1 + menqianqing[ck]);
								ifyouyi[19] = 1;
								break;
							}
		if (ifyouyi[19] != 1)
		{
			if (abc + chi1 == 3 || youzi == 1)
				if (xyz[0] % 9 == xyz[1] % 9 && xyz[0] != xyz[1])
					if (xyz[1] % 9 == xyz[2] % 9 && xyz[0] != xyz[2] && xyz[2] != xyz[1])
					{
						fan += (1 + menqianqing[ck]);
						ifyouyi[11] = 1;
					}
					else
					{
						if (xyz[0] % 9 == xyz[1] % 9 && xyz[0] != xyz[1])
						{
							if (xyz[1] % 9 == xyz[2] % 9 && xyz[0] != xyz[2] && xyz[2] != xyz[1])
							{
								fan += (1 + menqianqing[ck]);
								ifyouyi[11] = 1;
							}
							else if (xyz[1] % 9 == xyz[3] % 9 && xyz[0] != xyz[3] && xyz[3] != xyz[1])
							{
								fan += (1 + menqianqing[ck]);
								ifyouyi[11] = 1;
							}
						}
						else
						{
							if (xyz[2] % 9 == xyz[1] % 9 && xyz[2] != xyz[1])
								if (xyz[3] % 9 == xyz[2] % 9 && xyz[3] != xyz[2] && xyz[3] != xyz[1])
								{
									fan += (1 + menqianqing[ck]);
									ifyouyi[11] = 1;
								}
						}
					}
		}
	}
	if (aaa + penggang > 2)
	{
		if (aaa + penggang == 3 || youzi == 1)
			if (xxx[0] % 9 == xxx[1] % 9 && xxx[0] != xxx[1])
				if (xxx[1] % 9 == xxx[2] % 9 && xxx[0] != xxx[2] && xxx[2] != xxx[1])
				{
					fan += 2;
					ifyouyi[20] = 1;
				}
				else
				{
					if (xxx[0] % 9 == xxx[1] % 9 && xxx[0] != xxx[1])
					{
						if (xxx[1] % 9 == xxx[2] % 9 && xxx[0] != xxx[2] && xyz[2] != xxx[1])
						{
							fan += 2;
							ifyouyi[20] = 1;
						}
						else if (xxx[1] % 9 == xxx[3] % 9 && xxx[0] != xxx[3] && xxx[3] != xxx[1])
						{
							fan += 2;
							ifyouyi[20] = 1;
						}
					}
					else
					{
						if (xxx[2] % 9 == xxx[1] % 9 && xxx[2] != xxx[1])
							if (xxx[3] % 9 == xxx[2] % 9 && xxx[3] != xxx[2] && xxx[3] != xxx[1])
							{
								fan += 2;
								ifyouyi[20] = 1;
							}
					}
				}
	}
	if (cking[10] + cking[11] + cking[12] + cking[14] + cking[16] + cking[33] == valsp[ck] + 1)
	{
		temp7 = 1;
		for (temp8 = 0; temp8 < abc + chi1; temp8++)
			if (xyz[temp8] != 10)
				temp7 = 0;
		for (temp8 = 0; temp8 < aaa + penggang; temp8++)
			if (xxx[temp8] != 10 && xxx[temp8] != 11 && xxx[temp8] != 12 && xxx[temp8] != 14 && xxx[temp8] != 16 && xxx[temp8] != 33)
				temp7 = 0;
		if (temp7 == 1)
		{
			yiman++;
			ifyouyi[31] = 1;
		}
	}
	point = jisuanfan(fan, fu);
	if (point > point1)
	{
		point1 = point;
		for (temp7 = 0; temp7 < 52; temp7++)
			alyi[temp7] = ifyouyi[temp7];
		fan1 = fan;
		fu1 = fu;
	}
}
void sousuo(int y, int tmp)//#搜索搭子
{
	int tmp2, tmp3;
	for (; tmp < 27; tmp++)
	{
		if (cking[tmp] > 2)
		{
			xxx[aaa] = tmp;
			aaa++;
			cking[tmp] -= 3;
			y--;
			sousuo(y, tmp + 1);
			y++;
			cking[tmp] += 3;
			aaa--;
			sousuo(y, tmp + 1);
		}
	}
	for (tmp2 = 0; tmp2 < 25; tmp2++)
	{
		if (cking[tmp2] == 0 || tmp2 % 9 > 6)
			continue;
		if (cking[tmp2] <= cking[tmp2 + 1] && cking[tmp2] <= cking[tmp2 + 2])
		{
			for (tmp3 = 0; tmp3 < cking[tmp2]; tmp3++)
			{
				xyz[abc] = tmp2;
				cking[tmp2]--;
				cking[tmp2 + 1]--;
				cking[tmp2 + 2]--;
				abc++;
			}
		}
		if (cking[tmp2] <= cking[tmp2 + 1] && cking[tmp2] <= cking[tmp2 + 2])
		{
			for (tmp3 = 0; tmp3 < cking[tmp2]; tmp3++)
			{
				xyz[abc] = tmp2;
				cking[tmp2]--;
				cking[tmp2 + 1]--;
				cking[tmp2 + 2]--;
				abc++;
			}
		}
	}
	if (abc != y)
	{
		while (abc > 0)
		{
			abc--;
			cking[xyz[abc]]++;
			cking[xyz[abc] + 1]++;
			cking[xyz[abc] + 2]++;
		}
		return;
	}
	else
	{
		for (tmp2 = 0; tmp2 <= aaa; tmp2++)
		{
			if (xxx[tmp2] % 9 == 8 || xxx[tmp2] % 9 == 0 || xxx[tmp2] > 26)
				fu += 8;
			else fu += 4;
			if (get == q)
			{
				fu += 2;
				danqi = 1;
				checkfan();
				danqi = 0;
				fu -= 2;
			}
			if (get < 27)
				for (tmp3 = 0; tmp3 < abc; tmp3++)
				{
					if ((get % 9 == 2 && xyz[tmp3] == get - 2) || (get % 9 == 6 && xyz[tmp3] == get + 2))
					{
						fu += 2;
						checkfan();
						fu -= 2;
					}
				}
			checkfan();
			if (xxx[tmp2] % 9 == 8 || xxx[tmp2] % 9 == 0 || xxx[tmp2] > 26)
				fu -= 4;
			else fu -= 2;
		}
	}
}

void hupaihou()//#胡牌后结算
{
	ck = wholestate;
	int guoshiwushuang[13] = { 0, 32, 36, 68, 72, 104, 108, 112, 116, 120, 124, 128, 132 };
	int i, j, k, y = valsp[ck] / 3, tmp, fu2, tmp2;
	int qdz[7];
	fu = 20;
	fu1 = 1;
	fan1 = 0;
	fan = 1;
	point1 = 1;
	yiman = 0;
	dian = 0;
	danqi = 0;
	get = active / 4;
	for (i = 0; i < 41; i++)
		alyi[i] = 0;
	for (i = 0; i < 34; i++)
		cking[i] = 0;
	for (i = 0; i < valsp[ck] + 1; i++)
	{
		j = shoupai[ck][i] / 4;
		cking[j] ++;
	}
	if (valsp[now] == 13)
	{
		for (i = 0, j = 0; i < 34; i++)//七对子判定
			if (cking[i] == 2)
				j++;
		if (j == 7)
			qiduizir = 1;
	}
	for (i = 0, j = 0; (valsp[ck] == 13) && (i < 14); j++)//国士无双判定 
	{
		if ((shoupai[ck][i] / 4 != guoshiwushuang[j] / 4))
		{
			if ((i == 0) && (shoupai[ck][i] % 4 != guoshiwushuang[j - 1]))
				break;
		}
		else
			j++;
	}
	if (j == 13)
		guoshiwushuangr = 1;
	if (guoshiwushuangr == 1)
	{
		if (yixun == 2 && zimor == 1)
		{
			yiman++;
			if (now == zhuang)
				alyi[26]++;
			else alyi[27]++;
		}
		cking[get]--;
		for (i = 0; i < 34; i++)
		{
			if (cking[i] == 2)
			{
				yiman++;
				alyi[33] = 1;//国士无双 
				return;
			}
		}
		alyi[40] = 1;//国士无双十三面听 
		yiman += 2;
		return;
	}
	if (qiduizir == 1)
	{
		if (yixun == 2 && zimor == 1)
		{
			yiman++;
			if (now == zhuang)
				alyi[26]++;
			else alyi[27]++;
		}
		alyi[17] = 1;//七对子 
		fan1 += 2;
		fu1 = 25;
		if (shoupai[ck][0] > 107)
		{
			yiman++;
			alyi[30] = 1;//字一色 
			return;
		}
		if (shoupai[ck][0] / 36 == shoupai[ck][13] / 36)
		{
			fan1 += 6;
			alyi[24] = 1;//清一色 
			return;
		}
		j = 0;
		for (i = 0; i < 34; i++)
		{
			if (cking[i] != 0)
			{
				qdz[j] = i;
				j++;
			}
		}
		if (qdz[6] < 27)
		{
			for (i = 0; i < 7; i++)
				if (qdz[i] % 9 == 0 || qdz[i] % 9 == 8)
					break;
			if (i == 7)
			{
				fan1++;
				alyi[1] = 1;//断幺九 
			}
		}
		else
		{
			for (i = 0; i < 6 && qdz[i] < 27; i++)
				if (qdz[i] % 9 != 0 && qdz[i] % 9 != 8)
					break;
			if (qdz[i] > 26)
			{
				fan1 += 2;
				alyi[16] = 1;//混老头 
			}
			for (j = 6; qdz[j] > 26; j--);
			if (qdz[i] / 9 == qdz[j] / 9)
			{
				fan1 += 3;
				alyi[19] = 1;
			}
		}
		return;
	}
	if (valsp[ck] == 13 && shoupai[ck][0] / 36 == shoupai[ck][13] / 36 && (shoupai[ck][0] / 4) % 9 == 0 && shoupai[ck][0] < 76)
	{
		tmp = shoupai[ck][0] / 4;
		if (cking[tmp] > 2 && cking[tmp + 8] > 2)
		{
			if (cking[tmp + 8] == 4)
				j = tmp + 8;
			else j = tmp;
			k = 0;
			for (i = 1; i < 8; i++)
			{
				if (cking[tmp + i] < 1)
					break;
				else if (cking[tmp + i] == 2)
					j = tmp + i;
			}
			if (i == 8)
			{
				if (j == get)
				{
					yiman += 2;
					alyi[38] = 1;
					return;
				}
				else
				{
					yiman += 1;
					alyi[36] = 1;
					return;
				}
			}
		}
	}
	if (zimor == 1)
		fu += 2;
	if (menqianqing[ck] == 1 && zimor == 0)
		fu += 10;
	fu2 = fu;
	for (q = 0; q < 34; q++)
	{
		tmp2 = 0;
		if (cking[q] < 2)
			continue;
		cking[q] -= 2;
		if (q == 27)
			fu += 2;
		if (q == (4 - zhuang) % 4 + 27)
			fu += 2;
		if (q > 30)
			fu += 2;
		aaa = 0;
		abc = 0;
		for (tmp = 27; tmp < 34; tmp++)
		{
			if (cking[tmp] == 3)
			{
				xxx[aaa] = tmp;
				aaa++;
				cking[tmp] -= 3;
				y--;
				tmp2++;
			}
		}
		if (y >= 0)
			sousuo(y, 0);
		fu = fu2;
		for (i = 0; i < 34; i++)
			cking[i] = 0;
		for (i = 0; i < valsp[ck] + 1; i++)
		{
			j = shoupai[ck][i] / 4;
			cking[j] ++;
		}
		y += tmp2;
	}
}
