project('Vulkan project', 'cpp', version: '0.1',default_options: ['default_library=static', 'cpp_std=c++20'])

subdir('src')

dep = []
dep += [dependency('vulkan')]
dep += [dependency('sdl2')]

if build_machine.system() == 'windows'
    dep += [dependency('sdl2main')]
    executable('mainDebug', sources:sources, win_subsystem: 'windows', dependencies: dep)
elif build_machine.system() == 'linux'
    executable('mainDebug', sources: sources, dependencies: dep)
endif
