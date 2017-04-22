/*
 * IKHWObjectModelling.cpp
 *
 *  Created on: Apr 7, 2017
 *      Author: raghav
 */
#define DEBUG_LEVEL DEBUG_LEVEL_DEBUG
#include "IKSolution.hpp"


#if 0

void myGstreamerPipeLineImplementation()
{

    for() //all elements
    {
        //call chain();
    }


}



void dataSourceMain()
{
    while(true)
    {

        msg = getMsg(DataSourceQueue);
        switch(msg)
        {

        }
        dataSourcePublishFunction();
    }

}

void dataSourceRegisteFunction(fnc) //Register a subscriber
{
}

void dataSourcePublishFunction()
{
    for()
    {
        //Call all callbacks

    }
}

void ATCMain()
{

    dataSourceRegisteFunction(ATCDataSourceCallBackFunction);

    while(true)
    {

        msg = getMsg(ATCQueue);
        switch(msg)
        {
            case FLIGHTLANDREQUEST:
                postMsg(FlightQueue, ATCMESSAGE);

        }

        handlePublishers(); //Post a message to itself data source has upated some data. time to process it.

    }

}

void callBackForPublishers()
{
    postMsg(FlightQueue, ATCMESSAGE);

}


void FlightMain()
{
    while(true)
    {

        msg = getMsg(FlightQueue);
        switch(msg)
        {
            case ATCMESSAGE:
        }


    }

}



void AirTrafficcontroller()
{
    ATCController ATCc;
    Flight f[MAX_FLIGHTS]

    ATCc.init();

    while(1)
    {
        ACCc.request("Enter"); //Enter the zone
    }

}
#endif

/*****************************************************************************************/
#if 0
/* Model a Parking Lot

 * */
void parkingLotMain()
{
    Parker driver;
    ParkingLot lot;
    ParkingLotMgmnt mgmnt;
    PaymentSystem ps;

    mgmnt.open();
    mgmnt.enableSecurity();


    driver.driveIntoLot();
    Ticket ticket = ps.requestTicket();

    driver.assignTicket(ticket);

    lot.opentGate();
    mgmnt.updateSigns(); //ipdateFreeSlots(); opentgate should do this.

    lot.provideEmtySlot();
    driver.park();

    mgmnt.addSpaces();

    mgmnt.openMoreSpaces();
    mgmnt.openMoreFloors();

    driver.unPark();
    res = ps.makeAPayment(ticket, paymentmethod);
    lot.openGate();
    driver.driveOutOfLot();
    lot.removeSpaces(); //update availability info.
    //lot.updateAvailability();

    mgmnt.disableSecurity();
    mgmnt.close();



}
#endif

/*****************************************************************************************/

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
