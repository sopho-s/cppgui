#include <exception>
#include <string>
#pragma once

namespace windowmanager {
    class WindowManagerError : public std::exception {
        private:
            std::string message;
        public:
            WindowManagerError(std::string message);
            const char* what() const throw();
    };
}