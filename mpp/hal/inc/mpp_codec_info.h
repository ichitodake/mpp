/*
 * Copyright 2015 Rockchip Electronics Co. LTD
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __MPP_CODEC_INFO_H__
#define __MPP_CODEC_INFO_H__

#include "rk_type.h"
#include "mpp_err.h"

typedef enum EncInfoType_e {
    ENC_INFO_BASE              = 0,
    ENC_INFO_WIDTH,
    ENC_INFO_HEIGHT,
    ENC_INFO_FORMAT,
    ENC_INFO_FPS_IN,
    ENC_INFO_FPS_OUT,
    ENC_INFO_RC_MODE,
    ENC_INFO_BITRATE,

    ENC_INFO_GOP_SIZE,
    ENC_INFO_FPS_CALC,
    ENC_INFO_PROFILE,

    ENC_INFO_BUTT,
} EncInfoType;

enum ENC_INFO_FLAGS {
    ENC_INFO_FLAG_NULL     = 0,
    ENC_INFO_FLAG_NUMBER,
    ENC_INFO_FLAG_STRING,

    ENC_INFO_FLAG_BUTT,
};

typedef struct CodecInfoElem_t {
    RK_U32 type;
    RK_U32 flag;
    RK_U64 data;
} CodecInfoElem;

typedef struct CodecInfo_t {
    CodecInfoElem elem_last[ENC_INFO_BUTT];
    CodecInfoElem elem_set[ENC_INFO_BUTT];

    RK_S32 cnt;
} CodecInfo;


#ifdef __cplusplus
extern "C" {
#endif

MPP_RET mpp_set_codec_info_elem(CodecInfo *info, RK_U32 type, RK_U32 flag, RK_U64 data);
MPP_RET mpp_get_rc_mode_codec_info_data(RK_S32 rc_mode, RK_U64 *data);

#ifdef __cplusplus
}
#endif

#endif /*__MPP_CODEC_INFO_H__*/

