#pragma once

#include <Urho3D/Urho3D.h>

#ifdef URHO3D_STATIC
    #define PLUGIN_CORE_SAMPLEPLUGIN_API
#else
    #if Plugin_Core_SamplePlugin_EXPORT
        #define PLUGIN_CORE_SAMPLEPLUGIN_API URHO3D_EXPORT_API
    #else
        #define PLUGIN_CORE_SAMPLEPLUGIN_API URHO3D_IMPORT_API
    #endif
#endif
