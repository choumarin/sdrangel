/**
 * SDRangel
 * This is the web REST/JSON API of SDRangel SDR software. SDRangel is an Open Source Qt5/OpenGL 3.0+ (4.3+ in Windows) GUI and server Software Defined Radio and signal analyzer in software. It supports Airspy, BladeRF, HackRF, LimeSDR, PlutoSDR, RTL-SDR, SDRplay RSP1 and FunCube     ---   Limitations and specifcities:       * In SDRangel GUI the first Rx device set cannot be deleted. Conversely the server starts with no device sets and its number of device sets can be reduced to zero by as many calls as necessary to /sdrangel/deviceset with DELETE method.   * Stopping instance i.e. /sdrangel with DELETE method is a server only feature. It allows stopping the instance nicely.   * Preset import and export from/to file is a server only feature.   * Device set focus is a GUI only feature.   * The following channels are not implemented (status 501 is returned): ATV demodulator, Channel Analyzer, Channel Analyzer NG, LoRa demodulator, TCP source   * The content type returned is always application/json except in the following cases:     * An incorrect URL was specified: this document is returned as text/html with a status 400    --- 
 *
 * OpenAPI spec version: 4.0.0
 * Contact: f4exb06@gmail.com
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */

/*
 * SWGLoggingInfo.h
 *
 * Logging parameters setting
 */

#ifndef SWGLoggingInfo_H_
#define SWGLoggingInfo_H_

#include <QJsonObject>


#include <QString>

#include "SWGObject.h"

namespace SWGSDRangel {

class SWGLoggingInfo: public SWGObject {
public:
    SWGLoggingInfo();
    SWGLoggingInfo(QString json);
    ~SWGLoggingInfo();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject asJsonObject();
    void fromJsonObject(QJsonObject json);
    SWGLoggingInfo* fromJson(QString jsonString);

    QString* getConsoleLevel();
    void setConsoleLevel(QString* console_level);

    QString* getFileLevel();
    void setFileLevel(QString* file_level);

    qint32 getDumpToFile();
    void setDumpToFile(qint32 dump_to_file);

    QString* getFileName();
    void setFileName(QString* file_name);


    virtual bool isSet() override;

private:
    QString* console_level;
    bool m_console_level_isSet;

    QString* file_level;
    bool m_file_level_isSet;

    qint32 dump_to_file;
    bool m_dump_to_file_isSet;

    QString* file_name;
    bool m_file_name_isSet;

};

}

#endif /* SWGLoggingInfo_H_ */
