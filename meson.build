project('hypo-cpp', 'cpp',
  version : '0.1',
  default_options : ['cpp_std=c++2a', 'warning_level=3'])

incdir = include_directories('include')

subdir('include')
subdir('src')
subdir('tests')

pkg_mod = import('pkgconfig')
pkg_mod.generate(libraries: hypolib,
  version: '0.1',
  name: 'libhypo',
  filebase: 'hypo',
  description: 'an implementation of the Calc Virtual Machine')

exe = executable('hypo_cpp', 'src/main.cpp',
  include_directories: incdir,
  link_with: hypolib,
  install : true)
