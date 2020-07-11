#include <QDebug>
#include <chrono>
#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace WDWE::gui
{
MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  sim_ = new logic::Simulation();
  res_ = new Resources();
  timer_ = new QTimer(this);
  connect(timer_, SIGNAL(timeout()), this, SLOT(repaint()));
  timer_->start(interval_);

  this->resize(sim_->pixelWidth(), sim_->pixelHeight()
               + ui->toolBar->height()
               + ui->statusbar->height());
  //  this->showFullScreen();
}

MainWindow::~MainWindow()
{
  delete res_;
  delete sim_;
  delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
  QPainter *pen = new QPainter(this);
  pen->setRenderHint(QPainter::Antialiasing);

  int ratio_w = sim_->pixelWidth() / sim_->tileWidth();
  int ratio_h = sim_->pixelHeight() / sim_->tileHeight();
  for (int x = 0; x < sim_->tileWidth(); ++x)
    for (int y = 0; y < sim_->tileHeight(); ++y)
      pen->drawPixmap(x * ratio_w, y * ratio_h,
                      *res_->biomeTexture(sim_->biomeAt(x * ratio_w, y * ratio_h)));

  for (int i = 0; i < sim_->entityNumber(); ++i)
    drawAlignToCenter(pen, sim_->kindAt(i), sim_->positionAt(i));
  delete pen;
}

void MainWindow::drawAlignToCenter(QPainter *pen, logic::entities::Kind kind,
                                   QPointF center)
{
  QPixmap texture = *res_->entityTexture(kind);
  QPointF offset = QPointF(texture.width()/2, texture.height()/2);
  pen->drawPixmap(center - offset, texture);
}
}

void WDWE::gui::MainWindow::on_actionSimulation_Pause_toggled(bool arg1)
{
  if(arg1)
    sim_->simPause();
  else
    sim_->simStart();
}

void WDWE::gui::MainWindow::on_actionSimulation_Reset_Speed_triggered()
{
  sim_->simResetSpeed();
}

void WDWE::gui::MainWindow::on_actionSimulation_Slower_triggered()
{
  sim_->simSlower();
}

void WDWE::gui::MainWindow::on_actionSimulation_Faster_triggered()
{
  sim_->simFaster();
}

void WDWE::gui::MainWindow::on_actionStart_New_Disaster_triggered()
{
  sim_->simPause();
  sim_->startDisaster(logic::disasters::Type::METEOR);
  sim_->simStart();
}
