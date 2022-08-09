// 我确认本程序完全由本小组成员独立完成
// 姓名：刘益枫、张焯扬、庞常毓、李子麒、仲柯源
// 学号：2020010909、2020010888、2020012561、2020012577、2020012567
// 时间：2021年5月30日 

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


char pai[136][6] = { "1万 ","1万 ","1万 ","1万 ","2万 ","2万 ","2万 ","2万 ","3万 ","3万 ","3万 ","3万 ","4万 ","4万 ","4万 ","4万 ",
"5万 ","5万 ","5万 ","五万","6万 ","6万 ","6万 ","6万 ","7万 ","7万 ","7万 ","7万 ","8万 ","8万 ","8万 ","8万 ","9万 ","9万 ","9万 ","9万 ",
"1条 ","1条 ","1条 ","1条 ","2条 ","2条 ","2条 ","2条 ","3条 ","3条 ","3条 ","3条 ","4条 ","4条 ","4条 ","4条 ","5条 ","5条 ","5条 ","五条",
"6条 ","6条 ","6条 ","6条 ","7条 ","7条 ","7条 ","7条 ","8条 ","8条 ","8条 ","8条 ","9条 ","9条 ","9条 ","9条 ",
"1筒 ","1筒 ","1筒 ","1筒 ","2筒 ","2筒 ","2筒 ","2筒 ","3筒 ","3筒 ","3筒 ","3筒 ","4筒 ","4筒 ","4筒 ","4筒 ","5筒 ","5筒 ","五筒","五筒",
"6筒 ","6筒 ","6筒 ","6筒 ","7筒 ","7筒 ","7筒 ","7筒 ","8筒 ","8筒 ","8筒 ","8筒 ","9筒 ","9筒 ","9筒 ","9筒 ",
"東風","東風","東風","東風","南風","南風","南風","南風","西風","西風","西風","西風","北風","北風","北風","北風",
"紅中","紅中","紅中","紅中","白板","白板","白板","白板","發財","發財","發財","發財" };
TCHAR yizhong[52][32] = { _T("立直		一番"),_T("断幺九		一番"),_T("门前清自摸和	一番"),_T("平和		一番"),_T("一杯口		一番"),
_T("抢杠		一番"),_T("岭上开花	一番"),_T("海底摸月	一番"),_T("河底捞鱼	一番"),_T("一发		一番"),
_T("两立直		两番"),_T("三色同刻	两番"),_T("三杠子		两番"),_T("对对和		两番"),_T("三暗刻		两番"),
_T("小三元		两番"),_T("混老头		两番"),_T("七对子		两番"),_T("混全带幺九	两番"),_T("一气通贯	两番"),
_T("三色同顺	两番"),_T("二杯口		三番"),_T("纯全带幺九	三番"),_T("混一色		三番"),_T("清一色		六番"),
_T("流局满贯"),_T("天和		役满"),_T("地和		役满"),_T("大三元		役满"),_T("四暗刻		役满"),
_T("字一色		役满"),_T("绿一色		役满"),_T("清老头		役满"),_T("国士无双	役满"),_T("小四喜		役满"),
_T("四杠子		役满"),_T("九莲宝灯	役满"),_T("四暗刻单骑	双倍役满"),_T("纯正九莲宝灯	双倍役满"),_T("大四喜		双倍役满"),
_T("国士无双十三面听	双倍役满"),_T("役牌：中	一番"),_T("役牌：白	一番"),_T("役牌：发	一番"),_T("场风牌：东	一番"),
_T("场风牌：南	一番"),_T("场风牌：西	一番"),_T("场风牌：北	一番"),_T("自风牌：东	一番"),_T("自风牌：南	一番"),
_T("自风牌：西	一番"),_T("自风牌：北	一番") };
int guoshiwushuang[13] = { 0, 32, 36, 68, 72, 104, 108, 112, 116, 120, 124, 128, 132 };//幺九牌

int prior_value[14] = { 0 };//AI判定权重值
int order[136] = { 0 };//牌堆
int shoupai[5][14] = { 0 };//手牌（shoupai【4】用于检查胡牌类型）
int cking[34] = { 0 };//34=136/4，检查胡牌时各种牌数量
int ifyouyi[52] = { 0 };//临时检查是否有役
int alyi[52] = { 0 };//根据点数大小最终判定役种
int xxx[4] = { 0 };//刻子起始牌号（0~33）
int xyz[4] = { 0 };//刻子起始牌号（0~33）
int state[5] = { 0 };//判定能否吃碰杠和立直
int lichi[5] = { 0 };//立直指示
int wlichi[5] = { 0 };//w立直指示
int chistate[4][5][3] = { 0 };//吃牌【人】【序号（0为吃牌数量）】【各吃牌牌号（0~135）】
int peng[4][5] = { 0 };//碰牌：【人】【0】为碰的数量，【人】【n】为碰的牌号（0~132，4的倍数）
int pengstate[4][5] = { 0 };//碰牌：【人】【n】为碰牌的状态：0为无红宝牌，1or2为一张或两张红宝牌
int gang[4][9] = { 0 };//杠牌：【人】【0】碰牌数量，【人】【n】(1~4)为杠牌牌号（0~132，4的倍数），【人】【n】（5~8）为杠的状态：1暗杠2明杠3加杠
int dragon[5] = { 0 };//实际宝牌
int dratishi[5] = { 0 };//宝牌提示牌
int lidra[5] = { 0 };//里宝牌
int qipaidui[4][40] = { 0 };//各人弃牌堆，【人】【0】为弃牌堆数量
int chitemp[3] = { 0 };//吃牌临时变量
int feng1[4] = { 0 };//四家各自的风向
int menqianqing[4] = { 1, 1, 1, 1 };//门前清1
int valsp[5] = { 13, 13, 13, 13, 13 };//非当前回合手牌允许量
TCHAR manguanlv[11][13] = { _T(" "),_T("满贯"),_T("跳满"),_T("倍满"),_T("三倍满"),_T("累计役满"),
_T("两倍役满"),_T("三倍役满"),_T("四倍役满"),_T("五倍役满"),_T("六倍役满") };//满贯类型

int zhuang, active, now, ck, wholestate, nowpai, drastate, gangnum = 0, changshu;
//zhuang=庄家，active=当前牌对应的数，now=当前玩家，ck=checking中的玩家，wholestate=赢家（-1流局），nowpai=现在摸的是第几张牌，drastate=明宝牌数量
int i, j, k, r, m, temp, temp1, temphu, temphu1, tempck;//临时变量
int gangr, gangpai, pengr, pengpai, hur, ifzimo, rongnum, zigangr, lichir, jiagangr;
//gangr、gangpai、pengr、pengpai、zigangr、jiagangr（手牌中第几个可以加杠）杠、碰、暗杠、加杠临时变量，
//hur和lichir表明是否能胡牌和立直，ifzimo表明是否自摸，rongnum放铳临时变量
int zimor, guoshiwushuangr, qiduizir, chir, dranum, lidranum, pengtemp, jiagangr1, jiagangr2;
//zimor、guoshiwushuangr、qiduizir自摸、国士无双、七对子与否、chir吃牌临时变量、dranum、lidranum宝牌里宝牌、pengtemp碰牌临时变量
//jiagangr1（加杠牌为第几个碰牌），jiagangr2加杠牌（4倍数）
int hutype, aaa = 0, abc = 0, q, get, fu, fu1, fan, fan1, point, point1, yiman, dian, danqi, ganghou, yixun, yifa, focus;
//focus：当前所摸牌的序号（0~valsp），yifa=立直后一发，yixun判断天和地和，ganghou判断岭上开花，yiman、dian、point、point1、fan、fan1、fu、fu1计算点数
//get目前牌对应的数（0~33）、q雀头，abc、aaa判定刻子和顺子、hutype胡牌类型
int chizuo, chiyou, chika, strategycheckif, currenting = 0, froming, leijipoint;
//chizuo、chiyou、chika均为判断吃牌的临时变量、currenting为GUI有关变量、froming为判断牌来自的变量、leijipoint为累计点数
char c;
//temp:判定能否操作变量 ；temp1：碰杠吃判定及完成变量； 

void rtrn()//*返回开始界面 
{
	if (wholestate < 0)
	{
		slp(3000);
		return;
	}
	int i;
	IMAGE img;
	loadimage(&img, _T("桌面1.png"), 1425, 675);
	putimage(0, 0, &img);
	LOGFONT f;
	gettextstyle(&f);
	setbkmode(TRANSPARENT);
	f.lfHeight = 40;
	settextcolor(RGB(255, 255, 255));
	wcscpy_s(f.lfFaceName, _T("华文行楷"));
	settextstyle(&f);
	if (wholestate == 0)
	{
		outtextxy(45, 80, _T("你赢了！"));
	}
	if (wholestate == 1)
	{
		outtextxy(45, 80, _T("下家赢了！"));
	}
	if (wholestate == 2)
	{
		outtextxy(45, 80, _T("对家赢了！"));
	}
	if (wholestate == 3)
	{
		outtextxy(45, 80, _T("上家赢了！"));
	}
	outtextxy(45, 140, _T("赢家牌型："));
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



void initialize()//*初始化
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
	wcscpy_s(f.lfFaceName, _T("华文行楷"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	settextcolor(RGB(163, 73, 164));
	TCHAR changnum[2];
	_stprintf_s(changnum, _T("%d"), changshu);
	outtextxy(640, 530, changnum);
	outtextxy(700, 530, _T("本场"));
	slp(5000);
	IMAGE img;
	loadimage(&img, _T("桌面1.png"), 1425, 675);
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
		outtextxy(440, 420, _T("您的场风为:東風"));
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
		outtextxy(440, 420, _T("您的场风为:北風"));
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
		outtextxy(440, 420, _T("您的场风为:西風"));
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
		outtextxy(440, 420, _T("您的场风为:南風"));
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



void begin()//*轮转 
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

void qingsuan()//!*终局清算 
{
	int i, j, k, temp4, reddranum = 0;
	rtrn();
	TCHAR pnts2[7];
	TCHAR hjds2[] = _T("累计点数：");
	LOGFONT f;
	gettextstyle(&f);
	f.lfItalic = 0;
	setbkmode(TRANSPARENT);
	settextcolor(RGB(255, 255, 255));
	wcscpy_s(f.lfFaceName, _T("华文行楷"));
	f.lfQuality = ANTIALIASED_QUALITY;
	if (wholestate == -1)
	{
		HWND hwnd = GetHWnd();
		SetWindowText(hwnd, _T("Nihon Mahjong"));
		clearrectangle(0, 0, 1425, 675);
		IMAGE img;
		loadimage(&img, _T("桌面1.png"), 1425, 675);
		putimage(0, 0, &img);
		f.lfHeight = 225;
		settextstyle(&f);
		TCHAR draprint[] = _T("流  局");
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
		loadimage(&img, _T("桌面1.png"), 1425, 675);
		putimage(0, 0, &img);
		gettextstyle(&f);
		setbkmode(TRANSPARENT);
		f.lfHeight = 40;
		settextcolor(RGB(255, 255, 255));
		wcscpy_s(f.lfFaceName, _T("华文行楷"));
		settextstyle(&f);
		if (wholestate == 0)
		{
			outtextxy(45, 80, _T("你赢了！"));
		}
		if (wholestate == 1)
		{
			outtextxy(45, 80, _T("下家赢了！"));
		}
		if (wholestate == 2)
		{
			outtextxy(45, 80, _T("对家赢了！"));
		}
		if (wholestate == 3)
		{
			outtextxy(45, 80, _T("上家赢了！"));
		}
		LOGFONT f;
		gettextstyle(&f);
		f.lfHeight = 37.5;
		f.lfItalic = 0;
		wcscpy_s(f.lfFaceName, _T("华文行楷"));
		f.lfQuality = ANTIALIASED_QUALITY;
		settextstyle(&f);
		TCHAR draprint[] = _T("宝牌："), lidraprint[] = _T("里宝牌："), reddraprint[] = _T("赤宝牌：");
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
		TCHAR hjds[] = _T("合计点数：");
		if (temp4 > 0)
		{
			f.lfHeight = 60;
			outtextxy(150, 570, manguanlv[temp4]);
		}
		else
		{
			f.lfHeight = 67.5;
			TCHAR fuprint[] = _T("符"), fanprint[] = _T("番");
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
	PlaySound(_T(".\\ww\\一路花香一路唱2.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
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
		wcscpy_s(f2.lfFaceName, _T("华文等线"));

		setbkmode(TRANSPARENT);
		settextcolor(WHITE);
		gettextstyle(&f2);
		f2.lfHeight = 18;
		wcscpy_s(f2.lfFaceName, _T("华文等线"));
		f2.lfItalic = 0;
		f2.lfWeight = 1500;
		f2.lfQuality = ANTIALIASED_QUALITY;
		settextstyle(&f2);
		outtextxy(1230, 615, _T("ver3.0.1(beta)"));
		outtextxy(1230, 637.5, _T("美观、大气、和谐"));

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
		loadimage(&img, _T("桌面1.png"), 1425, 675);
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