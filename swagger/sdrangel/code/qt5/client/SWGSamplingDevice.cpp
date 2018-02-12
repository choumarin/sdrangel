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


#include "SWGSamplingDevice.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGSDRangel {

SWGSamplingDevice::SWGSamplingDevice(QString json) {
    init();
    this->fromJson(json);
}

SWGSamplingDevice::SWGSamplingDevice() {
    init();
}

SWGSamplingDevice::~SWGSamplingDevice() {
    this->cleanup();
}

void
SWGSamplingDevice::init() {
    index = 0;
    m_index_isSet = false;
    hw_type = new QString("");
    m_hw_type_isSet = false;
    tx = 0;
    m_tx_isSet = false;
    nb_streams = 0;
    m_nb_streams_isSet = false;
    stream_index = 0;
    m_stream_index_isSet = false;
    sequence = 0;
    m_sequence_isSet = false;
    serial = new QString("");
    m_serial_isSet = false;
    center_frequency = 0L;
    m_center_frequency_isSet = false;
    bandwidth = 0;
    m_bandwidth_isSet = false;
    state = new QString("");
    m_state_isSet = false;
}

void
SWGSamplingDevice::cleanup() {

    if(hw_type != nullptr) { 
        delete hw_type;
    }




    if(serial != nullptr) { 
        delete serial;
    }


    if(state != nullptr) { 
        delete state;
    }
}

SWGSamplingDevice*
SWGSamplingDevice::fromJson(QString json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGSamplingDevice::fromJsonObject(QJsonObject pJson) {
    ::SWGSDRangel::setValue(&index, pJson["index"], "qint32", "");
    
    ::SWGSDRangel::setValue(&hw_type, pJson["hwType"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&tx, pJson["tx"], "qint32", "");
    
    ::SWGSDRangel::setValue(&nb_streams, pJson["nbStreams"], "qint32", "");
    
    ::SWGSDRangel::setValue(&stream_index, pJson["streamIndex"], "qint32", "");
    
    ::SWGSDRangel::setValue(&sequence, pJson["sequence"], "qint32", "");
    
    ::SWGSDRangel::setValue(&serial, pJson["serial"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&center_frequency, pJson["centerFrequency"], "qint64", "");
    
    ::SWGSDRangel::setValue(&bandwidth, pJson["bandwidth"], "qint32", "");
    
    ::SWGSDRangel::setValue(&state, pJson["state"], "QString", "QString");
    
}

QString
SWGSamplingDevice::asJson ()
{
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject
SWGSamplingDevice::asJsonObject() {
    QJsonObject obj;
    if(m_index_isSet){
        obj.insert("index", QJsonValue(index));
    }
    if(hw_type != nullptr && *hw_type != QString("")){
        toJsonValue(QString("hwType"), hw_type, obj, QString("QString"));
    }
    if(m_tx_isSet){
        obj.insert("tx", QJsonValue(tx));
    }
    if(m_nb_streams_isSet){
        obj.insert("nbStreams", QJsonValue(nb_streams));
    }
    if(m_stream_index_isSet){
        obj.insert("streamIndex", QJsonValue(stream_index));
    }
    if(m_sequence_isSet){
        obj.insert("sequence", QJsonValue(sequence));
    }
    if(serial != nullptr && *serial != QString("")){
        toJsonValue(QString("serial"), serial, obj, QString("QString"));
    }
    if(m_center_frequency_isSet){
        obj.insert("centerFrequency", QJsonValue(center_frequency));
    }
    if(m_bandwidth_isSet){
        obj.insert("bandwidth", QJsonValue(bandwidth));
    }
    if(state != nullptr && *state != QString("")){
        toJsonValue(QString("state"), state, obj, QString("QString"));
    }

    return obj;
}

qint32
SWGSamplingDevice::getIndex() {
    return index;
}
void
SWGSamplingDevice::setIndex(qint32 index) {
    this->index = index;
    this->m_index_isSet = true;
}

QString*
SWGSamplingDevice::getHwType() {
    return hw_type;
}
void
SWGSamplingDevice::setHwType(QString* hw_type) {
    this->hw_type = hw_type;
    this->m_hw_type_isSet = true;
}

qint32
SWGSamplingDevice::getTx() {
    return tx;
}
void
SWGSamplingDevice::setTx(qint32 tx) {
    this->tx = tx;
    this->m_tx_isSet = true;
}

qint32
SWGSamplingDevice::getNbStreams() {
    return nb_streams;
}
void
SWGSamplingDevice::setNbStreams(qint32 nb_streams) {
    this->nb_streams = nb_streams;
    this->m_nb_streams_isSet = true;
}

qint32
SWGSamplingDevice::getStreamIndex() {
    return stream_index;
}
void
SWGSamplingDevice::setStreamIndex(qint32 stream_index) {
    this->stream_index = stream_index;
    this->m_stream_index_isSet = true;
}

qint32
SWGSamplingDevice::getSequence() {
    return sequence;
}
void
SWGSamplingDevice::setSequence(qint32 sequence) {
    this->sequence = sequence;
    this->m_sequence_isSet = true;
}

QString*
SWGSamplingDevice::getSerial() {
    return serial;
}
void
SWGSamplingDevice::setSerial(QString* serial) {
    this->serial = serial;
    this->m_serial_isSet = true;
}

qint64
SWGSamplingDevice::getCenterFrequency() {
    return center_frequency;
}
void
SWGSamplingDevice::setCenterFrequency(qint64 center_frequency) {
    this->center_frequency = center_frequency;
    this->m_center_frequency_isSet = true;
}

qint32
SWGSamplingDevice::getBandwidth() {
    return bandwidth;
}
void
SWGSamplingDevice::setBandwidth(qint32 bandwidth) {
    this->bandwidth = bandwidth;
    this->m_bandwidth_isSet = true;
}

QString*
SWGSamplingDevice::getState() {
    return state;
}
void
SWGSamplingDevice::setState(QString* state) {
    this->state = state;
    this->m_state_isSet = true;
}


bool
SWGSamplingDevice::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_index_isSet){ isObjectUpdated = true; break;}
        if(hw_type != nullptr && *hw_type != QString("")){ isObjectUpdated = true; break;}
        if(m_tx_isSet){ isObjectUpdated = true; break;}
        if(m_nb_streams_isSet){ isObjectUpdated = true; break;}
        if(m_stream_index_isSet){ isObjectUpdated = true; break;}
        if(m_sequence_isSet){ isObjectUpdated = true; break;}
        if(serial != nullptr && *serial != QString("")){ isObjectUpdated = true; break;}
        if(m_center_frequency_isSet){ isObjectUpdated = true; break;}
        if(m_bandwidth_isSet){ isObjectUpdated = true; break;}
        if(state != nullptr && *state != QString("")){ isObjectUpdated = true; break;}
    }while(false);
    return isObjectUpdated;
}
}

