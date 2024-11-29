#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <iostream>
#include <string>
#include <unordered_map>

/*
 * The Keyboard namespace provides functionalities for handling keyboard input
 * within the graphics engine. It includes key state management, event handling,
 * and key code mappings.
 *
 * Key responsibilities:
 * - Managing the state of keys (pressed/released).
 * - Handling key events and callbacks.
 * - Mapping keys to corresponding actions.
 */

namespace Keyboard {

// Enum representing key states
enum class KeyState { Pressed, Released };

// Function to initialize the keyboard subsystem
void initialize();

// Function to cleanup the keyboard subsystem
void cleanup();

// Function to update the state of a key
void setKeyState(const std::string& key, KeyState state);

// Function to get the current state of a key
KeyState getKeyState(const std::string& key);

}  // namespace Keyboard

#endif  // KEYBOARD_H
