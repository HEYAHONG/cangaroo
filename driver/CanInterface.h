/*
 * CanInterface.h
 *
 *  Created on: 19.12.2015
 *      Author: hd
 */

#ifndef BASE_CANINTERFACE_H_
#define BASE_CANINTERFACE_H_

#include <QString>
#include <QSharedPointer>
#include <stdint.h>

class CanDriver;
class CanMessage;

class CanInterface {
public:
    CanInterface(CanDriver *driver);
	virtual ~CanInterface();
    virtual CanDriver *getDriver();
    virtual QString getName() const = 0;

	virtual int getBitrate() = 0;
	virtual void setBitrate(int bitrate) = 0;
    virtual QList<int> getAvailableBitrates();

	virtual void open();
	virtual void close();

    virtual void sendMessage(const CanMessage &msg) = 0;
    virtual bool readMessage(CanMessage &msg, unsigned int timeout_ms) = 0;

    uint16_t getId();
    void setId(uint16_t id);

private:
    uint16_t _id;
    CanDriver *_driver;
};

typedef QSharedPointer<CanInterface> pCanInterface;

#endif /* BASE_CANINTERFACE_H_ */