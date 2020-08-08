/**
 * SDRangel
 * This is the web REST/JSON API of SDRangel SDR software. SDRangel is an Open Source Qt5/OpenGL 3.0+ (4.3+ in Windows) GUI and server Software Defined Radio and signal analyzer in software. It supports Airspy, BladeRF, HackRF, LimeSDR, PlutoSDR, RTL-SDR, SDRplay RSP1 and FunCube    ---   Limitations and specifcities:    * In SDRangel GUI the first Rx device set cannot be deleted. Conversely the server starts with no device sets and its number of device sets can be reduced to zero by as many calls as necessary to /sdrangel/deviceset with DELETE method.   * Preset import and export from/to file is a server only feature.   * Device set focus is a GUI only feature.   * The following channels are not implemented (status 501 is returned): ATV and DATV demodulators, Channel Analyzer NG, LoRa demodulator   * The device settings and report structures contains only the sub-structure corresponding to the device type. The DeviceSettings and DeviceReport structures documented here shows all of them but only one will be or should be present at a time   * The channel settings and report structures contains only the sub-structure corresponding to the channel type. The ChannelSettings and ChannelReport structures documented here shows all of them but only one will be or should be present at a time    --- 
 *
 * OpenAPI spec version: 4.14.0
 * Contact: f4exb06@gmail.com
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */


#include "SWGDeviceActions.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGSDRangel {

SWGDeviceActions::SWGDeviceActions(QString* json) {
    init();
    this->fromJson(*json);
}

SWGDeviceActions::SWGDeviceActions() {
    device_hw_type = nullptr;
    m_device_hw_type_isSet = false;
    direction = 0;
    m_direction_isSet = false;
    originator_index = 0;
    m_originator_index_isSet = false;
}

SWGDeviceActions::~SWGDeviceActions() {
    this->cleanup();
}

void
SWGDeviceActions::init() {
    device_hw_type = new QString("");
    m_device_hw_type_isSet = false;
    direction = 0;
    m_direction_isSet = false;
    originator_index = 0;
    m_originator_index_isSet = false;
}

void
SWGDeviceActions::cleanup() {
    if(device_hw_type != nullptr) { 
        delete device_hw_type;
    }


}

SWGDeviceActions*
SWGDeviceActions::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGDeviceActions::fromJsonObject(QJsonObject &pJson) {
    ::SWGSDRangel::setValue(&device_hw_type, pJson["deviceHwType"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&direction, pJson["direction"], "qint32", "");
    
    ::SWGSDRangel::setValue(&originator_index, pJson["originatorIndex"], "qint32", "");
    
}

QString
SWGDeviceActions::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGDeviceActions::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(device_hw_type != nullptr && *device_hw_type != QString("")){
        toJsonValue(QString("deviceHwType"), device_hw_type, obj, QString("QString"));
    }
    if(m_direction_isSet){
        obj->insert("direction", QJsonValue(direction));
    }
    if(m_originator_index_isSet){
        obj->insert("originatorIndex", QJsonValue(originator_index));
    }

    return obj;
}

QString*
SWGDeviceActions::getDeviceHwType() {
    return device_hw_type;
}
void
SWGDeviceActions::setDeviceHwType(QString* device_hw_type) {
    this->device_hw_type = device_hw_type;
    this->m_device_hw_type_isSet = true;
}

qint32
SWGDeviceActions::getDirection() {
    return direction;
}
void
SWGDeviceActions::setDirection(qint32 direction) {
    this->direction = direction;
    this->m_direction_isSet = true;
}

qint32
SWGDeviceActions::getOriginatorIndex() {
    return originator_index;
}
void
SWGDeviceActions::setOriginatorIndex(qint32 originator_index) {
    this->originator_index = originator_index;
    this->m_originator_index_isSet = true;
}


bool
SWGDeviceActions::isSet(){
    bool isObjectUpdated = false;
    do{
        if(device_hw_type && *device_hw_type != QString("")){
            isObjectUpdated = true; break;
        }
        if(m_direction_isSet){
            isObjectUpdated = true; break;
        }
        if(m_originator_index_isSet){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

