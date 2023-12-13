#ifndef HANDSMODEL_H
#define HANDSMODEL_H

#include <QAbstractListModel>

struct Hand {
    QString firstCardURL;
    QString secondCardUrl;
    Hand(QString url1, QString url2) {
        firstCardURL    = url1;
        secondCardUrl   = url2;
    }
};

class HandsModel : public QAbstractListModel
{
    Q_OBJECT

public: 

    explicit HandsModel(QObject *parent = nullptr);

    enum {
        firstCardURLRole = Qt::UserRole,
        secondCardURLRole
    };

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void add(QString url1, QString url2);

private:
    QVector<Hand> m_hands;
};

#endif // HANDSMODEL_H
