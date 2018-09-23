/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein is
 * confidential and proprietary to MediaTek Inc. and/or its licensors. Without
 * the prior written permission of MediaTek inc. and/or its licensors, any
 * reproduction, modification, use or disclosure of MediaTek Software, and
 * information contained herein, in whole or in part, shall be strictly
 * prohibited.
 *
 * MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER
 * ON AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL
 * WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR
 * NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH
 * RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 * INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES
 * TO LOOK ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO.
 * RECEIVER EXPRESSLY ACKNOWLEDGES THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO
 * OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES CONTAINED IN MEDIATEK
 * SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE
 * RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S
 * ENTIRE AND CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE
 * RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE
 * MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE
 * CHARGE PAID BY RECEIVER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek
 * Software") have been modified by MediaTek Inc. All revisions are subject to
 * any receiver's applicable license agreements with MediaTek Inc.
 */
#ifndef _MTK_HARDWARE_MTKCAM_INCLUDE_MTKCAM_AAA_IDNGINFO_H_
#define _MTK_HARDWARE_MTKCAM_INCLUDE_MTKCAM_AAA_IDNGINFO_H_

#include <mtkcam/main/core/module.h>
#include <mtkcam/utils/metadata/IMetadata.h>

/******************************************************************************
 *
 ******************************************************************************/
namespace NS3Av3
{
class IDngInfo
{
protected:
    virtual                     ~IDngInfo() {}

public:
    static  IDngInfo*           getInstance(char const* szCallerName, MUINT const sensorIndex);

    virtual NSCam::IMetadata    getStaticMetadata() const = 0;
    virtual NSCam::IMetadata    getDynamicNoiseProfile(MUINT32 iso) const = 0;

    // utility namespace function
    virtual NSCam::IMetadata    getShadingMapFromMem(MBOOL fgShadOn, const NSCam::IMetadata::Memory& lscData) const = 0;
    virtual NSCam::IMetadata    getShadingMapFromHal(const NSCam::IMetadata& halMeta, const NSCam::IMetadata& appMeta) const = 0;
    virtual MUINT32             getRawBitDepth() const = 0;
};
};


/**
 * @brief The definition of the maker of DngInfo instance.
 */
typedef NS3Av3::IDngInfo* (*DngInfo_FACTORY_T)(char const* szCallerName, MUINT const sensorIndex);
#define MAKE_DngInfo(...) \
    MAKE_MTKCAM_MODULE(MTKCAM_MODULE_ID_AAA_DNG_INFO, DngInfo_FACTORY_T, __VA_ARGS__)


#endif //_MTK_HARDWARE_MTKCAM_INCLUDE_MTKCAM_AAA_IDNGINFO_H_