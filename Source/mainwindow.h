#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QColor>
#include "simulation.h"
#include "resources.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace WDWE::gui
{
class MainWindow : public QMainWindow
{
  Q_OBJECT
public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private:
  Ui::MainWindow *ui;
  logic::Simulation *sim_;
  Resources *res_;
  QTimer *timer_;
  float interval_ = 1000.0/60.0;
//  QPixmap *background_;
//  QPixmap *foreground;

  void paintEvent(QPaintEvent *) override;
  void drawAlignToCenter(QPainter *pen, logic::entities::Kind kind,
                         QPointF center);
};
}
#endif // MAINWINDOW_H
