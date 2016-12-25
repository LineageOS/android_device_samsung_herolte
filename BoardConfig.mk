ifeq ($(CUSTOM_DTB_BUILD),true)
BOARD_MKBOOTIMG_ARGS := --kernel_offset 0x00008000 --ramdisk_offset 0x01000000 --tags_offset 0x00000100 --board SRPOI30A000KU
else
BOARD_MKBOOTIMG_ARGS := --kernel_offset 0x00008000 --ramdisk_offset 0x01000000 --tags_offset 0x00000100 --board SRPOI30A000RU --dt device/samsung/heroltexx/dtb.img
endif
TARGET_KERNEL_SOURCE := kernel/samsung/exynos8890
TARGET_KERNEL_CONFIG := exynos8890-herolte_defconfig


# Partitions
BOARD_BOOTIMAGE_PARTITION_SIZE     := 41943040
BOARD_RECOVERYIMAGE_PARTITION_SIZE := 48234496
BOARD_SYSTEMIMAGE_PARTITION_SIZE   := 4508876800
BOARD_USERDATAIMAGE_PARTITION_SIZE := 27044851712
BOARD_CACHEIMAGE_PARTITION_SIZE    := 209715200
BOARD_FLASH_BLOCK_SIZE := 131072

TARGET_RECOVERY_FSTAB := device/samsung/universal8890/ramdisk/fstab.samsungexynos8890

# RIL
BOARD_MODEM_TYPE := ss333

# Recovery
TARGET_OTA_ASSERT_DEVICE := heroltebmc,herolteskt,heroltektt,heroltelgt,heroltexx

# Inherit common board flags
include device/samsung/universal8890/BoardConfigCommon.mk
