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
#ifndef __QBG_PROFILE_H__
#define __QBG_PROFILE_H__
#define MAX_BP_LUT_ROWS 35
#define MAX_BP_LUT_COLS 8
#define MAX_PROFILE_NAME_LENGTH 256
enum profile_table_type {
  CHARGE_TABLE = 0,
  DISCHARGE_TABLE,
};
struct battery_data_table {
  unsigned short int table[MAX_BP_LUT_ROWS][MAX_BP_LUT_COLS];
  int unit_conv_factor[MAX_BP_LUT_COLS];
  unsigned short int nrows;
  unsigned short int ncols;
};
struct battery_config {
  char bp_profile_name[MAX_PROFILE_NAME_LENGTH];
  int bp_batt_id;
  int capacity;
  int bp_checksum;
  int soh_range_high;
  int soh_range_low;
  int normal_impedance;
  int aged_impedance;
  int normal_capacity;
  int aged_capacity;
  int recharge_soc_delta;
  int recharge_vflt_delta;
  int recharge_iterm;
};
struct battery_profile_table {
  enum profile_table_type table_type;
  int table_index;
  struct battery_data_table * table;
};
#define BPIOCXBP _IOWR('B', 0x01, struct battery_config)
#define BPIOCXBPTABLE _IOWR('B', 0x02, struct battery_profile_table)
#endif
