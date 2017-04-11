/*
 * IKHWObjectModelling.cpp
 *
 *  Created on: Apr 7, 2017
 *      Author: raghav
 */
#define DEBUG_LEVEL DEBUG_LEVEL_DEBUG
#include "IKSolution.hpp"


class currentDisplay;
class Notifier;
class displayElement;


class weatherData
{

    private:
        Notifier* notif;
    public:
        int getTemperature();
        int getHumidity();
        int getPressure();
        int measurementsChanged();
        int registerWithweatherData(Notifier* arg);

};

class Notifier
{
    private:
        vector<displayElement*> cDElem;
    public:
        int registerWithNotifier(displayElement* arg);
        int notify();
};

class displayElement
{
    public:
        virtual void myNotificationFunction() = 0;
        virtual ~displayElement(){}; //dont make it = 0;
};

class currentDisplay : public displayElement
{
    public:
        void init();
        void myNotificationFunction();
        ~currentDisplay();
};


/**********************************************************************/

int weatherData::registerWithweatherData(Notifier* arg)
{
    notif = arg;
    return 0;
}


int weatherData::measurementsChanged()
{
    notif->notify();
    return 0;
}

/**********************************************************************/

int Notifier::registerWithNotifier(displayElement* arg)
{
    cDElem.push_back(arg);
    return 0;
}


int Notifier::notify()
{
    for(auto objs : cDElem)
        objs->myNotificationFunction();
    return 0;
}

/**********************************************************************/

void currentDisplay::init()
{
};

void currentDisplay::myNotificationFunction()
{
    cout << " Display " << this << " Hey!!!..Its time to redraw all pictures \n";
};


currentDisplay::~currentDisplay()
{
    return;
};
/**********************************************************************/


/**************************************************************************/


int IKSolution::myMainDisp()
{
    Notifier notify;

    weatherData wd;

    currentDisplay disp1;
    currentDisplay disp2;

    notify.registerWithNotifier(&disp1);
    notify.registerWithNotifier(&disp2);

    wd.registerWithweatherData(&notify);
    wd.measurementsChanged();

    return 0;
}
/**********************************************************************************/



class weatherStats : public displayElement
{
    //notify.registerWithNotifier();
};

class weatherForecast : public displayElement
{
    //notify.registerWithNotifier();
};
