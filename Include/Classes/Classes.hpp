#pragma once
#include <string>
#include <map>
#include <iostream>

typedef std::map<std::string, double> t_map;
typedef std::map<std::string, class Classes> class_map;

class Classes{
    public:

        Classes();
        Classes(std::string);

        t_map get_Stats();
        std::string get_name();

    protected:
        std::string Name;
        t_map Stats;

        
};