#ifndef __NODE_H__
#define __NODE_H__

#include "node_state_machine.h"
#include "node_status.h"
#include <iostream>
#include <array>

/*  多sentinel选举算法，参考redis sentinel
          
                   检测leader节点失效

1. 此sentinel节点发现一个组的leader节点状态不更新了，将此节点标记为+sdown，即“主观down”
2. 此sentinel节点向其他sentinel节点报告此节点进入+sdown
3. 此sentinel节点周期性检查此leader的状态在多少个sentinel节点中标记为+sdown，如果大于配置
   的quorum数，那么将此leader节点的状态改为+odown，即“客观down”

            准备failover，选举一个sentinel节点主持failover

1. 检测出leader变成odown的sentinel节点，增加epoch号，向其他sentinel发出一个包，要求作为此次
   切换的负责sentinel (+new-epoch, +try-failover)
2. 

*/

struct node_t
{
    /// 本地、同城、异地
    uint32_t site_id {0};
    /// 交易、行情、等等
    uint32_t area_id {0};
    /// 同一台机器上分组，在同一台设备上部署多套系统
    uint32_t group_id {0};
    /// site_id + area_id + group_id + node_id 唯一定位一个
    uint32_t dev_id {0};

    /// 上一个信息包收到的时间，毫秒
    mstime_t last_rcv_time {0};
    /// 每个节点都会定期通过hello包，报告一下当前的接收序号，当准备切换时
    /// sentinel主点会发一个开始选举包，

    uint64_t last_rcv_seq {0};

    /// 部分节点只做为备点，不参与选举，用于减轻主点的负担
    bool always_slave {false};

    std::array<node_status_t> node_array;

    struct node_t *parent_ptr {nullptr};
    struct node_t *left_child_ptr {nullptr};
    struct node_t *right_child_ptr {nullptr};
};

/// struct node_t *node_root_ptr {nullptr};
#endif
