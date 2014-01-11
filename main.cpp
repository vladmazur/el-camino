#include <QCoreApplication>
#include <QDebug>

#include <iostream>
#include <cstdlib>

using namespace std;

typedef enum {DAC=0, ADC=1} MODE;

typedef struct { QString analog, digital, resistance; } SIGNAL;

void appendinputAlltedFile(QString output, QStringList matched) // matched :
{
//    integer fo; // file initial
//    begin
//    fo = $fopen("C:/diploma/test_files/myoutfile.dat", "w");

//    $fdisplay(fo, "names begin\n", "rout[0] 1\n",
//    "clock2 1\n", "end\n", "variation begin\n"); # 500 $fclose(fo);
//    end
//    always @(rout[0])
//    $fdisplay(fo, "rout[0] 0: %t %d", $time, rout[0]);
//    always @(clock2)
//    $fdisplay(fo, "clock2 0: %t %d", $time, clock2);




//    code += r'''
//integer fo;     // file
//initial
//    begin
//        fo = $fopen("%s", "w");
//        $fdisplay(fo, "names begin\n", ''' % filename

//	for item in signals:
//		d_name = item[0].get()
//		code += r'''"%s 1\n", ''' % d_name
//	code += r'''"end\n", "variation begin\n");
//        # 500 $fclose(fo);
//    end'''


//	for item in signals:
//		d_name = item[0].get()
//		code += '''\nalways @('''+d_name+''')\n'''


//		code += r'''    $fdisplay(fo, "'''+d_name+r''' 0: %t  %d", $time, '''+d_name+''');'''

//    matched.join()

    QStringList code;
    code.append("integer fo; // file\ninitial");
    code.append("begin");
    QString outfileStr = QString("fo = $fopen(\"%1\", \"w\");").arg(output);
    code.append(outfileStr);
    code.append("$fdisplay(fo, \"names begin\\n\",");
    for (QString item : matched) {
        QString temp = QString("\"%1 1\\n\", ").arg(item.split(" ")[0]);
        code.append(temp);
    }

    code.append("\"end\\n\", \"variation begin\\n\");");
    code.append("# 500 $fclose(fo);\nend");

    for (QString item : matched) {
        QString temp = QString("\nalways @(%1)\n").arg(item.split(" ")[0]);
        code.append(temp);
        temp = QString("$fdisplay(fo, \"%1 0: %t %d\", $time, %1);").arg(item.split(" ")[0]);
        code.append(temp);
    }

    qDebug() << "\n\n" << code.join("\n");
}

int main(int argc, char *argv[])
{
    QList <QString> files;

//    set files
    files.push_back("Files//task.v");
    files.push_back("Files//myoutfile.dat");
    files.push_back("Files//reg.atd");
    files.push_back("Files//allted.ato");

//    for (string s : files) {
//        std::cout << s << "\n";
//    }

//    set time and mode
    unsigned time = 100;
    MODE mode = DAC;

    if (mode == DAC)
    {
//        set levels and times
        double level_of_0 = 0.8, level_of_1 = 2.8, time_of_lead_edge = 3.0, time_of_trail_edge = 2.0;
//        get matched signals
//        list<string> matched;
        QStringList matched;
//        format = "%s=>%s(%s), \t"
        matched.push_back("d[0] 0.01 EJK");
        matched.push_back("clock2 0.01 EC");

        for (QString str : matched) {
            QStringList oneLine  = str.split(" ");
//            qDebug() << oneLine;
            QString reallyMatched = QString("%1=>%2(%3)").arg(oneLine[0], oneLine[2], oneLine[1]);
            qDebug() << reallyMatched;
        }

//        change input ALLTED file
        appendinputAlltedFile(files[1], matched);

    }
}
