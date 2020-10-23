#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H


#include <QGraphicsView>
#include <QObject>
#include <QtCharts/QChartView>
#include <optional>

QT_BEGIN_NAMESPACE
class QWheelEvent;
QT_END_NAMESPACE
/**
 * @brief The GraphicsView class
 * 自定义的QGraphicsView，主要对鼠标位置进行滚轮缩放
 */
class GraphicsView:public QGraphicsView
{
    Q_OBJECT
public:
	explicit GraphicsView(QWidget *parent = nullptr);

	std::optional<QImage> getImage() const;
	void setImage(const std::optional<QImage> &value);
	QPixmap* getPixmap();

protected:
	void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE;

private:
	qreal scale_m;

	std::optional<QImage>image;

	// QGraphicsView interface
protected:
	virtual void drawBackground(QPainter *painter, const QRectF &rect) override;
};

#endif // GRAPHICSVIEW_H
