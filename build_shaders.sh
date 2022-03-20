mkdir -p build/shaders

glslc ./vendor/VultrCore/src/renderer/shaders/basic.vert -o build/shaders/basic_vert.spv
glslc ./vendor/VultrCore/src/renderer/shaders/basic.frag -o build/shaders/basic_frag.spv
glslc ./vendor/VultrCore/src/renderer/shaders/fullscreen.vert -o build/shaders/fullscreen_vert.spv
glslc ./vendor/VultrCore/src/renderer/shaders/fullscreen.frag -o build/shaders/fullscreen_frag.spv
