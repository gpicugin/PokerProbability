#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractListModel>
#include "Cards.h"

class TableModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit TableModel(QObject *parent = nullptr);

    enum {
        cardURL = Qt::UserRole
    };

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    bool clearItemData(const QModelIndex &index) override;

    virtual QHash<int, QByteArray> roleNames() const override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;

public slots:
    void add(Card card);
    void clear();

private:
    QVector<Card> m_table;

};

#endif // TABLEMODEL_H
