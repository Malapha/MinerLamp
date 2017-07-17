#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <QSystemTrayIcon>

#include "minerprocess.h"
#include "highlighter.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setVisible(bool visible) Q_DECL_OVERRIDE;

protected:
     void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

private slots:
     void setIcon();
     void iconActivated(QSystemTrayIcon::ActivationReason reason);

private:
     void createActions();
     void createTrayIcon();

     void setupEditor();

private slots:
    void on_pushButton_clicked();


    void on_checkBoxRestart_clicked(bool checked);

    void on_spinBoxMax0MHs_valueChanged(int arg1);

    void on_spinBoxDelay_valueChanged(int arg1);

    void on_checkBoxOnlyShare_clicked(bool checked);

    void on_pushButtonHelp_clicked();

private:

    void onMinerStarted();
    void onMinerStoped();
    void onHashrate(QString& hashrate);
    void onError();

    Ui::MainWindow *ui;
    MinerProcess* _process;
    QSettings*  _settings;
    QIcon*       _icon;

    bool _isMinerRunning;
    bool _isStartStoping;

    unsigned int _errorCount;

    QSystemTrayIcon* _trayIcon;
    QMenu* _trayIconMenu;

    QAction* _minimizeAction;
    QAction* _maximizeAction;
    QAction* _restoreAction;
    QAction* _quitAction;

    Highlighter* _highlighter;
};

#endif // MAINWINDOW_H