#ifndef GAUSSEIDEL_H
#define GAUSSEIDEL_H

#include <QMainWindow>

namespace Ui {
class Gausseidel;
}

class Gausseidel : public QMainWindow
{
    Q_OBJECT

public:
    explicit Gausseidel(QWidget *parent = 0);
    ~Gausseidel();
    double errora;
    double x1,x2,x3,x4;
    double matriz[4][4];
    double indep [4][1];
    double tempo[1][4], tempo2[1][4];
    double ind1,ind2;
    int interacion, icont;
    int i,j;
    int max;
public slots:
    void ejecutar();
    void limpiar();
    void agregar();


private:
    Ui::Gausseidel *ui;
};

#endif // GAUSSEIDEL_H
