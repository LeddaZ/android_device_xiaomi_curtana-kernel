/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ***   To edit the content of this header, modify the corresponding
 ***   source file (e.g. under external/kernel-headers/original/) then
 ***   run bionic/libc/kernel/tools/update_all.py
 ***
 ***   Any manual change here will be lost the next time this script will
 ***   be run. You've been warned!
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef _UAPI_MSM_HGSL_H
#define _UAPI_MSM_HGSL_H
#include <linux/types.h>
#include <linux/ioctl.h>
#define DB_STATE_Q_MASK 0xffff
#define DB_STATE_Q_UNINIT 1
#define DB_STATE_Q_INIT_DONE 2
#define DB_STATE_Q_FAULT 3
#define DB_SIGNAL_INVALID 0
#define DB_SIGNAL_GLOBAL_0 1
#define DB_SIGNAL_GLOBAL_1 2
#define DB_SIGNAL_LOCAL 3
#define DB_SIGNAL_MAX DB_SIGNAL_LOCAL
struct hgsl_ibdesc {
  uint64_t gpuaddr;
  uint32_t sizedwords;
};
struct hgsl_mem_object {
  uint64_t gpuaddr;
  uint32_t sizedwords;
};
struct hgsl_fhi_issud_cmds {
  uint32_t context_id;
  uint32_t timestamp;
  uint32_t flags;
  uint32_t num_ibs;
  uint32_t num_bos;
  uint64_t ibs;
  uint64_t bos;
};
struct hgsl_db_queue_inf {
  int32_t fd;
  uint32_t head_dwords;
  int32_t head_off_dwords;
  uint32_t queue_dwords;
  int32_t queue_off_dwords;
  uint32_t db_signal;
};
struct hgsl_ctxt_create_info {
  uint32_t context_id;
  int32_t shadow_fd;
  uint32_t shadow_sop_offset;
  uint32_t shadow_eop_offset;
};
struct hgsl_wait_ts_info {
  uint32_t context_id;
  unsigned int timestamp;
  unsigned int timeout;
};
struct hgsl_dbq_release_info {
  uint32_t ref_count;
  uint32_t ctxt_id;
};
#define HGSL_IOCTL_BASE 'h'
#define HGSL_IORW(n,t) _IOWR(HGSL_IOCTL_BASE, n, t)
#define HGSL_IOW(n,t) _IOW(HGSL_IOCTL_BASE, n, t)
#define HGSL_IOCTL_DBQ_GETSTATE HGSL_IORW(0x01, int32_t)
#define HGSL_IOCTL_DBQ_INIT HGSL_IORW(0x02, struct hgsl_db_queue_inf)
#define HGSL_IOCTL_DBQ_ASSIGN HGSL_IORW(0x03, uint32_t)
#define HGSL_IOCTL_DBQ_RELEASE HGSL_IORW(0x04, uint32_t)
#define HGSL_IOCTL_ISSUE_CMDS HGSL_IORW(0x05, struct hgsl_fhi_issud_cmds)
#define HGSL_IOCTL_CTXT_CREATE HGSL_IOW(0x10, struct hgsl_ctxt_create_info)
#define HGSL_IOCTL_CTXT_DESTROY HGSL_IOW(0x11, uint32_t)
#define HGSL_IOCTL_WAIT_TIMESTAMP HGSL_IOW(0x12, struct hgsl_wait_ts_info)
#endif
