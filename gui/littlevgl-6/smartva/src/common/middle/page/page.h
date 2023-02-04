#ifndef __PAGE_H__
#define __PAGE_H__
#include "smt_config.h"
#include "msg.h"

typedef struct
{
	 int (*on_create)(void);
	 int (*on_destroy)(void);
	 int (*on_show)(void);
	 int (*on_hide)(void);
	 int (*msg_proc)(MsgDataInfo *);
	 int (*on_anim)(page_id_t old_page, page_id_t new_page);
	 int (*is_anim_end)(void);
} page_ops_t;

typedef struct
{
	 page_id_t id;
	 void *user_data;
} page_info_t;

typedef struct
{
	page_ops_t ops;
	page_info_t info;
} page_interface_t;

typedef enum
{
	CMD_NONE = 0,
	CMD_SWITCH = 1,
	CMD_ANIM_SWITCH = 2,
} page_cmd_t;

typedef struct
{
	int cmd;			// no user
	long int param[2];
} page_param;

void page_init();
void page_uninit();
void reg_page(page_interface_t *page);
void unreg_page(page_interface_t *page);
int create_page(page_id_t id);
void destory_page(page_id_t id);
void show_page(page_id_t id);
void hide_page(page_id_t id);
page_id_t current_page(void);
void switch_page(page_id_t old_id, page_id_t new_id);
void anim_switch_page(page_id_t old_id, page_id_t new_id);
void sent_page_msg(MsgDataInfo *msg);
int  set_page_user_data(page_id_t id,void *user_data);
void* get_page_user_data(page_id_t id);

#define REG_PAGE(name)\
do{\
    extern void REGISTER_##name(void);\
    REGISTER_##name();\
}while(0)


#endif
