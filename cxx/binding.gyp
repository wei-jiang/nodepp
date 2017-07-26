{
  "targets": [
    {
      "target_name": "cpp_back"
      ,'msvs_precompiled_header': 'stdafx.h'
      ,'msvs_precompiled_source': 'stdafx.cpp'
      # ,'type': 'shared_library'
      ,"sources": [ 
        "hvipc.cpp"
        ,'stdafx.cpp'
        ,'app_dealer.cpp'
        ,'udp_dealer.cpp'
        ,"cpp_back_wrap.cxx" 
        ,"jsoncpp.cpp"
        ,"common.cpp"
        ,"freego.cpp"
        ,"async_io.cpp"
      ]
      ,'defines': [ 'WIN32_LEAN_AND_MEAN' ]
      ,'include_dirs': [
        'D:/cpp_libs/Boost/include/boost-1_64',
      ]
      ,'variables': {
        'boost_lib%': 'D:/cpp_libs/Boost/lib'
      }
      ,'libraries': [
        '-l<(boost_lib)/libboost_system-vc140-mt-s-1_64.lib'
        ,'-l<(boost_lib)/libboost_date_time-vc140-mt-s-1_64.lib'
        ,'-l<(boost_lib)/libboost_regex-vc140-mt-s-1_64.lib'
        ,'-l<(boost_lib)/libboost_atomic-vc140-mt-s-1_64.lib'
        ,'-l<(boost_lib)/libboost_chrono-vc140-mt-s-1_64.lib'
        ,'-l<(boost_lib)/libboost_log_setup-vc140-mt-s-1_64.lib'
        ,'-l<(boost_lib)/libboost_thread-vc140-mt-s-1_64.lib'
        ,'-l<(boost_lib)/libboost_filesystem-vc140-mt-s-1_64.lib'
        ,'-l<(boost_lib)/libboost_log-vc140-mt-s-1_64.lib'
      ]
      # ,'cflags!': [
      #   '-llibboost_system-vc140-mt-s-1_64.lib', '-LD:/cpp_libs/Boost/lib'
      # ]
      # ,'ldflags': [
      #   '-pthread',
      # ]
      ,'configurations': {
        'Release': {
          'msvs_settings': {
            'VCCLCompilerTool': {             
              # enable rtti
              'RuntimeTypeInfo': 'true',
              'ExceptionHandling': 1
              # ,'RuntimeLibrary': 2, # shared release
            }
          }
        }
      }
    }
  ]
}