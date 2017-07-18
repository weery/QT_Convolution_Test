#pragma once

#include "StructureElement.h"
#include <QImage>

enum Morhps
{
	erosion,
	dilation,
	closing,
	opening,
	boundary,
	none,
	number_of_operations,
};

static char* Morph_names[] =
{
	"Erosion",
	"Dilation",
	"Closing",
	"Opening",
	"Boundary",
	"none",
	"End Of Operations",
};

struct Apply_Morphological_Operations
{
	static void Apply_Operation(QImage* image_out, QImage* image_in, StructureElement* se, Morhps morph)
	{
		switch (morph)
		{
		case erosion:
			Apply_Erosion(image_out, image_in, se);
			break;
		case dilation:
			Apply_Dilation(image_out, image_in,se);
			break;
		case closing:
			Apply_Closing(image_out,image_in,se);
			break;
		case opening:
			Apply_Opening(image_out, image_in, se);
			break;
		case boundary:
			Apply_Boundary_Extraction(image_out,image_in,se);
			break;
		case none:
			Copy(image_out,image_in);
			break;
		default:
			break;
		}
	}

	private:
	static void Apply_Difference(QImage* image_out, QImage* ref_img1, QImage* ref_img2)
	{
		int width = ref_img1->width();
		int height = ref_img1->height();
		for (int i = 0; i < width; i++)
			for (int j = 0; j < height; j++)
			{
				int val = ref_img1->pixelColor(i, j).value() - ref_img2->pixelColor(i, j).value();
				image_out->setPixel(i, j, qRgb(val, val, val));
			}
	}

	static void Apply_Boundary_Extraction(QImage* image_out, QImage* image, StructureElement* se)
	{
		int width = image->width();
		int height = image->height();

		QImage* tempImage = new QImage(width, height, image->format());
		Apply_Erosion(tempImage, image, se);
		Apply_Difference(image_out, image, tempImage);
		delete tempImage;
	}

	static void Apply_Opening(QImage* image_out, QImage* image_in, StructureElement* se)
	{
		int width = image_in->width();
		int height = image_in->height();

		QImage* tempImage = new QImage(width, height, image_in->format());
		Apply_Erosion(tempImage, image_in, se);
		Apply_Dilation(image_out, tempImage, se);
		delete tempImage;
	}

	static void Apply_Closing(QImage* image_out, QImage* image_in, StructureElement* se)
	{
		int width = image_in->width();
		int height = image_in->height();

		QImage* tempImage = new QImage(width, height, image_in->format());
		Apply_Dilation(tempImage, image_in, se);
		Apply_Erosion(image_out, tempImage, se);
		delete tempImage;
	}

	static void Copy(QImage* image_out, QImage* image_in)
	{
		int width = image_in->width();
		int height = image_in->height();

		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < height; j++)
			{
				image_out->setPixel(i,j,image_in->pixel(i,j));
			}
		}

	}

	static void Apply_Dilation(QImage* image_out, QImage* image_in, StructureElement* se)
	{
		int width = image_in->width();
		int height = image_in->height();

		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < height; j++)
			{
				bool some_overlapping = false;
				// Stop loop if there is some overlapping
				for (int x = 0; x < se->_width && !some_overlapping; x++)
				{
					for (int y = 0; y < se->_height && !some_overlapping; y++)
					{
						int x_pos = i + se->delta_x[x][y];
						int y_pos = j + se->delta_y[x][y];

						// index outside image
						if (x_pos < 0 || x_pos >= width || y_pos < 0 || y_pos >= height)
						{
							some_overlapping = true;
							break;
						}
						if (se->SE[x][y])
							if (image_in->pixelColor(x_pos, y_pos).value() > 0)
							{
								some_overlapping = true;
							}
					}
				}

				if (some_overlapping)
					image_out->setPixel(i, j, qRgb(255, 255, 255));
				else
					image_out->setPixel(i, j, qRgb(0, 0, 0));
			}
		}
	}

	static void Apply_Erosion(QImage* image_out, QImage* image_in, StructureElement* se)
	{
		int width = image_in->width();
		int height = image_in->height();

		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < height; j++)
			{
				bool fully_contained = true;
				// Stop looping if fully_contained proved false
				for (int x = 0; x < se->_width && fully_contained; x++)
				{
					for (int y = 0; y < se->_height && fully_contained; y++)
					{
						int x_pos = i + se->delta_x[x][y];
						int y_pos = j + se->delta_y[x][y];
						
						// index outside image
						if (x_pos < 0 || x_pos >= width || y_pos < 0 || y_pos >= height)
						{
							// Zero padding?
							// fully_contained = false;
							break;
						}
						if (se->SE[x][y])
							if (image_in->pixelColor(x_pos, y_pos).value() == 0)
							{
								fully_contained = false;
							}
					}
				}

				if (fully_contained)
					image_out->setPixel(i,j,qRgb(255,255,255));
				else
					image_out->setPixel(i, j, qRgb(0,0,0));
			}
		}
	}

};