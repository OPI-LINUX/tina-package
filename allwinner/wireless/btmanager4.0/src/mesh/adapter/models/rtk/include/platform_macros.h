/**
*****************************************************************************************
*     Copyright(c) 2015, Realtek Semiconductor Corporation. All rights reserved.
*****************************************************************************************
  * @file     platform_misc.h
  * @brief    Head file for platform miscellaneous.
  * @details  Data types and external functions declaration.
  * @author   bill
  * @date     2017-3-3
  * @version  v1.0
  * *************************************************************************************
  */

#ifndef _PLATFORM_MACROS_H_
#define _PLATFORM_MACROS_H_

/** @addtogroup Mesh_Platform_Macros Mesh Platform Macros
  * @brief compile, mathematic etc related
  * @{
  */

/** @defgroup Mesh_Platform_Macros_Exported_Macros Mesh Platform Macros Exported Macros
  * @brief
  * @{
  */

#ifndef _PACKED_
#define _PACKED_  __attribute__ ((packed))
#endif

#ifndef __INLINE
#define __INLINE  __inline
#endif

#undef  MAX
#define MAX(a, b)    ((a) > (b) ? (a) : (b))

#undef  MIN
#define MIN(a, b)    ((a) > (b) ? (b) : (a))

#undef  ABS
#define ABS(a)      ((a < 0) ? -(a) : (a))

#undef  CLAMP
#define CLAMP(x, low, high)  (((x) > (high)) ? (high) : (((x) < (low)) ? (low) : (x)))

#define MEMBER_OFFSET(struct_type, member)      ((uint32_t)&((struct_type *)0)->member)

#define CONTAINER_OF(member_ptr, struct_type, member)                       \
    ({                                                                      \
        (struct_type *)((char *)member_ptr - MEMBER_OFFSET(struct_type, member)); \
    })

#define BIT0        0x00000001
#define BIT1        0x00000002
#define BIT2        0x00000004
#define BIT3        0x00000008
#define BIT4        0x00000010
#define BIT5        0x00000020
#define BIT6        0x00000040
#define BIT7        0x00000080
#define BIT8        0x00000100
#define BIT9        0x00000200
#define BIT10       0x00000400
#define BIT11       0x00000800
#define BIT12       0x00001000
#define BIT13       0x00002000
#define BIT14       0x00004000
#define BIT15       0x00008000
#define BIT16       0x00010000
#define BIT17       0x00020000
#define BIT18       0x00040000
#define BIT19       0x00080000
#define BIT20       0x00100000
#define BIT21       0x00200000
#define BIT22       0x00400000
#define BIT23       0x00800000
#define BIT24       0x01000000
#define BIT25       0x02000000
#define BIT26       0x04000000
#define BIT27       0x08000000
#define BIT28       0x10000000
#define BIT29       0x20000000
#define BIT30       0x40000000
#define BIT31       0x80000000

#define BIT(_n)   (uint32_t)(1U << (_n))

/* Get local WORD from external 2 BYTE, Big-Endian format STANDARD NETWORK BYTE ORDER */
#define BE_EXTRN2WORD(p) ((*((p)+1)) & 0xff) + ((*(p)) << 8)

/* Get local DWORD from external 4 BYTE, Big-Endian format STANDARD NETWORK BYTE ORDER */
#define BE_EXTRN2DWORD(p) ((unsigned long)(*((p)+3)) & 0xff) + ((unsigned long)(*((p)+2)) << 8) \
    + ((unsigned long)(*((p)+1)) << 16)  + ((unsigned long)(*((p)+0)) << 24)

/* PUT external 2 CHARS from local SHORT, Big-Endian format STANDARD NETWORK BYTE ORDER */
#define BE_WORD2EXTRN(p,w)                 \
    {*((p)+1) = (unsigned char)((w) & 0xff);         \
        *(p)     = /*lint -e(572,778)*/ (unsigned char)(((w)>>8) & 0xff);}

/* PUT external 4 BYTE from local DWORD, Big-Endian format STANDARD NETWORK BYTE ORDER */
#define BE_DWORD2EXTRN(p,w)                   \
    {*((p)+3) = (unsigned char)((w) & 0xff);          \
        *((p)+2) = /*lint -e(572,778)*/ (unsigned char)(((w)>>8) & 0xff);     \
        *((p)+1) = /*lint -e(572,778)*/ (unsigned char)(((w)>>16) & 0xff);    \
        *((p)+0) = /*lint -e(572,778)*/ (unsigned char)(((w)>>24) & 0xff);}

/* Get local WORD from external 2 BYTE, Little-Endian format */
#define LE_EXTRN2WORD(p) (((*(p)) & 0xff) + ((*((p)+1)) << 8))

/* Get local DWORD from external 4 BYTE, Little-Endian format  */
#define LE_EXTRN2DWORD(p) (((unsigned long)(*((p)+0)) & 0xff) + ((unsigned long)(*((p)+1)) << 8) \
                           + ((unsigned long)(*((p)+2)) << 16)  + ((unsigned long)(*((p)+3)) << 24))

/* PUT external 2 BYTE from local WORD, Little-Endian Format */
#define LE_WORD2EXTRN(p,w)                 \
    {*((unsigned char*)p)     = (unsigned char)((unsigned short)(w) & 0xff);      \
        *(((unsigned char*)p)+1) = /*lint -e(572,778)*/ (unsigned char)(((unsigned short)(w)>>8) & 0xff);}

/* PUT external 4 BYTE from local DWORD, Little endian Format */
#define LE_DWORD2EXTRN(p,w)                      \
    {*((unsigned char*)p)     = (unsigned char)((unsigned long)(w) & 0xff);          \
        *(((unsigned char*)p)+1) = (unsigned char)(((unsigned long)(w)>>8) & 0xff);     \
        *(((unsigned char*)p)+2) = (unsigned char)(((unsigned long)(w)>>16) & 0xff);    \
        *(((unsigned char*)p)+3) = (unsigned char)(((unsigned long)(w)>>24) & 0xff);}

#ifdef __cplusplus
#define BEGIN_DECLS extern "C" {
#define END_DECLS   }
#else
#define BEGIN_DECLS
#define END_DECLS
#endif

#ifndef UNUSED
#define UNUSED(x) ((void)x)
#endif

/** @} */

/** @} End of group Mesh_Platform_MACROS */

#endif /* _PLATFORM_MACROS_H_ */