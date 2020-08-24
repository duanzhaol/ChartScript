#include "multimimedata.h"


MultiMimeData::MultiMimeData(QList<ChartItem *> items)
{
    foreach (ChartItem *item , items ) {
           m_items.append(item);//不知道可不可以
        }


}

MultiMimeData::~MultiMimeData()
{

}
