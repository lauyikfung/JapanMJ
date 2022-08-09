#include <stdio.h>
#include <stdlib.h>
extern int nowpai, gangnum, zimor, abc, ck, zhuang, aaa, abc, hur, yiman, now;
extern int lichi[5], chistate[4][5][3], peng[4][5], gang[4][9];
extern int menqianqing[4], shoupai[5][14], valsp[5], xyz[4], xxx[4], cking[34];
extern int guoshiwushuang[13];
int dra(int i)//#宝牌与宝牌指示牌关系 
{
	int j = (i / 4) * 4;
	if (j < 108)
	{
		return (j % 36 == 32) ? (j - 32) : (j + 4);
	}
	else if (j < 124)
	{
		return (j == 120) ? 108 : (j + 4);
	}
	else
	{
		return (j == 132) ? 124 : (j + 4);
	}
}
int jisuanmg(int pt)//#计算满贯等级
{
	switch (pt)
	{
	case 8000: return 1;
	case 12000: return 2;
	case 16000: return 3;
	case 24000: return 4;
	case 32000: return 5;
	case 64000: return 6;
	case 96000: return 7;
	case 128000: return 8;
	case 160000: return 9;
	case 192000: return 10;
	default: return 0;
	}
}
int jisuanfan(int fa, int fiu)//#计算点数
{
	int temp5;
	if (yiman > 0)
		return 32000 * yiman;
	else if (fa > 4)
	{
		if (fa > 12)
			return 32000;
		else if (fa > 10)
			return 24000;
		else if (fa > 7)
			return 16000;
		else if (fa > 5)
			return 12000;
		else return 8000;
	}
	else if ((fa == 4 && fiu > 30) || (fa == 3 && fiu > 60))
		return 8000;
	else if (now == zhuang)
	{
		temp5 = fiu << (fa + 2);
		return (temp5 % 100 == 0) ? (temp5 * 6) : (temp5 * 6 / 100 * 100 + 100);
	}
	else
	{
		temp5 = fiu << (fa + 2);
		return (temp5 % 100 == 0) ? (temp5 * 4) : (temp5 * 4 / 100 * 100 + 100);
	}
}
void checkyouyi(int quetou)//#检查能否听牌
{
	int temp7, temp8, temp9, yise, yise1, youyi;
	if (lichi[4] == 1)//checklichi
		return;
	if (lichi[ck] == 1)//立直
		return;
	if (nowpai == 122 + gangnum)
		return;
	if (nowpai < 56)
		if (chistate[0][0][0] + chistate[1][0][0] + chistate[2][0][0] + chistate[3][0][0] == 0)
			if (peng[0][0] + peng[1][0] + peng[2][0] + peng[3][0] == 0)
				if (gang[0][0] + gang[1][0] + gang[2][0] + gang[3][0] == 0)
					return;
	if (gang[ck][0] > 2)
		return;
	if ((menqianqing[ck] == 0) && (zimor == 1))
		return;
	if ((chistate[ck][0][0] == 0) && (abc == 0))
		return;
	for (temp7 = 0; temp7 < aaa; temp7++)
	{
		if (xxx[temp7] > 30)
			return;
		if (xxx[temp7] == (ck + 4 - zhuang) % 4 && xxx[temp7] == 27)
			return;
	}
	for (temp7 = 1; temp7 <= gang[ck][0]; temp7++)
	{
		if (gang[ck][temp7] < 108)
			continue;
		temp8 = gang[ck][temp7];
		if (temp8 == 108)
			return;
		if (temp8 > 123)
			return;
		temp9 = (ck + 4 - zhuang) % 4;
		if (temp8 == 108 + 4 * temp9)
			return;
	}
	for (temp7 = 1; temp7 <= peng[ck][0]; temp7++)
	{
		if (peng[ck][temp7] < 108)
			continue;
		temp8 = peng[ck][temp7];
		if (temp8 == 108)
			return;
		if (temp8 > 123)
			return;
		temp9 = (ck + 4 - zhuang) % 4;
		if (temp8 == 108 + 4 * temp9)
			return;
	}
	youyi = 1;
	for (temp7 = 0; temp7 < valsp[ck] + 1; temp7++)//以下为断幺九判定 
	{
		temp9 = (shoupai[ck][temp7] / 4) * 4;
		for (temp8 = 0; temp8 < 13; temp8++)
			if (guoshiwushuang[temp8] == temp9)
				youyi += 3;
	}
	for (temp7 = 1; temp7 <= gang[ck][0]; temp7++)
	{
		for (temp8 = 0; temp8 < 13; temp8++)
			if (guoshiwushuang[temp8] == gang[ck][temp7])
				youyi += 3;
	}
	for (temp7 = 1; temp7 <= peng[ck][0]; temp7++)
	{
		for (temp8 = 0; temp8 < 13; temp8++)
			if (guoshiwushuang[temp8] == peng[ck][temp7])
				youyi += 3;
	}
	for (temp7 = 1; temp7 <= chistate[ck][0][0]; temp7++)
	{
		for (temp9 = 0; temp9 < 3; temp9++)
			for (temp8 = 0; temp8 < 13; temp8++)
				if (guoshiwushuang[temp8] == chistate[ck][temp7][temp9])
					youyi += 3;
	}
	if (youyi == 1)
		return;
	for (temp7 = 1, yise1 = shoupai[ck][0] / 36; (temp7 < valsp[ck] + 1) && (shoupai[ck][temp7] > 107); temp7++)//以下为染手判定 
	{
		yise = shoupai[ck][temp7] / 36;
		if (yise > yise1)
		{
			hur = 0;
			return;
		}
	}
	for (temp7 = 1; (temp7 <= gang[ck][0]) && (gang[ck][temp7] > 107); temp7++)
	{
		yise = gang[ck][temp7] / 36;
		if (yise > yise1)
		{
			hur = 0;
			return;
		}
	}
	for (temp7 = 1; (temp7 <= peng[ck][0]) && (peng[ck][temp7] > 107); temp7++)
	{
		yise = peng[ck][temp7] / 36;
		if (yise > yise1)
		{
			hur = 0;
			return;
		}
	}
	for (temp7 = 1; temp7 <= chistate[ck][0][0]; temp7++)
	{
		yise = chistate[ck][temp7][0] / 36;
		if (yise > yise1)
		{
			hur = 0;
			return;
		}
	}
	if (cking[0] && cking[1] && cking[2] && cking[3] && cking[4] && cking[5] && cking[6] && cking[7] && cking[8])
		return;
	if (cking[9] && cking[10] && cking[11] && cking[12] && cking[13] && cking[14] && cking[15] && cking[16] && cking[17])
		return;
	if (cking[18] && cking[19] && cking[20] && cking[21] && cking[22] && cking[23] && cking[24] && cking[25] && cking[26])
		return;
	if ((quetou % 9 == 0) || (quetou % 9 == 8) || (quetou % 9 > 26))
	{
		temp8 = 1;
		for (temp7 = 0; temp7 < aaa; temp7++)
		{
			if ((xxx[temp7] % 9 != 0) && (xxx[temp7] % 9 != 8) && (xxx[temp7] % 9 < 27))
			{
				temp8 = 0;
				break;
			}
		}
		for (temp7 = 0; temp7 < abc; temp7++)
		{
			if ((xyz[temp7] % 9 != 0) && (xxx[temp7] % 9 != 8))
			{
				temp8 = 0;
				break;
			}
		}
		if (temp8)
			return;
	}
	for (temp7 = 0; temp7 < 27; temp7++)
		if (xyz[temp7] > 1)
			break;
	if (aaa == 3)
		if ((xxx[2] < 27) && (xxx[0] + 9 == xxx[1]) && (xxx[1] + 9 == xxx[2]))
			return;
	if (abc == 3)
		if ((xyz[0] + 9 == xyz[1]) && (xyz[1] + 9 == xyz[2]))
			return;
	if (abc == 4)
	{
		if (xyz[0] < 9)
		{
			temp7 = xyz[0];
			if ((xyz[1] != temp7 + 9) && (xyz[1] < 9))
			{
				temp8 = xyz[1] % 9;
				if ((xyz[2] == temp7 + 9) && (xyz[3] == temp7 + 18))
					return;
				if ((xyz[2] == temp8 + 9) && (xyz[3] == temp8 + 18))
					return;
			}
			else if (xyz[1] == temp7 + 9)
				if ((xyz[2] == temp7 + 18) || (xyz[3] == temp7 + 18))
					return;
		}
	}
	hur = 0;
}
