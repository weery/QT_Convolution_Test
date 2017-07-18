#pragma once

#include <QObject>

class StructureElement : public QObject
{
	Q_OBJECT
public:
	StructureElement();
	~StructureElement();

	void InitializeSE(int width, int height, int center_x, int center_y);



	bool** SE;
	int** delta_x;
	int** delta_y;
	int _width, _height, _center_x, _center_y;
private:

signals:
	void SE_changed();

	public slots:
	void toggleSE(int x, int y);

};