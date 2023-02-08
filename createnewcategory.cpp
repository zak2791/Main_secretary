 #include "createnewcategory.h"
#include <QDebug>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QApplication>
#include <QClipboard>

CreateNewCategory::CreateNewCategory(QString s, QList<int> l){
    qDebug()<<s;

    setMaximumSize(600, 600);
    setMinimumSize(600, 600);
    setWindowTitle("Новая категория");

    tableWidget = new QTableWidget(this);
    tableWidget->setColumnCount(3);
    tableWidget->setHorizontalHeaderLabels( { "Спортсмен", "Разряд", "Команда" });
    tableWidget->setColumnWidth(0, 250);
    tableWidget->setColumnWidth(1, 100);
    tableWidget->setColumnWidth(2, 250);

    QList<QString> rowsFromExcel = s.split("\n");
    QString str;
    int countRows = 0;
    foreach (str, rowsFromExcel){
        QList<QString> row = str.split("\t");
        int i = row.at(0).toInt();
        //qDebug()<<"i = "<<i;
        if(i > 0){

            tableWidget->insertRow(countRows);
            qDebug()<<"tableWidget->rowCount()"<<tableWidget->rowCount();

            //int row = tableWidget->currentRow();
            //qDebug()<<"row "<<row;

            tableWidget->setItem(countRows, 0, new QTableWidgetItem(row.at(l.at(1) - 1)));
            tableWidget->setItem(countRows, 1, new QTableWidgetItem(row.at(l.at(2) - 1)));
            tableWidget->setItem(countRows, 2, new QTableWidgetItem(row.at(l.at(3) - 1)));
            //qDebug()<<"1"<<l<<row.at(l.at(1) - 1) + ";" + row.at(l.at(2) - 1) + ";" + row.at(l.at(3) - 1) + "\t";
            sportsmens.append(row.at(l.at(1) - 1) + ";" + row.at(l.at(2) - 1) + ";" + row.at(l.at(3) - 1) + "\t");

            //tableWidget->setItem(countRows, 3, new QTableWidgetItem(row.at(3)));

            countRows++;
            qDebug()<<countRows;

        }else
            break;
    }

    cbKind = new QComboBox;
    if(countRows == 8){
        cbKind->addItems({"", "утешения от полуфиналиста на 8 человек"});
                          //"круговая на 6 человек"});
    }else if(countRows == 7){
        cbKind->addItems({"", "утешения от полуфиналиста на 8 человек"});
                          //"круговая на 6 человек"});
    }else if(countRows == 6){
        cbKind->addItems({"", "утешения от полуфиналиста на 8 человек",
                          "круговая на 6 человек"});
    }else if(countRows == 5){
        cbKind->addItems({"", "утешения от полуфиналиста на 8 человек",
                      "круговая на 5 человек"});
    }else{
        cbKind->addItems({""});
    }
    connect(cbKind, SIGNAL(currentTextChanged(QString)), this, SIGNAL(kindSet(QString)));

    QVBoxLayout* kindLayout = new QVBoxLayout();
    QLabel* lblKind = new QLabel("Система проведения");
    lblKind->setAlignment(Qt::AlignHCenter);
    kindLayout->addWidget(lblKind);
    kindLayout->addWidget(cbKind);

    cbAge = new QComboBox;
    cbAge->addItems({"", "12-13 лет", "14-15 лет", "16-17 лет", "18+"});
    connect(cbAge, SIGNAL(currentTextChanged(QString)), this, SIGNAL(ageSet(QString)));

    QVBoxLayout* ageLayout = new QVBoxLayout();
    QLabel* lblAge = new QLabel("Возраст");
    lblAge->setAlignment(Qt::AlignHCenter);
    ageLayout->addWidget(lblAge);
    ageLayout->addWidget(cbAge);

    cbWeight = new QComboBox;
    cbWeight->addItems({"", "21 кг", "25 кг", "27 кг", "29 кг", "32 кг", "31 кг",
                        "34 кг", "35 кг", "37 кг", "38 кг", "40 кг", "41 кг",
                        "44 кг", "44+ кг", "48 кг", "48+ кг", "52 кг", "52+ кг",
                        "53 кг", "53+ кг", "57 кг", "57+ кг", "58 кг", "58+ кг",
                        "62 кг", "62+ кг", "64 кг", "64+ кг", "67 кг", "67+ кг",
                        "70 кг", "70+ кг", "73 кг", "73+ кг", "80 кг", "80+ кг",
                        "88 кг", "97 кг", "97+ кг", "абсолютная"});
    connect(cbWeight, SIGNAL(currentTextChanged(QString)), this, SIGNAL(weightSet(QString)));

    QVBoxLayout* weightLayout = new QVBoxLayout();
    QLabel* lblWeight = new QLabel("Вес");
    lblWeight->setAlignment(Qt::AlignHCenter);
    weightLayout->addWidget(lblWeight);
    weightLayout->addWidget(cbWeight);

    cbCategory = new QComboBox;
    cbCategory->addItems({"", "мужчины", "женщины", "юниоры", "юниорки", "юноши", "девушки"});
    connect(cbCategory, SIGNAL(currentTextChanged(QString)), this, SIGNAL(categorySet(QString)));

    QVBoxLayout* genderLayout = new QVBoxLayout();
    QLabel* lblGender = new QLabel("Пол");
    lblGender->setAlignment(Qt::AlignHCenter);
    genderLayout->addWidget(lblGender);
    genderLayout->addWidget(cbCategory);

    QHBoxLayout* hLayout = new QHBoxLayout();
    hLayout->addLayout(kindLayout);
    hLayout->addLayout(ageLayout);
    hLayout->addLayout(weightLayout);
    hLayout->addLayout(genderLayout);

    QPushButton* btnOk = new QPushButton("Подтвердить");
    btnOk->setMinimumWidth(100);
    connect(btnOk, SIGNAL(clicked()), this, SLOT(btnOkClick()));

    QPushButton* btnCancel = new QPushButton("Отмена");
    btnCancel->setMinimumWidth(100);
    connect(btnCancel, SIGNAL(clicked()), this, SLOT(close()));

    QHBoxLayout* buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(btnOk);
    buttonLayout->addWidget(btnCancel);
    buttonLayout->addStretch();

    QVBoxLayout* vLayout = new QVBoxLayout();
    setLayout(vLayout);
    vLayout->addWidget(tableWidget);
    vLayout->addSpacing(10 );
    vLayout->addLayout(hLayout);
    vLayout->addSpacing(20);
    vLayout->addLayout(buttonLayout);

    setAttribute(Qt::WA_DeleteOnClose);
    setWindowModality(Qt::WindowModal);

}

void CreateNewCategory::btnOkClick(){
    QString temp = "";
    if(cbKind->currentText() == "")
        temp = "формат проведения\n";
    if(cbAge->currentText() == "")
        temp = temp + "возраст\n";
    if(cbWeight->currentText() == "")
        temp = temp + "вес\n";
    if(cbCategory->currentText() == "")
        temp = temp + "пол\n";
    if(temp != ""){
        int n = QMessageBox::warning(0, "Внимание!",
                                        "Не выбраны:\n" + temp + "Продолжить выбор?",
                                        QMessageBox::Yes | QMessageBox::No,
                                        QMessageBox::Yes);
        if(n == QMessageBox::No)
            done(QDialog::Rejected);
    }else{
        QClipboard* pcb = QApplication::clipboard();
        pcb->setText(sportsmens);
        done(QDialog::Accepted);

        QString s("");
        //foreach (QString str, *sportsmens){
        //    s = s + str + "\t";
        //}
        //qDebug()>>sportsmens;

    }
}

