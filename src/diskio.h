/*-----------------------------------------------------------------------
/  PFF - Low level disk interface modlue include file    (C)ChaN, 2014
/-----------------------------------------------------------------------*/

#ifndef _DISKIO_DEFINED
#define _DISKIO_DEFINED

#ifdef __cplusplus
extern "C" {
#endif

#include "integer.h"


/* Status of Disk Functions */
typedef BYTE	DSTATUS;


/* Results of Disk Functions */
typedef enum {
    RES_OK = 0,		/* 0: Function succeeded */
    RES_ERROR,		/* 1: Disk error */
    RES_NOTRDY,		/* 2: Not ready */
    RES_PARERR		/* 3: Invalid parameter */
} DRESULT;

/* Block device (disk) and its operations */
typedef struct {
    void*    disk_obj;
    DSTATUS  (*disk_initialize) (void* disk_obj);
    DRESULT  (*disk_writep)     (void* disk_obj, const BYTE* buff, DWORD sc);
    DRESULT  (*disk_readp)      (void* disk_obj, BYTE* buff,
                                 DWORD sector, UINT offser, UINT count);

} DISK_TYPE;

/*---------------------------------------*/
/* Prototypes for disk control functions */

DSTATUS disk_initialize (DISK_TYPE* disk);
DRESULT disk_readp (DISK_TYPE* disk, BYTE* buff, DWORD sector, UINT offser, UINT count);
DRESULT disk_writep (DISK_TYPE* disk, const BYTE* buff, DWORD sc);

#define STA_NOINIT		0x01	/* Drive not initialized */
#define STA_NODISK		0x02	/* No medium in the drive */

#ifdef __cplusplus
}
#endif

#endif	/* _DISKIO_DEFINED */
