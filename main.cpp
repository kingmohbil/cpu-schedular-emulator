#include <iostream>
#include <string>
#include <queue>
using namespace std;
struct Task{
    string name;
    int time;
    Task(){
        name=""; 
        time= 0;
    }
};
class cpuSchedul{
    private: 
        queue<Task> q;
    public: 
        void pushTask(Task t){
            q.push(t);
        }
        bool isDone(Task &t){
            t.time -= 30;
            if(t.time <= 0)
                return true;
            return false;
        }
        void schedul(){
            while(!q.empty()){ 
                if(isDone(q.front())){
                    cout << q.front().name << endl;
                    q.pop();
                }
                else{
                    q.push(q.front());
                    q.pop();
                }
            }
        }
};
int main(){
    cpuSchedul cpu;
    Task task1;
    task1.name= "task 1";
    task1.time = 60;
    Task task2;
    task2.name= "task 2";
    task2.time = 30;
    cpu.pushTask(task1);
    cpu.pushTask(task2); 
    cpu.schedul();
    return 0;
}
