#include "windowmanager.h"

namespace windowmanager {
    WindowManager::WindowManager() {
        this->stoprun = false;
        this->windowcount = 0;
        this->framespersecond = 60.0;
    }

    WindowManager::~WindowManager() {
        this->stoprun = true;
        while (this->windowmanagermutex.try_lock()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
        this->destroy_all_windows();
    }

    int WindowManager::create_window() {
        this->windowcount++;
        this->windowidcounter++;
        this->windows[this->windowidcounter] = new Window(this->windowidcounter);
        return this->windowidcounter;
    }

    void WindowManager::destroy_window(int windowid) {
        if (this->windowcount == 0) {
            throw WindowManagerError("No windows to destroy");
        }

        if (this->windows.find(windowid) == this->windows.end()) {
            throw WindowManagerError("Window does not exist");
        }

        this->windows.erase(windowid);
        this->windowcount--;
    }

    void WindowManager::destroy_all_windows() {
        this->windows.clear();
        this->windowcount = 0;
    }

    int WindowManager::get_window_count() {
        return this->windowcount;
    }

    Window& WindowManager::get_window(int windowid) {
        if (this->windows.find(windowid) == this->windows.end()) {
            throw WindowManagerError("Window does not exist");
        }

        return *this->windows[windowid];
    }

    void WindowManager::set_window_manager_property(std::string key, std::string value) {
        if (this->windowmanagerproperties.find(key) == this->windowmanagerproperties.end()) {
            throw WindowManagerError("Property does not exist");
        }

        this->windowmanagerproperties[key] = value;
    }

    std::string WindowManager::get_window_manager_property(std::string key) {
        if (this->windowmanagerproperties.find(key) == this->windowmanagerproperties.end()) {
            throw WindowManagerError("Property does not exist");
        }

        return this->windowmanagerproperties[key];
    }

    void WindowManager::set_window_property(int windowid, std::string key, std::string value) {
        if (this->windows.find(windowid) == this->windows.end()) {
            throw WindowManagerError("Window does not exist");
        }

        this->windows[windowid]->set_property(key, value);
    }

    std::string WindowManager::get_window_property(int windowid, std::string key) {
        if (this->windows.find(windowid) == this->windows.end()) {
            throw WindowManagerError("Window does not exist");
        }

        return this->windows[windowid]->get_property(key);
    }

    std::vector<int> WindowManager::get_window_ids() {
        std::vector<int> windowids;
        for (auto const& window : this->windows) {
            windowids.push_back(window.first);
        }

        return windowids;
    }

    std::vector<Window*> WindowManager::get_windows() {
        std::vector<Window*> windowpointers;
        for (auto const& window : this->windows) {
            windowpointers.push_back(window.second);
        }

        return windowpointers;
    }

    void WindowManager::run() {
        if (this->windowmanagermutex.try_lock()) {
            throw WindowManagerError("Window manager is already running");
        }
        this->windowmanagermutex.lock();
        while (this->windowcount > 0 && this->stoprun == false) {
            for (auto const& window : this->windows) {
                // Render window
            }
        }
        this->windowmanagermutex.unlock();
    }

    void WindowManager::stop() {
        stoprun = true;
    }
}