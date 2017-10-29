#include "gausseidel.h"
#include "ui_gausseidel.h"

Gausseidel::Gausseidel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Gausseidel)
{
    ui->setupUi(this);
    connect(ui->iniciar,SIGNAL(clicked()),this,SLOT(ejecutar()));
    connect(ui->limpiar,SIGNAL(clicked()),this,SLOT(limpiar()));
    connect(ui->agrega,SIGNAL(clicked()),this,SLOT(agregar()));
    connect(ui->Erroraceptado,SIGNAL(clicked()),this,SLOT(agregar()));
    connect(ui->Interac,SIGNAL(clicked()),this,SLOT(agregar()));
    ui->iniciar->setDisabled(true);
    ui->limpiar->setDisabled(true);
    i=0; j=0;
}
void Gausseidel::agregar(){
    ui->limpiar->setDisabled(false);
    matriz[i][0]=ui->valorx1->value();
    matriz[i][1]=ui->valorx2->value();
    matriz[i][2]=ui->valorx3->value();
    matriz[i][3]=ui->valorx4->value();
    indep[i][0]=ui->valorindep->value();
    ui->matrix->setItem(i,0,new QTableWidgetItem(ui->valorx1->text()));
    ui->matrix->setItem(i,1,new QTableWidgetItem(ui->valorx2->text()));
    ui->matrix->setItem(i,2,new QTableWidgetItem(ui->valorx3->text()));
    ui->matrix->setItem(i,3,new QTableWidgetItem(ui->valorx4->text()));
    ui->matrix->setItem(i,4,new QTableWidgetItem(ui->valorindep->text()));
    i++;
    if(i==4){
        ui->agrega->setDisabled(true);
        ui->iniciar->setDisabled(false);
        ui->Erroraceptado->setDisabled(true);
        interacion=ui->Interac->value();
        if((errora==0)&&(interacion==0)){
            ui->iniciar->setDisabled(true);
        }
            else{
            ui->iniciar->setDisabled(false);
        }
        }
    }
void Gausseidel::ejecutar(){// This slot starts the method, when the start button been clicked.
            for(i=0;i<4;i++){// This cycle analyzes if the main diagonal of the main matrix have zeros.
                if(matriz[i][i]==0){// If it haves zeros:
                    for(j=0;j<4;j++){// This cycle exchanges row positions for the x variables.
                        if(i==3){// If is the last row.
                            ind1=indep[i][0];// A temporal variable takes the value of last row independent variable.
                            ind2=indep[i-1][0];// Another temporal variable takes the value of the previous row independent variable.
                            indep[i-1][0]=ind1;// Puts the secound independent variable on next row.
                            indep[i][0]=ind2;// Puts the first independent variable on previous row.
                            tempo[0][j]=matriz[i][j];// A temporal matrix saves the last row.
                            tempo2[0][j]=matriz[i-1][j];// Another temporal matrix saves the previous row.
                            matriz[i-1][j]=tempo[0][j];// Puts the last row on the previous row.
                            matriz[i][j]=tempo2[0][j];// Puts the previos row on the last row.
                        }
                        else{// If isn't the last row:
                            ind1=indep[i][0];// A temporal variable takes the value of the detected row independent variable.
                            ind2=indep[i+1][0];// Another temporal variable takes the value of the next independent variable.
                            indep[i+1][0]=ind1;// Puts the detected row independent variable on next row.
                            indep[i][0]=ind2;// Puts the next variable on previous row.
                            tempo[0][j]=matriz[i][j];// A temporal matrix saves the detected row.
                            tempo2[0][j]=matriz[i+1][j];// Another temporal matrix saves the next row.
                            matriz[i+1][j]=tempo[0][j];// Puts the detected row on the next row.
                            matriz[i][j]=tempo2[0][j];// Puts the next row on the previous row.
                        }
                    }
                }
            }
             }
            double x=0, y=0, z=0, w=0;// Creates temporal variables, for save previous calculated values on method.
            double ex1=100, ex2=100, ex3=100, ex4=100;// Creates temporal variables ,for independent variables error.
            // The method starts with a cycle, and will stop when the independent calculated errors been small than the accepted error provided by the user.
            // Or when the iterations maximum been reached.

while((ex1>errora)&&(ex2>errora)&&(ex3>errora)&&(ex4>errora)||(icont<interacion)){
                x1=(indep[0][0]-(matriz[0][1]*x2)-(matriz[0][2]*x3)-(matriz[0][3]*x4))/(matriz[0][0]);// Calulates the value for x1.
                ex1=100*std::abs(x1-x)/(x1);// Calculates the error for the found value.
                x=x1;// A temporal variable saves the found value, it will be use in the next error calculation.
                x2=(indep[1][0]-(matriz[1][0]*x1)-(matriz[1][2]*x3)-(matriz[1][3]*x4))/(matriz[1][1]);// Calulates the value for x2.
                ex2=100*std::abs(x2-y)/(x2);// Calculates the error for the found value.
                y=x2;// A temporal variable saves the found value, it will be use in the next error calculation.
                x3=(indep[2][0]-(matriz[2][0]*x1)-(matriz[2][1]*x2)-(matriz[2][3]*x4))/(matriz[2][2]);// Calulates the value for x3.
                ex3=100*std::abs(x3-z)/(x3);// Calculates the error for the found value.
                z=x3;// A temporal variable saves the found value, it will be use in the next error calculation.
                x4=(indep[3][0]-(matriz[3][0]*x1)-(matriz[3][1]*x2)-(matriz[3][2]*x3))/(matriz[3][3]);// Calulates the value for x4.
                ex4=100*std::abs(x4-w)/(x4);// Calculates the error for the found value.
                w=x4;// A temporal variable saves the found value, it will be use in the next error calculation.
                icont++;// Sums one number to the iterations counter.
            } // The method finishes.
        void Gausseidel::limpiar(){// This slot clears all the user interface fields, when the clear button been clicked.
            //Clears all spinboxes.
            ui->valorx1->setValue(0.0);
            ui->valorx2->setValue(0.0);
            ui->valorx3->setValue(0.0);
            ui->valorx4->setValue(0.0);
            ui->valorindep->setValue(0.0);
            ui->Erroraceptado->setValue(0.0);
            ui->Interac->setValue(0.0);
            ui->matrix->clearContents();// Clears the table widget contents.
            // Clears all the LCD numbers.
            ui->valor1->display(0.0);
            ui->valor2->display(0.0);
            ui->valor3->display(0.0);
            ui->valor4->display(0.0);
            ui->Erroraceptado->display(0.0);
            ui->iniciar->setDisabled(true);// Disables the start button.
            ui->limpiar->setDisabled(false);// Enables the add button.
            ui->Erroraceptado->setDisabled(true);// The row counter goes to zero, for start over the data introduction.
            i=0;
        }
 Gausseidel::~Gausseidel(){
   delete ui;
}



