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

	в╗пмши = 0,			//0
	яхмхи,				//1
	гекемши,			//2
	цнксани,			//3
	йпюямши,			//4
	кхкнбши,			//5
	йнпхвмебши,			//6
	яберкн_яепши,		//7
	яепши,				//8
	яберкн_яхмхи,		//9
	яберкн_гекемши,		//10
	яберкн_цнксани,		//11
	яберкн_йпюямши,		//12
	яберкн_кхкнбши,		//13
	фекрши,				//14
	аекши,				//15
}
COLORS, жберю;