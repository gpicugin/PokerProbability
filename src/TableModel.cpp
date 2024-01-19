#include "TableModel.h"

TableModel::TableModel(QObject *parent)
    : QAbstractListModel(parent)
{}

int TableModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    return m_table.size();
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    switch (role) {
    case cardURL:
        return QVariant(m_table[index.row()].m_URL);
    }
    // FIXME: Implement me!
    return QVariant();
}

bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        switch (role) {
        case cardURL:
            m_table[index.row()].m_URL = value.toString();
        }
        emit dataChanged(index, index, {role});
        return true;
    }
    return false;
}

bool TableModel::clearItemData(const QModelIndex &index)
{
    m_table.clear();
    emit dataChanged(index, index);
    return QAbstractListModel::clearItemData(index);
}

QHash<int, QByteArray> TableModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[cardURL] = "url";
    return roles;
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable; // FIXME: Implement me!
}

void TableModel::add(Card card)
{
    beginInsertRows(QModelIndex(), m_table.size(), m_table.size());
    m_table.append(card);
    endInsertRows();

}

void TableModel::clear()
{
    beginRemoveRows(QModelIndex(), 0, m_table.size() -1);
    m_table.clear();
    endRemoveRows();
}
