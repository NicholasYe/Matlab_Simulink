#include "Nicholas_DCDC_Buck_capi_host.h"
static Nicholas_DCDC_Buck_host_DataMapInfo_T root;
static int initialized = 0;
__declspec( dllexport ) rtwCAPI_ModelMappingInfo *getRootMappingInfo()
{
    if (initialized == 0) {
        initialized = 1;
        Nicholas_DCDC_Buck_host_InitializeDataMapInfo(&(root), "Nicholas_DCDC_Buck");
    }
    return &root.mmi;
}

rtwCAPI_ModelMappingInfo *mexFunction() {return(getRootMappingInfo());}
