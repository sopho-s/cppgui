#include <iostream>
#include <vector>
#include <unordered_map>
#include <mutex>
#include <chrono>
#include <thread>
#include <string>
#include "errors/errors.h"
#include "window/window.h"
#pragma once

namespace windowmanager {
    class WindowManager {
    private:
        std::mutex windowmanagermutex;
        int windowidcounter;
        int windowcount;
        float framespersecond;
        bool stoprun;
        std::unordered_map<std::string, std::string> windowmanagerproperties;
        std::unordered_map<int, Window*> windows;
    public:
        WindowManager();
        ~WindowManager();
        int create_window();
        void destroy_window(int windowid);
        void destroy_all_windows();
        int get_window_count();
        Window& get_window(int windowid);

        void set_window_manager_property(std::string key, std::string value);
        std::string get_window_manager_property(std::string key);
        void set_window_property(int windowid, std::string key, std::string value);
        std::string get_window_property(int windowid, std::string key);

        std::vector<int> get_window_ids();
        std::vector<Window*> get_windows();

        void run();
        void stop();
    };
}