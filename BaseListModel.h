/**********************************************************
 * Author: Qt君
 * 微信公众号: Qt君(首发)
 * Website: qtbig.com(后续更新)
 * Email:  2088201923@qq.com
 * QQ交流群: 732271126
 * LISCENSE: MIT
 ************************************************************/
#ifndef CPP_BASE_LIST_MODEL_H
#define CPP_BASE_LIST_MODEL_H

#include <QAbstractListModel>

class BaseListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles {
        ModelDataRole = Qt::UserRole + 1
    };

    BaseListModel(QObject* parent = 0)
        : QAbstractListModel(parent) {
    }

private:
    QHash<int,QByteArray> roleNames() const {
        QHash<int, QByteArray> roles;
        roles[ModelDataRole] = "modelData";
        return roles;
    }
};

#endif // BASELISTMODEL_H
