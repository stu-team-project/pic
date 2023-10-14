#pragma once

#include <QImage>
#include <QtWidgets>

#include "T_Project.h"

class OriginPicture :public QWidget 
{
	Q_OBJECT
public:
	OriginPicture(QWidget* parent = Q_NULLPTR);
	//OriginPicture(QWidget* parent = nullptr) : QWidget(parent) {
	//	// Set the size of the widget and initialize the image.
	//	setFixedSize(300, 300);
	//	image = QImage(size(), QImage::Format_RGB32);
	//	image.fill(Qt::white); // Fill the image with a white background.
	//}


	//OriginPicture();
	~OriginPicture();

	bool openImage(const QString& fileName);
	void drawSomethink();
	void setPixel(int x, int y, QColor col) { image.setPixelColor(x, y, col); };

	//void drawPicture(T_Picture& Pic);
private:
	void resizeImage(QImage* image, const QSize& newSize);

	bool modified = false;

	//QImage* img = nullptr;
	QImage image;
	QColor col = Qt::red;
	//
	//inspiration from computer graphics
	//
	//QPainter* painter = nullptr;
	//uchar* data = nullptr;
};




