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

    return m_hands.size();
}

QVariant HandsModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    switch (role) {
    case firstCardURLRole:
        return QVariant(m_hands[index.row()].m_firstCard.m_URL);
    case secondCardURLRole:
        return QVariant(m_hands[index.row()].m_secondCard.m_URL);
    }

    return QVariant();
}

bool HandsModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        switch (role)
        {
        case firstCardURLRole:
            m_hands[index.row()].m_firstCard.m_URL = value.toString();
            break;
        case secondCardURLRole:
            m_hands[index.row()].m_secondCard.m_URL = value.toString();
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

    return Qt::ItemIsEditable;
}

void HandsModel::add(QString firstURL, QString secondURL)
{
    beginInsertRows(QModelIndex(), m_hands.size(), m_hands.size());
    Hand hand;
    hand.m_firstCard.m_URL  = firstURL;
    hand.m_secondCard.m_URL = secondURL;
    m_hands.append(hand);
    endInsertRows();

    // m_hands[0] = QString("Size: %1").arg(m_hands.size());
    // QModelIndex index = createIndex(0, 0, static_cast<void *>(0));
    // emit dataChanged(index, index);
}

void HandsModel::clear()
{
    beginRemoveRows(QModelIndex(), 0, m_hands.size() -1);
    m_hands.clear();
    endRemoveRows();
}

QHash<int, QByteArray> HandsModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[firstCardURLRole] = "firstCardURL";
    roles[secondCardURLRole] = "secondCardURL";
    return roles;
}
