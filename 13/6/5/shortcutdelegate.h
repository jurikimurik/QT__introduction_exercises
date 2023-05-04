#ifndef SHORTCUTDELEGATE_H
#define SHORTCUTDELEGATE_H


#include <QStyledItemDelegate>
#include <QStyleOptionViewItem>
#include <QLineEdit>

class ShortcutDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    typedef QStyledItemDelegate SUPER;
    ShortcutDelegate(QObject* parent = nullptr) : SUPER(parent) {}


    // QAbstractItemDelegate interface
public:
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
};

#endif // SHORTCUTDELEGATE_H
