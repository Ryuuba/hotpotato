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

package ds_ex1_tictoc.simulations;
import ds_ex1_tictoc.SimpleNodev2;

channel Link extends ned.DatarateChannel
{
    parameters:
        int cost = default(0);
}

//
// Generated network with random topology (10 nodes, 20 edges, seed=1).
//
network Scenario2
{
    parameters:
        @display("bgb=400,400");
        int initializer;
        node[*].initializer = initializer;
    submodules:
        node[10]: SimpleNodev2;
    connections allowunconnected:
        node[0].port++ <--> Link <--> node[1].port++;
        node[0].port++ <--> Link <--> node[2].port++;
        node[0].port++ <--> Link <--> node[7].port++;
        node[0].port++ <--> Link <--> node[8].port++;
        node[0].port++ <--> Link <--> node[9].port++;
        node[1].port++ <--> Link <--> node[2].port++;
        node[1].port++ <--> Link <--> node[3].port++;
        node[1].port++ <--> Link <--> node[4].port++;
        node[1].port++ <--> Link <--> node[5].port++;
        node[1].port++ <--> Link <--> node[9].port++;
        node[2].port++ <--> Link <--> node[6].port++;
        node[2].port++ <--> Link <--> node[7].port++;
        node[3].port++ <--> Link <--> node[4].port++;
        node[3].port++ <--> Link <--> node[6].port++;
        node[4].port++ <--> Link <--> node[5].port++;
        node[4].port++ <--> Link <--> node[6].port++;
        node[4].port++ <--> Link <--> node[7].port++;
        node[5].port++ <--> Link <--> node[6].port++;
        node[5].port++ <--> Link <--> node[8].port++;
        node[6].port++ <--> Link <--> node[8].port++;
}
