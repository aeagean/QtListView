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
