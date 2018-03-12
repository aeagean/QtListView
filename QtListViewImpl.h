#ifndef CPP_QT_LISTVIEW_IMPL_H
#define CPP_QT_LISTVIEW_IMPL_H

#include "QtListView.h"
#include <QDebug>

template <class M>
int QtListView<M>::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_itemList.size();
}

template <class M>
QVariant QtListView<M>::data(const QModelIndex &index, int role) const
{
    if (role == ModelDataRole) {
        const M * item = m_itemList.at(index.row());
        return QVariant::fromValue((QObject *)item);
    }

    return QVariant();
}

template <class M>
QVariant QtListView<M>::at(int index)
{
    if (index < 0 || index >= m_itemList.size())
        return QVariant();

    return QVariant::fromValue((QObject *) m_itemList.at(index));
}


template <class M>
QVariant QtListView<M>::last()
{
    if (m_itemList.size() > 0) {
        return QVariant::fromValue((QObject *)m_itemList.last());
    }
    return QVariant();
}

template <class M>
int QtListView<M>::size()
{
    return m_itemList.size();
}

template <class M>
const QList<M *> QtListView<M>::getItemList()
{
    return m_itemList;
}

template <class M>
void QtListView<M>::notifyAppend(M *item)
{
    int pos = m_itemList.size();

    beginInsertRows(QModelIndex(), pos, pos);
    m_itemList.append(item);
    endInsertRows();
}

template <class M>
void QtListView<M>::notifyRemove(int index)
{
    if (index < 0 || index >= m_itemList.size())
        return;

    beginRemoveRows(QModelIndex(), index, index);

    M *item = m_itemList.at(index);
    m_itemList.removeAt(index);
    delete item;
    endRemoveRows();
}

template <class M>
void QtListView<M>::notifyResetList(QList<M *> & itemList)
{
    for (int i = 0; (i < m_itemList.size()) && (i < itemList.size()); i++) {
        *m_itemList.at(i) = *itemList.at(i);
    }

    if (m_itemList.size() < itemList.size()) {
        // add new items
        int pos = m_itemList.size();

        beginInsertRows(QModelIndex(), pos, itemList.size() - 1);

        for (int i = pos; i < itemList.size(); i++) {
            M *newItem = new M(this);
            *newItem = *itemList.at(i);
            m_itemList.append(newItem);
        }

        endInsertRows();

    }
    else if (m_itemList.size() > itemList.size()) {
        // del outsize items

        beginRemoveRows(QModelIndex(), itemList.size(), m_itemList.size() - 1);

        while (m_itemList.size() > itemList.size()) {
            M *item = m_itemList.last();
            m_itemList.removeLast();
            delete item;
        }

        endRemoveRows();

    }

    for (int i = 0; i < itemList.size(); i++) {
        delete itemList[i];
    }

    beginResetModel();
    itemList.clear();
    endResetModel();
}

#endif // CPP_QT_LISTVIEW_IMPL_H

