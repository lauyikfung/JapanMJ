#include <stdio.h>
#include <stdlib.h>
#include "ckhu.h"
extern int nowpai, gangnum, zimor, abc, ck, zhuang, aaa, abc, hur, yiman, now;
extern int lichi[5], chistate[4][5][3], peng[4][5], gang[4][9], pengstate[4][5];
extern int guoshiwushuangr, qiduizir, temp, hutype, guoshiwushuang[13];
extern int menqianqing[4], shoupai[5][14], valsp[5], xyz[4], xxx[4], cking[34], state[5];
void checkhu()//#此4个函数判定胡牌 
{
	int temp2, temp3, temp4, temp5, temp6, temp7, temp8, temp9, yise, yise1;
	hur = 0;
	guoshiwushuangr = 0;
	qiduizir = 0;
	temp7 = 0;
	temp8 = 0;
	for (temp2 = 0; temp2 < 34; temp2++)
		cking[temp2] = 0;
	for (temp2 = 0; temp2 < valsp[ck] + 1; temp2++)
	{
		temp3 = shoupai[ck][temp2] / 4;
		cking[temp3]++;
	}
	if (valsp[ck] == 13)
	{
		for (temp2 = 0, temp3 = 0; temp2 < 34; temp2++)//七对子判定
		{
			if (cking[temp2] == 2)
				temp3++;
		}
		if (temp3 == 7)
		{
			hur = 1;
			temp = 1;
			qiduizir = 1;
			state[4] = 1;
			hutype = 2;
			return;
		}
	}
	for (temp2 = 0; temp2 < 34; temp2++)
	{
		temp4 = valsp[ck] / 3;
		temp5 = 0;
		temp6 = 0;
		aaa = 0;
		abc = 0;
		for (temp7 = 0; temp7 < 34; temp7++)
			cking[temp7] = 0;
		for (temp7 = 0; temp7 < valsp[ck] + 1; temp7++)
		{
			temp3 = shoupai[ck][temp7] / 4;
			cking[temp3]++;
		}
		if (cking[temp2] < 2)
			continue;
		cking[temp2] -= 2;
		temp6 = 1;
		for (temp9 = 33; temp9 > 26; temp9--)
		{
			if (cking[temp9] % 3 != 0)
			{
				cking[temp2] += 2;
				temp5 = 1;
				break;
			}
			else
			{
				temp8 = (cking[temp9] / 3);
				if (temp8 == 1)
				{
					xxx[aaa] = temp9;
					aaa += temp8;
					temp4--;
				}
			}
		}
		if (temp5 == 1)
			continue;//
		for (temp9 = 0; (temp9 < 27) && (temp4 > 0); temp9++)
		{
			if (cking[temp9] > 2)
			{
				cking[temp9] -= 3;
				xxx[aaa] = temp9;
				aaa++;
				temp4--;
			}
			if (cking[temp9] > 0)
			{
				if (temp9 % 9 > 6)
				{
					cking[temp2] += 2;
					break;
				}
				if (cking[temp9] != 0)
				{
					if ((cking[temp9 + 1] >= cking[temp9]) && (cking[temp9 + 2] >= cking[temp9]))
					{
						temp8 = cking[temp9];
						cking[temp9] = 0;
						cking[temp9 + 1] -= temp8;
						cking[temp9 + 2] -= temp8;
						if (temp8 == 1)
						{
							xyz[abc] = temp9;
							abc++;
						}
						else
						{
							xyz[abc] = temp9;
							xyz[abc + 1] = temp9;
							abc += 2;
						}
					}
					else
					{
						cking[temp2] += 2;
						temp5 = 1;
						break;
					}
				}
			}
		}
		if (temp5 == 1)
			continue;
		if (abc + aaa > valsp[ck] / 3 - 1 && temp6 == 1)
		{
			hur = 1;
			temp = 1;
			state[4] = 1;
			hutype = 1;
			break;
		}
	}
	for (temp2 = 0; temp2 < 34; temp2++)
		cking[temp2] = 0;
	for (temp2 = 0; temp2 < valsp[ck] + 1; temp2++)
	{
		temp3 = shoupai[ck][temp2] / 4;
		cking[temp3]++;
	}
	if (hur == 1)//有役判定
	{
		checkyouyi(temp2);
		return;
	}
	for (temp7 = 0, temp8 = 0; (valsp[ck] == 13) && (temp7 < 14); temp7++)//国士无双判定 
	{
		if ((shoupai[ck][temp7] / 4 != guoshiwushuang[temp8] / 4))
		{
			if ((temp7 == 0) && (shoupai[ck][temp7] % 4 != guoshiwushuang[temp8 - 1]))
				break;
		}
		else
			temp8++;
	}
	if (temp8 == 13)
	{
		hur = 1;
		temp = 1;
		guoshiwushuangr = 1;
		state[4] = 1;
		hutype = 3;
		return;
	}
}