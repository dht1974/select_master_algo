#ifndef __NODE_STATUS_T__
#define __NODE_STATUS_T__

#include <iostream>

/// 目前支持二叉树
constexpr const int max_child_count {2};

struct node_status_t
{
    union {
        {
            /// 本地、同城、异地
            uint32_t site_id:6 {};
            /// 交易、行情、等等
            uint32_t area_id:8 {};
            /// 同一台机器上分组，在同一台设备上部署多套系统
            uint32_t group_id:8 {};
            /// site_id + area_id + group_id + node_id 唯一定位一个
            uint32_t node_id:10 {};
        }
        /// 这个变量由于在union里不能初始化，会覆盖前面的，编译会报错
        uint32_t node_global_id;
    };    

    /// 当前此节点在二叉树的第几层
    uint8_t layer_id {};
    /// 是否参与选举，根据设计，在二叉树上，有部分节点只同步数据，不提供服务，
    /// 这部分节点有可能参与仲裁，但不参与选举，即无被选资格
    bool election_candidate {false};
    /// 有选举资格的一定参与仲裁，也有可能即不参与选举，也不参与仲裁，只是同步数据
    /// 比如说灾备系统，不在一个分区里，没资格参与
    bool arbitration_candidate {false};
    /// 当前节点有几个子节点
    uint8_t child_count {};


    /// 当前节点写入盘中的数据量
    uint64_t recv_seq {};

    /// 接收到节点hello包，更新时间
    struct timeval recv_time {};
};

#endif
