#ifndef ENGINE_H
#define ENGINE_H

#include "Graphics.h"

/*
 * This header file provides declarations for the `Engine` namespace,
 * which serves as the core of the application, integrating various subsystems
 * such as Graphics, Audio, and Physics.
 *
 * Key responsibilities:
 * - Declare functions to initialize, run, and clean up the engine.
 * - Serve as the main control hub for the application's lifecycle.
 */

namespace Engine {

// Initializes the engine, including subsystems like Graphics, Audio, and
// Physics.
void initialize();

// The main loop of the engine, managing application flow and interactions.
void mainLoop();

// Cleans up the engine, including releasing resources from subsystems.
void cleanup();

}  // namespace Engine

#endif  // ENGINE_H
