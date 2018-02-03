#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    parseRegioni();
    updateUI();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showRegion(QVector<fascia_eta>& qv) {
    QString fascia, uomini, donne;
    int rows = qv.size();
    ui->tableRegion->setRowCount(rows);
    // int columns = 5;
    for (int i = 0; i < rows; ++i) {
        ui->tableRegion->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(qv[i].fascia)));
        ui->tableRegion->setItem(i, 1, new QTableWidgetItem(QString::number(qv[i].uomini)));
        ui->tableRegion->setItem(i, 2, new QTableWidgetItem(QString::number(qv[i].pcUomini, 'f', 2)));
        ui->tableRegion->setItem(i, 3, new QTableWidgetItem(QString::number(qv[i].donne)));
        ui->tableRegion->setItem(i, 4, new QTableWidgetItem(QString::number(qv[i].pcDonne, 'f', 2)));

    }
}

void MainWindow::updateUI() {
    ui->tableRegion->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QList<QString> headers;
    headers.append("Fascia");
    headers.append("Uomini");
    headers.append("% Uomini");
    headers.append("Donne");
    headers.append("% Donne");
    QStringList qHeaders(headers);
    ui->tableRegion->setHorizontalHeaderLabels(qHeaders);
    ui->tableRegion->verticalHeader()->hide();

    QMap<std::string, QVector<fascia_eta> >::iterator i, ie;
    for(i = regioniFasce.begin(), ie = regioniFasce.end(); i != ie; ++i) {
        ui->cbRegion->addItem(QString::fromStdString(i.key()));
    }
}

void MainWindow::parseRegioni() {
    QString filename = "./data.txt";
    std::ifstream is;
    is.open(filename.toStdString().c_str());
    std::string regione, fascia;
    int uomini, donne;

    if(is.is_open()) {
        is >> regione;
        while (regione != "<END>") {
            is >> fascia >> uomini >> donne;
            double xx = 100 * static_cast<double>(donne) / (uomini + donne);
            double xy = 100 * static_cast<double>(uomini) / (uomini + donne);
            if (regioniFasce.count(regione) == 0) {
                QVector<fascia_eta> qv;
                regioniFasce.insert(regione, qv);
                regioniFasce[regione].push_back(fascia_eta(fascia, uomini, xy, donne, xx));
            }
            else {
                regioniFasce[regione].push_back(fascia_eta(fascia, uomini, xy, donne, xx));
            }
            is >> regione;
        }
    }
}

std::ostream &operator<<(std::ostream &os, const fascia_eta &f) {
    os << f.fascia << " " << f.uomini << " " << f.donne;
    return os;
}

void MainWindow::on_cbRegion_currentTextChanged(const QString &arg1) {
    showRegion(regioniFasce[arg1.toStdString()]);
    ui->labRegion->setText(arg1);
}
