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


#include "SWGFileSourceSettings.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGSDRangel {

SWGFileSourceSettings::SWGFileSourceSettings(QString json) {
    init();
    this->fromJson(json);
}

SWGFileSourceSettings::SWGFileSourceSettings() {
    init();
}

SWGFileSourceSettings::~SWGFileSourceSettings() {
    this->cleanup();
}

void
SWGFileSourceSettings::init() {
    file_name = new QString("");
    m_file_name_isSet = false;
}

void
SWGFileSourceSettings::cleanup() {
    if(file_name != nullptr) { 
        delete file_name;
    }
}

SWGFileSourceSettings*
SWGFileSourceSettings::fromJson(QString json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGFileSourceSettings::fromJsonObject(QJsonObject pJson) {
    ::SWGSDRangel::setValue(&file_name, pJson["fileName"], "QString", "QString");
    
}

QString
SWGFileSourceSettings::asJson ()
{
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject
SWGFileSourceSettings::asJsonObject() {
    QJsonObject obj;
    if(file_name != nullptr && *file_name != QString("")){
        toJsonValue(QString("fileName"), file_name, obj, QString("QString"));
    }

    return obj;
}

QString*
SWGFileSourceSettings::getFileName() {
    return file_name;
}
void
SWGFileSourceSettings::setFileName(QString* file_name) {
    this->file_name = file_name;
    this->m_file_name_isSet = true;
}


bool
SWGFileSourceSettings::isSet(){
    bool isObjectUpdated = false;
    do{
        if(file_name != nullptr && *file_name != QString("")){ isObjectUpdated = true; break;}
    }while(false);
    return isObjectUpdated;
}
}

