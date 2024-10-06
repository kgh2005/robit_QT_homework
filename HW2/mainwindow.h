#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Copy_clicked();
    void on_Clear_clicked();
    void on_Wave_clicked();
    void on_One_clicked();
    void on_Two_clicked();
    void on_Three_clicked();
    void on_Four_clicked();
    void on_Five_clicked();
    void on_Six_clicked();
    void on_Seven_clicked();
    void on_Eight_clicked();
    void on_Nine_clicked();
    void on_Zero_clicked();
    void on_Bar_clicked();
    void on_Plus_clicked();
    void on_Backspace_clicked();
    void on_Tab_clicked();
    void on_Qq_clicked();
    void on_Ww_clicked();
    void on_Ee_clicked();
    void on_Rr_clicked();
    void on_Tt_clicked();
    void on_Yy_clicked();
    void on_Uu_clicked();
    void on_Ii_clicked();
    void on_Oo_clicked();
    void on_Pp_clicked();
    void on_Parenthesis_Start_clicked();
    void on_Parenthesis_Finsh_clicked();
    void on_ReverseSlash_clicked();
    void on_Caps_clicked();
    void on_Aa_clicked();
    void on_Ss_clicked();
    void on_Dd_clicked();
    void on_Ff_clicked();
    void on_Gg_clicked();
    void on_Hh_clicked();
    void on_Jj_clicked();
    void on_Kk_clicked();
    void on_Ll_clicked();
    void on_Semicolon_clicked();
    void on_Quotes_clicked();
    void on_Enter_clicked();
    void on_Shift_L_clicked();
    void on_Zz_clicked();
    void on_Xx_clicked();
    void on_Cc_clicked();
    void on_Vv_clicked();
    void on_Bb_clicked();
    void on_Nn_clicked();
    void on_Mm_clicked();
    void on_Rest_clicked();
    void on_Spot_clicked();
    void on_Slash_clicked();
    void on_Shift_R_clicked();
    void on_Ctrl_L_clicked();
    void on_Win_L_clicked();
    void on_Ait_clicked();
    void on_Space_clicked();
    void on_Change_clicked();
    void on_Win_R_clicked();
    void on_Menu_clicked();
    void on_Ctrl_R_clicked();
    void toggleLanguage();
    void addTextToScreen(const QString &text);
    void connectButtons();
    void simulateWinKeyPress();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
