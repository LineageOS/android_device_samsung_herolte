# Inherit device configuration
$(call inherit-product, device/samsung/heroltexx/device_herolte.mk)
$(call inherit-product, device/samsung/universal8890/device_universal8890.mk)

# Inherit from the 64 bit configuration
$(call inherit-product, $(SRC_TARGET_DIR)/product/core_64_bit.mk)

# Inherit from the common Open Source product configuration
$(call inherit-product, $(SRC_TARGET_DIR)/product/aosp_base_telephony.mk)

# Inherit some common CM stuff.
$(call inherit-product, vendor/cm/config/common_full_phone.mk)

## Device identifier. This must come after all inclusions
PRODUCT_NAME := cm_heroltexx
PRODUCT_DEVICE := heroltexx
PRODUCT_BRAND := Samsung
PRODUCT_MANUFACTURER := Samsung
PRODUCT_MODEL := SM-G930F
# Release name
PRODUCT_RELEASE_NAME := heroltexx
