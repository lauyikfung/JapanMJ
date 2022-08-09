#include<stdio.h>
#include<stdlib.h>
extern int r, chika, temp1, ck, temp, chir, chika, chizuo, chiyou, active;
extern int valsp[5], shoupai[5][14], state[5], chitemp[3];
void checkchika()//#¼ì²é³ÔÅÆº¯Êý
{
	int r1;
	chika = 0;
	for (r = 0; (r < valsp[ck] - 1) && (shoupai[ck][r] < temp1); r++)
	{
		if (shoupai[ck][r] > temp1 - 5)
		{
			r1 = r;
			for (; (r < valsp[ck]) && (shoupai[ck][r] < temp1 + 8); r++)
				if (shoupai[ck][r] > temp1 + 3)
				{
					chitemp[0] = shoupai[ck][r1];
					state[1] = 1;
					temp = 1;
					chitemp[2] = shoupai[ck][r];
					chitemp[1] = active;
					chir = r;
					chika = 1;
					return;
				}
			break;
		}
	}
}

void checkchizuo()//#
{
	int r1;
	chizuo = 0;
	for (r = 0; (r < valsp[ck] - 1) && (shoupai[ck][r] < temp1 + 8); r++)
	{
		if (shoupai[ck][r] > temp1 + 3)
		{
			r1 = r;
			for (; (r < valsp[ck]) && (shoupai[ck][r] < temp1 + 12); r++)
				if (shoupai[ck][r] > temp1 + 7)
				{
					chitemp[1] = shoupai[ck][r1];
					state[1] = 1;
					temp = 1;
					chitemp[2] = shoupai[ck][r];
					chitemp[0] = active;
					chir = r;
					chizuo = 1;
					return;
				}
		}
	}
}

void checkchiyou()//#
{
	int r1;
	chiyou = 0;
	for (r = 0; (r < valsp[ck] - 1) && (shoupai[ck][r] < temp1 - 4); r++)
	{
		if (shoupai[ck][r] > temp1 - 9)
		{
			r1 = r;
			for (; (r < valsp[ck]) && (shoupai[ck][r] < temp1); r++)
				if (shoupai[ck][r] > temp1 - 5)
				{
					chitemp[0] = shoupai[ck][r1];
					state[1] = 1;
					temp = 1;
					chitemp[1] = shoupai[ck][r];
					chitemp[2] = active;
					chir = r;
					chiyou = 1;
					return;
				}
		}
	}
}

