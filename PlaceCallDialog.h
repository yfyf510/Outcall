#ifndef PLACECALLDIALOG_H
#define PLACECALLDIALOG_H

#include "ChooseNumber.h"
#include "SettingsDialog.h"

#include <QDialog>
#include <QSqlQueryModel>
#include <QTableView>
#include <QValidator>
#include <QKeyEvent>

class ChooseNumber;

namespace Ui {
class PlaceCallDialog;
}

class PlaceCallDialog : public QDialog
{
    Q_OBJECT

public slots:
    void receiveNumber(QString);

public:
    explicit PlaceCallDialog(QWidget *parent = 0);
    ~PlaceCallDialog();

private slots:
    void onCallButton();
    void onCancelButton();

    void onUpdate();
    void onComboBoxSelected();
    void clearEditText();

    void showNumber(const QModelIndex &);

    void on_lineEdit_returnPressed();
    void on_phoneLine_returnPressed();

    void showEvent(QShowEvent* event);
    void closeEvent(QCloseEvent* event);
    void keyPressEvent(QKeyEvent* event);

private:
    Ui::PlaceCallDialog *ui;

    ChooseNumber* chooseNumber;

    QSqlQueryModel* queryModel;

    QValidator* validator;

    QString update;
    QString number;
    QString my_number;
};

#endif // PLACECALLDIALOG_H
