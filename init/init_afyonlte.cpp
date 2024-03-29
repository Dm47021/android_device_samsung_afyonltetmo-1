/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

#include "init_msm.h"

void init_msm_properties(unsigned long msm_id, unsigned long msm_ver, char *board_type)
{
    char platform[PROP_VALUE_MAX];
    char bootloader[PROP_VALUE_MAX];
    char device[PROP_VALUE_MAX];
    char devicename[PROP_VALUE_MAX];
    int rc;

    UNUSED(msm_id);
    UNUSED(msm_ver);
    UNUSED(board_type);

    rc = property_get("ro.board.platform", platform);
    if (!rc || !ISMATCH(platform, ANDROID_TARGET))
        return;

    property_get("ro.bootloader", bootloader);

    if (strstr(bootloader, "G386T")) {
        /* G386T */
//        gsm_properties();
        property_set("ro.build.fingerprint", "samsung/afyonltetmo/afyonltetmo:4.4.2/KOT49H/G386TUVU1ANK3:user/release-keys");
        property_set("ro.build.description", "afyonltetmo-user 4.4.2 KOT49H G386TUVU1ANK3 release-keys");
        property_set("ro.product.model", "SM-G386T");
        property_set("ro.product.device", "afyonltetmo");
     } else if (strstr(bootloader, "G386T1")) {
        /* G386T1 */
//       gsm_properties();
        property_set("ro.build.fingerprint", "samsung/afyonlteMetroPCS/afyonlteMetroPCS:4.4.2/KOT49H/G386T1UVU1ANK3:user/release-keys");
        property_set("ro.build.description", "afyonlteMetroPCS-user 4.4.2 KOT49H G386T1UVU1ANK3 release-keys");
        property_set("ro.product.model", "SM-G386T1");
        property_set("ro.product.device", "afyonlteMetroPCS");
    } else if (strstr(bootloader, "G386W")) {
        /* G386W */
//        gsm_properties();
        property_set("ro.build.fingerprint", "samsung/afyonltevl/afyonltecan:4.4.2/KOT49H/G386WVLU1ANJ1:user/release-keys");
        property_set("ro.build.description", "afyonltecan-user 4.4.2 KOT49H G386WVLU1ANJ1 release-keys");
        property_set("ro.product.model", "SM-G386W");
        property_set("ro.product.device", "afyonltecan");
    }

    property_get("ro.product.device", device);
    strlcpy(devicename, device, sizeof(devicename));
    INFO("Found bootloader id %s setting build properties for %s device\n", bootloader, devicename);
}

//void gsm_properties()
//{
//    property_set("telephony.lteOnGsmDevice", "1");
//    property_set("ro.telephony.default_network", "9");
//}
