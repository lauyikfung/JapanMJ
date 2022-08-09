#include<stdio.h>
#include<stdlib.h>
#include <graphics.h>
#include <conio.h>
extern int pai[136][6], dragon[5],lichi[5],wlichi[5];
extern int drastate, zhuang, changshu, dratishi[5];
void anniu(int number, int i)
{
	IMAGE s;
	switch (number)
	{
	case(1):
	{
		loadimage(&s, _T(".\\anniu\\1.png"), 60, 48);
		putimage(288 + i * 100, 480, &s);
		break;
	}
	case(2):
	{
		loadimage(&s, _T(".\\anniu\\2.png"), 60, 48);
		putimage(288 + i * 100, 480, &s);
		break;
	}
	case(3):
	{
		loadimage(&s, _T(".\\anniu\\3.png"), 60, 48);
		putimage(288 + i * 100, 480, &s);
		break;
	}
	case(4):
	{
		loadimage(&s, _T(".\\anniu\\4.png"), 60, 48);
		putimage(288 + i * 100, 480, &s);
		break;
	}
	case(5):
	{
		loadimage(&s, _T(".\\anniu\\5.png"), 100, 48);
		putimage(288 + i * 100, 480, &s);
		break;
	}
	case(6):
	{
		loadimage(&s, _T(".\\anniu\\6.png"), 100, 48);
		putimage(288 + i * 100, 480, &s);
		break;
	}
	case(0):
	{
		loadimage(&s, _T(".\\anniu\\0.png"), 100, 48);
		putimage(288 + i * 100, 480, &s);
		break;
	}
	}

}
void daoxiamajiangpai(int number_pai, int who, int number, int x, int y)
{
	number_pai++;
	IMAGE s;
	if (who == 0)
	{
		if (number_pai == 1 || number_pai == 2 || number_pai == 3 || number_pai == 4)
		{
			loadimage(&s, _T(".\\s倒\\sd01.png"), 36, 43);
			putimage(x + 36 * number, y, &s);
		}
		if (number_pai == 5 || number_pai == 6 || number_pai == 7 || number_pai == 8)
		{
			loadimage(&s, _T(".\\s倒\\sd02.png"), 36, 43);
			putimage(x + 36 * number, y, &s);
		}
		if (number_pai == 9 || number_pai == 10 || number_pai == 11 || number_pai == 12)
		{
			loadimage(&s, _T(".\\s倒\\sd03.png"), 36, 43);
			putimage(x + 36 * number, y, &s);
		}
		if (number_pai == 13 || number_pai == 14 || number_pai == 15 || number_pai == 16)
		{
			loadimage(&s, _T(".\\s倒\\sd04.png"), 36, 43);
			putimage(x + 36 * number, y, &s);
		}
		if (number_pai == 17 || number_pai == 18 || number_pai == 19)
		{
			loadimage(&s, _T(".\\s倒\\sd05.png"), 36, 43);
			putimage(x + 36 * number, y, &s);
		}
		if (number_pai == 20)
		{
			loadimage(&s, _T(".\\s倒\\sd05b.png"), 36, 43);
			putimage(x + 36 * number, y, &s);
		}
		if (number_pai == 21 || number_pai == 22 || number_pai == 23 || number_pai == 24)
		{
			loadimage(&s, _T(".\\s倒\\sd06.png"), 36, 43);
			putimage(x + 36 * number, y, &s);
		}
		if (number_pai == 25 || number_pai == 26 || number_pai == 27 || number_pai == 28)
		{
			loadimage(&s, _T(".\\s倒\\sd07.png"), 36, 43);
			putimage(x + 36 * number, y, &s);
		}
		if (number_pai == 29 || number_pai == 30 || number_pai == 31 || number_pai == 32)
		{
			loadimage(&s, _T(".\\s倒\\sd08.png"), 36, 43);
			putimage(x + 36 * number, y, &s);
		}
		if (number_pai == 33 || number_pai == 34 || number_pai == 35 || number_pai == 36)
		{
			loadimage(&s, _T(".\\s倒\\sd09.png"), 36, 43);
			putimage(x + 36 * number, y, &s);
		}
		if (number_pai == 37 || number_pai == 38 || number_pai == 39 || number_pai == 40)
		{
			loadimage(&s, _T(".\\s倒\\sd11.png"), 36, 43);
			putimage(x + 36 * number, y, &s);
		}
		if (number_pai == 41 || number_pai == 42 || number_pai == 43 || number_pai == 44)
		{
			loadimage(&s, _T(".\\s倒\\sd12.png"), 36, 43);
			putimage(x + 36 * number, y, &s);
		}
		if (number_pai == 45 || number_pai == 46 || number_pai == 47 || number_pai == 48)
		{
			loadimage(&s, _T(".\\s倒\\sd13.png"), 36, 43);
			putimage(x + 36 * number, y, &s);
		}
		if (number_pai == 49 || number_pai == 50 || number_pai == 51 || number_pai == 52)
		{
			loadimage(&s, _T(".\\s倒\\sd14.png"), 36, 43);
			putimage(x + 36 * number, y, &s);
		}
		if (number_pai == 53 || number_pai == 54 || number_pai == 55)
		{
			loadimage(&s, _T(".\\s倒\\sd15.png"), 36, 43);
			putimage(x + 36 * number, y, &s);
		}
		if (number_pai == 56)
		{
			loadimage(&s, _T(".\\s倒\\sd15b.png"), 36, 43);
			putimage(x + 36 * number, y, &s);
		}
		if (number_pai == 57 || number_pai == 58 || number_pai == 59 || number_pai == 60)
		{
			loadimage(&s, _T(".\\s倒\\sd16.png"), 36, 43);
			putimage(x + 36 * number, y, &s);
		}
		if (number_pai == 61 || number_pai == 62 || number_pai == 63 || number_pai == 64)
		{
			loadimage(&s, _T(".\\s倒\\sd17.png"), 36, 43);
			putimage(x + 36 * number, y, &s);
		}
		if (number_pai == 65 || number_pai == 66 || number_pai == 67 || number_pai == 68)
		{
			loadimage(&s, _T(".\\s倒\\sd18.png"), 36, 43);
			putimage(x + 36 * number, y, &s);
		}
		if (number_pai == 69 || number_pai == 70 || number_pai == 71 || number_pai == 72)
		{
			loadimage(&s, _T(".\\s倒\\sd19.png"), 36, 43);
			putimage(x + 36 * number, y, &s);
		}
		if (number_pai == 73 || number_pai == 74 || number_pai == 75 || number_pai == 76)
		{
			loadimage(&s, _T(".\\s倒\\sd21.png"), 36, 43);
			putimage(x + 36 * number, y, &s);
		}
		if (number_pai == 77 || number_pai == 78 || number_pai == 79 || number_pai == 80)
		{
			loadimage(&s, _T(".\\s倒\\sd22.png"), 36, 43);
			putimage(x + 36 * number, y, &s);
		}
		if (number_pai == 81 || number_pai == 82 || number_pai == 83 || number_pai == 84)
		{
			loadimage(&s, _T(".\\s倒\\sd23.png"), 36, 43);
			putimage(x + 36 * number, y, &s);
		}
		if (number_pai == 85 || number_pai == 86 || number_pai == 87 || number_pai == 88)
		{
			loadimage(&s, _T(".\\s倒\\sd24.png"), 36, 43);
			putimage(x + 36 * number, y, &s);
		}
		if (number_pai == 89 || number_pai == 90)
		{
			loadimage(&s, _T(".\\s倒\\sd25.png"), 36, 43);
			putimage(x + 36 * number, y, &s);
		}
		if (number_pai == 91 || number_pai == 92)
		{
			loadimage(&s, _T(".\\s倒\\sd25b.png"), 36, 43);
			putimage(x + 36 * number, y, &s);
		}
		if (number_pai == 93 || number_pai == 94 || number_pai == 95 || number_pai == 96)
		{
			loadimage(&s, _T(".\\s倒\\sd26.png"), 36, 43);
			putimage(x + 36 * number, y, &s);
		}
		if (number_pai == 97 || number_pai == 98 || number_pai == 99 || number_pai == 100)
		{
			loadimage(&s, _T(".\\s倒\\sd27.png"), 36, 43);
			putimage(x + 36 * number, y, &s);
		}
		if (number_pai == 101 || number_pai == 102 || number_pai == 103 || number_pai == 104)
		{
			loadimage(&s, _T(".\\s倒\\sd28.png"), 36, 43);
			putimage(x + 36 * number, y, &s);
		}
		if (number_pai == 105 || number_pai == 106 || number_pai == 107 || number_pai == 108)
		{
			loadimage(&s, _T(".\\s倒\\sd29.png"), 36, 43);
			putimage(x + 36 * number, y, &s);
		}
		if (number_pai == 109 || number_pai == 110 || number_pai == 111 || number_pai == 112)
		{
			loadimage(&s, _T(".\\s倒\\sd 东.png"), 36, 43);
			putimage(x + 36 * number, y, &s);
		}
		if (number_pai == 113 || number_pai == 114 || number_pai == 115 || number_pai == 116)
		{
			loadimage(&s, _T(".\\s倒\\sd 南.png"), 36, 43);
			putimage(x + 36 * number, y, &s);
		}
		if (number_pai == 117 || number_pai == 118 || number_pai == 119 || number_pai == 120)
		{
			loadimage(&s, _T(".\\s倒\\sd 西.png"), 36, 43);
			putimage(x + 36 * number, y, &s);
		}
		if (number_pai == 121 || number_pai == 122 || number_pai == 123 || number_pai == 124)
		{
			loadimage(&s, _T(".\\s倒\\sd 北.png"), 36, 43);
			putimage(x + 36 * number, y, &s);
		}
		if (number_pai == 125 || number_pai == 126 || number_pai == 127 || number_pai == 128)
		{
			loadimage(&s, _T(".\\s倒\\sd 中.png"), 36, 43);
			putimage(x + 36 * number, y, &s);
		}
		if (number_pai == 129 || number_pai == 130 || number_pai == 131 || number_pai == 132)
		{
			loadimage(&s, _T(".\\s倒\\sd 白板.png"), 36, 43);
			putimage(x + 36 * number, y, &s);
		}
		if (number_pai == 133 || number_pai == 134 || number_pai == 135 || number_pai == 136)
		{
			loadimage(&s, _T(".\\s倒\\sd 发.png"), 36, 43);
			putimage(x + 36 * number, y, &s);
		}
		if (number_pai == 137)
		{
			loadimage(&s, _T(".\\s倒\\sd 后.png"), 36, 43);
			putimage(x + 36 * number, y, &s);
		}
	}
	else if (who == 1)
	{
	if (number_pai == 1 || number_pai == 2 || number_pai == 3 || number_pai == 4)
	{
		loadimage(&s, _T(".\\d\\d01.png"), 43,36);
		putimage(x, y - 36 * number, &s);
	}
	if (number_pai == 5 || number_pai == 6 || number_pai == 7 || number_pai == 8)
	{
		loadimage(&s, _T(".\\d\\d02.png"), 43,36);
		putimage(x, y - 36 * number, &s);
	}
	if (number_pai == 9 || number_pai == 10 || number_pai == 11 || number_pai == 12)
	{
		loadimage(&s, _T(".\\d\\d03.png"), 43,36);
		putimage(x, y - 36 * number, &s);
	}
	if (number_pai == 13 || number_pai == 14 || number_pai == 15 || number_pai == 16)
	{
		loadimage(&s, _T(".\\d\\d04.png"), 43,36);
		putimage(x, y - 36 * number, &s);
	}
	if (number_pai == 17 || number_pai == 18 || number_pai == 19)
	{
		loadimage(&s, _T(".\\d\\d05.png"), 43,36);
		putimage(x, y - 36 * number, &s);
	}
	if (number_pai == 20)
	{
		loadimage(&s, _T(".\\d\\d05b.png"), 43,36);
		putimage(x, y - 36 * number, &s);
	}
	if (number_pai == 21 || number_pai == 22 || number_pai == 23 || number_pai == 24)
	{
		loadimage(&s, _T(".\\d\\d06.png"), 43,36);
		putimage(x, y - 36 * number, &s);
	}
	if (number_pai == 25 || number_pai == 26 || number_pai == 27 || number_pai == 28)
	{
		loadimage(&s, _T(".\\d\\d07.png"), 43,36);
		putimage(x, y - 36 * number, &s);
	}
	if (number_pai == 29 || number_pai == 30 || number_pai == 31 || number_pai == 32)
	{
		loadimage(&s, _T(".\\d\\d08.png"), 43,36);
		putimage(x, y - 36 * number, &s);
	}
	if (number_pai == 33 || number_pai == 34 || number_pai == 35 || number_pai == 36)
	{
		loadimage(&s, _T(".\\d\\d09.png"), 43,36);
		putimage(x, y - 36 * number, &s);
	}
	if (number_pai == 37 || number_pai == 38 || number_pai == 39 || number_pai == 40)
	{
		loadimage(&s, _T(".\\d\\d11.png"), 43,36);
		putimage(x, y - 36 * number, &s);
	}
	if (number_pai == 41 || number_pai == 42 || number_pai == 43 || number_pai == 44)
	{
		loadimage(&s, _T(".\\d\\d12.png"), 43,36);
		putimage(x, y - 36 * number, &s);
	}
	if (number_pai == 45 || number_pai == 46 || number_pai == 47 || number_pai == 48)
	{
		loadimage(&s, _T(".\\d\\d13.png"), 43,36);
		putimage(x, y - 36 * number, &s);
	}
	if (number_pai == 49 || number_pai == 50 || number_pai == 51 || number_pai == 52)
	{
		loadimage(&s, _T(".\\d\\d14.png"), 43,36);
		putimage(x, y - 36 * number, &s);
	}
	if (number_pai == 53 || number_pai == 54 || number_pai == 55)
	{
		loadimage(&s, _T(".\\d\\d15.png"), 43,36);
		putimage(x, y - 36 * number, &s);
	}
	if (number_pai == 56)
	{
		loadimage(&s, _T(".\\d\\d15b.png"), 43,36);
		putimage(x, y - 36 * number, &s);
	}
	if (number_pai == 57 || number_pai == 58 || number_pai == 59 || number_pai == 60)
	{
		loadimage(&s, _T(".\\d\\d16.png"), 43,36);
		putimage(x, y - 36 * number, &s);
	}
	if (number_pai == 61 || number_pai == 62 || number_pai == 63 || number_pai == 64)
	{
		loadimage(&s, _T(".\\d\\d17.png"), 43,36);
		putimage(x, y - 36 * number, &s);
	}
	if (number_pai == 65 || number_pai == 66 || number_pai == 67 || number_pai == 68)
	{
		loadimage(&s, _T(".\\d\\d18.png"), 43,36);
		putimage(x, y - 36 * number, &s);
	}
	if (number_pai == 69 || number_pai == 70 || number_pai == 71 || number_pai == 72)
	{
		loadimage(&s, _T(".\\d\\d19.png"), 43,36);
		putimage(x, y - 36 * number, &s);
	}
	if (number_pai == 73 || number_pai == 74 || number_pai == 75 || number_pai == 76)
	{
		loadimage(&s, _T(".\\d\\d21.png"), 43,36);
		putimage(x, y - 36 * number, &s);
	}
	if (number_pai == 77 || number_pai == 78 || number_pai == 79 || number_pai == 80)
	{
		loadimage(&s, _T(".\\d\\d22.png"), 43,36);
		putimage(x, y - 36 * number, &s);
	}
	if (number_pai == 81 || number_pai == 82 || number_pai == 83 || number_pai == 84)
	{
		loadimage(&s, _T(".\\d\\d23.png"), 43,36);
		putimage(x, y - 36 * number, &s);
	}
	if (number_pai == 85 || number_pai == 86 || number_pai == 87 || number_pai == 88)
	{
		loadimage(&s, _T(".\\d\\d24.png"), 43,36);
		putimage(x, y - 36 * number, &s);
	}
	if (number_pai == 89 || number_pai == 90)
	{
		loadimage(&s, _T(".\\d\\d25.png"), 43,36);
		putimage(x, y - 36 * number, &s);
	}
	if (number_pai == 91 || number_pai == 92)
	{
		loadimage(&s, _T(".\\d\\d25b.png"), 43,36);
		putimage(x, y - 36 * number, &s);
	}
	if (number_pai == 93 || number_pai == 94 || number_pai == 95 || number_pai == 96)
	{
		loadimage(&s, _T(".\\d\\d26.png"), 43,36);
		putimage(x, y - 36 * number, &s);
	}
	if (number_pai == 97 || number_pai == 98 || number_pai == 99 || number_pai == 100)
	{
		loadimage(&s, _T(".\\d\\d27.png"), 43,36);
		putimage(x, y - 36 * number, &s);
	}
	if (number_pai == 101 || number_pai == 102 || number_pai == 103 || number_pai == 104)
	{
		loadimage(&s, _T(".\\d\\d28.png"), 43,36);
		putimage(x, y - 36 * number, &s);
	}
	if (number_pai == 105 || number_pai == 106 || number_pai == 107 || number_pai == 108)
	{
		loadimage(&s, _T(".\\d\\d29.png"), 43,36);
		putimage(x, y - 36 * number, &s);
	}
	if (number_pai == 109 || number_pai == 110 || number_pai == 111 || number_pai == 112)
	{
		loadimage(&s, _T(".\\d\\d 东.png"), 43,36);
		putimage(x, y - 36 * number, &s);
	}
	if (number_pai == 113 || number_pai == 114 || number_pai == 115 || number_pai == 116)
	{
		loadimage(&s, _T(".\\d\\d 南.png"), 43,36);
		putimage(x, y - 36 * number, &s);
	}
	if (number_pai == 117 || number_pai == 118 || number_pai == 119 || number_pai == 120)
	{
		loadimage(&s, _T(".\\d\\d 西.png"), 43,36);
		putimage(x, y - 36 * number, &s);
	}
	if (number_pai == 121 || number_pai == 122 || number_pai == 123 || number_pai == 124)
	{
		loadimage(&s, _T(".\\d\\d 北.png"), 43,36);
		putimage(x, y - 36 * number, &s);
	}
	if (number_pai == 125 || number_pai == 126 || number_pai == 127 || number_pai == 128)
	{
		loadimage(&s, _T(".\\d\\d 中.png"), 43,36);
		putimage(x, y - 36 * number, &s);
	}
	if (number_pai == 129 || number_pai == 130 || number_pai == 131 || number_pai == 132)
	{
		loadimage(&s, _T(".\\d\\d 白板.png"), 43,36);
		putimage(x, y - 36 * number, &s);
	}
	if (number_pai == 133 || number_pai == 134 || number_pai == 135 || number_pai == 136)
	{
		loadimage(&s, _T(".\\d\\d 发.png"), 43,36);
		putimage(x, y - 36 * number, &s);
	}
	if (number_pai == 137)
	{
		loadimage(&s, _T(".\\d\\d 后.png"), 43,36);
		putimage(x, y - 36 * number, &s);
	}
	}
	else if (who == 2)
	{
	if (number_pai == 1 || number_pai == 2 || number_pai == 3 || number_pai == 4)
	{
		loadimage(&s, _T(".\\w\\w01.png"), 36,43);
		putimage(x - 36 * number, y, &s);
	}
	if (number_pai == 5 || number_pai == 6 || number_pai == 7 || number_pai == 8)
	{
		loadimage(&s, _T(".\\w\\w02.png"), 36,43);
		putimage(x - 36 * number, y, &s);
	}
	if (number_pai == 9 || number_pai == 10 || number_pai == 11 || number_pai == 12)
	{
		loadimage(&s, _T(".\\w\\w03.png"), 36,43);
		putimage(x - 36 * number, y, &s);
	}
	if (number_pai == 13 || number_pai == 14 || number_pai == 15 || number_pai == 16)
	{
		loadimage(&s, _T(".\\w\\w04.png"), 36,43);
		putimage(x - 36 * number, y, &s);
	}
	if (number_pai == 17 || number_pai == 18 || number_pai == 19)
	{
		loadimage(&s, _T(".\\w\\w05.png"), 36,43);
		putimage(x - 36 * number, y, &s);
	}
	if (number_pai == 20)
	{
		loadimage(&s, _T(".\\w\\w05b.png"), 36,43);
		putimage(x - 36 * number, y, &s);
	}
	if (number_pai == 21 || number_pai == 22 || number_pai == 23 || number_pai == 24)
	{
		loadimage(&s, _T(".\\w\\w06.png"), 36,43);
		putimage(x - 28* number, y, &s);
	}
	if (number_pai == 25 || number_pai == 26 || number_pai == 27 || number_pai == 28)
	{
		loadimage(&s, _T(".\\w\\w07.png"), 36,43);
		putimage(x - 36 * number, y, &s);
	}
	if (number_pai == 29 || number_pai == 30 || number_pai == 31 || number_pai == 32)
	{
		loadimage(&s, _T(".\\w\\w08.png"), 36,43);
		putimage(x - 36 * number, y, &s);
	}
	if (number_pai == 33 || number_pai == 34 || number_pai == 35 || number_pai == 36)
	{
		loadimage(&s, _T(".\\w\\w09.png"), 36,43);
		putimage(x - 36 * number, y, &s);
	}
	if (number_pai == 37 || number_pai == 38 || number_pai == 39 || number_pai == 40)
	{
		loadimage(&s, _T(".\\w\\w11.png"), 36,43);
		putimage(x - 36 * number, y, &s);
	}
	if (number_pai == 41 || number_pai == 42 || number_pai == 43 || number_pai == 44)
	{
		loadimage(&s, _T(".\\w\\w12.png"), 36,43);
		putimage(x - 36 * number, y, &s);
	}
	if (number_pai == 45 || number_pai == 46 || number_pai == 47 || number_pai == 48)
	{
		loadimage(&s, _T(".\\w\\w13.png"), 36,43);
		putimage(x - 36 * number, y, &s);
	}
	if (number_pai == 49 || number_pai == 50 || number_pai == 51 || number_pai == 52)
	{
		loadimage(&s, _T(".\\w\\w14.png"), 36,43);
		putimage(x - 36 * number, y, &s);
	}
	if (number_pai == 53 || number_pai == 54 || number_pai == 55)
	{
		loadimage(&s, _T(".\\w\\w15.png"), 36,43);
		putimage(x - 36 * number, y, &s);
	}
	if (number_pai == 56)
	{
		loadimage(&s, _T(".\\w\\w15b.png"), 36,43);
		putimage(x - 36 * number, y, &s);
	}
	if (number_pai == 57 || number_pai == 58 || number_pai == 59 || number_pai == 60)
	{
		loadimage(&s, _T(".\\w\\w16.png"), 36,43);
		putimage(x - 36 * number, y, &s);
	}
	if (number_pai == 61 || number_pai == 62 || number_pai == 63 || number_pai == 64)
	{
		loadimage(&s, _T(".\\w\\w17.png"), 36,43);
		putimage(x - 36 * number, y, &s);
	}
	if (number_pai == 65 || number_pai == 66 || number_pai == 67 || number_pai == 68)
	{
		loadimage(&s, _T(".\\w\\w18.png"), 36,43);
		putimage(x - 36 * number, y, &s);
	}
	if (number_pai == 69 || number_pai == 70 || number_pai == 71 || number_pai == 72)
	{
		loadimage(&s, _T(".\\w\\w19.png"), 36,43);
		putimage(x - 36 * number, y, &s);
	}
	if (number_pai == 73 || number_pai == 74 || number_pai == 75 || number_pai == 76)
	{
		loadimage(&s, _T(".\\w\\w21.png"), 36,43);
		putimage(x - 36 * number, y, &s);
	}
	if (number_pai == 77 || number_pai == 78 || number_pai == 79 || number_pai == 80)
	{
		loadimage(&s, _T(".\\w\\w22.png"), 36,43);
		putimage(x - 36 * number, y, &s);
	}
	if (number_pai == 81 || number_pai == 82 || number_pai == 83 || number_pai == 84)
	{
		loadimage(&s, _T(".\\w\\w23.png"), 36,43);
		putimage(x - 36 * number, y, &s);
	}
	if (number_pai == 85 || number_pai == 86 || number_pai == 87 || number_pai == 88)
	{
		loadimage(&s, _T(".\\w\\w24.png"), 36,43);
		putimage(x - 36 * number, y, &s);
	}
	if (number_pai == 89 || number_pai == 90)
	{
		loadimage(&s, _T(".\\w\\w25.png"), 36,43);
		putimage(x - 36 * number, y, &s);
	}
	if (number_pai == 91 || number_pai == 92)
	{
		loadimage(&s, _T(".\\w\\w25b.png"), 36,43);
		putimage(x - 36 * number, y, &s);
	}
	if (number_pai == 93 || number_pai == 94 || number_pai == 95 || number_pai == 96)
	{
		loadimage(&s, _T(".\\w\\w26.png"), 36,43);
		putimage(x - 36 * number, y, &s);
	}
	if (number_pai == 97 || number_pai == 98 || number_pai == 99 || number_pai == 100)
	{
		loadimage(&s, _T(".\\w\\w27.png"), 36,43);
		putimage(x - 36 * number, y, &s);
	}
	if (number_pai == 101 || number_pai == 102 || number_pai == 103 || number_pai == 104)
	{
		loadimage(&s, _T(".\\w\\w28.png"), 36,43);
		putimage(x - 36 * number, y, &s);
	}
	if (number_pai == 105 || number_pai == 106 || number_pai == 107 || number_pai == 108)
	{
		loadimage(&s, _T(".\\w\\w29.png"), 36,43);
		putimage(x - 36 * number, y, &s);
	}
	if (number_pai == 109 || number_pai == 110 || number_pai == 111 || number_pai == 112)
	{
		loadimage(&s, _T(".\\w\\w 东.png"), 36,43);
		putimage(x - 36 * number, y, &s);
	}
	if (number_pai == 113 || number_pai == 114 || number_pai == 115 || number_pai == 116)
	{
		loadimage(&s, _T(".\\w\\w 南.png"), 36,43);
		putimage(x - 36 * number, y, &s);
	}
	if (number_pai == 117 || number_pai == 118 || number_pai == 119 || number_pai == 120)
	{
		loadimage(&s, _T(".\\w\\w 西.png"), 36,43);
		putimage(x - 36 * number, y, &s);
	}
	if (number_pai == 121 || number_pai == 122 || number_pai == 123 || number_pai == 124)
	{
		loadimage(&s, _T(".\\w\\w 北.png"), 36,43);
		putimage(x - 36 * number, y, &s);
	}
	if (number_pai == 125 || number_pai == 126 || number_pai == 127 || number_pai == 128)
	{
		loadimage(&s, _T(".\\w\\w 中.png"), 36,43);
		putimage(x - 36 * number, y, &s);
	}
	if (number_pai == 129 || number_pai == 130 || number_pai == 131 || number_pai == 132)
	{
		loadimage(&s, _T(".\\w\\w 白板.png"), 36,43);
		putimage(x - 36 * number, y, &s);
	}
	if (number_pai == 133 || number_pai == 134 || number_pai == 135 || number_pai == 136)
	{
		loadimage(&s, _T(".\\w\\w 发.png"), 36,43);
		putimage(x - 36 * number, y, &s);
	}
	if (number_pai == 137)
	{
		loadimage(&s, _T(".\\w\\w 后.png"), 36,43);
		putimage(x - 36 * number, y, &s);
	}
	}
	else if (who == 3)
	{
	if (number_pai == 1 || number_pai == 2 || number_pai == 3 || number_pai == 4)
	{
		loadimage(&s, _T(".\\a\\a01.png"), 43, 36);
		putimage(x, y + 25 * number, &s);
	}
	if (number_pai == 5 || number_pai == 6 || number_pai == 7 || number_pai == 8)
	{
		loadimage(&s, _T(".\\a\\a02.png"), 43,36);
		putimage(x, y + 25 * number, &s);
	}
	if (number_pai == 9 || number_pai == 10 || number_pai == 11 || number_pai == 12)
	{
		loadimage(&s, _T(".\\a\\a03.png"), 43,36);
		putimage(x, y + 25 * number, &s);
	}
	if (number_pai == 13 || number_pai == 14 || number_pai == 15 || number_pai == 16)
	{
		loadimage(&s, _T(".\\a\\a04.png"), 43,36);
		putimage(x, y + 25 * number, &s);
	}
	if (number_pai == 17 || number_pai == 18 || number_pai == 19)
	{
		loadimage(&s, _T(".\\a\\a05.png"), 43,36);
		putimage(x, y + 25 * number, &s);
	}
	if (number_pai == 20)
	{
		loadimage(&s, _T(".\\a\\a05b.png"), 43,36);
		putimage(x, y + 25 * number, &s);
	}
	if (number_pai == 21 || number_pai == 22 || number_pai == 23 || number_pai == 24)
	{
		loadimage(&s, _T(".\\a\\a06.png"), 43,36);
		putimage(x, y + 25 * number, &s);
	}
	if (number_pai == 25 || number_pai == 26 || number_pai == 27 || number_pai == 28)
	{
		loadimage(&s, _T(".\\a\\a07.png"), 43,36);
		putimage(x, y + 25 * number, &s);
	}
	if (number_pai == 29 || number_pai == 30 || number_pai == 31 || number_pai == 32)
	{
		loadimage(&s, _T(".\\a\\a08.png"), 43,36);
		putimage(x, y + 25 * number, &s);
	}
	if (number_pai == 33 || number_pai == 34 || number_pai == 35 || number_pai == 36)
	{
		loadimage(&s, _T(".\\a\\a09.png"), 43,36);
		putimage(x, y + 25 * number, &s);
	}
	if (number_pai == 37 || number_pai == 38 || number_pai == 39 || number_pai == 40)
	{
		loadimage(&s, _T(".\\a\\a11.png"), 43,36);
		putimage(x, y + 25 * number, &s);
	}
	if (number_pai == 41 || number_pai == 42 || number_pai == 43 || number_pai == 44)
	{
		loadimage(&s, _T(".\\a\\a12.png"), 43,36);
		putimage(x, y + 25 * number, &s);
	}
	if (number_pai == 45 || number_pai == 46 || number_pai == 47 || number_pai == 48)
	{
		loadimage(&s, _T(".\\a\\a13.png"), 43,36);
		putimage(x, y + 25 * number, &s);
	}
	if (number_pai == 49 || number_pai == 50 || number_pai == 51 || number_pai == 52)
	{
		loadimage(&s, _T(".\\a\\a14.png"), 43,36);
		putimage(x, y + 25 * number, &s);
	}
	if (number_pai == 53 || number_pai == 54 || number_pai == 55)
	{
		loadimage(&s, _T(".\\a\\a15.png"), 43,36);
		putimage(x, y + 25 * number, &s);
	}
	if (number_pai == 56)
	{
		loadimage(&s, _T(".\\a\\a15b.png"), 43,36);
		putimage(x, y + 25 * number, &s);
	}
	if (number_pai == 57 || number_pai == 58 || number_pai == 59 || number_pai == 60)
	{
		loadimage(&s, _T(".\\a\\a16.png"), 43,36);
		putimage(x, y + 25 * number, &s);
	}
	if (number_pai == 61 || number_pai == 62 || number_pai == 63 || number_pai == 64)
	{
		loadimage(&s, _T(".\\a\\a17.png"), 43,36);
		putimage(x, y + 25 * number, &s);
	}
	if (number_pai == 65 || number_pai == 66 || number_pai == 67 || number_pai == 68)
	{
		loadimage(&s, _T(".\\a\\a18.png"), 43,36);
		putimage(x, y + 25 * number, &s);
	}
	if (number_pai == 69 || number_pai == 70 || number_pai == 71 || number_pai == 72)
	{
		loadimage(&s, _T(".\\a\\a19.png"), 43,36);
		putimage(x, y + 25 * number, &s);
	}
	if (number_pai == 73 || number_pai == 74 || number_pai == 75 || number_pai == 76)
	{
		loadimage(&s, _T(".\\a\\a21.png"), 43,36);
		putimage(x, y + 25 * number, &s);
	}
	if (number_pai == 77 || number_pai == 78 || number_pai == 79 || number_pai == 80)
	{
		loadimage(&s, _T(".\\a\\a22.png"), 43,36);
		putimage(x, y + 25 * number, &s);
	}
	if (number_pai == 81 || number_pai == 82 || number_pai == 83 || number_pai == 84)
	{
		loadimage(&s, _T(".\\a\\a23.png"), 43,36);
		putimage(x, y + 25 * number, &s);
	}
	if (number_pai == 85 || number_pai == 86 || number_pai == 87 || number_pai == 88)
	{
		loadimage(&s, _T(".\\a\\a24.png"), 43,36);
		putimage(x, y + 25 * number, &s);
	}
	if (number_pai == 89 || number_pai == 90)
	{
		loadimage(&s, _T(".\\a\\a25.png"), 43,36);
		putimage(x, y + 25 * number, &s);
	}
	if (number_pai == 91 || number_pai == 92)
	{
		loadimage(&s, _T(".\\a\\a25b.png"), 43,36);
		putimage(x, y + 25 * number, &s);
	}
	if (number_pai == 93 || number_pai == 94 || number_pai == 95 || number_pai == 96)
	{
		loadimage(&s, _T(".\\a\\a26.png"), 43,36);
		putimage(x, y + 25 * number, &s);
	}
	if (number_pai == 97 || number_pai == 98 || number_pai == 99 || number_pai == 100)
	{
		loadimage(&s, _T(".\\a\\a27.png"), 43,36);
		putimage(x, y + 25 * number, &s);
	}
	if (number_pai == 101 || number_pai == 102 || number_pai == 103 || number_pai == 104)
	{
		loadimage(&s, _T(".\\a\\a28.png"), 43,36);
		putimage(x, y + 25 * number, &s);
	}
	if (number_pai == 105 || number_pai == 106 || number_pai == 107 || number_pai == 108)
	{
		loadimage(&s, _T(".\\a\\a29.png"), 43,36);
		putimage(x, y + 25 * number, &s);
	}
	if (number_pai == 109 || number_pai == 110 || number_pai == 111 || number_pai == 112)
	{
		loadimage(&s, _T(".\\a\\a 东.png"), 43,36);
		putimage(x, y + 25 * number, &s);
	}
	if (number_pai == 113 || number_pai == 114 || number_pai == 115 || number_pai == 116)
	{
		loadimage(&s, _T(".\\a\\a 南.png"), 43,36);
		putimage(x, y + 25 * number, &s);
	}
	if (number_pai == 117 || number_pai == 118 || number_pai == 119 || number_pai == 120)
	{
		loadimage(&s, _T(".\\a\\a 西.png"), 43,36);
		putimage(x, y + 25 * number, &s);
	}
	if (number_pai == 121 || number_pai == 122 || number_pai == 123 || number_pai == 124)
	{
		loadimage(&s, _T(".\\a\\a 北.png"), 43,36);
		putimage(x, y + 25 * number, &s);
	}
	if (number_pai == 125 || number_pai == 126 || number_pai == 127 || number_pai == 128)
	{
		loadimage(&s, _T(".\\a\\a 中.png"), 43,36);
		putimage(x, y + 25 * number, &s);
	}
	if (number_pai == 129 || number_pai == 130 || number_pai == 131 || number_pai == 132)
	{
		loadimage(&s, _T(".\\a\\a 白板.png"), 43,36);
		putimage(x, y + 25 * number, &s);
	}
	if (number_pai == 133 || number_pai == 134 || number_pai == 135 || number_pai == 136)
	{
		loadimage(&s, _T(".\\a\\a 发.png"), 43,36);
		putimage(x, y + 25 * number, &s);
	}
	if (number_pai == 137)
	{
		loadimage(&s, _T(".\\a\\a 后.png"), 43,36);
		putimage(x, y + 25 * number, &s);
	}
	}
}
void majiangpai(int number_pai, int number, int x, int y)
{
	number_pai++;
	IMAGE s;
	if (number_pai == 1 || number_pai == 2 || number_pai == 3 || number_pai == 4)
	{
		loadimage(&s, _T(".\\s\\s01.png"), 63, 105);
		putimage(x + 63 * number, y, &s);
	}
	if (number_pai == 5 || number_pai == 6 || number_pai == 7 || number_pai == 8)
	{
		loadimage(&s, _T(".\\s\\s02.png"), 63, 105);
		putimage(x + 63 * number, y, &s);
	}
	if (number_pai == 9 || number_pai == 10 || number_pai == 11 || number_pai == 12)
	{
		loadimage(&s, _T(".\\s\\s03.png"), 63, 105);
		putimage(x + 63 * number, y, &s);
	}
	if (number_pai == 13 || number_pai == 14 || number_pai == 15 || number_pai == 16)
	{
		loadimage(&s, _T(".\\s\\s04.png"), 63, 105);
		putimage(x + 63 * number, y, &s);
	}
	if (number_pai == 17 || number_pai == 18 || number_pai == 19)
	{
		loadimage(&s, _T(".\\s\\s05.png"), 63, 105);
		putimage(x + 63 * number, y, &s);
	}
	if (number_pai == 20)
	{
		loadimage(&s, _T(".\\s\\s05b.png"), 63, 105);
		putimage(x + 63 * number, y, &s);
	}
	if (number_pai == 21 || number_pai == 22 || number_pai == 23 || number_pai == 24)
	{
		loadimage(&s, _T(".\\s\\s06.png"), 63, 105);
		putimage(x + 63 * number, y, &s);
	}
	if (number_pai == 25 || number_pai == 26 || number_pai == 27 || number_pai == 28)
	{
		loadimage(&s, _T(".\\s\\s07.png"), 63, 105);
		putimage(x + 63 * number, y, &s);
	}
	if (number_pai == 29 || number_pai == 30 || number_pai == 31 || number_pai == 32)
	{
		loadimage(&s, _T(".\\s\\s08.png"), 63, 105);
		putimage(x + 63 * number, y, &s);
	}
	if (number_pai == 33 || number_pai == 34 || number_pai == 35 || number_pai == 36)
	{
		loadimage(&s, _T(".\\s\\s09.png"), 63, 105);
		putimage(x + 63 * number, y, &s);
	}
	if (number_pai == 37 || number_pai == 38 || number_pai == 39 || number_pai == 40)
	{
		loadimage(&s, _T(".\\s\\s11.png"), 63, 105);
		putimage(x + 63 * number, y, &s);
	}
	if (number_pai == 41 || number_pai == 42 || number_pai == 43 || number_pai == 44)
	{
		loadimage(&s, _T(".\\s\\s12.png"), 63, 105);
		putimage(x + 63 * number, y, &s);
	}
	if (number_pai == 45 || number_pai == 46 || number_pai == 47 || number_pai == 48)
	{
		loadimage(&s, _T(".\\s\\s13.png"), 63, 105);
		putimage(x + 63 * number, y, &s);
	}
	if (number_pai == 49 || number_pai == 50 || number_pai == 51 || number_pai == 52)
	{
		loadimage(&s, _T(".\\s\\s14.png"), 63, 105);
		putimage(x + 63 * number, y, &s);
	}
	if (number_pai == 53 || number_pai == 54 || number_pai == 55)
	{
		loadimage(&s, _T(".\\s\\s15.png"), 63, 105);
		putimage(x + 63 * number, y, &s);
	}
	if (number_pai == 56)
	{
		loadimage(&s, _T(".\\s\\s15b.png"), 63, 105);
		putimage(x + 63 * number, y, &s);
	}
	if (number_pai == 57 || number_pai == 58 || number_pai == 59 || number_pai == 60)
	{
		loadimage(&s, _T(".\\s\\s16.png"), 63, 105);
		putimage(x + 63 * number, y, &s);
	}
	if (number_pai == 61 || number_pai == 62 || number_pai == 63 || number_pai == 64)
	{
		loadimage(&s, _T(".\\s\\s17.png"), 63, 105);
		putimage(x + 63 * number, y, &s);
	}
	if (number_pai == 65 || number_pai == 66 || number_pai == 67 || number_pai == 68)
	{
		loadimage(&s, _T(".\\s\\s18.png"), 63, 105);
		putimage(x + 63 * number, y, &s);
	}
	if (number_pai == 69 || number_pai == 70 || number_pai == 71 || number_pai == 72)
	{
		loadimage(&s, _T(".\\s\\s19.png"), 63, 105);
		putimage(x + 63 * number, y, &s);
	}
	if (number_pai == 73 || number_pai == 74 || number_pai == 75 || number_pai == 76)
	{
		loadimage(&s, _T(".\\s\\s21.png"), 63, 105);
		putimage(x + 63 * number, y, &s);
	}
	if (number_pai == 77 || number_pai == 78 || number_pai == 79 || number_pai == 80)
	{
		loadimage(&s, _T(".\\s\\s22.png"), 63, 105);
		putimage(x + 63 * number, y, &s);
	}
	if (number_pai == 81 || number_pai == 82 || number_pai == 83 || number_pai == 84)
	{
		loadimage(&s, _T(".\\s\\s23.png"), 63, 105);
		putimage(x + 63 * number, y, &s);
	}
	if (number_pai == 85 || number_pai == 86 || number_pai == 87 || number_pai == 88)
	{
		loadimage(&s, _T(".\\s\\s24.png"), 63, 105);
		putimage(x + 63 * number, y, &s);
	}
	if (number_pai == 89 || number_pai == 90)
	{
		loadimage(&s, _T(".\\s\\s25.png"), 63, 105);
		putimage(x + 63 * number, y, &s);
	}
	if (number_pai == 91 || number_pai == 92)
	{
		loadimage(&s, _T(".\\s\\s25b.png"), 63, 105);
		putimage(x + 63 * number, y, &s);
	}
	if (number_pai == 93 || number_pai == 94 || number_pai == 95 || number_pai == 96)
	{
		loadimage(&s, _T(".\\s\\s26.png"), 63, 105);
		putimage(x + 63 * number, y, &s);
	}
	if (number_pai == 97 || number_pai == 98 || number_pai == 99 || number_pai == 100)
	{
		loadimage(&s, _T(".\\s\\s27.png"), 63, 105);
		putimage(x + 63 * number, y, &s);
	}
	if (number_pai == 101 || number_pai == 102 || number_pai == 103 || number_pai == 104)
	{
		loadimage(&s, _T(".\\s\\s28.png"), 63, 105);
		putimage(x + 63 * number, y, &s);
	}
	if (number_pai == 105 || number_pai == 106 || number_pai == 107 || number_pai == 108)
	{
		loadimage(&s, _T(".\\s\\s29.png"), 63, 105);
		putimage(x + 63 * number, y, &s);
	}
	if (number_pai == 109 || number_pai == 110 || number_pai == 111 || number_pai == 112)
	{
		loadimage(&s, _T(".\\s\\s 东.png"), 63, 105);
		putimage(x + 63 * number, y, &s);
	}
	if (number_pai == 113 || number_pai == 114 || number_pai == 115 || number_pai == 116)
	{
		loadimage(&s, _T(".\\s\\s 南.png"), 63, 105);
		putimage(x + 63 * number, y, &s);
	}
	if (number_pai == 117 || number_pai == 118 || number_pai == 119 || number_pai == 120)
	{
		loadimage(&s, _T(".\\s\\s 西.png"), 63, 105);
		putimage(x + 63 * number, y, &s);
	}
	if (number_pai == 121 || number_pai == 122 || number_pai == 123 || number_pai == 124)
	{
		loadimage(&s, _T(".\\s\\s 北.png"), 63, 105);
		putimage(x + 63 * number, y, &s);
	}
	if (number_pai == 125 || number_pai == 126 || number_pai == 127 || number_pai == 128)
	{
		loadimage(&s, _T(".\\s\\s 中.png"), 63, 105);
		putimage(x + 63 * number, y, &s);
	}
	if (number_pai == 129 || number_pai == 130 || number_pai == 131 || number_pai == 132)
	{
		loadimage(&s, _T(".\\s\\s 白板.png"), 63, 105);
		putimage(x + 63 * number, y, &s);
	}
	if (number_pai == 133 || number_pai == 134 || number_pai == 135 || number_pai == 136)
	{
		loadimage(&s, _T(".\\s\\s 发.png"), 63, 105);
		putimage(x + 63 * number, y, &s);
	}
	if (number_pai == 137)
	{
		loadimage(&s, _T(".\\s\\s 后.png"), 63, 105);
		putimage(x + 63 * number, y, &s);
	}
}
void shwdra()//*显示宝牌 
{
	int temp4;
	printf("\nドラ指示牌: ");
	for (temp4 = 0; temp4 < drastate; temp4++)
	{
		majiangpai(dratishi[temp4], temp4, 0, 0);
	}
	printf("\n");
}
void shengyupaishuxianshi(int paishu)
{
	LOGFONT f;
	gettextstyle(&f);
	settextcolor(RGB(255, 255, 255));
	f.lfHeight = 25;
	wcscpy_s(f.lfFaceName, _T("华文行楷"));
	f.lfWeight = 100;
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	TCHAR s[4];
	_stprintf_s(s, _T("%d"), paishu);
	TCHAR changnum[2];
	_stprintf_s(changnum, _T("%d"), changshu);
	outtextxy(1322.5, 10, changnum);
	outtextxy(1235, 10, _T("东风局:"));
	outtextxy(1335, 10, _T("本场"));
	outtextxy(1235, 40, _T("剩余牌数为:"));
	outtextxy(1380, 40, s);
	outtextxy(0, 110, _T("——宝牌信息"));
	outtextxy(1235, 70, _T("场风："));
	outtextxy(1325, 70, _T("东风"));
	outtextxy(1235, 100, _T("自风："));
	if (zhuang == 0)
		outtextxy(1325, 100, _T("东风"));
	if (zhuang == 1)
		outtextxy(1325, 100, _T("北风"));
	if (zhuang == 2)
		outtextxy(1325, 100, _T("西风"));
	if (zhuang == 3)
		outtextxy(1325, 100, _T("南风"));
}

void qipaixianshi(int type, int number_pai, int number)
{
	number_pai++;
	switch (type)
	{
	case 0:
	{
		IMAGE s;
		if (number_pai == 1 || number_pai == 2 || number_pai == 3 || number_pai == 4)
		{
			loadimage(&s, _T(".\\s倒\\sd01.png"), 36, 43);
			putimage(583 + 36 * (number % 7), (363 + 36 * (number / 7)), &s);
		}
		if (number_pai == 5 || number_pai == 6 || number_pai == 7 || number_pai == 8)
		{
			loadimage(&s, _T(".\\s倒\\sd02.png"), 36, 43);
			putimage(583 + 36 * (number % 7), (363 + 36 * (number / 7)), &s);
		}
		if (number_pai == 9 || number_pai == 10 || number_pai == 11 || number_pai == 12)
		{
			loadimage(&s, _T(".\\s倒\\sd03.png"), 36, 43);
			putimage(583 + 36 * (number % 7), (363 + 36 * (number / 7)), &s);
		}
		if (number_pai == 13 || number_pai == 14 || number_pai == 15 || number_pai == 16)
		{
			loadimage(&s, _T(".\\s倒\\sd04.png"), 36, 43);
			putimage(583 + 36 * (number % 7), (363 + 36 * (number / 7)), &s);
		}
		if (number_pai == 17 || number_pai == 18 || number_pai == 19)
		{
			loadimage(&s, _T(".\\s倒\\sd05.png"), 36, 43);
			putimage(583 + 36 * (number % 7), (363 + 36 * (number / 7)), &s);
		}
		if (number_pai == 20)
		{
			loadimage(&s, _T(".\\s倒\\sd05b.png"), 36, 43);
			putimage(583 + 36 * (number % 7), (363 + 36 * (number / 7)), &s);
		}
		if (number_pai == 21 || number_pai == 22 || number_pai == 23 || number_pai == 24)
		{
			loadimage(&s, _T(".\\s倒\\sd06.png"), 36, 43);
			putimage(583 + 36 * (number % 7), (363 + 36 * (number / 7)), &s);
		}
		if (number_pai == 25 || number_pai == 26 || number_pai == 27 || number_pai == 28)
		{
			loadimage(&s, _T(".\\s倒\\sd07.png"), 36, 43);
			putimage(583 + 36 * (number % 7), (363 + 36 * (number / 7)), &s);
		}
		if (number_pai == 29 || number_pai == 30 || number_pai == 31 || number_pai == 32)
		{
			loadimage(&s, _T(".\\s倒\\sd08.png"), 36, 43);
			putimage(583 + 36 * (number % 7), (363 + 36 * (number / 7)), &s);
		}
		if (number_pai == 33 || number_pai == 34 || number_pai == 35 || number_pai == 36)
		{
			loadimage(&s, _T(".\\s倒\\sd09.png"), 36, 43);
			putimage(583 + 36 * (number % 7), (363 + 36 * (number / 7)), &s);
		}
		if (number_pai == 37 || number_pai == 38 || number_pai == 39 || number_pai == 40)
		{
			loadimage(&s, _T(".\\s倒\\sd11.png"), 36, 43);
			putimage(583 + 36 * (number % 7), (363 + 36 * (number / 7)), &s);
		}
		if (number_pai == 41 || number_pai == 42 || number_pai == 43 || number_pai == 44)
		{
			loadimage(&s, _T(".\\s倒\\sd12.png"), 36, 43);
			putimage(583 + 36 * (number % 7), (363 + 36 * (number / 7)), &s);
		}
		if (number_pai == 45 || number_pai == 46 || number_pai == 47 || number_pai == 48)
		{
			loadimage(&s, _T(".\\s倒\\sd13.png"), 36, 43);
			putimage(583 + 36 * (number % 7), (363 + 36 * (number / 7)), &s);
		}
		if (number_pai == 49 || number_pai == 50 || number_pai == 51 || number_pai == 52)
		{
			loadimage(&s, _T(".\\s倒\\sd14.png"), 36, 43);
			putimage(583 + 36 * (number % 7), (363 + 36 * (number / 7)), &s);
		}
		if (number_pai == 53 || number_pai == 54 || number_pai == 55)
		{
			loadimage(&s, _T(".\\s倒\\sd15.png"), 36, 43);
			putimage(583 + 36 * (number % 7), (363 + 36 * (number / 7)), &s);
		}
		if (number_pai == 56)
		{
			loadimage(&s, _T(".\\s倒\\sd15b.png"), 36, 43);
			putimage(583 + 36 * (number % 7), (363 + 36 * (number / 7)), &s);
		}
		if (number_pai == 57 || number_pai == 58 || number_pai == 59 || number_pai == 60)
		{
			loadimage(&s, _T(".\\s倒\\sd16.png"), 36, 43);
			putimage(583 + 36 * (number % 7), (363 + 36 * (number / 7)), &s);
		}
		if (number_pai == 61 || number_pai == 62 || number_pai == 63 || number_pai == 64)
		{
			loadimage(&s, _T(".\\s倒\\sd17.png"), 36, 43);
			putimage(583 + 36 * (number % 7), (363 + 36 * (number / 7)), &s);
		}
		if (number_pai == 65 || number_pai == 66 || number_pai == 67 || number_pai == 68)
		{
			loadimage(&s, _T(".\\s倒\\sd18.png"), 36, 43);
			putimage(583 + 36 * (number % 7), (363 + 36 * (number / 7)), &s);
		}
		if (number_pai == 69 || number_pai == 70 || number_pai == 71 || number_pai == 72)
		{
			loadimage(&s, _T(".\\s倒\\sd19.png"), 36, 43);
			putimage(583 + 36 * (number % 7), (363 + 36 * (number / 7)), &s);
		}
		if (number_pai == 73 || number_pai == 74 || number_pai == 75 || number_pai == 76)
		{
			loadimage(&s, _T(".\\s倒\\sd21.png"), 36, 43);
			putimage(583 + 36 * (number % 7), (363 + 36 * (number / 7)), &s);
		}
		if (number_pai == 77 || number_pai == 78 || number_pai == 79 || number_pai == 80)
		{
			loadimage(&s, _T(".\\s倒\\sd22.png"), 36, 43);
			putimage(583 + 36 * (number % 7), (363 + 36 * (number / 7)), &s);
		}
		if (number_pai == 81 || number_pai == 82 || number_pai == 83 || number_pai == 84)
		{
			loadimage(&s, _T(".\\s倒\\sd23.png"), 36, 43);
			putimage(583 + 36 * (number % 7), (363 + 36 * (number / 7)), &s);
		}
		if (number_pai == 85 || number_pai == 86 || number_pai == 87 || number_pai == 88)
		{
			loadimage(&s, _T(".\\s倒\\sd24.png"), 36, 43);
			putimage(583 + 36 * (number % 7), (363 + 36 * (number / 7)), &s);
		}
		if (number_pai == 89 || number_pai == 90)
		{
			loadimage(&s, _T(".\\s倒\\sd25.png"), 36, 43);
			putimage(583 + 36 * (number % 7), (363 + 36 * (number / 7)), &s);
		}
		if (number_pai == 91 || number_pai == 92)
		{
			loadimage(&s, _T(".\\s倒\\sd25b.png"), 36, 43);
			putimage(583 + 36 * (number % 7), (363 + 36 * (number / 7)), &s);
		}
		if (number_pai == 93 || number_pai == 94 || number_pai == 95 || number_pai == 96)
		{
			loadimage(&s, _T(".\\s倒\\sd26.png"), 36, 43);
			putimage(583 + 36 * (number % 7), (363 + 36 * (number / 7)), &s);
		}
		if (number_pai == 97 || number_pai == 98 || number_pai == 99 || number_pai == 100)
		{
			loadimage(&s, _T(".\\s倒\\sd27.png"), 36, 43);
			putimage(583 + 36 * (number % 7), (363 + 36 * (number / 7)), &s);
		}
		if (number_pai == 101 || number_pai == 102 || number_pai == 103 || number_pai == 104)
		{
			loadimage(&s, _T(".\\s倒\\sd28.png"), 36, 43);
			putimage(583 + 36 * (number % 7), (363 + 36 * (number / 7)), &s);
		}
		if (number_pai == 105 || number_pai == 106 || number_pai == 107 || number_pai == 108)
		{
			loadimage(&s, _T(".\\s倒\\sd29.png"), 36, 43);
			putimage(583 + 36 * (number % 7), (363 + 36 * (number / 7)), &s);
		}
		if (number_pai == 109 || number_pai == 110 || number_pai == 111 || number_pai == 112)
		{
			loadimage(&s, _T(".\\s倒\\sd 东.png"), 36, 43);
			putimage(583 + 36 * (number % 7), (363 + 36 * (number / 7)), &s);
		}
		if (number_pai == 113 || number_pai == 114 || number_pai == 115 || number_pai == 116)
		{
			loadimage(&s, _T(".\\s倒\\sd 南.png"), 36, 43);
			putimage(583 + 36 * (number % 7), (363 + 36 * (number / 7)), &s);
		}
		if (number_pai == 117 || number_pai == 118 || number_pai == 119 || number_pai == 120)
		{
			loadimage(&s, _T(".\\s倒\\sd 西.png"), 36, 43);
			putimage(583 + 36 * (number % 7), (363 + 36 * (number / 7)), &s);
		}
		if (number_pai == 121 || number_pai == 122 || number_pai == 123 || number_pai == 124)
		{
			loadimage(&s, _T(".\\s倒\\sd 北.png"), 36, 43);
			putimage(583 + 36 * (number % 7), (363 + 36 * (number / 7)), &s);
		}
		if (number_pai == 125 || number_pai == 126 || number_pai == 127 || number_pai == 128)
		{
			loadimage(&s, _T(".\\s倒\\sd 中.png"), 36, 43);
			putimage(583 + 36 * (number % 7), (363 + 36 * (number / 7)), &s);
		}
		if (number_pai == 129 || number_pai == 130 || number_pai == 131 || number_pai == 132)
		{
			loadimage(&s, _T(".\\s倒\\sd 白板.png"), 36, 43);
			putimage(583 + 36 * (number % 7), (363 + 36 * (number / 7)), &s);
		}
		if (number_pai == 133 || number_pai == 134 || number_pai == 135 || number_pai == 136)
		{
			loadimage(&s, _T(".\\s倒\\sd 发.png"), 36, 43);
			putimage(583 + 36 * (number % 7), (363 + 36 * (number / 7)), &s);
		}
		break;
	}
	case 1:
	{
		IMAGE s;
		if (number_pai == 1 || number_pai == 2 || number_pai == 3 || number_pai == 4)
		{
			loadimage(&s, _T(".\\d\\d01.png"), 34,26);
			putimage(837 + 34 * (number / 5) - 2*(number % 5), (330 - 26 * (number % 5)), &s);
		}
		if (number_pai == 5 || number_pai == 6 || number_pai == 7 || number_pai == 8)
		{
			loadimage(&s, _T(".\\d\\d02.png"), 34,26);
			putimage(837 + 34 * (number / 5) - 2*(number % 5), (330 - 26 * (number % 5)), &s);
		}
		if (number_pai == 9 || number_pai == 10 || number_pai == 11 || number_pai == 12)
		{
			loadimage(&s, _T(".\\d\\d03.png"), 34,26);
			putimage(837 + 34 * (number / 5) - 2*(number % 5), (330 - 26 * (number % 5)), &s);
		}
		if (number_pai == 13 || number_pai == 14 || number_pai == 15 || number_pai == 16)
		{
			loadimage(&s, _T(".\\d\\d04.png"), 34,26);
			putimage(837 + 34 * (number / 5) - 2*(number % 5), (330 - 26 * (number % 5)), &s);
		}
		if (number_pai == 17 || number_pai == 18 || number_pai == 19)
		{
			loadimage(&s, _T(".\\d\\d05.png"), 34,26);
			putimage(837 + 34 * (number / 5) - 2*(number % 5), (330 - 26 * (number % 5)), &s);
		}
		if (number_pai == 20)
		{
			loadimage(&s, _T(".\\d\\d05b.png"), 34,26);
			putimage(837 + 34 * (number / 5) - 2*(number % 5), (330 - 26 * (number % 5)), &s);
		}
		if (number_pai == 21 || number_pai == 22 || number_pai == 23 || number_pai == 24)
		{
			loadimage(&s, _T(".\\d\\d06.png"), 34,26);
			putimage(837 + 34 * (number / 5) - 2*(number % 5), (330 - 26 * (number % 5)), &s);
		}
		if (number_pai == 25 || number_pai == 26 || number_pai == 27 || number_pai == 28)
		{
			loadimage(&s, _T(".\\d\\d07.png"), 34,26);
			putimage(837 + 34 * (number / 5) - 2*(number % 5), (330 - 26 * (number % 5)), &s);
		}
		if (number_pai == 29 || number_pai == 30 || number_pai == 31 || number_pai == 32)
		{
			loadimage(&s, _T(".\\d\\d08.png"), 34,26);
			putimage(837 + 34 * (number / 5) - 2*(number % 5), (330 - 26 * (number % 5)), &s);
		}
		if (number_pai == 33 || number_pai == 34 || number_pai == 35 || number_pai == 36)
		{
			loadimage(&s, _T(".\\d\\d09.png"), 34,26);
			putimage(837 + 34 * (number / 5) - 2*(number % 5), (330 - 26 * (number % 5)), &s);
		}
		if (number_pai == 37 || number_pai == 38 || number_pai == 39 || number_pai == 40)
		{
			loadimage(&s, _T(".\\d\\d11.png"), 34,26);
			putimage(837 + 34 * (number / 5) - 2*(number % 5), (330 - 26 * (number % 5)), &s);
		}
		if (number_pai == 41 || number_pai == 42 || number_pai == 43 || number_pai == 44)
		{
			loadimage(&s, _T(".\\d\\d12.png"), 34,26);
			putimage(837 + 34 * (number / 5) - 2*(number % 5), (330 - 26 * (number % 5)), &s);
		}
		if (number_pai == 45 || number_pai == 46 || number_pai == 47 || number_pai == 48)
		{
			loadimage(&s, _T(".\\d\\d13.png"), 34,26);
			putimage(837 + 34 * (number / 5) - 2*(number % 5), (330 - 26 * (number % 5)), &s);
		}
		if (number_pai == 49 || number_pai == 50 || number_pai == 51 || number_pai == 52)
		{
			loadimage(&s, _T(".\\d\\d14.png"), 34,26);
			putimage(837 + 34 * (number / 5) - 2*(number % 5), (330 - 26 * (number % 5)), &s);
		}
		if (number_pai == 53 || number_pai == 54 || number_pai == 55)
		{
			loadimage(&s, _T(".\\d\\d15.png"), 34,26);
			putimage(837 + 34 * (number / 5) - 2*(number % 5), (330 - 26 * (number % 5)), &s);
		}
		if (number_pai == 56)
		{
			loadimage(&s, _T(".\\d\\d15b.png"), 34,26);
			putimage(837 + 34 * (number / 5) - 2*(number % 5), (330 - 26 * (number % 5)), &s);
		}
		if (number_pai == 57 || number_pai == 58 || number_pai == 59 || number_pai == 60)
		{
			loadimage(&s, _T(".\\d\\d16.png"), 34,26);
			putimage(837 + 34 * (number / 5) - 2*(number % 5), (330 - 26 * (number % 5)), &s);
		}
		if (number_pai == 61 || number_pai == 62 || number_pai == 63 || number_pai == 64)
		{
			loadimage(&s, _T(".\\d\\d17.png"), 34,26);
			putimage(837 + 34 * (number / 5) - 2*(number % 5), (330 - 26 * (number % 5)), &s);
		}
		if (number_pai == 65 || number_pai == 66 || number_pai == 67 || number_pai == 68)
		{
			loadimage(&s, _T(".\\d\\d18.png"), 34,26);
			putimage(837 + 34 * (number / 5) - 2*(number % 5), (330 - 26 * (number % 5)), &s);
		}
		if (number_pai == 69 || number_pai == 70 || number_pai == 71 || number_pai == 72)
		{
			loadimage(&s, _T(".\\d\\d19.png"), 34,26);
			putimage(837 + 34 * (number / 5) - 2*(number % 5), (330 - 26 * (number % 5)), &s);
		}
		if (number_pai == 73 || number_pai == 74 || number_pai == 75 || number_pai == 76)
		{
			loadimage(&s, _T(".\\d\\d21.png"), 34,26);
			putimage(837 + 34 * (number / 5) - 2*(number % 5), (330 - 26 * (number % 5)), &s);
		}
		if (number_pai == 77 || number_pai == 78 || number_pai == 79 || number_pai == 80)
		{
			loadimage(&s, _T(".\\d\\d22.png"), 34,26);
			putimage(837 + 34 * (number / 5) - 2*(number % 5), (330 - 26 * (number % 5)), &s);
		}
		if (number_pai == 81 || number_pai == 82 || number_pai == 83 || number_pai == 84)
		{
			loadimage(&s, _T(".\\d\\d23.png"), 34,26);
			putimage(837 + 34 * (number / 5) - 2*(number % 5), (330 - 26 * (number % 5)), &s);
		}
		if (number_pai == 85 || number_pai == 86 || number_pai == 87 || number_pai == 88)
		{
			loadimage(&s, _T(".\\d\\d24.png"), 34,26);
			putimage(837 + 34 * (number / 5) - 2*(number % 5), (330 - 26 * (number % 5)), &s);
		}
		if (number_pai == 89 || number_pai == 90)
		{
			loadimage(&s, _T(".\\d\\d25.png"), 34,26);
			putimage(837 + 34 * (number / 5) - 2*(number % 5), (330 - 26 * (number % 5)), &s);
		}
		if (number_pai == 91 || number_pai == 92)
		{
			loadimage(&s, _T(".\\d\\d25b.png"), 34,26);
			putimage(837 + 34 * (number / 5) - 2*(number % 5), (330 - 26 * (number % 5)), &s);
		}
		if (number_pai == 93 || number_pai == 94 || number_pai == 95 || number_pai == 96)
		{
			loadimage(&s, _T(".\\d\\d26.png"), 34,26);
			putimage(837 + 34 * (number / 5) - 2*(number % 5), (330 - 26 * (number % 5)), &s);
		}
		if (number_pai == 97 || number_pai == 98 || number_pai == 99 || number_pai == 100)
		{
			loadimage(&s, _T(".\\d\\d27.png"), 34,26);
			putimage(837 + 34 * (number / 5) - 2*(number % 5), (330 - 26 * (number % 5)), &s);
		}
		if (number_pai == 101 || number_pai == 102 || number_pai == 103 || number_pai == 104)
		{
			loadimage(&s, _T(".\\d\\d28.png"), 34,26);
			putimage(837 + 34 * (number / 5) - 2*(number % 5), (330 - 26 * (number % 5)), &s);
		}
		if (number_pai == 105 || number_pai == 106 || number_pai == 107 || number_pai == 108)
		{
			loadimage(&s, _T(".\\d\\d29.png"), 34,26);
			putimage(837 + 34 * (number / 5) - 2*(number % 5), (330 - 26 * (number % 5)), &s);
		}
		if (number_pai == 109 || number_pai == 110 || number_pai == 111 || number_pai == 112)
		{
			loadimage(&s, _T(".\\d\\d 东.png"), 34,26);
			putimage(837 + 34 * (number / 5) - 2*(number % 5), (330 - 26 * (number % 5)), &s);
		}
		if (number_pai == 113 || number_pai == 114 || number_pai == 115 || number_pai == 116)
		{
			loadimage(&s, _T(".\\d\\d 南.png"), 34,26);
			putimage(837 + 34 * (number / 5) - 2*(number % 5), (330 - 26 * (number % 5)), &s);
		}
		if (number_pai == 117 || number_pai == 118 || number_pai == 119 || number_pai == 120)
		{
			loadimage(&s, _T(".\\d\\d 西.png"), 34,26);
			putimage(837 + 34 * (number / 5) - 2*(number % 5), (330 - 26 * (number % 5)), &s);
		}
		if (number_pai == 121 || number_pai == 122 || number_pai == 123 || number_pai == 124)
		{
			loadimage(&s, _T(".\\d\\d 北.png"), 34,26);
			putimage(837 + 34 * (number / 5) - 2*(number % 5), (330 - 26 * (number % 5)), &s);
		}
		if (number_pai == 125 || number_pai == 126 || number_pai == 127 || number_pai == 128)
		{
			loadimage(&s, _T(".\\d\\d 中.png"), 34,26);
			putimage(837 + 34 * (number / 5) - 2*(number % 5), (330 - 26 * (number % 5)), &s);
		}
		if (number_pai == 129 || number_pai == 130 || number_pai == 131 || number_pai == 132)
		{
			loadimage(&s, _T(".\\d\\d 白板.png"), 34,26);
			putimage(837 + 34 * (number / 5) - 2*(number % 5), (330 - 26 * (number % 5)), &s);
		}
		if (number_pai == 133 || number_pai == 134 || number_pai == 135 || number_pai == 136)
		{
			loadimage(&s, _T(".\\d\\d 发.png"), 34,26);
			putimage(837 + 34 * (number / 5) - 2*(number % 5), (330 - 26 * (number % 5)), &s);
		}
		break;
	}
	case 2:
	{
		IMAGE s;
		if (number_pai == 1 || number_pai == 2 || number_pai == 3 || number_pai == 4)
		{
			loadimage(&s, _T(".\\w\\w01.png"), 28, 36);
			putimage(784 - 28 * (number % 7), (182 - 36 * (number / 7)), &s);
		}
		if (number_pai == 5 || number_pai == 6 || number_pai == 7 || number_pai == 8)
		{
			loadimage(&s, _T(".\\w\\w02.png"), 28,36);
			putimage(784 - 28 * (number % 7), (182 - 36 * (number / 7)), &s);
		}
		if (number_pai == 9 || number_pai == 10 || number_pai == 11 || number_pai == 12)
		{
			loadimage(&s, _T(".\\w\\w03.png"), 28,36);
			putimage(784 - 28 * (number % 7), (182 - 36 * (number / 7)), &s);
		}
		if (number_pai == 13 || number_pai == 14 || number_pai == 15 || number_pai == 16)
		{
			loadimage(&s, _T(".\\w\\w04.png"), 28,36);
			putimage(784 - 28 * (number % 7), (182 - 36 * (number / 7)), &s);
		}
		if (number_pai == 17 || number_pai == 18 || number_pai == 19)
		{
			loadimage(&s, _T(".\\w\\w05.png"), 28,36);
			putimage(784 - 28 * (number % 7), (182 - 36 * (number / 7)), &s);
		}
		if (number_pai == 20)
		{
			loadimage(&s, _T(".\\w\\w05b.png"), 28,36);
			putimage(784 - 28 * (number % 7), (182 - 36 * (number / 7)), &s);
		}
		if (number_pai == 21 || number_pai == 22 || number_pai == 23 || number_pai == 24)
		{
			loadimage(&s, _T(".\\w\\w06.png"), 28,36);
			putimage(784 - 28 * (number % 7), (182 - 36 * (number / 7)), &s);
		}
		if (number_pai == 25 || number_pai == 26 || number_pai == 27 || number_pai == 28)
		{
			loadimage(&s, _T(".\\w\\w07.png"), 28,36);
			putimage(784 - 28 * (number % 7), (182 - 36 * (number / 7)), &s);
		}
		if (number_pai == 29 || number_pai == 30 || number_pai == 31 || number_pai == 32)
		{
			loadimage(&s, _T(".\\w\\w08.png"), 28,36);
			putimage(784 - 28 * (number % 7), (182 - 36 * (number / 7)), &s);
		}
		if (number_pai == 33 || number_pai == 34 || number_pai == 35 || number_pai == 36)
		{
			loadimage(&s, _T(".\\w\\w09.png"), 28,36);
			putimage(784 - 28 * (number % 7), (182 - 36 * (number / 7)), &s);
		}
		if (number_pai == 37 || number_pai == 38 || number_pai == 39 || number_pai == 40)
		{
			loadimage(&s, _T(".\\w\\w11.png"), 28,36);
			putimage(784 - 28 * (number % 7), (182 - 36 * (number / 7)), &s);
		}
		if (number_pai == 41 || number_pai == 42 || number_pai == 43 || number_pai == 44)
		{
			loadimage(&s, _T(".\\w\\w12.png"), 28,36);
			putimage(784 - 28 * (number % 7), (182 - 36 * (number / 7)), &s);
		}
		if (number_pai == 45 || number_pai == 46 || number_pai == 47 || number_pai == 48)
		{
			loadimage(&s, _T(".\\w\\w13.png"), 28,36);
			putimage(784 - 28 * (number % 7), (182 - 36 * (number / 7)), &s);
		}
		if (number_pai == 49 || number_pai == 50 || number_pai == 51 || number_pai == 52)
		{
			loadimage(&s, _T(".\\w\\w14.png"), 28,36);
			putimage(784 - 28 * (number % 7), (182 - 36 * (number / 7)), &s);
		}
		if (number_pai == 53 || number_pai == 54 || number_pai == 55)
		{
			loadimage(&s, _T(".\\w\\w15.png"), 28,36);
			putimage(784 - 28 * (number % 7), (182 - 36 * (number / 7)), &s);
		}
		if (number_pai == 56)
		{
			loadimage(&s, _T(".\\w\\w15b.png"), 28,36);
			putimage(784 - 28 * (number % 7), (182 - 36 * (number / 7)), &s);
		}
		if (number_pai == 57 || number_pai == 58 || number_pai == 59 || number_pai == 60)
		{
			loadimage(&s, _T(".\\w\\w16.png"), 28,36);
			putimage(784 - 28 * (number % 7), (182 - 36 * (number / 7)), &s);
		}
		if (number_pai == 61 || number_pai == 62 || number_pai == 63 || number_pai == 64)
		{
			loadimage(&s, _T(".\\w\\w17.png"), 28,36);
			putimage(784 - 28 * (number % 7), (182 - 36 * (number / 7)), &s);
		}
		if (number_pai == 65 || number_pai == 66 || number_pai == 67 || number_pai == 68)
		{
			loadimage(&s, _T(".\\w\\w18.png"), 28,36);
			putimage(784 - 28 * (number % 7), (182 - 36 * (number / 7)), &s);
		}
		if (number_pai == 69 || number_pai == 70 || number_pai == 71 || number_pai == 72)
		{
			loadimage(&s, _T(".\\w\\w19.png"), 28,36);
			putimage(784 - 28 * (number % 7), (182 - 36 * (number / 7)), &s);
		}
		if (number_pai == 73 || number_pai == 74 || number_pai == 75 || number_pai == 76)
		{
			loadimage(&s, _T(".\\w\\w21.png"), 28,36);
			putimage(784 - 28 * (number % 7), (182 - 36 * (number / 7)), &s);
		}
		if (number_pai == 77 || number_pai == 78 || number_pai == 79 || number_pai == 80)
		{
			loadimage(&s, _T(".\\w\\w22.png"), 28,36);
			putimage(784 - 28 * (number % 7), (182 - 36 * (number / 7)), &s);
		}
		if (number_pai == 81 || number_pai == 82 || number_pai == 83 || number_pai == 84)
		{
			loadimage(&s, _T(".\\w\\w23.png"), 28,36);
			putimage(784 - 28 * (number % 7), (182 - 36 * (number / 7)), &s);
		}
		if (number_pai == 85 || number_pai == 86 || number_pai == 87 || number_pai == 88)
		{
			loadimage(&s, _T(".\\w\\w24.png"), 28,36);
			putimage(784 - 28 * (number % 7), (182 - 36 * (number / 7)), &s);
		}
		if (number_pai == 89 || number_pai == 90)
		{
			loadimage(&s, _T(".\\w\\w25.png"), 28,36);
			putimage(784 - 28 * (number % 7), (182 - 36 * (number / 7)), &s);
		}
		if (number_pai == 91 || number_pai == 92)
		{
			loadimage(&s, _T(".\\w\\w25b.png"), 28,36);
			putimage(784 - 28 * (number % 7), (182 - 36 * (number / 7)), &s);
		}
		if (number_pai == 93 || number_pai == 94 || number_pai == 95 || number_pai == 96)
		{
			loadimage(&s, _T(".\\w\\w26.png"), 28,36);
			putimage(784 - 28 * (number % 7), (182 - 36 * (number / 7)), &s);
		}
		if (number_pai == 97 || number_pai == 98 || number_pai == 99 || number_pai == 100)
		{
			loadimage(&s, _T(".\\w\\w27.png"), 28,36);
			putimage(784 - 28 * (number % 7), (182 - 36 * (number / 7)), &s);
		}
		if (number_pai == 101 || number_pai == 102 || number_pai == 103 || number_pai == 104)
		{
			loadimage(&s, _T(".\\w\\w28.png"), 28,36);
			putimage(784 - 28 * (number % 7), (182 - 36 * (number / 7)), &s);
		}
		if (number_pai == 105 || number_pai == 106 || number_pai == 107 || number_pai == 108)
		{
			loadimage(&s, _T(".\\w\\w29.png"), 28,36);
			putimage(784 - 28 * (number % 7), (182 - 36 * (number / 7)), &s);
		}
		if (number_pai == 109 || number_pai == 110 || number_pai == 111 || number_pai == 112)
		{
			loadimage(&s, _T(".\\w\\w 东.png"), 28,36);
			putimage(784 - 28 * (number % 7), (182 - 36 * (number / 7)), &s);
		}
		if (number_pai == 113 || number_pai == 114 || number_pai == 115 || number_pai == 116)
		{
			loadimage(&s, _T(".\\w\\w 南.png"), 28,36);
			putimage(784 - 28 * (number % 7), (182 - 36 * (number / 7)), &s);
		}
		if (number_pai == 117 || number_pai == 118 || number_pai == 119 || number_pai == 120)
		{
			loadimage(&s, _T(".\\w\\w 西.png"), 28,36);
			putimage(784 - 28 * (number % 7), (182 - 36 * (number / 7)), &s);
		}
		if (number_pai == 121 || number_pai == 122 || number_pai == 123 || number_pai == 124)
		{
			loadimage(&s, _T(".\\w\\w 北.png"), 28,36);
			putimage(784 - 28 * (number % 7), (182 - 36 * (number / 7)), &s);
		}
		if (number_pai == 125 || number_pai == 126 || number_pai == 127 || number_pai == 128)
		{
			loadimage(&s, _T(".\\w\\w 中.png"), 28,36);
			putimage(784 - 28 * (number % 7), (182 - 36 * (number / 7)), &s);
		}
		if (number_pai == 129 || number_pai == 130 || number_pai == 131 || number_pai == 132)
		{
			loadimage(&s, _T(".\\w\\w 白板.png"), 28,36);
			putimage(784 - 28 * (number % 7), (182 - 36 * (number / 7)), &s);
		}
		if (number_pai == 133 || number_pai == 134 || number_pai == 135 || number_pai == 136)
		{
			loadimage(&s, _T(".\\w\\w 发.png"), 28,36);
			putimage(784 - 28 * (number % 7), (182 - 36 * (number / 7)), &s);
		}
		break;
	}
	case 3:
	{
		IMAGE s;
		if (number_pai == 1 || number_pai == 2 || number_pai == 3 || number_pai == 4)
		{
			loadimage(&s, _T(".\\a\\a01.png"), 34, 26);
			putimage(550 - 34 * (number / 5) - 2 * (number % 5), (225 + 26 * (number % 5)), &s);
		}
		if (number_pai == 5 || number_pai == 6 || number_pai == 7 || number_pai == 8)
		{
			loadimage(&s, _T(".\\a\\a02.png"), 34,26);
			putimage(550 - 34 * (number / 5) - 2 * (number % 5), (225 + 26 * (number % 5)), &s);
		}
		if (number_pai == 9 || number_pai == 10 || number_pai == 11 || number_pai == 12)
		{
			loadimage(&s, _T(".\\a\\a03.png"), 34,26);
			putimage(550 - 34 * (number / 5) - 2 * (number % 5), (225 + 26 * (number % 5)), &s);
		}
		if (number_pai == 13 || number_pai == 14 || number_pai == 15 || number_pai == 16)
		{
			loadimage(&s, _T(".\\a\\a04.png"), 34,26);
			putimage(550 - 34 * (number / 5) - 2 * (number % 5), (225 + 26 * (number % 5)), &s);
		}
		if (number_pai == 17 || number_pai == 18 || number_pai == 19)
		{
			loadimage(&s, _T(".\\a\\a05.png"), 34,26);
			putimage(550 - 34 * (number / 5) - 2 * (number % 5), (225 + 26 * (number % 5)), &s);
		}
		if (number_pai == 20)
		{
			loadimage(&s, _T(".\\a\\a05b.png"), 34,26);
			putimage(550 - 34 * (number / 5) - 2 * (number % 5), (225 + 26 * (number % 5)), &s);
		}
		if (number_pai == 21 || number_pai == 22 || number_pai == 23 || number_pai == 24)
		{
			loadimage(&s, _T(".\\a\\a06.png"), 34,26);
			putimage(550 - 34 * (number / 5) - 2 * (number % 5), (225 + 26 * (number % 5)), &s);
		}
		if (number_pai == 25 || number_pai == 26 || number_pai == 27 || number_pai == 28)
		{
			loadimage(&s, _T(".\\a\\a07.png"), 34,26);
			putimage(550 - 34 * (number / 5) - 2 * (number % 5), (225 + 26 * (number % 5)), &s);
		}
		if (number_pai == 29 || number_pai == 30 || number_pai == 31 || number_pai == 32)
		{
			loadimage(&s, _T(".\\a\\a08.png"), 34,26);
			putimage(550 - 34 * (number / 5) - 2 * (number % 5), (225 + 26 * (number % 5)), &s);
		}
		if (number_pai == 33 || number_pai == 34 || number_pai == 35 || number_pai == 36)
		{
			loadimage(&s, _T(".\\a\\a09.png"), 34,26);
			putimage(550 - 34 * (number / 5) - 2 * (number % 5), (225 + 26 * (number % 5)), &s);
		}
		if (number_pai == 37 || number_pai == 38 || number_pai == 39 || number_pai == 40)
		{
			loadimage(&s, _T(".\\a\\a11.png"), 34,26);
			putimage(550 - 34 * (number / 5) - 2 * (number % 5), (225 + 26 * (number % 5)), &s);
		}
		if (number_pai == 41 || number_pai == 42 || number_pai == 43 || number_pai == 44)
		{
			loadimage(&s, _T(".\\a\\a12.png"), 34,26);
			putimage(550 - 34 * (number / 5) - 2 * (number % 5), (225 + 26 * (number % 5)), &s);
		}
		if (number_pai == 45 || number_pai == 46 || number_pai == 47 || number_pai == 48)
		{
			loadimage(&s, _T(".\\a\\a13.png"), 34,26);
			putimage(550 - 34 * (number / 5) - 2 * (number % 5), (225 + 26 * (number % 5)), &s);
		}
		if (number_pai == 49 || number_pai == 50 || number_pai == 51 || number_pai == 52)
		{
			loadimage(&s, _T(".\\a\\a14.png"), 34,26);
			putimage(550 - 34 * (number / 5) - 2 * (number % 5), (225 + 26 * (number % 5)), &s);
		}
		if (number_pai == 53 || number_pai == 54 || number_pai == 55)
		{
			loadimage(&s, _T(".\\a\\a15.png"), 34,26);
			putimage(550 - 34 * (number / 5) - 2 * (number % 5), (225 + 26 * (number % 5)), &s);
		}
		if (number_pai == 56)
		{
			loadimage(&s, _T(".\\a\\a15b.png"), 34,26);
			putimage(550 - 34 * (number / 5) - 2 * (number % 5), (225 + 26 * (number % 5)), &s);
		}
		if (number_pai == 57 || number_pai == 58 || number_pai == 59 || number_pai == 60)
		{
			loadimage(&s, _T(".\\a\\a16.png"), 34,26);
			putimage(550 - 34 * (number / 5) - 2 * (number % 5), (225 + 26 * (number % 5)), &s);
		}
		if (number_pai == 61 || number_pai == 62 || number_pai == 63 || number_pai == 64)
		{
			loadimage(&s, _T(".\\a\\a17.png"), 34,26);
			putimage(550 - 34 * (number / 5) - 2 * (number % 5), (225 + 26 * (number % 5)), &s);
		}
		if (number_pai == 65 || number_pai == 66 || number_pai == 67 || number_pai == 68)
		{
			loadimage(&s, _T(".\\a\\a18.png"), 34,26);
			putimage(550 - 34 * (number / 5) - 2 * (number % 5), (225 + 26 * (number % 5)), &s);
		}
		if (number_pai == 69 || number_pai == 70 || number_pai == 71 || number_pai == 72)
		{
			loadimage(&s, _T(".\\a\\a19.png"), 34,26);
			putimage(550 - 34 * (number / 5) - 2 * (number % 5), (225 + 26 * (number % 5)), &s);
		}
		if (number_pai == 73 || number_pai == 74 || number_pai == 75 || number_pai == 76)
		{
			loadimage(&s, _T(".\\a\\a21.png"), 34,26);
			putimage(550 - 34 * (number / 5) - 2 * (number % 5), (225 + 26 * (number % 5)), &s);
		}
		if (number_pai == 77 || number_pai == 78 || number_pai == 79 || number_pai == 80)
		{
			loadimage(&s, _T(".\\a\\a22.png"), 34,26);
			putimage(550 - 34 * (number / 5) - 2 * (number % 5), (225 + 26 * (number % 5)), &s);
		}
		if (number_pai == 81 || number_pai == 82 || number_pai == 83 || number_pai == 84)
		{
			loadimage(&s, _T(".\\a\\a23.png"), 34,26);
			putimage(550 - 34 * (number / 5) - 2 * (number % 5), (225 + 26 * (number % 5)), &s);
		}
		if (number_pai == 85 || number_pai == 86 || number_pai == 87 || number_pai == 88)
		{
			loadimage(&s, _T(".\\a\\a24.png"), 34,26);
			putimage(550 - 34 * (number / 5) - 2 * (number % 5), (225 + 26 * (number % 5)), &s);
		}
		if (number_pai == 89 || number_pai == 90)
		{
			loadimage(&s, _T(".\\a\\a25.png"), 34,26);
			putimage(550 - 34 * (number / 5) - 2 * (number % 5), (225 + 26 * (number % 5)), &s);
		}
		if (number_pai == 91 || number_pai == 92)
		{
			loadimage(&s, _T(".\\a\\a25b.png"), 34,26);
			putimage(550 - 34 * (number / 5) - 2 * (number % 5), (225 + 26 * (number % 5)), &s);
		}
		if (number_pai == 93 || number_pai == 94 || number_pai == 95 || number_pai == 96)
		{
			loadimage(&s, _T(".\\a\\a26.png"), 34,26);
			putimage(550 - 34 * (number / 5) - 2 * (number % 5), (225 + 26 * (number % 5)), &s);
		}
		if (number_pai == 97 || number_pai == 98 || number_pai == 99 || number_pai == 100)
		{
			loadimage(&s, _T(".\\a\\a27.png"), 34,26);
			putimage(550 - 34 * (number / 5) - 2 * (number % 5), (225 + 26 * (number % 5)), &s);
		}
		if (number_pai == 101 || number_pai == 102 || number_pai == 103 || number_pai == 104)
		{
			loadimage(&s, _T(".\\a\\a28.png"), 34,26);
			putimage(550 - 34 * (number / 5) - 2 * (number % 5), (225 + 26 * (number % 5)), &s);
		}
		if (number_pai == 105 || number_pai == 106 || number_pai == 107 || number_pai == 108)
		{
			loadimage(&s, _T(".\\a\\a29.png"), 34,26);
			putimage(550 - 34 * (number / 5) - 2 * (number % 5), (225 + 26 * (number % 5)), &s);
		}
		if (number_pai == 109 || number_pai == 110 || number_pai == 111 || number_pai == 112)
		{
			loadimage(&s, _T(".\\a\\a 东.png"), 34,26);
			putimage(550 - 34 * (number / 5) - 2 * (number % 5), (225 + 26 * (number % 5)), &s);
		}
		if (number_pai == 113 || number_pai == 114 || number_pai == 115 || number_pai == 116)
		{
			loadimage(&s, _T(".\\a\\a 南.png"), 34,26);
			putimage(550 - 34 * (number / 5) - 2 * (number % 5), (225 + 26 * (number % 5)), &s);
		}
		if (number_pai == 117 || number_pai == 118 || number_pai == 119 || number_pai == 120)
		{
			loadimage(&s, _T(".\\a\\a 西.png"), 34,26);
			putimage(550 - 34 * (number / 5) - 2 * (number % 5), (225 + 26 * (number % 5)), &s);
		}
		if (number_pai == 121 || number_pai == 122 || number_pai == 123 || number_pai == 124)
		{
			loadimage(&s, _T(".\\a\\a 北.png"), 34,26);
			putimage(550 - 34 * (number / 5) - 2 * (number % 5), (225 + 26 * (number % 5)), &s);
		}
		if (number_pai == 125 || number_pai == 126 || number_pai == 127 || number_pai == 128)
		{
			loadimage(&s, _T(".\\a\\a 中.png"), 34,26);
			putimage(550 - 34 * (number / 5) - 2 * (number % 5), (225 + 26 * (number % 5)), &s);
		}
		if (number_pai == 129 || number_pai == 130 || number_pai == 131 || number_pai == 132)
		{
			loadimage(&s, _T(".\\a\\a 白板.png"), 34,26);
			putimage(550 - 34 * (number / 5) - 2 * (number % 5), (225 + 26 * (number % 5)), &s);
		}
		if (number_pai == 133 || number_pai == 134 || number_pai == 135 || number_pai == 136)
		{
			loadimage(&s, _T(".\\a\\a 发.png"), 34,26);
			putimage(550 - 34 * (number / 5) - 2 * (number % 5), (225 + 26 * (number % 5)), &s);
		}
		break;
	}
	}
}

void duimianpai(int n)
{
	IMAGE s;
	if (n == 1)
	{
		loadimage(&s, _T(".\\bmp\\牌墙 w 1.png"), 38, 54);
		putimage(700 - (n - 1) / 2 * 38, 40, &s);
	}
	if (n == 2)
	{
		loadimage(&s, _T(".\\bmp\\牌墙 w 2.png"), 74, 54);
		putimage(700 - (n - 1) / 2 * 38, 40, &s);
	}
	if (n == 4)
	{
		loadimage(&s, _T(".\\bmp\\牌墙 w 4.png"), 144, 54);
		putimage(700 - (n - 1) / 2 * 38, 40, &s);
	}
	if (n == 5)
	{
		loadimage(&s, _T(".\\bmp\\牌墙 w 5.png"), 179, 54);
		putimage(700 - (n - 1) / 2 * 38, 40, &s);
	}
	if (n == 7)
	{
		loadimage(&s, _T(".\\bmp\\牌墙 w 7.png"), 250, 54);
		putimage(700 - (n - 1) / 2 * 38, 40, &s);
	}
	if (n == 8)
	{
		loadimage(&s, _T(".\\bmp\\牌墙 w 8.png"), 285, 54);
		putimage(700 - (n - 1) / 2 * 38, 40, &s);
	}
	if (n == 10)
	{
		loadimage(&s, _T(".\\bmp\\牌墙 w 10.png"), 355, 54);
		putimage(700 - (n - 1) / 2 * 38, 40, &s);
	}
	if (n == 11)
	{
		loadimage(&s, _T(".\\bmp\\牌墙 w 11.png"), 390, 54);
		putimage(700 - (n - 1) / 2 * 38, 40, &s);
	}
	if (n == 13)
	{
		loadimage(&s, _T(".\\bmp\\牌墙 w 13.png"), 461, 54);
		putimage(700 - (n - 1) / 2 * 38, 40, &s);
	}
	if (n == 14)
	{
		loadimage(&s, _T(".\\bmp\\牌墙 w 14.png"), 496, 54);
		putimage(700 - (n - 1) / 2 * 38, 40, &s);
	}
}

void drawAlpha(IMAGE* picture, int  picture_x, int picture_y) //x为载入图片的X坐标，y为Y坐标
{

	// 变量初始化
	DWORD* dst = GetImageBuffer();    // GetImageBuffer()函数，用于获取绘图设备的显存指针，EASYX自带
	DWORD* draw = GetImageBuffer();
	DWORD* src = GetImageBuffer(picture); //获取picture的显存指针
	int picture_width = picture->getwidth(); //获取picture的宽度，EASYX自带
	int picture_height = picture->getheight(); //获取picture的高度，EASYX自带
	int graphWidth = getwidth();       //获取绘图区的宽度，EASYX自带
	int graphHeight = getheight();     //获取绘图区的高度，EASYX自带
	int dstX = 0;    //在显存里像素的角标

	// 实现透明贴图 公式： Cp=αp*FP+(1-αp)*BP ， 贝叶斯定理来进行点颜色的概率计算
	for (int iy = 0; iy < picture_height; iy++)
	{
		for (int ix = 0; ix < picture_width; ix++)
		{
			int srcX = ix + iy * picture_width; //在显存里像素的角标
			int sa = ((src[srcX] & 0xff000000) >> 24); //0xAArrggbb;AA是透明度
			int sr = ((src[srcX] & 0xff0000) >> 16); //获取RGB里的R
			int sg = ((src[srcX] & 0xff00) >> 8);   //G
			int sb = src[srcX] & 0xff;              //B
			if (ix >= 0 && ix <= graphWidth && iy >= 0 && iy <= graphHeight && dstX <= graphWidth * graphHeight)
			{
				dstX = (ix + picture_x) + (iy + picture_y) * graphWidth; //在显存里像素的角标
				int dr = ((dst[dstX] & 0xff0000) >> 16);
				int dg = ((dst[dstX] & 0xff00) >> 8);
				int db = dst[dstX] & 0xff;
				draw[dstX] = ((sr * sa / 255 + dr * (255 - sa) / 255) << 16)  //公式： Cp=αp*FP+(1-αp)*BP  ； αp=sa/255 , FP=sr , BP=dr
					| ((sg * sa / 255 + dg * (255 - sa) / 255) << 8)         //αp=sa/255 , FP=sg , BP=dg
					| (sb * sa / 255 + db * (255 - sa) / 255);              //αp=sa/255 , FP=sb , BP=db
			}
		}
	}
}

void youmianpai(int n)
{
	IMAGE s;
	if (n == 1)
	{
		loadimage(&s, _T(".\\ymp\\牌墙 d 1.png"), 39, 57);
		drawAlpha(&s, 1096, 260 - 11 * n);
	}
	if (n == 2)
	{
		loadimage(&s, _T(".\\ymp\\牌墙 d 2.png"), 45, 84);
		drawAlpha(&s, 1093, 260 - 11 * n);
	}
	if (n == 4)
	{
		loadimage(&s, _T(".\\ymp\\牌墙 d 4.png"), 60, 138);
		drawAlpha(&s, 1087, 260 - 11 * n);
	}
	if (n == 5)
	{
		loadimage(&s, _T(".\\ymp\\牌墙 d 5.png"), 68, 165);
		drawAlpha(&s, 1084, 260 - 11 * n);
	}
	if (n == 7)
	{
		loadimage(&s, _T(".\\ymp\\牌墙 d 7.png"), 83, 218);
		drawAlpha(&s, 1078, 260 - 11 * n);
	}
	if (n == 8)
	{
		loadimage(&s, _T(".\\ymp\\牌墙 d 8.png"), 90, 248);
		drawAlpha(&s, 1075, 260 - 11 * n);
	}
	if (n == 10)
	{
		loadimage(&s, _T(".\\ymp\\牌墙 d 10.png"), 98, 300);
		drawAlpha(&s, 1069, 260 - 11 * n);
	}
	if (n == 11)
	{
		loadimage(&s, _T(".\\ymp\\牌墙 d 11.png"), 105, 330);
		drawAlpha(&s, 1066, 260 - 11 * n);
	}
	if (n == 13)
	{
		loadimage(&s, _T(".\\ymp\\牌墙 d 13.png"), 120, 338);
		drawAlpha(&s, 1060, 260 - 11 * n);
	}
	if (n == 14)
	{
		loadimage(&s, _T(".\\ymp\\牌墙 d 14.png"), 128, 413);
		drawAlpha(&s, 1057, 260 - 11 * n);
	}
}

void zuomianpai(int n)
{
	IMAGE s;
	if (n == 1)
	{
		loadimage(&s, _T(".\\zmp\\牌墙 a 1.png"), 39, 57);
		drawAlpha(&s, 187, 260 - 11 * n);
	}
	if (n == 2)
	{
		loadimage(&s, _T(".\\zmp\\牌墙 a 2.png"), 45, 84);
		drawAlpha(&s, 190, 260 - 11 * n);
	}
	if (n == 4)
	{
		loadimage(&s, _T(".\\zmp\\牌墙 a 4.png"), 60, 138);
		drawAlpha(&s, 196, 260 - 11 * n);
	}
	if (n == 5)
	{
		loadimage(&s, _T(".\\zmp\\牌墙 a 5.png"), 68, 165);
		drawAlpha(&s, 199, 260 - 11 * n);
	}
	if (n == 7)
	{
		loadimage(&s, _T(".\\zmp\\牌墙 a 7.png"), 83, 218);
		drawAlpha(&s, 205, 260 - 11 * n);
	}
	if (n == 8)
	{
		loadimage(&s, _T(".\\zmp\\牌墙 a 8.png"), 90, 248);
		drawAlpha(&s, 208, 260 - 11 * n);
	}
	if (n == 10)
	{
		loadimage(&s, _T(".\\zmp\\牌墙 a 10.png"), 98, 300);
		drawAlpha(&s, 214, 260 - 11 * n);
	}
	if (n == 11)
	{
		loadimage(&s, _T(".\\zmp\\牌墙 a 11.png"), 105, 330);
		drawAlpha(&s, 217, 260 - 11 * n);
	}
	if (n == 13)
	{
		loadimage(&s, _T(".\\zmp\\牌墙 a 13.png"), 120, 338);
		drawAlpha(&s, 223, 260 - 11 * n);
	}
	if (n == 14)
	{
		loadimage(&s, _T(".\\zmp\\牌墙 a 14.png"), 128, 413);
		drawAlpha(&s, 226, 260 - 11 * n);
	}
}

void lizhibang()
{
	IMAGE s;
	if (lichi[0] + wlichi[0] >= 1)
	{
		loadimage(&s, _T(".\\lichi\\立直s.png"));
		putimage(660,510,&s);
	}
	if (lichi[1] + wlichi[1] >= 1)
	{
		loadimage(&s, _T(".\\lichi\\立直d.png"),14,100);
		drawAlpha(&s, 1055, 230);
	}
	if (lichi[2] + wlichi[2] >= 1)
	{
		loadimage(&s, _T(".\\lichi\\立直w.png"));
		putimage(660, 95, &s);
	}
	if (lichi[3] + wlichi[3] >= 1)
	{
		loadimage(&s, _T(".\\lichi\\立直a.png"), 14, 100);
		drawAlpha(&s, 330, 230);
	}
}

