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
