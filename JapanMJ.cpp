// ��ȷ�ϱ�������ȫ�ɱ�С���Ա�������
// ����������㡢������ӳ�ع�������衢�ٿ�Դ
// ѧ�ţ�2020010909��2020010888��2020012561��2020012577��2020012567
// ʱ�䣺2021��5��30�� 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <graphics.h>
#include <conio.h>
#include "chckhu.h"
#include "checking.h"
#include "ckhu.h"
#include "ending.h"
#include "already.h"
#include "check_currnt.h"
#include "AI.h"
#include "GUI.h"
#include "printing.h"
#pragma comment(lib,"winmm.lib")
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


char pai[136][6] = { "1�� ","1�� ","1�� ","1�� ","2�� ","2�� ","2�� ","2�� ","3�� ","3�� ","3�� ","3�� ","4�� ","4�� ","4�� ","4�� ",
"5�� ","5�� ","5�� ","����","6�� ","6�� ","6�� ","6�� ","7�� ","7�� ","7�� ","7�� ","8�� ","8�� ","8�� ","8�� ","9�� ","9�� ","9�� ","9�� ",
"1�� ","1�� ","1�� ","1�� ","2�� ","2�� ","2�� ","2�� ","3�� ","3�� ","3�� ","3�� ","4�� ","4�� ","4�� ","4�� ","5�� ","5�� ","5�� ","����",
"6�� ","6�� ","6�� ","6�� ","7�� ","7�� ","7�� ","7�� ","8�� ","8�� ","8�� ","8�� ","9�� ","9�� ","9�� ","9�� ",
"1Ͳ ","1Ͳ ","1Ͳ ","1Ͳ ","2Ͳ ","2Ͳ ","2Ͳ ","2Ͳ ","3Ͳ ","3Ͳ ","3Ͳ ","3Ͳ ","4Ͳ ","4Ͳ ","4Ͳ ","4Ͳ ","5Ͳ ","5Ͳ ","��Ͳ","��Ͳ",
"6Ͳ ","6Ͳ ","6Ͳ ","6Ͳ ","7Ͳ ","7Ͳ ","7Ͳ ","7Ͳ ","8Ͳ ","8Ͳ ","8Ͳ ","8Ͳ ","9Ͳ ","9Ͳ ","9Ͳ ","9Ͳ ",
"�|�L","�|�L","�|�L","�|�L","���L","���L","���L","���L","���L","���L","���L","���L","���L","���L","���L","���L",
"�t��","�t��","�t��","�t��","�װ�","�װ�","�װ�","�װ�","�lؔ","�lؔ","�lؔ","�lؔ" };
TCHAR yizhong[52][32] = { _T("��ֱ		һ��"),_T("���۾�		һ��"),_T("��ǰ��������	һ��"),_T("ƽ��		һ��"),_T("һ����		һ��"),
_T("����		һ��"),_T("���Ͽ���	һ��"),_T("��������	һ��"),_T("�ӵ�����	һ��"),_T("һ��		һ��"),
_T("����ֱ		����"),_T("��ɫͬ��	����"),_T("������		����"),_T("�ԶԺ�		����"),_T("������		����"),
_T("С��Ԫ		����"),_T("����ͷ		����"),_T("�߶���		����"),_T("��ȫ���۾�	����"),_T("һ��ͨ��	����"),
_T("��ɫͬ˳	����"),_T("������		����"),_T("��ȫ���۾�	����"),_T("��һɫ		����"),_T("��һɫ		����"),
_T("��������"),_T("���		����"),_T("�غ�		����"),_T("����Ԫ		����"),_T("�İ���		����"),
_T("��һɫ		����"),_T("��һɫ		����"),_T("����ͷ		����"),_T("��ʿ��˫	����"),_T("С��ϲ		����"),
_T("�ĸ���		����"),_T("��������	����"),_T("�İ��̵���	˫������"),_T("������������	˫������"),_T("����ϲ		˫������"),
_T("��ʿ��˫ʮ������	˫������"),_T("���ƣ���	һ��"),_T("���ƣ���	һ��"),_T("���ƣ���	һ��"),_T("�����ƣ���	һ��"),
_T("�����ƣ���	һ��"),_T("�����ƣ���	һ��"),_T("�����ƣ���	һ��"),_T("�Է��ƣ���	һ��"),_T("�Է��ƣ���	һ��"),
_T("�Է��ƣ���	һ��"),_T("�Է��ƣ���	һ��") };
int guoshiwushuang[13] = { 0, 32, 36, 68, 72, 104, 108, 112, 116, 120, 124, 128, 132 };//�۾���

int prior_value[14] = { 0 };//AI�ж�Ȩ��ֵ
int order[136] = { 0 };//�ƶ�
int shoupai[5][14] = { 0 };//���ƣ�shoupai��4�����ڼ��������ͣ�
int cking[34] = { 0 };//34=136/4��������ʱ����������
int ifyouyi[52] = { 0 };//��ʱ����Ƿ�����
int alyi[52] = { 0 };//���ݵ�����С�����ж�����
int xxx[4] = { 0 };//������ʼ�ƺţ�0~33��
int xyz[4] = { 0 };//������ʼ�ƺţ�0~33��
int state[5] = { 0 };//�ж��ܷ�����ܺ���ֱ
int lichi[5] = { 0 };//��ֱָʾ
int wlichi[5] = { 0 };//w��ֱָʾ
int chistate[4][5][3] = { 0 };//���ơ��ˡ�����ţ�0Ϊ���������������������ƺţ�0~135����
int peng[4][5] = { 0 };//���ƣ����ˡ���0��Ϊ�������������ˡ���n��Ϊ�����ƺţ�0~132��4�ı�����
int pengstate[4][5] = { 0 };//���ƣ����ˡ���n��Ϊ���Ƶ�״̬��0Ϊ�޺챦�ƣ�1or2Ϊһ�Ż����ź챦��
int gang[4][9] = { 0 };//���ƣ����ˡ���0���������������ˡ���n��(1~4)Ϊ�����ƺţ�0~132��4�ı����������ˡ���n����5~8��Ϊ�ܵ�״̬��1����2����3�Ӹ�
int dragon[5] = { 0 };//ʵ�ʱ���
int dratishi[5] = { 0 };//������ʾ��
int lidra[5] = { 0 };//�ﱦ��
int qipaidui[4][40] = { 0 };//�������ƶѣ����ˡ���0��Ϊ���ƶ�����
int chitemp[3] = { 0 };//������ʱ����
int feng1[4] = { 0 };//�ļҸ��Եķ���
int menqianqing[4] = { 1, 1, 1, 1 };//��ǰ��1
int valsp[5] = { 13, 13, 13, 13, 13 };//�ǵ�ǰ�غ�����������
TCHAR manguanlv[11][13] = { _T(" "),_T("����"),_T("����"),_T("����"),_T("������"),_T("�ۼ�����"),
_T("��������"),_T("��������"),_T("�ı�����"),_T("�屶����"),_T("��������") };//��������

int zhuang, active, now, ck, wholestate, nowpai, drastate, gangnum = 0, changshu;
//zhuang=ׯ�ң�active=��ǰ�ƶ�Ӧ������now=��ǰ��ң�ck=checking�е���ң�wholestate=Ӯ�ң�-1���֣���nowpai=���������ǵڼ����ƣ�drastate=����������
int i, j, k, r, m, temp, temp1, temphu, temphu1, tempck;//��ʱ����
int gangr, gangpai, pengr, pengpai, hur, ifzimo, rongnum, zigangr, lichir, jiagangr;
//gangr��gangpai��pengr��pengpai��zigangr��jiagangr�������еڼ������ԼӸܣ��ܡ��������ܡ��Ӹ���ʱ������
//hur��lichir�����Ƿ��ܺ��ƺ���ֱ��ifzimo�����Ƿ�������rongnum�����ʱ����
int zimor, guoshiwushuangr, qiduizir, chir, dranum, lidranum, pengtemp, jiagangr1, jiagangr2;
//zimor��guoshiwushuangr��qiduizir��������ʿ��˫���߶������chir������ʱ������dranum��lidranum�����ﱦ�ơ�pengtemp������ʱ����
//jiagangr1���Ӹ���Ϊ�ڼ������ƣ���jiagangr2�Ӹ��ƣ�4������
int hutype, aaa = 0, abc = 0, q, get, fu, fu1, fan, fan1, point, point1, yiman, dian, danqi, ganghou, yixun, yifa, focus;
//focus����ǰ�����Ƶ���ţ�0~valsp����yifa=��ֱ��һ����yixun�ж���͵غͣ�ganghou�ж����Ͽ�����yiman��dian��point��point1��fan��fan1��fu��fu1�������
//getĿǰ�ƶ�Ӧ������0~33����qȸͷ��abc��aaa�ж����Ӻ�˳�ӡ�hutype��������
int chizuo, chiyou, chika, strategycheckif, currenting = 0, froming, leijipoint;
//chizuo��chiyou��chika��Ϊ�жϳ��Ƶ���ʱ������currentingΪGUI�йر�����fromingΪ�ж������Եı�����leijipointΪ�ۼƵ���
char c;
//temp:�ж��ܷ�������� ��temp1�����ܳ��ж�����ɱ����� 

void rtrn()//*���ؿ�ʼ���� 
{
	if (wholestate < 0)
	{
		slp(3000);
		return;
	}
	int i;
	IMAGE img;
	loadimage(&img, _T("����1.png"), 1425, 675);
	putimage(0, 0, &img);
	LOGFONT f;
	gettextstyle(&f);
	setbkmode(TRANSPARENT);
	f.lfHeight = 40;
	settextcolor(RGB(255, 255, 255));
	wcscpy_s(f.lfFaceName, _T("�����п�"));
	settextstyle(&f);
	if (wholestate == 0)
	{
		outtextxy(45, 80, _T("��Ӯ�ˣ�"));
	}
	if (wholestate == 1)
	{
		outtextxy(45, 80, _T("�¼�Ӯ�ˣ�"));
	}
	if (wholestate == 2)
	{
		outtextxy(45, 80, _T("�Լ�Ӯ�ˣ�"));
	}
	if (wholestate == 3)
	{
		outtextxy(45, 80, _T("�ϼ�Ӯ�ˣ�"));
	}
	outtextxy(45, 140, _T("Ӯ�����ͣ�"));
	for (i = 0; i < valsp[wholestate] + 1; i++)
	{
		majiangpai(shoupai[wholestate][i], i, 45, 250);
	}
	for (i = 1; i <= gang[wholestate][0]; i++)
	{
		for (j = 0; j < 4; j++)
			daoxiamajiangpai(gang[wholestate][i] + j, 0, j, 45 + 150 * i - 150, 390);
	}
	for (i = 1; i <= peng[wholestate][0]; i++)
	{
		if (pengstate[wholestate][i] == 0)
			for (j = 0; j < 3; j++)
				daoxiamajiangpai(peng[wholestate][i], 0, j, 40 + 150 * (i + gang[wholestate][0]) - 150, 632);
		else if (pengstate[0][i] == 1)
		{
			daoxiamajiangpai(peng[wholestate][i], 0, 0, 40 + 150 * (i + gang[wholestate][0]) - 150, 632);
			daoxiamajiangpai(peng[wholestate][i], 0, 1, 40 + 150 * (i + gang[wholestate][0]) - 150, 632);
			daoxiamajiangpai(peng[wholestate][i] + 3, 0, 2, 40 + 150 * (i + gang[wholestate][0]) - 150, 632);
		}
		else
		{
			daoxiamajiangpai(peng[wholestate][i], 0, 0, 40 + 150 * (i + gang[wholestate][0]) - 150, 632);
			daoxiamajiangpai(peng[wholestate][i] + 2, 0, 1, 40 + 150 * (i + gang[wholestate][0]) - 150, 632);
			daoxiamajiangpai(peng[wholestate][i] + 3, 0, 2, 40 + 150 * (i + gang[wholestate][0]) - 150, 632);
		}
	}
	for (i = 1; i <= chistate[wholestate][0][0]; i++)
	{
		for (j = 0; j < 3; j++)
			daoxiamajiangpai(chistate[wholestate][i][j], 0, j, 45 + 150 * (i + gang[wholestate][0] + peng[wholestate][0]) - 150, 390);
	}
	slp(5000);
}



void initialize()//*��ʼ��
{
	int temp;
	nowpai = 52;
	froming = 0;
	ganghou = 0;
	yixun = 2;
	yifa = -1;
	k = 0;
	jiagangr = -1;
	jiagangr1 = -1;
	jiagangr2 = -1;
	wholestate = -1;
	drastate = 1;
	hutype = -1;
	clearrectangle(0, 0, 1425, 675);
	IMAGE s;
	loadimage(&s, _T("homepage3.jpg"), 1425, 675);
	putimage(0, 0, &s);
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 70;
	f.lfWeight = 800;
	f.lfItalic = 0;
	wcscpy_s(f.lfFaceName, _T("�����п�"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	settextcolor(RGB(163, 73, 164));
	TCHAR changnum[2];
	_stprintf_s(changnum, _T("%d"), changshu);
	outtextxy(640, 530, changnum);
	outtextxy(700, 530, _T("����"));
	slp(5000);
	IMAGE img;
	loadimage(&img, _T("����1.png"), 1425, 675);
	putimage(0, 0, &img);
	for (i = 0; i < 5; i++)
		lichi[i] = 0;
	for (i = 0; i < 5; i++)
		wlichi[i] = 0;
	for (i = 0; i < 4; i++)
		chistate[i][0][0] = 0;
	for (i = 0; i < 4; i++)
		pengstate[i][0] = 0;
	for (i = 0; i < 4; i++)
		peng[i][0] = 0;
	for (i = 0; i < 4; i++)
		gang[i][0] = 0;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 40; j++)
			qipaidui[i][j] = 0;
	for (i = 0; i < 4; i++)
		menqianqing[i] = 1;
	for (i = 0; i < 5; i++)
		valsp[i] = 13;
	for (i = 0; i < 136; i++)
		order[i] = i;
	for (i = 0; i < 136; i++)
	{
		j = rand() % (136 - i) + i;
		k = order[i];
		order[i] = order[j];
		order[j] = k;
	}
	slp(500);
	zhuang = rand() % 4;
	for (j = 0; j < 4; j++)
	{
		for (i = 0; i < 13; i++)
		{
			shoupai[zhuang][i] = order[i + 13 * j];
		}
		zhuang = (zhuang == 3) ? 0 : (zhuang + 1);
	}
	switch (zhuang)
	{
	case 0:
		LOGFONT g;
		gettextstyle(&g);
		g.lfHeight = 100;
		g.lfItalic = 0;
		wcscpy_s(g.lfFaceName, _T("Ink Free"));
		g.lfQuality = ANTIALIASED_QUALITY;
		settextstyle(&g);
		settextcolor(RGB(255, 255, 255));
		outtextxy(440, 420, _T("���ĳ���Ϊ:�|�L"));
		slp(2000);
		feng1[0] = 0;
		feng1[1] = 1;
		feng1[2] = 2;
		feng1[3] = 3;
		break;
	case 1:
		gettextstyle(&g);
		g.lfHeight = 100;
		g.lfItalic = 0;
		wcscpy_s(g.lfFaceName, _T("Ink Free"));
		g.lfQuality = ANTIALIASED_QUALITY;
		settextstyle(&g);
		settextcolor(RGB(255, 255, 255));
		outtextxy(440, 420, _T("���ĳ���Ϊ:���L"));
		slp(2000);
		feng1[0] = 3;
		feng1[1] = 0;
		feng1[2] = 1;
		feng1[3] = 2;
		break;
	case 2:
		gettextstyle(&g);
		g.lfHeight = 100;
		g.lfItalic = 0;
		wcscpy_s(g.lfFaceName, _T("Ink Free"));
		g.lfQuality = ANTIALIASED_QUALITY;
		settextstyle(&g);
		settextcolor(RGB(255, 255, 255));
		outtextxy(440, 420, _T("���ĳ���Ϊ:���L"));
		slp(2000);
		feng1[0] = 2;
		feng1[1] = 3;
		feng1[2] = 0;
		feng1[3] = 1;
		break;
	default:
		gettextstyle(&g);
		g.lfHeight = 100;
		g.lfItalic = 0;
		wcscpy_s(g.lfFaceName, _T("Ink Free"));
		g.lfQuality = ANTIALIASED_QUALITY;
		settextstyle(&g);
		settextcolor(RGB(255, 255, 255));
		outtextxy(440, 420, _T("���ĳ���Ϊ:���L"));
		slp(2000);
		feng1[0] = 1;
		feng1[1] = 2;
		feng1[2] = 3;
		feng1[3] = 0;
		break;
	}
	slp(1000);
	for (i = 0; i < 4; i++)
	{
		for (j = 12; j > 0; j--)
		{
			for (k = 0; k < j; k++)
			{
				if (shoupai[i][k] > shoupai[i][k + 1])
				{
					temp = shoupai[i][k];
					shoupai[i][k] = shoupai[i][k + 1];
					shoupai[i][k + 1] = temp;
				}
			}
		}
	}
	for (i = 0; i < 5; i++)
	{
		dratishi[i] = order[i + 126];
		dragon[i] = dra(dratishi[i]);
		lidra[i] = dra(order[i + 131]);
	}
	shwdra();
	for (i = 0; i < 13; i++)
		majiangpai(shoupai[0][i], i, 303, 525);
	now = zhuang;
}



void begin()//*��ת 
{
	while (nowpai < 122 + gangnum)
	{
		if (now == yifa)
			yifa = -1;
		bases();
		putin(now);
		if (now == 0)
		{
			slp(1000);
			shwdra();
			currnt();
		}
		else
		{
			bases();
			strategy();
			bases();
		}
		if (wholestate > -1)
			return;
		if (lichi[0] + lichi[1] + lichi[2] + lichi[3] == 4)
			return;
		if (gang[0][0] + gang[1][0] + gang[2][0] + gang[3][0] == 4)
			return;
		if (yixun > 0 && now == (zhuang == 3) ? (zhuang + 1) : 0)
			yixun--;
	}
}

void qingsuan()//!*�վ����� 
{
	int i, j, k, temp4, reddranum = 0;
	rtrn();
	TCHAR pnts2[7];
	TCHAR hjds2[] = _T("�ۼƵ�����");
	LOGFONT f;
	gettextstyle(&f);
	f.lfItalic = 0;
	setbkmode(TRANSPARENT);
	settextcolor(RGB(255, 255, 255));
	wcscpy_s(f.lfFaceName, _T("�����п�"));
	f.lfQuality = ANTIALIASED_QUALITY;
	if (wholestate == -1)
	{
		HWND hwnd = GetHWnd();
		SetWindowText(hwnd, _T("Nihon Mahjong"));
		clearrectangle(0, 0, 1425, 675);
		IMAGE img;
		loadimage(&img, _T("����1.png"), 1425, 675);
		putimage(0, 0, &img);
		f.lfHeight = 225;
		settextstyle(&f);
		TCHAR draprint[] = _T("��  ��");
		outtextxy(375, 225, draprint);
		gettextstyle(&f);
		f.lfHeight = 50;
		settextstyle(&f);
		outtextxy(645, 30, hjds2);
		_stprintf_s(pnts2, _T("%d"), leijipoint);
		outtextxy(945, 30, pnts2);
		slp(3000);
	}
	else
	{
		gettextstyle(&f);
		f.lfHeight = 40;
		settextstyle(&f);
		hupaihou();
		dranum = 0;
		lidranum = 0;
		reddranum = 0;
		for (i = 0; i < valsp[now] + 1; i++)
		{
			for (j = 0; j < drastate; j++)
				if (shoupai[now][i] / 4 == dragon[j] / 4)
					dranum++;
			for (j = 0; j < drastate; j++)
				if (shoupai[now][i] / 4 == lidra[j] / 4)
					lidranum++;
			if ((shoupai[now][i] == 19) || (shoupai[now][i] == 55) || (shoupai[now][i] == 90) || (shoupai[now][i] == 91))
				reddranum++;
		}
		for (i = 1; i <= chistate[now][0][0]; i++)
		{
			for (k = 0; k < 3; k++)
			{
				for (j = 0; j < drastate; j++)
					if (chistate[now][i][k] / 4 == dragon[j] / 4)
						dranum++;
				for (j = 0; j < drastate; j++)
					if (chistate[now][i][k] / 4 == lidra[j] / 4)
						lidranum++;
				if ((chistate[now][i][k] == 19) || (chistate[now][i][k] == 55) || (chistate[now][i][k] == 90) || (chistate[now][i][k] == 91))
					reddranum++;
			}
		}
		for (i = 1; i <= peng[now][0]; i++)
		{
			for (j = 0; j < drastate; j++)
				if (peng[now][i] / 4 == dragon[j] / 4)
					dranum += 3;
			for (j = 0; j < drastate; j++)
				if (peng[now][i] / 4 == lidra[j] / 4)
					lidranum += 3;
			reddranum += pengstate[now][i];
		}
		for (i = 1; i <= gang[now][0]; i++)
		{
			for (j = 0; j < drastate; j++)
				if (gang[now][i] / 4 == dragon[j] / 4)
					dranum += 4;
			for (j = 0; j < drastate; j++)
				if (gang[now][i] / 4 == lidra[j] / 4)
					lidranum += 4;
			if ((gang[now][i] == 16) || (gang[now][i] == 52))
				reddranum += 1;
			if (gang[now][i] == 88)
				reddranum += 2;
		}
		slp(1000);
		HWND hwnd = GetHWnd();
		SetWindowText(hwnd, _T("Nihon Mahjong"));
		clearrectangle(0, 0, 1425, 675);
		IMAGE img;
		loadimage(&img, _T("����1.png"), 1425, 675);
		putimage(0, 0, &img);
		gettextstyle(&f);
		setbkmode(TRANSPARENT);
		f.lfHeight = 40;
		settextcolor(RGB(255, 255, 255));
		wcscpy_s(f.lfFaceName, _T("�����п�"));
		settextstyle(&f);
		if (wholestate == 0)
		{
			outtextxy(45, 80, _T("��Ӯ�ˣ�"));
		}
		if (wholestate == 1)
		{
			outtextxy(45, 80, _T("�¼�Ӯ�ˣ�"));
		}
		if (wholestate == 2)
		{
			outtextxy(45, 80, _T("�Լ�Ӯ�ˣ�"));
		}
		if (wholestate == 3)
		{
			outtextxy(45, 80, _T("�ϼ�Ӯ�ˣ�"));
		}
		LOGFONT f;
		gettextstyle(&f);
		f.lfHeight = 37.5;
		f.lfItalic = 0;
		wcscpy_s(f.lfFaceName, _T("�����п�"));
		f.lfQuality = ANTIALIASED_QUALITY;
		settextstyle(&f);
		TCHAR draprint[] = _T("���ƣ�"), lidraprint[] = _T("�ﱦ�ƣ�"), reddraprint[] = _T("�౦�ƣ�");
		TCHAR drnm[3], lidrnm[3], reddrnm[3];
		if (dranum)
		{
			_stprintf_s(drnm, _T("%d"), dranum);
			outtextxy(45, 150, draprint);
			outtextxy(157.5, 150, drnm);
			slp(500);
		}
		if ((lidranum > 0) && (lichi[now] == 1))
		{
			_stprintf_s(lidrnm, _T("%d"), lidranum);
			outtextxy(345, 150, lidraprint);
			outtextxy(457.5, 150, lidrnm);
			slp(500);
		}
		if (reddranum)
		{
			_stprintf_s(reddrnm, _T("%d"), reddranum);
			outtextxy(645, 150, reddraprint);
			outtextxy(757.5, 150, reddrnm);
			slp(500);
		}
		if (lichi[now] == 1)
			fan1 += lidranum;
		fan1 = fan1 + dranum + reddranum;
		point1 = jisuanfan(fan1, fu1);
		j = 197.5;
		k = 45;
		for (i = 0; i < 52; i++)
			if (alyi[i] > 0)
			{
				if (j == 555)
				{
					j = 150;
					k += 750;
				}
				slp(500);
				outtextxy(k, j, yizhong[i]);
				j += 45;
			}
		slp(1000);
		temp4 = jisuanmg(point1);
		TCHAR hjds[] = _T("�ϼƵ�����");
		if (temp4 > 0)
		{
			f.lfHeight = 60;
			outtextxy(150, 570, manguanlv[temp4]);
		}
		else
		{
			f.lfHeight = 67.5;
			TCHAR fuprint[] = _T("��"), fanprint[] = _T("��");
			TCHAR funum[4], fannum[3];
			_stprintf_s(funum, _T("%d"), fu1);
			_stprintf_s(fannum, _T("%d"), fan1);
			outtextxy(150, 570, funum);
			outtextxy(352.5, 570, fuprint);
			outtextxy(420, 570, fannum);
			outtextxy(555, 570, fanprint);
		}
		outtextxy(645, 570, hjds);
		outtextxy(645, 30, hjds2);
		TCHAR pnts[6];
		if (wholestate == 0)
			leijipoint += point1;
		else if (wholestate > 0)
		{
			if (zhuang == 0 && froming == 0)
				leijipoint -= point1;
			else if (froming == 0)
				leijipoint -= point1;
			else if (zimor == 0 && zhuang == 0)
				leijipoint -= (point1 / 2) / 100 * 100;
			else leijipoint -= (point1 / 4) / 100 * 100;
		}
		f.lfHeight = 90;
		_stprintf_s(pnts, _T("%d"), point1);
		_stprintf_s(pnts2, _T("%d"), leijipoint);
		outtextxy(945, 570, pnts);
		outtextxy(945, 30, pnts2);
		slp(5000);
	}
}

int main()
{
	PlaySound(_T(".\\ww\\һ·����һ·��2.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	initgraph(1425, 675);
	while (1) {
		int info = 0, info1 = 0;
		int bttn = 0;
		MOUSEMSG m;
		HWND hwnd = GetHWnd();
		SetWindowText(hwnd, _T("Nihon Mahjong"));
		leijipoint = 25000;
		changshu = 1;
		IMAGE img;
		loadimage(&img, _T("homepage.jpg"), 1425, 675);
		putimage(0, 0, &img);


		LINESTYLE lstyle;
		getlinestyle(&lstyle);
		setlinestyle(PS_SOLID | PS_ENDCAP_ROUND, 3);
		setcolor(RGB(255, 215, 0));
		roundrect(910, 400, 1050, 520, 60, 60);

		setbkmode(TRANSPARENT);
		settextcolor(RED);
		LOGFONT f;

		setbkmode(TRANSPARENT);
		settextcolor(WHITE);
		LOGFONT f2;
		gettextstyle(&f2);
		f2.lfHeight = 25;
		wcscpy_s(f2.lfFaceName, _T("���ĵ���"));

		setbkmode(TRANSPARENT);
		settextcolor(WHITE);
		gettextstyle(&f2);
		f2.lfHeight = 18;
		wcscpy_s(f2.lfFaceName, _T("���ĵ���"));
		f2.lfItalic = 0;
		f2.lfWeight = 1500;
		f2.lfQuality = ANTIALIASED_QUALITY;
		settextstyle(&f2);
		outtextxy(1230, 615, _T("ver3.0.1(beta)"));
		outtextxy(1230, 637.5, _T("���ۡ���������г"));

		setcolor(RGB(200, 191, 231));
		roundrect(1170, 405, 1290, 510, 60, 60);

		LOGFONT f1;
		
		while (true)
		{
			m = GetMouseMsg();
			if (m.x > 910 && m.x < 1050 && m.y>400 && m.y < 520)
			{
				setcolor(RGB(255, 0, 0));
				roundrect(910, 400, 1050, 520, 60, 60);
				bttn = 1;
			}
			else if (m.x > 1170 && m.x < 1290 && m.y>405 && m.y < 515)
			{
				setcolor(RGB(102, 0, 204));
				roundrect(1170, 405, 1290, 510, 60, 60);
				bttn = 2;
			}
			else if (bttn == 1)
			{
				setcolor(RGB(255, 215, 0));
				roundrect(910, 400, 1050, 520, 60, 60);
				bttn = 0;
			}
			else if (bttn == 2)
			{
				setcolor(RGB(200, 191, 231));
				roundrect(1170, 405, 1290, 510, 60, 60);
				bttn = 0;
			}
			m = GetMouseMsg();
			if (m.uMsg == WM_LBUTTONUP)
			{
				if (m.x > 910 && m.x < 1050 && m.y>400 && m.y < 520)
				{
					info = 1;
					break;
				}
				else if (m.x > 1170 && m.x < 1290 && m.y>405 && m.y < 515)
				{
					info = -1;
					break;
				}
			}
		}
		if (info == -1)
		{
			closegraph();
			return 0;
		}
		srand((unsigned)time(NULL));
		loop: initialize();
		begin();
		qingsuan();
		loadimage(&img, _T("����1.png"), 1425, 675);
		putimage(0, 0, &img);

		setcolor(RGB(255, 165, 0));
		fillroundrect(1095, 75, 1380, 180, 60, 60);
		setfillcolor(RGB(255, 165, 0));
		floodfill(1260, 90, RGB(255, 165, 0), 0);

		setbkmode(TRANSPARENT);
		settextcolor(RGB(0, 191, 255));
		gettextstyle(&f);
		f.lfHeight = 75;
		wcscpy_s(f.lfFaceName, _T("Ink Free"));
		f.lfItalic = 1;
		f.lfWeight = 1500;
		f.lfQuality = ANTIALIASED_QUALITY;
		settextstyle(&f);
		outtextxy(1147.5, 90, _T("Go on!"));

		setcolor(RGB(128, 128, 0));
		fillroundrect(1260, 225, 1380, 285, 37.5, 37.5);
		setfillcolor(RGB(128, 128, 0));
		floodfill(1275, 255, RGB(128, 128, 0), 0);

		setbkmode(TRANSPARENT);
		settextcolor(RGB(255, 255, 255));
		gettextstyle(&f1);
		f1.lfHeight = 42;
		wcscpy_s(f1.lfFaceName, _T("Arial Black"));
		f1.lfItalic = 0;
		f1.lfWeight = 750;
		f1.lfQuality = ANTIALIASED_QUALITY;
		settextstyle(&f1);
		outtextxy(1279.5, 232.5, _T("Back"));
		while (true)
		{
			m = GetMouseMsg();
			if (m.x > 1095 && m.x < 1380 && m.y>75 && m.y < 180)
			{
				setcolor(RGB(51, 102, 127));
				roundrect(1101, 81, 1374, 174, 45, 45);
				bttn = 1;
			}
			else if (m.x > 1260 && m.x < 1380 && m.y>225 && m.y < 285)
			{
				setcolor(RGB(0, 127, 0));
				roundrect(1264.5, 229.5, 1375.5, 280.5, 27, 27);
				bttn = 2;
			}
			else if (bttn == 1)
			{
				setcolor(RGB(255, 165, 0));
				fillroundrect(1095, 75, 1380, 180, 60, 60);
				setfillcolor(RGB(255, 165, 0));
				floodfill(1260, 90, RGB(255, 165, 0), 0);

				setbkmode(TRANSPARENT);
				settextcolor(RGB(0, 191, 255));
				gettextstyle(&f);
				f.lfHeight = 75;
				wcscpy_s(f.lfFaceName, _T("Ink Free"));
				f.lfItalic = 1;
				f.lfWeight = 1500;
				f.lfQuality = ANTIALIASED_QUALITY;
				settextstyle(&f);
				outtextxy(1147.5, 90, _T("Go on!"));
				bttn = 0;
			}
			else if (bttn == 2)
			{
				setfillcolor(RGB(128, 128, 0));
				clearroundrect(1260, 225, 1380, 285, 37.5, 37.5);
				setcolor(RGB(128, 128, 0));
				fillroundrect(1260, 225, 1380, 285, 37.5, 37.5);

				setbkmode(TRANSPARENT);
				settextcolor(RGB(255, 255, 255));
				gettextstyle(&f1);
				f1.lfHeight = 42;
				wcscpy_s(f1.lfFaceName, _T("Arial Black"));
				f1.lfItalic = 0;
				f1.lfWeight = 750;
				f1.lfQuality = ANTIALIASED_QUALITY;
				settextstyle(&f1);
				outtextxy(1279.5, 235, _T("Back"));
				bttn = 0;
			}
			m = GetMouseMsg();
			if (m.uMsg == WM_LBUTTONUP)
			{
				if (m.x > 1095 && m.x < 1380 && m.y>75 && m.y < 180)
				{
					changshu++;
					goto loop;
					break;
				}
				else if (m.x > 1260 && m.x < 1380 && m.y>225 && m.y < 285)
				{
					info1 = -1;
					changshu = 1;
					leijipoint = 25000;
					break;
				}
			}
		}
	}
	return 0;
}