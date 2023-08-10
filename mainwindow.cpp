#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("mouse03");

    cursorPosLabel = new QLabel("Cursor Position: ", this);
    cursorPosLabel->setFont(QFont("Times", 12));

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(cursorPosLabel);
    ui->centralwidget->setLayout(layout);

    // Start tracking when the window is created
    startTimer(100); // Timer interval in milliseconds
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);
    QPoint globalCursorPos = QCursor::pos(); // Get global cursor position
    cursorPosLabel->setText("Cursor Position: (" + QString::number(globalCursorPos.x()) + ", " + QString::number(globalCursorPos.y()) + ")");
    adjustSize(); // Resize the window to fit the label contents
}
