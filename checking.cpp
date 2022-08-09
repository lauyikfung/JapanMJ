#include <stdio.h>
#include <stdlib.h>
#include "chckchi.h"
#include "chckhu.h"
extern int r, chika, temp1, ck, temp, chir, chika, chizuo, chiyou, active, wholestate;
extern int gangr, gangpai, jiagangr, now, jiagangr1, jiagangr2, pengr, pengtemp, pengpai;
extern int ifzimo, tempck, rongnum, hur, zigangr, zimor;
extern int valsp[5], shoupai[5][14], state[5], chitemp[3], peng[4][5], lichi[5], menqianqing[4];

void checkchi()//#判定吃 
{
	chizuo = 0;
	chiyou = 0;
	chika = 0;
	if (valsp[ck] == 1)
		return;
	if (active > 107)
		return;
	temp1 = (active / 4) * 4;
	if (temp1 % 36 == 0)
	{
		checkchizuo();
	}
	else if (temp1 % 36 == 32)
	{
		checkchiyou();
	}
	else if (temp1 % 36 == 4)
	{
		checkchika();
		checkchizuo();
	}
	else if (temp1 % 36 == 28)
	{
		checkchiyou();
		checkchika();
	}
	else
	{
		checkchiyou();
		checkchika();
		checkchizuo();
	}
}
void checkgang()//#检查杠牌
{
	gangr = -1;
	if (valsp[ck] == 1)
		return;
	else {
		temp1 = (active / 4) * 4;
		for (r = 0; (r < valsp[ck] - 2) && (shoupai[ck][r] < temp1 + 4); r++)
		{
			if (shoupai[ck][r] > temp1 - 1)
			{
				r++;
				if (shoupai[ck][r] < temp1 + 4)
				{
					r++;
					if (shoupai[ck][r] < temp1 + 4)
					{
						gangr = r;
						state[3] = 1;
						temp = 1;
						gangpai = temp1;
					}
				}
				break;
			}
		}
	}
}
void checkjiagang()//#检查加杠
{
	int temp2, temp3, temp4;
	jiagangr = -1;
	for (temp4 = 0; temp4 < valsp[now] + 1; temp4++)
	{
		temp2 = (shoupai[now][temp4] / 4) * 4;
		for (temp3 = 1; temp3 <= peng[now][0]; temp3++)
		{
			if (peng[now][temp3] == temp2)
			{
				jiagangr = temp4;
				jiagangr1 = temp3;
				jiagangr2 = peng[now][temp3];
			}
		}
	}
}
void checkpeng()//#检查碰牌
{
	pengr = -1;
	temp1 = (active / 4) * 4;
	if (valsp[ck] == 1)
		return;
	for (r = 0; (r < valsp[ck] - 1) && (shoupai[ck][r] < temp1 + 4); r++)
	{
		if (shoupai[ck][r] > temp1 - 1)
		{
			if ((shoupai[ck][r] == 19) || (shoupai[ck][r] == 55) || (shoupai[ck][r] == 90) || (shoupai[ck][r] == 91))
				pengtemp = 1;
			else pengtemp = 0;
			r++;
			if (shoupai[ck][r] < temp1 + 4)
			{
				if ((shoupai[ck][r] == 19) || (shoupai[ck][r] == 55) || (shoupai[ck][r] == 90) || (shoupai[ck][r] == 91))
					pengtemp += 1;
				pengr = r;
				state[2] = 1;
				temp = 1;
				pengpai = temp1;
				return;
			}
			break;
		}
	}
}

void checkrong()//#放铳 
{
	ifzimo = 0;
	shoupai[ck][valsp[ck]] = active;
	for (r = valsp[ck]; (shoupai[ck][r] < shoupai[ck][r - 1]) && (r > 0); r--)
	{
		tempck = shoupai[ck][r];
		shoupai[ck][r] = shoupai[ck][r - 1];
		shoupai[ck][r - 1] = tempck;
	}
	rongnum = r;
	checkhu();
	for (r = rongnum; r < valsp[ck]; r++)
	{
		tempck = shoupai[ck][r];
		shoupai[ck][r] = shoupai[ck][r + 1];
		shoupai[ck][r + 1] = tempck;
	}
	shoupai[ck][valsp[ck]] = 0;
}
void checklichi()//#检查能否立直
{
	int temp4, temp5, temp6, temp7, temp8, temp9;
	valsp[4] = valsp[now];
	state[0] = 0;
	lichi[4] = 0;
	hur = 0;
	if (wholestate > -1)
		return;
	if (lichi[now] == 1)
		return;
	if (menqianqing[now] == 0)
		return;
	for (temp5 = 0; temp5 < valsp[4]; temp5++)
		shoupai[4][temp5] = shoupai[now][temp5];
	for (temp6 = 0; temp6 < 136; temp6 += 4)
	{
		ck = 4;
		temp8 = temp6;
		for (temp7 = 0; (temp7 < valsp[4]) && (shoupai[4][temp7] < temp6 + 4); temp7++)
		{
			if (shoupai[4][temp7] == temp8)
				temp8++;
		}
		if (temp8 == temp6 + 4)
		{
			ck = now;
			continue;
		}
		shoupai[4][valsp[4]] = temp8;
		for (temp7 = valsp[4]; (temp7 > 0) && (shoupai[4][temp7] < shoupai[4][temp7 - 1]); temp7--)
		{
			temp4 = shoupai[4][temp7];
			shoupai[4][temp7] = shoupai[4][temp7 - 1];
			shoupai[4][temp7 - 1] = temp4;
		}
		lichi[4] = 1;
		checkhu();
		lichi[4] = 0;
		ck = now;
		for (temp9 = temp7; temp9 < valsp[4]; temp9++)
		{
			temp4 = shoupai[4][temp9];
			shoupai[4][temp9] = shoupai[4][temp9 + 1];
			shoupai[4][temp9 + 1] = temp4;
		}
		if (hur == 1)
			break;
	}

	if (hur == 1)
	{
		state[0] = 1;
		hur = 0;
		return;
	}
	return;
}
void checkzigang()//#暗杠 
{
	int temp2, temp3;
	zigangr = -1;
	for (temp2 = 0; temp2 < valsp[now] - 2; temp2++)
	{
		temp3 = shoupai[now][temp2];
		if ((temp3 % 4 == 0) && (shoupai[now][temp2 + 1] == temp3 + 1) && (shoupai[now][temp2 + 2] == temp3 + 2) && (shoupai[now][temp2 + 3] == temp3 + 3))
		{
			zigangr = temp2 + 3;
			gangpai = temp3;
		}
	}
}
void checkzimo()//#检查能否自摸
{
	ifzimo = 1;
	hur = 0;
	zimor = 0;
	checkhu();
	if (hur == 1)
	{
		zimor = 1;
		hur = 0;
		return;
	}
}

