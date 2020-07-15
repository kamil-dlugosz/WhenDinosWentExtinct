#include <qdebug.h>
#include "disasterdialog.h"
#include "ui_disasterdialog.h"
#include "include-disasters.h"

namespace WDWE::gui
{
DisasterDialog::DisasterDialog(logic::Simulation *sim, Resources *res,
                               QWidget *parent)
  : QDialog(parent)
  , ui(new Ui::DisasterDialog)
  , sim_(sim)
  , res_(res)
{
  ui->setupUi(this);
  setFixedSize(460, 335);
  on_comboBox_disaster_currentIndexChanged(ui->comboBox_disaster->currentText());
}

DisasterDialog::~DisasterDialog()
{
  delete ui;
}

void DisasterDialog::on_comboBox_disaster_currentIndexChanged
(const QString &type_string)
{
  if (type_string == "Inferno")
    changeInputs(true, true, false, true);
  else if (type_string == "Meteor")
    changeInputs(true, true, false, true);
  else if (type_string == "Drought")
    changeInputs(true, true, false, false);
  else if (type_string == "Gamma Ray")
    changeInputs(true, true, false, false);
  else if (type_string == "Annihilation")
    changeInputs(false, false, true, false);
  else
    changeInputs(true, false, false, false);
}

void DisasterDialog::paintEvent(QPaintEvent *)
{
  QPainter pen(this);
  if (res_ != nullptr)
    pen.drawPixmap(0, 0, res_->disasterDialogTexture());
}

void DisasterDialog::changeInputs(bool duration, bool rate, bool target, bool size)
{
  ui->label_duration->setVisible(duration);
  ui->spinBox_duration->setVisible(duration);
  ui->label_rate->setVisible(rate);
  ui->spinBox_rate->setVisible(rate);
  ui->label_target->setVisible(target);
  ui->comboBox_target->setVisible(target);
  ui->label_size->setVisible(size);
  ui->spinBox_size->setVisible(size);
}

logic::disasters::Type DisasterDialog::stringToType(const QString &type_string)
{
  if (type_string == "Inferno")
    return logic::disasters::Type::INFERNO;
  else if (type_string == "Meteor")
    return logic::disasters::Type::METEOR;
  else if (type_string == "Drought")
    return logic::disasters::Type::DROUGHT;
  else if (type_string == "Gamma Ray")
    return logic::disasters::Type::GAMMARAY;
  else if (type_string == "Annihilation")
    return logic::disasters::Type::ANNIHILATION;
  else
    return logic::disasters::Type::INVALID;
}

logic::entities::Kind DisasterDialog::stringToKind(const QString &kind_string)
{
  if (kind_string == "Land Dino")
    return logic::entities::Kind::LANDDINO;
  else if (kind_string == "Air Dino")
    return logic::entities::Kind::AIRDINO;
  else if (kind_string == "Water Dino")
    return logic::entities::Kind::WATERDINO;
  else if (kind_string == "Tree")
    return logic::entities::Kind::TREE;
  else if (kind_string == "Bush")
    return logic::entities::Kind::BUSH;
  else if (kind_string == "Grass")
    return logic::entities::Kind::GRASS;
  else if (kind_string == "Alga")
    return logic::entities::Kind::ALGA;
  else
    return logic::entities::Kind::INVALID;
}

void DisasterDialog::on_buttonBox_accepted()
{
  logic::disasters::Type type = stringToType(ui->comboBox_disaster->currentText());
  switch (type) {
  case logic::disasters::Type::INFERNO:
    sim_->startInferno(ui->spinBox_duration->value(),
                       ui->spinBox_size->value(),
                       ui->spinBox_rate->value() / 25.0);
    break;
  case logic::disasters::Type::METEOR:
    sim_->startMeteor(ui->spinBox_duration->value(),
                      ui->spinBox_size->value(),
                      ui->spinBox_rate->value() / 25.0);
    break;
  case logic::disasters::Type::DROUGHT:
    sim_->startDrought(ui->spinBox_duration->value(),
                       ui->spinBox_rate->value() / 50.0);
    break;
  case logic::disasters::Type::GAMMARAY:
    sim_->startGammaRay(ui->spinBox_duration->value(),
                        ui->spinBox_rate->value() / 5);
    break;
  case logic::disasters::Type::ANNIHILATION: {
    logic::entities::Kind kind = stringToKind(ui->comboBox_target->currentText());
    sim_->startAnnihilation(kind);
    break;
  }
  default:
    break;
  }
}
}
