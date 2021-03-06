#ifndef DIALOG_H
#define DIALOG_H

#include "config.h"
#include "universecomponent.h"
#include "zodiac.h"
#include <QDialog>
#include <QTimer>
#include <list>
#include <QLineEdit>
#include <QLabel>


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    virtual ~Dialog();

private slots:
    //prepare the next frame, called by the timer
    void nextFrame();
    //toggle the simultation's pause state
    void togglePause();
    //toggle rendering of Zodiacs
    void toggleZodiacs();
    //toggle rendering of labels
    void toggleLabels();
    //toggle zomming in
    void toggleZoomIn();
    //toggle zomming out
    void toggleZoomOut();
    //toggle auto adjust
    void toggleAdjust();

private:
    //method called when the window is being redrawn
    void paintEvent(QPaintEvent *event);
    //pause (or unpause) the simulation
    void pause(bool pause);
    //handle key presses
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::Dialog* ui;
    QTimer* m_timer; //Timer object for triggering updates

    //buttons for UI
    QPushButton* m_buttonPause;
    QPushButton* m_buttonZodiacs;
    QPushButton* m_buttonLabels;
    QPushButton* m_buttonZoomIn;
    QPushButton* m_buttonZoomOut;
    QPushButton* m_buttonAdjust;
    QLineEdit* m_textStep;
    QLabel* m_stepLabel;

    int m_width; //width of the window
    int m_height; //height of the window
    bool m_paused; //is the simulation paused?
    bool m_renderZodiacs; //should Zodiacs be rendered?
    bool m_renderLabels; //should labels be rendered?
    long m_timestamp; //simulation time since simulation start
    int m_timestep;   //simulations timestep - initially get from config
    int m_zoom;    //scale of zoom
    UniverseComponent* m_universe; //The universe
    std::list<Zodiac>* m_zodiacs; //Vector of zodiac lines
    Config* m_config; //the singleton config instance

};

#endif // DIALOG_H
