#include "HandsModel.h"

HandsModel::HandsModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

int HandsModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
    return m_hands.size();
}

QVariant HandsModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    switch (role) {
    case firstCardURLRole:
        return QVariant(m_hands[index.row()].firstCardURL);
    case secondCardURLRole:
        return QVariant(m_hands[index.row()].secondCardUrl);
    }

    return QVariant();
}

bool HandsModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        switch (role)
        {
        case firstCardURLRole:
            m_hands[index.row()].firstCardURL = value.toString();
        case secondCardURLRole:
            m_hands[index.row()].secondCardUrl = value.toString();
            break;
        default:
            return false;
        }
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags HandsModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable; // FIXME: Implement me!
}

void HandsModel::add(QString url1, QString url2)
{
    beginInsertRows(QModelIndex(), m_hands.size(), m_hands.size());
    Hand hand(url1, url2);
    m_hands.append(hand);
    endInsertRows();

    // m_hands[0] = QString("Size: %1").arg(m_hands.size());
    // QModelIndex index = createIndex(0, 0, static_cast<void *>(0));
    // emit dataChanged(index, index);
}

QHash<int, QByteArray> HandsModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[firstCardURLRole] = "firstCardURL";
    roles[secondCardURLRole] = "secondCardURL";
    return roles;
}