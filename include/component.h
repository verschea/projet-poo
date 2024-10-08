#include <string>
#include <vector>
#include <queue>
#include <boost/circular_buffer.hpp>


using namespace std;

#ifndef COMPONENTS_HPP
#define COMPONENTS_HPP

typedef struct {
   bool valid;
   double value;
} DataValue_t;

class Component {
    public:
        void virtual simulate()=0;
        //Component(string text_file);
};

class CPU : public Component{
    public:
        string label;
        CPU(string text_file);

    private :    
        int freq;
        int cores;
        string program;
        queue<float> cpu_register;

        void simulate();
        DataValue_t read();
};

class Bus : public Component{
    public:
        string label;
        string source;
        Bus(string text_file);
    private :
        int width;
        vector<DataValue_t> pending;
        vector<DataValue_t> ready;
        void simulate();
        void set_data_ready();
        DataValue_t read();
};

class Memory : public Component{
    public:
        string label;
        string source;
        Memory(string text_file);
    private :
        int size;
        int access;
        boost::circular_buffer<double> memory_data;
        void simulate();
        DataValue_t read();
};

class Display : public Component{
    public:
        string source;
        Display(string text_file);
    private:    
        int refresh;
        void simulate();
};


#endif