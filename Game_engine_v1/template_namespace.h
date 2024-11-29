#ifndef EXAMPLETEMPLATE_H
#define EXAMPLETEMPLATE_H

#include <iostream>
#include <string>
#include <vector>

#include "Vulkan.h"
#include "Window.h"

/*
 * This header file declares the `ExampleTemplate` namespace, which encapsulates
 * all template-related operations, including rendering and window management
 * using Vulkan and other graphics APIs.
 *
 * Key functionalities:
 * - Initializing and managing the Vulkan rendering system.
 * - Managing window integration with Vulkan.
 * - Cleaning up template-related resources.
 */

namespace ExampleTemplate {

// Example of a function in the namespace.
void somefunction();

// Initializes the ExampleTemplate subsystem, combining window and Vulkan setup.
void initialize();

// Cleans up the ExampleTemplate subsystem and releases resources.
void cleanup();

}  // namespace ExampleTemplate

#endif  // EXAMPLETEMPLATE_H
