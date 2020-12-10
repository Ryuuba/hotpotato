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

#include "SimpleNodev2.h"

Define_Module(SimpleNodev2);

SimpleNodev2::SimpleNodev2() {
    // TODO Auto-generated constructor stub

}

SimpleNodev2::~SimpleNodev2() {
    // TODO Auto-generated destructor stub
}

void SimpleNodev2::handleMessage(omnetpp::cMessage* recvMsg) {
    int lastGateIndex = gateSize("port$o") - 1;
    int destination = intuniform(0, lastGateIndex);
    switch(recvMsg->getKind()) {
    case msgKind::MESSAGE:
        EV_INFO << "Node " << nodeIndex << " received a msg from "
                << recvMsg->getSenderModule()->getIndex() << '\n';
        send(recvMsg, "port$o", destination);
        break;
    case msgKind::TIMER:
        bubble("Start");
        send(msg, "port$o", destination);
        break;
    default:
        error(
                "Node %d received an invalid message: %s\n",
                nodeIndex,
                recvMsg->getName()
             );
    }
}
