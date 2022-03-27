project('cynic',
    'c',
    version : '0.0.1',
    license: 'MIT',
    subproject_dir: 'third-party',
    default_options: ['c_std=c17', 'default_library=static'],
)

cc = meson.get_compiler('c')
m_dep = cc.find_library('m', required : false)
uthash_dep = dependency('uthash')
cmocka_dep = dependency('cmocka')

cynic_lib = library('cynic',
    sources: [
        'src/lexer.c',
        'src/token.c',
    ],
)

cynic_dep = declare_dependency(
    link_with: cynic_lib,
    include_directories: include_directories('src'),
)

executable('cynic',
    sources: ['src/main.c'],
    dependencies: [cynic_dep, uthash_dep],
)

test_files = [
    'test/lexer_test.c',
]

lexer_test = executable('lexer_test',
    sources: test_files,
    dependencies: [cmocka_dep, cynic_dep],
    build_by_default: false,
)

test('lexer_test', lexer_test)
