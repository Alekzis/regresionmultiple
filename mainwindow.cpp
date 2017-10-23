#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);//connections
    connect(ui->procesar,SIGNAL(clicked()),this,SLOT(procesar()));
    connect(ui->reinicio,SIGNAL(clicked()),this,SLOT(reinicio()));
    connect(ui->salir,SIGNAL(clicked()),this,SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::procesar(){

    QString temp,temp1,temp2,temp3,temp4;         //temporal

    double X1=ui->x1->value();   //values x
    double X2=ui->x2->value();   //
    double X3=ui->x3->value();   //
    double X4=ui->x4->value();   //
    double X5=ui->x5->value();   //
    double X6=ui->x6->value();   //

    double xuno=ui->xuno->value();   //values x2
    double xdos=ui->xdos->value();   //
    double xtres=ui->xtres->value();   //
    double xcuatro=ui->xcuatro->value();   //
    double xcinco=ui->xcinco->value();   //
    double xseis=ui->xseis->value();   //


    double Y1=ui->y1->value();   //values y
    double Y2=ui->y2->value();   //
    double Y3=ui->y3->value();   //
    double Y4=ui->y4->value();   //
    double Y5=ui->y5->value();   //
    double Y6=ui->y6->value();   //

    double M[6]={X1,X2,X3,X4,X5,X6}; //array x
    double W[6]={xuno,xdos,xtres,xcuatro,xcinco,xseis}; //array x2
    double N[6]={Y1,Y2,Y3,Y4,Y5,Y6};  //array y

    int i=1;      //var
    double P=0;   //
    double CuadX2=0;//
    double mult=0;//
    double multx2=0;//
    double f1=0;//
    double d=0;   //
    double m=0;   //
    double cu=0;  //
    double n=6;    //
    double y1=0,y2=0,y3=0,y4=0,y11=0,y22=0,y33=0,y44=0,y222=0,y333=0,y444=0,a2=0,ac=0;
    double au=0;
    double Sr=0,St=0,yn=0,r=0;
    for(i=0;i<n;i++){   //array
        P=P+M[i];//sum
        f1=f1+W[i];//sum
        cu=cu+(M[i]*M[i]);//sum of squares
        mult=mult+(M[i]*W[i]);   //Sum of product
        CuadX2=CuadX2+(W[i]*W[i]); //square
        d=d+N[i]; //
        m=m+(M[i]*N[i]); //products
        multx2=multx2+(W[i]*N[i]);//Sum of product
    }
    y1=P-(P/n)*n;         //Gaussian elimination method
    y2=cu-(P/n)*P;                     //
    y3=mult-(P/n)*f1;                  //
    y4=m-(P/n)*d;                      //

    y11=f1-(f1/n)*n;                   //
    y22=mult-(f1/n)*P;                 //
    y33=CuadX2-(f1/n)*f1;          //
    y44=multx2-(f1/n)*d;               //

    y222=mult-(mult/cu)*cu;            //
    y333=y33-(y22/y2)*y3;              //
    y444=y44-(y22/y2)*y4;              //

    a2=y444/y333;                      //
    au=(y44-y33*a2)/(y22);             //
    ac=(d-P*au-f1*a2)/(n);             //
    yn=d/n;                            //

    for(i=0;i<n;i++){                  //
    Sr=Sr+(N[i]-ac-au*M[i]-a2*W[i])*(N[i]-ac-au*M[i]-a2*W[i]);
    St=St+(N[i]-yn)*(N[i]-yn);
    }
    r=sqrt((St-Sr)/(St));               //value regression



    temp.append("\ny=").append(temp1.setNum(ac)).append("+").append(temp2.setNum(au)).append("x1 ").append(temp3.setNum(a2).append("x2\nr=").append(temp4.setNum(r)));
     ui->resultado->setText(temp); //
       }
void MainWindow::reinicio(){
    ui->x1->setValue(0.0);  //restart valuesx
    ui->x2->setValue(0.0);
    ui->x3->setValue(0.0);
    ui->x4->setValue(0.0);  //
    ui->x5->setValue(0.0);
    ui->x6->setValue(0.0);

    ui->xuno->setValue(0.0);  //restart values x2
    ui->xdos->setValue(0.0);
    ui->xtres->setValue(0.0);
    ui->xcuatro->setValue(0.0);  //
    ui->xcinco->setValue(0.0);
    ui->xseis->setValue(0.0);

    ui->y1->setValue(0.0);
    ui->y2->setValue(0.0);
    ui->y3->setValue(0.0);  //restart values y
    ui->y4->setValue(0.0);
    ui->y5->setValue(0.0);
    ui->y6->setValue(0.0);

    ui->resultado->clear();
}


