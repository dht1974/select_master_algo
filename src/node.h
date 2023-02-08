#ifndef __NODE_H__
#define __NODE_H__

#include "node_state_machine.h"
#include "node_status.h"
#include <iostream>
#include <array>

struct node_t
{
    /// 本地、同城、异地
    uint32_t site_id:6 {};
    /// 交易、行情、等等
    uint32_t area_id:8 {};
    /// 同一台机器上分组，在同一台设备上部署多套系统
    uint32_t group_id:8 {};
    /// site_id + area_id + group_id + node_id 唯一定位一个
    uint32_t node_id:10 {};

    std::array<node_status_t> node_array;

    struct node_t *parent_ptr {nullptr};
    struct node_t *left_child_ptr {nullptr};
    struct node_t *right_child_ptr {nullptr};
};

/// struct node_t *node_root_ptr {nullptr};
#endif
