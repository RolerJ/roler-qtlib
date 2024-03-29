#pragma once

#include "roler/roler_global.h"

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

namespace roler {

class ROLER_EXPORT TagLabel : public QWidget {
    Q_OBJECT

public:
    TagLabel(QWidget *parent = nullptr);

    void setText(const QString &text);
    QString text() const;
    void setCloseable(bool closeable);
    bool isCloseable() const;

protected:
    void resizeEvent(QResizeEvent *e) override;

private:
    void init();

signals:
    void closeTag();

private:
    QLabel *m_label;
    QPushButton *m_delete_btn;
};

class ROLER_EXPORT TagWidget : public QWidget {
    Q_OBJECT

public:
    TagWidget(QWidget *parent = nullptr);
    ~TagWidget() override;

    void setCountPerRow(int count);
    int countPerRow() const;

    void setLabelList(const QStringList &list);
    QStringList labelList() const;

    void clear();

private:
    void updateTags();
    void addTag(const QString &text);

private slots:
    void addTag();

signals:
    void tagRemoved();

private:
    QLineEdit *m_inputLineEdit;
    int m_count_per_row;
    QVBoxLayout *m_v_layout;
    QVector<TagLabel *> m_tag_vec;
};

}  // namespace roler
