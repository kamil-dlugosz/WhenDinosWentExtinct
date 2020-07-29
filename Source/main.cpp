#include <QApplication>
#include <QDebug>
#include "mainwindow.h"

/**
* \mainpage
* \par When Dinos Went Extinct
* Program symulujący łańcuch pokarmowy dinozaurów, dodatkowo umożliwia
*  przeprowadzanie katastrof i obserwowanie wyniku
* \author Kamil Długosz
* \date 2020.07.15
* \version 1.0
*/

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  WDWE::gui::MainWindow w;
  w.show();
  return a.exec();
}
