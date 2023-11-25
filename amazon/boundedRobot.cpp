/*Robot Bounded In Circle:
On an infinite plane, a robot initially stands at (0, 0) and faces north. 
The robot can receive one of three instructions:

- "G": go straight 1 unit;
- "L": turn 90 degrees to the left;
- "R": turn 90 degrees to the right

Example 1:
Input: instructions = "GGLLGG"
Output: true
Explanation: The robot moves from (0,0) to (0,2), turns 180 degrees, and then returns to
(0,0).
When repeating these instructions, the robot remains in the circle of radius 2 centered at
the origin.

Example 2:
Input: instructions = "GG"
Output: false
Explanation: The robot moves north indefinitely.

Example 3:
Input: instructions = "GL"
Output: true
Explanation: The robot moves from (0, 0) -> (0, 1) -> (-1, 1) -> (-1, 0) -> (0, 0) -> ...

Constraints:
1 <= instructions.length <= 100
instructions[i] is 'G', 'L' or, 'R'.
*/


#include <iostream>
using namespace std;

bool isRobotBounded(string instructions) {
    char current_dir = 'N';
    int x = 0, y= 0;
    for(int i=0;i<instructions.length();i++){ 
        if(instructions[i] == 'G'){
            y += current_dir =='N' ? 1 : 0;
            y += current_dir =='S' ? -1 : 0;
            x += current_dir == 'E' ? 1 : 0;
            x += current_dir == 'W' ? -1 : 0;
        }
        else{
            char incoming = instructions[i];
            if(current_dir == 'N'){
                current_dir = incoming == 'L' ? 'W' : 'E';
            }
            else if(current_dir == 'W'){
                current_dir = incoming == 'L' ? 'S' : 'N';
            }
            else if(current_dir == 'S'){
                current_dir = incoming == 'L' ? 'E' : 'W';
            }
            else{
                current_dir = incoming == 'L' ? 'N' : 'S';
            }
        } 
        
    }
    
    if( (x==0 && y==0) || (current_dir!='N'))
        return true;
    
    return false;
}

bool isRobotBounded2(string instructions){
    char current_dir = 'N';
    int x =0  , y = 0;
    for(char c : instructions){
        if(c == 'G'){           
            y += (current_dir =='N' )? 1 :  0;
            y += (current_dir =='S' )? -1 : 0;
            x += (current_dir == 'E') ? 1 : 0;
            x += (current_dir == 'W') ? -1 :0;
        }else{
            if(current_dir == 'N'){
            current_dir = (c == 'L' ) ?'w':'E';
            }else if(current_dir == 'w'){
                current_dir = (c == 'L') ?'S':'N';
            }else if(current_dir =='S'){
                current_dir = (c == 'L') ?'E':'W';
            }else if(current_dir =='E'){
                current_dir = (c == 'L') ?'N':'S';
            }
        }
    }
    if(( x == 0 && y ==0) ||(current_dir != 'N')){
        return true;
    }
    return false;

}

int main(){
    cout<<"---Robot Bounded In Circle---"<<endl;
    cout<<boolalpha;
    cout<<"GGLLGGL: "<<isRobotBounded("GGLLGG")<<endl;
    cout<<"GGLLGGL: "<<isRobotBounded("GG")<<endl;
    cout<<"GGLLGGL: "<<isRobotBounded("GGLLGG")<<endl;

    cout<<"---Robot Bounded In Circle2---"<<endl;
    cout<<boolalpha;
    cout<<"GGLLGGL: "<<isRobotBounded2("GGLLGG")<<endl;
    cout<<"GGLLGGL: "<<isRobotBounded2("GG")<<endl;
    cout<<"GGLLGGL: "<<isRobotBounded2("GGLLGG")<<endl;
    return 0;
}