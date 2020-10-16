#include "GraphicsEllipseItem.h"


GraphicsEllipseItem::GraphicsEllipseItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent):
    QGraphicsEllipseItem(x,y,width,height,parent)
{
    qDebug()<<x<<y<<width<<height;    setFlags(QGraphicsItem::ItemIsSelectable|
                                               QGraphicsItem::ItemIsMovable|
                                               QGraphicsItem::ItemSendsGeometryChanges|
                                               QGraphicsItem::ItemIsFocusable);//设定选型
    setAcceptHoverEvents(true);//接受hover事件
    m_bIsResizing=0;
    creatCircle();
}

void GraphicsEllipseItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //QChart::paint(0,0,widget);
    QGraphicsEllipseItem::paint(painter,option,widget);

    prepareGeometryChange();
    //qDebug("调用MyChartItem::paint");
    QStyleOptionGraphicsItem op;
    if (option->state & QStyle::State_Selected) {//如果被选中的话
        //qDebug("画边框");
        //qDebug()<<geometry();
        painter->setRenderHint(QPainter::Antialiasing, true);
        if(selectColor==nullptr){
            painter->setPen(Qt::blue);//设置默认选择框颜色
        }else{
            painter->setPen(selectColor);//设置默认选择框颜色
        }
        double radius=5;//小圆圈的半径
        setCircleVisible(true);
        setCirclePos();
        painter->drawRect(boundingRect().adjusted(0,0,0,0));
        painter->setPen(Qt::red);
        painter->setRenderHint(QPainter::Antialiasing, false);  // 重点
    }else{
        setCircleVisible(false);
    }
}

void GraphicsEllipseItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug()<<event;
    if(event->button() == Qt::LeftButton){
        int type=IsInResizeArea(event->pos());
        if(type!=0){
            m_bIsResizing = type;//在区域中按了左键，进入改变大小的状态
            qDebug() <<"调整大小中";
            event->accept();

        }else if(event->modifiers() == Qt::ControlModifier){
            event->ignore();
            setSelected(true);
            qDebug() <<"左键点击选中了一个chart！";
            QGraphicsItem::mousePressEvent(event);
        }else{
            setSelected(true);
            //setGeometry(geometry().adjusted(30,5,0,0));

            qDebug() <<"左键点击选中了一个chart！";
            QGraphicsItem::mousePressEvent(event);
            event->accept();
        }
    }else if(event->button() == Qt::RightButton){
        //显示属性窗口
        qDebug() << "右键了一个chart";
        event->ignore();
    }
}

void GraphicsEllipseItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (m_bIsResizing)
    {
        QRectF newPlace=getNewPlace(m_bIsResizing,pos(),event->pos());
        qDebug()<<"ldfrect"<<newPlace;
        setPos(newPlace.x(),newPlace.y());
        newPlace=mapFromScene(newPlace).boundingRect();
        qDebug()<<"rect"<<newPlace;
        qDebug()<<"bounding"<<boundingRect();
        setRect(newPlace);//改变大小
    }
    else
    {
        QGraphicsItem::mouseMoveEvent(event);
    }
}

void GraphicsEllipseItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && (m_bIsResizing!=0))
        m_bIsResizing = 0;//松开后不再改变大小状态
    else
        QGraphicsItem::mouseReleaseEvent(event);
}

void GraphicsEllipseItem::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
    int type=IsInResizeArea(event->pos());
    //qDebug()<<type;
    if (m_bIsResizing || (type!=0) && isSelected()){
        switch (type) {
        case 31:
            setCursor(Qt::SizeBDiagCursor);
            break;
        case 32:
            setCursor(Qt::SizeVerCursor);
            break;
        case 33:
            setCursor(Qt::SizeFDiagCursor);//如果在对应的区域里且是选中状态，则改变指针样式
            break;
        case 21:
            setCursor(Qt::SizeHorCursor);
            break;
        case 23:
            setCursor(Qt::SizeHorCursor);
            break;
        case 11:
            setCursor(Qt::SizeFDiagCursor);
            break;
        case 12:
            setCursor(Qt::SizeVerCursor);
            break;
        case 13:
            setCursor(Qt::SizeBDiagCursor);
            break;
        default:
            setCursor(Qt::ArrowCursor);
            break;
        }
    }
    else{
        setCursor(Qt::ArrowCursor);

    }
    QGraphicsItem::hoverMoveEvent(event);
}

void GraphicsEllipseItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug()<<"双击";
    SLOT_openAttributeWidget();
}
void GraphicsEllipseItem::creatCircle()
{
    QRectF rect=QRectF(0,0,10,10);
    circle11=new QGraphicsEllipseItem(rect,this);
    circle11->setVisible(false);
    circle12=new QGraphicsEllipseItem(rect,this);
    circle12->setVisible(false);
    circle13=new QGraphicsEllipseItem(rect,this);
    circle13->setVisible(false);
    circle21=new QGraphicsEllipseItem(rect,this);
    circle21->setVisible(false);
    circle23=new QGraphicsEllipseItem(rect,this);
    circle23->setVisible(false);
    circle31=new QGraphicsEllipseItem(rect,this);
    circle31->setVisible(false);
    circle32=new QGraphicsEllipseItem(rect,this);
    circle32->setVisible(false);
    circle33=new QGraphicsEllipseItem(rect,this);
    circle33->setVisible(false);
}

void GraphicsEllipseItem::setCircleVisible(bool vis)
{
    if(vis){
        if(circle11->isVisible())
            return;
        circle11->setVisible(true);
        circle12->setVisible(true);
        circle13->setVisible(true);
        circle21->setVisible(true);
        circle23->setVisible(true);
        circle31->setVisible(true);
        circle32->setVisible(true);
        circle33->setVisible(true);
    }else{
        if(!circle11->isVisible())
            return;
        circle11->setVisible(false);
        circle12->setVisible(false);
        circle13->setVisible(false);
        circle21->setVisible(false);
        circle23->setVisible(false);
        circle31->setVisible(false);
        circle32->setVisible(false);
        circle33->setVisible(false);
    }
}

void GraphicsEllipseItem::setCirclePos()
{
    double radius=5;//小圆圈的半径
    QRectF circleRect=QRectF(0,0,2*radius,2*radius);//决定圆形的矩形
    double width=boundingRect().width();
    double height=boundingRect().height();
    circle11->setRect(circleRect.adjusted(-radius,-radius,-radius,-radius));
    circle12->setRect(circleRect.adjusted(width/2-radius,-radius,width/2-radius,-radius));
    circle13->setRect(circleRect.adjusted(width-radius,-radius,width-radius,-radius));
    circle21->setRect(circleRect.adjusted(-radius,height/2-radius,-radius,height/2-radius));//21
    circle23->setRect(circleRect.adjusted(width-radius,height/2-radius,width-radius,height/2-radius));//23
    circle31->setRect(circleRect.adjusted(-radius,height-radius,-radius,height-radius));//31
    circle32->setRect(circleRect.adjusted(width/2-radius,height-radius,width/2-radius,height-radius));//32
    circle33->setRect(circleRect.adjusted(width-radius,height-radius,width-radius,height-radius));//33
}

int GraphicsEllipseItem::IsInResizeArea(const QPointF &pos)
{
    int radius=5;
    if(abs(pos.x()-boundingRect().width())<=radius){
        if(abs(pos.y()-boundingRect().height())<=radius){
            return 33;
        }else if(abs(pos.y()-boundingRect().height()/2)<=radius){
            return 23;
        }else if(abs(pos.y())<=radius){
            return 13;
        }
    }else if(abs(pos.x()-boundingRect().width()/2)<=radius){
        if(abs(pos.y()-boundingRect().height())<=radius){
            return 32;
        }else if(abs(pos.y())<=radius){
            return 12;
        }
    }else if(abs(pos.x())<=radius){
        if(abs(pos.y()-boundingRect().height())<=radius){
            return 31;
        }else if(abs(pos.y()-boundingRect().height()/2)<=radius){
            return 21;
        }else if(abs(pos.y())<=radius){
            return 11;
        }
    }
    return 0;
}

QRectF GraphicsEllipseItem::getNewPlace(int type, QPointF LT, QPointF RB)
{
    QRectF re=*new QRectF(0,0,0,0);
    qreal x=LT.x();
    qreal y=LT.y();
    qreal w=RB.x();
    qreal h=RB.y();
    switch (type) {
    case 31:
        re.setRect(x+w,y,boundingRect().width()-w,h);
        //qDebug()<<boundingRect().width()<<" "<<w<<" "<<x;
        break;
    case 32:
        re.setRect(x,y,boundingRect().width(),h);
        break;
    case 33:
        re.setRect(x,y,w,h);
        break;
    case 21:
        re.setRect(x+w,y,boundingRect().width()-w,boundingRect().height());
        break;
    case 23:
        re.setRect(x,y,w,boundingRect().height());
        break;
    case 11:
        re.setRect(x+w,y+h,boundingRect().width()-w,boundingRect().height()-h);
        break;
    case 12:
        re.setRect(x,y+h,boundingRect().width(),boundingRect().height()-h);
        break;
    case 13:
        re.setRect(x,y+h,w,boundingRect().height()-h);
        break;
    default:
        break;
    }
    return re;
}

void GraphicsEllipseItem::SLOT_openAttributeWidget()
{
    ChartAttribute *ca = new ChartAttribute();
    ca->show();
    attr = ca->getUi();
    QString tt = attr->comboBox_ZoomColor->currentText();
    qDebug()<<tt;
    this->connect(attr->confirmAttr,&QPushButton::clicked,
                  this,&GraphicsEllipseItem::setAttr);
}

void GraphicsEllipseItem::setCircleColor(QColor color)
{
    circle11->setBrush(color);
    circle12->setBrush(color);
    circle13->setBrush(color);
    circle21->setBrush(color);
    circle23->setBrush(color);
    circle31->setBrush(color);
    circle32->setBrush(color);
    circle33->setBrush(color);
}

QRectF GraphicsEllipseItem::boundingRect() const
{
    return rect();
}

void GraphicsEllipseItem::setAttr()
{
    selectColor.setNamedColor(attr->comboBox_SelectColor->currentText());
    zoomColor.setNamedColor(attr->comboBox_ZoomColor->currentText());
    setCircleColor(zoomColor);
    qDebug()<<"SLECT"<<selectColor;
    qDebug()<<"ZOOM"<<zoomColor;
}





