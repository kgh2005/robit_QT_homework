#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QPushButton>
#include <QClipboard>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/extensions/XTest.h>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Screen QLabel에 '_' 텍스트 설정
    ui->Screen->setText("_");
    ui->Screen->setAlignment(Qt::AlignLeft | Qt::AlignVCenter); // 왼쪽 가운데 정렬
    ui->Screen->setStyleSheet("background-color: gray; color: white;"); // 폰트 크기 및 색상 설정

    // 왼쪽 간격 설정 (left, top, right, bottom)
    ui->Screen->setContentsMargins(10, 0, 0, 0); // 왼쪽 간격을 10픽셀로 설정

    // 전체 버튼에 적용할 스타일시트
    QString buttonStyle =
    "QPushButton {"
    "   background-color: gray;"  // 기본 버튼 색상
    "   color: white;"
    "   border: 1px solid black;"
    "}"
    "QPushButton:pressed {"
    "   background-color: white;"      // 눌렸을 때 흰색으로 변경
    "   color: black;"
    "}";

    // QWidget 대신 QPushButton에만 스타일시트 적용
    QList<QPushButton *> buttons = this->findChildren<QPushButton *>();
    for(auto button : buttons) {
        button->setStyleSheet(buttonStyle);
    }

    // Caps 버튼은 눌렸을 때 흰색으로 유지
    ui->Caps->setCheckable(true);  // Caps 버튼을 체크 가능하게 설정
    ui->Caps->setStyleSheet(
        "QPushButton {"
        "   background-color: gray;"  // 기본 색상
        "   color: white;"
        "   border: 1px solid black;"
        "}"
        "QPushButton:checked {"
        "   background-color: white;"      // 눌렸을 때 흰색 유지
        "   color: black;"
        "}"
    );




    // 상단 버튼
    ui->Copy->setText("Copy");
    ui->Clear->setText("Clear");

    // 첫 번째 줄 버튼 (숫자 + 특수 문자)
    ui->Wave->setText("~\n`");
    ui->One->setText("!\n1");
    ui->Two->setText("@\n2");
    ui->Three->setText("#\n3");
    ui->Four->setText("$\n4");
    ui->Five->setText("%\n5");
    ui->Six->setText("^\n6");
    ui->Seven->setText("&&\n7");
    ui->Eight->setText("*\n8");
    ui->Nine->setText("(\n9");
    ui->Zero->setText(")\n0");
    ui->Bar->setText("_\n-");
    ui->Plus->setText("+\n=");

    // 두 번째 줄 버튼 (대문자 + 소문자)
    ui->Tab->setText("Tab");
    ui->Qq->setText("Q\nq");
    ui->Ww->setText("W\nw");
    ui->Ee->setText("E\ne");
    ui->Rr->setText("R\nr");
    ui->Tt->setText("T\nt");
    ui->Yy->setText("Y\ny");
    ui->Uu->setText("U\nu");
    ui->Ii->setText("I\ni");
    ui->Oo->setText("O\no");
    ui->Pp->setText("P\np");
    ui->Parenthesis_Start->setText("{\n[");
    ui->Parenthesis_Finsh->setText("}\n]");
    ui->ReverseSlash->setText("\\\n|");

    // 세 번째 줄 버튼 (대문자 + 소문자)
    ui->Caps->setText("Caps");
    ui->Aa->setText("A\na");
    ui->Ss->setText("S\ns");
    ui->Dd->setText("D\nd");
    ui->Ff->setText("F\nf");
    ui->Gg->setText("G\ng");
    ui->Hh->setText("H\nh");
    ui->Jj->setText("J\nj");
    ui->Kk->setText("K\nk");
    ui->Ll->setText("L\nl");
    ui->Semicolon->setText(":\n;");
    ui->Quotes->setText("\"\n'");

    // 네 번째 줄 버튼 (대문자 + 소문자)
    ui->Shift_L->setText("Shift");
    ui->Zz->setText("Z\nz");
    ui->Xx->setText("X\nx");
    ui->Cc->setText("C\nc");
    ui->Vv->setText("V\nv");
    ui->Bb->setText("B\nb");
    ui->Nn->setText("N\nn");
    ui->Mm->setText("M\nm");
    ui->Rest->setText("<\n,");
    ui->Spot->setText(">\n.");
    ui->Slash->setText("?\n/");

    // 스페이스 바 및 하단 버튼들
    ui->Ctrl_L->setText("Ctrl");
    ui->Win_L->setText("Win");
    ui->Ait->setText("Alt");
    ui->Space->setText("Space");
    ui->Change->setText("Kor");
    //ui->Win_R->setText("Win");
    ui->Menu->setText("Menu");
    ui->Ctrl_R->setText("Ctrl");

    // "Kor" 버튼 클릭 시 한글/영문 전환 기능
    connect(ui->Change, &QPushButton::clicked, this, &MainWindow::toggleLanguage);

    // 버튼 클릭 이벤트 연결
    connectButtons();


}

// 언어 전환 함수
void MainWindow::toggleLanguage() {
    static bool isKorean = false;  // 현재 언어 상태 저장

    if (isKorean) {
        // 영어 자판으로 변경
        ui->Qq->setText("Q\nq");
        ui->Ww->setText("W\nw");
        ui->Ee->setText("E\ne");
        ui->Rr->setText("R\nr");
        ui->Tt->setText("T\nt");
        ui->Yy->setText("Y\ny");
        ui->Uu->setText("U\nu");
        ui->Ii->setText("I\ni");
        ui->Oo->setText("O\no");
        ui->Pp->setText("P\np");
        ui->Aa->setText("A\na");
        ui->Ss->setText("S\ns");
        ui->Dd->setText("D\nd");
        ui->Ff->setText("F\nf");
        ui->Gg->setText("G\ng");
        ui->Hh->setText("H\nh");
        ui->Jj->setText("J\nj");
        ui->Kk->setText("K\nk");
        ui->Ll->setText("L\nl");
        ui->Zz->setText("Z\nz");
        ui->Xx->setText("X\nx");
        ui->Cc->setText("C\nc");
        ui->Vv->setText("V\nv");
        ui->Bb->setText("B\nb");
        ui->Nn->setText("N\nn");
        ui->Mm->setText("M\nm");

        ui->Change->setText("Kor");
    } else {
        // 한글 자판으로 변경
        ui->Qq->setText("ㅂ");
        ui->Ww->setText("ㅈ");
        ui->Ee->setText("ㄷ");
        ui->Rr->setText("ㄱ");
        ui->Tt->setText("ㅅ");
        ui->Yy->setText("ㅛ");
        ui->Uu->setText("ㅕ");
        ui->Ii->setText("ㅑ");
        ui->Oo->setText("ㅒ\nㅐ");
        ui->Pp->setText("ㅖ\nㅔ");
        ui->Aa->setText("ㅁ");
        ui->Ss->setText("ㄴ");
        ui->Dd->setText("ㅇ");
        ui->Ff->setText("ㄹ");
        ui->Gg->setText("ㅎ");
        ui->Hh->setText("ㅗ");
        ui->Jj->setText("ㅓ");
        ui->Kk->setText("ㅏ");
        ui->Ll->setText("ㅣ");
        ui->Zz->setText("ㅋ");
        ui->Xx->setText("ㅌ");
        ui->Cc->setText("ㅊ");
        ui->Vv->setText("ㅍ");
        ui->Bb->setText("ㅠ");
        ui->Nn->setText("ㅜ");
        ui->Mm->setText("ㅡ");

        ui->Change->setText("영어");
    }

    isKorean = !isKorean;  // 언어 상태 토글
}

void MainWindow::simulateWinKeyPress() {
    // 디스플레이 열기
    Display* display = XOpenDisplay(nullptr);

//    if (display == nullptr) {
//        qDebug() << "Cannot open display!";
//        return;
//    }

    // Win 키의 키코드 가져오기 (XK_Super_L은 왼쪽 Win 키)
    KeyCode winKeyCode = XKeysymToKeycode(display, XK_Super_L);

    // Win 키 눌림 이벤트 시뮬레이션
    XTestFakeKeyEvent(display, winKeyCode, True, 0);

    // Win 키 떼는 이벤트 시뮬레이션
    XTestFakeKeyEvent(display, winKeyCode, False, 0);

    // 이벤트를 디스플레이에 적용
    XFlush(display);

    // 디스플레이 닫기
    XCloseDisplay(display);
}


// 버튼 클릭 시 텍스트 추가 함수
void MainWindow::addTextToScreen(const QString &text) {
    QString currentText = ui->Screen->text();

    // '_''가 포함되어 있는 경우 제거
    if (currentText.endsWith("_")) {
        currentText.chop(1);  // 마지막 문자 '_' 제거
    }

    // 버튼 텍스트 추가
    ui->Screen->setText(currentText + text + "_");  // 텍스트 추가 후 '_' 붙이기
}

// 버튼 클릭 이벤트 연결
void MainWindow::connectButtons() {
    // 버튼 목록
    QList<QPushButton *> buttons = this->findChildren<QPushButton *>();
    for (auto button : buttons) {
        // 출력하지 않아야 하는 버튼 목록
        QStringList noOutputButtons = {"Tab", "Caps", "Shift", "Ctrl", "Win", "Alt", "Space", "Change", "Copy", "Clear", "Enter", "Backspace", "Menu", "Kor", "영어"};

        // 출력하지 않아야 하는 버튼인지 확인
        if (!noOutputButtons.contains(button->text().split("\n").first())) {
            // 버튼 클릭 시 addTextToScreen 호출
            connect(button, &QPushButton::clicked, [this, button]() {
                QString textToAdd;
                if (button->text().contains("\n")) {
                    // Caps 버튼의 색상 확인
                    if (ui->Caps->isChecked()) {
                        // Caps가 체크된 경우, \n 뒤의 글자 출력
                        textToAdd = button->text().split("\n").first();
                    }
                    else {
                        // Caps가 체크되지 않은 경우, \n 앞의 글자 출력
                        textToAdd = button->text().split("\n").last();
                    }
                }
                else {
                    // \n이 없는 경우, 버튼 텍스트 전체 출력
                    textToAdd = button->text();
                }

                addTextToScreen(textToAdd); // 텍스트 추가
            });
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


// Copy 버튼 클릭 시 클립보드에 텍스트 복사
void MainWindow::on_Copy_clicked() {
    QClipboard *clipboard = QApplication::clipboard();
    QString textToCopy = ui->Screen->text();

    // 마지막 문자가 '_'인 경우 제거
    if (textToCopy.endsWith("_")) {
        textToCopy.chop(1);
    }

    clipboard->setText(textToCopy);
}


// Clear 버튼 클릭 시 텍스트 지우기
void MainWindow::on_Clear_clicked() {
    ui->Screen->setText("_");
}

void MainWindow::on_Wave_clicked()
{

}


void MainWindow::on_One_clicked()
{

}


void MainWindow::on_Two_clicked()
{

}


void MainWindow::on_Three_clicked()
{

}


void MainWindow::on_Four_clicked()
{

}


void MainWindow::on_Five_clicked()
{

}


void MainWindow::on_Six_clicked()
{

}


void MainWindow::on_Seven_clicked()
{

}


void MainWindow::on_Eight_clicked()
{

}


void MainWindow::on_Nine_clicked()
{

}


void MainWindow::on_Zero_clicked()
{

}


void MainWindow::on_Bar_clicked()
{

}


void MainWindow::on_Plus_clicked()
{

}


// Backspace 버튼 클릭 시 마지막 문자 삭제 (underscore 앞의 문자만 삭제)
void MainWindow::on_Backspace_clicked() {
    QString currentText = ui->Screen->text();

    // 현재 텍스트가 '_'가 아닌 경우에만 처리
    if (currentText != "_") {
        // 마지막 문자가 '_'이면, 그 앞의 문자 삭제
        if (currentText.endsWith("_")) {
            currentText.chop(1);  // 마지막 문자 '_' 제거
        }

        // 마지막 문자 삭제
        if (!currentText.isEmpty()) {
            currentText.chop(1);  // 마지막 문자 제거
        }

        ui->Screen->setText(currentText + "_");  // '_'를 다시 추가
    }
}




// Tab 버튼 클릭 시 탭 공백 추가
void MainWindow::on_Tab_clicked() {
    addTextToScreen("\t"); // 탭 공백 추가
}

void MainWindow::on_Qq_clicked()
{

}


void MainWindow::on_Ww_clicked()
{

}


void MainWindow::on_Ee_clicked()
{

}


void MainWindow::on_Rr_clicked()
{

}


void MainWindow::on_Tt_clicked()
{

}


void MainWindow::on_Yy_clicked()
{

}


void MainWindow::on_Uu_clicked()
{

}


void MainWindow::on_Ii_clicked()
{

}


void MainWindow::on_Oo_clicked()
{

}


void MainWindow::on_Pp_clicked()
{

}


void MainWindow::on_Parenthesis_Start_clicked()
{

}


void MainWindow::on_Parenthesis_Finsh_clicked()
{

}


void MainWindow::on_ReverseSlash_clicked()
{

}


void MainWindow::on_Caps_clicked()
{

}


void MainWindow::on_Aa_clicked()
{

}


void MainWindow::on_Ss_clicked()
{

}


void MainWindow::on_Dd_clicked()
{

}


void MainWindow::on_Ff_clicked()
{

}


void MainWindow::on_Gg_clicked()
{

}


void MainWindow::on_Hh_clicked()
{

}


void MainWindow::on_Jj_clicked()
{

}


void MainWindow::on_Kk_clicked()
{

}


void MainWindow::on_Ll_clicked()
{

}


void MainWindow::on_Semicolon_clicked()
{

}


void MainWindow::on_Quotes_clicked()
{

}


// Enter 버튼 클릭 시 줄 바꿈 추가
void MainWindow::on_Enter_clicked() {
    addTextToScreen("\n");
}


void MainWindow::on_Shift_L_clicked()
{

}


void MainWindow::on_Zz_clicked()
{

}


void MainWindow::on_Xx_clicked()
{

}


void MainWindow::on_Cc_clicked()
{

}


void MainWindow::on_Vv_clicked()
{

}


void MainWindow::on_Bb_clicked()
{

}


void MainWindow::on_Nn_clicked()
{

}


void MainWindow::on_Mm_clicked()
{

}


void MainWindow::on_Rest_clicked()
{

}


void MainWindow::on_Spot_clicked()
{

}


void MainWindow::on_Slash_clicked()
{

}


void MainWindow::on_Shift_R_clicked()
{

}


void MainWindow::on_Ctrl_L_clicked()
{

}


void MainWindow::on_Win_L_clicked() {
    simulateWinKeyPress(); // Win 키 이벤트 시뮬레이션
}


void MainWindow::on_Ait_clicked()
{

}


// Space 버튼 클릭 시 공백 추가
void MainWindow::on_Space_clicked() {
    addTextToScreen(" "); // 공백 추가
}


void MainWindow::on_Change_clicked()
{

}


void MainWindow::on_Win_R_clicked() {
    //simulateWinKeyPress(); // Win 키 이벤트 시뮬레이션
}


void MainWindow::on_Menu_clicked()
{

}


void MainWindow::on_Ctrl_R_clicked()
{

}

