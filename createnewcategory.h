#ifndef CREATENEWCATEGORY_H
#define CREATENEWCATEGORY_H

#include <QDialog>
#include <QTableWidget>
#include <QComboBox>

class CreateNewCategory : public QDialog {
    Q_OBJECT

    QTableWidget* tableWidget;
    QComboBox* cbKind;          //выбор вида проведения соревнований для категории
    QComboBox* cbAge;           //выбор возраста для категории
    QComboBox* cbWeight;        //выбор веса для категории
    QComboBox* cbCategory;      //выбор пола (мужчины, женщины (юноши, девушки)) для категории

    QString  sportsmens;        //список спортсменов с командами и разрядами через точку с запятой

private slots:
    void btnOkClick(void);

signals:
    void ageSet(QString);
    void weightSet(QString);
    void categorySet(QString);
    void kindSet(QString);

public:
    CreateNewCategory(QString, QList<int>);
};

#endif // CREATENEWCATEGORY_H
