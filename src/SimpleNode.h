//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#ifndef SIMPLENODE_H_
#define SIMPLENODE_H_

#include <omnetpp.h>

class SimpleNode : public omnetpp::cSimpleModule{
protected:
    /** @brief Enumeration describing the number kind of messages this node
     * is able to transmit.
     */
    enum msgKind {
        MESSAGE = 1,
        TIMER = 2,
        OTHER = 3
    };
    /** @brief Enumeration describing the status of this node. */
    enum Status {
        INITIALIZER = 10,
        IDLE = 11
    };
    /** @brief The index of the node assuming it is an element of a vector. */
    int nodeIndex;
    /** @brief The node status. */
    Status status;
    /** @brief The message exchanged by simple nodes. */
    omnetpp::cMessage* msg;
    /** @brief The message exchanged by simple nodes. */
    omnetpp::cMessage* timer;
public:
    SimpleNode();
    virtual ~SimpleNode();
    /** @brief Parses the index of the node that start the communication process
     * This number is a number in the range [0, N-1], where N is the network
     * size. Besides, it parses the time at which the simulation starts.
     */
    virtual void initialize();
    /** @brief If the node is the initializer, then it sends the message to the
     * other node. Otherwise, it resends the received message.
     */
    virtual void handleMessage(omnetpp::cMessage*);
};

#endif /* SIMPLENODE_H_ */
