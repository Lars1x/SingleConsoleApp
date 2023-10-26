#pragma once
#include "windows.h"
#include <fstream>

class figure {

protected:
	int nleftx;
	int topy;
	int nrightx;
	int boty;
	int color;
	int height;
	int width;
	int nname;
	int id;
public:
	figure() {
		id = 0;
		setposition(0, 0, 0, 0);
		color = 0;
		nname = 0;
	}

	int getcenterX() { return (nleftx + nrightx) / 2; }
	int getcenterY() { return (topy + boty) / 2; }
	int getid() { return id; }
	int getnname() { return nname; }
	int getleftx() { return nleftx; }
	int getrightx() { return nrightx; }
	int gettopy() { return topy;}
	int getboty() {return boty;	}
	int getcolor() {return color;}
	int getheight() {return height;}
	int getwidth() { return width; }
		
	void setposition(int xleft, int ytop, int xright, int ybot) {
		nleftx = xleft;
		topy = ytop;
		nrightx = xright;
		boty = ybot;
		height = ybot - ytop;
		width = nrightx - nleftx;
	}

	void setcolor(int color) { this->color = color; }
	void setwidth(int width) {
		this->width = width;
		nrightx = nleftx + width;
	}
	void setheight(int height) {
		this->height = height;
		boty = topy - height;
	}

	virtual void setcenter(int x, int y) {
		setposition(x - width / 2, y + height / 2, x + width / 2, y - height / 2);
	}

	virtual int save(ofstream& stream) {
		if (stream) {
			int cursor;
			stream << nname << '\n'
				<< id << '\n'
				<< nleftx << '\n'
				<< topy << '\n'
				<< nrightx << '\n'
				<< boty << '\n'
				<< width << '\n'
				<< height << '\n'
				<< color << '\n';
			cursor = stream.tellp();
			return cursor;
		}
		return 0;
	}

	virtual int load(istream& stream, figure* f = NULL, figure* f2 = NULL) {
		if (stream)
		{
			int cursor = 0;
			stream >> id
				>> nleftx
				>> topy
				>> nrightx
				>> boty
				>> width
				>> height
				>> color;
			return cursor;
		}
		return 0;
	}

	virtual void draw(bool drawnum = true) = 0;

	void drawnumber(bool draw = true) {
		if (draw == true) {
			HDC hdc = GetDC(GetConsoleWindow());
			char* nums = new char[3];
			memset(nums, 0, 3);
			sprintf_s(nums, sizeof(nums) * 3, "%d", id);
			TextOutA(hdc, getcenterX(), getcenterY(), nums, id < 10 ? 2 : 3);
		}
	}
};

class сrectangle :public figure {
public:
	void draw(bool drawnum = true) {
		HDC hdc = GetDC(GetConsoleWindow());
		POINT p[5];
		LOGBRUSH lpBrush;
		lpBrush.lbColor = color;
		lpBrush.lbStyle = BS_SOLID;
		HBRUSH hBrush = CreateBrushIndirect(&lpBrush);
		HPEN hPen = CreatePen(PS_SOLID, 3, RGB(255, 255, 255));
		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);
		Rectangle(hdc, nleftx, topy, nrightx, boty);
		drawnumber(drawnum);
		DeleteObject(hBrush);
		DeleteObject(hPen);
	}
	сrectangle(int id, int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0) {
		this->id = id;
		nname = 1;
		setposition(x1, y1, x2, y2);
		setposition(x1, y1, x2, y2);
		setcolor(RGB(255, 0, 0));
	}
};

class сtriangle :public figure {
public:
	void draw(bool drawnum = true) {
		POINT p[4];
		HDC hdc = GetDC(GetConsoleWindow());
		LOGBRUSH lpBrush;
		lpBrush.lbColor = color;
		lpBrush.lbStyle = BS_SOLID;
		HBRUSH hBrush = CreateBrushIndirect(&lpBrush);
		HPEN hPen = CreatePen(PS_SOLID, 3, RGB(255, 255, 255));
		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);
		p[0].x = nleftx - (nleftx - nrightx) / 2;
		p[0].y = topy;
		p[1].x = nrightx;
		p[1].y = boty;
		p[2].x = nleftx;
		p[2].y = boty;
		p[3].x = nleftx - (nleftx - nrightx) / 2;
		p[3].y = topy;
		//Polyline(hdc, p, 4);
		Polygon(hdc, p, 4);
		drawnumber(drawnum);
		DeleteObject(hBrush);
		DeleteObject(hPen);
	}
	void setcenter(int x, int y) {
		setposition(x - width / 2, y - height * 2 / 3, x + width / 2, y + height / 3);
	}
	int getcentery() {
		return (topy + boty + boty) / 3;
	}

	сtriangle(int id, int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0) {
		this->id = id;
		nname = 2;
		setposition(x1, y1, x2, y2);
		setcolor(RGB(0, 175, 175));
	}
};

class сellipse :public figure {
public:
	void draw(bool drawnum = true) {
		HDC hdc = GetDC(GetConsoleWindow());
		LOGBRUSH lpBrush;
		lpBrush.lbColor = color;
		lpBrush.lbStyle = BS_SOLID;
		HBRUSH hBrush = CreateBrushIndirect(&lpBrush);
		HPEN hPen = CreatePen(PS_SOLID, 3, RGB(255, 255, 255));
		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);
		Ellipse(hdc, nleftx, topy, nrightx, boty);
		drawnumber(drawnum);
		DeleteObject(hBrush);
		DeleteObject(hPen);
	}
	сellipse(int id, int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0) {
		this->id = id;
		nname = 3;
		setposition(x1, y1, x2, y2);
		setcolor(RGB(0, 0, 150));
	}
};
class Line :public figure {
private:
	figure* figur, * figur1;
public:
	Line() {
		nname = 4;
		color = RGB(255, 255, 255);
		figur = NULL; figur1 = NULL;
	}
	Line(figure* f, figure* f1) {
		nname = 4;
		figur = f;
		color = RGB(255, 255, 255);
		figur1 = f1;
		if (figur != NULL) {
			nleftx = f->getcenterX();
			topy = f->getcenterY();
		}
		if (figur1 != NULL) {
			nrightx = f1->getcenterX();
			boty = f1->getcenterY();
		}
	}
	void update() {
		if (figur != NULL) {
			nleftx = figur->getcenterX();
			topy = figur->getcenterY();
		}
		if (figur1 != NULL) {
			nrightx = figur1->getcenterX();
			boty = figur1->getcenterY();
		}
	}
	void draw(bool drawnum = false) {
		update();
		HDC hdc = GetDC(GetConsoleWindow());
		HPEN hpenold = 0, hpenW = CreatePen(PS_SOLID, 4, color);
		hpenold = (HPEN)SelectObject(hdc, hpenW);
		MoveToEx(hdc, nleftx, topy, NULL);
		LineTo(hdc, nrightx, boty);
		SelectObject(hdc, hpenold);
		DeleteObject(hpenW);
		DeleteObject(hpenold);
	}
	int save(ofstream& stream) {
		if (stream) {
			int cursor;
			stream
				<< nname << '\n'
				<< figur->getid() << '\n'
				<< figur1->getid() << '\n';
			/*
				<< id << '\n'
				<< nleftx << '\n'
				<< topy << '\n'
				<< nrightx << '\n'
				<< boty << '\n'
				<< width << '\n'
				<< height << '\n'
				<< color << '\n';*/
			cursor = stream.tellp();
			return cursor;
		}
		return 0;
	}

	virtual int load(istream& stream, figure* f, figure* f1) {
		figur = f;
		figur1 = f1;
		if (figur != NULL) {
			nleftx = f->getcenterX();
			topy = f->getcenterY();
		}
		if (figur1 != NULL) {
			nrightx = f1->getcenterX();
			boty = f1->getcenterY();
		}
		if (stream)
		{
			int cursor = 0;
			stream
				>> id
				>> nleftx
				>> topy
				>> nrightx
				>> boty
				>> width
				>> height
				>> color;
			//cursor = stream.tellp();
			return cursor;
		}
		return 0;
	}
	void setfigur(figure* f) { figur = f; }
	void setfigur1(figure* f) { figur1 = f; }
};


class FigurManager {
private:
	figure** nFigures;
	int figurecount;
	int figureID;
public:
	FigurManager() {
		figureID = 0;
		figurecount = 0;
	}
	void ADDellipse(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0) {
		nFigures = (figure**)realloc(nFigures, sizeof(figure) * (figurecount + 1));
		nFigures[figurecount] = new сellipse(figurecount, x1, y1, x2, y2);
		figurecount++;

	}
	void ADDtriangle(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0) {

		nFigures = (figure**)realloc(nFigures, sizeof(figure) * (figurecount + 1));
		nFigures[figurecount] = new сtriangle(figurecount, x1, y1, x2, y2);
		figurecount++;
	}
	void ADDrectangle(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0) {

		nFigures = (figure**)realloc(nFigures, sizeof(figure) * (figurecount + 1));
		nFigures[figurecount] = new сrectangle(figurecount, x1, y1, x2, y2);
		figurecount++;
	}
	void ADDline(int figure1 = 0, int figure2 = 0) {
		nFigures = (figure**)realloc(nFigures, sizeof(figure) * (figurecount + 1));
		nFigures[figurecount] = new Line(nFigures[figure1], nFigures[figure2]);
		figurecount++;
	}
	void Moving(int figurenumber, int centerx, int centery) {
		if (figurenumber >= figurecount) return;

		int color = nFigures[figurenumber]->getcolor();
		nFigures[figurenumber]->setcolor(0);
		nFigures[figurenumber]->draw(false);
		nFigures[figurenumber]->setcolor(color);
		nFigures[figurenumber]->setcenter(centerx, centery);

	}
	void MoveAll(char pnKey) {
		if (pnKey == 75)
			for (int i = figurecount - 1; i > -1; i--)
				Moving(i, nFigures[i]->getcenterX() - 1, nFigures[i]->getcenterY());
		if (pnKey == 72)
			for (int i = figurecount - 1; i > -1; i--)
				Moving(i, nFigures[i]->getcenterX(), nFigures[i]->getcenterY() - 1);
		if (pnKey == 77)
			for (int i = figurecount - 1; i > -1; i--)
				Moving(i, nFigures[i]->getcenterX() + 1, nFigures[i]->getcenterY());
		if (pnKey == 80)
			for (int i = figurecount - 1; i > -1; i--)
				Moving(i, nFigures[i]->getcenterX(), nFigures[i]->getcenterY() + 1);
	}
	void selectfigure(int figurename = 0) { this->figureID = figurename; }
	void DrawFig() {
		if (figureID == 0) {
			for (int i = 0; i < figurecount; i++)
				if (nFigures[i]->getnname() == 4)
					nFigures[i]->draw();
			for (int i = 0; i < figurecount; i++)
				if (nFigures[i]->getnname() != 4)
					nFigures[i]->draw();
		}
		else for (int i = 0; i < figurecount; i++)
			if (nFigures[i]->getnname() == figureID)
				nFigures[i]->draw();
	}
	int getfigurecount() { return figurecount; }
};




























/*class CTringle {
private:
	int nX1, nY1, nX2, nY2;		//координаты объекта в пространстве
	//int color;					//цвет фигуры
	//int colorpen;				//цвет контура
protected:
public:
	CTringle() { nX1 = 0; nY1 = 0; nX2 = 0; nY2 = 0; /*SetColorPen(65535); }
	CTringle(int pnX, int pnY, short Width=75, short Height = 75) {
		nX1 = pnX; nY1 = pnY;			//координаты левого верхнего угла
		nX2 = nX1 + Width; nY2 = nY1 + Height;			//координаты нижнего правого угла
		//SetColor(color);
		//SetColorPen(colorpen);
	}

	int GetX1() { return nX1; }
	int GetY1() { return nY1; }
	int GetX2() { return nX2; }
	int GetY2() { return nY2; }
	//int GetColor() { return color; }
	//int GetColorPen() { return colorpen; }
	int GetWidth() { return nX2 - nX1; }
	int GetHeight() { return nY2 - nY1; }
	int SetWidth(short Width) { nX2 = nX1 + Width; }
	int SetHeight(short Height) { nY2 = nY1 + Height; }
	//int SetColor(int nCol) { this->color = color; }
	//int SetColorPen(int pcolor) {this->colorpen = pcolor; }

	void SetLeftUp(int pnX, int pnY) {
		nX1 = pnX; nY1 = pnY;
	}
	void SetRightDown(int pnX, int pnY) {
		nX2 = pnX; nY2 = pnY;
	}

	int Draw() {
		HDC hdc = GetDC(GetConsoleWindow());
		POINT p[4];
		p[0].x = nX1 + GetWidth() / 2; p[0].y = nY1;
		p[1].x = nX2; p[1].y = nY2;
		p[2].x = nX1; p[2].y = nY2;
		p[3].x = nX1 + GetWidth() / 2; p[3].y = nY1;

		LOGBRUSH lpBrush;
		lpBrush.lbColor = RGB(255,0,0);
		lpBrush.lbStyle = BS_SOLID;
		HBRUSH hBrush = CreateBrushIndirect(&lpBrush);
		HPEN hPen = CreatePen(PS_SOLID, 3, RGB(255, 255, 255));
		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);
		Polygon(hdc, p, 4);
		return 0;
	}
};

class CEllipse {
private:
	int nX1, nY1, nX2, nY2;		//координаты объекта в пространстве
protected:
public:
	CEllipse() { nX1 = 0, nY1 = 0, nX2 = 0, nY2 = 0; }
	CEllipse(int pnX, int pnY, short Width = 75, short Height =75) {
		nX1 = pnX; nY1 = pnY;			//координаты левого верхнего угла
		nX2 = nX1 + Width; nY2 = nY1 + Height;			//координаты нижнего правого угла
	}

	int GetX1() { return nX1; }
	int GetY1() { return nY1; }
	int GetX2() { return nX2; }
	int GetY2() { return nY2; }
	void SetLeftUp(int pnX, int pnY) {
		nX1 = pnX; nY1 = pnY;
	}
	void SetRightDown(int pnX, int pnY) {
		nX2 = pnX; nY2 = pnY;
	}

	int Draw() {
		HDC hdc = GetDC(GetConsoleWindow());
		LOGBRUSH lpBrush;
		lpBrush.lbColor = RGB(0, 255, 0);
		lpBrush.lbStyle = BS_SOLID;
		HBRUSH hBrush = CreateBrushIndirect(&lpBrush);
		HPEN hPen = CreatePen(PS_SOLID, 3, RGB(255, 255, 255));
		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);

		Ellipse(hdc, nX1, nY1, nX2, nY2);
		return 0;
	}
};

class CRectangle {
private:
	int nX1, nY1, nX2, nY2;		//координаты объекта в пространстве
protected:
public:
	CRectangle() { nX1 = 0, nY1 = 0, nX2 = 0, nY2 = 0; }
	CRectangle(int pnX, int pnY, short Width = 75, short Height = 75) {
		nX1 = pnX; nY1 = pnY;			//координаты левого верхнего угла
		nX2 = nX1 + Width; nY2 = nY1 + Height;			//координаты нижнего правого угла
	}

	int GetX1() { return nX1; }
	int GetY1() { return nY1; }
	int GetX2() { return nX2; }
	int GetY2() { return nY2; }
	void SetLeftUp(int pnX, int pnY) {
		nX1 = pnX; nY1 = pnY;
	}
	void SetRightDown(int pnX, int pnY) {
		nX2 = pnX; nY2 = pnY;
	}

	int Draw() {
		HDC hdc = GetDC(GetConsoleWindow());
		LOGBRUSH lpBrush;
		lpBrush.lbColor = RGB(0, 0, 255);
		lpBrush.lbStyle = BS_SOLID;
		HBRUSH hBrush = CreateBrushIndirect(&lpBrush);
		HPEN hPen = CreatePen(PS_SOLID, 3, RGB(255, 255, 255));
		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);

		Rectangle(hdc, nX1, nY1, nX2, nY2);
		return 0;
	}

};*/