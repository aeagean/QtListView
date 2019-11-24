/**********************************************************
 * Author: Qt君
 * 微信公众号: Qt君(首发)
 * Website: qtbig.com(后续更新)
 * Email:  2088201923@qq.com
 * QQ交流群: 732271126
 * LISCENSE: MIT
 ************************************************************/
#ifndef CPP_BASE_ITEM_MODEL_H
#define CPP_BASE_ITEM_MODEL_H

#include <QObject>

class BaseItemModel : public QObject
{
    Q_OBJECT
public:
    BaseItemModel(QObject* parent = 0) : QObject(parent) { }

    virtual void operator = (BaseItemModel &item) { Q_UNUSED(item); }
};

#endif // CPP_BASE_ITEM_MODEL_H
