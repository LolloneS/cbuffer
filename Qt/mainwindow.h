#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <iostream>
#include <string>
#include <QString>
#include <QMap>
#include <QVector>
#include <vector>
#include <fstream>
#include <iostream>

namespace Ui {
class MainWindow;
}

struct fascia_eta {
    std::string fascia;
    int uomini;
    double pcUomini;
    int donne;
    double pcDonne;
    fascia_eta() {}
    fascia_eta(std::string &f, int u, double pu, int d, double pd) : fascia(f), uomini(u), pcUomini(pu), donne(d), pcDonne(pd) {}
};

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showRegion(QVector<fascia_eta>& qv);
    QMap<std::string, QVector<fascia_eta> > regioniFasce;
    void selectRegione(std::string &s);
    void parseRegioni();


private slots:
    void on_cbRegion_currentTextChanged(const QString &arg1);

    void on_pbLoadData_clicked();

private:
    Ui::MainWindow *ui;
    void updateUI();
};


#endif // MAINWINDOW_H
