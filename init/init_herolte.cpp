/*
   Copyright (c) 2016, The Linux Foundation. All rights reserved.
   Copyright (c) 2017-2020, The LineageOS Project. All rights reserved.

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

#include <android-base/logging.h>
#include <android-base/properties.h>

#include "property_service.h"

#include "init_universal8890.h"

using android::base::GetProperty;
using android::init::property_set;

void vendor_load_properties()
{
    std::string bootloader = GetProperty("ro.bootloader", "");

    if (bootloader.find("G930F") == 0) {
        /* heroltexx */
        property_override("ro.build.description", "heroltexx-user 8.0.0 R16NW G930FXXU2ERD5 release-keys");
        set_ro_product_prop("device", "heroltexx");
        set_ro_build_prop("fingerprint", "samsung/heroltexx/herolte:8.0.0/R16NW/G930FXXU2ERD5:user/release-keys");
        set_ro_product_prop("model", "SM-G930F");
        set_ro_product_prop("name", "heroltexx");
        gsm_properties("9");
    } else if (bootloader.find("G930W8") == 0) {
        /* heroltebmc */
        property_override("ro.build.description", "heroltebmc-user 8.0.0 R16NW G930W8VLS7CTB2 release-keys");
        set_ro_product_prop("device", "heroltebmc");
        set_ro_build_prop("fingerprint", "samsung/heroltebmc/heroltebmc:8.0.0/R16NW/G930W8VLS7CTB2:user/release-keys");
        set_ro_product_prop("model", "SM-G930W8");
        set_ro_product_prop("name", "heroltebmc");
        gsm_properties("9");
    } else if (bootloader.find("G930S") == 0) {
        /* herolteskt */
        property_override("ro.build.description", "herolteskt-user 8.0.0 R16NW G930SKSU3ETD2 release-keys");
        set_ro_product_prop("device", "herolteskt");
        set_ro_build_prop("fingerprint", "samsung/herolteskt/herolteskt:8.0.0/R16NW/G930SKSU3ETD2:user/release-keys");
        set_ro_product_prop("model", "SM-G930S");
        set_ro_product_prop("name", "herolteskt");
        gsm_properties("9");
    } else if (bootloader.find("G930K") == 0) {
        /* heroltektt */
        property_override("ro.build.description", "heroltektt-user 8.0.0 R16NW G930KKKU3ETD2 release-keys");
        set_ro_product_prop("device", "heroltektt");
        set_ro_build_prop("fingerprint", "samsung/heroltektt/heroltektt:8.0.0/R16NW/G930KKKU3ETD2:user/release-keys");
        set_ro_product_prop("model", "SM-G930K");
        set_ro_product_prop("name", "heroltektt");
        gsm_properties("9");
    }  else if (bootloader.find("G930L") == 0) {
        /* heroltelgt */
        property_override("ro.build.description", "heroltelgt-user 8.0.0 R16NW G930LKLU3ETD2 release-keys");
        set_ro_product_prop("device", "heroltelgt");
        set_ro_build_prop("fingerprint", "samsung/heroltelgt/heroltelgt:8.0.0/R16NW/G930LKLU3ETD2:user/release-keys");
        set_ro_product_prop("model", "SM-G930L");
        set_ro_product_prop("name", "heroltelgt");
        gsm_properties("9");
    } else {
        gsm_properties("9");
    }

    std::string device = GetProperty("ro.product.device", "");
    LOG(ERROR) << "Found bootloader id " << bootloader <<  " setting build properties for "
        << device <<  " device" << std::endl;
}
