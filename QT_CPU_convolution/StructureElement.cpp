#include "StructureElement.h"

StructureElement::StructureElement()
{

}

StructureElement::~StructureElement()
{
	for (int i = 0; i < _width; i++)
	{
		delete SE[i];
		delete delta_x[i];
		delete delta_y[i];
	}
	delete SE;
	delete delta_x;
	delete delta_y;
}

void StructureElement::InitializeSE(int width, int height, int center_x, int center_y)
{
	SE = new bool*[width];
	delta_x = new int*[width];
	delta_y = new int*[width];
	for (int i = 0; i < width; i++)
	{
		SE[i] = new bool[height];
		delta_x[i] = new int[height];
		delta_y[i] = new int[height];
	}

	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
		{
			SE[i][j] = false;
			delta_x[i][j] = i - center_x;
			delta_y[i][j] = j - center_y;
		}

	SE[center_x][center_y] = true;


	_width = width;
	_height = height;
	_center_x = center_x;
	_center_y = center_y;
}

void StructureElement::toggleSE(int x, int y)
{
	if (x < _width && y < _height)
	{
		SE[x][y] = !SE[x][y];
		emit SE_changed();
	}
}