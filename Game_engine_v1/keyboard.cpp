#include "Keyboard.h"

/*
 * Implementation of the Keyboard namespace. This file handles key state
 * management, initialization, and cleanup logic for the keyboard subsystem.
 */

namespace Keyboard {

// Internal map to store the state of each key
static std::unordered_map<std::string, KeyState> keyStates;

void initialize() {
    std::cout << "Keyboard subsystem initialized successfully." << std::endl;

    // Example: Prepopulate key states for common keys
    keyStates["W"] = KeyState::Released;
    keyStates["A"] = KeyState::Released;
    keyStates["S"] = KeyState::Released;
    keyStates["D"] = KeyState::Released;
}

void cleanup() {
    keyStates.clear();
    std::cout << "Keyboard subsystem cleaned up successfully." << std::endl;
}

void setKeyState(const std::string& key, KeyState state) {
    keyStates[key] = state;
    std::cout << "Key '" << key << "' set to "
              << (state == KeyState::Pressed ? "Pressed" : "Released") << "."
              << std::endl;
}

KeyState getKeyState(const std::string& key) {
    if (keyStates.find(key) != keyStates.end()) {
        return keyStates[key];
    }
    std::cout << "Key '" << key << "' not found. Defaulting to Released."
              << std::endl;
    return KeyState::Released;
}

}  // namespace Keyboard
