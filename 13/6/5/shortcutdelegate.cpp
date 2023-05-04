#include "shortcutdelegate.h"

#include <QDebug>

QWidget *ShortcutDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QString field = index.model()->headerData(index.column(), Qt::Horizontal).toString();
    if(field == "Shortcut") {
        return new QLineEdit(parent);
    }
    return SUPER::createEditor(parent, option, index);
}

void ShortcutDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QVariant val = index.data(Qt::EditRole);
    QLineEdit* lineEditor = qobject_cast<QLineEdit*>(editor);
    if(lineEditor != nullptr) {
        QString shortcut = val.toString();
        lineEditor->setText(shortcut);
    }
}

void ShortcutDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QLineEdit* lineEditor = qobject_cast<QLineEdit*>(editor);
    if(lineEditor != nullptr) {
        QKeySequence shortcut = QKeySequence::fromString(lineEditor->text());
        model->setData(index, shortcut, Qt::EditRole);
        return;
    }
    SUPER::setModelData(editor, model, index);
    return;
}

