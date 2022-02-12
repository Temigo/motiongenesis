{
  'targets': [
    {
        'target_name': 'hello_world_native', # Name of the executable
        'sources': [ 'hello_world.cc' ],
        'include_dirs': [
            "<!@(node -p \"require('node-addon-api').include\")",
            "lib/dummylib"
        ],
        'libraries': ['-ldl', '-lDummyLib', '-L../lib/dummylib', '-Wl,-rpath=./lib/dummylib'],
        'dependencies': [
            "<!(node -p \"require('node-addon-api').gyp\")"
        ],
        'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
        #"cflags!": [ "-fno-exceptions" ],
        #"cflags_cc!": [ "-fno-exceptions" ],
        #"cflags": ["-std=c++11"],
        #"cflags_cc": ['-std=c++11'], # '-stdlib=libc++'
        # "conditions": [
        #     ['OS=="win"',
        #     {"include_dirs": ["loader/windows"], "sources": ["loader/windows/loader.h"] },
        #     {"include_dirs": ["loader/unix/"],   "sources": ["loader/unix/loader.h"] }]
        # ],
        # "link_settings": {
        #     "libraries": [],
        #     "library_dirs": []
        # }
    }
  ]
}
