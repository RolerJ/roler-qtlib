#pragma once

#include "roler/roler_global.h"

#include <QLineEdit>

namespace roler {

class ROLER_EXPORT PasswordLineEdit : public QLineEdit {
    Q_OBJECT

public:
    PasswordLineEdit(QWidget *parent = nullptr);
    ~PasswordLineEdit() override;

    void setSwitchIcons(const QIcon &show_icon, const QIcon &hide_icon);
    void getSwitchIcons(QIcon *show_icon, QIcon *hide_icon);

private:
    void init();

private:
    QAction *m_show;
    QAction *m_hide;
};

}  // namespace roler
