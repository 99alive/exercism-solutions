#include <string>

namespace log_line {
    
    // Task 1: Get message from log line
    std::string message(std::string line) {
        // Find the position of the first space after the colon
        size_t colon_pos = line.find(": ");
        // Extract everything after ": "
        std::string msg = line.substr(colon_pos + 2);
        
        // Trim potential trailing whitespace/newlines
        size_t last = msg.find_last_not_of(" \t\n\r");
        return (last == std::string::npos) ? "" : msg.substr(0, last + 1);
    }

    // Task 2: Get log level from log line
    std::string log_level(std::string line) {
        // Find positions of the brackets
        size_t start = line.find("[") + 1;
        size_t end = line.find("]");
        // Extract the text between them
        return line.substr(start, end - start);
    }

    // Task 3: Reformat the log line
    std::string reformat(std::string line) {
        // Combine the message and the level in the new format: "message (level)"
        return message(line) + " (" + log_level(line) + ")";
    }
    
}  // namespace log_line