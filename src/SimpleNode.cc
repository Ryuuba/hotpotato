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

#include "SimpleNode.h"

Define_Module(SimpleNode);

// Member list initializer. This constructor assigns default values
SimpleNode::SimpleNode()
    : nodeIndex(0)
    , status(Status::IDLE)
    , msg(nullptr)
    , timer(nullptr) {
    // TODO Auto-generated constructor stub

}

// OMNeT++ destructors must release all objects created by the new instruction.
// Besides, the messages must be freed with the cancelAndDelete function member.
SimpleNode::~SimpleNode() {
    if (timer)
        cancelAndDelete(timer);
}

void SimpleNode::initialize() {
    int initializer = par("initializer").intValue();
    omnetpp::simtime_t start = par("startTime");
    nodeIndex = getIndex();
    if (initializer == nodeIndex) {
        msg = new omnetpp::cMessage("msg", msgKind::MESSAGE);
        timer = new omnetpp::cMessage("timer", msgKind::TIMER);
        scheduleAt(start, timer);
        status = Status::INITIALIZER;
    }
    WATCH(status);
}

void SimpleNode::handleMessage(omnetpp::cMessage* recvMsg) {
    switch(recvMsg->getKind()) {
    case msgKind::MESSAGE:
        EV_INFO << "Node " << nodeIndex << " received a msg from "
                << recvMsg->getSenderModule()->getIndex() << '\n';
        send(recvMsg, "out");
        break;
    case msgKind::TIMER:
        bubble("Start");
        send(msg, "out");
        break;
    default:
        error(
                "Node %d received an invalid message: %s\n",
                nodeIndex,
                recvMsg->getName()
             );
    }
}

