#include <unordered_map>
#include <string>
#pragma once

namespace windowmanager {
    class Window {
    private:
        int id;
        std::unordered_map<std::string, std::string> windowproperties;
    public:
        Window(int id);
        int get_id();

        void set_property(std::string key, std::string value);
        std::string get_property(std::string key);
    };
}