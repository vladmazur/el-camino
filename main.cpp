#include <QCoreApplication>

using namespace std;

typedef enum {DAC=0, ADC=1} MODE;

int main(int argc, char *argv[])
{
    list <string> files;

//    set files
    files.push_back("Files//task.v");
    files.push_back("Files//myoutfile.dat");
    files.push_back("Files//reg.atd");
    files.push_back("Files//allted.ato");

//    set time and mode
    unsigned time = 100;
    MODE mode = DAC;

    if (mode = DAC)
    {
//        set levels and times
        double level_of_0 = 0.8, level_of_1 = 2.8, time_of_lead_edge = 3.0, time_of_trail_edge = 2.0;
//        get matched signals

    }
}
