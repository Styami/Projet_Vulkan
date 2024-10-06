project('Vulkan project', 'cpp', default_options: ['default_library=static', 'cpp_std=c++20'])

subdir('src')
vulkan_dep = dependency('vulkan')
sdl2_dep = dependency('sdl2')
sdl2_main_dep = dependency('sdl2main')

executable('mainDebug', sources, win_subsystem: 'windows', dependencies: [sdl2_dep, sdl2_main_dep, vulkan_dep])