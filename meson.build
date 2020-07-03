project('apa',
    'c',
    version : '0.0.0',
    license: 'MIT',
    subproject_dir: 'third-party',
    default_options: ['c_std=c17', 'default_library=static']
)

cc = meson.get_compiler('c')
dep_m = cc.find_library('m', required : false)
thread_dep = dependency('threads')

cmocka_dep = dependency('cmocka', fallback: ['cmocka', 'cmocka_dep'])

apa_lib = library('apa',
    sources: [
        'src/lexer.c',
        'src/node.c',
        'src/token.c'
    ]
)

apa_dep = declare_dependency(
    link_with: apa_lib,
    include_directories: include_directories('src')
)

executable('apa',
    sources: ['src/main.c'],
    dependencies: [apa_dep],
)

test_files = [
    'tests/lexer_test.c'
]

lexer_test = executable('lexer_test',
    sources: test_files,
    dependencies: [cmocka_dep, apa_dep],
    build_by_default: false
)

test('lexer_test', lexer_test)
