#ifndef CPP_QT_LISTVIEW_IMPL_H
#define CPP_QT_LISTVIEW_IMPL_H

#include "QtListView.h"
#include <QDebug>

template <class M>
int QtListView<M>::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_list.size();
}

template <class M>
QVariant QtListView<M>::data(const QModelIndex &index, int role) const
{
    if (role == ModelDataRole) {
        const M * item = m_list.at(index.row());
        return QVariant::fromValue((QObject *)item);
    }

    return QVariant();
}

template <class M>
QVariant QtListView<M>::at(int index)
{
    if (index < 0 || index >= m_list.size())
        return QVariant();

    return QVariant::fromValue((QObject *) m_list.at(index));
}

template <class M>
int QtListView<M>::size()
{
    return m_list.size();
}

template <class M>
const QList<M *> QtListView<M>::getItemList()
{
    return m_list;
}

template <class M>
void QtListView<M>::appendItem(M *item)
{
    int pos = m_list.size();

    beginInsertRows(QModelIndex(), pos, pos);
    m_list.append(item);
    endInsertRows();
}

template <class M>
void QtListView<M>::removeItem(int index)
{
    if (index < 0 || index >= m_list.size())
        return;

    beginRemoveRows(QModelIndex(), index, index);

    M *item = m_list.at(index);
    m_list.removeAt(index);
    delete item;
    endRemoveRows();
}

template <class M>
void QtListView<M>::resetList(QList<M *> & itemList)
{
    for (int i = 0; (i < m_list.size()) && (i < itemList.size()); i++) {
        *m_list.at(i) = *itemList.at(i);
    }

    if (m_list.size() < itemList.size()) {
        int pos = m_list.size();

        beginInsertRows(QModelIndex(), pos, itemList.size() - 1);

        for (int i = pos; i < itemList.size(); i++) {
            M *newItem = new M(this);
            *newItem = *itemList.at(i);
            m_list.append(newItem);
        }

        endInsertRows();

    }
    else if (m_list.size() > itemList.size()) {
        beginRemoveRows(QModelIndex(), itemList.size(), m_list.size() - 1);

        while (m_list.size() > itemList.size()) {
            M *item = m_list.last();
            m_list.removeLast();
            delete item;
        }

        endRemoveRows();
    }

    qDeleteAll(itemList);

    beginResetModel();
    itemList.clear();
    endResetModel();
}

#endif // CPP_QT_LISTVIEW_IMPL_H

