#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vtkSmartPointer.h>
#include <vtkLine.h>
#include <vtkPoints.h>
#include "QVTKWidget.h"
#include <vtkSphereSource.h>
#include <vtkConeSource.h>
#include <vtkPolyData.h>
#include <vtkSmartPointer.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkProperty.h>
#include <vtkPolyData.h>
#include <vtkSTLReader.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkCamera.h>
#include <iostream>
#include <cstdlib>
#include <vtkTransform.h>
#include <vtkObjectFactory.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkWindowToImageFilter.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
      vtkSmartPointer<vtkSphereSource> sphereSource = vtkSmartPointer<vtkSphereSource>::New();
      sphereSource->SetCenter(0.0, 0.0, 0.0);
      sphereSource->SetRadius(5.0);

      vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
      mapper->SetInputConnection(sphereSource->GetOutputPort());

      vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
      actor->SetMapper(mapper);

      vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
      vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
      renderWindow->AddRenderer(renderer);
      vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
      renderWindowInteractor->SetRenderWindow(renderWindow);
      renderWindow->SetSize(800,600);
      renderer->AddActor(actor);
      renderer->SetBackground(.3, .6, .3); // Background color green
      renderWindow->Render();
      renderWindowInteractor->Start();
}

void MainWindow::on_pushButton_2_clicked()
{
    vtkSmartPointer<vtkConeSource> coneSource = vtkSmartPointer<vtkConeSource>::New();
    coneSource->SetRadius(4);
    coneSource->SetHeight(10);
    coneSource->SetDirection(0,1,0);

    vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputConnection(coneSource->GetOutputPort());

    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);
    actor->GetProperty()->SetColor(1,0,0);
    vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
    vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
    renderWindow->AddRenderer(renderer);
    vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
    renderWindowInteractor->SetRenderWindow(renderWindow);
    renderer->AddActor(actor);
    renderer->SetBackground(1,1,1);
    renderWindow->Render();
    renderWindow->SetSize(800,600);
    renderWindowInteractor->Start();
}


void MainWindow::on_pushButton_3_clicked()
{
    vtkSmartPointer<vtkRenderer> renderer =  vtkSmartPointer<vtkRenderer>::New();
    vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
    vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
    renderWindow->AddRenderer(renderer);
    renderWindow->SetSize(800,800);
    renderWindowInteractor->SetRenderWindow(renderWindow);


    int i;

    for (i=1; i<6; i++)
    {
        char filename[200];
        sprintf(filename,"C:\\VTK\\VTK-examples\\ReadSTL\\AugReality\\%d.stl",i);
        std::string inputFilename =filename;

        vtkSmartPointer<vtkSTLReader> reader = vtkSmartPointer<vtkSTLReader>::New();
        reader->SetFileName(inputFilename.c_str());
        reader->Update();

        // mapper
        vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
        mapper->SetInputConnection(reader->GetOutputPort());

        //actor
       vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
       actor->SetMapper(mapper);
       if (i==1)
       {
       actor->GetProperty()->SetColor(0,0,1);
       }
       if (i==2)
       {
           actor->GetProperty()->SetColor(0,1,0);
       }
       if (i==3)
       {
           actor->GetProperty()->SetColor(1,0,1);
       }
       if (i==4)
       {
           actor->GetProperty()->SetColor(1,1,0);
       }
       if (i==5)
       {
           actor->GetProperty()->SetColor(0.5,0,0.3);
       }

       //renderer

       renderer->AddActor(actor);
       renderer->SetBackground(.1, .2, .3);

    }
    renderWindow->Render();
    renderWindowInteractor->Start();
}
