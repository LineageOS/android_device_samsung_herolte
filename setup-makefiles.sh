#!/bin/bash
#
# Copyright (C) 2017-2021 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

set -e

DEVICE=herolte
VENDOR=samsung

export INITIAL_COPYRIGHT_YEAR=2017

# Load extract_utils and do some sanity checks
MY_DIR="${BASH_SOURCE%/*}"
if [[ ! -d "${MY_DIR}" ]]; then MY_DIR="${PWD}"; fi

ANDROID_ROOT="${MY_DIR}/../../.."

HELPER="${ANDROID_ROOT}/tools/extract-utils/extract_utils.sh"
if [ ! -f "${HELPER}" ]; then
    echo "Unable to find helper script at ${HELPER}"
    exit 1
fi
source "${HELPER}"

# Initialize the helper
setup_vendor "${DEVICE}" "${VENDOR}" "${ANDROID_ROOT}"

# Copyright headers and guards
write_headers

# The standard blobs
write_makefiles "${MY_DIR}/proprietary-files.txt" true

###################################################################################################
# CUSTOM PART START                                                                               #
###################################################################################################
OUTDIR=vendor/$VENDOR/$DEVICE
(cat << EOF) >> $ANDROID_ROOT/$OUTDIR/Android.mk
include \$(CLEAR_VARS)

LIFEVIBES_LIBS := libLifevibes_lvverx.so libLifevibes_lvvetx.so
LIFEVIBES_SYMLINKS := \$(addprefix (TARGET_OUT_VENDOR)/lib/soundfx/,\$(notdir \$(LIFEVIBES_LIBS)))
\$(LIFEVIBES_SYMLINKS): \$(LOCAL_INSTALLED_MODULE)
	@echo "LifeVibes lib link: \$@"
	@mkdir -p \$(dir \$@)
	@rm -rf \$@
	\$(hide) ln -sf /vendor/lib/\$(notdir \$@) \$@

ALL_DEFAULT_INSTALLED_MODULES += \$(LIFEVIBES_SYMLINKS)

EOF
###################################################################################################
# CUSTOM PART END                                                                                 #
###################################################################################################

# Finish
write_footers
