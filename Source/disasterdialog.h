#ifndef DISASTERDIALOG_H
#define DISASTERDIALOG_H

#include <QDialog>
#include <QPainter>
#include "simulation.h"
#include "resources.h"

namespace Ui { class DisasterDialog; }

namespace WDWE::gui
{
class DisasterDialog : public QDialog
{
  Q_OBJECT

public:
  explicit DisasterDialog(logic::Simulation *sim, Resources *res,
                          QWidget *parent = nullptr);
  ~DisasterDialog();

private slots:
  void on_comboBox_disaster_currentIndexChanged(const QString &type_string);
  void on_buttonBox_accepted();

private:
  Ui::DisasterDialog *ui;
  logic::Simulation *sim_;
  Resources *res_;

  void paintEvent(QPaintEvent *) override;
  void changeInputs(bool duration, bool rate, bool target, bool size);
  logic::disasters::Type stringToType(const QString &type_string);
  logic::entities::Kind stringToKind(const QString &kind_string);
};
}
#endif // DISASTERDIALOG_H
