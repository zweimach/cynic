project('cynic', 'c',
    version : '0.0.1',
    license: 'Apache-2.0',
    default_options: [
        'c_std=c17',
        'default_library=static',
    ],
)

cc = meson.get_compiler('c')
m_dep = cc.find_library('m', required : false)

cynic_lib = library('cynic',
    sources: [
        'src/token.c',
    ],
    dependencies: [
        m_dep,
    ],
)
