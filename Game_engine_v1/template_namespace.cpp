#include <iostream>
#include <string>
#include <vector>

#include "Vulkan.h"
#include "Window.h"

/*
 * This file serves as the primary entry point for managing all template-related
 * operations, including rendering and window management using Vulkan and other
 * graphics APIs. It provides the initialization logic and serves as the
 * foundation for handling graphical elements within the application.
 *
 * Key responsibilities of this file:
 * - Initializing the Vulkan rendering system and setting up the graphics
 * pipeline.
 * - Managing rendering contexts and integrating with the windowing system.
 * - Providing a namespace (`ExampleTemplate`) to encapsulate all
 * template-related functionalities.
 */

namespace ExampleTemplate {

// Function to initialize rendering systems
void somefunction() {
    // Call the Vulkan::initialize function
    Vulkan::initialize();
}

void initialize() {
    // Call somefunction to initialize systems
    somefunction();
}

void cleanup() {
    // Cleanup logic for the template
    std::cout << " cleanup() ExampleTemplate systems cleaned up successfully."
              << std::endl;
}

}  // namespace ExampleTemplate

// using this template create a namespace loadModels, i want
// just the empty code with the structure that is displayed above, because i
// want to fill in the functions afterwards. Give me also the h for that. put an
// initialize function there that just cout "loadModels
// Initialized" Remember the namespace always has a caps in the first letter
