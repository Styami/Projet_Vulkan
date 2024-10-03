project('Vulkan project', 'cpp')

subdir('src')
vulkan_dep = dependency('vulkan')
sdl2_dep = dependency('sdl2')
sdl2_main_dep = dependency('sdl2main')

executable('mainDebug', sources, cpp_args : ['-std=c++20', '-g'], win_subsystem: 'windows', dependencies: [sdl2_dep, sdl2_main_dep, vulkan_dep])