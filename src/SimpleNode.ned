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

package ds_ex1_tictoc;

//
// TODO auto-generated type
//
simple SimpleNode
{
    parameters:
        // The index of the node starting the experiment
        int initializer = default(0); 
        // The time at which the initializer sends the first message
        double startTime @unit(s) = default(0s); 
        // The icon of the node
        @display("i=device/laptop"); 
    gates:
        input in;   // The input port of the simple node
        output out; // The output port of the simple node
}
