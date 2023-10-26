#pragma once
#define DEF_COLOR_TEXT 15
#define DEF_COLOR_BACKGROUND 0


void SetColor(int text = DEF_COLOR_TEXT, int bg = DEF_COLOR_BACKGROUND);
void SetCursor(int pnRow, int pnCol);


typedef enum enColors {
	CL_BLACK,			//0
	CL_BLUE,			//1
	CL_GREEN,			//2
	CL_CYAN,			//3
	CL_RED,				//4
	CL_PURPLE,			//5
	CL_YELLOW,			//6
	CL_WHITE,			//7
	CL_GRAY,			//8
	CL_LIGHT_BLUE,		//9
	CL_LIGHT_GREEN,		//10
	CL_LIGHT_CYAN,		//11
	CL_LIGHT_RED,		//12
	CL_LIGHT_PURPLE,	//13
	CL_LIGHT_YELLOW,	//14
	CL_LIGHT_WHITE,		//15

	ר���� = 0,			//0
	�����,				//1
	�������,			//2
	�������,			//3
	�������,			//4
	�������,			//5
	����������,			//6
	������_�����,		//7
	�����,				//8
	������_�����,		//9
	������_�������,		//10
	������_�������,		//11
	������_�������,		//12
	������_�������,		//13
	������,				//14
	�����,				//15
}
COLORS, �����;